package com.zeroone.star.bizcenter.service.impl;


import cn.hutool.core.bean.BeanUtil;
import cn.hutool.json.JSONUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.zeroone.star.bizcenter.entity.*;
import com.zeroone.star.bizcenter.exception.BizcenterException;
import com.zeroone.star.bizcenter.service.*;

import com.zeroone.star.project.vo.j5.bizcenter.*;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

/**
 * 获取流程监控服务实现类
 */

@Service
public class GetProcessMonitoringServiceImpl implements GetProcessMonitoringService {


    // 依赖注入流程开始节点服务
    @Resource
    private IPpEBeginService ppEBeginService;
    @Resource
    // 依赖注入流程结束节点服务
    private IPpEEndService ppEEndService;

    @Override
    public ComplexVO getComplex(String flag) {
        //实例化一个ComplexVO对象
        ComplexVO complexVO = new ComplexVO();
        //获取流程信息
        getProcessInfo(flag, complexVO);
        //获取开始结点
        getBegin(flag, complexVO);
        //获取结束结点
        getEndList(flag, complexVO);
        //获取人工节点
        getManualInfo(flag, complexVO);
        //获取路由结点
        getRouteInfo(flag, complexVO);
        //获取代理结点信息
        getAgentInfo(flag, complexVO);
        //获取撤销结点信息
        getCancelInfo(flag, complexVO);
        //获取选择结点信息
        getChoiceInfo(flag, complexVO);
        //获取延时结点信息
        getDelayInfo(flag, complexVO);
        //获取嵌套子流程信息
        getEmbedInfo(flag, complexVO);
        //获取调用结点信息
        getInvokeInfo(flag,complexVO);
        //流程合并信息
        getMergeInfo(flag, complexVO);
        //获取并行分支信息
        getParallelInfo(flag,complexVO);
        //获取发布结点信息
        getPublishInfo(flag, complexVO);
        //获取服务节点信息
        getServiceInfo(flag,complexVO);
        //获取拆分结点信息
        getSplitInfo(flag,complexVO);
        return complexVO;
    }




    @Resource
    private IPpESplitService ppESplitService;

    @Resource
    private IPpESplitReaddatapathlistService ppESplitReaddatapathlistService;

    @Resource
    private IPpESplitReadgrouplistService ppESplitReadgrouplistService;

    @Resource
    private IPpESplitReadidentitylistService ppESplitReadidentitylistService;

    @Resource
    private IPpESplitReadunitlistService ppESplitReadunitlistService;

    @Resource
    private IPpESplitReviewdatapathlistService ppESplitReviewdatapathlistService;
    @Resource
    private IPpESplitReviewgrouplistService ppESplitReviewgrouplistService;
    @Resource
    private IPpESplitReviewidentitylistService ppESplitReviewidentitylistService;
    @Resource
    private IPpESplitReviewunitlistService ppESplitReviewunitlistService;


    private void getSplitInfo(String flag, ComplexVO complexVO) {
        List<PpESplit> ppESplitList = ppESplitService.lambdaQuery().eq(PpESplit::getXprocess, flag).list();
        if (ppESplitList.isEmpty()){
            complexVO.setSplitList(Collections.emptyList());
            return;
        }
        List<SplitVO> SplitVOList = new ArrayList<>();

        for (PpESplit ppESplit : ppESplitList) {
            SplitVO SplitVO = BeanUtil.copyProperties(ppESplit, SplitVO.class);
            Map<String,Object> properties = JSONUtil.toBean(ppESplit.getXproperties(), Map.class);
            if (properties != null){
                SplitVO.setProperties(properties);
            } else {
                SplitVO.setProperties(Collections.emptyMap());
            }
            SplitVOList.add(SplitVO);
        }

        List<String> ids = SplitVOList.stream().map(SplitVO::getId).collect(Collectors.toList());
        List<PpESplitReaddatapathlist> ppESplitReaddatapathlistList = ppESplitReaddatapathlistService.listByIds(ids);
        if (ppESplitReaddatapathlistList != null){
            for (SplitVO SplitVO : SplitVOList) {
                String SplitVOId = SplitVO.getId();
                List<String> list = new ArrayList<>();
                for (PpESplitReaddatapathlist ppESplitReaddatapathlist : ppESplitReaddatapathlistList) {
                    if (SplitVOId.equals(ppESplitReaddatapathlist.getSplitXid())){
                        list.add(ppESplitReaddatapathlist.getXorderColumn(),ppESplitReaddatapathlist.getXreadDataPathList());
                    }
                }
                SplitVO.setReadDataPathList(list);
            }
        }else {
            SplitVOList.forEach(d -> d.setReadDataPathList(Collections.emptyList()));
        }

        List<PpESplitReadgrouplist> ppESplitReadgrouplistList = ppESplitReadgrouplistService.listByIds(ids);
        if (ppESplitReadgrouplistList != null){
            for (SplitVO SplitVO : SplitVOList) {
                String SplitVOId = SplitVO.getId();
                List<String> list = new ArrayList<>();
                for (PpESplitReadgrouplist ppESplitReadgrouplist : ppESplitReadgrouplistList) {
                    if (SplitVOId.equals(ppESplitReadgrouplist.getSplitXid())){
                        list.add(ppESplitReadgrouplist.getXorderColumn(),ppESplitReadgrouplist.getXreadGroupList());
                    }
                }
                SplitVO.setReadGroupList(list);
            }
        }else {
            SplitVOList.forEach(d -> d.setReadGroupList(Collections.emptyList()));
        }


        List<PpESplitReadidentitylist> ppESplitReadidentitylistList = ppESplitReadidentitylistService.listByIds(ids);
        if (ppESplitReadidentitylistList != null){
            for (SplitVO SplitVO : SplitVOList) {
                String SplitVOId = SplitVO.getId();
                List<String> list = new ArrayList<>();
                for (PpESplitReadidentitylist ppESplitReadidentitylist : ppESplitReadidentitylistList) {
                    if (SplitVOId.equals(ppESplitReadidentitylist.getSplitXid())){
                        list.add(ppESplitReadidentitylist.getXorderColumn(),ppESplitReadidentitylist.getXreadIdentityList());
                    }
                }
                SplitVO.setReadIdentityList(list);
            }
        }else {
            SplitVOList.forEach(d -> d.setReadIdentityList(Collections.emptyList()));
        }

        List<PpESplitReadunitlist> ppESplitReadunitlistList = ppESplitReadunitlistService.listByIds(ids);
        if (ppESplitReadunitlistList != null){
            for (SplitVO SplitVO : SplitVOList) {
                String SplitVOId = SplitVO.getId();
                List<String> list = new ArrayList<>();
                for (PpESplitReadunitlist ppESplitReadunitlist : ppESplitReadunitlistList) {
                    if (SplitVOId.equals(ppESplitReadunitlist.getSplitXid())){
                        list.add(ppESplitReadunitlist.getXorderColumn(),ppESplitReadunitlist.getXreadUnitList());
                    }
                }
                SplitVO.setReadUnitList(list);
            }
        }else {
            SplitVOList.forEach(d -> d.setReadUnitList(Collections.emptyList()));
        }

        List<PpESplitReviewdatapathlist> ppESplitReviewdatapathlistList = ppESplitReviewdatapathlistService.listByIds(ids);
        if (ppESplitReviewdatapathlistList != null){
            for (SplitVO SplitVO : SplitVOList) {
                String SplitVOId = SplitVO.getId();
                List<String> list = new ArrayList<>();
                for (PpESplitReviewdatapathlist ppESplitReviewdatapathlist : ppESplitReviewdatapathlistList) {
                    if (SplitVOId.equals(ppESplitReviewdatapathlist.getSplitXid())){
                        list.add(ppESplitReviewdatapathlist.getXorderColumn(),ppESplitReviewdatapathlist.getXreviewDataPathList());
                    }
                }
                SplitVO.setReviewDataPathList(list);
            }
        }else {
            SplitVOList.forEach(d -> d.setReviewDataPathList(Collections.emptyList()));
        }

        List<PpESplitReviewgrouplist> ppESplitReviewgrouplistList = ppESplitReviewgrouplistService.listByIds(ids);
        if (ppESplitReviewgrouplistList != null){
            for (SplitVO SplitVO : SplitVOList) {
                String SplitVOId = SplitVO.getId();
                List<String> list = new ArrayList<>();
                for (PpESplitReviewgrouplist ppESplitReviewgrouplist : ppESplitReviewgrouplistList) {
                    if (SplitVOId.equals(ppESplitReviewgrouplist.getSplitXid())){
                        list.add(ppESplitReviewgrouplist.getXorderColumn(),ppESplitReviewgrouplist.getXreviewGroupList());
                    }
                }
                SplitVO.setReviewGroupList(list);
            }
        }else {
            SplitVOList.forEach(d -> d.setReviewGroupList(Collections.emptyList()));
        }


        List<PpESplitReviewidentitylist> ppESplitReviewidentitylistList = ppESplitReviewidentitylistService.listByIds(ids);
        if (ppESplitReviewidentitylistList != null){
            for (SplitVO SplitVO : SplitVOList) {
                String SplitVOId = SplitVO.getId();
                List<String> list = new ArrayList<>();
                for (PpESplitReviewidentitylist ppESplitReviewidentitylist : ppESplitReviewidentitylistList) {
                    if (SplitVOId.equals(ppESplitReviewidentitylist.getSplitXid())){
                        list.add(ppESplitReviewidentitylist.getXorderColumn(),ppESplitReviewidentitylist.getXreviewIdentityList());
                    }
                }
                SplitVO.setReviewIdentityList(list);
            }
        }else {
            SplitVOList.forEach(d -> d.setReviewIdentityList(Collections.emptyList()));
        }

        List<PpESplitReviewunitlist> ppESplitReviewunitlistList = ppESplitReviewunitlistService.listByIds(ids);
        if (ppESplitReviewunitlistList != null){
            for (SplitVO SplitVO : SplitVOList) {
                String SplitVOId = SplitVO.getId();
                List<String> list = new ArrayList<>();
                for (PpESplitReviewunitlist ppESplitReviewunitlist : ppESplitReviewunitlistList) {
                    if (SplitVOId.equals(ppESplitReviewunitlist.getSplitXid())){
                        list.add(ppESplitReviewunitlist.getXorderColumn(),ppESplitReviewunitlist.getXreviewUnitList());
                    }
                }
                SplitVO.setReviewUnitList(list);
            }
        }else {
            SplitVOList.forEach(d -> d.setReviewUnitList(Collections.emptyList()));
        }

        complexVO.setSplitList(SplitVOList);

    }






    @Resource
    private IPpEServiceService ppEServiceService;

    @Resource
    private IPpEServiceReaddatapathlistService ppEServiceReaddatapathlistService;

    @Resource
    private IPpEServiceReadgrouplistService ppEServiceReadgrouplistService;

    @Resource
    private IPpEServiceReadidentitylistService ppEServiceReadidentitylistService;

    @Resource
    private IPpEServiceReadunitlistService ppEServiceReadunitlistService;

    @Resource
    private IPpEServiceReviewdatapathlistService ppEServiceReviewdatapathlistService;
    @Resource
    private IPpEServiceReviewgrouplistService ppEServiceReviewgrouplistService;
    @Resource
    private IPpEServiceReviewidentitylistService ppEServiceReviewidentitylistService;
    @Resource
    private IPpEServiceReviewunitlistService ppEServiceReviewunitlistService;

    @Resource
    private IPpEServiceTrustaddresslistService ppEServiceTrustaddresslistService;


    private void getServiceInfo(String flag, ComplexVO complexVO) {
        List<PpEService> ppEServiceList = ppEServiceService.lambdaQuery().eq(PpEService::getXprocess, flag).list();
        if (ppEServiceList.isEmpty()){
            complexVO.setServiceList(Collections.emptyList());
            return;
        }
        List<ServiceVO> ServiceVOList = new ArrayList<>();

        for (PpEService ppEService : ppEServiceList) {
            ServiceVO ServiceVO = BeanUtil.copyProperties(ppEService, ServiceVO.class);
            Map<String,Object> properties = JSONUtil.toBean(ppEService.getXproperties(), Map.class);
            if (properties != null){
                ServiceVO.setProperties(properties);
            } else {
                ServiceVO.setProperties(Collections.emptyMap());
            }
            ServiceVOList.add(ServiceVO);
        }

        List<String> ids = ServiceVOList.stream().map(ServiceVO::getId).collect(Collectors.toList());
        List<PpEServiceReaddatapathlist> ppEServiceReaddatapathlistList = ppEServiceReaddatapathlistService.listByIds(ids);
        if (ppEServiceReaddatapathlistList != null){
            for (ServiceVO ServiceVO : ServiceVOList) {
                String ServiceVOId = ServiceVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEServiceReaddatapathlist ppEServiceReaddatapathlist : ppEServiceReaddatapathlistList) {
                    if (ServiceVOId.equals(ppEServiceReaddatapathlist.getServiceXid())){
                        list.add(ppEServiceReaddatapathlist.getXorderColumn(),ppEServiceReaddatapathlist.getXreadDataPathList());
                    }
                }
                ServiceVO.setReadDataPathList(list);
            }
        }else {
            ServiceVOList.forEach(d -> d.setReadDataPathList(Collections.emptyList()));
        }

