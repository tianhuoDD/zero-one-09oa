package com.zeroone.star.bizcenter.service.impl;

import cn.hutool.core.bean.BeanUtil;
import cn.hutool.json.JSONObject;
import cn.hutool.json.JSONUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;

import com.zeroone.star.bizcenter.entity.*;
import com.zeroone.star.bizcenter.exception.BizcenterException;

import com.zeroone.star.bizcenter.service.*;
import com.zeroone.star.project.dto.j5.bizcenter.PrecessingDTO;
import com.zeroone.star.project.dto.j5.bizcenter.ReplaceDTO;
import com.zeroone.star.project.dto.j5.bizcenter.RerouteDTO;
import com.zeroone.star.project.dto.j5.bizcenter.RollbackDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j5.bizcenter.*;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.Resource;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.time.temporal.ChronoUnit;
import java.util.*;
import java.util.stream.Collectors;

@Service
public class UpdatePrecessServiceImpl implements UpdatePrecessService {


    /**
     * 回溯
     *
     * @param workCompletedId
     * @param rollbackDTO
     * @return
     */
    @Override
    @Transactional
    public RollbackVO rollBack(String workCompletedId, RollbackDTO rollbackDTO) {
        //获取工作日志
        PpCWorklog ppCWorklog = ppCWorklogService.getById(rollbackDTO.getWorkLog());

        PpCWorkcompleted ppCWorkcompleted = ppCWorkcompletedService.getById(workCompletedId);
        ppCWorkcompletedService.removeById(ppCWorkcompleted);

        PpCTaskcompleted ppCTaskcompleted = ppCTaskcompletedService.lambdaQuery().eq(PpCTaskcompleted::getXworkCompleted, ppCWorkcompleted.getXid()).one();
        ppCTaskcompletedService.lambdaUpdate().eq(PpCTaskcompleted::getXworkCompleted, ppCWorkcompleted.getXid()).remove();

        PpCWork ppCWork = BeanUtil.copyProperties(ppCWorkcompleted, PpCWork.class);

        ppCWork.setXid(ppCWorkcompleted.getXwork());
        ppCWork.setXupdateTime(LocalDateTime.now());
        ppCWork.setXactivity(ppCWorklog.getXfromActivity());
        ppCWork.setXactivityName(ppCWorklog.getXfromActivityName());
        ppCWork.setXactivityAlias(ppCWorklog.getXfromActivityAlias());
        ppCWork.setXactivityType(ppCWorklog.getXfromActivityType());
        ppCWork.setXactivityArrivedTime(ppCWorklog.getXarrivedTime());
        ppCWork.setXactivityToken(ppCWorklog.getXfromActivityToken());
        ppCWork.setXworkCreateType("assign");
        ppCWork.setXworkStatus("processing");
        ppCWork.setXsplitting(false);

        ppCWorkService.save(ppCWork);


        String xrouteName = ppCWorklog.getXrouteName();
        String xarrivedActivity = ppCWorklog.getXarrivedActivity();
        //删除多余的工作日志
        if (!"结束".equals(xrouteName)) {
            //删除后续人工活动日志
            PpCWorklog ppCWorklog1 = ppCWorklog;
            while (ppCWorklogService.lambdaUpdate()
                    .eq(PpCWorklog::getXwork, ppCWork.getXid())
                    .eq(PpCWorklog::getXfromActivity, xarrivedActivity)
                    .remove()){

                xarrivedActivity = ppCWorklog1.getXarrivedActivity();
                ppCWorklog1 = ppCWorklogService.lambdaQuery()
                        .eq(PpCWorklog::getXfromActivity, xarrivedActivity)
                        .eq(PpCWorklog::getXwork, ppCWork.getXid())
                        .one();
            }
        }else {
            ppCWorklogService.lambdaUpdate()
                    .eq(PpCWorklog::getXwork, ppCWork.getXid())
                    .eq(PpCWorklog::getXid, rollbackDTO.getWorkLog())
                    .set(PpCWorklog::getXarrivedActivity,"")
                    .set(PpCWorklog::getXarrivedActivityAlias,"")
                    .set(PpCWorklog::getXarrivedActivityName,"")
                    .set(PpCWorklog::getXarrivedActivityToken,"")
                    .set(PpCWorklog::getXarrivedActivityType,null)
                    .set(PpCWorklog::getXarrivedGroup,null)
                    .set(PpCWorklog::getXarrivedOpinionGroup,null)
                    .set(PpCWorklog::getXarrivedTime,null)
                    .set(PpCWorklog::getXcompleted,false)
                    .set(PpCWorklog::getXconnected,false)
                    .update();
        }
        //统一初始化
        ppCWorklogService.lambdaUpdate()
                .eq(PpCWorklog::getXwork, ppCWork.getXid())
                .set(PpCWorklog::getXcompleted,false)
                .set(PpCWorklog::getXworkCompleted,"")
                .update();
        PpCTask ppCTask = BeanUtil.copyProperties(ppCTaskcompleted, PpCTask.class);
        //向task表插入任务数据
        for (String distinguished : rollbackDTO.getDistinguishedNameList()) {

            ppCTask.setXid(UUID.randomUUID().toString());
            ppCTask.setXcreateTime(LocalDateTime.now());
            ppCTask.setXsequence(LocalDateTime.now().format(DateTimeFormatter.ofPattern("yyyyMMddHHmmss")) + ppCTask.getXid());
            ppCTask.setXupdateTime(LocalDateTime.now());
            ppCTask.setXactivity(ppCWork.getXactivity());
            ppCTask.setXactivityName(ppCWork.getXactivityName());
            ppCTask.setXactivityType(ppCWork.getXactivityType());
            ppCTask.setXactivityAlias(ppCWork.getXactivityAlias());
            ppCTask.setXactivityToken(ppCWork.getXactivityToken());
            ppCTask.setXallowRapid(false);
            ppCTask.setXexpired(false);
            ppCTask.setXfirst(true);
            ppCTask.setXmodified(false);
            ppCTask.setXurged(false);
            ppCTask.setXworkCreateType(ppCWork.getXworkCreateType());

            ppCTask.setXperson(distinguished);
            ppCTask.setXunit(distinguished);
            ppCTaskService.save(ppCTask);

        }


        PpCRecord ppCRecord = BeanUtil.copyProperties(ppCWorklog, PpCRecord.class);
        //设置属性
        Map<String, Object> map = new HashMap<>();
        map.put("unitLevelOrderNumber", "");
        map.put("unitLevelName", "");
        map.put("unitDutyList", Collections.emptyList());
        List<ActivityVO> activityVOS = new ArrayList<>();
        ActivityVO activityVO = new ActivityVO();
        activityVO.setActivity(ppCWork.getXactivity());
        activityVO.setActivityType(ppCWork.getXactivityType());
        activityVO.setActivityName(ppCWork.getXactivityName());
        activityVO.setActivityAlias(ppCWork.getXactivityAlias());
        activityVO.setActivityToken(ppCWork.getXactivityToken());
        activityVO.setTaskIdentityList(rollbackDTO.getDistinguishedNameList());
        activityVOS.add(activityVO);
        map.put("nextManualList", activityVOS);
        map.put("nextManualTaskIdentityList", rollbackDTO.getDistinguishedNameList());
        map.put("opinion", rollbackDTO.getOpinion());
        map.put("routeName", "");
        map.put("startTime", LocalDateTime.now());
        map.put("elapsed", ppCWorklog.getXduration());
        map.put("fromGroup", ppCWorklog.getXfromGroup());
        map.put("fromOpinionGroup", ppCWorklog.getXfromOpinionGroup());
        String jsonStr1 = JSONUtil.toJsonStr(map);
        ppCRecord.setXproperties(jsonStr1);
        ppCRecord.setXrecordTime(LocalDateTime.now());
        ppCRecord.setXtype("reroute");
        ppCRecord.setXunit(rollbackDTO.getDistinguishedNameList().get(0));
        ppCRecordService.save(ppCRecord);

        RollbackVO rollbackVO = BeanUtil.copyProperties(ppCRecord, RollbackVO.class);
        rollbackVO.setRouteName("");
        rollbackVO.setOpinion(rollbackDTO.getOpinion());
        rollbackVO.setNextManualList(null);
        rollbackVO.setNextManualTaskIdentityList(rollbackDTO.getDistinguishedNameList());
        rollbackVO.setStartTime(LocalDateTime.now());


        return rollbackVO;
    }


