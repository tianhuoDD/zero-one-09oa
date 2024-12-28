package com.zeroone.star.cmshome.controller;

import com.zeroone.star.project.j5.cmshome.ModifyMessageApis;
import com.zeroone.star.cmshome.entity.CmsDocument;
import com.zeroone.star.cmshome.entity.CmsForm;
import com.zeroone.star.cmshome.service.ICmsDocumentService;
import com.zeroone.star.cmshome.service.ICmsFormService;
import com.zeroone.star.project.dto.j5.cmshome.ModifyEditMessageDTO;
import com.zeroone.star.project.vo.j5.cmshome.modifyMessage.ModifyEditVO;

import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;
import java.time.LocalDateTime;

/**
 * @Description: 消息管理-修改消息
 * @Param:
 * @return:
 * @Author: yuanzijie
 * @Date:
 */
@RestController
@RequestMapping("cmshome/modify-message")
@Api(tags = "修改消息")
@Validated
public class ModifyMessageController implements ModifyMessageApis {

    @Resource
    ICmsDocumentService cmsDocumentService;

    @Resource
    ICmsFormService cmsFormService;

    @ApiOperation(value = "查询修改消息编辑页面")
    @GetMapping("queryMessageEdit")
    @Override
    public JsonVO<ModifyEditVO> queryNewEdit(String documentXid) {
        CmsDocument document = cmsDocumentService.queryDocument(documentXid);
        ModifyEditVO modifyEditVO = new ModifyEditVO();
        modifyEditVO.setXcreateTime(document.getXcreateTime()); //获取创建时间
        modifyEditVO.setXcreatorName(document.getXcreatorIdentity()); //获取创建人姓名
        modifyEditVO.setXfieldTitle(document.getXtitle()); //获取标题
        CmsForm form = cmsFormService.queryForm(document.getXform()); //获取发布类编辑表单信息
        modifyEditVO.setXdata(form.getXdata()); //获取模板内容
        return JsonVO.success(modifyEditVO);
    }

    @ApiOperation(value = "保存修改消息")
    @GetMapping("updateMessageEdit")
    @Override
    public JsonVO<Boolean> updateEditMessage(ModifyEditMessageDTO modifyEditMessageDTO) {
        CmsDocument document = cmsDocumentService.queryDocument(modifyEditMessageDTO.getDocumentXid()); //查询document
        CmsForm form = cmsFormService.queryForm(document.getXform()); //查询form
        form.setXdata(modifyEditMessageDTO.getXdata());// 修改data
        form.setXupdateTime(LocalDateTime.now());// 获取当前日期和时间
        boolean updateForm = cmsFormService.updateForm(form); //更新form中的xdata和xupdateTime
        document.setXtitle(modifyEditMessageDTO.getXfieldTitle());
        boolean updateDocument = cmsDocumentService.updateDocument(document);
        if(updateForm && updateDocument){
            return JsonVO.success(true);
        }else{
            return JsonVO.fail(false);
        }
    }

}
