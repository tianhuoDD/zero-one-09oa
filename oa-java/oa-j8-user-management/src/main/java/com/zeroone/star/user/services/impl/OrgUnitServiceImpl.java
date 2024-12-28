package com.zeroone.star.user.services.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j8.user.role_position.UnitVO;
import com.zeroone.star.user.entity.OrgUnit;
import com.zeroone.star.user.mapper.OrgUnitMapper;
import com.zeroone.star.user.services.OrgUnitService;
import java.util.List;
import java.util.stream.Collectors;
import javax.annotation.Resource;
import org.springframework.beans.BeanUtils;
import org.springframework.stereotype.Service;

/**
 * @author Sleepyhead-Desktop
 * @description 针对表【org_unit】的数据库操作Service实现
 * @createDate 2024-10-24 20:49:30
 */
@Service
public class OrgUnitServiceImpl extends ServiceImpl<OrgUnitMapper, OrgUnit>
    implements OrgUnitService {

    @Resource
    OrgUnitMapper orgUnitMapper;

    @Override
    public JsonVO<List<UnitVO>> getChildrenUnitList(String unitId) {
        LambdaQueryWrapper<OrgUnit> queryWrapper = new LambdaQueryWrapper<>();
        queryWrapper.eq(OrgUnit::getXsuperior, unitId);
        List<UnitVO> units = orgUnitMapper.selectList(queryWrapper).stream().map(
                orgUnit -> {
                    UnitVO unitVO = new UnitVO();
                    BeanUtils.copyProperties(orgUnit, unitVO); // 使用属性拷贝
                    return unitVO;
                }
            )
            .collect(Collectors.toList());
        return JsonVO.success(units);
    }
}