    /**
     * 管理员调度
     *
     * @param workId
     * @param rerouteDTO
     * @return
     */
    @Override
    @Transactional
    public RerouteVO reroute(String workId, RerouteDTO rerouteDTO) {

        PpCWork ppCWork = ppCWorkService.getById(workId);
        if (ppCWork == null) {
            throw new BizcenterException("未找到对应的工作");
        }
        //获取调度前的任务信息
        PpCTask ppCTask_Source = ppCTaskService.lambdaQuery().eq(PpCTask::getXwork, workId).one();
        if (ppCTask_Source == null) {
            throw new BizcenterException("未找到对应的任务记录");
        }
        String ppCTaskXid = ppCTask_Source.getXid();
        ppCTaskService.removeById(ppCTaskXid);

        PpCTask ppCTask = BeanUtil.copyProperties(ppCTask_Source, PpCTask.class);
        PpCReview ppCReview = BeanUtil.copyProperties(ppCTask_Source, PpCReview.class);

        //查询人工活动名称
        PpEManual ppEManual = ppEManualService.lambdaQuery().eq(PpEManual::getXid, rerouteDTO.getActivity()).one();
        ppCTask.setXactivityName(ppEManual.getXname());
        ppCTask.setXactivityToken(UUID.randomUUID().toString());
        PpERoute ppERoute = ppERouteService.lambdaQuery().eq(PpERoute::getXactivity, rerouteDTO.getActivity()).one();


        String xproperties = ppCTask.getXproperties();
        Map<String, Object> properties = JSONUtil.toBean(xproperties, Map.class);
        Object prevTaskIdentity = properties.get("prevTaskIdentity");
        if (prevTaskIdentity instanceof String) {
            properties.put("prevTaskIdentity", ppCTask.getXperson());
        }
        String jsonStr = JSONUtil.toJsonStr(properties);
        ppCTask.setXproperties(jsonStr);

        //向worklog添加数据
        //获取上次的工作日志
        PpCWorklog ppCWorklog = ppCWorklogService.lambdaQuery().eq(PpCWorklog::getXfromActivityName, ppCTask_Source.getXactivityName()).eq(PpCWorklog::getXwork, workId).one();

        //有多个处理人
        for (String DistinguishedName : rerouteDTO.getDistinguishedNameList()) {
            //新增任务
            ppCTask.setXid(UUID.randomUUID().toString());
            ppCTask.setXcreateTime(LocalDateTime.now());
            ppCTask.setXsequence(LocalDateTime.now().format(DateTimeFormatter.ofPattern("yyyyMMddHHmmss")) + ppCTask.getXid());
            ppCTask.setXupdateTime(LocalDateTime.now());
            ppCTask.setXactivity(rerouteDTO.getActivity());
            ppCTask.setXactivityType(rerouteDTO.getActivityType());
            ppCTask.setXdistinguishedName(DistinguishedName);
            ppCTask.setXidentity(DistinguishedName);
            ppCTask.setXperson(DistinguishedName);
            ppCTask.setXstartTime(LocalDateTime.now());
            ppCTask.setXstartTimeMonth(LocalDateTime.now().format(DateTimeFormatter.ofPattern("yyyy-MM")));
            ppCTask.setXactivityToken(UUID.randomUUID().toString());
            ppCTaskService.save(ppCTask);
            //新增review
            ppCReview.setXid(UUID.randomUUID().toString());
            ppCReview.setXcreateTime(LocalDateTime.now());
            ppCReview.setXsequence(LocalDateTime.now().format(DateTimeFormatter.ofPattern("yyyyMMddHHmmss")) + ppCReview.getXid());
            ppCReview.setXupdateTime(LocalDateTime.now());
            ppCReview.setXcompleted(false);
            ppCReview.setXpermissionWrite(false);
            Map<String, Object> map = new HashMap<>();
            map.put("title", ppCReview.getXtitle());
            String jsonStr1 = JSONUtil.toJsonStr(map);
            ppCReview.setXproperties(jsonStr1);
            ppCReviewService.save(ppCReview);


        }

        //修改work表数据
        ppCWork.setXupdateTime(LocalDateTime.now());
        ppCWork.setXactivity(rerouteDTO.getActivity());
        ppCWork.setXactivityName(ppEManual.getXname());
        ppCWork.setXactivityArrivedTime(LocalDateTime.now());
        ppCWork.setXdestinationRoute(ppERoute.getXid());
        ppCWork.setXdestinationRouteName(ppERoute.getXname());
        ppCWorkService.updateById(ppCWork);
        //修改worklog表数据
        ppCWorklog.setXupdateTime(LocalDateTime.now());
        ppCWorklog.setXarrivedActivity(ppEManual.getXid());
        ppCWorklog.setXarrivedActivityName(ppEManual.getXname());
        ppCWorklog.setXarrivedActivityToken(ppCTask.getXactivityToken());
        ppCWorklog.setXarrivedActivityType(ppCTask.getXactivityType());
        //计算时间戳
        LocalDateTime xupdateTime = ppCWorklog.getXupdateTime();
        LocalDateTime xcreateTime = ppCWorklog.getXcreateTime();
        long timestamp = ChronoUnit.MILLIS.between(xcreateTime, xupdateTime);

        ppCWorklog.setXduration(timestamp);
        ppCWorklog.setXroute(ppERoute.getXid());
        ppCWorklog.setXrouteName(ppERoute.getXname());
        ppCWorklog.setXtype("reroute");
        ppCWorklogService.updateById(ppCWorklog);

        //添加下一条工作日志
        PpCWorklog nextPpCWorklog = PpCWorklog.builder()
                .xid(UUID.randomUUID().toString())
                .xcreateTime(LocalDateTime.now())
                .xsequence(LocalDateTime.now().format(DateTimeFormatter.ofPattern("yyyyMMddHHmmss")) + ppCWorklog.getXid())
                .xupdateTime(LocalDateTime.now())
                .xapplication(ppCWorklog.getXapplication())
                .xapplicationAlias(ppCWorklog.getXapplicationAlias())
                .xapplicationName(ppCWorklog.getXapplicationName())
                .xcompleted(Boolean.FALSE)
                .xconnected(Boolean.FALSE)
                .xfromActivity(ppCWorklog.getXarrivedActivity())
                .xfromActivityAlias(ppCWorklog.getXarrivedActivityAlias())
                .xfromActivityName(ppCWorklog.getXarrivedActivityName())
                .xfromActivityToken(ppCWorklog.getXarrivedActivityToken())
                .xfromActivityType(ppCWorklog.getXarrivedActivityType())
                .xfromGroup(ppCWorklog.getXarrivedGroup())
                .xfromOpinionGroup(ppCWorklog.getXarrivedOpinionGroup())
                .xfromTime(LocalDateTime.now())
                .xjob(ppCWorklog.getXjob())
                .xprocess(ppCWorklog.getXprocess())
                .xprocessAlias(ppCWorklog.getXprocessAlias())
                .xproperties(ppCWorklog.getXproperties())
                .xsplitting(Boolean.FALSE)
                .xwork(workId).build();
        ppCWorklogService.save(nextPpCWorklog);

        //添加记录
        PpCRecord ppCRecord = BeanUtil.copyProperties(ppCWorklog, PpCRecord.class);
        ppCRecord.setXid(UUID.randomUUID().toString());
        ppCRecord.setXcreateTime(LocalDateTime.now());
        ppCRecord.setXsequence(LocalDateTime.now().format(DateTimeFormatter.ofPattern("yyyyMMddHHmmss")) + ppCRecord.getXid());
        ppCRecord.setXupdateTime(LocalDateTime.now());
        ppCRecord.setXdisplay(true);
        ppCRecord.setXidentity(ppCTask_Source.getXidentity());
        ppCRecord.setXorder(System.currentTimeMillis());
        ppCRecord.setXperson(ppCTask_Source.getXperson());
        //设置属性
        Map<String, Object> map = new HashMap<>();
        map.put("unitLevelOrderNumber", "");
        map.put("unitLevelName", "");
        map.put("unitDutyList", Collections.emptyList());
        List<ActivityVO> activityVOS = new ArrayList<>();
        ActivityVO activityVO = new ActivityVO();
        activityVO.setActivity(rerouteDTO.getActivity());
        activityVO.setActivityType(rerouteDTO.getActivityType());
        activityVO.setActivityName(ppCTask.getXactivityName());
        activityVO.setActivityAlias(ppCTask.getXactivityAlias());
        activityVO.setActivityToken(ppCTask.getXactivityToken());
        activityVO.setTaskIdentityList(rerouteDTO.getDistinguishedNameList());
        activityVOS.add(activityVO);
        map.put("nextManualList", activityVOS);
        map.put("nextManualTaskIdentityList", rerouteDTO.getDistinguishedNameList());
        map.put("opinion", rerouteDTO.getOpinion());
        map.put("routeName", rerouteDTO.getRouteName());
        map.put("startTime", LocalDateTime.now());
        map.put("elapsed", ppCWorklog.getXduration());
        map.put("fromGroup", ppCWorklog.getXfromGroup());
        map.put("fromOpinionGroup", ppCWorklog.getXfromOpinionGroup());
        String jsonStr1 = JSONUtil.toJsonStr(map);
        ppCRecord.setXproperties(jsonStr1);
        ppCRecord.setXrecordTime(LocalDateTime.now());
        ppCRecord.setXtype("reroute");
        ppCRecord.setXunit(ppCTask_Source.getXunit());
        ppCRecordService.save(ppCRecord);

        //返回数据
        RerouteVO rerouteVO = BeanUtil.copyProperties(ppCRecord, RerouteVO.class);
        rerouteVO.setRouteName(rerouteDTO.getRouteName());
        rerouteVO.setOpinion(rerouteDTO.getOpinion());
        rerouteVO.setNextManualList(activityVOS);
        rerouteVO.setNextManualTaskIdentityList(rerouteDTO.getDistinguishedNameList());
        rerouteVO.setStartTime(LocalDateTime.now());

        return rerouteVO;
    }