        List<PpEServiceReadgrouplist> ppEServiceReadgrouplistList = ppEServiceReadgrouplistService.listByIds(ids);
        if (ppEServiceReadgrouplistList != null){
            for (ServiceVO ServiceVO : ServiceVOList) {
                String ServiceVOId = ServiceVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEServiceReadgrouplist ppEServiceReadgrouplist : ppEServiceReadgrouplistList) {
                    if (ServiceVOId.equals(ppEServiceReadgrouplist.getServiceXid())){
                        list.add(ppEServiceReadgrouplist.getXorderColumn(),ppEServiceReadgrouplist.getXreadGroupList());
                    }
                }
                ServiceVO.setReadGroupList(list);
            }
        }else {
            ServiceVOList.forEach(d -> d.setReadGroupList(Collections.emptyList()));
        }


        List<PpEServiceReadidentitylist> ppEServiceReadidentitylistList = ppEServiceReadidentitylistService.listByIds(ids);
        if (ppEServiceReadidentitylistList != null){
            for (ServiceVO ServiceVO : ServiceVOList) {
                String ServiceVOId = ServiceVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEServiceReadidentitylist ppEServiceReadidentitylist : ppEServiceReadidentitylistList) {
                    if (ServiceVOId.equals(ppEServiceReadidentitylist.getServiceXid())){
                        list.add(ppEServiceReadidentitylist.getXorderColumn(),ppEServiceReadidentitylist.getXreadIdentityList());
                    }
                }
                ServiceVO.setReadIdentityList(list);
            }
        }else {
            ServiceVOList.forEach(d -> d.setReadIdentityList(Collections.emptyList()));
        }

        List<PpEServiceReadunitlist> ppEServiceReadunitlistList = ppEServiceReadunitlistService.listByIds(ids);
        if (ppEServiceReadunitlistList != null){
            for (ServiceVO ServiceVO : ServiceVOList) {
                String ServiceVOId = ServiceVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEServiceReadunitlist ppEServiceReadunitlist : ppEServiceReadunitlistList) {
                    if (ServiceVOId.equals(ppEServiceReadunitlist.getServiceXid())){
                        list.add(ppEServiceReadunitlist.getXorderColumn(),ppEServiceReadunitlist.getXreadUnitList());
                    }
                }
                ServiceVO.setReadUnitList(list);
            }
        }else {
            ServiceVOList.forEach(d -> d.setReadUnitList(Collections.emptyList()));
        }

        List<PpEServiceReviewdatapathlist> ppEServiceReviewdatapathlistList = ppEServiceReviewdatapathlistService.listByIds(ids);
        if (ppEServiceReviewdatapathlistList != null){
            for (ServiceVO ServiceVO : ServiceVOList) {
                String ServiceVOId = ServiceVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEServiceReviewdatapathlist ppEServiceReviewdatapathlist : ppEServiceReviewdatapathlistList) {
                    if (ServiceVOId.equals(ppEServiceReviewdatapathlist.getServiceXid())){
                        list.add(ppEServiceReviewdatapathlist.getXorderColumn(),ppEServiceReviewdatapathlist.getXreviewDataPathList());
                    }
                }
                ServiceVO.setReviewDataPathList(list);
            }
        }else {
            ServiceVOList.forEach(d -> d.setReviewDataPathList(Collections.emptyList()));
        }

        List<PpEServiceReviewgrouplist> ppEServiceReviewgrouplistList = ppEServiceReviewgrouplistService.listByIds(ids);
        if (ppEServiceReviewgrouplistList != null){
            for (ServiceVO ServiceVO : ServiceVOList) {
                String ServiceVOId = ServiceVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEServiceReviewgrouplist ppEServiceReviewgrouplist : ppEServiceReviewgrouplistList) {
                    if (ServiceVOId.equals(ppEServiceReviewgrouplist.getServiceXid())){
                        list.add(ppEServiceReviewgrouplist.getXorderColumn(),ppEServiceReviewgrouplist.getXreviewGroupList());
                    }
                }
                ServiceVO.setReviewGroupList(list);
            }
        }else {
            ServiceVOList.forEach(d -> d.setReviewGroupList(Collections.emptyList()));
        }


        List<PpEServiceReviewidentitylist> ppEServiceReviewidentitylistList = ppEServiceReviewidentitylistService.listByIds(ids);
        if (ppEServiceReviewidentitylistList != null){
            for (ServiceVO ServiceVO : ServiceVOList) {
                String ServiceVOId = ServiceVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEServiceReviewidentitylist ppEServiceReviewidentitylist : ppEServiceReviewidentitylistList) {
                    if (ServiceVOId.equals(ppEServiceReviewidentitylist.getServiceXid())){
                        list.add(ppEServiceReviewidentitylist.getXorderColumn(),ppEServiceReviewidentitylist.getXreviewIdentityList());
                    }
                }
                ServiceVO.setReviewIdentityList(list);
            }
        }else {
            ServiceVOList.forEach(d -> d.setReviewIdentityList(Collections.emptyList()));
        }

        List<PpEServiceReviewunitlist> ppEServiceReviewunitlistList = ppEServiceReviewunitlistService.listByIds(ids);
        if (ppEServiceReviewunitlistList != null){
            for (ServiceVO ServiceVO : ServiceVOList) {
                String ServiceVOId = ServiceVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEServiceReviewunitlist ppEServiceReviewunitlist : ppEServiceReviewunitlistList) {
                    if (ServiceVOId.equals(ppEServiceReviewunitlist.getServiceXid())){
                        list.add(ppEServiceReviewunitlist.getXorderColumn(),ppEServiceReviewunitlist.getXreviewUnitList());
                    }
                }
                ServiceVO.setReviewUnitList(list);
            }
        }else {
            ServiceVOList.forEach(d -> d.setReviewUnitList(Collections.emptyList()));
        }

        List<PpEServiceTrustaddresslist> ppEServiceTrustaddresslistList = ppEServiceTrustaddresslistService.listByIds(ids);
        if (ppEServiceTrustaddresslistList != null){
            for (ServiceVO ServiceVO : ServiceVOList) {
                String ServiceVOId = ServiceVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEServiceTrustaddresslist ppEServiceTrustaddresslist : ppEServiceTrustaddresslistList) {
                    if (ServiceVOId.equals(ppEServiceTrustaddresslist.getServiceXid())){
                        list.add(ppEServiceTrustaddresslist.getXorderColumn(),ppEServiceTrustaddresslist.getXtrustAddressList());
                    }
                }
                ServiceVO.setTrustaddresslist(list);
            }
        }else {
            ServiceVOList.forEach(d -> d.setTrustaddresslist(Collections.emptyList()));
        }

        complexVO.setServiceList(ServiceVOList);
    }











    @Resource
    private IPpEPublishService ppEPublishService;

    @Resource
    private IPpEPublishReaddatapathlistService ppEPublishReaddatapathlistService;

    @Resource
    private IPpEPublishReadgrouplistService ppEPublishReadgrouplistService;

    @Resource
    private IPpEPublishReadidentitylistService ppEPublishReadidentitylistService;

    @Resource
    private IPpEPublishReadunitlistService ppEPublishReadunitlistService;

    @Resource
    private IPpEPublishReviewdatapathlistService ppEPublishReviewdatapathlistService;
    @Resource
    private IPpEPublishReviewgrouplistService ppEPublishReviewgrouplistService;
    @Resource
    private IPpEPublishReviewidentitylistService ppEPublishReviewidentitylistService;
    @Resource
    private IPpEPublishReviewunitlistService ppEPublishReviewunitlistService;


    private void getPublishInfo(String flag, ComplexVO complexVO) {
        List<PpEPublish> ppEPublishList = ppEPublishService.lambdaQuery().eq(PpEPublish::getXprocess, flag).list();
        if (ppEPublishList.isEmpty()){
            complexVO.setPublishList(Collections.emptyList());
            return;
        }
        List<PublishVO> PublishVOList = new ArrayList<>();

        for (PpEPublish ppEPublish : ppEPublishList) {
            PublishVO PublishVO = BeanUtil.copyProperties(ppEPublish, PublishVO.class);
            Map<String,Object> properties = JSONUtil.toBean(ppEPublish.getXproperties(), Map.class);
            if (properties != null){
                PublishVO.setProperties(properties);
            } else {
                PublishVO.setProperties(Collections.emptyMap());
            }
            PublishVOList.add(PublishVO);
        }

        List<String> ids = PublishVOList.stream().map(PublishVO::getId).collect(Collectors.toList());
        List<PpEPublishReaddatapathlist> ppEPublishReaddatapathlistList = ppEPublishReaddatapathlistService.listByIds(ids);
        if (ppEPublishReaddatapathlistList != null){
            for (PublishVO PublishVO : PublishVOList) {
                String PublishVOId = PublishVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEPublishReaddatapathlist ppEPublishReaddatapathlist : ppEPublishReaddatapathlistList) {
                    if (PublishVOId.equals(ppEPublishReaddatapathlist.getPublishXid())){
                        list.add(ppEPublishReaddatapathlist.getXorderColumn(),ppEPublishReaddatapathlist.getXreadDataPathList());
                    }
                }
                PublishVO.setReadDataPathList(list);
            }
        }else {
            PublishVOList.forEach(d -> d.setReadDataPathList(Collections.emptyList()));
        }

        List<PpEPublishReadgrouplist> ppEPublishReadgrouplistList = ppEPublishReadgrouplistService.listByIds(ids);
        if (ppEPublishReadgrouplistList != null){
            for (PublishVO PublishVO : PublishVOList) {
                String PublishVOId = PublishVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEPublishReadgrouplist ppEPublishReadgrouplist : ppEPublishReadgrouplistList) {
                    if (PublishVOId.equals(ppEPublishReadgrouplist.getPublishXid())){
                        list.add(ppEPublishReadgrouplist.getXorderColumn(),ppEPublishReadgrouplist.getXreadGroupList());
                    }
                }
                PublishVO.setReadGroupList(list);
            }
        }else {
            PublishVOList.forEach(d -> d.setReadGroupList(Collections.emptyList()));
        }


        List<PpEPublishReadidentitylist> ppEPublishReadidentitylistList = ppEPublishReadidentitylistService.listByIds(ids);
        if (ppEPublishReadidentitylistList != null){
            for (PublishVO PublishVO : PublishVOList) {
                String PublishVOId = PublishVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEPublishReadidentitylist ppEPublishReadidentitylist : ppEPublishReadidentitylistList) {
                    if (PublishVOId.equals(ppEPublishReadidentitylist.getPublishXid())){
                        list.add(ppEPublishReadidentitylist.getXorderColumn(),ppEPublishReadidentitylist.getXreadIdentityList());
                    }
                }
                PublishVO.setReadIdentityList(list);
            }
        }else {
            PublishVOList.forEach(d -> d.setReadIdentityList(Collections.emptyList()));
        }

        List<PpEPublishReadunitlist> ppEPublishReadunitlistList = ppEPublishReadunitlistService.listByIds(ids);
        if (ppEPublishReadunitlistList != null){
            for (PublishVO PublishVO : PublishVOList) {
                String PublishVOId = PublishVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEPublishReadunitlist ppEPublishReadunitlist : ppEPublishReadunitlistList) {
                    if (PublishVOId.equals(ppEPublishReadunitlist.getPublishXid())){
                        list.add(ppEPublishReadunitlist.getXorderColumn(),ppEPublishReadunitlist.getXreadUnitList());
                    }
                }
                PublishVO.setReadUnitList(list);
            }
        }else {
            PublishVOList.forEach(d -> d.setReadUnitList(Collections.emptyList()));
        }

        List<PpEPublishReviewdatapathlist> ppEPublishReviewdatapathlistList = ppEPublishReviewdatapathlistService.listByIds(ids);
        if (ppEPublishReviewdatapathlistList != null){
            for (PublishVO PublishVO : PublishVOList) {
                String PublishVOId = PublishVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEPublishReviewdatapathlist ppEPublishReviewdatapathlist : ppEPublishReviewdatapathlistList) {
                    if (PublishVOId.equals(ppEPublishReviewdatapathlist.getPublishXid())){
                        list.add(ppEPublishReviewdatapathlist.getXorderColumn(),ppEPublishReviewdatapathlist.getXreviewDataPathList());
                    }
                }
                PublishVO.setReviewDataPathList(list);
            }
        }else {
            PublishVOList.forEach(d -> d.setReviewDataPathList(Collections.emptyList()));
        }

        List<PpEPublishReviewgrouplist> ppEPublishReviewgrouplistList = ppEPublishReviewgrouplistService.listByIds(ids);
        if (ppEPublishReviewgrouplistList != null){
            for (PublishVO PublishVO : PublishVOList) {
                String PublishVOId = PublishVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEPublishReviewgrouplist ppEPublishReviewgrouplist : ppEPublishReviewgrouplistList) {
                    if (PublishVOId.equals(ppEPublishReviewgrouplist.getPublishXid())){
                        list.add(ppEPublishReviewgrouplist.getXorderColumn(),ppEPublishReviewgrouplist.getXreviewGroupList());
                    }
                }
                PublishVO.setReviewGroupList(list);
            }
        }else {
            PublishVOList.forEach(d -> d.setReviewGroupList(Collections.emptyList()));
        }


        List<PpEPublishReviewidentitylist> ppEPublishReviewidentitylistList = ppEPublishReviewidentitylistService.listByIds(ids);
        if (ppEPublishReviewidentitylistList != null){
            for (PublishVO PublishVO : PublishVOList) {
                String PublishVOId = PublishVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEPublishReviewidentitylist ppEPublishReviewidentitylist : ppEPublishReviewidentitylistList) {
                    if (PublishVOId.equals(ppEPublishReviewidentitylist.getPublishXid())){
                        list.add(ppEPublishReviewidentitylist.getXorderColumn(),ppEPublishReviewidentitylist.getXreviewIdentityList());
                    }
                }
                PublishVO.setReviewIdentityList(list);
            }
        }else {
            PublishVOList.forEach(d -> d.setReviewIdentityList(Collections.emptyList()));
        }

        List<PpEPublishReviewunitlist> ppEPublishReviewunitlistList = ppEPublishReviewunitlistService.listByIds(ids);
        if (ppEPublishReviewunitlistList != null){
            for (PublishVO PublishVO : PublishVOList) {
                String PublishVOId = PublishVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEPublishReviewunitlist ppEPublishReviewunitlist : ppEPublishReviewunitlistList) {
                    if (PublishVOId.equals(ppEPublishReviewunitlist.getPublishXid())){
                        list.add(ppEPublishReviewunitlist.getXorderColumn(),ppEPublishReviewunitlist.getXreviewUnitList());
                    }
                }
                PublishVO.setReviewUnitList(list);
            }
        }else {
            PublishVOList.forEach(d -> d.setReviewUnitList(Collections.emptyList()));
        }

        complexVO.setPublishList(PublishVOList);

    }







    @Resource
    private IPpEParallelService ppEParallelService;

    @Resource
    private IPpEParallelReaddatapathlistService ppEParallelReaddatapathlistService;

    @Resource
    private IPpEParallelReadgrouplistService ppEParallelReadgrouplistService;

    @Resource
    private IPpEParallelReadidentitylistService ppEParallelReadidentitylistService;

    @Resource
    private IPpEParallelReadunitlistService ppEParallelReadunitlistService;

    @Resource
    private IPpEParallelReviewdatapathlistService ppEParallelReviewdatapathlistService;
    @Resource
    private IPpEParallelReviewgrouplistService ppEParallelReviewgrouplistService;

    @Resource
    private IPpEParallelReviewidentitylistService ppEParallelReviewidentitylistService;

    @Resource
    private IPpEParallelReviewunitlistService ppEParallelReviewunitlistService;

    @Resource
    private IPpEParallelRoutelistService ppEParallelRoutelistService;

    private void getParallelInfo(String flag, ComplexVO complexVO) {
        List<PpEParallel> ppEParallelList = ppEParallelService.lambdaQuery().eq(PpEParallel::getXprocess, flag).list();
        if (ppEParallelList.isEmpty()){
            complexVO.setParallelList(Collections.emptyList());
            return;
        }
        List<ParallelVO> ParallelVOList = new ArrayList<>();
        for (PpEParallel ppEParallel : ppEParallelList) {
            ParallelVO ParallelVO = BeanUtil.copyProperties(ppEParallel, ParallelVO.class);
            Map<String,Object> properties = JSONUtil.toBean(ppEParallel.getXproperties(), Map.class);
            if (properties != null){
                ParallelVO.setProperties(properties);
            } else {
                ParallelVO.setProperties(Collections.emptyMap());
            }
            ParallelVOList.add(ParallelVO);
        }
        List<String> ids = ParallelVOList.stream().map(ParallelVO::getId).collect(Collectors.toList());


        List<PpEParallelReaddatapathlist> ppEParallelReaddatapathlistList = ppEParallelReaddatapathlistService.listByIds(ids);
        if (ppEParallelReaddatapathlistList != null){
            for (ParallelVO ParallelVO : ParallelVOList) {
                String ParallelVOId = ParallelVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEParallelReaddatapathlist ppEParallelReaddatapathlist : ppEParallelReaddatapathlistList) {
                    if (ParallelVOId.equals(ppEParallelReaddatapathlist.getParallelXid())){
                        list.add(ppEParallelReaddatapathlist.getXorderColumn(),ppEParallelReaddatapathlist.getXreadDataPathList());
                    }
                }
                ParallelVO.setReadDataPathList(list);
            }
        }else {
            ParallelVOList.forEach(ParallelVO -> ParallelVO.setReadDataPathList(Collections.emptyList()));
        }


        List<PpEParallelReadgrouplist> ppEParallelReadgrouplistList = ppEParallelReadgrouplistService.listByIds(ids);
        if (ppEParallelReadgrouplistList != null){
            for (ParallelVO ParallelVO : ParallelVOList) {
                String ParallelVOId = ParallelVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEParallelReadgrouplist ppEParallelReadgrouplist : ppEParallelReadgrouplistList) {
                    if (ParallelVOId.equals(ppEParallelReadgrouplist.getParallelXid())){
                        list.add(ppEParallelReadgrouplist.getXorderColumn(),ppEParallelReadgrouplist.getXreadGroupList());
                    }
                }
                ParallelVO.setReadGroupList(list);
            }
        }else {
            ParallelVOList.forEach(ParallelVO -> ParallelVO.setReadGroupList(Collections.emptyList()));
        }

        List<PpEParallelReadidentitylist> ppEParallelReadidentitylistList = ppEParallelReadidentitylistService.listByIds(ids);
        if (ppEParallelReadidentitylistList != null){
            for (ParallelVO ParallelVO : ParallelVOList) {
                String ParallelVOId = ParallelVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEParallelReadidentitylist ppEParallelReadidentitylist : ppEParallelReadidentitylistList) {
                    if (ParallelVOId.equals(ppEParallelReadidentitylist.getParallelXid())){
                        list.add(ppEParallelReadidentitylist.getXorderColumn(),ppEParallelReadidentitylist.getXreadIdentityList());
                    }
                }
                ParallelVO.setReadIdentityList(list);
            }
        }else {
            ParallelVOList.forEach(ParallelVO -> ParallelVO.setReadIdentityList(Collections.emptyList()));
        }

        List<PpEParallelReadunitlist> ppEParallelReadunitlistList = ppEParallelReadunitlistService.listByIds(ids);
        if (ppEParallelReadunitlistList != null){
            for (ParallelVO ParallelVO : ParallelVOList) {
                String ParallelVOId = ParallelVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEParallelReadunitlist ppEParallelReadunitlist : ppEParallelReadunitlistList) {
                    if (ParallelVOId.equals(ppEParallelReadunitlist.getParallelXid())){
                        list.add(ppEParallelReadunitlist.getXorderColumn(),ppEParallelReadunitlist.getXreadUnitList());
                    }
                }
                ParallelVO.setReadUnitList(list);
            }
        }else {
            ParallelVOList.forEach(ParallelVO -> ParallelVO.setReadUnitList(Collections.emptyList()));
        }

        List<PpEParallelReviewdatapathlist> ppEParallelReviewdatapathlistList = ppEParallelReviewdatapathlistService.listByIds(ids);
        if (ppEParallelReviewdatapathlistList != null){
            for (ParallelVO ParallelVO : ParallelVOList) {
                String ParallelVOId = ParallelVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEParallelReviewdatapathlist ppEParallelReviewdatapathlist : ppEParallelReviewdatapathlistList) {
                    if (ParallelVOId.equals(ppEParallelReviewdatapathlist.getParallelXid())){
                        list.add(ppEParallelReviewdatapathlist.getXorderColumn(),ppEParallelReviewdatapathlist.getXreviewDataPathList());
                    }
                }
                ParallelVO.setReviewDataPathList(list);
            }
        }else {
            ParallelVOList.forEach(ParallelVO -> ParallelVO.setReviewDataPathList(Collections.emptyList()));
        }

        List<PpEParallelReviewgrouplist> ppEParallelReviewgrouplistList = ppEParallelReviewgrouplistService.listByIds(ids);
        if (ppEParallelReviewgrouplistList != null){
            for (ParallelVO ParallelVO : ParallelVOList) {
                String ParallelVOId = ParallelVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEParallelReviewgrouplist ppEParallelReviewgrouplist : ppEParallelReviewgrouplistList) {
                    if (ParallelVOId.equals(ppEParallelReviewgrouplist.getParallelXid())){
                        list.add(ppEParallelReviewgrouplist.getXorderColumn(),ppEParallelReviewgrouplist.getXreviewGroupList());
                    }
                }
                ParallelVO.setReviewGroupList(list);
            }
        }else {
            ParallelVOList.forEach(ParallelVO -> ParallelVO.setReviewGroupList(Collections.emptyList()));
        }

        List<PpEParallelReviewidentitylist> ppEParallelReviewidentitylistList = ppEParallelReviewidentitylistService.listByIds(ids);
        if (ppEParallelReviewidentitylistList != null){
            for (ParallelVO ParallelVO : ParallelVOList) {
                String ParallelVOId = ParallelVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEParallelReviewidentitylist ppEParallelReviewidentitylist : ppEParallelReviewidentitylistList) {
                    if (ParallelVOId.equals(ppEParallelReviewidentitylist.getParallelXid())){
                        list.add(ppEParallelReviewidentitylist.getXorderColumn(),ppEParallelReviewidentitylist.getXreviewIdentityList());
                    }
                }
                ParallelVO.setReviewIdentityList(list);
            }
        }else {
            ParallelVOList.forEach(ParallelVO -> ParallelVO.setReviewIdentityList(Collections.emptyList()));
        }

        List<PpEParallelReviewunitlist> ppEParallelReviewunitlistList = ppEParallelReviewunitlistService.listByIds(ids);
        if (ppEParallelReviewunitlistList != null){
            for (ParallelVO ParallelVO : ParallelVOList) {
                String ParallelVOId = ParallelVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEParallelReviewunitlist ppEParallelReviewunitlist : ppEParallelReviewunitlistList) {
                    if (ParallelVOId.equals(ppEParallelReviewunitlist.getParallelXid())){
                        list.add(ppEParallelReviewunitlist.getXorderColumn(),ppEParallelReviewunitlist.getXreviewUnitList());
                    }
                }
                ParallelVO.setReviewUnitList(list);
            }
        }else {
            ParallelVOList.forEach(ParallelVO -> ParallelVO.setReviewUnitList(Collections.emptyList()));
        }

        List<PpEParallelRoutelist> ppEParallelRoutelistList = ppEParallelRoutelistService.listByIds(ids);
        if (ppEParallelRoutelistList != null){
            for (ParallelVO ParallelVO : ParallelVOList) {
                String ParallelVOId = ParallelVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEParallelRoutelist ppEParallelRoutelist : ppEParallelRoutelistList) {
                    if (ParallelVOId.equals(ppEParallelRoutelist.getParallelXid())){
                        list.add(ppEParallelRoutelist.getXorderColumn(),ppEParallelRoutelist.getXrouteList());
                    }
                }
                ParallelVO.setRouteList(list);
            }
        }else {
            ParallelVOList.forEach(ParallelVO -> ParallelVO.setRouteList(Collections.emptyList()));
        }


        complexVO.setParallelList(ParallelVOList);

    }








    @Resource
    private IPpEMergeService ppEMergeService;

    @Resource
    private IPpEMergeReaddatapathlistService ppEMergeReaddatapathlistService;

    @Resource
    private IPpEMergeReadgrouplistService ppEMergeReadgrouplistService;

    @Resource
    private IPpEMergeReadidentitylistService ppEMergeReadidentitylistService;

    @Resource
    private IPpEMergeReadunitlistService ppEMergeReadunitlistService;

    @Resource
    private IPpEMergeReviewdatapathlistService ppEMergeReviewdatapathlistService;
    @Resource
    private IPpEMergeReviewgrouplistService ppEMergeReviewgrouplistService;
    @Resource
    private IPpEMergeReviewidentitylistService ppEMergeReviewidentitylistService;
    @Resource
    private IPpEMergeReviewunitlistService ppEMergeReviewunitlistService;


    private void getMergeInfo(String flag, ComplexVO complexVO) {
        List<PpEMerge> ppEMergeList = ppEMergeService.lambdaQuery().eq(PpEMerge::getXprocess, flag).list();
        if (ppEMergeList.isEmpty()){
            complexVO.setMergeList(Collections.emptyList());
            return;
        }
        List<MergeVO> MergeVOList = new ArrayList<>();

        for (PpEMerge ppEMerge : ppEMergeList) {
            MergeVO MergeVO = BeanUtil.copyProperties(ppEMerge, MergeVO.class);
            Map<String,Object> properties = JSONUtil.toBean(ppEMerge.getXproperties(), Map.class);
            if (properties != null){
                MergeVO.setProperties(properties);
            } else {
                MergeVO.setProperties(Collections.emptyMap());
            }
            MergeVOList.add(MergeVO);
        }

        List<String> ids = MergeVOList.stream().map(MergeVO::getId).collect(Collectors.toList());
        List<PpEMergeReaddatapathlist> ppEMergeReaddatapathlistList = ppEMergeReaddatapathlistService.listByIds(ids);
        if (ppEMergeReaddatapathlistList != null){
            for (MergeVO MergeVO : MergeVOList) {
                String MergeVOId = MergeVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEMergeReaddatapathlist ppEMergeReaddatapathlist : ppEMergeReaddatapathlistList) {
                    if (MergeVOId.equals(ppEMergeReaddatapathlist.getMergeXid())){
                        list.add(ppEMergeReaddatapathlist.getXorderColumn(),ppEMergeReaddatapathlist.getXreadDataPathList());
                    }
                }
                MergeVO.setReadDataPathList(list);
            }
        }else {
            MergeVOList.forEach(d -> d.setReadDataPathList(Collections.emptyList()));
        }

        List<PpEMergeReadgrouplist> ppEMergeReadgrouplistList = ppEMergeReadgrouplistService.listByIds(ids);
        if (ppEMergeReadgrouplistList != null){
            for (MergeVO MergeVO : MergeVOList) {
                String MergeVOId = MergeVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEMergeReadgrouplist ppEMergeReadgrouplist : ppEMergeReadgrouplistList) {
                    if (MergeVOId.equals(ppEMergeReadgrouplist.getMergeXid())){
                        list.add(ppEMergeReadgrouplist.getXorderColumn(),ppEMergeReadgrouplist.getXreadGroupList());
                    }
                }
                MergeVO.setReadGroupList(list);
            }
        }else {
            MergeVOList.forEach(d -> d.setReadGroupList(Collections.emptyList()));
        }


        List<PpEMergeReadidentitylist> ppEMergeReadidentitylistList = ppEMergeReadidentitylistService.listByIds(ids);
        if (ppEMergeReadidentitylistList != null){
            for (MergeVO MergeVO : MergeVOList) {
                String MergeVOId = MergeVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEMergeReadidentitylist ppEMergeReadidentitylist : ppEMergeReadidentitylistList) {
                    if (MergeVOId.equals(ppEMergeReadidentitylist.getMergeXid())){
                        list.add(ppEMergeReadidentitylist.getXorderColumn(),ppEMergeReadidentitylist.getXreadIdentityList());
                    }
                }
                MergeVO.setReadIdentityList(list);
            }
        }else {
            MergeVOList.forEach(d -> d.setReadIdentityList(Collections.emptyList()));
        }

        List<PpEMergeReadunitlist> ppEMergeReadunitlistList = ppEMergeReadunitlistService.listByIds(ids);
        if (ppEMergeReadunitlistList != null){
            for (MergeVO MergeVO : MergeVOList) {
                String MergeVOId = MergeVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEMergeReadunitlist ppEMergeReadunitlist : ppEMergeReadunitlistList) {
                    if (MergeVOId.equals(ppEMergeReadunitlist.getMergeXid())){
                        list.add(ppEMergeReadunitlist.getXorderColumn(),ppEMergeReadunitlist.getXreadUnitList());
                    }
                }
                MergeVO.setReadUnitList(list);
            }
        }else {
            MergeVOList.forEach(d -> d.setReadUnitList(Collections.emptyList()));
        }

        List<PpEMergeReviewdatapathlist> ppEMergeReviewdatapathlistList = ppEMergeReviewdatapathlistService.listByIds(ids);
        if (ppEMergeReviewdatapathlistList != null){
            for (MergeVO MergeVO : MergeVOList) {
                String MergeVOId = MergeVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEMergeReviewdatapathlist ppEMergeReviewdatapathlist : ppEMergeReviewdatapathlistList) {
                    if (MergeVOId.equals(ppEMergeReviewdatapathlist.getMergeXid())){
                        list.add(ppEMergeReviewdatapathlist.getXorderColumn(),ppEMergeReviewdatapathlist.getXreviewDataPathList());
                    }
                }
                MergeVO.setReviewDataPathList(list);
            }
        }else {
            MergeVOList.forEach(d -> d.setReviewDataPathList(Collections.emptyList()));
        }

        List<PpEMergeReviewgrouplist> ppEMergeReviewgrouplistList = ppEMergeReviewgrouplistService.listByIds(ids);
        if (ppEMergeReviewgrouplistList != null){
            for (MergeVO MergeVO : MergeVOList) {
                String MergeVOId = MergeVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEMergeReviewgrouplist ppEMergeReviewgrouplist : ppEMergeReviewgrouplistList) {
                    if (MergeVOId.equals(ppEMergeReviewgrouplist.getMergeXid())){
                        list.add(ppEMergeReviewgrouplist.getXorderColumn(),ppEMergeReviewgrouplist.getXreviewGroupList());
                    }
                }
                MergeVO.setReviewGroupList(list);
            }
        }else {
            MergeVOList.forEach(d -> d.setReviewGroupList(Collections.emptyList()));
        }


        List<PpEMergeReviewidentitylist> ppEMergeReviewidentitylistList = ppEMergeReviewidentitylistService.listByIds(ids);
        if (ppEMergeReviewidentitylistList != null){
            for (MergeVO MergeVO : MergeVOList) {
                String MergeVOId = MergeVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEMergeReviewidentitylist ppEMergeReviewidentitylist : ppEMergeReviewidentitylistList) {
                    if (MergeVOId.equals(ppEMergeReviewidentitylist.getMergeXid())){
                        list.add(ppEMergeReviewidentitylist.getXorderColumn(),ppEMergeReviewidentitylist.getXreviewIdentityList());
                    }
                }
                MergeVO.setReviewIdentityList(list);
            }
        }else {
            MergeVOList.forEach(d -> d.setReviewIdentityList(Collections.emptyList()));
        }

        List<PpEMergeReviewunitlist> ppEMergeReviewunitlistList = ppEMergeReviewunitlistService.listByIds(ids);
        if (ppEMergeReviewunitlistList != null){
            for (MergeVO MergeVO : MergeVOList) {
                String MergeVOId = MergeVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEMergeReviewunitlist ppEMergeReviewunitlist : ppEMergeReviewunitlistList) {
                    if (MergeVOId.equals(ppEMergeReviewunitlist.getMergeXid())){
                        list.add(ppEMergeReviewunitlist.getXorderColumn(),ppEMergeReviewunitlist.getXreviewUnitList());
                    }
                }
                MergeVO.setReviewUnitList(list);
            }
        }else {
            MergeVOList.forEach(d -> d.setReviewUnitList(Collections.emptyList()));
        }

        complexVO.setMergeList(MergeVOList);

    }


    @Resource
    private IPpEInvokeService ppEInvokeService;

    @Resource
    private IPpEInvokeReaddatapathlistService ppEInvokeReaddatapathlistService;

    @Resource
    private IPpEInvokeReadgrouplistService ppEInvokeReadgrouplistService;

    @Resource
    private IPpEInvokeReadidentitylistService ppEInvokeReadidentitylistService;

    @Resource
    private IPpEInvokeReadunitlistService ppEInvokeReadunitlistService;

    @Resource
    private IPpEInvokeReviewdatapathlistService ppEInvokeReviewdatapathlistService;
    @Resource
    private IPpEInvokeReviewgrouplistService ppEInvokeReviewgrouplistService;
    @Resource
    private IPpEInvokeReviewidentitylistService ppEInvokeReviewidentitylistService;
    @Resource
    private IPpEInvokeReviewunitlistService ppEInvokeReviewunitlistService;


    private void getInvokeInfo(String flag, ComplexVO complexVO) {
        List<PpEInvoke> ppEInvokeList = ppEInvokeService.lambdaQuery().eq(PpEInvoke::getXprocess, flag).list();
        if (ppEInvokeList.isEmpty()){
            complexVO.setInvokeList(Collections.emptyList());
            return;
        }
        List<InvokeVO> InvokeVOList = new ArrayList<>();

        for (PpEInvoke ppEInvoke : ppEInvokeList) {
            InvokeVO InvokeVO = BeanUtil.copyProperties(ppEInvoke, InvokeVO.class);
            Map<String,Object> properties = JSONUtil.toBean(ppEInvoke.getXproperties(), Map.class);
            if (properties != null){
                InvokeVO.setProperties(properties);
            } else {
                InvokeVO.setProperties(Collections.emptyMap());
            }
            InvokeVOList.add(InvokeVO);
        }

        List<String> ids = InvokeVOList.stream().map(InvokeVO::getId).collect(Collectors.toList());
        List<PpEInvokeReaddatapathlist> ppEInvokeReaddatapathlistList = ppEInvokeReaddatapathlistService.listByIds(ids);
        if (ppEInvokeReaddatapathlistList != null){
            for (InvokeVO InvokeVO : InvokeVOList) {
                String InvokeVOId = InvokeVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEInvokeReaddatapathlist ppEInvokeReaddatapathlist : ppEInvokeReaddatapathlistList) {
                    if (InvokeVOId.equals(ppEInvokeReaddatapathlist.getInvokeXid())){
                        list.add(ppEInvokeReaddatapathlist.getXorderColumn(),ppEInvokeReaddatapathlist.getXreadDataPathList());
                    }
                }
                InvokeVO.setReadDataPathList(list);
            }
        }else {
            InvokeVOList.forEach(d -> d.setReadDataPathList(Collections.emptyList()));
        }

        List<PpEInvokeReadgrouplist> ppEInvokeReadgrouplistList = ppEInvokeReadgrouplistService.listByIds(ids);
        if (ppEInvokeReadgrouplistList != null){
            for (InvokeVO InvokeVO : InvokeVOList) {
                String InvokeVOId = InvokeVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEInvokeReadgrouplist ppEInvokeReadgrouplist : ppEInvokeReadgrouplistList) {
                    if (InvokeVOId.equals(ppEInvokeReadgrouplist.getInvokeXid())){
                        list.add(ppEInvokeReadgrouplist.getXorderColumn(),ppEInvokeReadgrouplist.getXreadGroupList());
                    }
                }
                InvokeVO.setReadGroupList(list);
            }
        }else {
            InvokeVOList.forEach(d -> d.setReadGroupList(Collections.emptyList()));
        }


        List<PpEInvokeReadidentitylist> ppEInvokeReadidentitylistList = ppEInvokeReadidentitylistService.listByIds(ids);
        if (ppEInvokeReadidentitylistList != null){
            for (InvokeVO InvokeVO : InvokeVOList) {
                String InvokeVOId = InvokeVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEInvokeReadidentitylist ppEInvokeReadidentitylist : ppEInvokeReadidentitylistList) {
                    if (InvokeVOId.equals(ppEInvokeReadidentitylist.getInvokeXid())){
                        list.add(ppEInvokeReadidentitylist.getXorderColumn(),ppEInvokeReadidentitylist.getXreadIdentityList());
                    }
                }
                InvokeVO.setReadIdentityList(list);
            }
        }else {
            InvokeVOList.forEach(d -> d.setReadIdentityList(Collections.emptyList()));
        }

        List<PpEInvokeReadunitlist> ppEInvokeReadunitlistList = ppEInvokeReadunitlistService.listByIds(ids);
        if (ppEInvokeReadunitlistList != null){
            for (InvokeVO InvokeVO : InvokeVOList) {
                String InvokeVOId = InvokeVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEInvokeReadunitlist ppEInvokeReadunitlist : ppEInvokeReadunitlistList) {
                    if (InvokeVOId.equals(ppEInvokeReadunitlist.getInvokeXid())){
                        list.add(ppEInvokeReadunitlist.getXorderColumn(),ppEInvokeReadunitlist.getXreadUnitList());
                    }
                }
                InvokeVO.setReadUnitList(list);
            }
        }else {
            InvokeVOList.forEach(d -> d.setReadUnitList(Collections.emptyList()));
        }

        List<PpEInvokeReviewdatapathlist> ppEInvokeReviewdatapathlistList = ppEInvokeReviewdatapathlistService.listByIds(ids);
        if (ppEInvokeReviewdatapathlistList != null){
            for (InvokeVO InvokeVO : InvokeVOList) {
                String InvokeVOId = InvokeVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEInvokeReviewdatapathlist ppEInvokeReviewdatapathlist : ppEInvokeReviewdatapathlistList) {
                    if (InvokeVOId.equals(ppEInvokeReviewdatapathlist.getInvokeXid())){
                        list.add(ppEInvokeReviewdatapathlist.getXorderColumn(),ppEInvokeReviewdatapathlist.getXreviewDataPathList());
                    }
                }
                InvokeVO.setReviewDataPathList(list);
            }
        }else {
            InvokeVOList.forEach(d -> d.setReviewDataPathList(Collections.emptyList()));
        }

        List<PpEInvokeReviewgrouplist> ppEInvokeReviewgrouplistList = ppEInvokeReviewgrouplistService.listByIds(ids);
        if (ppEInvokeReviewgrouplistList != null){
            for (InvokeVO InvokeVO : InvokeVOList) {
                String InvokeVOId = InvokeVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEInvokeReviewgrouplist ppEInvokeReviewgrouplist : ppEInvokeReviewgrouplistList) {
                    if (InvokeVOId.equals(ppEInvokeReviewgrouplist.getInvokeXid())){
                        list.add(ppEInvokeReviewgrouplist.getXorderColumn(),ppEInvokeReviewgrouplist.getXreviewGroupList());
                    }
                }
                InvokeVO.setReviewGroupList(list);
            }
        }else {
            InvokeVOList.forEach(d -> d.setReviewGroupList(Collections.emptyList()));
        }


        List<PpEInvokeReviewidentitylist> ppEInvokeReviewidentitylistList = ppEInvokeReviewidentitylistService.listByIds(ids);
        if (ppEInvokeReviewidentitylistList != null){
            for (InvokeVO InvokeVO : InvokeVOList) {
                String InvokeVOId = InvokeVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEInvokeReviewidentitylist ppEInvokeReviewidentitylist : ppEInvokeReviewidentitylistList) {
                    if (InvokeVOId.equals(ppEInvokeReviewidentitylist.getInvokeXid())){
                        list.add(ppEInvokeReviewidentitylist.getXorderColumn(),ppEInvokeReviewidentitylist.getXreviewIdentityList());
                    }
                }
                InvokeVO.setReviewIdentityList(list);
            }
        }else {
            InvokeVOList.forEach(d -> d.setReviewIdentityList(Collections.emptyList()));
        }

        List<PpEInvokeReviewunitlist> ppEInvokeReviewunitlistList = ppEInvokeReviewunitlistService.listByIds(ids);
        if (ppEInvokeReviewunitlistList != null){
            for (InvokeVO InvokeVO : InvokeVOList) {
                String InvokeVOId = InvokeVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEInvokeReviewunitlist ppEInvokeReviewunitlist : ppEInvokeReviewunitlistList) {
                    if (InvokeVOId.equals(ppEInvokeReviewunitlist.getInvokeXid())){
                        list.add(ppEInvokeReviewunitlist.getXorderColumn(),ppEInvokeReviewunitlist.getXreviewUnitList());
                    }
                }
                InvokeVO.setReviewUnitList(list);
            }
        }else {
            InvokeVOList.forEach(d -> d.setReviewUnitList(Collections.emptyList()));
        }

        complexVO.setInvokeList(InvokeVOList);

    }




    @Resource
    private IPpEEmbedService ppEEmbedService;

    @Resource
    private IPpEEmbedReaddatapathlistService ppEEmbedReaddatapathlistService;

    @Resource
    private IPpEEmbedReadgrouplistService ppEEmbedReadgrouplistService;

    @Resource
    private IPpEEmbedReadidentitylistService ppEEmbedReadidentitylistService;

    @Resource
    private IPpEEmbedReadunitlistService ppEEmbedReadunitlistService;

    @Resource
    private IPpEEmbedReviewdatapathlistService ppEEmbedReviewdatapathlistService;
    @Resource
    private IPpEEmbedReviewgrouplistService ppEEmbedReviewgrouplistService;
    @Resource
    private IPpEEmbedReviewidentitylistService ppEEmbedReviewidentitylistService;
    @Resource
    private IPpEEmbedReviewunitlistService ppEEmbedReviewunitlistService;


    private void getEmbedInfo(String flag, ComplexVO complexVO) {
        List<PpEEmbed> ppEEmbedList = ppEEmbedService.lambdaQuery().eq(PpEEmbed::getXprocess, flag).list();
        if (ppEEmbedList.isEmpty()){
            complexVO.setEmbedList(Collections.emptyList());
            return;
        }
        List<EmbedVO> EmbedVOList = new ArrayList<>();

        for (PpEEmbed ppEEmbed : ppEEmbedList) {
            EmbedVO EmbedVO = BeanUtil.copyProperties(ppEEmbed, EmbedVO.class);
            Map<String,Object> properties = JSONUtil.toBean(ppEEmbed.getXproperties(), Map.class);
            if (properties != null){
                EmbedVO.setProperties(properties);
            } else {
                EmbedVO.setProperties(Collections.emptyMap());
            }
            EmbedVOList.add(EmbedVO);
        }

        List<String> ids = EmbedVOList.stream().map(EmbedVO::getId).collect(Collectors.toList());
        List<PpEEmbedReaddatapathlist> ppEEmbedReaddatapathlistList = ppEEmbedReaddatapathlistService.listByIds(ids);
        if (ppEEmbedReaddatapathlistList != null){
            for (EmbedVO EmbedVO : EmbedVOList) {
                String EmbedVOId = EmbedVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEEmbedReaddatapathlist ppEEmbedReaddatapathlist : ppEEmbedReaddatapathlistList) {
                    if (EmbedVOId.equals(ppEEmbedReaddatapathlist.getEmbedXid())){
                        list.add(ppEEmbedReaddatapathlist.getXorderColumn(),ppEEmbedReaddatapathlist.getXreadDataPathList());
                    }
                }
                EmbedVO.setReadDataPathList(list);
            }
        }else {
            EmbedVOList.forEach(d -> d.setReadDataPathList(Collections.emptyList()));
        }

        List<PpEEmbedReadgrouplist> ppEEmbedReadgrouplistList = ppEEmbedReadgrouplistService.listByIds(ids);
        if (ppEEmbedReadgrouplistList != null){
            for (EmbedVO EmbedVO : EmbedVOList) {
                String EmbedVOId = EmbedVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEEmbedReadgrouplist ppEEmbedReadgrouplist : ppEEmbedReadgrouplistList) {
                    if (EmbedVOId.equals(ppEEmbedReadgrouplist.getEmbedXid())){
                        list.add(ppEEmbedReadgrouplist.getXorderColumn(),ppEEmbedReadgrouplist.getXreadGroupList());
                    }
                }
                EmbedVO.setReadGroupList(list);
            }
        }else {
            EmbedVOList.forEach(d -> d.setReadGroupList(Collections.emptyList()));
        }


        List<PpEEmbedReadidentitylist> ppEEmbedReadidentitylistList = ppEEmbedReadidentitylistService.listByIds(ids);
        if (ppEEmbedReadidentitylistList != null){
            for (EmbedVO EmbedVO : EmbedVOList) {
                String EmbedVOId = EmbedVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEEmbedReadidentitylist ppEEmbedReadidentitylist : ppEEmbedReadidentitylistList) {
                    if (EmbedVOId.equals(ppEEmbedReadidentitylist.getEmbedXid())){
                        list.add(ppEEmbedReadidentitylist.getXorderColumn(),ppEEmbedReadidentitylist.getXreadIdentityList());
                    }
                }
                EmbedVO.setReadIdentityList(list);
            }
        }else {
            EmbedVOList.forEach(d -> d.setReadIdentityList(Collections.emptyList()));
        }

        List<PpEEmbedReadunitlist> ppEEmbedReadunitlistList = ppEEmbedReadunitlistService.listByIds(ids);
        if (ppEEmbedReadunitlistList != null){
            for (EmbedVO EmbedVO : EmbedVOList) {
                String EmbedVOId = EmbedVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEEmbedReadunitlist ppEEmbedReadunitlist : ppEEmbedReadunitlistList) {
                    if (EmbedVOId.equals(ppEEmbedReadunitlist.getEmbedXid())){
                        list.add(ppEEmbedReadunitlist.getXorderColumn(),ppEEmbedReadunitlist.getXreadUnitList());
                    }
                }
                EmbedVO.setReadUnitList(list);
            }
        }else {
            EmbedVOList.forEach(d -> d.setReadUnitList(Collections.emptyList()));
        }

        List<PpEEmbedReviewdatapathlist> ppEEmbedReviewdatapathlistList = ppEEmbedReviewdatapathlistService.listByIds(ids);
        if (ppEEmbedReviewdatapathlistList != null){
            for (EmbedVO EmbedVO : EmbedVOList) {
                String EmbedVOId = EmbedVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEEmbedReviewdatapathlist ppEEmbedReviewdatapathlist : ppEEmbedReviewdatapathlistList) {
                    if (EmbedVOId.equals(ppEEmbedReviewdatapathlist.getEmbedXid())){
                        list.add(ppEEmbedReviewdatapathlist.getXorderColumn(),ppEEmbedReviewdatapathlist.getXreviewDataPathList());
                    }
                }
                EmbedVO.setReviewDataPathList(list);
            }
        }else {
            EmbedVOList.forEach(d -> d.setReviewDataPathList(Collections.emptyList()));
        }

        List<PpEEmbedReviewgrouplist> ppEEmbedReviewgrouplistList = ppEEmbedReviewgrouplistService.listByIds(ids);
        if (ppEEmbedReviewgrouplistList != null){
            for (EmbedVO EmbedVO : EmbedVOList) {
                String EmbedVOId = EmbedVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEEmbedReviewgrouplist ppEEmbedReviewgrouplist : ppEEmbedReviewgrouplistList) {
                    if (EmbedVOId.equals(ppEEmbedReviewgrouplist.getEmbedXid())){
                        list.add(ppEEmbedReviewgrouplist.getXorderColumn(),ppEEmbedReviewgrouplist.getXreviewGroupList());
                    }
                }
                EmbedVO.setReviewGroupList(list);
            }
        }else {
            EmbedVOList.forEach(d -> d.setReviewGroupList(Collections.emptyList()));
        }


        List<PpEEmbedReviewidentitylist> ppEEmbedReviewidentitylistList = ppEEmbedReviewidentitylistService.listByIds(ids);
        if (ppEEmbedReviewidentitylistList != null){
            for (EmbedVO EmbedVO : EmbedVOList) {
                String EmbedVOId = EmbedVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEEmbedReviewidentitylist ppEEmbedReviewidentitylist : ppEEmbedReviewidentitylistList) {
                    if (EmbedVOId.equals(ppEEmbedReviewidentitylist.getEmbedXid())){
                        list.add(ppEEmbedReviewidentitylist.getXorderColumn(),ppEEmbedReviewidentitylist.getXreviewIdentityList());
                    }
                }
                EmbedVO.setReviewIdentityList(list);
            }
        }else {
            EmbedVOList.forEach(d -> d.setReviewIdentityList(Collections.emptyList()));
        }

        List<PpEEmbedReviewunitlist> ppEEmbedReviewunitlistList = ppEEmbedReviewunitlistService.listByIds(ids);
        if (ppEEmbedReviewunitlistList != null){
            for (EmbedVO EmbedVO : EmbedVOList) {
                String EmbedVOId = EmbedVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEEmbedReviewunitlist ppEEmbedReviewunitlist : ppEEmbedReviewunitlistList) {
                    if (EmbedVOId.equals(ppEEmbedReviewunitlist.getEmbedXid())){
                        list.add(ppEEmbedReviewunitlist.getXorderColumn(),ppEEmbedReviewunitlist.getXreviewUnitList());
                    }
                }
                EmbedVO.setReviewUnitList(list);
            }
        }else {
            EmbedVOList.forEach(d -> d.setReviewUnitList(Collections.emptyList()));
        }

        complexVO.setEmbedList(EmbedVOList);

    }


    @Resource
    private IPpEDelayService ppEDelayService;

    @Resource
    private IPpEDelayReaddatapathlistService ppEDelayReaddatapathlistService;

    @Resource
    private IPpEDelayReadgrouplistService ppEDelayReadgrouplistService;

    @Resource
    private IPpEDelayReadidentitylistService ppEDelayReadidentitylistService;

    @Resource
    private IPpEDelayReadunitlistService ppEDelayReadunitlistService;

    @Resource
    private IPpEDelayReviewdatapathlistService ppEDelayReviewdatapathlistService;
    @Resource
    private IPpEDelayReviewgrouplistService ppEDelayReviewgrouplistService;
    @Resource
    private IPpEDelayReviewidentitylistService ppEDelayReviewidentitylistService;
    @Resource
    private IPpEDelayReviewunitlistService ppEDelayReviewunitlistService;

    private void getDelayInfo(String flag, ComplexVO complexVO) {

        List<PpEDelay> ppEDelayList = ppEDelayService.lambdaQuery().eq(PpEDelay::getXprocess, flag).list();
        if (ppEDelayList.isEmpty()){
            complexVO.setDelayList(Collections.emptyList());
            return;
        }
        List<DelayVO> delayVOList = new ArrayList<>();

        for (PpEDelay ppEDelay : ppEDelayList) {
            DelayVO delayVO = BeanUtil.copyProperties(ppEDelay, DelayVO.class);
            Map<String,Object> properties = JSONUtil.toBean(ppEDelay.getXproperties(), Map.class);
            if (properties != null){
                delayVO.setProperties(properties);
            } else {
                delayVO.setProperties(Collections.emptyMap());
            }
            delayVOList.add(delayVO);
        }

        List<String> ids = delayVOList.stream().map(DelayVO::getId).collect(Collectors.toList());
        List<PpEDelayReaddatapathlist> ppEDelayReaddatapathlistList = ppEDelayReaddatapathlistService.listByIds(ids);
        if (ppEDelayReaddatapathlistList != null){
            for (DelayVO delayVO : delayVOList) {
                String delayVOId = delayVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEDelayReaddatapathlist ppEDelayReaddatapathlist : ppEDelayReaddatapathlistList) {
                    if (delayVOId.equals(ppEDelayReaddatapathlist.getDelayXid())){
                        list.add(ppEDelayReaddatapathlist.getXorderColumn(),ppEDelayReaddatapathlist.getXreadDataPathList());
                    }
                }
                delayVO.setReadDataPathList(list);
            }
        }else {
            delayVOList.forEach(d -> d.setReadDataPathList(Collections.emptyList()));
        }

        List<PpEDelayReadgrouplist> ppEDelayReadgrouplistList = ppEDelayReadgrouplistService.listByIds(ids);
        if (ppEDelayReadgrouplistList != null){
            for (DelayVO delayVO : delayVOList) {
                String delayVOId = delayVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEDelayReadgrouplist ppEDelayReadgrouplist : ppEDelayReadgrouplistList) {
                    if (delayVOId.equals(ppEDelayReadgrouplist.getDelayXid())){
                        list.add(ppEDelayReadgrouplist.getXorderColumn(),ppEDelayReadgrouplist.getXreadGroupList());
                    }
                }
                delayVO.setReadGroupList(list);
            }
        }else {
            delayVOList.forEach(d -> d.setReadGroupList(Collections.emptyList()));
        }


        List<PpEDelayReadidentitylist> ppEDelayReadidentitylistList = ppEDelayReadidentitylistService.listByIds(ids);
        if (ppEDelayReadidentitylistList != null){
            for (DelayVO delayVO : delayVOList) {
                String delayVOId = delayVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEDelayReadidentitylist ppEDelayReadidentitylist : ppEDelayReadidentitylistList) {
                    if (delayVOId.equals(ppEDelayReadidentitylist.getDelayXid())){
                        list.add(ppEDelayReadidentitylist.getXorderColumn(),ppEDelayReadidentitylist.getXreadIdentityList());
                    }
                }
                delayVO.setReadIdentityList(list);
            }
        }else {
            delayVOList.forEach(d -> d.setReadIdentityList(Collections.emptyList()));
        }

        List<PpEDelayReadunitlist> ppEDelayReadunitlistList = ppEDelayReadunitlistService.listByIds(ids);
        if (ppEDelayReadunitlistList != null){
            for (DelayVO delayVO : delayVOList) {
                String delayVOId = delayVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEDelayReadunitlist ppEDelayReadunitlist : ppEDelayReadunitlistList) {
                    if (delayVOId.equals(ppEDelayReadunitlist.getDelayXid())){
                        list.add(ppEDelayReadunitlist.getXorderColumn(),ppEDelayReadunitlist.getXreadUnitList());
                    }
                }
                delayVO.setReadUnitList(list);
            }
        }else {
            delayVOList.forEach(d -> d.setReadUnitList(Collections.emptyList()));
        }

        List<PpEDelayReviewdatapathlist> ppEDelayReviewdatapathlistList = ppEDelayReviewdatapathlistService.listByIds(ids);
        if (ppEDelayReviewdatapathlistList != null){
            for (DelayVO delayVO : delayVOList) {
                String delayVOId = delayVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEDelayReviewdatapathlist ppEDelayReviewdatapathlist : ppEDelayReviewdatapathlistList) {
                    if (delayVOId.equals(ppEDelayReviewdatapathlist.getDelayXid())){
                        list.add(ppEDelayReviewdatapathlist.getXorderColumn(),ppEDelayReviewdatapathlist.getXreviewDataPathList());
                    }
                }
                delayVO.setReviewDataPathList(list);
            }
        }else {
            delayVOList.forEach(d -> d.setReviewDataPathList(Collections.emptyList()));
        }

        List<PpEDelayReviewgrouplist> ppEDelayReviewgrouplistList = ppEDelayReviewgrouplistService.listByIds(ids);
        if (ppEDelayReviewgrouplistList != null){
            for (DelayVO delayVO : delayVOList) {
                String delayVOId = delayVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEDelayReviewgrouplist ppEDelayReviewgrouplist : ppEDelayReviewgrouplistList) {
                    if (delayVOId.equals(ppEDelayReviewgrouplist.getDelayXid())){
                        list.add(ppEDelayReviewgrouplist.getXorderColumn(),ppEDelayReviewgrouplist.getXreviewGroupList());
                    }
                }
                delayVO.setReviewGroupList(list);
            }
        }else {
            delayVOList.forEach(d -> d.setReviewGroupList(Collections.emptyList()));
        }


        List<PpEDelayReviewidentitylist> ppEDelayReviewidentitylistList = ppEDelayReviewidentitylistService.listByIds(ids);
        if (ppEDelayReviewidentitylistList != null){
            for (DelayVO delayVO : delayVOList) {
                String delayVOId = delayVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEDelayReviewidentitylist ppEDelayReviewidentitylist : ppEDelayReviewidentitylistList) {
                    if (delayVOId.equals(ppEDelayReviewidentitylist.getDelayXid())){
                        list.add(ppEDelayReviewidentitylist.getXorderColumn(),ppEDelayReviewidentitylist.getXreviewIdentityList());
                    }
                }
                delayVO.setReviewIdentityList(list);
            }
        }else {
            delayVOList.forEach(d -> d.setReviewIdentityList(Collections.emptyList()));
        }

        List<PpEDelayReviewunitlist> ppEDelayReviewunitlistList = ppEDelayReviewunitlistService.listByIds(ids);
        if (ppEDelayReviewunitlistList != null){
            for (DelayVO delayVO : delayVOList) {
                String delayVOId = delayVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEDelayReviewunitlist ppEDelayReviewunitlist : ppEDelayReviewunitlistList) {
                    if (delayVOId.equals(ppEDelayReviewunitlist.getDelayXid())){
                        list.add(ppEDelayReviewunitlist.getXorderColumn(),ppEDelayReviewunitlist.getXreviewUnitList());
                    }
                }
                delayVO.setReviewUnitList(list);
            }
        }else {
            delayVOList.forEach(d -> d.setReviewUnitList(Collections.emptyList()));
        }

        complexVO.setDelayList(delayVOList);


    }


    @Resource
    private IPpEChoiceService ppEChoiceService;

    @Resource
    private IPpEChoiceReaddatapathlistService ppEChoiceReaddatapathlistService;

    @Resource
    private IPpEChoiceReadgrouplistService ppEChoiceReadgrouplistService;

    @Resource
    private IPpEChoiceReadidentitylistService ppEChoiceReadidentitylistService;

    @Resource
    private IPpEChoiceReadunitlistService ppEChoiceReadunitlistService;

    @Resource
    private IPpEChoiceReviewdatapathlistService ppEChoiceReviewdatapathlistService;
    @Resource
    private IPpEChoiceReviewgrouplistService ppEChoiceReviewgrouplistService;

    @Resource
    private IPpEChoiceReviewidentitylistService ppEChoiceReviewidentitylistService;

    @Resource
    private IPpEChoiceReviewunitlistService ppEChoiceReviewunitlistService;

    @Resource
    private IPpEChoiceRoutelistService ppEChoiceRoutelistService;

    private void getChoiceInfo(String flag, ComplexVO complexVO) {
        List<PpEChoice> ppEChoiceList = ppEChoiceService.lambdaQuery().eq(PpEChoice::getXprocess, flag).list();
        if (ppEChoiceList.isEmpty()){
            complexVO.setChoiceList(Collections.emptyList());
            return;
        }
        List<ChoiceVO> choiceVOList = new ArrayList<>();
        for (PpEChoice ppEChoice : ppEChoiceList) {
            ChoiceVO choiceVO = BeanUtil.copyProperties(ppEChoice, ChoiceVO.class);
            Map<String,Object> properties = JSONUtil.toBean(ppEChoice.getXproperties(), Map.class);
            if (properties != null){
                choiceVO.setProperties(properties);
            } else {
                choiceVO.setProperties(Collections.emptyMap());
            }
            choiceVOList.add(choiceVO);
        }
        List<String> ids = choiceVOList.stream().map(ChoiceVO::getId).collect(Collectors.toList());


        List<PpEChoiceReaddatapathlist> ppEChoiceReaddatapathlistList = ppEChoiceReaddatapathlistService.listByIds(ids);
        if (ppEChoiceReaddatapathlistList != null){
            for (ChoiceVO choiceVO : choiceVOList) {
                String choiceVOId = choiceVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEChoiceReaddatapathlist ppEChoiceReaddatapathlist : ppEChoiceReaddatapathlistList) {
                    if (choiceVOId.equals(ppEChoiceReaddatapathlist.getChoiceXid())){
                       list.add(ppEChoiceReaddatapathlist.getXorderColumn(),ppEChoiceReaddatapathlist.getXreadDataPathList());
                    }
                }
                choiceVO.setReadDataPathList(list);
            }
        }else {
            choiceVOList.forEach(choiceVO -> choiceVO.setReadDataPathList(Collections.emptyList()));
        }


        List<PpEChoiceReadgrouplist> ppEChoiceReadgrouplistList = ppEChoiceReadgrouplistService.listByIds(ids);
        if (ppEChoiceReadgrouplistList != null){
            for (ChoiceVO choiceVO : choiceVOList) {
                String choiceVOId = choiceVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEChoiceReadgrouplist ppEChoiceReadgrouplist : ppEChoiceReadgrouplistList) {
                    if (choiceVOId.equals(ppEChoiceReadgrouplist.getChoiceXid())){
                        list.add(ppEChoiceReadgrouplist.getXorderColumn(),ppEChoiceReadgrouplist.getXreadGroupList());
                    }
                }
                choiceVO.setReadGroupList(list);
            }
        }else {
            choiceVOList.forEach(choiceVO -> choiceVO.setReadGroupList(Collections.emptyList()));
        }

        List<PpEChoiceReadidentitylist> ppEChoiceReadidentitylistList = ppEChoiceReadidentitylistService.listByIds(ids);
        if (ppEChoiceReadidentitylistList != null){
            for (ChoiceVO choiceVO : choiceVOList) {
                String choiceVOId = choiceVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEChoiceReadidentitylist ppEChoiceReadidentitylist : ppEChoiceReadidentitylistList) {
                    if (choiceVOId.equals(ppEChoiceReadidentitylist.getChoiceXid())){
                        list.add(ppEChoiceReadidentitylist.getXorderColumn(),ppEChoiceReadidentitylist.getXreadIdentityList());
                    }
                }
                choiceVO.setReadIdentityList(list);
            }
        }else {
            choiceVOList.forEach(choiceVO -> choiceVO.setReadIdentityList(Collections.emptyList()));
        }

        List<PpEChoiceReadunitlist> ppEChoiceReadunitlistList = ppEChoiceReadunitlistService.listByIds(ids);
        if (ppEChoiceReadunitlistList != null){
            for (ChoiceVO choiceVO : choiceVOList) {
                String choiceVOId = choiceVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEChoiceReadunitlist ppEChoiceReadunitlist : ppEChoiceReadunitlistList) {
                    if (choiceVOId.equals(ppEChoiceReadunitlist.getChoiceXid())){
                        list.add(ppEChoiceReadunitlist.getXorderColumn(),ppEChoiceReadunitlist.getXreadUnitList());
                    }
                }
                choiceVO.setReadUnitList(list);
            }
        }else {
            choiceVOList.forEach(choiceVO -> choiceVO.setReadUnitList(Collections.emptyList()));
        }

        List<PpEChoiceReviewdatapathlist> ppEChoiceReviewdatapathlistList = ppEChoiceReviewdatapathlistService.listByIds(ids);
        if (ppEChoiceReviewdatapathlistList != null){
            for (ChoiceVO choiceVO : choiceVOList) {
                String choiceVOId = choiceVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEChoiceReviewdatapathlist ppEChoiceReviewdatapathlist : ppEChoiceReviewdatapathlistList) {
                    if (choiceVOId.equals(ppEChoiceReviewdatapathlist.getChoiceXid())){
                        list.add(ppEChoiceReviewdatapathlist.getXorderColumn(),ppEChoiceReviewdatapathlist.getXreviewDataPathList());
                    }
                }
                choiceVO.setReviewDataPathList(list);
            }
        }else {
            choiceVOList.forEach(choiceVO -> choiceVO.setReviewDataPathList(Collections.emptyList()));
        }

        List<PpEChoiceReviewgrouplist> ppEChoiceReviewgrouplistList = ppEChoiceReviewgrouplistService.listByIds(ids);
        if (ppEChoiceReviewgrouplistList != null){
            for (ChoiceVO choiceVO : choiceVOList) {
                String choiceVOId = choiceVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEChoiceReviewgrouplist ppEChoiceReviewgrouplist : ppEChoiceReviewgrouplistList) {
                    if (choiceVOId.equals(ppEChoiceReviewgrouplist.getChoiceXid())){
                        list.add(ppEChoiceReviewgrouplist.getXorderColumn(),ppEChoiceReviewgrouplist.getXreviewGroupList());
                    }
                }
                choiceVO.setReviewGroupList(list);
            }
        }else {
            choiceVOList.forEach(choiceVO -> choiceVO.setReviewGroupList(Collections.emptyList()));
        }

        List<PpEChoiceReviewidentitylist> ppEChoiceReviewidentitylistList = ppEChoiceReviewidentitylistService.listByIds(ids);
        if (ppEChoiceReviewidentitylistList != null){
            for (ChoiceVO choiceVO : choiceVOList) {
                String choiceVOId = choiceVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEChoiceReviewidentitylist ppEChoiceReviewidentitylist : ppEChoiceReviewidentitylistList) {
                    if (choiceVOId.equals(ppEChoiceReviewidentitylist.getChoiceXid())){
                        list.add(ppEChoiceReviewidentitylist.getXorderColumn(),ppEChoiceReviewidentitylist.getXreviewIdentityList());
                    }
                }
                choiceVO.setReviewIdentityList(list);
            }
        }else {
            choiceVOList.forEach(choiceVO -> choiceVO.setReviewIdentityList(Collections.emptyList()));
        }

        List<PpEChoiceReviewunitlist> ppEChoiceReviewunitlistList = ppEChoiceReviewunitlistService.listByIds(ids);
        if (ppEChoiceReviewunitlistList != null){
            for (ChoiceVO choiceVO : choiceVOList) {
                String choiceVOId = choiceVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEChoiceReviewunitlist ppEChoiceReviewunitlist : ppEChoiceReviewunitlistList) {
                    if (choiceVOId.equals(ppEChoiceReviewunitlist.getChoiceXid())){
                        list.add(ppEChoiceReviewunitlist.getXorderColumn(),ppEChoiceReviewunitlist.getXreviewUnitList());
                    }
                }
                choiceVO.setReviewUnitList(list);
            }
        }else {
            choiceVOList.forEach(choiceVO -> choiceVO.setReviewUnitList(Collections.emptyList()));
        }

        List<PpEChoiceRoutelist> ppEChoiceRoutelistList = ppEChoiceRoutelistService.listByIds(ids);
        if (ppEChoiceRoutelistList != null){
            for (ChoiceVO choiceVO : choiceVOList) {
                String choiceVOId = choiceVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEChoiceRoutelist ppEChoiceRoutelist : ppEChoiceRoutelistList) {
                    if (choiceVOId.equals(ppEChoiceRoutelist.getChoiceXid())){
                        list.add(ppEChoiceRoutelist.getXorderColumn(),ppEChoiceRoutelist.getXrouteList());
                    }
                }
                choiceVO.setRouteList(list);
            }
        }else {
            choiceVOList.forEach(choiceVO -> choiceVO.setRouteList(Collections.emptyList()));
        }


        complexVO.setChoiceList(choiceVOList);

    }


    @Resource
    private IPpECancelService ppECancelService;

    @Resource
    private IPpECancelReaddatapathlistService ppECancelReaddatapathlistService;

    @Resource
    private IPpECancelReadgrouplistService ppECancelReadgrouplistService;

    @Resource
    private IPpECancelReadidentitylistService ppECancelReadidentitylistService;

    @Resource
    private IPpECancelReadunitlistService ppECancelReadunitlistService;

    @Resource
    private IPpECancelReviewdatapathlistService ppECancelReviewdatapathlistService;

    @Resource
    private IPpECancelReviewgrouplistService ppECancelReviewgrouplistService;

    @Resource
    private IPpECancelReviewidentitylistService ppECancelReviewidentitylistService;

    @Resource
    private IPpECancelReviewunitlistService ppECancelReviewunitlistService;


    private void getCancelInfo(String flag, ComplexVO complexVO) {
        List<PpECancel> ppECancelList = ppECancelService.lambdaQuery().eq(PpECancel::getXprocess, flag).list();
        if (ppECancelList.isEmpty()) {
            complexVO.setCancelList(Collections.emptyList());
            return;
        }
        List<CancelVO> cancelVOList = new ArrayList<>();
        for (PpECancel ppECancel : ppECancelList) {
            CancelVO cancelVO = BeanUtil.copyProperties(ppECancel, CancelVO.class);

            Map<String, Object> properties = JSONUtil.toBean(ppECancel.getXproperties(), Map.class);
            if (properties != null) {
                cancelVO.setProperties(properties);
            } else {
                cancelVO.setProperties(Collections.emptyMap());
            }
            cancelVOList.add(cancelVO);
        }

        List<String> ids = cancelVOList.stream().map(CancelVO::getId).collect(Collectors.toList());

        List<PpECancelReaddatapathlist> ppECancelReaddatapathlistList = ppECancelReaddatapathlistService.listByIds(ids);
        if (ppECancelReaddatapathlistList != null) {
            for (CancelVO cancelVO : cancelVOList) {
                String cancelVOId = cancelVO.getId();
                List<String> list = new ArrayList<>();
                for (PpECancelReaddatapathlist ppECancelReaddatapathlist : ppECancelReaddatapathlistList) {
                    if (cancelVOId.equals(ppECancelReaddatapathlist.getCancelXid())){
                        list.add(ppECancelReaddatapathlist.getXorderColumn(),ppECancelReaddatapathlist.getXreadDataPathList());
                    }
                }
                cancelVO.setReadDataPathList(list);
            }
        }else{
            cancelVOList.forEach(cancelVO -> cancelVO.setReadDataPathList(Collections.emptyList()));
        }

        List<PpECancelReadgrouplist> ppECancelReadgrouplistList = ppECancelReadgrouplistService.listByIds(ids);
        if (ppECancelReadgrouplistList != null){
            for (CancelVO cancelVO : cancelVOList) {
                String cancelVOId = cancelVO.getId();
                List<String> list = new ArrayList<>();
                for (PpECancelReadgrouplist ppECancelReadgrouplist : ppECancelReadgrouplistList) {
                    if (cancelVOId.equals(ppECancelReadgrouplist.getCancelXid())){
                        list.add(ppECancelReadgrouplist.getXorderColumn(),ppECancelReadgrouplist.getXreadGroupList());
                    }
                }
                cancelVO.setReadGroupList(list);
            }
        }else {
            cancelVOList.forEach(cancelVO -> cancelVO.setReadGroupList(Collections.emptyList()));
        }

        List<PpECancelReadidentitylist> ppECancelReadidentitylistList = ppECancelReadidentitylistService.listByIds(ids);
        if (ppECancelReadidentitylistList != null){
            for (CancelVO cancelVO : cancelVOList) {
                String cancelVOId = cancelVO.getId();
                List<String> list = new ArrayList<>();
                for (PpECancelReadidentitylist ppECancelReadidentitylist : ppECancelReadidentitylistList) {
                    if (cancelVOId.equals(ppECancelReadidentitylist.getCancelXid())){
                        list.add(ppECancelReadidentitylist.getXorderColumn(),ppECancelReadidentitylist.getXreadIdentityList());
                    }
                }
                cancelVO.setReadIdentityList(list);
            }
        }else {
            cancelVOList.forEach(cancelVO -> cancelVO.setReadIdentityList(Collections.emptyList()));
        }

        List<PpECancelReadunitlist> ppECancelReadunitlistList = ppECancelReadunitlistService.listByIds(ids);
        if (ppECancelReadunitlistList != null){
            for (CancelVO cancelVO : cancelVOList) {
                String cancelVOId = cancelVO.getId();
                List<String> list = new ArrayList<>();
                for (PpECancelReadunitlist ppECancelReadunitlist : ppECancelReadunitlistList) {
                    if (cancelVOId.equals(ppECancelReadunitlist.getCancelXid())){
                        list.add(ppECancelReadunitlist.getXorderColumn(),ppECancelReadunitlist.getXreadUnitList());
                    }
                }
                cancelVO.setReadUnitList(list);
            }
        }else {
            cancelVOList.forEach(cancelVO -> cancelVO.setReadUnitList(Collections.emptyList()));
        }

        List<PpECancelReviewdatapathlist> ppECancelReviewdatapathlistList = ppECancelReviewdatapathlistService.listByIds(ids);
        if (ppECancelReviewdatapathlistList != null){
            for (CancelVO cancelVO : cancelVOList) {
                String cancelVOId = cancelVO.getId();
                List<String> list = new ArrayList<>();
                for (PpECancelReviewdatapathlist ppECancelReviewdatapathlist : ppECancelReviewdatapathlistList) {
                    if (cancelVOId.equals(ppECancelReviewdatapathlist.getCancelXid())){
                        list.add(ppECancelReviewdatapathlist.getXorderColumn(),ppECancelReviewdatapathlist.getXreviewDataPathList());
                    }
                }
                cancelVO.setReviewDataPathList(list);
            }
        }else {
            cancelVOList.forEach(cancelVO -> cancelVO.setReviewDataPathList(Collections.emptyList()));
        }

        List<PpECancelReviewgrouplist> ppECancelReviewgrouplistList = ppECancelReviewgrouplistService.listByIds(ids);
        if (ppECancelReviewgrouplistList != null){
            for (CancelVO cancelVO : cancelVOList) {
                String cancelVOId = cancelVO.getId();
                List<String> list = new ArrayList<>();
                for (PpECancelReviewgrouplist ppECancelReviewgrouplist : ppECancelReviewgrouplistList) {
                    if (cancelVOId.equals(ppECancelReviewgrouplist.getCancelXid())){
                        list.add(ppECancelReviewgrouplist.getXorderColumn(),ppECancelReviewgrouplist.getXreviewGroupList());
                    }
                }
                cancelVO.setReviewGroupList(list);
            }
        }else {
            cancelVOList.forEach(cancelVO -> cancelVO.setReviewGroupList(Collections.emptyList()));
        }

        List<PpECancelReviewidentitylist> ppECancelReviewidentitylistList = ppECancelReviewidentitylistService.listByIds(ids);
        if (ppECancelReviewidentitylistList != null){
            for (CancelVO cancelVO : cancelVOList) {
                String cancelVOId = cancelVO.getId();
                List<String> list = new ArrayList<>();
                for (PpECancelReviewidentitylist ppECancelReviewidentitylist : ppECancelReviewidentitylistList) {
                    if (cancelVOId.equals(ppECancelReviewidentitylist.getCancelXid())){
                        list.add(ppECancelReviewidentitylist.getXorderColumn(),ppECancelReviewidentitylist.getXreviewIdentityList());
                    }
                }
                cancelVO.setReviewIdentityList(list);
            }
        }else {
            cancelVOList.forEach(cancelVO -> cancelVO.setReviewIdentityList(Collections.emptyList()));
        }


        List<PpECancelReviewunitlist> ppECancelReviewunitlistList = ppECancelReviewunitlistService.listByIds(ids);
        if (ppECancelReviewunitlistList != null){
            for (CancelVO cancelVO : cancelVOList) {
                String cancelVOId = cancelVO.getId();
                List<String> list = new ArrayList<>();
                for (PpECancelReviewunitlist ppECancelReviewunitlist : ppECancelReviewunitlistList) {
                    if (cancelVOId.equals(ppECancelReviewunitlist.getCancelXid())){
                        list.add(ppECancelReviewunitlist.getXorderColumn(),ppECancelReviewunitlist.getXreviewUnitList());
                    }
                }
                cancelVO.setReviewUnitList(list);
            }
        }else {
            cancelVOList.forEach(cancelVO -> cancelVO.setReviewUnitList(Collections.emptyList()));
        }

        complexVO.setCancelList(cancelVOList);

    }

    @Resource
    private IPpEAgentService ppEAgentService;

    @Resource
    private IPpEAgentReaddatapathlistService ppEAgentReaddatapathlistService;

    @Resource
    private IPpEAgentReadgrouplistService ppEAgentReadgrouplistService;

    @Resource
    private IPpEAgentReadidentitylistService ppEAgentReadidentitylistService;

    @Resource
    private IPpEAgentReadunitlistService ppEAgentReadunitlistService;

    @Resource
    private IPpEAgentReviewdatapathlistService ppEAgentReviewdatapathlistService;

    @Resource
    private IPpEAgentReviewgrouplistService ppEAgentReviewgrouplistService;

    @Resource
    private IPpEAgentReviewidentitylistService ppEAgentReviewidentitylistService;

    @Resource
    private IPpEAgentReviewunitlistService ppEAgentReviewunitlistService;


    private void getAgentInfo(String flag, ComplexVO complexVO) {
        List<PpEAgent> ppEAgentList = ppEAgentService.lambdaQuery().eq(PpEAgent::getXprocess, flag).list();
        //还需要ppEAgentList是否存在，不存在直接返回
        if (ppEAgentList.isEmpty()) {
            complexVO.setAgentList(Collections.emptyList());
            return;
        }
        List<AgentVO> agentVOList = new ArrayList<>();
        for (PpEAgent ppEAgent : ppEAgentList) {
            AgentVO agentVO = BeanUtil.copyProperties(ppEAgent, AgentVO.class);
            //设置属性
            Map<String, Object> properties = JSONUtil.toBean(ppEAgent.getXproperties(), Map.class);
            if (properties != null) {
                agentVO.setProperties(properties);
            } else {
                agentVO.setProperties(Collections.emptyMap());
            }
            agentVOList.add(agentVO);
        }
        List<String> ids = agentVOList.stream().map(AgentVO::getId).collect(Collectors.toList());

        List<PpEAgentReaddatapathlist> ppEAgentReaddatapathlistList = ppEAgentReaddatapathlistService.listByIds(ids);
        if (ppEAgentReaddatapathlistList != null) {
            for (AgentVO agentVO : agentVOList) {
                String agentVOId = agentVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEAgentReaddatapathlist ppEAgentReaddatapathlist : ppEAgentReaddatapathlistList) {
                    if (agentVOId.equals(ppEAgentReaddatapathlist.getAgentXid())) {
                        list.add(ppEAgentReaddatapathlist.getXorderColumn(), ppEAgentReaddatapathlist.getXreadDataPathList());
                    }
                }
                agentVO.setReadDataPathList(list);
            }
        } else {
            agentVOList.forEach(agentVO -> agentVO.setReadDataPathList(Collections.emptyList()));
        }


        List<PpEAgentReadgrouplist> ppEAgentReadgrouplistList = ppEAgentReadgrouplistService.listByIds(ids);
        if (ppEAgentReadgrouplistList != null) {
            for (AgentVO agentVO : agentVOList) {
                String agentVOId = agentVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEAgentReadgrouplist ppEAgentReadgrouplist : ppEAgentReadgrouplistList) {
                    if (agentVOId.equals(ppEAgentReadgrouplist.getAgentXid())) {
                        list.add(ppEAgentReadgrouplist.getXorderColumn(), ppEAgentReadgrouplist.getXreadGroupList());
                    }
                }
                agentVO.setReadGroupList(list);
            }
        } else {
            agentVOList.forEach(agentVO -> agentVO.setReadGroupList(Collections.emptyList()));
        }


        List<PpEAgentReadidentitylist> ppEAgentReadidentitylistList = ppEAgentReadidentitylistService.listByIds(ids);
        if (ppEAgentReadidentitylistList != null) {
            for (AgentVO agentVO : agentVOList) {
                String agentVOId = agentVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEAgentReadidentitylist ppEAgentReadidentitylist : ppEAgentReadidentitylistList) {
                    if (agentVOId.equals(ppEAgentReadidentitylist.getAgentXid())) {
                        list.add(ppEAgentReadidentitylist.getXorderColumn(), ppEAgentReadidentitylist.getXreadIdentityList());
                    }
                }
                agentVO.setReadIdentityList(list);
            }
        } else {
            agentVOList.forEach(agentVO -> agentVO.setReadIdentityList(Collections.emptyList()));
        }

        List<PpEAgentReadunitlist> ppEAgentReadunitlistList = ppEAgentReadunitlistService.listByIds(ids);
        if (ppEAgentReadunitlistList != null) {
            for (AgentVO agentVO : agentVOList) {
                String agentVOId = agentVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEAgentReadunitlist ppEAgentReadunitlist : ppEAgentReadunitlistList) {
                    if (agentVOId.equals(ppEAgentReadunitlist.getAgentXid())) {
                        list.add(ppEAgentReadunitlist.getXorderColumn(), ppEAgentReadunitlist.getXreadUnitList());
                    }
                }
                agentVO.setReadUnitList(list);
            }
        } else {
            agentVOList.forEach(agentVO -> agentVO.setReadUnitList(Collections.emptyList()));
        }

        List<PpEAgentReviewdatapathlist> ppEAgentReviewdatapathlistList = ppEAgentReviewdatapathlistService.listByIds(ids);
        if (ppEAgentReviewdatapathlistList != null) {
            for (AgentVO agentVO : agentVOList) {
                String agentVOId = agentVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEAgentReviewdatapathlist ppEAgentReviewdatapathlist : ppEAgentReviewdatapathlistList) {
                    if (agentVOId.equals(ppEAgentReviewdatapathlist.getAgentXid())) {
                        list.add(ppEAgentReviewdatapathlist.getXorderColumn(), ppEAgentReviewdatapathlist.getXreviewDataPathList());
                    }
                }
                agentVO.setReviewDataPathList(list);
            }
        } else {
            agentVOList.forEach(agentVO -> agentVO.setReviewDataPathList(Collections.emptyList()));
        }

        List<PpEAgentReviewgrouplist> ppEAgentReviewgrouplistList = ppEAgentReviewgrouplistService.listByIds(ids);
        if (ppEAgentReviewgrouplistList != null) {
            for (AgentVO agentVO : agentVOList) {
                String agentVOId = agentVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEAgentReviewgrouplist ppEAgentReviewgrouplist : ppEAgentReviewgrouplistList) {
                    if (agentVOId.equals(ppEAgentReviewgrouplist.getAgentXid())) {
                        list.add(ppEAgentReviewgrouplist.getXorderColumn(), ppEAgentReviewgrouplist.getXreviewGroupList());
                    }
                }
                agentVO.setReviewGroupList(list);
            }
        } else {
            agentVOList.forEach(agentVO -> agentVO.setReviewGroupList(Collections.emptyList()));
        }

        List<PpEAgentReviewunitlist> ppEAgentReviewunitlistList = ppEAgentReviewunitlistService.listByIds(ids);
        if (ppEAgentReviewunitlistList != null) {
            for (AgentVO agentVO : agentVOList) {
                String agentVOId = agentVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEAgentReviewunitlist ppEAgentReviewunitlist : ppEAgentReviewunitlistList) {
                    if (agentVOId.equals(ppEAgentReviewunitlist.getAgentXid())) {
                        list.add(ppEAgentReviewunitlist.getXorderColumn(), ppEAgentReviewunitlist.getXreviewUnitList());
                    }
                }
                agentVO.setReviewUnitList(list);
            }
        } else {
            agentVOList.forEach(agentVO -> agentVO.setReviewUnitList(Collections.emptyList()));
        }


        List<PpEAgentReviewidentitylist> ppEAgentReviewidentitylistList = ppEAgentReviewidentitylistService.listByIds(ids);
        if (ppEAgentReviewidentitylistList != null) {
            for (AgentVO agentVO : agentVOList) {
                String agentVOId = agentVO.getId();
                List<String> list = new ArrayList<>();
                for (PpEAgentReviewidentitylist ppEAgentReviewidentitylist : ppEAgentReviewidentitylistList) {
                    if (agentVOId.equals(ppEAgentReviewidentitylist.getAgentXid())) {
                        list.add(ppEAgentReviewidentitylist.getXorderColumn(), ppEAgentReviewidentitylist.getXreviewIdentityList());
                    }
                }
                agentVO.setReviewIdentityList(list);
            }
        } else {
            agentVOList.forEach(agentVO -> agentVO.setReviewIdentityList(Collections.emptyList()));
        }
        complexVO.setAgentList(agentVOList);
    }


    @Resource
    // 依赖注入流程服务
    private IPpEProcessService ppEProcessService;

    @Resource
    private IPpEProcessControllerlistService ppEProcessControllerlistService;

    @Resource
    private IPpEProcessStartablegrouplistService ppEProcessStartablegrouplistService;

    @Resource
    private IPpEProcessStartableidentitylistService ppEProcessStartableidentitylistService;

    @Resource
    private IPpEProcessStartableunitlistService ppEProcessStartableunitlistService;


    /**
     * 获取流程信息
     *
     * @param flag
     * @param complexVO
     */
    private void getProcessInfo(String flag, ComplexVO complexVO) {

        //完善如何处理异常信息
        //获取流程信息
        PpEProcess process = ppEProcessService.getById(flag);
        if (process == null){
            BizcenterException.cast("流程不存在");
        }

        BeanUtil.copyProperties(process, complexVO);

        //获取流程控制器列表
        List<PpEProcessControllerlist> ppEProcessControllerlistList = ppEProcessControllerlistService.list(new QueryWrapper<PpEProcessControllerlist>().eq("PROCESS_XID", flag));
        if (ppEProcessControllerlistList != null) {
            List<String> list = new ArrayList<>();
            for (PpEProcessControllerlist ppEProcessControllerlist : ppEProcessControllerlistList) {
                list.add(ppEProcessControllerlist.getXorderColumn(), ppEProcessControllerlist.getXcontrollerList());
            }
            complexVO.setControllerList(list);
        } else {
            complexVO.setControllerList(Collections.emptyList());
        }

        //获取流程可启动身份列表
        List<PpEProcessStartablegrouplist> ppEProcessStartablegrouplistList = ppEProcessStartablegrouplistService.list(new QueryWrapper<PpEProcessStartablegrouplist>().eq("PROCESS_XID", flag));
        if (ppEProcessStartablegrouplistList != null) {
            List<String> list = new ArrayList<>();
            for (PpEProcessStartablegrouplist ppEProcessStartablegrouplist : ppEProcessStartablegrouplistList) {
                list.add(ppEProcessStartablegrouplist.getXorderColumn(), ppEProcessStartablegrouplist.getXstartableGroupList());
            }
            complexVO.setStartableGroupList(list);
        } else {
            complexVO.setStartableGroupList(Collections.emptyList());
        }

        //获取流程可启动人员列表
        List<PpEProcessStartableidentitylist> ppEProcessStartableidentitylistList = ppEProcessStartableidentitylistService.list(new QueryWrapper<PpEProcessStartableidentitylist>().eq("PROCESS_XID", flag));
        if (ppEProcessStartableidentitylistList != null) {
            List<String> list = new ArrayList<>();
            for (PpEProcessStartableidentitylist ppEProcessStartableidentitylist : ppEProcessStartableidentitylistList) {
                list.add(ppEProcessStartableidentitylist.getXorderColumn(), ppEProcessStartableidentitylist.getXstartableIdentityList());
            }
            complexVO.setStartableIdentityList(list);
        } else {
            complexVO.setStartableIdentityList(Collections.emptyList());
        }

        //获取流程可启动部门列表
        List<PpEProcessStartableunitlist> ppEProcessStartableunitlistList = ppEProcessStartableunitlistService.list(new QueryWrapper<PpEProcessStartableunitlist>().eq("PROCESS_XID", flag));
        if (ppEProcessStartableunitlistList != null) {
            List<String> list = new ArrayList<>();
            for (PpEProcessStartableunitlist ppEProcessStartableunitlist : ppEProcessStartableunitlistList) {
                list.add(ppEProcessStartableunitlist.getXorderColumn(), ppEProcessStartableunitlist.getXstartableUnitList());
            }
            complexVO.setStartableUnitList(list);
        } else {
            complexVO.setStartableUnitList(Collections.emptyList());
        }


    }


    @Resource
    // 依赖注入流程路由服务
    private IPpERouteService ppERouteService;

    private void getRouteInfo(String flag, ComplexVO complexVO) {
        List<PpERoute> ppERouteList = ppERouteService.lambdaQuery().eq(PpERoute::getXprocess, flag).list();
        List<RouteVO> routeVOList = new ArrayList<>();
        for (PpERoute ppERoute : ppERouteList) {

            RouteVO routeVO = BeanUtil.copyProperties(ppERoute, RouteVO.class);
            //设置属性，将json字符串转换为Map
            Map<String, Object> properties = JSONUtil.toBean(ppERoute.getXproperties(), Map.class);
            if (properties != null) {
                Object value = properties.get("asyncSupported");
                if (value instanceof Boolean) {
                    routeVO.setAsyncSupported((Boolean) value);
                }
                Object value1 = properties.get("soleDirect");
                if (value1 instanceof Boolean) {
                    routeVO.setSoleDirect((Boolean) value1);
                }
                routeVO.setProperties(properties);
            } else {
                routeVO.setProperties(Collections.emptyMap());
                routeVO.setSoleDirect(null);
                routeVO.setAsyncSupported(null);
            }
            routeVOList.add(routeVO);
        }
        complexVO.setRouteList(routeVOList);
    }

    @Resource
    private IPpEManualReviewdatapathlistService ppEManualReviewdatapathlistService;

    @Resource
    private IPpEManualReviewgrouplistService ppEManualReviewgrouplistService;

    @Resource
    private IPpEManualReviewidentitylistService ppEManualReviewidentitylistService;

    @Resource
    private IPpEManualReviewunitlistService ppEManualReviewunitlistService;

    /**
     * 获取人工审核节点信息
     *
     * @param manualVO
     */
    public void getManualReviewInfo(ManualVO manualVO) {

        List<PpEManualReviewdatapathlist> ppEManualReviewdatapathlistList = ppEManualReviewdatapathlistService.list(new QueryWrapper<PpEManualReviewdatapathlist>().eq("MANUAL_XID", manualVO.getId()));
        if (ppEManualReviewdatapathlistList != null) {
            List<String> list = new ArrayList<>();
            for (PpEManualReviewdatapathlist ppEManualReviewdatapathlist : ppEManualReviewdatapathlistList) {
                list.add(ppEManualReviewdatapathlist.getXorderColumn(), ppEManualReviewdatapathlist.getXreviewDataPathList());
            }
            manualVO.setReviewDataPathList(list);
        } else {
            manualVO.setReviewDataPathList(Collections.emptyList());
        }

        List<PpEManualReviewgrouplist> ppEManualReviewgrouplistList = ppEManualReviewgrouplistService.list(new QueryWrapper<PpEManualReviewgrouplist>().eq("MANUAL_XID", manualVO.getId()));
        if (ppEManualReviewgrouplistList != null) {
            List<String> list = new ArrayList<>();
            for (PpEManualReviewgrouplist ppEManualReviewgrouplist : ppEManualReviewgrouplistList) {
                list.add(ppEManualReviewgrouplist.getXorderColumn(), ppEManualReviewgrouplist.getXreviewGroupList());
            }
            manualVO.setReviewGroupList(list);
        } else {
            manualVO.setReviewGroupList(Collections.emptyList());
        }

        List<PpEManualReviewidentitylist> ppEManualReviewidentitylistList = ppEManualReviewidentitylistService.list(new QueryWrapper<PpEManualReviewidentitylist>().eq("MANUAL_XID", manualVO.getId()));
        if (ppEManualReviewidentitylistList != null) {
            List<String> list = new ArrayList<>();
            for (PpEManualReviewidentitylist ppEManualReviewidentitylist : ppEManualReviewidentitylistList) {
                list.add(ppEManualReviewidentitylist.getXorderColumn(), ppEManualReviewidentitylist.getXreviewIdentityList());
            }
            manualVO.setReviewIdentityList(list);
        } else {
            manualVO.setReviewIdentityList(Collections.emptyList());
        }


        List<PpEManualReviewunitlist> ppEManualReviewunitlistList = ppEManualReviewunitlistService.list(new QueryWrapper<PpEManualReviewunitlist>().eq("MANUAL_XID", manualVO.getId()));
        if (ppEManualReviewunitlistList != null) {
            List<String> list = new ArrayList<>();
            for (PpEManualReviewunitlist ppEManualReviewunitlist : ppEManualReviewunitlistList) {
                list.add(ppEManualReviewunitlist.getXorderColumn(), ppEManualReviewunitlist.getXreviewUnitList());
            }
            manualVO.setReviewUnitList(list);
        } else {
            manualVO.setReviewUnitList(Collections.emptyList());
        }


    }


    @Resource
    private IPpEManualReaddatapathlistService ppEManualReaddatapathlistService;

    @Resource
    private IPpEManualReadgrouplistService ppEManualReadgrouplistService;

    @Resource
    private IPpEManualReadidentitylistService ppEManualReadidentitylistService;

    @Resource
    private IPpEManualReadunitlistService ppEManualReadunitlistService;

    /**
     * 获取阅件人信息
     *
     * @param manualVO
     */
    public void getManualReadInfo(ManualVO manualVO) {


        List<PpEManualReaddatapathlist> ppEManualReaddatapathlistList = ppEManualReaddatapathlistService.list(new QueryWrapper<PpEManualReaddatapathlist>().eq("MANUAL_XID", manualVO.getId()));
        if (ppEManualReaddatapathlistList != null) {
            List<String> list = new ArrayList<>();
            for (PpEManualReaddatapathlist ppEManualReaddatapathlist : ppEManualReaddatapathlistList) {
                list.add(ppEManualReaddatapathlist.getXorderColumn(), ppEManualReaddatapathlist.getXreadDataPathList());
            }
            manualVO.setReadDataPathList(list);
        } else {
            manualVO.setReadDataPathList(Collections.emptyList());
        }

        List<PpEManualReadgrouplist> ppEManualReadgrouplistList = ppEManualReadgrouplistService.list(new QueryWrapper<PpEManualReadgrouplist>().eq("MANUAL_XID", manualVO.getId()));
        if (ppEManualReadgrouplistList != null) {
            List<String> list = new ArrayList<>();
            for (PpEManualReadgrouplist ppEManualReadgrouplist : ppEManualReadgrouplistList) {
                list.add(ppEManualReadgrouplist.getXorderColumn(), ppEManualReadgrouplist.getXreadGroupList());
            }
            manualVO.setReadGroupList(list);
        } else {
            manualVO.setReadGroupList(Collections.emptyList());
        }

        List<PpEManualReadidentitylist> ppEManualReadidentitylistList = ppEManualReadidentitylistService.list(new QueryWrapper<PpEManualReadidentitylist>().eq("MANUAL_XID", manualVO.getId()));
        if (ppEManualReadidentitylistList != null) {
            List<String> list = new ArrayList<>();
            for (PpEManualReadidentitylist ppEManualReadidentitylist : ppEManualReadidentitylistList) {
                list.add(ppEManualReadidentitylist.getXorderColumn(), ppEManualReadidentitylist.getXreadIdentityList());
            }
            manualVO.setReadIdentityList(list);
        } else {
            manualVO.setReadIdentityList(Collections.emptyList());
        }

        List<PpEManualReadunitlist> ppEManualReadunitlistList = ppEManualReadunitlistService.list(new QueryWrapper<PpEManualReadunitlist>().eq("MANUAL_XID", manualVO.getId()));
        if (ppEManualReadunitlistList != null) {
            List<String> list = new ArrayList<>();
            for (PpEManualReadunitlist ppEManualReadunitlist : ppEManualReadunitlistList) {
                list.add(ppEManualReadunitlist.getXorderColumn(), ppEManualReadunitlist.getXreadUnitList());
            }
            manualVO.setReadUnitList(list);
        } else {
            manualVO.setReadUnitList(Collections.emptyList());
        }

    }


    @Resource
    private IPpEManualTaskdatapathlistService ppEManualTaskdatapathlistService;

    @Resource
    private IPpEManualTaskgrouplistService ppEManualTaskgrouplistService;

    @Resource
    private IPpEManualTaskidentitylistService ppEManualTaskidentitylistService;

    @Resource
    private IPpEManualTaskunitlistService ppEManualTaskunitlistService;


    public void getManualTaskInfo(ManualVO manualVO) {

        List<PpEManualTaskdatapathlist> ppEManualTaskdatapathlistList = ppEManualTaskdatapathlistService.list(new QueryWrapper<PpEManualTaskdatapathlist>().eq("MANUAL_XID", manualVO.getId()));
        if (ppEManualTaskdatapathlistList != null) {
            List<String> list = new ArrayList<>();
            for (PpEManualTaskdatapathlist ppEManualTaskdatapathlist : ppEManualTaskdatapathlistList) {
                list.add(ppEManualTaskdatapathlist.getXorderColumn(), ppEManualTaskdatapathlist.getXtaskDataPathList());
            }
            manualVO.setTaskDataPathList(list);
        } else {
            manualVO.setTaskDataPathList(Collections.emptyList());
        }

        List<PpEManualTaskgrouplist> ppEManualTaskgrouplistList = ppEManualTaskgrouplistService.list(new QueryWrapper<PpEManualTaskgrouplist>().eq("MANUAL_XID", manualVO.getId()));
        if (ppEManualTaskgrouplistList != null) {
            List<String> list = new ArrayList<>();
            for (PpEManualTaskgrouplist ppEManualTaskgrouplist : ppEManualTaskgrouplistList) {
                list.add(ppEManualTaskgrouplist.getXorderColumn(), ppEManualTaskgrouplist.getXtaskGroupList());
            }
            manualVO.setTaskGroupList(list);
        } else {
            manualVO.setTaskGroupList(Collections.emptyList());
        }


        List<PpEManualTaskidentitylist> ppEManualTaskidentitylistList = ppEManualTaskidentitylistService.list(new QueryWrapper<PpEManualTaskidentitylist>().eq("MANUAL_XID", manualVO.getId()));
        if (ppEManualTaskidentitylistList != null) {
            List<String> list = new ArrayList<>();
            for (PpEManualTaskidentitylist ppEManualTaskidentitylist : ppEManualTaskidentitylistList) {
                list.add(ppEManualTaskidentitylist.getXorderColumn(), ppEManualTaskidentitylist.getXtaskIdentityList());
            }
            manualVO.setTaskIdentityList(list);
        } else {
            manualVO.setTaskIdentityList(Collections.emptyList());
        }

        List<PpEManualTaskunitlist> ppEManualTaskunitlistList = ppEManualTaskunitlistService.list(new QueryWrapper<PpEManualTaskunitlist>().eq("MANUAL_XID", manualVO.getId()));
        if (ppEManualTaskunitlistList != null) {
            List<String> list = new ArrayList<>();
            for (PpEManualTaskunitlist ppEManualTaskunitlist : ppEManualTaskunitlistList) {
                list.add(ppEManualTaskunitlist.getXorderColumn(), ppEManualTaskunitlist.getXtaskUnitList());
            }
            manualVO.setTaskUnitList(list);
        } else {
            manualVO.setTaskUnitList(Collections.emptyList());
        }


    }


    @Resource
    // 依赖注入流程人工节点服务
    private IPpEManualService ppEManualService;
    @Resource
    // 依赖注入流程人工节点路由服务
    private IPpEManualRoutelistService ppEManualRoutelistService;

    private void getManualInfo(String flag, ComplexVO complexVO) {
        //实例化manualVOList
        List<ManualVO> manualVOList = new ArrayList<>();

        //获取人工节点
        List<PpEManual> ppEManualList = ppEManualService.lambdaQuery().eq(PpEManual::getXprocess, flag).list();

        for (PpEManual ppEManual : ppEManualList) {
            ManualVO manualVO = BeanUtil.copyProperties(ppEManual, ManualVO.class);

            //设置属性，将json字符串转换为Map
            Map<String, Object> properties = JSONUtil.toBean(ppEManual.getXproperties(), Map.class);
            if (properties != null) {
                Object value = properties.get("goBackConfig");
                manualVO.setProperties(properties);
                manualVO.setGoBackConfig(value);
            } else {
                manualVO.setProperties(Collections.emptyMap());
            }

            //获取人工活动的读取、审批、任务节点
            getManualReadInfo(manualVO);

            getManualReviewInfo(manualVO);

            getManualTaskInfo(manualVO);


            //设置路由
            //获取manualVOId
            String manualVOId = manualVO.getId();
            //查找数据库pp_e_manual_routelist，获取PpEManualRoutelist集合
            List<PpEManualRoutelist> ppEManualRoutelists = ppEManualRoutelistService.list(
                    new QueryWrapper<PpEManualRoutelist>().eq("MANUAL_XID", manualVOId));
            //将路由添加到routeList中
            List<String> routeList = new ArrayList<>();
            for (PpEManualRoutelist ppEManualRoutelist : ppEManualRoutelists) {
                routeList.add(ppEManualRoutelist.getXorderColumn(), ppEManualRoutelist.getXrouteList());
            }
            manualVO.setRouteList(routeList);
            manualVOList.add(manualVO);


        }


        complexVO.setManualList(manualVOList);
    }


    @Resource
    private IPpEBeginReaddatapathlistService ppEBeginReaddatapathlistService;

    @Resource
    private IPpEBeginReadgrouplistService ppEBeginReadgrouplistService;

    @Resource
    private IPpEBeginReadidentitylistService ppEBeginReadidentitylistService;

    @Resource
    private IPpEBeginReadunitlistService ppEBeginReadunitlistService;

    @Resource
    private IPpEBeginReviewdatapathlistService ppEBeginReviewdatapathlistService;

    @Resource
    private IPpEBeginReviewgrouplistService ppEBeginReviewgrouplistService;

    @Resource
    private IPpEBeginReviewidentitylistService ppEBeginReviewidentitylistService;

    @Resource
    private IPpEBeginReviewunitlistService ppEBeginReviewunitlistService;


    /**
     * 获取开始节点信息
     *
     * @param flag
     * @param complexVO
     */
    private void getBegin(String flag, ComplexVO complexVO) {
        //获取开始节点
        PpEBegin begin = ppEBeginService.lambdaQuery().eq(PpEBegin::getXprocess, flag).one();
        //将开始节点转换为VO
        BeginVO beginVO = BeanUtil.copyProperties(begin, BeginVO.class);

        //获取开始节点的读数据路径
        List<PpEBeginReaddatapathlist> beginReadDataPathLists = ppEBeginReaddatapathlistService.list(new QueryWrapper<PpEBeginReaddatapathlist>().eq("BEGIN_XID", begin.getXid()));
        //判断是否为空
        if (beginReadDataPathLists != null) {
            //实例化
            List<String> list = new ArrayList<>();
            //遍历
            for (PpEBeginReaddatapathlist beginReadDataPathList : beginReadDataPathLists) {
                //根据XorderColumn添加数据
                list.add(beginReadDataPathList.getXorderColumn(), beginReadDataPathList.getXreadDataPathList());
            }
            beginVO.setReadDataPathList(list);
        } else {
            beginVO.setReadDataPathList(Collections.emptyList());
        }

        //获取开始节点的读群组
        List<PpEBeginReadgrouplist> beginReadgrouplistList = ppEBeginReadgrouplistService.list(new QueryWrapper<PpEBeginReadgrouplist>().eq("BEGIN_XID", begin.getXid()));
        if (beginReadgrouplistList != null) {
            List<String> list = new ArrayList<>();
            for (PpEBeginReadgrouplist ppEBeginReadgrouplist : beginReadgrouplistList) {
                list.add(ppEBeginReadgrouplist.getXorderColumn(), ppEBeginReadgrouplist.getXreadGroupList());
            }
            beginVO.setReadGroupList(list);
        } else {
            beginVO.setReadGroupList(Collections.emptyList());
        }

        //获取开始节点的读单位
        List<PpEBeginReadidentitylist> ppEBeginReadidentitylistList = ppEBeginReadidentitylistService.list(new QueryWrapper<PpEBeginReadidentitylist>().eq("BEGIN_XID", begin.getXid()));
        if (ppEBeginReadidentitylistList != null) {
            List<String> list = new ArrayList<>();
            for (PpEBeginReadidentitylist ppEBeginReadidentitylist : ppEBeginReadidentitylistList) {
                list.add(ppEBeginReadidentitylist.getXorderColumn(), ppEBeginReadidentitylist.getXreadIdentityList());
            }
            beginVO.setReadUnitList(list);
        } else {
            beginVO.setReadUnitList(Collections.emptyList());
        }

        //获取开始节点的读身份
        List<PpEBeginReadunitlist> ppEBeginReadunitlistList = ppEBeginReadunitlistService.list(new QueryWrapper<PpEBeginReadunitlist>().eq("BEGIN_XID", begin.getXid()));
        if (ppEBeginReadunitlistList != null) {
            List<String> list = new ArrayList<>();
            for (PpEBeginReadunitlist ppEBeginReadunitlist : ppEBeginReadunitlistList) {
                list.add(ppEBeginReadunitlist.getXorderColumn(), ppEBeginReadunitlist.getXreadUnitList());
            }
            beginVO.setReadUnitList(list);
        } else {
            beginVO.setReadUnitList(Collections.emptyList());
        }


        //获取开始节点的审核数据路径
        List<PpEBeginReviewdatapathlist> ppEBeginReviewdatapathlistList = ppEBeginReviewdatapathlistService.list(new QueryWrapper<PpEBeginReviewdatapathlist>().eq("BEGIN_XID", begin.getXid()));
        if (ppEBeginReviewdatapathlistList != null) {
            List<String> list = new ArrayList<>();
            for (PpEBeginReviewdatapathlist ppEBeginReviewdatapathlist : ppEBeginReviewdatapathlistList) {
                list.add(ppEBeginReviewdatapathlist.getXorderColumn(), ppEBeginReviewdatapathlist.getXreviewDataPathList());
            }
            beginVO.setReviewDataPathList(list);
        } else {
            beginVO.setReviewDataPathList(Collections.emptyList());
        }

        //获取开始节点的审核群组
        List<PpEBeginReviewgrouplist> ppEBeginReviewgrouplistList = ppEBeginReviewgrouplistService.list(new QueryWrapper<PpEBeginReviewgrouplist>().eq("BEGIN_XID", begin.getXid()));
        if (ppEBeginReviewgrouplistList != null) {
            List<String> list = new ArrayList<>();
            for (PpEBeginReviewgrouplist ppEBeginReviewgrouplist : ppEBeginReviewgrouplistList) {
                list.add(ppEBeginReviewgrouplist.getXorderColumn(), ppEBeginReviewgrouplist.getXreviewGroupList());
            }
            beginVO.setReviewGroupList(list);
        } else {
            beginVO.setReviewGroupList(Collections.emptyList());
        }

        //获取开始节点的审核身份
        List<PpEBeginReviewidentitylist> ppEBeginReviewidentitylistList = ppEBeginReviewidentitylistService.list(new QueryWrapper<PpEBeginReviewidentitylist>().eq("BEGIN_XID", begin.getXid()));
        if (ppEBeginReviewidentitylistList != null) {
            List<String> list = new ArrayList<>();
            for (PpEBeginReviewidentitylist ppEBeginReviewidentitylist : ppEBeginReviewidentitylistList) {
                list.add(ppEBeginReviewidentitylist.getXorderColumn(), ppEBeginReviewidentitylist.getXreviewIdentityList());
            }
            beginVO.setReviewIdentityList(list);
        } else {
            beginVO.setReviewIdentityList(Collections.emptyList());
        }

        //获取开始节点的审核单位
        List<PpEBeginReviewunitlist> ppEBeginReviewunitlistList = ppEBeginReviewunitlistService.list(new QueryWrapper<PpEBeginReviewunitlist>().eq("BEGIN_XID", begin.getXid()));
        if (ppEBeginReviewunitlistList != null) {
            List<String> list = new ArrayList<>();
            for (PpEBeginReviewunitlist ppEBeginReviewunitlist : ppEBeginReviewunitlistList) {
                list.add(ppEBeginReviewunitlist.getXorderColumn(), ppEBeginReviewunitlist.getXreviewUnitList());
            }
            beginVO.setReviewUnitList(list);
        } else {
            beginVO.setReviewUnitList(Collections.emptyList());
        }

        //设置开始节点
        complexVO.setBegin(beginVO);


    }


    @Resource
    private IPpEEndReaddatapathlistService ppEEndReaddatapathlistService;

    @Resource
    private IPpEEndReadgrouplistService ppEEndReadgrouplistService;

    @Resource
    private IPpEEndReadidentitylistService ppEEndReadidentitylistService;

    @Resource
    private IPpEEndReadunitlistService ppEEndReadunitlistService;

    @Resource
    private IPpEEndReviewdatapathlistService ppEEndReviewdatapathlistService;

    @Resource
    private IPpEEndReviewgrouplistService ppEEndReviewgrouplistService;

    @Resource
    private IPpEEndReviewidentitylistService ppEEndReviewidentitylistService;

    @Resource
    private IPpEEndReviewunitlistService ppEEndReviewunitlistService;


    /**
     * 获取结束节点
     *
     * @param flag
     * @param complexVO
     */
    public void getEndList(String flag, ComplexVO complexVO) {
        //获取结束节点
        List<PpEEnd> list = ppEEndService.lambdaQuery().eq(PpEEnd::getXprocess, flag).list();
        List<EndVO> endVOList = new ArrayList<>();
        for (PpEEnd ppEEnd : list) {
            EndVO endVO = BeanUtil.copyProperties(ppEEnd, EndVO.class);
            endVOList.add(endVO);
        }
        List<String> ids = endVOList.stream().map(EndVO::getId).collect(Collectors.toList());

        //获取结束节点的读数据路径
        List<PpEEndReaddatapathlist> ppEEndReaddatapathlistList = ppEEndReaddatapathlistService.listByIds(ids);
        if (ppEEndReaddatapathlistList != null) {
            for (EndVO endVO : endVOList) {
                List<String> valusList = new ArrayList<>();
                String endVOId = endVO.getId();
                for (PpEEndReaddatapathlist ppEEndReaddatapathlist : ppEEndReaddatapathlistList) {
                    if (endVOId.equals(ppEEndReaddatapathlist.getEndXid())) {
                        valusList.add(ppEEndReaddatapathlist.getXorderColumn(), ppEEndReaddatapathlist.getXreadDataPathList());
                    }
                }
                endVO.setReadDataPathList(valusList);
            }
        } else {
            endVOList.forEach(endVO -> endVO.setReadDataPathList(Collections.emptyList()));
        }

        //获取结束节点的读群组
        List<PpEEndReadgrouplist> ppEEndReadgrouplistList = ppEEndReadgrouplistService.listByIds(ids);
        if (ppEEndReadgrouplistList != null) {
            for (EndVO endVO : endVOList) {
                List<String> valusList = new ArrayList<>();
                String endVOId = endVO.getId();
                for (PpEEndReadgrouplist ppEEndReadgrouplist : ppEEndReadgrouplistList) {
                    if (endVOId.equals(ppEEndReadgrouplist.getEndXid())) {
                        valusList.add(ppEEndReadgrouplist.getXorderColumn(), ppEEndReadgrouplist.getXreadGroupList());
                    }
                }
                endVO.setReadGroupList(valusList);
            }
        } else {
            endVOList.forEach(endVO -> endVO.setReadGroupList(Collections.emptyList()));
        }

        //获取结束节点的读身份
        List<PpEEndReadidentitylist> ppEEndReadidentitylistList = ppEEndReadidentitylistService.listByIds(ids);
        if (ppEEndReadidentitylistList != null) {
            for (EndVO endVO : endVOList) {
                List<String> valusList = new ArrayList<>();
                String endVOId = endVO.getId();
                for (PpEEndReadidentitylist ppEEndReadidentitylist : ppEEndReadidentitylistList) {
                    if (endVOId.equals(ppEEndReadidentitylist.getEndXid())) {
                        valusList.add(ppEEndReadidentitylist.getXorderColumn(), ppEEndReadidentitylist.getXreadIdentityList());
                    }
                }
                endVO.setReadIdentityList(valusList);
            }
        } else {
            endVOList.forEach(endVO -> endVO.setReadIdentityList(Collections.emptyList()));
        }

        //获取结束节点的读单位
        List<PpEEndReadunitlist> ppEEndReadunitlistList = ppEEndReadunitlistService.listByIds(ids);
        if (ppEEndReadunitlistList != null) {
            for (EndVO endVO : endVOList) {
                List<String> valusList = new ArrayList<>();
                String endVOId = endVO.getId();
                for (PpEEndReadunitlist ppEEndReadunitlist : ppEEndReadunitlistList) {
                    if (endVOId.equals(ppEEndReadunitlist.getEndXid())) {
                        valusList.add(ppEEndReadunitlist.getXorderColumn(), ppEEndReadunitlist.getXreadUnitList());
                    }
                }
                endVO.setReadUnitList(valusList);
            }
        } else {
            endVOList.forEach(endVO -> endVO.setReadUnitList(Collections.emptyList()));
        }

        //获取结束节点的审核数据路径
        List<PpEEndReviewdatapathlist> ppEEndReviewdatapathlistList = ppEEndReviewdatapathlistService.listByIds(ids);
        if (ppEEndReviewdatapathlistList != null) {
            for (EndVO endVO : endVOList) {
                List<String> valusList = new ArrayList<>();
                String endVOId = endVO.getId();
                for (PpEEndReviewdatapathlist ppEEndReviewdatapathlist : ppEEndReviewdatapathlistList) {
                    if (endVOId.equals(ppEEndReviewdatapathlist.getEndXid())) {
                        valusList.add(ppEEndReviewdatapathlist.getXorderColumn(), ppEEndReviewdatapathlist.getXreviewDataPathList());
                    }
                }
                endVO.setReviewDataPathList(valusList);
            }
        } else {
            endVOList.forEach(endVO -> endVO.setReviewDataPathList(Collections.emptyList()));
        }

        //获取结束节点的审核身份
        List<PpEEndReviewgrouplist> ppEEndReviewgrouplistList = ppEEndReviewgrouplistService.listByIds(ids);
        if (ppEEndReviewgrouplistList != null) {
            for (EndVO endVO : endVOList) {
                List<String> valusList = new ArrayList<>();
                String endVOId = endVO.getId();
                for (PpEEndReviewgrouplist ppEEndReviewgrouplist : ppEEndReviewgrouplistList) {
                    if (endVOId.equals(ppEEndReviewgrouplist.getEndXid())) {
                        valusList.add(ppEEndReviewgrouplist.getXorderColumn(), ppEEndReviewgrouplist.getXreviewGroupList());
                    }
                }
                endVO.setReviewGroupList(valusList);
            }
        } else {
            endVOList.forEach(endVO -> endVO.setReviewGroupList(Collections.emptyList()));
        }

        //获取结束节点的审核身份
        List<PpEEndReviewidentitylist> ppEEndReviewidentitylistList = ppEEndReviewidentitylistService.listByIds(ids);
        if (ppEEndReviewidentitylistList != null) {
            for (EndVO endVO : endVOList) {
                List<String> valusList = new ArrayList<>();
                String endVOId = endVO.getId();
                for (PpEEndReviewidentitylist ppEEndReviewidentitylist : ppEEndReviewidentitylistList) {
                    if (endVOId.equals(ppEEndReviewidentitylist.getEndXid())) {
                        valusList.add(ppEEndReviewidentitylist.getXorderColumn(), ppEEndReviewidentitylist.getXreviewIdentityList());
                    }
                }
                endVO.setReviewIdentityList(valusList);
            }
        } else {
            endVOList.forEach(endVO -> endVO.setReviewIdentityList(Collections.emptyList()));
        }


        //获取结束节点的审核单位
        List<PpEEndReviewunitlist> ppEEndReviewunitlistList = ppEEndReviewunitlistService.listByIds(ids);
        if (ppEEndReviewunitlistList != null) {
            for (EndVO endVO : endVOList) {
                List<String> valusList = new ArrayList<>();
                String endVOId = endVO.getId();
                for (PpEEndReviewunitlist ppEEndReviewunitlist : ppEEndReviewunitlistList) {
                    if (endVOId.equals(ppEEndReviewunitlist.getEndXid())) {
                        valusList.add(ppEEndReviewunitlist.getXorderColumn(), ppEEndReviewunitlist.getXreviewUnitList());
                    }
                }
                endVO.setReviewUnitList(valusList);
            }
        } else {
            endVOList.forEach(endVO -> endVO.setReviewUnitList(Collections.emptyList()));
        }

        complexVO.setEndList(endVOList);

    }


}
