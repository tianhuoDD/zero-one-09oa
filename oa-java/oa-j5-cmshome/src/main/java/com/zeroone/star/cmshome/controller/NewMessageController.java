package com.zeroone.star.cmshome.controller;


import com.zeroone.star.project.j5.cmshome.NewMessageApis;
import com.zeroone.star.cmshome.entity.CmsAppinfo;
import com.zeroone.star.cmshome.entity.CmsDocument;
import com.zeroone.star.cmshome.entity.CmsForm;
import com.zeroone.star.cmshome.entity.OrgIdentity;
import com.zeroone.star.cmshome.service.ICmsAppinfoService;
import com.zeroone.star.cmshome.service.ICmsDocumentService;
import com.zeroone.star.cmshome.service.ICmsFormService;
import com.zeroone.star.cmshome.service.IOrgIdentityService;
import com.zeroone.star.project.dto.j5.cmshome.NewMessageDTO;

import com.zeroone.star.project.query.j5.cmshome.newMessage.NewMessageQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j5.cmshome.newMessage.NewEditVO;
import com.zeroone.star.project.vo.j5.cmshome.newMessage.NewMessageVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;
import java.time.LocalDateTime;

import java.time.format.DateTimeFormatter;

/**
 * @Description: 消息管理-新建消息
 * @Param:
 * @return:
 * @Author: yuanzijie
 * @Date:
 */
@RestController
@RequestMapping("cmshome/new-message")
@Api(tags = "新建消息")
@Validated
public class NewMessageController implements NewMessageApis {

    @Resource
    ICmsAppinfoService cmsAppinfoService;

    @Resource
    IOrgIdentityService orgIdentityService;

    @Resource
    ICmsDocumentService cmsDocumentService;

    @Resource
    ICmsFormService cmsFormService;

    CmsAppinfo appInfo = new CmsAppinfo(); //把这三个设为全局变量，方便在调用完queryNewMessage方法后再在上传时使用

    OrgIdentity identity = new OrgIdentity();

    LocalDateTime createTime; //创建时间


    //点击确定后直接会在document里面新建一个模板，然后跳到编辑模板√
    //在F12里去找前置查询是什么 ! 答：前置是appid和identityid
    //大致思路：这里我使用的是引入app和创建人的Service，但是获取创建人信息我是默认该页面会传入一个创建人的id，并且我查询的是org_identity表，该表是准确的
    //阿伟学长说可以用凭证的方式获取当前登录用户的信息，但我不了解凭证的使用，暂且先用这种方式，如果后续修改请看这里！
    //数据库表没问题！
    @ApiOperation(value = "查询新建消息页面")
    @GetMapping("queryNewMessage")
    @Override
    public JsonVO<NewMessageVO> queryNewMessage(NewMessageQuery newQuery) {
        NewMessageVO newMessageVO = new NewMessageVO();
        appInfo = cmsAppinfoService.queryAppInfo(newQuery.getXappId());//获取app信息
        newMessageVO.setXcategoryName(appInfo.getXappName());//获取app名称
        newMessageVO.setXcategoryIcon(appInfo.getXappIcon());//获取app图标
        LocalDateTime now = LocalDateTime.now();//获取当前时间
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss");
        String startTime = now.format(formatter);
        createTime = LocalDateTime.parse(startTime, formatter);//全局保存的是LocalDateTime类型
        newMessageVO.setXcreateTime(startTime); //页面返回的是String类型
        identity = orgIdentityService.queryOrgIdentity(newQuery.getXidentityId());//获取创建人信息
        newMessageVO.setXcreatorName(identity.getXname());//获取创建人姓名
        newMessageVO.setXcreatorUnitName(identity.getXunitName());//获取单位的名称
        newMessageVO.setTitle(null);//设置标题内容为空
        return JsonVO.success(newMessageVO);
    }

    //我认为在输入完标题点击确定后就已经是新建了一个document了，然后跳到编辑模板并访问刚刚创建的这个document
    @ApiOperation(value = "上传新建消息")//新建一个document
    @GetMapping("addNewMessage")
    @Override
    public JsonVO<Boolean> addNewMessage(NewMessageDTO newMessageDTO) {
        if(cmsDocumentService.addNewMessage(newMessageDTO)){
            return JsonVO.success(true);
        }
        return JsonVO.fail(false);
    }

    //我认为新建时的编辑页面VO应该只返回已存在的数据，对于未被编辑的数据我在VO中是用form表单的xdata表示的，阿伟学长这么说的，
    // 观察后续是否需要修改，暂时还没有考虑根据不同的模板生成不同的内容，这里标记一下？
    @ApiOperation(value = "查询新建消息编辑页面")
    @GetMapping("queryNewMessageEdit")
    @Override
    public JsonVO<NewEditVO> queryNewEdit(String documentXid) {
        CmsDocument document = cmsDocumentService.queryDocument(documentXid);
        NewEditVO newEditVO = new NewEditVO();
        newEditVO.setXcreateTime(document.getXcreateTime()); //获取创建时间
        newEditVO.setXcreatorName(document.getXcreatorIdentity()); //获取创建人姓名
        newEditVO.setXfieldTitle(document.getXtitle());//获取标题

        //!!!!!云数据库中cms_document表中的关联字段xform有问题，为应测试要求，把form相关的操作都注释掉了
        /*CmsForm form = cmsFormService.queryForm(document.getXform()); //获取模板信息，这里document不确定要获取哪个字段名对应form表？？？？
        newEditVO.setXdata(form.getXdata());//获取模板内容*/
        return JsonVO.success(newEditVO);
    }

}