    @Resource
    private IPpCReviewService ppCReviewService;

    @Resource
    private IPpCTaskService ppCTaskService;

    @Resource
    private IPpCTaskcompletedService ppCTaskcompletedService;

    @Resource
    private IPpCWorkService ppCWorkService;

    @Resource
    private IQryItemService qryItemService;

    @Resource
    private IPpCReadService ppCReadService;

    @Resource
    private IPpCReadcompletedService ppCReadcompletedService;

    @Resource
    private IPpCAttachmentService ppCAttachmentService;

    @Resource
    private IPpCRecordService ppCRecordService;

    @Resource
    private IPpCWorklogService ppCWorklogService;


    /**
     * 修改工作业务数据
     *
     * @param id
     * @param params
     */
    @Override
    @Transactional
    public void updateWorkData(String id, Map<String, Object> params) {
        //1.先查询当前工作的信息
        PpCWork ppCWork = ppCWorkService.getById(id);
        if (ppCWork == null) {
            throw new BizcenterException("未找到对应的工作");
        }
        if (params == null || params.isEmpty()) {
            return;
        }
        ppCWork.setXdataChanged(true);
        //当修改标题时（subject），需要执行
        if (params.get("subject") != null) {
            //修改pp_c_work表
            Map<String, Object> workProperties = JSONUtil.toBean(ppCWork.getXproperties(), Map.class);
            workProperties.put("title", params.get("subject"));
            String updateWorkProperties = JSONUtil.toJsonStr(workProperties);

            ppCWork.setXproperties(updateWorkProperties);
            ppCWork.setXupdateTime(LocalDateTime.now());
            ppCWork.setXtitle(params.get("subject").toString());
            ppCWorkService.updateById(ppCWork);

            //修改pp_c_review表
            PpCReview ppCReview = ppCReviewService.lambdaQuery().eq(PpCReview::getXwork, id).one();
            if (ppCReview == null) {
                throw new BizcenterException("未找到对应的审核记录");
            }
            String xproperties = ppCReview.getXproperties();
            Map<String, Object> properties = JSONUtil.toBean(xproperties, Map.class);
            properties.put("title", params.get("subject"));
            String updateProperties = JSONUtil.toJsonStr(properties);
            //重新设置数据
            ppCReview.setXtitle(params.get("subject").toString());
            ppCReview.setXproperties(updateProperties);
            ppCReview.setXupdateTime(LocalDateTime.now());
            //修改数据
            ppCReviewService.updateById(ppCReview);

            //修改pp_c_task表
            PpCTask ppCTask = ppCTaskService.lambdaQuery().eq(PpCTask::getXwork, id).one();
            if (ppCTask == null) {
                throw new BizcenterException("未找到对应的任务记录");
            }
            Map<String, Object> taskProperties = JSONUtil.toBean(ppCTask.getXproperties(), Map.class);
            taskProperties.put("title", params.get("subject"));
            String updateTaskProperties = JSONUtil.toJsonStr(taskProperties);
            //设置数据
            ppCTask.setXproperties(updateTaskProperties);
            ppCTask.setXtitle(params.get("subject").toString());
            ppCTask.setXupdateTime(LocalDateTime.now());
            ppCTaskService.updateById(ppCTask);


            //修改pp_c_taskcompleted表
            //先判断当前表是否有数据
            PpCTaskcompleted ppCTaskcompleted = ppCTaskcompletedService.lambdaQuery().eq(PpCTaskcompleted::getXwork, id).one();
            if (ppCTaskcompleted != null) {
                Map<String, Object> taskCompletedProperties = JSONUtil.toBean(ppCTaskcompleted.getXproperties(), Map.class);
                taskCompletedProperties.put("title", params.get("subject"));
                String updateTaskCompletedProperties = JSONUtil.toJsonStr(taskCompletedProperties);

                ppCTaskcompleted.setXproperties(updateTaskCompletedProperties);
                ppCTaskcompleted.setXtitle(params.get("subject").toString());
                ppCTaskcompleted.setXupdateTime(LocalDateTime.now());
                ppCTaskcompletedService.updateById(ppCTaskcompleted);
            }
            qryItemService.lambdaUpdate().eq(QryItem::getXbundle, ppCWork.getXjob()).eq(QryItem::getXitemCategory, "pp").eq(QryItem::getXpath0, "$work").set(QryItem::getXstringShortValue, params.get("subject")).set(QryItem::getXupdateTime, LocalDateTime.now()).update();
        }

        //获取表单对应的数据
        // 思考如何修改表单数据
        //修改单项数据
        List<String> xpathStringList = new ArrayList<>();
        List<QryItem> qryItemList = new ArrayList<>();
        params.forEach((k, v) -> {
            if (v instanceof String) {
                xpathStringList.add(k);
            }
        });
        List<QryItem> qryItemStringList = qryItemService.lambdaQuery().in(QryItem::getXpath0, xpathStringList).eq(QryItem::getXbundle, ppCWork.getXjob()).eq(QryItem::getXitemCategory, "pp").list();
        if (qryItemStringList.isEmpty()) {
            params.forEach((k, v) -> {
                if (v instanceof String) {
                    String uuId = UUID.randomUUID().toString();
                    QryItem qryItem = QryItem.builder().xid(uuId)
                            .xcreateTime(LocalDateTime.now())
                            .xsequence(LocalDateTime.now().format(DateTimeFormatter.ofPattern("yyyyMMddHHmmss")) + uuId)
                            .xupdateTime(LocalDateTime.now())
                            .xbundle(ppCWork.getXjob())
                            .xitemCategory("pp")
                            .xitemPrimitiveType("s")
                            .xitemStringValueType("s")
                            .xitemType("p")
                            .xpath0(k)
                            .xpath0Location(-1)
                            .xpath1(String.valueOf(-1))
                            .xpath1Location(0)
                            .xpath2(k)
                            .xpath2Location(-1)
                            .xpath3(String.valueOf(-1))
                            .xpath3Location(-1)
                            .xpath4(String.valueOf(-1))
                            .xpath4Location(-1)
                            .xpath5(String.valueOf(-1))
                            .xpath5Location(-1)
                            .xpath6(String.valueOf(-1))
                            .xpath6Location(-1)
                            .xpath7(String.valueOf(-1))
                            .xpath7Location(-1)
                            .xstringShortValue(String.valueOf(v))
                            .build();
                    qryItemList.add(qryItem);
                    params.remove(k);
                }

            });
        } else {
            for (QryItem qryItem : qryItemStringList) {
                params.forEach((k, v) -> {
                    if (qryItem.getXpath0().equals(k)) {
                        if ("Time".contains(qryItem.getXpath0())) {
                            qryItem.setXdateTimeValue((LocalDateTime) v);
                        }
                        if (v instanceof String) {
                            qryItem.setXstringShortValue((String) v);
                        }
                        qryItem.setXupdateTime(LocalDateTime.now());
                        qryItemService.updateById(qryItem);
                        params.remove(k);
                    }
                });
            }
        }
        //清空集合
//        qryItemList.clear();
        //修改集合数据
        params.forEach((k, v) -> {
            if (v instanceof List) {
                //修改集合数据
                //1.先删除原有的数据
                qryItemService.lambdaUpdate().eq(QryItem::getXpath0, k).eq(QryItem::getXbundle, ppCWork.getXjob()).remove();
                for (int i = 0; i < ((List<?>) v).size(); i++) {
                    //解析集合数据
                    String jsonStr = JSONUtil.toJsonStr(((List<?>) v).get(i));
                    Map<String, Object> value = JSONUtil.toBean(jsonStr, Map.class);
                    int finalI = i;
                    value.forEach((k1, v1) -> {
                        String uuId = UUID.randomUUID().toString();
                        QryItem qryItem = QryItem.builder().xid(uuId)
                                .xcreateTime(LocalDateTime.now())
                                .xsequence(LocalDateTime.now().format(DateTimeFormatter.ofPattern("yyyyMMddHHmmss")) + uuId)
                                .xupdateTime(LocalDateTime.now())
                                .xbundle(ppCWork.getXjob())
                                .xitemCategory("pp")
                                .xitemPrimitiveType("s")
                                .xitemStringValueType("s")
                                .xitemType("p")
                                .xpath0(k)
                                .xpath0Location(-1)
                                .xpath1(String.valueOf(finalI))
                                .xpath1Location(0)
                                .xpath2(k)
                                .xpath2Location(-1)
                                .xpath3(String.valueOf(-1))
                                .xpath3Location(-1)
                                .xpath4(String.valueOf(-1))
                                .xpath4Location(-1)
                                .xpath5(String.valueOf(-1))
                                .xpath5Location(-1)
                                .xpath6(String.valueOf(-1))
                                .xpath6Location(-1)
                                .xpath7(String.valueOf(-1))
                                .xpath7Location(-1)
                                .xstringShortValue(String.valueOf(v1))
                                .build();
                        qryItemList.add(qryItem);
                    });
                    //批量插入
                    qryItemService.saveBatch(qryItemList);
                }
            }
        });
    }


