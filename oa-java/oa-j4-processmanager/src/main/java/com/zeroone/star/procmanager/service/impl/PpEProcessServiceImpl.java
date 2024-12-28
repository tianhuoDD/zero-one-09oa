package com.zeroone.star.procmanager.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.process.PpEProcessPageDTO;
import com.zeroone.star.project.query.j4.pocess.PpEProcessQuery;
import com.zeroone.star.procmanager.entity.PpEProcess;
import com.zeroone.star.procmanager.mapper.PpEProcessMapper;
import com.zeroone.star.procmanager.service.IPpEProcessService;
import org.mapstruct.Mapper;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;
import java.util.Map;


@Mapper(componentModel = "spring")
interface MsPpEProcessPageMapper{
    /**
     * 将PpEProcess do转换为PpEProcessPageDto
     * @param ppEProcess do对象
     * @return 转换结果
     */
    PpEProcessPageDTO ppEProcess2PpEprocessPageDTO(PpEProcess ppEProcess);

}

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author qy
 * @since 2024-10-21
 */
@Service
public class PpEProcessServiceImpl extends ServiceImpl<PpEProcessMapper, PpEProcess> implements IPpEProcessService {

    @Resource
    MsPpEProcessPageMapper msPpEProcessPageMapper;


    @Override
    public List<Map<String, Object>> countCategory() {
        QueryWrapper<PpEProcess> queryWrapper=new QueryWrapper<>();
        // 使用 QueryWrapper 构建查询条件
        queryWrapper.select("xcategory", "count(*) as count");
        queryWrapper.groupBy("xcategory");
        // 执行查询并返回结果
        return baseMapper.selectMaps(queryWrapper);
    }

    @Override
    public PageDTO<PpEProcessPageDTO> listAll(PpEProcessQuery query) {
        //构建分页对象
        Page<PpEProcess> page=new Page<>(query.getPageIndex(), query.getPageSize());
        //构建查询条件
        QueryWrapper<PpEProcess> queryWrapper=new QueryWrapper<>();

        if (query != null) {
            if (query.getXname() != null && !query.getXname().isEmpty()) {
                queryWrapper.like("xname", query.getXname());
            }
            if (query.getXid() != null && !query.getXid().isEmpty()) {
                queryWrapper.like("xid", query.getXid());
            }
            if (query.getXalias() != null && !query.getXalias().isEmpty()) {
                queryWrapper.like("xalias", query.getXalias());
            }
            if (query.getXcategory() != null && !query.getXcategory().isEmpty()) {
                queryWrapper.like("xcategory", query.getXcategory());
            }
            if (query.getXapplication() != null && !query.getXapplication().isEmpty()) {
                queryWrapper.like("xapplication", query.getXapplication());
            }

//TODO 待制作
//            if (query.getXcreateTime() != null && !query.getXcreateTime().isEmpty()) {
//                queryWrapper.like("xcreateTime", query.getXcreateTime()); // 注意：这通常不是处理日期的正确方式
//            }
//            if (query.getXupdateTime() != null && !query.getXupdateTime().isEmpty()) {
//                queryWrapper.like("xupdateTime", query.getXupdateTime()); // 注意：这通常不是处理日期的正确方式
//            }

            if (query.getXcreatorPerson() != null && !query.getXcreatorPerson().isEmpty()) {
                queryWrapper.like("xcreatorPerson", query.getXcreatorPerson());
            }
        }
        //执行查询
        Page<PpEProcess> resultByName = baseMapper.selectPage(page, queryWrapper);
        return PageDTO.create(resultByName,msPpEProcessPageMapper::ppEProcess2PpEprocessPageDTO);
    }

}
