package com.zeroone.star.basicinformation.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.basicinformation.entity.CmsAppinfo;
import com.zeroone.star.basicinformation.entity.CmsForm;
import com.zeroone.star.basicinformation.mapper.CmsAppinfoMapper;
import com.zeroone.star.basicinformation.mapper.CmsFormMapper;
import com.zeroone.star.basicinformation.service.ICmsAppinfoService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j3.appinfo.dto.AppDTO;
import com.zeroone.star.project.j3.appinfo.dto.AppTypeDTO;
import com.zeroone.star.project.j3.appinfo.query.AppQuery;
import com.zeroone.star.project.j3.columnbasicinformation.dto.AppinfoDTO;
import com.zeroone.star.project.j3.columnbasicinformation.dto.BasicinformationDTO;
import com.zeroone.star.project.j3.columnbasicinformation.query.BasicinformationQuery;
import com.zeroone.star.project.j3.columnbasicinformation.vo.BasicinformationVo;
import org.mapstruct.Mapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.Resource;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;

@Mapper(componentModel = "spring")
interface MsAppinfoMapper{
    /**
     * 将do转换为dto
     * @param cmsAppinfo
     * @return
     */
    BasicinformationDTO appinfo2basicinformationDTO(CmsAppinfo cmsAppinfo);
    AppDTO toAppDTO(CmsAppinfo cmsAppinfo);
    AppinfoDTO appinfo2AppinfoDTO(CmsAppinfo cmsAppinfo);

    BasicinformationVo toBasicinformationVo(BasicinformationDTO basicinformationDTO);
}


/**
 * <p>
 *  服务实现类
 * </p>
 *
 */
@Service
@Transactional
public class CmsAppinfoServiceImpl extends ServiceImpl<CmsAppinfoMapper, CmsAppinfo> implements ICmsAppinfoService {
    @Resource
    MsAppinfoMapper msAppinfoMapper;

    @Resource
    CmsAppinfoMapper cmsAppinfoMapper;

    @Autowired
    private CmsFormMapper cmsFormMapper;

    @Transactional(rollbackFor = Exception.class)
    @Override
    public BasicinformationVo queryBasicinformation(BasicinformationQuery basicinformationQuery) {
        BasicinformationDTO dto = cmsAppinfoMapper.basicinformation(basicinformationQuery.getXid());
        List<String> form = cmsAppinfoMapper.queryform(basicinformationQuery.getXid());
        BasicinformationVo result = msAppinfoMapper.toBasicinformationVo(dto);
        result.setWriteForm(form);
        result.setReadForm(form);
        return result;
    }

    @Transactional(rollbackFor = Exception.class)
    @Override
    public BasicinformationVo updateBasicinformation(BasicinformationDTO basicinformationDTO) {
        //在数据表中查询到该数据
        CmsAppinfo appinfo = new CmsAppinfo();
        appinfo.setXid(basicinformationDTO.getXid());
        appinfo.setXappAlias(basicinformationDTO.getXappAlias());
        appinfo.setXappName(basicinformationDTO.getXappName());
        appinfo.setXdescription(basicinformationDTO.getXdescription());
        appinfo.setXappInfoSeq(basicinformationDTO.getXappInfoSeq());
        appinfo.setXappType(basicinformationDTO.getXappType());
        appinfo.setXupdateTime(LocalDateTime.now());
        appinfo.setXdefaultReadForm(basicinformationDTO.getReadForm().toString());
        appinfo.setXdefaultEditForm(basicinformationDTO.getWriteForm().toString());
        appinfo.setXappIcon(basicinformationDTO.getXappIcon());
        cmsAppinfoMapper.updateId(appinfo);
        BasicinformationDTO dto = msAppinfoMapper.appinfo2basicinformationDTO(appinfo);
        BasicinformationVo result = msAppinfoMapper.toBasicinformationVo(dto);
        return result;
    }

    @Override
    public List<AppTypeDTO> listAllType() {
        return cmsAppinfoMapper.selectAppTypeList();
    }

    @Override
    public PageDTO<AppDTO> listApp(AppQuery condition) {
        QueryWrapper<CmsAppinfo> queryWrapper = new QueryWrapper<>();

        if(condition != null) {
            if(condition.getXappType()!=null&&condition.getXappType().trim()!=""){
                queryWrapper.eq("xappType",condition.getXappType());
            }
            if(condition.getXappName()!=null&&condition.getXappName().trim()!=""){
                queryWrapper.like("xappName",condition.getXappName());
            }else if(condition.getXappAlias()!=null&&condition.getXappAlias().trim()!=""){
                queryWrapper.like("xappAlias",condition.getXappAlias());
            }else if(condition.getXdescription()!=null&&condition.getXdescription().trim()!=""){
                queryWrapper.like("xdescription",condition.getXdescription());
            }
        }
        queryWrapper.orderByAsc("xappInfoSeq");

        int index = 1;
        int size = 10;
        if(condition!=null && condition.getPageIndex()>0){
            index =(int) condition.getPageIndex();
        }
        if(condition!=null && condition.getPageSize()>0){
            size = (int)condition.getPageSize();
        }

        List<CmsAppinfo> cmsAppinfos = cmsAppinfoMapper.selectList(queryWrapper);
        List<AppDTO> appDTOS = new ArrayList<>();
        // 查询栏目对应的 表单类型
        for (CmsAppinfo app:cmsAppinfos){
            QueryWrapper<CmsForm> wrapper1 = new QueryWrapper<>();
            wrapper1.eq("xid",app.getXdefaultEditForm());
            CmsForm cmsForm1 = cmsFormMapper.selectOne(wrapper1);
            if(cmsForm1 != null) {
                app.setXeditName(cmsForm1.getXname());
            }

            QueryWrapper<CmsForm> wrapper2 = new QueryWrapper<>();
            wrapper2.eq("xid",app.getXdefaultReadForm());
            CmsForm cmsForm2 = cmsFormMapper.selectOne(wrapper2);
            if (cmsForm2 != null) {
                app.setXpublishName(cmsForm2.getXname());
            }
            //将DO转换为DTO
            AppDTO appDTO = msAppinfoMapper.toAppDTO(app);
            appDTOS.add(appDTO);
        }

        Page<AppDTO> appDTOPage = new Page<>(index,size);
        appDTOPage.setTotal(appDTOS.size());
        appDTOPage.setRecords(appDTOS);

//        Pageable pageable = PageRequest.of(index,size);
//        Page<AppDTO> appDTOPage = new PageImpl<>(appDTOS, pageable, appDTOS.size());

        return PageDTO.create(appDTOPage);

    }

    @Override
    public String addColumn(AppinfoDTO appinfoDTO) {
        CmsAppinfo cmsAppinfo = BeanUtil.toBean(appinfoDTO, CmsAppinfo.class);
        //先查询是否有名字重复的栏目
        QueryWrapper<CmsAppinfo> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("xappName", cmsAppinfo.getXappName());
        CmsAppinfo cmsAppinfo2 = cmsAppinfoMapper.selectOne(queryWrapper);
        if (cmsAppinfo2 != null) {
            return "Name already exist";
        }
        Integer result = cmsAppinfoMapper.insert(cmsAppinfo);
        if (result > 0) {
            return cmsAppinfo.getXid();
        }
        return null;
    }

    @Override
    public Integer deleteColumn(String xid) {
        Integer result = cmsAppinfoMapper.deleteById(xid);
        return result;
    }

}
