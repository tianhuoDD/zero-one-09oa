package com.zeroone.star.cmshome.service.impl;

import com.zeroone.star.cmshome.entity.*;
import com.zeroone.star.cmshome.mapper.CmsDocumentMapper;
import com.zeroone.star.cmshome.service.*;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.j5.cmshome.NewMessageDTO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.time.format.DateTimeFormatter;

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author yuanzijie
 * @since 2024-10-24
 */
@Service
public class CmsDocumentServiceImpl extends ServiceImpl<CmsDocumentMapper, CmsDocument> implements ICmsDocumentService {

    @Resource
    ICmsAppinfoService cmsAppinfoService;

    @Resource
    ICmsCategoryinfoService cmsCategoryinfoService;

    @Resource
    IOrgIdentityService orgIdentityService;

    @Resource
    IOrgPersonService orgPersonService;

    @Resource
    IOrgUnitService orgUnitService;

    @Autowired
    CmsDocumentMapper cmsDocumentMapper;

    public CmsDocument set(CmsDocument cmsDocument,CmsAppinfo cmsAppinfo,CmsCategoryinfo cmsCategoryinfo){
        cmsDocument.setXappId(cmsAppinfo.getXid()); //app的Id
        cmsDocument.setXappName(cmsAppinfo.getXappName()); //app的名称
        cmsDocument.setXappAlias(cmsAppinfo.getXappAlias()); //app的别名
        cmsDocument.setXcategoryId(cmsCategoryinfo.getXid()); //分类Id
        cmsDocument.setXcategoryAlias(cmsCategoryinfo.getXcategoryAlias()); //分类别名
        cmsDocument.setXcategoryName(cmsCategoryinfo.getXcategoryName()); //分类名称
        cmsDocument.setXreadFormId(cmsCategoryinfo.getXreadFormId()); //阅读表单的Id
        cmsDocument.setXreadFormName(cmsCategoryinfo.getXreadFormName()); //阅读表单的名称
        return cmsDocument;
    }

    @Override
    public boolean addNewMessage(NewMessageDTO newMessageDTO) {
        CmsDocument cmsDocument = new CmsDocument();

        String xappId = newMessageDTO.getXappId(); //获取app的id
        CmsAppinfo cmsAppinfo = cmsAppinfoService.queryAppInfo(xappId); //获取appinfo
        String xcategoryId = newMessageDTO.getXcategoryId(); //获取分类id
        CmsCategoryinfo cmsCategoryinfo = cmsCategoryinfoService.queryCategory(xcategoryId); //获取分类信息
        cmsDocument = set(cmsDocument,cmsAppinfo,cmsCategoryinfo);

        cmsDocument.setXtitle(newMessageDTO.getXtitle()); //输入的标题
        cmsDocument.setXcreateTime(newMessageDTO.getXcreateTime()); //创建时间

        OrgIdentity orgIdentity = orgIdentityService.queryOrgIdentity(newMessageDTO.getXidentityId()); //获取创建人身份信息。查询的是org_identity表
        cmsDocument.setXcreatorIdentity(orgIdentity.getXdistinguishedName()); //星球2@kaifabu_xingqiu2@I
        OrgPerson orgPerson = orgPersonService.queryById(orgIdentity.getXperson());
        cmsDocument.setXcreatorPerson(orgPerson.getXdistinguishedName());//星球2@xingqiu2@P
        OrgUnit orgUnit = orgUnitService.queryById(orgIdentity.getXunit());
        cmsDocument.setXcreatorUnitName(orgUnit.getXdistinguishedName());//开发部@kaifabu@U
        //01星球@010A-zeroone@U这个xcreatorTopUnitName比较复杂，之后再搞？？

        //需要设为0的值
        cmsDocument.setXcommendCount(0L);
        cmsDocument.setXcommentCount(0L);
        cmsDocument.setXhasIndexPic(false);
        cmsDocument.setXisTop(false);
        cmsDocument.setXisTop(false);
        cmsDocument.setXreviewed(true);
        cmsDocument.setXviewCount(0L);

        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyyMMddHHmmss");
        String formatterDateTime = formatter.format(newMessageDTO.getXcreateTime()); //创建时间的字符串
        //创建时间的字符串+document的xid = xsequence
        if(baseMapper.insert(cmsDocument) > 0){//上传自动生成雪花ID，但是xsequence没有生成，我要怎么办？
            return true;
        }else {
            return false;
        }
    }

    @Override
    public CmsDocument queryDocument(String xid) {
        return cmsDocumentMapper.selectDocumentByXid(xid);
    }

    @Override
    public boolean updateDocument(CmsDocument cmsDocument) {
        if(baseMapper.updateById(cmsDocument) > 0){
            return true;
        }
        return false;
    }
}
