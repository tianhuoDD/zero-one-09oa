package com.zeroone.star.procmanager.service.impl;


import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;

import com.zeroone.star.procmanager.entity.PpEForm;
import com.zeroone.star.procmanager.mapper.FormMapper;
import com.zeroone.star.procmanager.service.QueryFormService;


import com.zeroone.star.project.dto.j4.form.data.CategoryDTO;
import com.zeroone.star.project.dto.j4.form.data.FormInfoDTO;
import com.zeroone.star.project.dto.j4.form.data.FormListDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j4.form.data.CategoryVO;
import com.zeroone.star.project.vo.j4.form.data.FormInfoVO;
import com.zeroone.star.project.vo.j4.form.data.FormListVO;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

@Service
public class QueryFormServiceImpl implements QueryFormService
{

    @Resource
    private FormMapper formMapper;

    @Override
    public JsonVO<List<CategoryVO>> queryCategoryVO(CategoryDTO categoryDTO)
    {

        String xid = categoryDTO.getXid();
        String xapplication = categoryDTO.getXapplication();
        Boolean xhasMobile = categoryDTO.getXhasMobile();
        String xalias = categoryDTO.getXalias();

        String xname = categoryDTO.getXname();
        QueryWrapper<PpEForm> queryWrapper = new QueryWrapper<>();

        if (xid!= null) {
            queryWrapper.eq("xid", xid);
        }
        if (xapplication!= null) {
            queryWrapper.eq("xapplication", xapplication);
        }
        if (xhasMobile!= null) {
            queryWrapper.eq("xhasMobile", xhasMobile);
        }

        if (xalias!= null) {
            queryWrapper.eq("xalias", xalias);
        }

        if (xname!= null) {
            queryWrapper.like("xname", xname);
        }



        //查询
        List<PpEForm> ppEFormList = formMapper.selectList(queryWrapper);

        /**
         *转换成vo,并用hashSet去重
         */
        Set<CategoryVO> categoryVOSet = new HashSet<>();

        for (PpEForm ppEForm : ppEFormList) {
            CategoryVO categoryVO = new CategoryVO();
            categoryVO.setXcategory(ppEForm.getXcategory());
            categoryVOSet.add(categoryVO);
        }

        /**
         * 将set转换成list
         */
        List<CategoryVO> categoryVOList = new ArrayList<>(categoryVOSet);


        return JsonVO.success(categoryVOList);
    }

    @Override
    public List<FormListVO> queryFormList(FormListDTO formListDTO)
    {
        Page<PpEForm> page = new Page<>(formListDTO.getPageIndex(), formListDTO.getPageSize());

        QueryWrapper<PpEForm> queryWrapper = new QueryWrapper<>();

        if (formListDTO.getXid()!= null) {
            queryWrapper.eq("xid", formListDTO.getXid());
        }
        if (formListDTO.getXname()!= null) {
            queryWrapper.like("xname", formListDTO.getXname());
        }
        if (formListDTO.getXalias()!= null) {
            queryWrapper.like("xalias", formListDTO.getXalias());
        }
        if (formListDTO.getXperson()!= null) {
            queryWrapper.like("xperson", formListDTO.getXperson());
        }
        if (formListDTO.getXcategory()!= null) {
            queryWrapper.like("xcategory", formListDTO.getXcategory());
        }
        Page<PpEForm> result = formMapper.selectPage(page, queryWrapper);

        List<FormListVO> formListVOs = new ArrayList<>();
        for (PpEForm ppEForm : result.getRecords()) {
            formListVOs.add(convertToFormListVO(ppEForm));
        }
        return formListVOs;

    }

    // 转换
    private FormListVO convertToFormListVO(PpEForm ppEForm) {
        FormListVO formListVO = new FormListVO();
        formListVO.setXid(ppEForm.getXid());
        formListVO.setXname(ppEForm.getXname());
        formListVO.setXcategory(ppEForm.getXcategory());
        formListVO.setXalias(ppEForm.getXalias());
        formListVO.setXcreateTime(ppEForm.getXcreateTime());
        formListVO.setXperson(ppEForm.getXlastUpdatePerson());
        formListVO.setXapplication(ppEForm.getXapplication());
        formListVO.setXhasMobile(ppEForm.getXhasMobile());
        formListVO.setXdescription(ppEForm.getXdescription());
        formListVO.setXdata(ppEForm.getXdata());
        return formListVO;
    }



    @Override
    public FormInfoVO queryFormInfo(FormInfoDTO formInfoDTO) {
        String xid = formInfoDTO.getXid();
        return formMapper.queryFormInfo(xid);

    }
}
