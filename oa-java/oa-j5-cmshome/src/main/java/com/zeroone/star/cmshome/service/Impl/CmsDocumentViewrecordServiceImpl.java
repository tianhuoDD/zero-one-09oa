//package com.zeroone.star.cmshome.service.impl;
//
//
//import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
//
//import com.zeroone.star.cmshome.entity.CmsDocumentViewRecord;
//import com.zeroone.star.cmshome.mapper.CmsDocumentViewrecordMapper;
//import com.zeroone.star.cmshome.service.ICmsDocumentViewrecordService;
//import com.zeroone.star.project.vo.j5.cmshome.GetReadingRecordVO;
//import com.zeroone.star.project.vo.j5.cmshome.UpdateReadingRecordVO;
//import org.springframework.stereotype.Service;
//
//import javax.annotation.Resource;
//
//@Service
//public class CmsDocumentViewrecordServiceImpl extends ServiceImpl<CmsDocumentViewrecordMapper, CmsDocumentViewRecord> implements ICmsDocumentViewrecordService {
//    @Resource
//    private CmsDocumentViewrecordMapper cmsDocumentViewrecordMapper;
//
//    @Override
//    public GetReadingRecordVO getReadingRecord(String xid){
//        CmsDocumentViewRecord cmsDocumentViewrecord = cmsDocumentViewrecordMapper.selectById(xid);
//        GetReadingRecordVO getReadingRecordVO = new GetReadingRecordVO();
//
//        //观看者姓名
//        getReadingRecordVO.setXviewerName(cmsDocumentViewrecord.getXviewerName());
//        //观看者单位
//        getReadingRecordVO.setXviewerUnitName(cmsDocumentViewrecord.getXviewerUnitName());
//        //观看者首次阅读时间
//        getReadingRecordVO.setXviewTime(cmsDocumentViewrecord.getXcreateTime());
//        //观看者最后观看时间
//        getReadingRecordVO.setXlastViewTime(cmsDocumentViewrecord.getXlastViewTime());
//        //观看次数
//        getReadingRecordVO.setXviewCount(cmsDocumentViewrecord.getXviewCount());
//        return getReadingRecordVO;
//    }
//
//    @Override
//    public UpdateReadingRecordVO updateReadingRecord(String xid){
//        CmsDocumentViewRecord cmsDocumentViewrecord = cmsDocumentViewrecordMapper.selectById(xid);
//        UpdateReadingRecordVO updateReadingRecordVO = new UpdateReadingRecordVO();
//        updateReadingRecordVO.setXviewCount(cmsDocumentViewrecord.getXviewCount());
//        updateReadingRecordVO.setXlastViewTime(cmsDocumentViewrecord.getXlastViewTime());
//        return updateReadingRecordVO;
//    }
//
//    }
