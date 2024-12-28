package com.zeroone.star.calmanager.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.calmanager.entity.CalCalendar;
import com.zeroone.star.calmanager.entity.CalCalendarFollowers;
import com.zeroone.star.calmanager.mapper.CalCalendarFollowersMapper;
import com.zeroone.star.calmanager.mapper.CalCalendarMapper;
import com.zeroone.star.calmanager.service.ICalCalendarService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;

import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j6.calendar.CalendarDTO;
import com.zeroone.star.project.query.j6.calendar.CalendarPageQuery;
import com.zeroone.star.project.vo.j6.calendar.CalenderAssembleVO;
import org.mapstruct.Mapper;
import org.mapstruct.Mapping;
import org.mapstruct.factory.Mappers;
import org.springframework.beans.factory.annotation.Autowired;
import com.zeroone.star.project.dto.j6.calendar.InsertCalendarDTO;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import com.zeroone.star.project.dto.j6.calendar.CalendarDTO;
import com.zeroone.star.project.dto.j6.calendar.CalendarInfoDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j6.calendar.CalendarInfoVO;
import org.mapstruct.Mapper;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
import cn.hutool.core.util.IdUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.zeroone.star.calmanager.entity.*;
import com.zeroone.star.calmanager.mapper.CalCalendarMapper;
import com.zeroone.star.calmanager.service.ICalCalendarService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.j6.calendar.CalendarDTO;
import com.zeroone.star.project.dto.j6.calendar.InsertCalendarDTO;
import com.zeroone.star.project.vo.j6.calendar.CalendarInfoVO;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.stereotype.Service;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.Collections;
import java.util.List;
import javax.annotation.Resource;
import java.util.List;
import java.util.stream.Collectors;

import java.util.UUID;

import javax.annotation.Resource;
import java.util.ArrayList;
import java.util.List;

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author lee
 * @since 2024-10-23
 */
@Mapper(componentModel = "spring")
interface MsCalMapper {
	CalendarInfoVO calendar2CalendarInfoVO(CalCalendar calendar);

	CalCalendar calendarDTO2CalCalendar(CalendarDTO calendarDTO);
}
@Service
@ComponentScan(basePackages = {
		"com.zeroone.star.project.components.jwt",
		"com.zeroone.star.project.components.user"
})
public class CalCalendarServiceImpl extends ServiceImpl<CalCalendarMapper, CalCalendar> implements ICalCalendarService {

	@Autowired
	private CalCalendarMapper calCalendarMapper;
	@Autowired
	private MsCalenderAssembleMapper msCalenderAssembleMapper;
	@Resource
	MsCalMapper msCalMapper;
	@Autowired
	CalCalendarFollowersMapper calCalendarFollowersMapper;
	@Autowired
	private UserHolder userHolder;

	@Override
	public PageDTO<CalendarDTO> listPublicCalendars(CalendarPageQuery calendarPageQuery) {
		// 创建分页对象
		Page<CalCalendar> page = new Page<>(calendarPageQuery.getPageIndex(), calendarPageQuery.getPageSize());
		// 构建查询条件
		QueryWrapper<CalCalendar> queryWrapper = new QueryWrapper<>();
		queryWrapper.eq("xisPublic", 1); // 假设xisPublic字段为1表示公开日历
		queryWrapper.orderByDesc("xcreateTime");
		// 执行分页查询
		Page<CalCalendar> resultPage = calCalendarMapper.selectPage(page, queryWrapper);

		// 使用MsCalenderAssembleMapper中的方法进行数据转换
		PageDTO<CalendarDTO> pageDTO = PageDTO.create(resultPage, msCalenderAssembleMapper::calCalendarToCalendarDTO);

		// 查询每个日历的followed状态
		for (CalendarDTO calendarDTO : pageDTO.getRows()) {
			String calendarId = calendarDTO.getXid();
//            String xtarget = calendarDTO.getXtarget();

			boolean isFollowed = calCalendarFollowersMapper.existsByCalendarIdAndTarget(calendarId);
			calendarDTO.setFollowed(isFollowed);
		}

		return pageDTO;
	}

