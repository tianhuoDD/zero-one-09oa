package com.zeroone.star.cmshome.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.cmshome.mapper.GetColumnCategoryMapper;
import com.zeroone.star.cmshome.service.IGetColumnCategoryService;
import com.zeroone.star.project.query.j5.cmshome.GetColumnCategory;
import com.zeroone.star.project.vo.j5.cmshome.GetColumnCategoryVO;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class GetColumnCategoryServiceImpl extends ServiceImpl<GetColumnCategoryMapper, GetColumnCategory> implements IGetColumnCategoryService {

    @Override
    public List<GetColumnCategoryVO> getColumnCategory() {
        List<GetColumnCategory> list = baseMapper.list();
        return BeanUtil.copyToList(list, GetColumnCategoryVO.class);
    }
}
