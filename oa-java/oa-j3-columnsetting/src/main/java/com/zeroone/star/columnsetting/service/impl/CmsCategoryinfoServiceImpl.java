package com.zeroone.star.columnsetting.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.columnsetting.entity.CmsCategoryinfo;
import com.zeroone.star.columnsetting.mapper.CmsCategoryinfoMapper;
import com.zeroone.star.columnsetting.service.ICmsCategoryinfoService;
import com.zeroone.star.project.j3.sortallocation.dto.CategoryDTO;
import com.zeroone.star.project.j3.sortallocation.vo.CategoryVO;

import org.mapstruct.Mapper;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.ArrayList;
import java.util.List;

@Mapper(componentModel = "spring")
interface MsCategoryinfoMapper {
    CategoryDTO categoryinfo2CategoryDTO(CmsCategoryinfo cmsCategoryinfo);
    List<CategoryDTO> categoryinfo2CategoryDTOList(List<CmsCategoryinfo> cmsCategoryinfoList);
    CategoryVO categoryinfo2CategoryVO(CmsCategoryinfo cmsCategoryinfo);
    List<CategoryVO> categoryinfo2CategoryVOList(List<CmsCategoryinfo> cmsCategoryinfoList);
}

@Service
public class CmsCategoryinfoServiceImpl extends ServiceImpl <CmsCategoryinfoMapper, CmsCategoryinfo> implements ICmsCategoryinfoService {
    @Resource
    MsCategoryinfoMapper msCategoryinfoMapper;
    @Resource
    CmsCategoryinfoMapper cmsCategoryinfoMapper;

    //获取所有栏目分类
    @Override
    public List<CategoryVO> listAll(String appId) {

        //构建查询对象
        QueryWrapper<CmsCategoryinfo> queryWrapper = new QueryWrapper<>();
        //设置查询条件
        queryWrapper.eq("xappId", appId);
        //执行查询
        List<CmsCategoryinfo> cmsCategoryinfoList=cmsCategoryinfoMapper.selectList(queryWrapper);

        //转换为VO对象
        List<CategoryVO> list = new ArrayList<>();
        for(CmsCategoryinfo cmsCategoryinfo : cmsCategoryinfoList)
        {
            CategoryVO categoryvo=new CategoryVO();
            if(cmsCategoryinfo.getXappId()!=null) categoryvo.setAppId(cmsCategoryinfo.getXappId());
            if (cmsCategoryinfo.getXcategoryAlias() != null) categoryvo.setCategoryAlias(cmsCategoryinfo.getXcategoryAlias());
            if (cmsCategoryinfo.getXcategoryName() != null) categoryvo.setCategoryName(cmsCategoryinfo.getXcategoryName());
            if (cmsCategoryinfo.getXdistributeFactor() != null)    categoryvo.setDistributeFactor(cmsCategoryinfo.getXdistributeFactor());
            if (cmsCategoryinfo.getXsendNotify() != null) categoryvo.setSendNotify(cmsCategoryinfo.getXsendNotify());
            if (cmsCategoryinfo.getXdocumentType() != null) categoryvo.setDocumentType(cmsCategoryinfo.getXdocumentType());
            if (cmsCategoryinfo.getXworkflowAppName() != null) categoryvo.setWorkflowAppName(cmsCategoryinfo.getXworkflowAppName());
            if (cmsCategoryinfo.getXworkflowName() != null) categoryvo.setWorkflowName(cmsCategoryinfo.getXworkflowName());
            if(cmsCategoryinfo.getXid() != null) categoryvo.setId(cmsCategoryinfo.getXid());

            //设置管理者、发布者、查看者
            categoryvo.setManager(
                    cmsCategoryinfoMapper.getManageablegroupList(cmsCategoryinfo.getXid())
                    + cmsCategoryinfoMapper.getManageablepersonList(cmsCategoryinfo.getXid())
                    + cmsCategoryinfoMapper.getManageableunitList(cmsCategoryinfo.getXid()));

            categoryvo.setPublisher(
                    cmsCategoryinfoMapper.getPublishablegroupList(cmsCategoryinfo.getXid())
                + cmsCategoryinfoMapper.getPublishablepersonList(cmsCategoryinfo.getXid())
                + cmsCategoryinfoMapper.getPublishableunitList(cmsCategoryinfo.getXid()));

            categoryvo.setViewableRange(
                    cmsCategoryinfoMapper.getViewablegroupList(cmsCategoryinfo.getXid())
                    + cmsCategoryinfoMapper.getViewablepersonList(cmsCategoryinfo.getXid())
                    + cmsCategoryinfoMapper.getViewableunitList(cmsCategoryinfo.getXid()));
            list.add(categoryvo);
        }
        return list;
    }