	/**
	 * 新建日历
	 * @param insertCalendarDTO
	 * @return
	 */
	@Override
	public boolean insertCalendar(InsertCalendarDTO insertCalendarDTO) {
		// 校验 xname 的唯一性
		if (!isXnameUnique(insertCalendarDTO.getXname())) {
			throw new IllegalArgumentException("日历名称已存在，不能重复添加");
		}

		// 创建 CalCalendar 实体对象并拷贝属性
		CalCalendar calCalendar = new CalCalendar();
		BeanUtils.copyProperties(insertCalendarDTO, calCalendar);

		// 使用 Hutool 的雪花算法生成 ID
		String xid = IdUtil.getSnowflake(1, 1).nextIdStr(); // 数据中心 ID 和机器 ID 可根据需要调整
		calCalendar.setXid(xid);

		// 生成当前创建时间
		LocalDateTime createTime = LocalDateTime.now();
		calCalendar.setXcreateTime(createTime);
		calCalendar.setXupdateTime(createTime);  // 初始化更新时间为创建时间

		// 生成 xsequence：创建日期（格式 YYYYMMDD）拼接上 xid，并去除空格和 "-"
		String date = createTime.format(DateTimeFormatter.ofPattern("yyyyMMdd"));
		String xsequence = date + xid.replaceAll("[-\\s]", "");
		calCalendar.setXsequence(xsequence);

		// 设置xcreator和xtarget
		UserDTO currentUser;
		try {
			currentUser = userHolder.getCurrentUser();
			if (currentUser != null) {
				String creator = currentUser.getUsername();
				calCalendar.setXcreateor(creator);
				// 处理 xtype
				if ("PERSON".equalsIgnoreCase(insertCalendarDTO.getXtype())) {
					calCalendar.setXtarget(creator);
					calCalendar.setXtype("PERSON");
					handlePersonalCalendarPermissions(calCalendar, currentUser);
				} else if ("UNIT".equalsIgnoreCase(insertCalendarDTO.getXtype())) {
					calCalendar.setXtarget(selectDistinguishedNameById(insertCalendarDTO.getOrganization()));
					calCalendar.setXtype("UNIT");
					handleOrganizationalCalendarPermissions(calCalendar, insertCalendarDTO);
				}
			} else {
				throw new IllegalStateException("无法获取当前用户信息");
			}
		} catch (Exception e) {
			throw new RuntimeException("获取用户信息失败", e);
		}

		// 设置 xsource 为创建来源（默认为 "PERSON"）
		calCalendar.setXsource("PERSON");

		// 保存对象到数据库
		return this.save(calCalendar);
	}

	private String selectDistinguishedNameById(String organizationId) {
		// 查询 org_unit 表，返回对应的 xdistinguishedName
		String distinguishedName = calCalendarMapper.selectUnitDistinguishedNameById(organizationId);
		if (distinguishedName == null) {
			throw new IllegalArgumentException("未找到对应的组织，ID: " + organizationId);
		}
		return distinguishedName;
	}

	private String selectIdByDistinguishedName(String name) {
		// 查询 org_person 表，返回对应的 xid
		String id = calCalendarMapper.selectDistinguishedNameByName(name);
		if (id == null) {
			throw new IllegalArgumentException("未找到对应的用户，name: " + name);
		}
		return id;
	}

	/**
	 * 处理个人日历的权限逻辑
	 */
	private void handlePersonalCalendarPermissions(CalCalendar calCalendar, UserDTO currentUser) {
		String username = currentUser.getUsername();
		// 将用户名转换为 List<String>
		List<String> userList = Collections.singletonList(username);
		// 存储权限
		saveToCalendarPermissions(calCalendar.getXid(), userList, null, null);
	}

	/**
	 * 处理组织日历的权限逻辑
	 */
	private void handleOrganizationalCalendarPermissions(CalCalendar calCalendar, InsertCalendarDTO insertCalendarDTO) {
		// 获取管理者
		List<String> managers = insertCalendarDTO.getManagers();
		// 获取可见范围
		List<String> viewableRange = insertCalendarDTO.getViewableRange();
		// 获取可新建范围
		List<String> manageableRange = insertCalendarDTO.getManageableRange();
		// 存储权限到对应的权限表
		saveToCalendarPermissions(calCalendar.getXid(), managers, manageableRange, viewableRange);
	}

