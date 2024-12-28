package com.zeroone.star.bizcenter.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.bizcenter.entity.CmsAppInfo;
import com.zeroone.star.bizcenter.entity.CmsCategoryInfo;
import com.zeroone.star.bizcenter.mapper.CmsAppInfoMapper;
import com.zeroone.star.bizcenter.service.CmsAppInfoService;
import com.zeroone.star.bizcenter.service.CmsCategoryInfoService;
import com.zeroone.star.project.dto.j5.bizcenter.ProcessCategoryDTO;
import com.zeroone.star.project.vo.j5.bizcenter.publishProcessVO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;

@Service
public class CmsAppInfoServiceImpl extends ServiceImpl<CmsAppInfoMapper, CmsAppInfo> implements CmsAppInfoService {

    @Autowired
    private CmsAppInfoMapper cmsAppInfoMapper;

    @Autowired
    private CmsCategoryInfoService cmsCategoryInfoService;

    /**
     * 查询公共流程
     * @return 公共流程
     */
    public List<publishProcessVO> listPublishProcess() {
        //1.获取所有应用信息
        List<CmsAppInfo> cmsAppInfos = cmsAppInfoMapper.selectList(null);
        //2.封装成 publishProcessVO
        List<publishProcessVO> publishProcessVOS = new ArrayList<>();
        for (CmsAppInfo cmsAppInfo : cmsAppInfos) {
            //3.根据应用id查询应用分类信息
            List<CmsCategoryInfo> cmsCategoryInfos
                    = cmsCategoryInfoService.listProcessListByAppId(cmsAppInfo.getXid());

            //4.封装成ProcessCategoryDTO
            List<ProcessCategoryDTO> wrapOutCategoryListList = new ArrayList<>();
            for (CmsCategoryInfo cmsCategoryInfo : cmsCategoryInfos) {
                ProcessCategoryDTO processCategoryDTO = new ProcessCategoryDTO().builder()
                        .id(cmsCategoryInfo.getXid())
                        .categoryName(cmsCategoryInfo.getXcategoryName())
                        .appId(cmsCategoryInfo.getXappId())
                        .appName(cmsCategoryInfo.getXappName())
                        .categoryAlias(cmsCategoryInfo.getXcategoryAlias())
                        .documentType(cmsCategoryInfo.getXdocumentType())
                        .workflowType(cmsCategoryInfo.getXworkflowType())
                        .workflowAppId(cmsCategoryInfo.getXworkflowAppId())
                        .workflowAppName(cmsCategoryInfo.getXworkflowAppName())
                        .workflowName(cmsCategoryInfo.getXworkflowName())
                        .workflowFlag(cmsCategoryInfo.getXworkflowFlag())
                        .formId(cmsCategoryInfo.getXformId())
                        .formName(cmsCategoryInfo.getXformName())
                        .readFormId(cmsCategoryInfo.getXreadFormId())
                        .readFormName(cmsCategoryInfo.getXreadFormName())
                        .categorySeq(cmsCategoryInfo.getXcategorySeq())
                        .creatorPerson(cmsCategoryInfo.getXcreatorPerson())
                        .creatorIdentity(cmsCategoryInfo.getXcreatorIdentity())
                        .creatorUnitName(cmsCategoryInfo.getXcreatorUnitName())
                        .creatorTopUnitName(cmsCategoryInfo.getXcreatorTopUnitName())
                        .anonymousAble(cmsCategoryInfo.getXanonymousAble())
                        .allPeopleView(cmsCategoryInfo.getXallPeopleView())
                        .allPeoplePublish(cmsCategoryInfo.getXallPeoplePublish())
                        .sendNotify(cmsCategoryInfo.getXsendNotify())
                        .blankToAllNotify(cmsCategoryInfo.getXblankToAllNotify())
                        .createTime(cmsCategoryInfo.getXcreateTime())
                        .updateTime(cmsCategoryInfo.getXupdateTime())
                        .build();
                wrapOutCategoryListList.add(processCategoryDTO);
            }


            //5.封装成publishProcessVO
            publishProcessVO publishProcessVO =  new publishProcessVO().builder()
                    .date(cmsAppInfo.getXcreateTime())
                    .id(cmsAppInfo.getXid())
                    .appName(cmsAppInfo.getXappName())
                    .appAlias(cmsAppInfo.getXappAlias())
                    .appType(cmsAppInfo.getXappType())
                    .documentType(cmsAppInfo.getXdocumentType())
                    .appInfoSeq(cmsAppInfo.getXappInfoSeq())
                    .appIcon(cmsAppInfo.getXappIcon())
                    .iconColor(cmsAppInfo.getXiconColor())
                    .creatorPerson(cmsAppInfo.getXcreatorPerson())
                    .creatorIdentify(cmsAppInfo.getXcreatorIdentity())
                    .creatorUnitName(cmsAppInfo.getXcreatorUnitName())
                    .creatorTopUnitName(cmsAppInfo.getXcreatorTopUnitName())
                    .anonymousAble(cmsAppInfo.getXanonymousAble())
                    .allPeopleView(cmsAppInfo.getXallPeopleView())
                    .allPeoplePublish(cmsAppInfo.getXallPeoplePublish())
                    .sendNotify(cmsAppInfo.getXsendNotify())
                    .showAllDocument(cmsAppInfo.getXshowAllDocuments())
                    .createTime(cmsAppInfo.getXcreateTime())
                    .updateTime(cmsAppInfo.getXupdateTime())
                    .wrapOutCategoryListList(wrapOutCategoryListList)
                    .build();
            publishProcessVOS.add(publishProcessVO);
        }

        return publishProcessVOS;
    }
}