    //修改栏目分类
    @Override
    public CategoryDTO updateCategory(CategoryDTO categorydto)
    {
        CmsCategoryinfo categoryinfo=new CmsCategoryinfo();
        QueryWrapper<CmsCategoryinfo> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("xid", categorydto.getId());
        categoryinfo = cmsCategoryinfoMapper.selectOne(queryWrapper);
        //主表属性修改的条件
        if (categorydto.getCategoryName() != null) categoryinfo.setXcategoryName(categorydto.getCategoryName());
        if (categorydto.getDistributeFactor() != null) categoryinfo.setXdistributeFactor(categorydto.getDistributeFactor());
        if (categorydto.getCategoryAlias() != null) categoryinfo.setXcategoryAlias(categorydto.getCategoryAlias());
        if (categorydto.getSendNotify() != null) categoryinfo.setXsendNotify(categorydto.getSendNotify());
        if (categorydto.getDocumentType() != null) categoryinfo.setXdocumentType(categorydto.getDocumentType());
        if (categorydto.getWorkflowAppName() != null) categoryinfo.setXworkflowAppName(categorydto.getWorkflowAppName());
        if (categorydto.getWorkflowName() != null) categoryinfo.setXworkflowName(categorydto.getWorkflowName());
        //执行修改
        cmsCategoryinfoMapper.update(categoryinfo, new QueryWrapper<CmsCategoryinfo>().eq("xid", categoryinfo.getXid()));

        categorydto.setId(categoryinfo.getXid());
        //设置发布者
        cmsCategoryinfoMapper.updateManageablegroupList(categorydto.getXmanageableGroupList(),categoryinfo.getXid());
        //设置管理者
        cmsCategoryinfoMapper.updateManageablepersonList(categorydto.getXmanageablePersonList(),categoryinfo.getXid());
        //设置管理单位
        cmsCategoryinfoMapper.updateManageableunitList(categorydto.getXmanageableUnitList(),categoryinfo.getXid());
        //设置发布组
        cmsCategoryinfoMapper.updatePublishablegroupList(categorydto.getXpublishableGroupList(),categoryinfo.getXid());
        //设置发布人
        cmsCategoryinfoMapper.updatePublishablepersonList(categorydto.getXpublishablePersonList(),categoryinfo.getXid());
        //设置发布单位
        cmsCategoryinfoMapper.updatePublishableunitList(categorydto.getXpublishableUnitList(),categoryinfo.getXid());
        //设置查看者
        cmsCategoryinfoMapper.updateViewablegroupList(categorydto.getXviewableGroupList(),categoryinfo.getXid());
        //设置查看人
        cmsCategoryinfoMapper.updateViewablepersonList(categorydto.getXviewablePersonList(),categoryinfo.getXid());
        //设置查看单位
        cmsCategoryinfoMapper.updateViewableunitList(categorydto.getXviewableUnitList(),categoryinfo.getXid());
        //将对象转换为DTO对象
        return categorydto;

    }

    //已完成
    //添加栏目分类
    @Override
    public String updateCategory(String name, String appId)
    {
        //构建查询条件
        QueryWrapper<CmsCategoryinfo> queryWrapper = new QueryWrapper<CmsCategoryinfo>();
        queryWrapper.eq("xcategoryName", name)
                .eq("xappId", appId);

        //执行查询
        CmsCategoryinfo cmsCategoryinfo = cmsCategoryinfoMapper.selectOne(queryWrapper);

        //如果存在则不添加
        if(cmsCategoryinfo!=null) return null;
        else
        {
            CmsCategoryinfo result=new CmsCategoryinfo();
            result.setXcategoryName(name);
            result.setXappId(appId);
            cmsCategoryinfoMapper.insert(result);
            QueryWrapper<CmsCategoryinfo> queryWrapper2 = new QueryWrapper<CmsCategoryinfo>();
            queryWrapper2.eq("xcategoryName", name)
                    .eq("xappId", appId);

            //执行查询
            CmsCategoryinfo cmsCategoryinfo2 = cmsCategoryinfoMapper.selectOne(queryWrapper);
            //添加数据到关联表
            cmsCategoryinfoMapper.addManageablegroupList(cmsCategoryinfo2.getXid());
            cmsCategoryinfoMapper.addManageablepersonList(cmsCategoryinfo2.getXid());
            cmsCategoryinfoMapper.addManageableunitList(cmsCategoryinfo2.getXid());
            cmsCategoryinfoMapper.addPublishablegroupList(cmsCategoryinfo2.getXid());
            cmsCategoryinfoMapper.addPublishablepersonList(cmsCategoryinfo2.getXid());
            cmsCategoryinfoMapper.addPublishableunitList(cmsCategoryinfo2.getXid());
            cmsCategoryinfoMapper.addViewablegroupList(cmsCategoryinfo2.getXid());
            cmsCategoryinfoMapper.addViewablepersonList(cmsCategoryinfo2.getXid());
            cmsCategoryinfoMapper.addViewableunitList(cmsCategoryinfo2.getXid());

            return cmsCategoryinfo2.getXid();
        }
    }

    //已完成
    //根据name删除栏目分类
    public Boolean removeCategorybyId(String id)
    {
        //构建查询条件
        QueryWrapper<CmsCategoryinfo> queryWrapper = new QueryWrapper<CmsCategoryinfo>();
        queryWrapper.eq("xid", id);

        //执行查询
        CmsCategoryinfo cmsCategoryinfo = cmsCategoryinfoMapper.selectOne(queryWrapper);
        if (cmsCategoryinfo!= null) {
            // 如果查询到数据，执行删除操作并返回删除结果
            // 先删除管理组
            cmsCategoryinfoMapper.deleteManageablegroupList(cmsCategoryinfo.getXid());
            cmsCategoryinfoMapper.deleteManageablepersonList(cmsCategoryinfo.getXid());
            cmsCategoryinfoMapper.deleteManageableunitList(cmsCategoryinfo.getXid());
            cmsCategoryinfoMapper.deletePublishablegroupList(cmsCategoryinfo.getXid());
            cmsCategoryinfoMapper.deletePublishablepersonList(cmsCategoryinfo.getXid());
            cmsCategoryinfoMapper.deletePublishableunitList(cmsCategoryinfo.getXid());
            cmsCategoryinfoMapper.deleteViewablegroupList(cmsCategoryinfo.getXid());
            cmsCategoryinfoMapper.deleteViewablepersonList(cmsCategoryinfo.getXid());
            cmsCategoryinfoMapper.deleteViewableunitList(cmsCategoryinfo.getXid());
            return cmsCategoryinfoMapper.deleteById(cmsCategoryinfo.getXid()) > 0;
        } else {
            // 如果未查询到数据，返回false
            return false;
        }
    }
}
