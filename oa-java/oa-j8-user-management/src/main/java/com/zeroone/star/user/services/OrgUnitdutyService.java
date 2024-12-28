package com.zeroone.star.user.services;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.j8.user.role_position.AddUserPositionDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j8.user.role_position.UnitDutyVO;
import com.zeroone.star.user.entity.OrgUnitduty;
import java.util.List;

/**
 * @author Sleepyhead-Desktop
 * @description 针对表【org_unitduty】的数据库操作Service
 * @createDate 2024-10-24 20:49:30
 */
public interface OrgUnitdutyService extends IService<OrgUnitduty> {

    JsonVO<String> addUserPosition(AddUserPositionDTO addUserPositionDTO);

    JsonVO<List<UnitDutyVO>> getUnitDutyList(String unitId);
}
