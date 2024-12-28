package com.zeroone.star.basicinformation.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.fasterxml.jackson.databind.ObjectMapper;
import com.fasterxml.jackson.databind.node.ObjectNode;
import com.zeroone.star.basicinformation.entity.CmsAppinfo;
import com.zeroone.star.basicinformation.entity.CmsAppinfoConfig;
import com.zeroone.star.basicinformation.entity.CmsForm;
import com.zeroone.star.basicinformation.mapper.*;
import com.zeroone.star.basicinformation.service.ColumnAttributeService;
import com.zeroone.star.project.j3.ColumnAttribute.dto.ColumnAttributeDTO;
import com.zeroone.star.project.j3.ColumnAttribute.vo.ColumnAttributeVO;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.io.IOException;
import java.time.LocalDateTime;
import java.util.List;

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author 阿伟
 * @since 2024-10-20
 */
@Service
public class ColumnAttributeServiceImpl extends ServiceImpl<CmsFormMapper, CmsForm> implements ColumnAttributeService {

    @Resource
    CmsAppinfoMapper cmsAppinfoMapper;

    @Resource
    CmsAppinfoConfigMapper cmsAppinfoConfigMapper;

    @Resource
    CmsAppinfoManageablepersonlistMapper cmsAppinfoManageablepersonlistMapper;

    @Resource
    CmsAppinfoViewablepersonlistMapper cmsAppinfoViewablepersonlistMapper;

    @Resource
    CmsAppinfoPublishablepersonlistMapper cmsAppinfoPublishablepersonlistMapper;

    /**
     * 查询栏目属性
     * @param id
     * @return
     */
    @Override
    public ColumnAttributeVO queryColumnAttribute(String id) {

//        CmsAppinfo cmsappinfo = cmsAppinfoMapper.selectById(id);
         QueryWrapper<CmsAppinfo> Wrapper = new QueryWrapper<>();
         Wrapper.eq("xid",id);
         CmsAppinfo cmsappinfo = cmsAppinfoMapper.selectOne(Wrapper);
        List<String> xpublishablePersonList = cmsAppinfoPublishablepersonlistMapper.selectById(id);
        List<String> xviewablePersonList = cmsAppinfoViewablepersonlistMapper.selectById(id);
        List<String> xmanageablePersonList = cmsAppinfoManageablepersonlistMapper.selectById(id);

        ColumnAttributeVO  columnAttributeVO1 =ColumnAttributeVO.builder()
                .xid(id)
                .xappName(cmsappinfo.getXappName())
                .xappAlias(cmsappinfo.getXappAlias())
                .xappType(cmsappinfo.getXappType())
                .xdocumentType(cmsappinfo.getXdocumentType())
                .xdescription(cmsappinfo.getXdescription())
                .xsequence(cmsappinfo.getXsequence())
                .xshowAllDocuments(cmsappinfo.getXshowAllDocuments())
                .xdefaultEditForm(cmsappinfo.getXdefaultEditForm())
                .xdefaultReadForm(cmsappinfo.getXdefaultReadForm())
                .xappIcon(cmsappinfo.getXappIcon())
                .xviewablePersonList(xviewablePersonList)
                .xpublishablePersonList(xpublishablePersonList)
                .xmanageablePersonList(xmanageablePersonList)
                .xanonymousAble(cmsappinfo.getXanonymousAble())
                .xappInfoSeq(cmsappinfo.getXappInfoSeq())
                .xappMemo(cmsappinfo.getXappMemo())
                .xcreateTime(cmsappinfo.getXcreateTime())
                .xallPeopleView(cmsappinfo.getXallPeopleView())
                .xallPeoplePublish(cmsappinfo.getXallPeoplePublish())
                .xcreatorIdentity(cmsappinfo.getXcreatorIdentity())
                .xcreatorPerson(cmsappinfo.getXcreatorPerson())
                .xiconColor(cmsappinfo.getXiconColor())
                .xdistributeFactor(cmsappinfo.getXdistributeFactor())
                .xupdateTime(cmsappinfo.getXupdateTime())
                .xcreatorTopUnitName(cmsappinfo.getXcreatorTopUnitName())
                .xcreatorUnitName(cmsappinfo.getXcreatorUnitName())
                .build();
        CmsAppinfoConfig cmsAppinfoConfig=cmsAppinfoConfigMapper.selectByXid(id);
        String jsonString=cmsAppinfoConfig.getXconfig();
        if(!("{}".equals(jsonString))){
            ObjectMapper mapper = new ObjectMapper();
            try {
                // 将字符串解析为ObjectNode
                ObjectNode jsonNode = (ObjectNode) mapper.readTree(jsonString);
                // 获取布尔值
                boolean ignoreTitle = jsonNode.get("ignoreTitle").asBoolean();
                columnAttributeVO1.setIgnoreTitle(ignoreTitle);
                boolean latest = jsonNode.get("latest").asBoolean();
                columnAttributeVO1.setLatest(latest);
                boolean saveDraftOnClose = jsonNode.get("saveDraftOnClose").asBoolean();
                columnAttributeVO1.setSaveDraftOnClose(saveDraftOnClose);
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return columnAttributeVO1;
    }

    /**
     * 修改栏目属性
     *
     * @param columnAttributeDTO
     * @return
     */
    @Override
    public boolean modifyCmsForm(ColumnAttributeDTO columnAttributeDTO) {

        CmsAppinfo cmsAppinfo =CmsAppinfo.builder()
                .xid(columnAttributeDTO.getXid())
                .xappName(columnAttributeDTO.getXappName())
                .xappAlias(columnAttributeDTO.getXappAlias())
                .xappType(columnAttributeDTO.getXappType())
                .xdocumentType(columnAttributeDTO.getXdocumentType())
                .xdescription(columnAttributeDTO.getXdescription())
                .xsequence(columnAttributeDTO.getXsequence())
                .xshowAllDocuments(columnAttributeDTO.getXshowAllDocuments())
                .xdefaultEditForm(columnAttributeDTO.getXdefaultEditForm())
                .xdefaultReadForm(columnAttributeDTO.getXdefaultReadForm())
                .xupdateTime(LocalDateTime.now())
                .build();
        QueryWrapper<CmsAppinfo> wrapper = new QueryWrapper<>();
        wrapper.eq("xid",columnAttributeDTO.getXid());
        cmsAppinfoMapper.update(cmsAppinfo,wrapper);
        String ignoreTitle;
        if(columnAttributeDTO.getIgnoreTitle()){
            ignoreTitle="true";
        }else{
            ignoreTitle="false";
        }
        String latest;
        if(columnAttributeDTO.getLatest()){
            latest="true";
        }else{
            latest="false";
        }
        String saveDraftOnClose;
        if(columnAttributeDTO.getSaveDraftOnClose()){
            saveDraftOnClose="true";
        }else {
            saveDraftOnClose="false";
        }
        String jsonString = "{\"ignoreTitle\":"+ignoreTitle+",\"latest\":"+latest+",\"saveDraftOnClose\":"+saveDraftOnClose+"}";
        CmsAppinfoConfig cmsAppinfoConfig=new CmsAppinfoConfig();
        cmsAppinfoConfig.setXconfig(jsonString);
        QueryWrapper<CmsAppinfoConfig> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("xid",columnAttributeDTO.getXid());
        cmsAppinfoConfigMapper.update(cmsAppinfoConfig,queryWrapper);
        return true;
    }

}
