package com.zeroone.star.user.services;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j8.user.user.AddPersonDTO;
import com.zeroone.star.project.dto.j8.user.user.PersonDTO;
import com.zeroone.star.project.dto.j8.user.user.UpdatePersonDTO;
import com.zeroone.star.project.query.j8.user.user.UserQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.user.entity.OrgPerson;
import java.util.Date;

/**
 * @author Sleepyhead-Desktop
 * @description 针对表【org_person】的数据库操作Service
 * @createDate 2024-10-24 20:49:30
 */
public interface OrgPersonService extends IService<OrgPerson> {

    // 获取人员列表，支持分页和条件查询
    JsonVO<PageDTO<PersonDTO>> getPersonList(UserQuery userQuery);

    // 根据ID获取人员信息
    PersonDTO getPersonById(String id);

    // 添加新人员
    boolean addPerson(AddPersonDTO addPersonDTO);

    // 更新人员信息
    boolean updatePerson(UpdatePersonDTO updatePersonDTO);

    // 删除人员
    boolean deletePerson(String id);

    String disableUserByID(String userId);

    String enableUser(String userId);

    String lockUser(String userId);

    String unlockUser(String userId);

    String setPasswordExpirationByID(String userId, Date expirationDate);

    void resetUserPasswordByid(String userId);
}