    @Resource
    private IPpMWorkeventService ppMWorkeventService;


    /**
     * 删除工作
     *
     * @param workId
     * @return
     */
    @Override
    @Transactional
    public Boolean closeWork(String workId) {
        //删除这项工作的数据
        //前提是待办工作，且没有人工活动
        //pp_c_review，pp_c_task，pp_c_work，qry_item ，pp_c_record,pp_c_worklog可能有附件pp_c_attachment
        //先获取work信息
        PpCWork ppCWork = ppCWorkService.getById(workId);
        if (ppCWork == null) {
            BizcenterException.cast("未找到对应的工作");
        }
        if (ppCWork.getXworkThroughManual()) {
            BizcenterException.cast("该工作已有人工活动,不能删除.");
        }
        String xjob = ppCWork.getXjob();

        PpMWorkevent ppMWorkevent = new PpMWorkevent();
        ppMWorkevent.setXjob(xjob);
        ppMWorkevent.setXapplication(ppCWork.getXapplication());
        ppMWorkevent.setXid(UUID.randomUUID().toString());
        ppMWorkevent.setXcreateTime(LocalDateTime.now());
        ppMWorkevent.setXsequence(LocalDateTime.now().format(DateTimeFormatter.ofPattern("yyyyMMddHHmmss")) + ppMWorkevent.getXid());
        ppMWorkevent.setXupdateTime(LocalDateTime.now());
        ppMWorkevent.setXtype("delete");
        ppMWorkevent.setXwork(workId);
        ppMWorkeventService.save(ppMWorkevent);

        qryItemService.remove(new QueryWrapper<QryItem>().eq("xbundle", xjob));
        //可能有附件
        ppCAttachmentService.remove(new QueryWrapper<PpCAttachment>().eq("xwork", workId));

        ppCWorklogService.remove(new QueryWrapper<PpCWorklog>().eq("xwork", workId));
        ppCReviewService.remove(new QueryWrapper<PpCReview>().eq("xwork", workId));
        ppCTaskService.remove(new QueryWrapper<PpCTask>().eq("xwork", workId));
        ppCRecordService.remove(new QueryWrapper<PpCRecord>().eq("xwork", workId));
        ppCWorkService.removeById(workId);

        return true;
    }


