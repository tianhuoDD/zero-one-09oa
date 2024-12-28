package com.zeroone.star.cmshome.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.cmshome.mapper.GetColumnListMapper;
import com.zeroone.star.cmshome.service.IGetColumnListService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.cmshome.GetColumnListDTO;
import com.zeroone.star.project.query.j5.cmshome.GetColumnList;
import com.zeroone.star.project.vo.j5.cmshome.GetColumnListVO;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;

@Service
public class GetColumnListServiceImpl extends ServiceImpl<GetColumnListMapper, GetColumnList> implements IGetColumnListService {

    @Override
    public PageDTO<GetColumnListVO> page(GetColumnListDTO getColumnListDTO) {
        PageDTO<GetColumnListVO> pageDTO = new PageDTO<>();
        // 将分页信息赋值给pageDTO
        pageDTO.setPageIndex(getColumnListDTO.getPageIndex());
        pageDTO.setPageSize(getColumnListDTO.getPageSize());
        getColumnListDTO.setPageIndex((getColumnListDTO.getPageIndex() - 1) * getColumnListDTO.getPageSize());
        // 查询栏目列表
        List<GetColumnList> columnList = baseMapper.getColumnList(getColumnListDTO);
        pageDTO.setTotal((long)columnList.size());
        // 将栏目列表实体类转换成VO类型，并赋值给pageDTO
        List<GetColumnListVO> columnListVO = BeanUtil.copyToList(columnList, GetColumnListVO.class);

        List<String> category = new ArrayList<>();
        List<String> title = new ArrayList<>();
        for (GetColumnList g : columnList) {
            if (!category.contains(g.getCategoryName())) {
                category.add(g.getCategoryName());
            }
            if (!title.contains(g.getTitle())) {
                title.add(g.getTitle());
            }
        }

        for (GetColumnListVO g : columnListVO) {
            g.setTitle(new ArrayList<>(category));
            g.setTitle(new ArrayList<>(title));
        }

        pageDTO.setRows(columnListVO);

        return pageDTO;
    }
}
