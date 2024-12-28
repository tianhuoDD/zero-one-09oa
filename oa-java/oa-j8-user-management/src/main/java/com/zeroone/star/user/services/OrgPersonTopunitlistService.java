package com.zeroone.star.user.services;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j8.user.role_position.UnitVO;
import com.zeroone.star.user.entity.OrgPersonTopunitlist;
import java.util.List;

/**
 * @author Sleepyhead-Desktop
 * @description 针对表【org_person_topunitlist】的数据库操作Service
 * @createDate 2024-10-24 20:49:30
 */
public interface OrgPersonTopunitlistService extends IService<OrgPersonTopunitlist> {

    JsonVO<List<UnitVO>> selectTopUnitListByUserId(String userId);
}