    /**
     * 重置处理人
     *
     * @param id
     * @param replaceDTO
     * @return
     */
    @Transactional
    @Override
    public ReplaceVO resetWorkPerson(String id, ReplaceDTO replaceDTO) {
        //首先查询pp_c_task信息
        PpCTask ppCTask = ppCTaskService.getById(id);
        PpCTaskcompleted ppCTaskcompleted = BeanUtil.copyProperties(ppCTask, PpCTaskcompleted.class);

        String uuId = UUID.randomUUID().toString();
        ppCTaskcompleted.setXid(uuId);
        ppCTaskcompleted.setXcreateTime(LocalDateTime.now());
        ppCTaskcompleted.setXsequence(LocalDateTime.now().format(DateTimeFormatter.ofPattern("yyyyMMddHHmmss")) + uuId);
        ppCTaskcompleted.setXupdateTime(LocalDateTime.now());
        ppCTaskcompleted.setXcompletedTime(LocalDateTime.now());
        ppCTaskcompleted.setXopinion(replaceDTO.getOpinion());
        ppCTaskcompleted.setXprocessingType("reset");
        ppCTaskcompleted.setXtask(id);
        //设置属性
        String xproperties = ppCTaskcompleted.getXproperties();
        Map<String, Object> properties = JSONUtil.toBean(xproperties, Map.class);
        properties.remove("prevTaskList");
        properties.put("opinion", replaceDTO.getOpinion());
        properties.put("prevTaskIdentityList", Collections.emptyList());
        properties.put("nextTaskIdentityList", replaceDTO.getIdentityList());

        String jsonStr = JSONUtil.toJsonStr(properties);
        ppCTaskcompleted.setXproperties(jsonStr);
        ppCTaskcompleted.setXrouteName(replaceDTO.getRouteName());
        boolean save = ppCTaskcompletedService.save(ppCTaskcompleted);
        if (!save) {
            BizcenterException.cast("重置处理人失败");
        }
        ppCTaskService.removeById(id);
        //修改review表
        String xworkId = ppCTask.getXwork();
        List<PpCReview> ppCReviewList = ppCReviewService.list(new QueryWrapper<PpCReview>().eq("xwork", xworkId));
        if (ppCReviewList == null) {
            BizcenterException.cast("未找到对应的记录");
        }
        for (PpCReview ppCReview : ppCReviewList) {
            if (!replaceDTO.getIdentityList().removeIf(s -> s.equals(ppCReview.getXperson()))) {
                ppCReviewService.remove(new QueryWrapper<PpCReview>().eq("xwork", xworkId));
            }
        }
        List<PpCReview> ppCReviewlist = ppCReviewService.lambdaQuery().eq(PpCReview::getXwork, xworkId).list();
        for (PpCReview ppCReview : ppCReviewlist) {
            for (String s : replaceDTO.getIdentityList()) {
                String uuid = UUID.randomUUID().toString();
                ppCReview.setXupdateTime(LocalDateTime.now());
                ppCReview.setXid(uuid);
                ppCReview.setXcreateTime(LocalDateTime.now());
                ppCReview.setXsequence(LocalDateTime.now().format(DateTimeFormatter.ofPattern("yyyyMMddHHmmss")) + uuid);
                ppCReview.setXperson(s);
                ppCReviewService.save(ppCReview);
            }
        }

        //设置work表
        PpCWork ppCWork = ppCWorkService.getById(xworkId);
        ppCWork.setXupdateTime(LocalDateTime.now());
        String xproperties1 = ppCWork.getXproperties();
        Map<String, Object> properties1 = JSONUtil.toBean(xproperties1, Map.class);
        //TODO 这里应该获取用户名
        properties1.put("manualTaskIdentityText", replaceDTO.getIdentityList().get(0).substring(0, 2));
        String jsonStr1 = JSONUtil.toJsonStr(properties1);
        ppCWork.setXproperties(jsonStr1);
        ppCWorkService.updateById(ppCWork);

        //向pp_c_record插入数据
        //TODO 数据有误
        PpCRecord ppCRecord = BeanUtil.copyProperties(ppCTask, PpCRecord.class);
        ppCRecord.setXid(UUID.randomUUID().toString());
        ppCRecord.setXcreateTime(LocalDateTime.now());
        ppCRecord.setXsequence(LocalDateTime.now().format(DateTimeFormatter.ofPattern("yyyyMMddHHmmss")) + ppCRecord.getXid());
        ppCRecord.setXupdateTime(LocalDateTime.now());
        ppCRecord.setXrecordTime(LocalDateTime.now());
        ppCRecord.setXtype("reset");
        ppCRecord.setXperson(replaceDTO.getDistinguishedNameList().get(0));
        ppCRecord.setXidentity(replaceDTO.getDistinguishedNameList().get(0));
        String xproperties2 = ppCRecord.getXproperties();
        Map<String, Object> properties2 = JSONUtil.toBean(xproperties2, Map.class);
        List<ActivityVO> nextManualList = new ArrayList<>();
        ActivityVO activityVO = BeanUtil.copyProperties(ppCTask, ActivityVO.class);
        activityVO.getTaskIdentityList().add(replaceDTO.getDistinguishedNameList().get(0));
        nextManualList.add(activityVO);
        properties2.put("nextManualList", nextManualList);
        properties2.put("nextManualTaskIdentityList", replaceDTO.getDistinguishedNameList().get(0));
        properties2.put("opinion", replaceDTO.getOpinion());
        properties2.put("routeName", replaceDTO.getRouteName());
        String jsonStr2 = JSONUtil.toJsonStr(properties2);
        ppCRecord.setXproperties(jsonStr2);
        ppCRecordService.save(ppCRecord);
        ReplaceVO replaceVO = BeanUtil.copyProperties(ppCRecord, ReplaceVO.class);
        replaceVO.setNextManualList(nextManualList);
        replaceVO.setNextManualTaskIdentityList(replaceDTO.getDistinguishedNameList().get(0));
        replaceVO.setProperties(properties2);
        return replaceVO;
    }


    @Resource
    private IPpERouteService ppERouteService;

    @Resource
    private IPpEManualService ppEManualService;

    @Resource
    private IPpCTaskRoutedecisionopinionlistService ppCTaskRoutedecisionopinionlistService;

    @Resource
    private IPpCTaskRoutelistService ppCTaskRoutelistService;

    @Resource
    private IPpCTaskRoutenamelistService ppCTaskRoutenamelistService;

    @Resource
    private IPpCTaskRouteopinionlistService ppCTaskRouteopinionlistService;

    @Resource
    private IPpCWorkcompletedService ppCWorkcompletedService;


