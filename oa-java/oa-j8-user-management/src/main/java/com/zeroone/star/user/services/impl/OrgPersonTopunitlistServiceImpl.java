package com.zeroone.star.user.services.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j8.user.role_position.UnitVO;
import com.zeroone.star.user.entity.OrgPersonTopunitlist;
import com.zeroone.star.user.entity.OrgUnit;
import com.zeroone.star.user.mapper.OrgPersonTopunitlistMapper;
import com.zeroone.star.user.mapper.OrgUnitMapper;
import com.zeroone.star.user.services.OrgPersonTopunitlistService;
import java.util.List;
import java.util.Objects;
import java.util.stream.Collectors;
import javax.annotation.Resource;
import org.springframework.beans.BeanUtils;
import org.springframework.stereotype.Service;

/**
 * @author Sleepyhead-Desktop
 * @description 针对表【org_person_topunitlist】的数据库操作Service实现
 * @createDate 2024-10-24 20:49:30
 */
@Service
public class OrgPersonTopunitlistServiceImpl extends ServiceImpl<OrgPersonTopunitlistMapper, OrgPersonTopunitlist>
    implements OrgPersonTopunitlistService {

    @Resource
    private OrgPersonTopunitlistMapper orgPersonTopunitlistMapper;

    @Resource
    OrgUnitMapper orgUnitMapper;


    @Override
    public JsonVO<List<UnitVO>> selectTopUnitListByUserId(String userId) {
        // 1. 参数校验
        if (userId == null || userId.isEmpty()) {
            return JsonVO.fail(null);
        }

        // 2. 构建查询条件
        LambdaQueryWrapper<OrgPersonTopunitlist> queryWrapper = new LambdaQueryWrapper<>();
        queryWrapper.eq(OrgPersonTopunitlist::getPersonXid, userId);

        try {
            // 3. 查询数据并通过属性拷贝转换为 UnitVO 列表
            List<UnitVO> unitVOList = orgPersonTopunitlistMapper.selectList(queryWrapper).stream()
                .map(orgPersonTopunitlist -> {
                    OrgUnit orgUnit = orgUnitMapper.selectById(orgPersonTopunitlist.getXtopunitlist());
                    if (orgUnit != null) {
                        UnitVO unitVO = new UnitVO();
                        BeanUtils.copyProperties(orgUnit, unitVO); // 使用属性拷贝
                        return unitVO;
                    }
                    return null;
                })
                .filter(Objects::nonNull)
                .collect(Collectors.toList());

            // 4. 返回成功结果
            return JsonVO.success(unitVOList);

        } catch (Exception e) {
            // 5. 异常处理
            return JsonVO.fail(null);
        }
    }

}