	/**
	 * 存储权限到 cal_calendar_* 子表中
	 */
	private void saveToCalendarPermissions(String calendarXid, List<String> managerIds, List<String> viewableRangeIds, List<String> manageableRangeIds) {
		// 存储管理者到 cal_calendar_manageablepersonlist
		int n1 = 0; // 排序初始值设置为 0
		if (managerIds != null && !managerIds.isEmpty()) {
			for (String manager : managerIds) {
				String distinguishedName = calCalendarMapper.selectPersonDistinguishedNameById(manager);
				if (distinguishedName != null) {
					CalCalendarManageablepersonlist manageablePerson = new CalCalendarManageablepersonlist();
					manageablePerson.setCalendarXid(calendarXid);
					manageablePerson.setXmanageablePersonList(distinguishedName);
					manageablePerson.setXorderColumn(n1++);
					calCalendarMapper.insertManager(manageablePerson);
				}
			}
		}
		// 最后插入超级管理员 xadmin
		CalCalendarManageablepersonlist adminPerson = new CalCalendarManageablepersonlist();
		adminPerson.setCalendarXid(calendarXid);
		adminPerson.setXmanageablePersonList("xadmin");
		adminPerson.setXorderColumn(n1);
		calCalendarMapper.insertManager(adminPerson);

		// 存储可见者到 cal_calendar_viewablepersonlist / cal_calendar_viewableunitlist / cal_calendar_viewablegrouplist
		int n2_person = 0; // 可见者person的排序初始值
		int n2_unit = 0;   // 可见者unit的排序初始值
		int n2_group = 0;  // 可见者group的排序初始值
		// 先将所有管理者加入到可见者列表
		for (String manager : managerIds) {
			String distinguishedName = calCalendarMapper.selectPersonDistinguishedNameById(manager);
			if (distinguishedName != null) {
				CalCalendarViewablepersonlist viewablePerson = new CalCalendarViewablepersonlist();
				viewablePerson.setCalendarXid(calendarXid);
				viewablePerson.setXviewablePersonList(distinguishedName);
				viewablePerson.setXorderColumn(n2_person++);
				calCalendarMapper.insertViewablePerson(viewablePerson);
			}
		}
		// 加入 viewableRangeIds 中在 org_person 中存在的可见者
		if (viewableRangeIds != null && !viewableRangeIds.isEmpty()) {
			for (String viewableRangeId : viewableRangeIds) {
				// 检查 org_person
				String distinguishedName = calCalendarMapper.selectDistinguishedNameById(viewableRangeId);
				if (distinguishedName != null) {
					CalCalendarViewablepersonlist viewablePerson = new CalCalendarViewablepersonlist();
					viewablePerson.setCalendarXid(calendarXid);
					viewablePerson.setXviewablePersonList(distinguishedName);
					viewablePerson.setXorderColumn(n2_person++);
					calCalendarMapper.insertViewablePerson(viewablePerson);
				}
				// 检查 org_unit
				distinguishedName = calCalendarMapper.selectDistinguishedNameByUnitId(viewableRangeId);
				if (distinguishedName != null) {
					CalCalendarViewableunitlist viewableUnit = new CalCalendarViewableunitlist();
					viewableUnit.setCalendarXid(calendarXid);
					viewableUnit.setXviewableUnitList(distinguishedName);
					viewableUnit.setXorderColumn(n2_unit++);
					calCalendarMapper.insertViewableUnit(viewableUnit);
				}
				// 检查 org_group
				distinguishedName = calCalendarMapper.selectDistinguishedNameByGroupId(viewableRangeId);
				if (distinguishedName != null) {
					CalCalendarViewablegrouplist viewableGroup = new CalCalendarViewablegrouplist();
					viewableGroup.setCalendarXid(calendarXid);
					viewableGroup.setXviewableGroupList(distinguishedName);
					viewableGroup.setXorderColumn(n2_group++);
					calCalendarMapper.insertViewableGroup(viewableGroup);
				}
			}
		}
		// 最后插入超级管理员 xadmin 到可见者
		CalCalendarViewablepersonlist adminVisiblePerson = new CalCalendarViewablepersonlist();
		adminVisiblePerson.setCalendarXid(calendarXid);
		adminVisiblePerson.setXviewablePersonList("xadmin");
		adminVisiblePerson.setXorderColumn(n2_person++);
		calCalendarMapper.insertViewablePerson(adminVisiblePerson);

		// 存储可新建者到 cal_calendar_publishablepersonlist / cal_calendar_publishableunitlist / cal_calendar_publishablegrouplist
		int n3_person = 0; // 可新建者person的排序初始值
		int n3_unit = 0;   // 可新建者unit的排序初始值
		int n3_group = 0;  // 可新建者group的排序初始值

		// 加入 manageableRangeIds 中的可新建者
		if (manageableRangeIds != null && !manageableRangeIds.isEmpty()) {
			for (String manageableRangeId : manageableRangeIds) {
				// 检查 org_person
				String distinguishedName = calCalendarMapper.selectDistinguishedNameById(manageableRangeId);
				if (distinguishedName != null) {
					CalCalendarPublishablepersonlist publishablePerson = new CalCalendarPublishablepersonlist();
					publishablePerson.setCalendarXid(calendarXid);
					publishablePerson.setXpublishablePersonList(distinguishedName);
					publishablePerson.setXorderColumn(n3_person++);
					calCalendarMapper.insertPublishablePerson(publishablePerson);
				}

				// 检查 org_unit
				distinguishedName = calCalendarMapper.selectDistinguishedNameByUnitId(manageableRangeId);
				if (distinguishedName != null) {
					CalCalendarPublishableunitlist publishableUnit = new CalCalendarPublishableunitlist();
					publishableUnit.setCalendarXid(calendarXid);
					publishableUnit.setXpublishableUnitList(distinguishedName);
					publishableUnit.setXorderColumn(n3_unit++);
					calCalendarMapper.insertPublishableUnit(publishableUnit);
				}

				// 检查 org_group
				distinguishedName = calCalendarMapper.selectDistinguishedNameByGroupId(manageableRangeId);
				if (distinguishedName != null) {
					CalCalendarPublishablegrouplist publishableGroup = new CalCalendarPublishablegrouplist();
					publishableGroup.setCalendarXid(calendarXid);
					publishableGroup.setXpublishableGroupList(distinguishedName);
					publishableGroup.setXorderColumn(n3_group++);
					calCalendarMapper.insertPublishableGroup(publishableGroup);
				}
			}
		}

		// 最后插入超级管理员 xadmin 到可新建者
		CalCalendarPublishablepersonlist adminPublishablePerson = new CalCalendarPublishablepersonlist();
		adminPublishablePerson.setCalendarXid(calendarXid);
		adminPublishablePerson.setXpublishablePersonList("xadmin");
		adminPublishablePerson.setXorderColumn(n3_person++);
		calCalendarMapper.insertPublishablePerson(adminPublishablePerson);
	}