    /**
     * 继续流转
     *
     * @param id
     * @param precessingDTO
     * @return
     */
    @Override
    @Transactional
    public RecordVO updateProcessing(String id, PrecessingDTO precessingDTO) {
        //1.查阅pp_c_task表
        PpCTask ppCTask = ppCTaskService.getById(id);
        if (ppCTask == null) {
            BizcenterException.cast("待办工作不存在!");
        }
        //2.向pp_c_taskcompleted插入数据
        PpCTaskcompleted ppCTaskcompleted = BeanUtil.copyProperties(ppCTask, PpCTaskcompleted.class);
        ppCTaskcompleted.setXid(UUID.randomUUID().toString());
        ppCTaskcompleted.setXcreateTime(LocalDateTime.now());
        ppCTaskcompleted.setXsequence(LocalDateTime.now().format(DateTimeFormatter.ofPattern("yyyyMMddHHmmss")) + ppCTaskcompleted.getXid());
        ppCTaskcompleted.setXupdateTime(LocalDateTime.now());
        ppCTaskcompleted.setXcompletedTime(LocalDateTime.now());
        ppCTaskcompleted.setXrouteName(precessingDTO.getRouteName());
        ppCTaskcompleted.setXprocessingType("task");
        ppCTaskcompleted.setXopinion(precessingDTO.getOpinion());
        ppCTaskcompleted.setXperson(precessingDTO.getCreatorPersonDn());
        ppCTaskcompleted.setXtask(ppCTask.getXid());

        //删除原有的待办
        ppCTaskService.removeById(id);
        String routerId = precessingDTO.getRouteList().get(0);
        PpERoute route = ppERouteService.getById(routerId);

        if ("结束".equals(route.getXname())) {

            //还需向pp_c_workcompleted表插入数据
            PpCWork ppCWork = ppCWorkService.getById(ppCTask.getXwork());
            PpCWorkcompleted ppCWorkcompleted = BeanUtil.copyProperties(ppCWork, PpCWorkcompleted.class);
            ppCWorkcompleted.setXid(UUID.randomUUID().toString());
            ppCWorkcompleted.setXcreateTime(LocalDateTime.now());
            ppCWorkcompleted.setXsequence(LocalDateTime.now().format(DateTimeFormatter.ofPattern("yyyyMMddHHmmss")) + ppCWorkcompleted.getXid());
            ppCWorkcompleted.setXupdateTime(LocalDateTime.now());
            ppCWorkcompleted.setXactivity(precessingDTO.getActivity());
            ppCWorkcompleted.setXactivityName(precessingDTO.getActivityName());
            ppCWorkcompleted.setXallowRollback(false);
            ppCWorkcompleted.setXcompletedTime(LocalDateTime.now());
            ppCWorkcompleted.setXcompletedTimeMonth(LocalDateTime.now().format(DateTimeFormatter.ofPattern("yyyyMM")));
            ppCWorkcompleted.setXcompletedType("end");
            Map<String, Object> properties = new HashMap<>();
            //List<PpCTaskcompleted> ppCTaskcompletedList = ppCTaskcompletedService.lambdaQuery().eq(PpCTaskcompleted::getXtask, ppCTask.getXid()).list();
            properties.put("taskCompleted", Collections.emptyList());
            //List<PpCReadcompleted> ppCReadcompletedList = ppCReadcompletedService.lambdaQuery().eq(PpCReadcompleted::getXwork, ppCTask.getXwork()).list();
            properties.put("readCompletedList", Collections.emptyList());
            //List<PpCReview> ppCReviewList = ppCReviewService.lambdaQuery().eq(PpCReview::getXwork, ppCTask.getXwork()).list();
            properties.put("reviewList", Collections.emptyList());
            //List<PpCWorklog> ppCWorklogList = ppCWorklogService.lambdaQuery().eq(PpCWorklog::getXwork, ppCTask.getXwork()).list();
            properties.put("workLogList", Collections.emptyList());
            properties.put("title", ppCWork.getXtitle());
            String jsonStr = JSONUtil.toJsonStr(properties);
            ppCWorkcompleted.setXproperties(jsonStr);
            ppCWorkcompleted.setXwork(ppCTask.getXwork());
            ppCWorkcompletedService.save(ppCWorkcompleted);

            ppCTaskcompleted.setXcurrentActivityName("结束");
            ppCTaskcompleted.setXworkCompleted(ppCWorkcompleted.getXid());

            //向worklog表中补充数据
            ppCWorklogService.lambdaUpdate().eq(PpCWorklog::getXwork, ppCTask.getXwork())
                    .set(PpCWorklog::getXcompleted, true)
                    .set(PpCWorklog::getXworkCompleted, ppCWorkcompleted.getXid())
                    .set(PpCWorklog::getXconnected, true)
                    .set(PpCWorklog::getXconnected, true)
                    .update();
        }

        //下一路由不是结束
        ppCTaskcompletedService.save(ppCTaskcompleted);
        //修改工作表数据，将当前人工活动修改为下一个结点的人工活动
        ppCWorkService.lambdaUpdate()
                .eq(PpCWork::getXid, ppCTask.getXwork())
                .set(PpCWork::getXupdateTime,LocalDateTime.now())
                .set(PpCWork::getXactivity, precessingDTO.getActivity())
                .set(PpCWork::getXactivityAlias, precessingDTO.getActivityAlias())
                .set(PpCWork::getXactivityToken,precessingDTO.getActivityToken())
                .set(PpCWork::getXactivityArrivedTime,LocalDateTime.now())
                .set(PpCWork::getXactivityDescription, precessingDTO.getActivityDescription())
                .set(PpCWork::getXactivityName, precessingDTO.getActivityName())
                .set(PpCWork::getXactivityType, precessingDTO.getActivityType())
                .set(PpCWork::getXdestinationRoute, precessingDTO.getRouteList().get(0))
                .set(PpCWork::getXdestinationRouteName, precessingDTO.getRouteNameList().get(0))
                .set(PpCWork::getXworkThroughManual,true)
                .update();
        //添加下一条工作日志
        // TODO 1.补充当前工作日志


        //新增待办
        PpCTask ppCTask1 = BeanUtil.copyProperties(ppCTask, PpCTask.class);
        ppCTask1.setXid(UUID.randomUUID().toString());
        ppCTask1.setXcreateTime(LocalDateTime.now());
        ppCTask1.setXsequence(LocalDateTime.now().format(DateTimeFormatter.ofPattern("yyyyMMddHHmmss")) + ppCTask1.getXid());
        ppCTask1.setXupdateTime(LocalDateTime.now());

        PpEManual manual = ppEManualService.getById(route.getXactivity());
        ppCTask1.setXactivityName(manual.getXname());
        //需要从qry_item表获取数据
        String xjob = ppCTask1.getXjob();
        //修改qry_item表数据
        qryItemService.lambdaUpdate().eq(QryItem::getXbundle, xjob).eq(QryItem::getXpath0, "$work")
                .eq(QryItem::getXitemCategory, "pp").eq(QryItem::getXpath1, "activityName")
                .set(QryItem::getXstringShortValue, ppCTask1.getXactivityName())
                .set(QryItem::getXupdateTime, LocalDateTime.now()).update();
        qryItemService.lambdaUpdate().eq(QryItem::getXbundle, xjob).eq(QryItem::getXpath0, "$work")
                .eq(QryItem::getXitemCategory, "pp").eq(QryItem::getXpath1, "updateTime")
                .set(QryItem::getXstringShortValue, LocalDateTime.now())
                .set(QryItem::getXupdateTime, LocalDateTime.now()).update();
        //List<QryItem> personDn = qryItemService.lambdaQuery().eq(QryItem::getXbundle, xjob).eq(QryItem::getXpath2, "personDn").eq(QryItem::getXitemCategory, "pp").list();
        ppCTask1.setXdistinguishedName(precessingDTO.getDistinguishedName());
        ppCTask1.setXidentity(precessingDTO.getIdentity());
        ppCTask1.setXperson(precessingDTO.getPerson());
        ppCTaskService.save(ppCTask1);

        //pp_c_task的子表插入数据
        if (precessingDTO.getRouteDecisionOpinionList() != null) {
            for (int i = 0; i < precessingDTO.getRouteDecisionOpinionList().size(); i++) {
                PpCTaskRoutedecisionopinionlist ppCTaskRoutedecisionopinionlist = new PpCTaskRoutedecisionopinionlist();
                ppCTaskRoutedecisionopinionlist.setTaskXid(ppCTask1.getXid());
                ppCTaskRoutedecisionopinionlist.setXrouteDecisionOpinionList(precessingDTO.getRouteDecisionOpinionList().get(i));
                ppCTaskRoutedecisionopinionlist.setXorderColumn(i);
                ppCTaskRoutedecisionopinionlistService.save(ppCTaskRoutedecisionopinionlist);
            }
        }

        if (precessingDTO.getRouteList() != null) {
            for (int i = 0; i < precessingDTO.getRouteList().size(); i++) {
                PpCTaskRoutelist ppCTaskRoutelist = new PpCTaskRoutelist();
                ppCTaskRoutelist.setTaskXid(ppCTask1.getXid());
                ppCTaskRoutelist.setXrouteList(precessingDTO.getRouteList().get(i));
                ppCTaskRoutelist.setXorderColumn(i);
                ppCTaskRoutelistService.save(ppCTaskRoutelist);
            }
        }
        if (precessingDTO.getRouteNameList() != null) {
            for (int i = 0; i < precessingDTO.getRouteNameList().size(); i++) {
                PpCTaskRoutenamelist ppCTaskRoutenamelist = new PpCTaskRoutenamelist();
                ppCTaskRoutenamelist.setTaskXid(ppCTask1.getXid());
                ppCTaskRoutenamelist.setXrouteNameList(precessingDTO.getRouteNameList().get(i));
                ppCTaskRoutenamelist.setXorderColumn(i);
                ppCTaskRoutenamelistService.save(ppCTaskRoutenamelist);
            }
        }
        if (precessingDTO.getRouteOpinionList() != null) {
            for (int i = 0; i < precessingDTO.getRouteOpinionList().size(); i++) {
                PpCTaskRouteopinionlist ppCTaskRouteopinionlist = new PpCTaskRouteopinionlist();
                ppCTaskRouteopinionlist.setTaskXid(ppCTask1.getXid());
                ppCTaskRouteopinionlist.setXrouteOpinionList(precessingDTO.getRouteOpinionList().get(i));
                ppCTaskRouteopinionlist.setXorderColumn(i);
                ppCTaskRouteopinionlistService.save(ppCTaskRouteopinionlist);
            }
        }
        //pp_c_record插入数据
        PpCRecord ppCRecord = BeanUtil.copyProperties(ppCTaskcompleted, PpCRecord.class);
        ppCRecord.setXid(UUID.randomUUID().toString());
        ppCRecord.setXcreateTime(LocalDateTime.now());
        ppCRecord.setXsequence(LocalDateTime.now().format(DateTimeFormatter.ofPattern("yyyyMMddHHmmss")) + ppCRecord.getXid());
        ppCRecord.setXupdateTime(LocalDateTime.now());
        ppCRecord.setXrecordTime(LocalDateTime.now());
        if (ppCRecord.getXworkCompleted() == null || ppCRecord.getXworkCompleted().isEmpty()) {
            ppCRecord.setXcompleted(false);
        } else {
            ppCRecord.setXcompleted(true);
        }
        ppCRecord.setXdisplay(true);

        //时间戳
        ppCRecord.setXorder(System.currentTimeMillis());
        //获取数据
        ppCRecord.setXperson(precessingDTO.getPerson());
        ppCRecord.setXtype("task");

        //设置属性
        String xproperties = ppCRecord.getXproperties();
        Map<String, Object> perperties = JSONUtil.toBean(xproperties, Map.class);
        // 清空
        perperties.clear();
        perperties.put("unitLevelOrderNumber", "");
        perperties.put("unitLevelName", "");
        perperties.put("unitDutyList", Collections.emptyList());
        List<ActivityVO> nextManualList = new ArrayList<>();
        ActivityVO activityVO = new ActivityVO();
        activityVO.setActivity(precessingDTO.getActivity());
        activityVO.setActivityType(precessingDTO.getActivityType());
        activityVO.setActivityName(precessingDTO.getActivityName());
        activityVO.setActivityToken(precessingDTO.getActivityToken());
        activityVO.setActivityAlias(precessingDTO.getActivityAlias());
        List<String> taskIdentityList = new ArrayList<>();

        taskIdentityList.add(precessingDTO.getProcess());
        activityVO.setTaskIdentityList(taskIdentityList);
        nextManualList.add(activityVO);

        perperties.put("nextManualList", nextManualList);
        perperties.put("nextManualTaskIdentityList", taskIdentityList);
        perperties.put("opinion", precessingDTO.getOpinion());
        perperties.put("routeName", precessingDTO.getRouteName());
        perperties.put("empowerFromIdentity", "");
        perperties.put("fromGroup", "");
        perperties.put("fromOpinionGroup", "");
        perperties.put("startTime", precessingDTO.getStartTime());
        perperties.put("elapsed", 0);
        String jsonStr = JSONUtil.toJsonStr(perperties);
        ppCRecord.setXproperties(jsonStr);
        ppCRecordService.save(ppCRecord);

        RecordVO recordVO = BeanUtil.copyProperties(ppCRecord, RecordVO.class);
        recordVO.setProperties(perperties);

        return recordVO;
    }


