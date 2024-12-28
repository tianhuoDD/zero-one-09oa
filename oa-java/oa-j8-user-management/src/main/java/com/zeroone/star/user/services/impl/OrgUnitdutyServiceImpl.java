package com.zeroone.star.user.services.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.j8.user.role_position.AddUserPositionDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j8.user.role_position.UnitDutyVO;
import com.zeroone.star.user.entity.OrgUnitduty;
import com.zeroone.star.user.entity.OrgUnitdutyIdentitylist;
import com.zeroone.star.user.mapper.OrgIdentityMapper;
import com.zeroone.star.user.mapper.OrgUnitdutyIdentitylistMapper;
import com.zeroone.star.user.mapper.OrgUnitdutyMapper;
import com.zeroone.star.user.services.OrgUnitdutyService;
import java.util.List;
import java.util.stream.Collectors;
import javax.annotation.Resource;
import org.springframework.stereotype.Service;

/**
 * @author Sleepyhead-Desktop
 * @description 针对表【org_unitduty】的数据库操作Service实现
 * @createDate 2024-10-24 20:49:30
 */
@Service
public class OrgUnitdutyServiceImpl extends ServiceImpl<OrgUnitdutyMapper, OrgUnitduty>
    implements OrgUnitdutyService {

    @Resource
    OrgUnitdutyMapper orgUnitdutyMapper;

    @Resource
    OrgUnitdutyIdentitylistMapper orgUnitdutyIdentitylistMapper;

    @Resource
    OrgIdentityMapper orgIdentityMapper;

    @Override
    public JsonVO<String> addUserPosition(AddUserPositionDTO addUserPositionDTO) {
        // 校验是否存在
        if (orgUnitdutyMapper.selectById(addUserPositionDTO.getUnitdutyId()) == null) {
            return JsonVO.fail("不存在此ID " + addUserPositionDTO.getUnitdutyId());
        }
        if (orgIdentityMapper.selectById(addUserPositionDTO.getIdentity()) == null) {
            return JsonVO.fail("不存在此ID " + addUserPositionDTO.getIdentity());
        }
        LambdaQueryWrapper<OrgUnitdutyIdentitylist> queryWrapper = new LambdaQueryWrapper<>();
        queryWrapper.eq(OrgUnitdutyIdentitylist::getUnitdutyXid, addUserPositionDTO.getUnitdutyId())
            .eq(OrgUnitdutyIdentitylist::getXidentitylist, addUserPositionDTO.getIdentity());
        if (orgUnitdutyIdentitylistMapper.selectOne(queryWrapper) != null) {
            return JsonVO.fail("已存在此职务");
        }

        OrgUnitdutyIdentitylist orgUnitdutyIdentitylist = new OrgUnitdutyIdentitylist();
        orgUnitdutyIdentitylist.setUnitdutyXid(addUserPositionDTO.getUnitdutyId());
        orgUnitdutyIdentitylist.setXidentitylist(addUserPositionDTO.getIdentity());
        orgUnitdutyIdentitylistMapper.insert(orgUnitdutyIdentitylist);
        return JsonVO.success("success");
    }

    @Override
    public JsonVO<List<UnitDutyVO>> getUnitDutyList(String unitId) {
        LambdaQueryWrapper<OrgUnitduty> queryWrapper = new LambdaQueryWrapper<>();
        queryWrapper.eq(OrgUnitduty::getXunit, unitId);
        List<UnitDutyVO> unitduties = orgUnitdutyMapper.selectList(queryWrapper).stream().map(
                orgUnitduty -> {
                    UnitDutyVO unitDutyVO = new UnitDutyVO();
                    BeanUtil.copyProperties(orgUnitduty, unitDutyVO);
                    return unitDutyVO;
                }
            )
            .collect(Collectors.toList());
        return JsonVO.success(unitduties);
    }
}




