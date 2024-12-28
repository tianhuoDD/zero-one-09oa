package com.zeroone.star.oaj2sysbasic.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.oaj2sysbasic.entity.FormTemplate;
import com.zeroone.star.oaj2sysbasic.mapper.TemplateMapper;
import com.zeroone.star.oaj2sysbasic.service.TemplateService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.system.basic.template.FormTemplateDTO;
import com.zeroone.star.project.query.j2.system.basic.template.FormTemplateQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j2.system.basic.template.FormTemplateVO;
import org.mapstruct.Mapper;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.time.LocalDateTime;

/**
 *
 */

@Mapper(componentModel = "spring")
interface MsTemplateMapper{
    /**
     * 将模板转换为DTO
     * @param template
     * @return
     */
    FormTemplateDTO Template2Dto(FormTemplate template);

    /**
     * 将DTO转换为模板
     * @param templateDTO
     * @return
     */
    FormTemplate Dto2Template(FormTemplateDTO templateDTO);
}
@Service
public class TemplateServiceImpl extends ServiceImpl<TemplateMapper, FormTemplate> implements TemplateService {

    @Resource
    MsTemplateMapper msTemplateMapper;

    @Resource
    TemplateMapper templateMapper;

    @Override
    public PageDTO<FormTemplateDTO> listAll(FormTemplateQuery query) {
        //构建分页对象
        Page<FormTemplate> page = new Page<>(query.getPageIndex(), query.getPageSize());
        //构建查询条件
        QueryWrapper<FormTemplate> queryWrapper = new QueryWrapper<>();
        queryWrapper.like("xname", query.getName());
        //执行查询
        Page<FormTemplate> result = baseMapper.selectPage(page, queryWrapper);
        //转换结果
        return PageDTO.create(result, msTemplateMapper::Template2Dto);
    }

    @Override
    public JsonVO<FormTemplateDTO> updateFormTemplate(FormTemplateDTO formTemplateDTO) {
        FormTemplate formTemplate=msTemplateMapper.Dto2Template(formTemplateDTO);
        String xid=formTemplate.getXid();
        if(xid==null&&xid.isEmpty())
            return JsonVO.fail(null);
//        formTemplate.setXupdateTime(LocalDateTime.now());
        templateMapper.updateformTemplate(formTemplate);
        return JsonVO.success(msTemplateMapper.Template2Dto(formTemplate));
    }


    /**
     * 新增模板
     * */
    @Override
    public void insTemplate(FormTemplateDTO templateDTO) {
        FormTemplate formTemplate=new FormTemplate();
        BeanUtils.copyProperties(templateDTO,formTemplate);
        templateMapper.insert(formTemplate);
    }
    /**
     * 删除模板
     * */
    @Override
    public void delTemplate(String xid) {
        templateMapper.deleteById(xid);
    }

    /**
     * 获取模板详情
     * */
    @Override
    public FormTemplateVO queryTemplate(String id) {
        FormTemplate formTemplate = templateMapper.selectById(id);
        FormTemplateVO formTemplateVO=new FormTemplateVO();
        if(formTemplate==null)return null;
        BeanUtils.copyProperties(formTemplate,formTemplateVO);
        return formTemplateVO;
    }

}