    /**
     * {
     * "unitLevelOrderNumber": "",
     * "unitLevelName": "",
     * "unitDutyList": [],
     * "nextManualList": [
     * {
     * "activity": "a1cc6925-d27c-42f9-870c-5071ca405d79",
     * "activityType": "manual",
     * "activityName": "申请人申请",
     * "activityAlias": "",
     * "activityToken": "912f7988-47e8-4207-a993-6b490e76fa95",
     * "taskIdentityList": [
     * "xj@1234_12312@I"
     * ]
     * }
     * ],
     * "nextManualTaskIdentityList": [
     * "xj@1234_12312@I"
     * ],
     * "empowerFromIdentity": "",
     * "routeName": "重置给:xj, 熊健",
     * "opinion": "重置给: xj, 熊健",
     * "startTime": "2024-10-29 19:03:07",
     * "elapsed": 0,
     * "fromGroup": "",
     * "fromOpinionGroup": ""
     * }
     */


    @Resource
    private ProcessTableDataService processTableDataService;


    /**
     * 放弃工作
     *
     * @param workId
     * @return
     */
    @Override
    @Transactional
    public String abandonedWork(String workId) {
        //先插入pp_c_snap表一张数据，返回这条数据的ID
        PpCWork ppCWork = ppCWorkService.getById(workId);
        if (ppCWork == null) {
            BizcenterException.cast("未找到对应的工作");
        }
        if (ppCWork.getXworkThroughManual()) {
            BizcenterException.cast("该工作已有人工活动,不能删除.");
        }
        PpCSnap ppCSnap = BeanUtil.copyProperties(ppCWork, PpCSnap.class);
        //设置UUID
        UUID uuid = UUID.randomUUID();
        ppCSnap.setXid(uuid.toString());
        //设置时间
        ppCSnap.setXcreateTime(LocalDateTime.now());
        ppCSnap.setXupdateTime(LocalDateTime.now());
        //设置序列号
        String time = LocalDateTime.now().format(DateTimeFormatter.ofPattern("yyyyMMddHHmmss"));
        ppCSnap.setXsequence(time + uuid);
        //设置类型
        ppCSnap.setXtype("abandoned");
        //设置属性
        Map<String, Object> properties = new HashMap<>();

        //1. 获取表单的data数据
        ProcessFormDataVO processFormDataVO = processTableDataService.getProcessTableDataByXid(workId);
        JSONObject data = processFormDataVO.getData();
        properties.put("data", data);
        //2.设置title
        properties.put("title", ppCSnap.getXtitle());
        //3.job
        properties.put("job", ppCSnap.getXjob());
        //4.workList
        WorkVO workVO = BeanUtil.copyProperties(ppCWork, WorkVO.class);
        properties.put("workList", workVO);
        //5.taskList
        List<PpCTask> ppCTask = ppCTaskService.lambdaQuery().eq(PpCTask::getXwork, workId).list();
        if (ppCTask != null) {
            List<TaskVO> taskVOList = new ArrayList<>();
            for (PpCTask cTask : ppCTask) {
                TaskVO taskVO = BeanUtil.copyProperties(cTask, TaskVO.class);
                taskVOList.add(taskVO);
            }
            properties.put("taskList", taskVOList);
        } else {
            properties.put("taskList", Collections.emptyList());
        }
        //taskCompletedList
        List<PpCTaskcompleted> ppCTaskcompleted = ppCTaskcompletedService.lambdaQuery().eq(PpCTaskcompleted::getXwork, workId).list();
        if (ppCTaskcompleted != null) {
            List<TaskCompletedVO> taskCompletedVOList = new ArrayList<>();
            for (PpCTaskcompleted cTaskcompleted : ppCTaskcompleted) {
                TaskCompletedVO taskCompletedVO = BeanUtil.copyProperties(cTaskcompleted, TaskCompletedVO.class);
                taskCompletedVOList.add(taskCompletedVO);
            }
            properties.put("taskCompletedList", taskCompletedVOList);
        } else {
            properties.put("taskCompletedList", Collections.emptyList());
        }
        //readList
        List<PpCRead> ppCReadList = ppCReadService.lambdaQuery().eq(PpCRead::getXwork, workId).list();
        if (ppCReadList != null) {
            List<ReadVO> readVOList = new ArrayList<>();
            for (PpCRead cRead : ppCReadList) {
                ReadVO readVO = BeanUtil.copyProperties(cRead, ReadVO.class);
                readVOList.add(readVO);
            }
            properties.put("readList", readVOList);
        } else {
            properties.put("readList", Collections.emptyList());
        }
        //readCompletedList
        List<PpCReadcompleted> ppCReadcompletedList = ppCReadcompletedService.lambdaQuery().eq(PpCReadcompleted::getXwork, workId).list();
        if (ppCReadcompletedList != null) {
            List<ReadCompletedVO> readCompletedVOList = new ArrayList<>();
            for (PpCReadcompleted cReadcompleted : ppCReadcompletedList) {
                ReadCompletedVO readCompletedVO = BeanUtil.copyProperties(cReadcompleted, ReadCompletedVO.class);
                readCompletedVOList.add(readCompletedVO);
            }
            properties.put("readCompletedList", readCompletedVOList);
        } else {
            properties.put("readCompletedList", Collections.emptyList());
        }
        //reviewList
        List<PpCReview> ppCReviewList = ppCReviewService.lambdaQuery().eq(PpCReview::getXwork, workId).list();
        if (ppCReviewList != null) {
            List<ReviewVO> reviewVOList = new ArrayList<>();
            for (PpCReview cReview : ppCReviewList) {
                ReviewVO reviewVO = BeanUtil.copyProperties(cReview, ReviewVO.class);
                reviewVOList.add(reviewVO);
            }
            properties.put("reviewList", reviewVOList);
        } else {
            properties.put("reviewList", Collections.emptyList());
        }
        //attachmentList
        List<PpCAttachment> ppCAttachmentList = ppCAttachmentService.lambdaQuery().eq(PpCAttachment::getXwork, workId).list();
        if (ppCAttachmentList != null) {
            List<AttachmentVO> attachmentVOList = new ArrayList<>();
            for (PpCAttachment ppCAttachment : ppCAttachmentList) {
                AttachmentVO attachmentVO = BeanUtil.copyProperties(ppCAttachment, AttachmentVO.class);
                attachmentVOList.add(attachmentVO);
            }
            getAttachmentList(attachmentVOList);
            properties.put("attachmentList", attachmentVOList);

        } else {
            properties.put("attachmentList", Collections.emptyList());
        }

        //recordList
        List<PpCRecord> ppCRecordList = ppCRecordService.lambdaQuery().eq(PpCRecord::getXwork, workId).list();
        if (ppCRecordList != null) {
            List<RecordVO> recordVOList = new ArrayList<>();
            for (PpCRecord cRecord : ppCRecordList) {
                RecordVO recordVO = BeanUtil.copyProperties(cRecord, RecordVO.class);
                recordVOList.add(recordVO);
            }
            properties.put("recordList", recordVOList);
        } else {
            properties.put("recordList", Collections.emptyList());
        }

        //workLogList
        List<PpCWorklog> ppCWorklogList = ppCWorklogService.lambdaQuery().eq(PpCWorklog::getXwork, workId).list();
        if (ppCWorklogList != null) {
            List<WorkLogVO> workLogVOList = new ArrayList<>();
            for (PpCWorklog cWorklog : ppCWorklogList) {
                WorkLogVO workLogVO = BeanUtil.copyProperties(cWorklog, WorkLogVO.class);
                workLogVOList.add(workLogVO);
            }
            properties.put("workLogList", workLogVOList);
        } else {
            properties.put("workLogList", Collections.emptyList());
        }

        return uuid.toString();
    }


