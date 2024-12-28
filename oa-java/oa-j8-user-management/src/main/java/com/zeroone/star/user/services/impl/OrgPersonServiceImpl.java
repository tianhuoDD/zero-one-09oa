package com.zeroone.star.user.services.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.metadata.IPage;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j8.user.user.AddPersonDTO;
import com.zeroone.star.project.dto.j8.user.user.PersonDTO;
import com.zeroone.star.project.dto.j8.user.user.UpdatePersonDTO;
import com.zeroone.star.project.query.j8.user.user.UserQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.user.entity.OrgPerson;
import com.zeroone.star.user.mapper.OrgPersonMapper;
import com.zeroone.star.user.services.OrgPersonService;
import java.util.Date;
import java.util.List;
import java.util.stream.Collectors;
import javax.annotation.Resource;
import org.springframework.stereotype.Service;

/**
 * @author Sleepyhead-Desktop
 * @description 针对表【org_person】的数据库操作Service实现
 * @createDate 2024-10-24 20:49:30
 */
@Service
public class OrgPersonServiceImpl extends ServiceImpl<OrgPersonMapper, OrgPerson> implements OrgPersonService {

    @Resource
    private OrgPersonMapper orgPersonMapper;  // 注入 org_person 表 Mapper

    /**
     * 获取人员列表的分页信息
     *
     * @param userQuery 用户查询条件
     * @return 返回包含人员信息的 JsonVO 对象
     */
    @Override
    public JsonVO<PageDTO<PersonDTO>> getPersonList(UserQuery userQuery) {
        // 创建分页对象
        Page<OrgPerson> orgPersonPage = new Page<>(userQuery.getCurrentPage(), userQuery.getPageSize());

        // 查询用户信息并获取总记录数
        IPage<OrgPerson> result = (IPage<OrgPerson>) orgPersonMapper.getPersonList(orgPersonPage, userQuery);

        // 使用 BeanUtil 直接将 records 转换为 PersonDTO
        List<PersonDTO> personDTOList = result.getRecords().stream()
            .map(orgPerson -> {
                PersonDTO dto = new PersonDTO();
                BeanUtil.copyProperties(orgPerson, dto); // 使用 BeanUtil 复制属性
                return dto;
            })
            .collect(Collectors.toList());

        // 创建 PageDTO 对象并设置当前页数据列表
        PageDTO<PersonDTO> pageDTO = new PageDTO<>();
        pageDTO.setPageIndex((long) userQuery.getCurrentPage());
        pageDTO.setPageSize((long) userQuery.getPageSize());
        pageDTO.setTotal(result.getTotal()); // 设置总记录数
        pageDTO.setPages(result.getPages()); // 设置总页数
        pageDTO.setRows(personDTOList); // 设置当前页数据

        return JsonVO.success(pageDTO);
    }


    /**
     * 根据ID查询用户信息
     *
     * @param id 用户唯一标识
     * @return 查询结果，包含单个用户信息
     */
    @Override
    public PersonDTO getPersonById(String id) {
        PersonDTO personDTO = new PersonDTO();
        OrgPerson orgPerson = orgPersonMapper.selectById(id);
        BeanUtil.copyProperties(orgPerson, personDTO);
        return personDTO;
    }

    /**
     * 添加新用户
     *
     * @param addPersonDTO 用户信息
     * @return 操作结果
     */
    @Override
    public boolean addPerson(AddPersonDTO addPersonDTO) {
        OrgPerson orgPerson = new OrgPerson();
        BeanUtil.copyProperties(addPersonDTO, orgPerson);
        return orgPersonMapper.insert(orgPerson) > 0;
    }

    /**
     * 更新用户信息
     *
     * @param updatePersonDTO 用户信息
     * @return 操作结果
     */
    @Override
    public boolean updatePerson(UpdatePersonDTO updatePersonDTO) {
        OrgPerson orgPerson = new OrgPerson();
        // 将 DTO 转换为实体
        BeanUtil.copyProperties(updatePersonDTO, orgPerson);
        return orgPersonMapper.updateById(orgPerson) > 0;
    }

    /**
     * 删除用户信息
     *
     * @param id 用户唯一标识
     * @return 操作结果
     */
    @Override
    public boolean deletePerson(String id) {
        return orgPersonMapper.deleteById(id) > 0;
    }

    @Override
    public String disableUserByID(String userId) {
        String DISABLED = "DISABLED";
        OrgPerson person = this.getById(userId);
        if (person == null) {
            throw new RuntimeException("User not found");
        }
        person.setXstatus(DISABLED); // 设置为禁用
        this.updateById(person); // 更新用户信息
        return DISABLED;
    }

    @Override
    public String enableUser(String userId) {
        String ENABLED = "ENABLED"; // 假设 "ENABLED" 是表示启用的状态
        OrgPerson person = this.getById(userId);
        if (person == null) {
            throw new RuntimeException("User not found");
        }
        person.setXstatus(ENABLED); // 设置为启用
        this.updateById(person); // 更新用户信息
        return ENABLED;

    }

    @Override
    public String lockUser(String userId) {
        String LOCKED = "LOCKED"; // 假设 "LOCKED" 是表示锁定的状态
        OrgPerson person = this.getById(userId);
        if (person == null) {
            throw new RuntimeException("User not found");
        }
        person.setXstatusdes(LOCKED); // 设置为锁定
        this.updateById(person); // 更新用户信息
        return LOCKED;
    }

    @Override
    public String unlockUser(String userId) {
        String UNLOCKED = "UNLOCKED"; // 假设 "UNLOCKED" 是表示解锁的状态
        OrgPerson person = this.getById(userId);
        if (person == null) {
            throw new RuntimeException("User not found");
        }
        person.setXstatusdes(UNLOCKED); // 设置为解锁
        this.updateById(person); // 更新用户信息
        return UNLOCKED;
    }

    @Override
    public String setPasswordExpirationByID(String userId, Date expirationDate) {
        OrgPerson person = this.getById(userId);
        if (person == null) {
            throw new RuntimeException("User not found");
        }
        person.setXpasswordexpiredtime(expirationDate); // 设置密码过期时间
        this.updateById(person); // 更新用户信息
        return expirationDate.toString();
    }

    @Override
    public void resetUserPasswordByid(String userId) {
        OrgPerson person = this.getById(userId);
        if (person == null) {
            throw new RuntimeException("User not found");
        }
        person.setXpassword("123456"); // 设置新密码
        this.updateById(person); // 更新用户信息
    }
}




