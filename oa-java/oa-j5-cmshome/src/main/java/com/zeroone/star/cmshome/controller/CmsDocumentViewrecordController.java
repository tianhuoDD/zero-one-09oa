//package com.zeroone.star.cmshome.controller;
//
//
//
//import com.zeroone.star.cmshome.service.ICmsDocumentViewrecordService;
//import com.zeroone.star.project.j5.cmshome.ReadingRecordApis;
//import com.zeroone.star.project.vo.JsonVO;
//import com.zeroone.star.project.vo.j5.cmshome.GetReadingRecordVO;
//import com.zeroone.star.project.vo.j5.cmshome.UpdateReadingRecordVO;
//import io.swagger.annotations.Api;
//import io.swagger.annotations.ApiOperation;
//import org.springframework.web.bind.annotation.GetMapping;
//import org.springframework.web.bind.annotation.RequestMapping;
//import org.springframework.web.bind.annotation.RestController;
//
//import javax.annotation.Resource;
//
//@RestController
//@RequestMapping("cmshome")
//@Api(tags = "消息读取")
//public class CmsDocumentViewrecordController implements ReadingRecordApis {
//
//    @Resource(name = "cmsDocumentViewrecordServiceImpl")
//    private ICmsDocumentViewrecordService cmsDocumentViewrecordService;
////    @Resource
////    private final CmsDocumentViewrecordServiceImpl cmsDocumentViewrecordService;
////
////    public CmsDocumentViewrecordController(CmsDocumentViewrecordServiceImpl cmsDocumentViewrecordService) {
////        this.cmsDocumentViewrecordService = cmsDocumentViewrecordService;
////    }
//
//    @GetMapping("readingrecord")
//    @ApiOperation(value = "获取阅读记录")
//    @Override
//    public JsonVO<GetReadingRecordVO> getReadingRecord(String xid) {
//        return JsonVO.success( cmsDocumentViewrecordService.getReadingRecord(xid));
//    }
//
//    @GetMapping("updatereadingrecord")
//    @ApiOperation(value = "更新消息记录")
//    @Override
//    public JsonVO<UpdateReadingRecordVO> updateReadingRecord(String xid) {
//        return JsonVO.success( cmsDocumentViewrecordService.updateReadingRecord(xid));
//    }
//}
//
//
//