    @Resource
    private IPpCAttachmentControlleridentitylistService ppCAttachmentControlleridentitylistService;

    @Resource
    private IPpCAttachmentControllerunitlistService ppCAttachmentControllerunitlistService;

    @Resource
    private IPpCAttachmentDivisionlistService ppCAttachmentDivisionlistService;

    @Resource
    private IPpCAttachmentEditidentitylistService ppCAttachmentEditidentitylistService;

    @Resource
    private IPpCAttachmentEditunitlistService ppCAttachmentEditunitlistService;

    @Resource
    private IPpCAttachmentReadidentitylistService ppCAttachmentReadidentitylistService;

    @Resource
    private IPpCAttachmentReadunitlistService ppCAttachmentReadunitlistService;

    private void getAttachmentList(List<AttachmentVO> ppCAttachmentVOList) {

        List<String> ids = ppCAttachmentVOList.stream().map(AttachmentVO::getId).collect(Collectors.toList());

        List<PpCAttachmentControlleridentitylist> ppCAttachmentControlleridentitylistList = ppCAttachmentControlleridentitylistService.listByIds(ids);
        if (ppCAttachmentControlleridentitylistList != null) {
            List<String> list = new ArrayList<>();
            for (AttachmentVO attachmentVO : ppCAttachmentVOList) {
                String attachmentVOId = attachmentVO.getId();
                for (PpCAttachmentControlleridentitylist ppCAttachmentControlleridentitylist : ppCAttachmentControlleridentitylistList) {
                    if (attachmentVOId.equals(ppCAttachmentControlleridentitylist.getAttachmentXid())) {
                        list.add(ppCAttachmentControlleridentitylist.getXorderColumn(), ppCAttachmentControlleridentitylist.getXcontrollerIdentityList());
                    }
                }
                attachmentVO.setControllerIdentityList(list);
            }
        } else {
            ppCAttachmentVOList.forEach(attachmentVO -> attachmentVO.setControllerIdentityList(Collections.emptyList()));
        }

        List<PpCAttachmentControllerunitlist> ppCAttachmentControllerunitlistList = ppCAttachmentControllerunitlistService.listByIds(ids);
        if (ppCAttachmentControllerunitlistList != null) {
            for (AttachmentVO attachmentVO : ppCAttachmentVOList) {
                String attachmentVOId = attachmentVO.getId();
                List<String> list = new ArrayList<>();
                for (PpCAttachmentControllerunitlist ppCAttachmentControllerunitlist : ppCAttachmentControllerunitlistList) {
                    if (attachmentVOId.equals(ppCAttachmentControllerunitlist.getAttachmentXid())) {
                        list.add(ppCAttachmentControllerunitlist.getXorderColumn(), ppCAttachmentControllerunitlist.getXcontrollerUnitList());
                    }
                }
                attachmentVO.setControllerUnitList(list);
            }
        } else {
            ppCAttachmentVOList.forEach(attachmentVO -> attachmentVO.setControllerUnitList(Collections.emptyList()));
        }

        List<PpCAttachmentDivisionlist> ppCAttachmentDivisionlistList = ppCAttachmentDivisionlistService.listByIds(ids);
        if (ppCAttachmentDivisionlistList != null) {
            for (AttachmentVO attachmentVO : ppCAttachmentVOList) {
                String attachmentVOId = attachmentVO.getId();
                List<String> list = new ArrayList<>();
                for (PpCAttachmentDivisionlist ppCAttachmentDivisionlist : ppCAttachmentDivisionlistList) {
                    if (attachmentVOId.equals(ppCAttachmentDivisionlist.getAttachmentXid())) {
                        list.add(ppCAttachmentDivisionlist.getXorderColumn(), ppCAttachmentDivisionlist.getXdivisionList());
                    }
                }
                attachmentVO.setDivisionList(list);
            }
        } else {
            ppCAttachmentVOList.forEach(attachmentVO -> attachmentVO.setDivisionList(Collections.emptyList()));
        }

        List<PpCAttachmentEditidentitylist> ppCAttachmentEditidentitylistList = ppCAttachmentEditidentitylistService.listByIds(ids);
        if (ppCAttachmentEditidentitylistList != null) {
            for (AttachmentVO attachmentVO : ppCAttachmentVOList) {
                String attachmentVOId = attachmentVO.getId();
                List<String> list = new ArrayList<>();
                for (PpCAttachmentEditidentitylist ppCAttachmentEditidentitylist : ppCAttachmentEditidentitylistList) {
                    if (attachmentVOId.equals(ppCAttachmentEditidentitylist.getAttachmentXid())) {
                        list.add(ppCAttachmentEditidentitylist.getXorderColumn(), ppCAttachmentEditidentitylist.getXeditIdentityList());
                    }
                }
                attachmentVO.setEditidentityList(list);
            }
        } else {
            ppCAttachmentVOList.forEach(attachmentVO -> attachmentVO.setEditidentityList(Collections.emptyList()));
        }

        List<PpCAttachmentEditunitlist> ppCAttachmentEditunitlistList = ppCAttachmentEditunitlistService.listByIds(ids);
        if (ppCAttachmentEditunitlistList != null) {
            for (AttachmentVO attachmentVO : ppCAttachmentVOList) {
                String attachmentVOId = attachmentVO.getId();
                List<String> list = new ArrayList<>();
                for (PpCAttachmentEditunitlist ppCAttachmentEditunitlist : ppCAttachmentEditunitlistList) {
                    if (attachmentVOId.equals(ppCAttachmentEditunitlist.getAttachmentXid())) {
                        list.add(ppCAttachmentEditunitlist.getXorderColumn(), ppCAttachmentEditunitlist.getXeditUnitList());
                    }
                }
                attachmentVO.setEditunitList(list);
            }
        } else {
            ppCAttachmentVOList.forEach(attachmentVO -> attachmentVO.setEditunitList(Collections.emptyList()));
        }

        List<PpCAttachmentReadidentitylist> ppCAttachmentReadidentitylistList = ppCAttachmentReadidentitylistService.listByIds(ids);
        if (ppCAttachmentReadidentitylistList != null) {
            for (AttachmentVO attachmentVO : ppCAttachmentVOList) {
                String attachmentVOId = attachmentVO.getId();
                List<String> list = new ArrayList<>();
                for (PpCAttachmentReadidentitylist ppCAttachmentReadidentitylist : ppCAttachmentReadidentitylistList) {
                    if (attachmentVOId.equals(ppCAttachmentReadidentitylist.getAttachmentXid())) {
                        list.add(ppCAttachmentReadidentitylist.getXorderColumn(), ppCAttachmentReadidentitylist.getXreadIdentityList());
                    }
                }
                attachmentVO.setReadIdentityList(list);
            }
        } else {
            ppCAttachmentVOList.forEach(attachmentVO -> attachmentVO.setReadIdentityList(Collections.emptyList()));
        }

        List<PpCAttachmentReadunitlist> ppCAttachmentReadunitlistList = ppCAttachmentReadunitlistService.listByIds(ids);
        if (ppCAttachmentReadunitlistList != null) {
            for (AttachmentVO attachmentVO : ppCAttachmentVOList) {
                String attachmentVOId = attachmentVO.getId();
                List<String> list = new ArrayList<>();
                for (PpCAttachmentReadunitlist ppCAttachmentReadunitlist : ppCAttachmentReadunitlistList) {
                    if (attachmentVOId.equals(ppCAttachmentReadunitlist.getAttachmentXid())) {
                        list.add(ppCAttachmentReadunitlist.getXorderColumn(), ppCAttachmentReadunitlist.getXreadUnitList());
                    }
                }
                attachmentVO.setReadUnitList(list);
            }
        } else {
            ppCAttachmentVOList.forEach(attachmentVO -> attachmentVO.setReadUnitList(Collections.emptyList()));
        }

    }


}
