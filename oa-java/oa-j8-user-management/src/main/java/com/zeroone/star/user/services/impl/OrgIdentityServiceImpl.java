package com.zeroone.star.user.services.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.metadata.IPage;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j8.user.user.PersonDTO;
import com.zeroone.star.project.dto.j8.user.user_identity.UserIdentityDTO;
import com.zeroone.star.project.query.j8.user.user_identity.UserIdentityQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j8.user.user.PersonVO;
import com.zeroone.star.project.vo.j8.user.user_identity.UserIdentityVO;
import com.zeroone.star.user.entity.OrgIdentity;
import com.zeroone.star.user.entity.OrgPerson;
import com.zeroone.star.user.entity.OrgUnitduty;
import com.zeroone.star.user.entity.OrgUnitdutyIdentitylist;
import com.zeroone.star.user.mapper.OrgIdentityMapper;
import com.zeroone.star.user.mapper.OrgUnitdutyIdentitylistMapper;
import com.zeroone.star.user.mapper.OrgUnitdutyMapper;
import com.zeroone.star.user.services.OrgIdentityService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;
import java.util.stream.Collectors;

/**
 * @author Sleepyhead-Desktop
 * @description 针对表【org_identity】的数据库操作Service实现
 * @createDate 2024-10-24 20:49:30
 */
@Service
public class OrgIdentityServiceImpl extends ServiceImpl<OrgIdentityMapper, OrgIdentity>
    implements OrgIdentityService {

    @Autowired
    private OrgIdentityMapper orgIdentityMapper;
    @Autowired
    private OrgUnitdutyIdentitylistMapper orgUnitdutyIdentitylistMapper;
    @Autowired
    private OrgUnitdutyMapper dutyMapper;

    /**
     * 获取身份列表
     * @param userIdentityQuery
     * @return
     */
    @Override
    public JsonVO<PageDTO<UserIdentityVO>> getIdentityList(UserIdentityQuery userIdentityQuery) {
        Page<OrgIdentity> orgIdentityPage = new Page<>(userIdentityQuery.getPageIndex(), userIdentityQuery.getPageSize());

        IPage<OrgIdentity> result = orgIdentityMapper.getIdentityList(orgIdentityPage, userIdentityQuery);

        List<UserIdentityVO> identityDTOList = result.getRecords().stream()
                .map(orgIdentity -> {
                    UserIdentityVO vo = new UserIdentityVO();
                    BeanUtil.copyProperties(orgIdentity, vo); // 使用 BeanUtil 复制属性
                    // 获取 duty_identity 表中的 xid
                    String dutyId = orgUnitdutyIdentitylistMapper.selectUnitdutyXidByXidentityList(orgIdentity.getXid());
                    if (dutyId != null) {
                        // 根据 dutyId 获取 xname
                        String position = dutyMapper.getXnameByDutyId(dutyId);
                        vo.setPosition(position);
                    }//orgIdentity.getXid()是唯一标识，需要根据这个值去查一下unitduty_identity表的xid,再在unitduty表里查一下xid对应的xname(职务名)
                    return vo;
                })
                .collect(Collectors.toList());
        PageDTO<UserIdentityVO> pageVO = new PageDTO<>();
        pageVO.setPageIndex((long) userIdentityQuery.getPageIndex());
        pageVO.setPageSize((long) userIdentityQuery.getPageSize());
        pageVO.setTotal(result.getTotal()); // 设置总记录数
        pageVO.setPages(result.getPages()); // 设置总页数
        pageVO.setRows(identityDTOList); // 设置当前页数据
        return JsonVO.success(pageVO);

    }

    /**
     * 更新用户身份
     * @param userIdentityDTO 用户更新的身份信息
     * @return 操作结果
     */
    @Override
    public boolean updateUserIdentity(UserIdentityDTO userIdentityDTO) {
        OrgIdentity orgIdentity = new OrgIdentity();
        // 将 DTO 转换为实体
        BeanUtil.copyProperties(userIdentityDTO, orgIdentity);
        String xperson = orgIdentity.getXperson();
        boolean xmajor = orgIdentity.getXmajor();

        // 使用 Wrapper 查询当前 xperson 对应的所有记录
        QueryWrapper<OrgIdentity> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("xperson", xperson);
        List<OrgIdentity> existingRecords = orgIdentityMapper.selectList(queryWrapper);

        // 如果 xmajor 为 true，则将所有记录的 xmajor 更新为 false
        if (xmajor) {
            for (OrgIdentity record : existingRecords) {
                record.setXmajor(false);
                orgIdentityMapper.updateById(record);
            }
        }
        return orgIdentityMapper.updateById(orgIdentity) > 0;
    }

}