	@Override
	public boolean isXnameUnique(String xname) {
		QueryWrapper<CalCalendar> queryWrapper = new QueryWrapper<>();
		queryWrapper.eq("xname", xname);
		return this.count(queryWrapper) == 0;  // 计数为0表示名称唯一
	}

	@Override
	public boolean deleteCalendar(String xid) {
		System.out.println("要删除的xid: " + xid);
		return calCalendarMapper.deleteById(xid);
	}

	@Override
	public boolean deleteCalendarSubRecords(String xid) {
		// 初始化成功标志
		boolean success = true;

		// 删除可见者记录
		int deletedViewablePersons = calCalendarMapper.deleteViewablePersonsByCalendarId(xid);
		if (deletedViewablePersons < 0) {
			success = false; // 记录删除失败
		}

		int deletedViewableUnits = calCalendarMapper.deleteViewableUnitsByCalendarId(xid);
		if (deletedViewableUnits < 0) {
			success = false; // 记录删除失败
		}

		int deletedViewableGroups = calCalendarMapper.deleteViewableGroupsByCalendarId(xid);
		if (deletedViewableGroups < 0) {
			success = false; // 记录删除失败
		}

		// 删除可新建者记录
		int deletedPublishablePersons = calCalendarMapper.deletePublishablePersonsByCalendarId(xid);
		if (deletedPublishablePersons < 0) {
			success = false; // 记录删除失败
		}

		int deletedPublishableUnits = calCalendarMapper.deletePublishableUnitsByCalendarId(xid);
		if (deletedPublishableUnits < 0) {
			success = false; // 记录删除失败
		}

		int deletedPublishableGroups = calCalendarMapper.deletePublishableGroupsByCalendarId(xid);
		if (deletedPublishableGroups < 0) {
			success = false; // 记录删除失败
		}

		// 删除可管理者记录
		int deletedManageablePersons = calCalendarMapper.deleteManageablePersonsByCalendarId(xid);
		if (deletedManageablePersons < 0) {
			success = false; // 记录删除失败
		}

		return success;
	}

	@Override
	public List<CalendarInfoVO> queryCalendarInfo() {
		QueryWrapper<CalCalendar> queryWrapper = new QueryWrapper<>();
		List<CalCalendar> calCalendars = baseMapper.selectList(queryWrapper);
		List<CalendarInfoVO> calendarInfoVOs = new ArrayList<>();
		for (CalCalendar calendar : calCalendars)
			calendarInfoVOs.add(msCalMapper.calendar2CalendarInfoVO(calendar));
		return calendarInfoVOs;
	}

	@Override
	public CalendarInfoVO queryCalendarInfo(String xid) {
		CalCalendar calCalendar = baseMapper.selectById(xid);
		if (calCalendar == null) throw new RuntimeException("查询失败");
		return msCalMapper.calendar2CalendarInfoVO(calCalendar);
	}

	@Override
	public Boolean modifyCalendarInfo(CalendarDTO calendarDTO) {
		int i = baseMapper.updateById(msCalMapper.calendarDTO2CalCalendar(calendarDTO));
		return i == 1;
	}
}
@Mapper(componentModel = "spring")
interface MsCalenderAssembleMapper {
	CalenderAssembleVO calenderAssembleVO(CalCalendar calendar);

	CalendarDTO calCalendarToCalendarDTO(CalCalendar calCalendar);
}
