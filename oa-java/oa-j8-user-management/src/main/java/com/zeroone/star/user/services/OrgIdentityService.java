package com.zeroone.star.user.services;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j8.user.user_identity.UserIdentityDTO;
import com.zeroone.star.project.query.j8.user.user_identity.UserIdentityQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j8.user.user_identity.UserIdentityVO;
import com.zeroone.star.user.entity.OrgIdentity;

/**
 * @author Sleepyhead-Desktop
 * @description 针对表【org_identity】的数据库操作Service
 * @createDate 2024-10-24 20:49:30
 */
public interface OrgIdentityService extends IService<OrgIdentity> {

    JsonVO<PageDTO<UserIdentityVO>> getIdentityList(UserIdentityQuery userIdentityQuery);

    boolean updateUserIdentity(UserIdentityDTO userIdentityDTO);
}
