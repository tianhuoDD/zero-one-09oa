package com.zeroone.star.procmanager.service.impl;

import cn.hutool.core.bean.BeanUtil;
import cn.hutool.core.collection.CollUtil;
import cn.hutool.core.util.StrUtil;
import com.alibaba.nacos.shaded.org.checkerframework.checker.units.qual.A;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.procmanager.entity.*;
import com.zeroone.star.procmanager.mapper.ProcessMapper;
import com.zeroone.star.procmanager.service.*;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.j4.process.*;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.project.vo.j4.process.DeleteProcessVO;
import com.zeroone.star.project.vo.j4.process.ModifyProcessOrAddProcessVO;
import org.apache.poi.ss.formula.functions.T;
import org.mapstruct.Mapper;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
import springfox.documentation.spring.web.json.Json;

import javax.annotation.Resource;
import javax.transaction.xa.Xid;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.UUID;
import java.util.stream.Collectors;

@Mapper(componentModel = "spring")
interface MSMapper {

    ModifyProcessOrAddProcessDTO processToModifyProcessOrAddProcessDTO(Process process);

    DeleteProcessDTO processToDeleteProcessDTO(Process process);


    PpEProcess processDTOToProcess(ProcessDTO processDTO);

    PpEAgent agentDTOToAgent(AgentDTO agentDTO);

    PpEBegin beginDTOToPpEBegin(BeginDTO beginDTO);

    PpECancel cancelDTOToPpECancel(CancelDTO cancelDTO);

    PpEChoice choiceDTOToPpEChoice(ChoiceDTO choiceDTO);

    PpEDelay delayDTOToPpEDelay(DelayDTO delayDTO);

    PpEEmbed embedDTOToPpEEmbed(EmbedDTO embedDTO);

    PpEEnd endDTOtoPpEEnd(EndDTO endDTO);

    PpEInvoke invokeDTOToPpEInvoke(InvokeDTO invokeDTO);

    PpEManual manualDTOToManual(ManualDTO manualDTO);

    PpEMerge mergeDTOToPpEMerge(MergeDTO mergeDTO);

    PpEParallel parallelDTOToPpEParallel(PpEParallel parallelDTO);

    PpEPublish publishDTOToPpEPublish(PpEPublish publishDTO);

    PpERoute routeDTOToPpERoute(PpERoute routeDTO);

    PpEService serviceDTOToPpEService(ServiceDTO serviceDTO);

    PpESplit splitDTOToPpESplit(PpESplit splitDTO);


}


/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author awei
 * @since 2024-10-21
 */
@Service
public class ProcessServiceImpl extends ServiceImpl<ProcessMapper, PpEProcess> implements IProcessService {

    @Resource
    MSMapper msMapper;

    @Resource
    ProcessMapper PpEprocessMapper;

    @Resource
    IPpEAgentReaddatapathlistService agentReaddatapathlistServiceImpl;
    @Resource
    IPpEAgentReadgrouplistService agentReadgrouplistServiceImpl;
    @Resource
    IPpEAgentReadidentitylistService agentReadidentitylistServiceImpl;
    @Resource
    IPpEAgentReadunitlistService agentReadunitlistServiceImpl;
    @Resource
    IPpEAgentReviewdatapathlistService agentReviewdatapathlistServiceImpl;
    @Resource
    IPpEAgentReviewgrouplistService agentReviewgrouplistServiceImpl;
    @Resource
    IPpEAgentReviewidentitylistService agentReviewidentitylistServiceImpl;
    @Resource
    IPpEAgentReviewunitlistService agentReviewunitlistServiceImpl;
    @Resource
    IPpEAgentService agentServiceImpl;
    @Resource
    IPpEBeginReaddatapathlistService beginReaddatapathlistServiceImpl;
    @Resource
    IPpEBeginReadgrouplistService beginReadgrouplistServiceImpl;
    @Resource
    IPpEBeginReadidentitylistService beginReadidentitylistServiceImpl;
    @Resource
    IPpEBeginReadunitlistService beginReadunitlistServiceImpl;
    @Resource
    IPpEBeginReviewdatapathlistService beginReviewdatapathlistServiceImpl;
    @Resource
    IPpEBeginReviewgrouplistService beginReviewgrouplistServiceImpl;
    @Resource
    IPpEBeginReviewidentitylistService beginReviewidentitylistServiceImpl;
    @Resource
    IPpEBeginReviewunitlistService beginReviewunitlistServiceImpl;
    @Resource
    IPpEBeginService beginServiceImpl;
    @Resource
    IPpECancelReaddatapathlistService cancelReaddatapathlistServiceImpl;
    @Resource
    IPpECancelReadgrouplistService cancelReadgrouplistServiceImpl;
    @Resource
    IPpECancelReadidentitylistService cancelReadidentitylistServiceImpl;
    @Resource
    IPpECancelReadunitlistService cancelReadunitlistServiceImpl;
    @Resource
    IPpECancelReviewdatapathlistService cancelReviewdatapathlistServiceImpl;
    @Resource
    IPpECancelReviewgrouplistService cancelReviewgrouplistServiceImpl;
    @Resource
    IPpECancelReviewidentitylistService cancelReviewidentitylistServiceImpl;
    @Resource
    IPpECancelReviewunitlistService cancelReviewunitlistServiceImpl;
    @Resource
    IPpECancelService cancelServiceImpl;
    @Resource
    IPpEChoiceReaddatapathlistService choiceReaddatapathlistServiceImpl;
    @Resource
    IPpEChoiceReadgrouplistService choiceReadgrouplistServiceImpl;
    @Resource
    IPpEChoiceReadidentitylistService choiceReadidentitylistServiceImpl;
    @Resource
    IPpEChoiceReadunitlistService choiceReadunitlistServiceImpl;
    @Resource
    IPpEChoiceReviewdatapathlistService choiceReviewdatapathlistServiceImpl;
    @Resource
    IPpEChoiceReviewgrouplistService choiceReviewgrouplistServiceImpl;
    @Resource
    IPpEChoiceReviewidentitylistService choiceReviewidentitylistServiceImpl;
    @Resource
    IPpEChoiceReviewunitlistService choiceReviewunitlistServiceImpl;
    @Resource
    IPpEChoiceRoutelistService choiceRoutelistServiceImpl;
    @Resource
    IPpEChoiceService choiceServiceImpl;
    @Resource
    IPpEDelayReaddatapathlistService delayReaddatapathlistServiceImpl;
    @Resource
    IPpEDelayReadgrouplistService delayReadgrouplistServiceImpl;
    @Resource
    IPpEDelayReadidentitylistService delayReadidentitylistServiceImpl;
    @Resource
    IPpEDelayReadunitlistService delayReadunitlistServiceImpl;
    @Resource
    IPpEDelayReviewdatapathlistService delayReviewdatapathlistServiceImpl;
    @Resource
    IPpEDelayReviewgrouplistService delayReviewgrouplistServiceImpl;
    @Resource
    IPpEDelayReviewidentitylistService delayReviewidentitylistServiceImpl;
    @Resource
    IPpEDelayReviewunitlistService delayReviewunitlistServiceImpl;
    @Resource
    IPpEDelayService delayServiceImpl;
    @Resource
    IPpEEmbedReaddatapathlistService embedReaddatapathlistServiceImpl;
    @Resource
    IPpEEmbedReadgrouplistService embedReadgrouplistServiceImpl;
    @Resource
    IPpEEmbedReadidentitylistService embedReadidentitylistServiceImpl;
    @Resource
    IPpEEmbedReadunitlistService embedReadunitlistServiceImpl;
    @Resource
    IPpEEmbedReviewdatapathlistService embedReviewdatapathlistServiceImpl;
    @Resource
    IPpEEmbedReviewgrouplistService embedReviewgrouplistServiceImpl;
    @Resource
    IPpEEmbedReviewidentitylistService embedReviewidentitylistServiceImpl;
    @Resource
    IPpEEmbedReviewunitlistService embedReviewunitlistServiceImpl;
    @Resource
    IPpEEmbedService embedServiceImpl;
    @Resource
    IPpEEndReaddatapathlistService endReaddatapathlistServiceImpl;
    @Resource
    IPpEEndReadgrouplistService endReadgrouplistServiceImpl;
    @Resource
    IPpEEndReadidentitylistService endReadidentitylistServiceImpl;
    @Resource
    IPpEEndReadunitlistService endReadunitlistServiceImpl;
    @Resource
    IPpEEndReviewdatapathlistService endReviewdatapathlistServiceImpl;
    @Resource
    IPpEEndReviewgrouplistService endReviewgrouplistServiceImpl;
    @Resource
    IPpEEndReviewidentitylistService endReviewidentitylistServiceImpl;
    @Resource
    IPpEEndReviewunitlistService endReviewunitlistServiceImpl;
    @Resource
    IPpEEndService endServiceImpl;
    @Resource
    IPpEInvokeReaddatapathlistService invokeReaddatapathlistServiceImpl;
    @Resource
    IPpEInvokeReadgrouplistService invokeReadgrouplistServiceImpl;
    @Resource
    IPpEInvokeReadidentitylistService invokeReadidentitylistServiceImpl;
    @Resource
    IPpEInvokeReadunitlistService invokeReadunitlistServiceImpl;
    @Resource
    IPpEInvokeReviewdatapathlistService invokeReviewdatapathlistServiceImpl;
    @Resource
    IPpEInvokeReviewgrouplistService invokeReviewgrouplistServiceImpl;
    @Resource
    IPpEInvokeReviewidentitylistService invokeReviewidentitylistServiceImpl;
    @Resource
    IPpEInvokeReviewunitlistService invokeReviewunitlistServiceImpl;
    @Resource
    IPpEInvokeService invokeServiceImpl;
    @Resource
    IPpEManualReaddatapathlistService manualReaddatapathlistServiceImpl;
    @Resource
    IPpEManualReadgrouplistService manualReadgrouplistServiceImpl;
    @Resource
    IPpEManualReadidentitylistService manualReadidentitylistServiceImpl;
    @Resource
    IPpEManualReadunitlistService manualReadunitlistServiceImpl;
    @Resource
    IPpEManualReviewdatapathlistService manualReviewdatapathlistServiceImpl;
    @Resource
    IPpEManualReviewgrouplistService manualReviewgrouplistServiceImpl;
    @Resource
    IPpEManualReviewidentitylistService manualReviewidentitylistServiceImpl;
    @Resource
    IPpEManualReviewunitlistService manualReviewunitlistServiceImpl;
    @Resource
    IPpEManualRoutelistService manualRoutelistServiceImpl;
    @Resource
    IPpEManualService manualServiceImpl;
    @Resource
    IPpEManualTaskdatapathlistService manualTaskdatapathlistServiceImpl;
    @Resource
    IPpEManualTaskgrouplistService manualTaskgrouplistServiceImpl;
    @Resource
    IPpEManualTaskidentitylistService manualTaskidentitylistServiceImpl;
    @Resource
    IPpEManualTaskunitlistService manualTaskunitlistServiceImpl;
    @Resource
    IPpEMergeReaddatapathlistService mergeReaddatapathlistServiceImpl;
    @Resource
    IPpEMergeReadgrouplistService mergeReadgrouplistServiceImpl;
    @Resource
    IPpEMergeReadidentitylistService mergeReadidentitylistServiceImpl;
    @Resource
    IPpEMergeReadunitlistService mergeReadunitlistServiceImpl;
    @Resource
    IPpEMergeReviewdatapathlistService mergeReviewdatapathlistServiceImpl;
    @Resource
    IPpEMergeReviewgrouplistService mergeReviewgrouplistServiceImpl;
    @Resource
    IPpEMergeReviewidentitylistService mergeReviewidentitylistServiceImpl;
    @Resource
    IPpEMergeReviewunitlistService mergeReviewunitlistServiceImpl;
    @Resource
    IPpEMergeService mergeServiceImpl;
    @Resource
    IPpEParallelReaddatapathlistService parallelReaddatapathlistServiceImpl;
    @Resource
    IPpEParallelReadgrouplistService parallelReadgrouplistServiceImpl;
    @Resource
    IPpEParallelReadidentitylistService parallelReadidentitylistServiceImpl;
    @Resource
    IPpEParallelReadunitlistService parallelReadunitlistServiceImpl;
    @Resource
    IPpEParallelReviewdatapathlistService parallelReviewdatapathlistServiceImpl;
    @Resource
    IPpEParallelReviewgrouplistService parallelReviewgrouplistServiceImpl;
    @Resource
    IPpEParallelReviewidentitylistService parallelReviewidentitylistServiceImpl;
    @Resource
    IPpEParallelReviewunitlistService parallelReviewunitlistServiceImpl;
    @Resource
    IPpEParallelRoutelistService parallelRoutelistServiceImpl;
    @Resource
    IPpEParallelService parallelServiceImpl;
    @Resource
    IPpEProcessControllerlistService processControllerlistServiceImpl;
    @Resource
    IPpEProcessStartablegrouplistService processStartablegrouplistServiceImpl;
    @Resource
    IPpEProcessStartableidentitylistService processStartableidentitylistServiceImpl;
    @Resource
    IPpEProcessStartableunitlistService processStartableunitlistServiceImpl;
    @Resource
    IPpEProcessversionService processversionServiceImpl;
    @Resource
    IPpEProcessService processService;
    @Resource
    IPpEPublishReaddatapathlistService publishReaddatapathlistServiceImpl;
    @Resource
    IPpEPublishReadgrouplistService publishReadgrouplistServiceImpl;
    @Resource
    IPpEPublishReadidentitylistService publishReadidentitylistServiceImpl;
    @Resource
    IPpEPublishReadunitlistService publishReadunitlistServiceImpl;
    @Resource
    IPpEPublishReviewdatapathlistService publishReviewdatapathlistServiceImpl;
    @Resource
    IPpEPublishReviewgrouplistService publishReviewgrouplistServiceImpl;
    @Resource
    IPpEPublishReviewidentitylistService publishReviewidentitylistServiceImpl;
    @Resource
    IPpEPublishReviewunitlistService publishReviewunitlistServiceImpl;
    @Resource
    IPpEPublishService publishServiceImpl;
    @Resource
    IPpEServiceReaddatapathlistService serviceReaddatapathlistServiceImpl;
    @Resource
    IPpEServiceReadgrouplistService serviceReadgrouplistServiceImpl;
    @Resource
    IPpEServiceReadidentitylistService serviceReadidentitylistServiceImpl;
    @Resource
    IPpEServiceReadunitlistService serviceReadunitlistServiceImpl;
    @Resource
    IPpEServiceReviewdatapathlistService serviceReviewdatapathlistServiceImpl;
    @Resource
    IPpEServiceReviewgrouplistService serviceReviewgrouplistServiceImpl;
    @Resource
    IPpEServiceReviewidentitylistService serviceReviewidentitylistServiceImpl;
    @Resource
    IPpEServiceReviewunitlistService serviceReviewunitlistServiceImpl;
    @Resource
    IPpEServiceService serviceServiceImpl;
    @Resource
    IPpEServiceTrustaddresslistService serviceTrustaddresslistServiceImpl;
    @Resource
    IPpESplitReaddatapathlistService splitReaddatapathlistServiceImpl;
    @Resource
    IPpESplitReadgrouplistService splitReadgrouplistServiceImpl;
    @Resource
    IPpESplitReadidentitylistService splitReadidentitylistServiceImpl;
    @Resource
    IPpESplitReadunitlistService splitReadunitlistServiceImpl;
    @Resource
    IPpESplitReviewdatapathlistService splitReviewdatapathlistServiceImpl;
    @Resource
    IPpESplitReviewgrouplistService splitReviewgrouplistServiceImpl;
    @Resource
    IPpESplitReviewidentitylistService splitReviewidentitylistServiceImpl;
    @Resource
    IPpESplitReviewunitlistService splitReviewunitlistServiceImpl;
    @Resource
    IPpESplitService splitServiceImpl;


    /**
     * 新增流程
     *
     * @param modifyProcessOrAddProcessDTO
     * @return com.zeroone.star.project.vo.JsonVO<com.zeroone.star.project.vo.j4.process.ModifyProcessOrAddProcessVO>
     * @author 夜寻
     * @create 2024/11/2
     **/
    @Override
    @Transactional
    public JsonVO<ModifyProcessOrAddProcessVO> saveProcess(ModifyProcessOrAddProcessDTO modifyProcessOrAddProcessDTO) {

        String id=modifyProcessOrAddProcessDTO.processDTO.xid;
        PpEProcess PpEprocess=PpEprocessMapper.selectById(id);

        if(BeanUtil.isNotEmpty(PpEprocess)){
            return JsonVO.create(null,ResultStatus.FAIL.getCode(),"该流程已存在");
        }

        //插入process表
        ProcessDTO processDTO = modifyProcessOrAddProcessDTO.getProcessDTO();
        if(BeanUtil.isNotEmpty(processDTO)){
            PpEProcess ppEProcess = BeanUtil.copyProperties(processDTO, PpEProcess.class);
            processService.save(ppEProcess);

            String processId = processDTO.getXid();
            //插入process_controller_list表
            ArrayList<String> controllerLists = modifyProcessOrAddProcessDTO.getControllerList();
            if(CollUtil.isNotEmpty(controllerLists)){
                List<PpEProcessControllerlist> processControllerlists = new ArrayList<>();
                for (String controllerList : controllerLists) {
                    PpEProcessControllerlist ppEProcessControllerlist = new PpEProcessControllerlist();
                    ppEProcessControllerlist.setProcessXid(processId);
                    ppEProcessControllerlist.setXcontrollerList(controllerList);

                    processControllerlists.add(ppEProcessControllerlist);
                }
                processControllerlistServiceImpl.saveBatch(processControllerlists);
            }

            //插入startable_group_list表
            String xstartableGroupList = processDTO.getXstartableGroupList();
            if(StrUtil.isNotBlank(xstartableGroupList)){
                PpEProcessStartablegrouplist ppEProcessStartablegrouplist = new PpEProcessStartablegrouplist();
                ppEProcessStartablegrouplist.setProcessXid(processId);
                ppEProcessStartablegrouplist.setXstartableGroupList(xstartableGroupList);
                processStartablegrouplistServiceImpl.save(ppEProcessStartablegrouplist);
            }

            //插入startable_unit_list表
            String xstartableUnitList = processDTO.getXstartableUnitList();
            if(StrUtil.isNotBlank(xstartableUnitList)){
                PpEProcessStartableunitlist ppEProcessStartableunitlist = new PpEProcessStartableunitlist();
                ppEProcessStartableunitlist.setProcessXid(processId);
                ppEProcessStartableunitlist.setXstartableUnitList(xstartableUnitList);
                processStartableunitlistServiceImpl.save(ppEProcessStartableunitlist);
            }

            //插入startableIdentitList表
            String xstartableIdentityList = processDTO.getXstartableIdentityList();
            if(StrUtil.isNotBlank(xstartableIdentityList)){
                PpEProcessStartableidentitylist ppEProcessStartableidentitylist = new PpEProcessStartableidentitylist();
                ppEProcessStartableidentitylist.setProcessXid(processId);
                ppEProcessStartableidentitylist.setXstartableIdentityList(xstartableIdentityList);
                processStartableidentitylistServiceImpl.save(ppEProcessStartableidentitylist);
            }

            //插入startableIdentitList表
            String xversionDescription = processDTO.getXversionDescription();
            if(StrUtil.isNotBlank(xversionDescription)){
                PpEProcessversion ppEProcessversion = new PpEProcessversion();
                ppEProcessversion.setXid(UUID.randomUUID().toString());
                ppEProcessversion.setXdata(xversionDescription);
                // ppEProcessversion.setXperson(new UserHolder().getCurrentToken());
                //TODO 修改为从UserHodler中获取person
                ppEProcessversion.setXcreateTime(LocalDateTime.now());
                ppEProcessversion.setXupdateTime(LocalDateTime.now());
                ppEProcessversion.setXprocess(processId);

                processversionServiceImpl.save(ppEProcessversion);
            }
        }

        //插入begin表
        BeginDTO beginDTO = modifyProcessOrAddProcessDTO.getBeginDTO();
        if(BeanUtil.isNotEmpty(beginDTO)){
            PpEBegin ppEBegin = BeanUtil.copyProperties(beginDTO, PpEBegin.class);
            beginServiceImpl.save(ppEBegin);
            String beginXid = ppEBegin.getXid();

            ArrayList<String> xreadDataPathLists = beginDTO.getXreadDataPathList();
            if(CollUtil.isNotEmpty(xreadDataPathLists)){
                List<PpEBeginReaddatapathlist> beginReaddatapathlists = new ArrayList<>();
                for (String xreadDataPathList : xreadDataPathLists) {
                    PpEBeginReaddatapathlist ppEBeginReaddatapathlist = new PpEBeginReaddatapathlist();
                    ppEBeginReaddatapathlist.setBeginXid(beginXid);
                    ppEBeginReaddatapathlist.setXreadDataPathList(xreadDataPathList);

                    beginReaddatapathlists.add(ppEBeginReaddatapathlist);
                }
                beginReaddatapathlistServiceImpl.saveBatch(beginReaddatapathlists);
            }


            ArrayList<String> xreadGroupLists = beginDTO.getXreadGroupList();
            if(CollUtil.isNotEmpty(xreadGroupLists)){
                List<PpEBeginReadgrouplist> beginReadgrouplists = new ArrayList<>();
                for (String xreadGroupList : xreadGroupLists) {
                    PpEBeginReadgrouplist ppEBeginReadgrouplist = new PpEBeginReadgrouplist();
                    ppEBeginReadgrouplist.setBeginXid(beginXid);
                    ppEBeginReadgrouplist.setXreadGroupList(xreadGroupList);

                    beginReadgrouplists.add(ppEBeginReadgrouplist);
                }
                beginReadgrouplistServiceImpl.saveBatch(beginReadgrouplists);
            }

            ArrayList<String> xreadUnitLists = beginDTO.getXreadUnitList();
            if(CollUtil.isNotEmpty(xreadUnitLists)){
                List<PpEBeginReadunitlist> beginReadunitlists = new ArrayList<>();
                for (String xreadUnitList : xreadUnitLists) {
                    PpEBeginReadunitlist ppEBeginReadunitlist = new PpEBeginReadunitlist();
                    ppEBeginReadunitlist.setBeginXid(beginXid);
                    ppEBeginReadunitlist.setXreadUnitList(xreadUnitList);

                    beginReadunitlists.add(ppEBeginReadunitlist);
                }
                beginReadunitlistServiceImpl.saveBatch(beginReadunitlists);
            }


            ArrayList<String> xreadIdentityLists = beginDTO.getXreadIdentityList();
            if(CollUtil.isNotEmpty(xreadIdentityLists)){
                List<PpEBeginReadidentitylist> beginReadidentitylists = new ArrayList<>();
                for (String xreadIdentityList : xreadIdentityLists) {
                    PpEBeginReadidentitylist ppEBeginReadidentitylist = new PpEBeginReadidentitylist();
                    ppEBeginReadidentitylist.setBeginXid(beginXid);
                    ppEBeginReadidentitylist.setXreadIdentityList(xreadIdentityList);

                    beginReadidentitylists.add(ppEBeginReadidentitylist);
                }
                beginReadidentitylistServiceImpl.saveBatch(beginReadidentitylists);
            }

            ArrayList<String> xreviewDataPathLists = beginDTO.getXreviewDataPathList();
            if(CollUtil.isNotEmpty(xreviewDataPathLists)){
                List<PpEBeginReviewdatapathlist> beginReviewdatapathlists = new ArrayList<>();
                for (String xreviewDataPathList : xreviewDataPathLists) {
                    PpEBeginReviewdatapathlist ppEBeginReviewdatapathlist = new PpEBeginReviewdatapathlist();
                    ppEBeginReviewdatapathlist.setBeginXid(beginXid);
                    ppEBeginReviewdatapathlist.setXreviewDataPathList(xreviewDataPathList);

                    beginReviewdatapathlists.add(ppEBeginReviewdatapathlist);
                }
                beginReviewdatapathlistServiceImpl.saveBatch(beginReviewdatapathlists);
            }

            ArrayList<String> xreviewGroupLists = beginDTO.getXreviewGroupList();
            if(CollUtil.isNotEmpty(xreviewGroupLists)){
                List<PpEBeginReviewgrouplist> beginReviewgrouplists = new ArrayList<>();
                for (String xreviewGroupList : xreviewGroupLists) {
                    PpEBeginReviewgrouplist ppEBeginReviewgrouplist = new PpEBeginReviewgrouplist();
                    ppEBeginReviewgrouplist.setBeginXid(beginXid);
                    ppEBeginReviewgrouplist.setXreviewGroupList(xreviewGroupList);

                    beginReviewgrouplists.add(ppEBeginReviewgrouplist);
                }
                beginReviewgrouplistServiceImpl.saveBatch(beginReviewgrouplists);
            }

            ArrayList<String> xreviewUnitLists = beginDTO.getXreviewUnitList();
            if(CollUtil.isNotEmpty(xreviewUnitLists)){
                List<PpEBeginReviewunitlist> beginReviewunitlists = new ArrayList<>();
                for (String xreviewUnitList : xreviewUnitLists) {
                    PpEBeginReviewunitlist ppEBeginReviewunitlist = new PpEBeginReviewunitlist();
                    ppEBeginReviewunitlist.setBeginXid(beginXid);
                    ppEBeginReviewunitlist.setXreviewUnitList(xreviewUnitList);

                    beginReviewunitlists.add(ppEBeginReviewunitlist);
                }
                beginReviewunitlistServiceImpl.saveBatch(beginReviewunitlists);
            }

            ArrayList<String> xreviewIdentityLists = beginDTO.getXreviewIdentityList();
            if(CollUtil.isNotEmpty(xreviewIdentityLists)){
                List<PpEBeginReviewidentitylist> beginReviewidentitylists = new ArrayList<>();
                for (String xreviewIdentityList : xreviewIdentityLists) {
                    PpEBeginReviewidentitylist ppEBeginReviewidentitylist = new PpEBeginReviewidentitylist();
                    ppEBeginReviewidentitylist.setBeginXid(beginXid);
                    ppEBeginReviewidentitylist.setXreviewIdentityList(xreviewIdentityList);

                    beginReviewidentitylists.add(ppEBeginReviewidentitylist);
                }
                beginReviewidentitylistServiceImpl.saveBatch(beginReviewidentitylists);
            }
        }

        //插入end表
        ArrayList<EndDTO> endList = modifyProcessOrAddProcessDTO.getEndList();
        EndDTO endDTO = endList.get(0);
        if(BeanUtil.isNotEmpty(endDTO)){
            PpEEnd ppEEnd = BeanUtil.copyProperties(endDTO, PpEEnd.class);
            endServiceImpl.save(ppEEnd);
            String endXid = ppEEnd.getXid();

            ArrayList<String> xreadDataPathLists = endDTO.getXreadDataPathList();
            if(CollUtil.isNotEmpty(xreadDataPathLists)){
                List<PpEEndReaddatapathlist> endReaddatapathlists = new ArrayList<>();
                for (String xreadDataPathList : xreadDataPathLists) {
                    PpEEndReaddatapathlist ppEEndReaddatapathlist = new PpEEndReaddatapathlist();
                    ppEEndReaddatapathlist.setEndXid(endXid);
                    ppEEndReaddatapathlist.setXreadDataPathList(xreadDataPathList);

                    endReaddatapathlists.add(ppEEndReaddatapathlist);
                }
                endReaddatapathlistServiceImpl.saveBatch(endReaddatapathlists);
            }


            ArrayList<String> xreadGroupLists = endDTO.getXreadGroupList();
            if(CollUtil.isNotEmpty(xreadGroupLists)){
                List<PpEEndReadgrouplist> endReadgrouplists = new ArrayList<>();
                for (String xreadGroupList : xreadGroupLists) {
                    PpEEndReadgrouplist ppEEndReadgrouplist = new PpEEndReadgrouplist();
                    ppEEndReadgrouplist.setEndXid(endXid);
                    ppEEndReadgrouplist.setXreadGroupList(xreadGroupList);

                    endReadgrouplists.add(ppEEndReadgrouplist);
                }
                endReadgrouplistServiceImpl.saveBatch(endReadgrouplists);
            }

            ArrayList<String> xreadUnitLists = endDTO.getXreadUnitList();
            if(CollUtil.isNotEmpty(xreadUnitLists)){
                List<PpEEndReadunitlist> endReadunitlists = new ArrayList<>();
                for (String xreadUnitList : xreadUnitLists) {
                    PpEEndReadunitlist ppEEndReadunitlist = new PpEEndReadunitlist();
                    ppEEndReadunitlist.setEndXid(endXid);
                    ppEEndReadunitlist.setXreadUnitList(xreadUnitList);

                   endReadunitlists.add(ppEEndReadunitlist);
                }
                endReadunitlistServiceImpl.saveBatch(endReadunitlists);
            }


            ArrayList<String> xreadIdentityLists = endDTO.getXreadIdentityList();
            if(CollUtil.isNotEmpty(xreadIdentityLists)){
                List<PpEEndReadidentitylist> endReadidentitylists = new ArrayList<>();
                for (String xreadIdentityList : xreadIdentityLists) {
                    PpEEndReadidentitylist ppEEndReadidentitylist = new PpEEndReadidentitylist();
                    ppEEndReadidentitylist.setEndXid(endXid);
                    ppEEndReadidentitylist.setXreadIdentityList(xreadIdentityList);

                    endReadidentitylists.add(ppEEndReadidentitylist);
                }
                endReadidentitylistServiceImpl.saveBatch(endReadidentitylists);
            }

            ArrayList<String> xreviewDataPathLists = endDTO.getXreviewDataPathList();
            if(CollUtil.isNotEmpty(xreviewDataPathLists)){
                List<PpEEndReviewdatapathlist> endReviewdatapathlists = new ArrayList<>();
                for (String xreviewDataPathList : xreviewDataPathLists) {
                    PpEEndReviewdatapathlist ppEEndReviewdatapathlist = new PpEEndReviewdatapathlist();
                    ppEEndReviewdatapathlist.setEndXid(endXid);
                    ppEEndReviewdatapathlist.setXreviewDataPathList(xreviewDataPathList);

                    endReviewdatapathlists.add(ppEEndReviewdatapathlist);
                }
                endReviewdatapathlistServiceImpl.saveBatch(endReviewdatapathlists);
            }

            ArrayList<String> xreviewGroupLists = endDTO.getXreviewGroupList();
            if(CollUtil.isNotEmpty(xreviewGroupLists)){
                List<PpEEndReviewgrouplist> endReviewgrouplists = new ArrayList<>();
                for (String xreviewGroupList : xreviewGroupLists) {
                    PpEEndReviewgrouplist ppEEndReviewgrouplist = new PpEEndReviewgrouplist();
                    ppEEndReviewgrouplist.setEndXid(endXid);
                    ppEEndReviewgrouplist.setXreviewGroupList(xreviewGroupList);

                    endReviewgrouplists.add(ppEEndReviewgrouplist);
                }
                endReviewgrouplistServiceImpl.saveBatch(endReviewgrouplists);
            }

            ArrayList<String> xreviewUnitLists = endDTO.getXreviewUnitList();
            if(CollUtil.isNotEmpty(xreviewUnitLists)){
                List<PpEEndReviewunitlist> endReviewunitlists = new ArrayList<>();
                for (String xreviewUnitList : xreviewUnitLists) {
                    PpEEndReviewunitlist ppEEndReviewunitlist = new PpEEndReviewunitlist();
                    ppEEndReviewunitlist.setEndXid(endXid);
                    ppEEndReviewunitlist.setXreviewUnitList(xreviewUnitList);

                    endReviewunitlists.add(ppEEndReviewunitlist);
                }
                endReviewunitlistServiceImpl.saveBatch(endReviewunitlists);
            }

            ArrayList<String> xreviewIdentityLists = endDTO.getXreviewIdentityList();
            if(CollUtil.isNotEmpty(xreviewIdentityLists)){
                List<PpEEndReviewidentitylist> endReviewidentitylists = new ArrayList<>();
                for (String xreviewIdentityList : xreviewIdentityLists) {
                    PpEEndReviewidentitylist ppEEndReviewidentitylist = new PpEEndReviewidentitylist();
                    ppEEndReviewidentitylist.setEndXid(endXid);
                    ppEEndReviewidentitylist.setXreviewIdentityList(xreviewIdentityList);

                    endReviewidentitylists.add(ppEEndReviewidentitylist);
                }
                endReviewidentitylistServiceImpl.saveBatch(endReviewidentitylists);
            }
        }

        //插入cancel表
        ArrayList<CancelDTO> cancelList = modifyProcessOrAddProcessDTO.getCancelList();
        CancelDTO cancelDTO = cancelList.get(0);
        if(BeanUtil.isNotEmpty(cancelDTO)){
            PpECancel ppECancel = BeanUtil.copyProperties(cancelDTO, PpECancel.class);
            cancelServiceImpl.save(ppECancel);
            String cancelXid = ppECancel.getXid();

            ArrayList<String> xreadDataPathLists = cancelDTO.getXreadDataPathList();
            if(CollUtil.isNotEmpty(xreadDataPathLists)){
                List<PpECancelReaddatapathlist> cancelReaddatapathlists = new ArrayList<>();
                for (String xreadDataPathList : xreadDataPathLists) {
                    PpECancelReaddatapathlist ppECancelReaddatapathlist = new PpECancelReaddatapathlist();
                    ppECancelReaddatapathlist.setCancelXid(cancelXid);
                    ppECancelReaddatapathlist.setXreadDataPathList(xreadDataPathList);

                    cancelReaddatapathlists.add(ppECancelReaddatapathlist);
                }
                cancelReaddatapathlistServiceImpl.saveBatch(cancelReaddatapathlists);
            }


            ArrayList<String> xreadGroupLists = cancelDTO.getXreadGroupList();
            if(CollUtil.isNotEmpty(xreadGroupLists)){
                List<PpECancelReadgrouplist> cancelReadgrouplists = new ArrayList<>();
                for (String xreadGroupList : xreadGroupLists) {
                    PpECancelReadgrouplist ppECancelReadgrouplist = new PpECancelReadgrouplist();
                    ppECancelReadgrouplist.setCancelXid(cancelXid);
                    ppECancelReadgrouplist.setXreadGroupList(xreadGroupList);

                    cancelReadgrouplists.add(ppECancelReadgrouplist);
                }
                cancelReadgrouplistServiceImpl.saveBatch(cancelReadgrouplists);
            }

            ArrayList<String> xreadUnitLists = cancelDTO.getXreadUnitList();
            if(CollUtil.isNotEmpty(xreadUnitLists)){
                List<PpECancelReadunitlist> cancelReadunitlists = new ArrayList<>();
                for (String xreadUnitList : xreadUnitLists) {
                    PpECancelReadunitlist ppECancelReadunitlist = new PpECancelReadunitlist();
                    ppECancelReadunitlist.setCancelXid(cancelXid);
                    ppECancelReadunitlist.setXreadUnitList(xreadUnitList);

                    cancelReadunitlists.add(ppECancelReadunitlist);
                }
                cancelReadunitlistServiceImpl.saveBatch(cancelReadunitlists);
            }


            ArrayList<String> xreadIdentityLists = cancelDTO.getXreadIdentityList();
            if(CollUtil.isNotEmpty(xreadIdentityLists)){
                List<PpECancelReadidentitylist> cancelReadidentitylists = new ArrayList<>();
                for (String xreadIdentityList : xreadIdentityLists) {
                    PpECancelReadidentitylist ppECancelReadidentitylist = new PpECancelReadidentitylist();
                    ppECancelReadidentitylist.setCancelXid(cancelXid);
                    ppECancelReadidentitylist.setXreadIdentityList(xreadIdentityList);

                    cancelReadidentitylists.add(ppECancelReadidentitylist);
                }
                cancelReadidentitylistServiceImpl.saveBatch(cancelReadidentitylists);
            }

            ArrayList<String> xreviewDataPathLists = cancelDTO.getXreviewDataPathList();
            if(CollUtil.isNotEmpty(xreviewDataPathLists)){
                List<PpECancelReviewdatapathlist> cancelReviewdatapathlists = new ArrayList<>();
                for (String xreviewDataPathList : xreviewDataPathLists) {
                    PpECancelReviewdatapathlist ppECancelReviewdatapathlist = new PpECancelReviewdatapathlist();
                    ppECancelReviewdatapathlist.setCancelXid(cancelXid);
                    ppECancelReviewdatapathlist.setXreviewDataPathList(xreviewDataPathList);

                    cancelReviewdatapathlists.add(ppECancelReviewdatapathlist);
                }
                cancelReviewdatapathlistServiceImpl.saveBatch(cancelReviewdatapathlists);
            }

            ArrayList<String> xreviewGroupLists = cancelDTO.getXreviewGroupList();
            if(CollUtil.isNotEmpty(xreviewGroupLists)){
                List<PpECancelReviewgrouplist> cancelReviewgrouplists = new ArrayList<>();
                for (String xreviewGroupList : xreviewGroupLists) {
                    PpECancelReviewgrouplist ppECancelReviewgrouplist = new PpECancelReviewgrouplist();
                    ppECancelReviewgrouplist.setCancelXid(cancelXid);
                    ppECancelReviewgrouplist.setXreviewGroupList(xreviewGroupList);

                    cancelReviewgrouplists.add(ppECancelReviewgrouplist);
                }
                cancelReviewgrouplistServiceImpl.saveBatch(cancelReviewgrouplists);
            }

            ArrayList<String> xreviewUnitLists = cancelDTO.getXreviewUnitList();
            if(CollUtil.isNotEmpty(xreviewUnitLists)){
                List<PpECancelReviewunitlist> cancelReviewunitlists = new ArrayList<>();
                for (String xreviewUnitList : xreviewUnitLists) {
                    PpECancelReviewunitlist ppECancelReviewunitlist = new PpECancelReviewunitlist();
                    ppECancelReviewunitlist.setCancelXid(cancelXid);
                    ppECancelReviewunitlist.setXreviewUnitList(xreviewUnitList);

                    cancelReviewunitlists.add(ppECancelReviewunitlist);
                }
                cancelReviewunitlistServiceImpl.saveBatch(cancelReviewunitlists);
            }

            ArrayList<String> xreviewIdentityLists = cancelDTO.getXreviewIdentityList();
            if(CollUtil.isNotEmpty(xreviewIdentityLists)){
                List<PpECancelReviewidentitylist> cancelReviewidentitylists = new ArrayList<>();
                for (String xreviewIdentityList : xreviewIdentityLists) {
                    PpECancelReviewidentitylist ppECancelReviewidentitylist = new PpECancelReviewidentitylist();
                    ppECancelReviewidentitylist.setCancelXid(cancelXid);
                    ppECancelReviewidentitylist.setXreviewIdentityList(xreviewIdentityList);

                    cancelReviewidentitylists.add(ppECancelReviewidentitylist);
                }
                cancelReviewidentitylistServiceImpl.saveBatch(cancelReviewidentitylists);
            }
        }

        //插入choice表
        ArrayList<ChoiceDTO> choiceList = modifyProcessOrAddProcessDTO.getChoiceList();
        ChoiceDTO choiceDTO = choiceList.get(0);
        if(BeanUtil.isNotEmpty(choiceDTO)){
            PpEChoice ppEChoice = BeanUtil.copyProperties(choiceDTO, PpEChoice.class);
            choiceServiceImpl.save(ppEChoice);
            String choiceXid = ppEChoice.getXid();

            ArrayList<String> xreadDataPathLists = choiceDTO.getXreadDataPathList();
            if(CollUtil.isNotEmpty(xreadDataPathLists)){
                List<PpEChoiceReaddatapathlist> choiceReaddatapathlists = new ArrayList<>();
                for (String xreadDataPathList : xreadDataPathLists) {
                    PpEChoiceReaddatapathlist ppEChoiceReaddatapathlist = new PpEChoiceReaddatapathlist();
                    ppEChoiceReaddatapathlist.setChoiceXid(choiceXid);
                    ppEChoiceReaddatapathlist.setXreadDataPathList(xreadDataPathList);

                    choiceReaddatapathlists.add(ppEChoiceReaddatapathlist);
                }
                choiceReaddatapathlistServiceImpl.saveBatch(choiceReaddatapathlists);
            }


            ArrayList<String> xreadGroupLists = choiceDTO.getXreadGroupList();
            if(CollUtil.isNotEmpty(xreadGroupLists)){
                List<PpEChoiceReadgrouplist> choiceReadgrouplists = new ArrayList<>();
                for (String xreadGroupList : xreadGroupLists) {
                    PpEChoiceReadgrouplist ppEChoiceReadgrouplist = new PpEChoiceReadgrouplist();
                    ppEChoiceReadgrouplist.setChoiceXid(choiceXid);
                    ppEChoiceReadgrouplist.setXreadGroupList(xreadGroupList);

                    choiceReadgrouplists.add(ppEChoiceReadgrouplist);
                }
                choiceReadgrouplistServiceImpl.saveBatch(choiceReadgrouplists);
            }

            ArrayList<String> xreadUnitLists = choiceDTO.getXreadUnitList();
            if(CollUtil.isNotEmpty(xreadUnitLists)){
                List<PpEChoiceReadunitlist> choiceReadunitlists = new ArrayList<>();
                for (String xreadUnitList : xreadUnitLists) {
                    PpEChoiceReadunitlist ppEChoiceReadunitlist = new PpEChoiceReadunitlist();
                    ppEChoiceReadunitlist.setChoiceXid(choiceXid);
                    ppEChoiceReadunitlist.setXreadUnitList(xreadUnitList);

                    choiceReadunitlists.add(ppEChoiceReadunitlist);
                }
                choiceReadunitlistServiceImpl.saveBatch(choiceReadunitlists);
            }


            ArrayList<String> xreadIdentityLists = choiceDTO.getXreadIdentityList();
            if(CollUtil.isNotEmpty(xreadIdentityLists)){
                List<PpEChoiceReadidentitylist> choiceReadidentitylists = new ArrayList<>();
                for (String xreadIdentityList : xreadIdentityLists) {
                    PpEChoiceReadidentitylist ppEChoiceReadidentitylist = new PpEChoiceReadidentitylist();
                    ppEChoiceReadidentitylist.setChoiceXid(choiceXid);
                    ppEChoiceReadidentitylist.setXreadIdentityList(xreadIdentityList);

                    choiceReadidentitylists.add(ppEChoiceReadidentitylist);
                }
                choiceReadidentitylistServiceImpl.saveBatch(choiceReadidentitylists);
            }

            ArrayList<String> xreviewDataPathLists = choiceDTO.getXreviewDataPathList();
            if(CollUtil.isNotEmpty(xreviewDataPathLists)){
                List<PpEChoiceReviewdatapathlist> choiceReviewdatapathlists = new ArrayList<>();
                for (String xreviewDataPathList : xreviewDataPathLists) {
                    PpEChoiceReviewdatapathlist ppEChoiceReviewdatapathlist = new PpEChoiceReviewdatapathlist();
                    ppEChoiceReviewdatapathlist.setChoiceXid(choiceXid);
                    ppEChoiceReviewdatapathlist.setXreviewDataPathList(xreviewDataPathList);

                    choiceReviewdatapathlists.add(ppEChoiceReviewdatapathlist);
                }
                choiceReviewdatapathlistServiceImpl.saveBatch(choiceReviewdatapathlists);
            }

            ArrayList<String> xreviewGroupLists = choiceDTO.getXreviewGroupList();
            if(CollUtil.isNotEmpty(xreviewGroupLists)){
                List<PpEChoiceReviewgrouplist> choiceReviewgrouplists = new ArrayList<>();
                for (String xreviewGroupList : xreviewGroupLists) {
                    PpEChoiceReviewgrouplist ppEChoiceReviewgrouplist = new PpEChoiceReviewgrouplist();
                    ppEChoiceReviewgrouplist.setChoiceXid(choiceXid);
                    ppEChoiceReviewgrouplist.setXreviewGroupList(xreviewGroupList);

                    choiceReviewgrouplists.add(ppEChoiceReviewgrouplist);
                }
                choiceReviewgrouplistServiceImpl.saveBatch(choiceReviewgrouplists);
            }

            ArrayList<String> xreviewUnitLists = choiceDTO.getXreviewUnitList();
            if(CollUtil.isNotEmpty(xreviewUnitLists)){
                List<PpEChoiceReviewunitlist> choiceReviewunitlists = new ArrayList<>();
                for (String xreviewUnitList : xreviewUnitLists) {
                    PpEChoiceReviewunitlist ppEChoiceReviewunitlist = new PpEChoiceReviewunitlist();
                    ppEChoiceReviewunitlist.setChoiceXid(choiceXid);
                    ppEChoiceReviewunitlist.setXreviewUnitList(xreviewUnitList);

                    choiceReviewunitlists.add(ppEChoiceReviewunitlist);
                }
                choiceReviewunitlistServiceImpl.saveBatch(choiceReviewunitlists);
            }

            ArrayList<String> xreviewIdentityLists = choiceDTO.getXreviewIdentityList();
            if(CollUtil.isNotEmpty(xreviewIdentityLists)){
                List<PpEChoiceReviewidentitylist> choiceReviewidentitylists = new ArrayList<>();
                for (String xreviewIdentityList : xreviewIdentityLists) {
                    PpEChoiceReviewidentitylist ppEChoiceReviewidentitylist = new PpEChoiceReviewidentitylist();
                    ppEChoiceReviewidentitylist.setChoiceXid(choiceXid);
                    ppEChoiceReviewidentitylist.setXreviewIdentityList(xreviewIdentityList);

                    choiceReviewidentitylists.add(ppEChoiceReviewidentitylist);
                }
                choiceReviewidentitylistServiceImpl.saveBatch(choiceReviewidentitylists);
            }

            ArrayList<String> xrouteLists = choiceDTO.getXrouteList();
            if(CollUtil.isNotEmpty(xrouteLists)){
                List<PpEChoiceRoutelist> choiceRoutelists = new ArrayList<>();
                for (String xrouteList : xrouteLists) {
                    PpEChoiceRoutelist ppEChoiceRoutelist = new PpEChoiceRoutelist();
                    ppEChoiceRoutelist.setChoiceXid(choiceXid);
                    ppEChoiceRoutelist.setXrouteList(xrouteList);

                    choiceRoutelists.add(ppEChoiceRoutelist);
                }
                choiceRoutelistServiceImpl.saveBatch(choiceRoutelists);
            }
        }

        //插入split表
        ArrayList<SplitDTO> splitList = modifyProcessOrAddProcessDTO.getSplitList();
        SplitDTO splitDTO = splitList.get(0);
        if(BeanUtil.isNotEmpty(splitDTO)){
            PpESplit ppESplit = BeanUtil.copyProperties(splitDTO, PpESplit.class);
            splitServiceImpl.save(ppESplit);
            String splitXid = ppESplit.getXid();

            ArrayList<String> xreadDataPathLists = splitDTO.getXreadDataPathList();
            if(CollUtil.isNotEmpty(xreadDataPathLists)){
                List<PpESplitReaddatapathlist> splitReaddatapathlists = new ArrayList<>();
                for (String xreadDataPathList : xreadDataPathLists) {
                    PpESplitReaddatapathlist ppESplitReaddatapathlist = new PpESplitReaddatapathlist();
                    ppESplitReaddatapathlist.setSplitXid(splitXid);
                    ppESplitReaddatapathlist.setXreadDataPathList(xreadDataPathList);

                    splitReaddatapathlists.add(ppESplitReaddatapathlist);
                }
                splitReaddatapathlistServiceImpl.saveBatch(splitReaddatapathlists);
            }


            ArrayList<String> xreadGroupLists = splitDTO.getXreadGroupList();
            if(CollUtil.isNotEmpty(xreadGroupLists)){
                List<PpESplitReadgrouplist> splitReadgrouplists = new ArrayList<>();
                for (String xreadGroupList : xreadGroupLists) {
                    PpESplitReadgrouplist ppESplitReadgrouplist = new PpESplitReadgrouplist();
                    ppESplitReadgrouplist.setSplitXid(splitXid);
                    ppESplitReadgrouplist.setXreadGroupList(xreadGroupList);

                    splitReadgrouplists.add(ppESplitReadgrouplist);
                }
                splitReadgrouplistServiceImpl.saveBatch(splitReadgrouplists);
            }

            ArrayList<String> xreadUnitLists = splitDTO.getXreadUnitList();
            if(CollUtil.isNotEmpty(xreadUnitLists)){
                List<PpESplitReadunitlist> splitReadunitlists = new ArrayList<>();
                for (String xreadUnitList : xreadUnitLists) {
                    PpESplitReadunitlist ppESplitReadunitlist = new PpESplitReadunitlist();
                    ppESplitReadunitlist.setSplitXid(splitXid);
                    ppESplitReadunitlist.setXreadUnitList(xreadUnitList);

                    splitReadunitlists.add(ppESplitReadunitlist);
                }
                splitReadunitlistServiceImpl.saveBatch(splitReadunitlists);
            }


            ArrayList<String> xreadIdentityLists = splitDTO.getXreadIdentityList();
            if(CollUtil.isNotEmpty(xreadIdentityLists)){
                List<PpESplitReadidentitylist> splitReadidentitylists = new ArrayList<>();
                for (String xreadIdentityList : xreadIdentityLists) {
                    PpESplitReadidentitylist ppESplitReadidentitylist = new PpESplitReadidentitylist();
                    ppESplitReadidentitylist.setSplitXid(splitXid);
                    ppESplitReadidentitylist.setXreadIdentityList(xreadIdentityList);

                    splitReadidentitylists.add(ppESplitReadidentitylist);
                }
                splitReadidentitylistServiceImpl.saveBatch(splitReadidentitylists);
            }

            ArrayList<String> xreviewDataPathLists = splitDTO.getXreviewDataPathList();
            if(CollUtil.isNotEmpty(xreviewDataPathLists)){
                List<PpESplitReviewdatapathlist> splitReviewdatapathlists = new ArrayList<>();
                for (String xreviewDataPathList : xreviewDataPathLists) {
                    PpESplitReviewdatapathlist ppESplitReviewdatapathlist = new PpESplitReviewdatapathlist();
                    ppESplitReviewdatapathlist.setSplitXid(splitXid);
                    ppESplitReviewdatapathlist.setXreviewDataPathList(xreviewDataPathList);

                    splitReviewdatapathlists.add(ppESplitReviewdatapathlist);
                }
                splitReviewdatapathlistServiceImpl.saveBatch(splitReviewdatapathlists);
            }

            ArrayList<String> xreviewGroupLists = splitDTO.getXreviewGroupList();
            if(CollUtil.isNotEmpty(xreviewGroupLists)){
                List<PpESplitReviewgrouplist> splitReviewgrouplists = new ArrayList<>();
                for (String xreviewGroupList : xreviewGroupLists) {
                    PpESplitReviewgrouplist ppESplitReviewgrouplist = new PpESplitReviewgrouplist();
                    ppESplitReviewgrouplist.setSplitXid(splitXid);
                    ppESplitReviewgrouplist.setXreviewGroupList(xreviewGroupList);

                    splitReviewgrouplists.add(ppESplitReviewgrouplist);
                }
                splitReviewgrouplistServiceImpl.saveBatch(splitReviewgrouplists);
            }

            ArrayList<String> xreviewUnitLists = splitDTO.getXreviewUnitList();
            if(CollUtil.isNotEmpty(xreviewUnitLists)){
                List<PpESplitReviewunitlist> splitReviewunitlists = new ArrayList<>();
                for (String xreviewUnitList : xreviewUnitLists) {
                    PpESplitReviewunitlist ppESplitReviewunitlist = new PpESplitReviewunitlist();
                    ppESplitReviewunitlist.setSplitXid(splitXid);
                    ppESplitReviewunitlist.setXreviewUnitList(xreviewUnitList);

                    splitReviewunitlists.add(ppESplitReviewunitlist);
                }
                splitReviewunitlistServiceImpl.saveBatch(splitReviewunitlists);
            }

            ArrayList<String> xreviewIdentityLists = splitDTO.getXreviewIdentityList();
            if(CollUtil.isNotEmpty(xreviewIdentityLists)){
                List<PpESplitReviewidentitylist> splitReviewidentitylists = new ArrayList<>();
                for (String xreviewIdentityList : xreviewIdentityLists) {
                    PpESplitReviewidentitylist ppESplitReviewidentitylist = new PpESplitReviewidentitylist();
                    ppESplitReviewidentitylist.setSplitXid(splitXid);
                    ppESplitReviewidentitylist.setXreviewIdentityList(xreviewIdentityList);

                    splitReviewidentitylists.add(ppESplitReviewidentitylist);
                }
                splitReviewidentitylistServiceImpl.saveBatch(splitReviewidentitylists);
            }
        }

        //插入parallel表
        ArrayList<ParallelDTO> parallelList = modifyProcessOrAddProcessDTO.getParallelList();
        ParallelDTO parallelDTO = parallelList.get(0);
        if(BeanUtil.isNotEmpty(parallelDTO)){
            PpEParallel ppEParallel = BeanUtil.copyProperties(parallelDTO, PpEParallel.class);
            parallelServiceImpl.save(ppEParallel);
            String parallelXid = ppEParallel.getXid();

            ArrayList<String> xreadDataPathLists = parallelDTO.getXreadDataPathList();
            if(CollUtil.isNotEmpty(xreadDataPathLists)){
                List<PpEParallelReaddatapathlist> parallelReaddatapathlists = new ArrayList<>();
                for (String xreadDataPathList : xreadDataPathLists) {
                    PpEParallelReaddatapathlist ppEParallelReaddatapathlist = new PpEParallelReaddatapathlist();
                    ppEParallelReaddatapathlist.setParallelXid(parallelXid);
                    ppEParallelReaddatapathlist.setXreadDataPathList(xreadDataPathList);

                    parallelReaddatapathlists.add(ppEParallelReaddatapathlist);
                }
                parallelReaddatapathlistServiceImpl.saveBatch(parallelReaddatapathlists);
            }


            ArrayList<String> xreadGroupLists = parallelDTO.getXreadGroupList();
            if(CollUtil.isNotEmpty(xreadGroupLists)){
                List<PpEParallelReadgrouplist> parallelReadgrouplists = new ArrayList<>();
                for (String xreadGroupList : xreadGroupLists) {
                    PpEParallelReadgrouplist ppEParallelReadgrouplist = new PpEParallelReadgrouplist();
                    ppEParallelReadgrouplist.setParallelXid(parallelXid);
                    ppEParallelReadgrouplist.setXreadGroupList(xreadGroupList);

                    parallelReadgrouplists.add(ppEParallelReadgrouplist);
                }
                parallelReadgrouplistServiceImpl.saveBatch(parallelReadgrouplists);
            }

            ArrayList<String> xreadUnitLists = parallelDTO.getXreadUnitList();
            if(CollUtil.isNotEmpty(xreadUnitLists)){
                List<PpEParallelReadunitlist> parallelReadunitlists = new ArrayList<>();
                for (String xreadUnitList : xreadUnitLists) {
                    PpEParallelReadunitlist ppEParallelReadunitlist = new PpEParallelReadunitlist();
                    ppEParallelReadunitlist.setParallelXid(parallelXid);
                    ppEParallelReadunitlist.setXreadUnitList(xreadUnitList);

                    parallelReadunitlists.add(ppEParallelReadunitlist);
                }
                parallelReadunitlistServiceImpl.saveBatch(parallelReadunitlists);
            }


            ArrayList<String> xreadIdentityLists = parallelDTO.getXreadIdentityList();
            if(CollUtil.isNotEmpty(xreadIdentityLists)){
                List<PpEParallelReadidentitylist> parallelReadidentitylists = new ArrayList<>();
                for (String xreadIdentityList : xreadIdentityLists) {
                    PpEParallelReadidentitylist ppEParallelReadidentitylist = new PpEParallelReadidentitylist();
                    ppEParallelReadidentitylist.setParallelXid(parallelXid);
                    ppEParallelReadidentitylist.setXreadIdentityList(xreadIdentityList);

                    parallelReadidentitylists.add(ppEParallelReadidentitylist);
                }
                parallelReadidentitylistServiceImpl.saveBatch(parallelReadidentitylists);
            }

            ArrayList<String> xreviewDataPathLists = parallelDTO.getXreviewDataPathList();
            if(CollUtil.isNotEmpty(xreviewDataPathLists)){
                List<PpEParallelReviewdatapathlist> parallelReviewdatapathlists = new ArrayList<>();
                for (String xreviewDataPathList : xreviewDataPathLists) {
                    PpEParallelReviewdatapathlist ppEParallelReviewdatapathlist = new PpEParallelReviewdatapathlist();
                    ppEParallelReviewdatapathlist.setParallelXid(parallelXid);
                    ppEParallelReviewdatapathlist.setXreviewDataPathList(xreviewDataPathList);

                    parallelReviewdatapathlists.add(ppEParallelReviewdatapathlist);
                }
                parallelReviewdatapathlistServiceImpl.saveBatch(parallelReviewdatapathlists);
            }

            ArrayList<String> xreviewGroupLists = parallelDTO.getXreviewGroupList();
            if(CollUtil.isNotEmpty(xreviewGroupLists)){
                List<PpEParallelReviewgrouplist> parallelReviewgrouplists = new ArrayList<>();
                for (String xreviewGroupList : xreviewGroupLists) {
                    PpEParallelReviewgrouplist ppEParallelReviewgrouplist = new PpEParallelReviewgrouplist();
                    ppEParallelReviewgrouplist.setParallelXid(parallelXid);
                    ppEParallelReviewgrouplist.setXreviewGroupList(xreviewGroupList);

                    parallelReviewgrouplists.add(ppEParallelReviewgrouplist);
                }
                parallelReviewgrouplistServiceImpl.saveBatch(parallelReviewgrouplists);
            }

            ArrayList<String> xreviewUnitLists = parallelDTO.getXreviewUnitList();
            if(CollUtil.isNotEmpty(xreviewUnitLists)){
                List<PpEParallelReviewunitlist> parallelReviewunitlists = new ArrayList<>();
                for (String xreviewUnitList : xreviewUnitLists) {
                    PpEParallelReviewunitlist ppEParallelReviewunitlist = new PpEParallelReviewunitlist();
                    ppEParallelReviewunitlist.setParallelXid(parallelXid);
                    ppEParallelReviewunitlist.setXreviewUnitList(xreviewUnitList);

                    parallelReviewunitlists.add(ppEParallelReviewunitlist);
                }
                parallelReviewunitlistServiceImpl.saveBatch(parallelReviewunitlists);
            }

            ArrayList<String> xreviewIdentityLists = parallelDTO.getXreviewIdentityList();
            if(CollUtil.isNotEmpty(xreviewIdentityLists)){
                List<PpEParallelReviewidentitylist> parallelReviewidentitylists = new ArrayList<>();
                for (String xreviewIdentityList : xreviewIdentityLists) {
                    PpEParallelReviewidentitylist ppEParallelReviewidentitylist = new PpEParallelReviewidentitylist();
                    ppEParallelReviewidentitylist.setParallelXid(parallelXid);
                    ppEParallelReviewidentitylist.setXreviewIdentityList(xreviewIdentityList);

                    parallelReviewidentitylists.add(ppEParallelReviewidentitylist);
                }
                parallelReviewidentitylistServiceImpl.saveBatch(parallelReviewidentitylists);
            }

            ArrayList<String> xrouteLists = parallelDTO.getXrouteList();
            if(CollUtil.isNotEmpty(xrouteLists)){
                List<PpEParallelRoutelist> parallelRoutelists = new ArrayList<>();
                for (String xrouteList : xrouteLists) {
                    PpEParallelRoutelist ppEParallelRoutelist = new PpEParallelRoutelist();
                    ppEParallelRoutelist.setParallelXid(parallelXid);
                    ppEParallelRoutelist.setXrouteList(xrouteList);

                    parallelRoutelists.add(ppEParallelRoutelist);
                }
                parallelRoutelistServiceImpl.saveBatch(parallelRoutelists);
            }
        }

        //插入merge表
        ArrayList<MergeDTO> mergeList = modifyProcessOrAddProcessDTO.getMergeList();
        MergeDTO mergeDTO = mergeList.get(0);
        if(BeanUtil.isNotEmpty(mergeDTO)){
            PpEMerge ppEMerge = BeanUtil.copyProperties(mergeDTO, PpEMerge.class);
            mergeServiceImpl.save(ppEMerge);
            String mergeXid = ppEMerge.getXid();

            ArrayList<String> xreadDataPathLists = mergeDTO.getXreadDataPathList();
            if(CollUtil.isNotEmpty(xreadDataPathLists)){
                List<PpEMergeReaddatapathlist> mergeReaddatapathlists = new ArrayList<>();
                for (String xreadDataPathList : xreadDataPathLists) {
                    PpEMergeReaddatapathlist ppEMergeReaddatapathlist = new PpEMergeReaddatapathlist();
                    ppEMergeReaddatapathlist.setMergeXid(mergeXid);
                    ppEMergeReaddatapathlist.setXreadDataPathList(xreadDataPathList);

                    mergeReaddatapathlists.add(ppEMergeReaddatapathlist);
                }
                mergeReaddatapathlistServiceImpl.saveBatch(mergeReaddatapathlists);
            }


            ArrayList<String> xreadGroupLists = mergeDTO.getXreadGroupList();
            if(CollUtil.isNotEmpty(xreadGroupLists)){
                List<PpEMergeReadgrouplist> mergeReadgrouplists = new ArrayList<>();
                for (String xreadGroupList : xreadGroupLists) {
                    PpEMergeReadgrouplist ppEMergeReadgrouplist = new PpEMergeReadgrouplist();
                    ppEMergeReadgrouplist.setMergeXid(mergeXid);
                    ppEMergeReadgrouplist.setXreadGroupList(xreadGroupList);

                    mergeReadgrouplists.add(ppEMergeReadgrouplist);
                }
                mergeReadgrouplistServiceImpl.saveBatch(mergeReadgrouplists);
            }

            ArrayList<String> xreadUnitLists = mergeDTO.getXreadUnitList();
            if(CollUtil.isNotEmpty(xreadUnitLists)){
                List<PpEMergeReadunitlist> mergeReadunitlists = new ArrayList<>();
                for (String xreadUnitList : xreadUnitLists) {
                    PpEMergeReadunitlist ppEMergeReadunitlist = new PpEMergeReadunitlist();
                    ppEMergeReadunitlist.setMergeXid(mergeXid);
                    ppEMergeReadunitlist.setXreadUnitList(xreadUnitList);

                    mergeReadunitlists.add(ppEMergeReadunitlist);
                }
                mergeReadunitlistServiceImpl.saveBatch(mergeReadunitlists);
            }


            ArrayList<String> xreadIdentityLists = mergeDTO.getXreadIdentityList();
            if(CollUtil.isNotEmpty(xreadIdentityLists)){
                List<PpEMergeReadidentitylist> mergeReadidentitylists = new ArrayList<>();
                for (String xreadIdentityList : xreadIdentityLists) {
                    PpEMergeReadidentitylist ppEMergeReadidentitylist = new PpEMergeReadidentitylist();
                    ppEMergeReadidentitylist.setMergeXid(mergeXid);
                    ppEMergeReadidentitylist.setXreadIdentityList(xreadIdentityList);

                    mergeReadidentitylists.add(ppEMergeReadidentitylist);
                }
                mergeReadidentitylistServiceImpl.saveBatch(mergeReadidentitylists);
            }

            ArrayList<String> xreviewDataPathLists = mergeDTO.getXreviewDataPathList();
            if(CollUtil.isNotEmpty(xreviewDataPathLists)){
                List<PpEMergeReviewdatapathlist> mergeReviewdatapathlists = new ArrayList<>();
                for (String xreviewDataPathList : xreviewDataPathLists) {
                    PpEMergeReviewdatapathlist ppEMergeReviewdatapathlist = new PpEMergeReviewdatapathlist();
                    ppEMergeReviewdatapathlist.setMergeXid(mergeXid);
                    ppEMergeReviewdatapathlist.setXreviewDataPathList(xreviewDataPathList);

                    mergeReviewdatapathlists.add(ppEMergeReviewdatapathlist);
                }
                mergeReviewdatapathlistServiceImpl.saveBatch(mergeReviewdatapathlists);
            }

            ArrayList<String> xreviewGroupLists = mergeDTO.getXreviewGroupList();
            if(CollUtil.isNotEmpty(xreviewGroupLists)){
                List<PpEMergeReviewgrouplist> mergeReviewgrouplists = new ArrayList<>();
                for (String xreviewGroupList : xreviewGroupLists) {
                    PpEMergeReviewgrouplist ppEMergeReviewgrouplist = new PpEMergeReviewgrouplist();
                    ppEMergeReviewgrouplist.setMergeXid(mergeXid);
                    ppEMergeReviewgrouplist.setXreviewGroupList(xreviewGroupList);

                    mergeReviewgrouplists.add(ppEMergeReviewgrouplist);
                }
                mergeReviewgrouplistServiceImpl.saveBatch(mergeReviewgrouplists);
            }

            ArrayList<String> xreviewUnitLists = mergeDTO.getXreviewUnitList();
            if(CollUtil.isNotEmpty(xreviewUnitLists)){
                List<PpEMergeReviewunitlist> mergeReviewunitlists = new ArrayList<>();
                for (String xreviewUnitList : xreviewUnitLists) {
                    PpEMergeReviewunitlist ppEMergeReviewunitlist = new PpEMergeReviewunitlist();
                    ppEMergeReviewunitlist.setMergeXid(mergeXid);
                    ppEMergeReviewunitlist.setXreviewUnitList(xreviewUnitList);

                    mergeReviewunitlists.add(ppEMergeReviewunitlist);
                }
                mergeReviewunitlistServiceImpl.saveBatch(mergeReviewunitlists);
            }

            ArrayList<String> xreviewIdentityLists = mergeDTO.getXreviewIdentityList();
            if(CollUtil.isNotEmpty(xreviewIdentityLists)){
                List<PpEMergeReviewidentitylist> mergeReviewidentitylists = new ArrayList<>();
                for (String xreviewIdentityList : xreviewIdentityLists) {
                    PpEMergeReviewidentitylist ppEMergeReviewidentitylist = new PpEMergeReviewidentitylist();
                    ppEMergeReviewidentitylist.setMergeXid(mergeXid);
                    ppEMergeReviewidentitylist.setXreviewIdentityList(xreviewIdentityList);

                    mergeReviewidentitylists.add(ppEMergeReviewidentitylist);
                }
                mergeReviewidentitylistServiceImpl.saveBatch(mergeReviewidentitylists);
            }
        }

        //插入embed表
        ArrayList<EmbedDTO> embedList = modifyProcessOrAddProcessDTO.getEmbedList();
        EmbedDTO embedDTO = embedList.get(0);
        if(BeanUtil.isNotEmpty(embedDTO)){
            PpEEmbed ppEEmbed = BeanUtil.copyProperties(embedDTO, PpEEmbed.class);
            embedServiceImpl.save(ppEEmbed);
            String embedXid = ppEEmbed.getXid();

            ArrayList<String> xreadDataPathLists = embedDTO.getXreadDataPathList();
            if(CollUtil.isNotEmpty(xreadDataPathLists)){
                List<PpEEmbedReaddatapathlist> embedReaddatapathlists = new ArrayList<>();
                for (String xreadDataPathList : xreadDataPathLists) {
                    PpEEmbedReaddatapathlist ppEEmbedReaddatapathlist = new PpEEmbedReaddatapathlist();
                    ppEEmbedReaddatapathlist.setEmbedXid(embedXid);
                    ppEEmbedReaddatapathlist.setXreadDataPathList(xreadDataPathList);

                    embedReaddatapathlists.add(ppEEmbedReaddatapathlist);
                }
                embedReaddatapathlistServiceImpl.saveBatch(embedReaddatapathlists);
            }


            ArrayList<String> xreadGroupLists = embedDTO.getXreadGroupList();
            if(CollUtil.isNotEmpty(xreadGroupLists)){
                List<PpEEmbedReadgrouplist> embedReadgrouplists = new ArrayList<>();
                for (String xreadGroupList : xreadGroupLists) {
                    PpEEmbedReadgrouplist ppEEmbedReadgrouplist = new PpEEmbedReadgrouplist();
                    ppEEmbedReadgrouplist.setEmbedXid(embedXid);
                    ppEEmbedReadgrouplist.setXreadGroupList(xreadGroupList);

                    embedReadgrouplists.add(ppEEmbedReadgrouplist);
                }
                embedReadgrouplistServiceImpl.saveBatch(embedReadgrouplists);
            }

            ArrayList<String> xreadUnitLists = embedDTO.getXreadUnitList();
            if(CollUtil.isNotEmpty(xreadUnitLists)){
                List<PpEEmbedReadunitlist> embedReadunitlists = new ArrayList<>();
                for (String xreadUnitList : xreadUnitLists) {
                    PpEEmbedReadunitlist ppEEmbedReadunitlist = new PpEEmbedReadunitlist();
                    ppEEmbedReadunitlist.setEmbedXid(embedXid);
                    ppEEmbedReadunitlist.setXreadUnitList(xreadUnitList);

                    embedReadunitlists.add(ppEEmbedReadunitlist);
                }
                embedReadunitlistServiceImpl.saveBatch(embedReadunitlists);
            }


            ArrayList<String> xreadIdentityLists = embedDTO.getXreadIdentityList();
            if(CollUtil.isNotEmpty(xreadIdentityLists)){
                List<PpEEmbedReadidentitylist> embedReadidentitylists = new ArrayList<>();
                for (String xreadIdentityList : xreadIdentityLists) {
                    PpEEmbedReadidentitylist ppEEmbedReadidentitylist = new PpEEmbedReadidentitylist();
                    ppEEmbedReadidentitylist.setEmbedXid(embedXid);
                    ppEEmbedReadidentitylist.setXreadIdentityList(xreadIdentityList);

                    embedReadidentitylists.add(ppEEmbedReadidentitylist);
                }
                embedReadidentitylistServiceImpl.saveBatch(embedReadidentitylists);
            }

            ArrayList<String> xreviewDataPathLists = embedDTO.getXreviewDataPathList();
            if(CollUtil.isNotEmpty(xreviewDataPathLists)){
                List<PpEEmbedReviewdatapathlist> embedReviewdatapathlists = new ArrayList<>();
                for (String xreviewDataPathList : xreviewDataPathLists) {
                    PpEEmbedReviewdatapathlist ppEEmbedReviewdatapathlist = new PpEEmbedReviewdatapathlist();
                    ppEEmbedReviewdatapathlist.setEmbedXid(embedXid);
                    ppEEmbedReviewdatapathlist.setXreviewDataPathList(xreviewDataPathList);

                    embedReviewdatapathlists.add(ppEEmbedReviewdatapathlist);
                }
                embedReviewdatapathlistServiceImpl.saveBatch(embedReviewdatapathlists);
            }

            ArrayList<String> xreviewGroupLists = embedDTO.getXreviewGroupList();
            if(CollUtil.isNotEmpty(xreviewGroupLists)){
                List<PpEEmbedReviewgrouplist> embedReviewgrouplists = new ArrayList<>();
                for (String xreviewGroupList : xreviewGroupLists) {
                    PpEEmbedReviewgrouplist ppEEmbedReviewgrouplist = new PpEEmbedReviewgrouplist();
                    ppEEmbedReviewgrouplist.setEmbedXid(embedXid);
                    ppEEmbedReviewgrouplist.setXreviewGroupList(xreviewGroupList);

                    embedReviewgrouplists.add(ppEEmbedReviewgrouplist);
                }
                embedReviewgrouplistServiceImpl.saveBatch(embedReviewgrouplists);
            }

            ArrayList<String> xreviewUnitLists = embedDTO.getXreviewUnitList();
            if(CollUtil.isNotEmpty(xreviewUnitLists)){
                List<PpEEmbedReviewunitlist> embedReviewunitlists = new ArrayList<>();
                for (String xreviewUnitList : xreviewUnitLists) {
                    PpEEmbedReviewunitlist ppEEmbedReviewunitlist = new PpEEmbedReviewunitlist();
                    ppEEmbedReviewunitlist.setEmbedXid(embedXid);
                    ppEEmbedReviewunitlist.setXreviewUnitList(xreviewUnitList);

                    embedReviewunitlists.add(ppEEmbedReviewunitlist);
                }
                embedReviewunitlistServiceImpl.saveBatch(embedReviewunitlists);
            }

            ArrayList<String> xreviewIdentityLists = embedDTO.getXreviewIdentityList();
            if(CollUtil.isNotEmpty(xreviewIdentityLists)){
                List<PpEEmbedReviewidentitylist> embedReviewidentitylists = new ArrayList<>();
                for (String xreviewIdentityList : xreviewIdentityLists) {
                    PpEEmbedReviewidentitylist ppEEmbedReviewidentitylist = new PpEEmbedReviewidentitylist();
                    ppEEmbedReviewidentitylist.setEmbedXid(embedXid);
                    ppEEmbedReviewidentitylist.setXreviewIdentityList(xreviewIdentityList);

                    embedReviewidentitylists.add(ppEEmbedReviewidentitylist);
                }
                embedReviewidentitylistServiceImpl.saveBatch(embedReviewidentitylists);
            }
        }

        //插入publish表
        ArrayList<PublishDTO> publishList = modifyProcessOrAddProcessDTO.getPublishList();
        PublishDTO publishDTO = publishList.get(0);
        if(BeanUtil.isNotEmpty(publishDTO)){
            PpEPublish ppEPublish = BeanUtil.copyProperties(publishDTO, PpEPublish.class);
            publishServiceImpl.save(ppEPublish);
            String publishXid = ppEPublish.getXid();

            ArrayList<String> xreadDataPathLists = publishDTO.getXreadDataPathList();
            if(CollUtil.isNotEmpty(xreadDataPathLists)){
                List<PpEPublishReaddatapathlist> publishReaddatapathlists = new ArrayList<>();
                for (String xreadDataPathList : xreadDataPathLists) {
                    PpEPublishReaddatapathlist ppEPublishReaddatapathlist = new PpEPublishReaddatapathlist();
                    ppEPublishReaddatapathlist.setPublishXid(publishXid);
                    ppEPublishReaddatapathlist.setXreadDataPathList(xreadDataPathList);

                    publishReaddatapathlists.add(ppEPublishReaddatapathlist);
                }
                publishReaddatapathlistServiceImpl.saveBatch(publishReaddatapathlists);
            }


            ArrayList<String> xreadGroupLists = publishDTO.getXreadGroupList();
            if(CollUtil.isNotEmpty(xreadGroupLists)){
                List<PpEPublishReadgrouplist> publishReadgrouplists = new ArrayList<>();
                for (String xreadGroupList : xreadGroupLists) {
                    PpEPublishReadgrouplist ppEPublishReadgrouplist = new PpEPublishReadgrouplist();
                    ppEPublishReadgrouplist.setPublishXid(publishXid);
                    ppEPublishReadgrouplist.setXreadGroupList(xreadGroupList);

                    publishReadgrouplists.add(ppEPublishReadgrouplist);
                }
                publishReadgrouplistServiceImpl.saveBatch(publishReadgrouplists);
            }

            ArrayList<String> xreadUnitLists = publishDTO.getXreadUnitList();
            if(CollUtil.isNotEmpty(xreadUnitLists)){
                List<PpEPublishReadunitlist> publishReadunitlists = new ArrayList<>();
                for (String xreadUnitList : xreadUnitLists) {
                    PpEPublishReadunitlist ppEPublishReadunitlist = new PpEPublishReadunitlist();
                    ppEPublishReadunitlist.setPublishXid(publishXid);
                    ppEPublishReadunitlist.setXreadUnitList(xreadUnitList);

                    publishReadunitlists.add(ppEPublishReadunitlist);
                }
                publishReadunitlistServiceImpl.saveBatch(publishReadunitlists);
            }


            ArrayList<String> xreadIdentityLists = publishDTO.getXreadIdentityList();
            if(CollUtil.isNotEmpty(xreadIdentityLists)){
                List<PpEPublishReadidentitylist> publishReadidentitylists = new ArrayList<>();
                for (String xreadIdentityList : xreadIdentityLists) {
                    PpEPublishReadidentitylist ppEPublishReadidentitylist = new PpEPublishReadidentitylist();
                    ppEPublishReadidentitylist.setPublishXid(publishXid);
                    ppEPublishReadidentitylist.setXreadIdentityList(xreadIdentityList);

                    publishReadidentitylists.add(ppEPublishReadidentitylist);
                }
                publishReadidentitylistServiceImpl.saveBatch(publishReadidentitylists);
            }

            ArrayList<String> xreviewDataPathLists = publishDTO.getXreviewDataPathList();
            if(CollUtil.isNotEmpty(xreviewDataPathLists)){
                List<PpEPublishReviewdatapathlist> publishReviewdatapathlists = new ArrayList<>();
                for (String xreviewDataPathList : xreviewDataPathLists) {
                    PpEPublishReviewdatapathlist ppEPublishReviewdatapathlist = new PpEPublishReviewdatapathlist();
                    ppEPublishReviewdatapathlist.setPublishXid(publishXid);
                    ppEPublishReviewdatapathlist.setXreviewDataPathList(xreviewDataPathList);

                    publishReviewdatapathlists.add(ppEPublishReviewdatapathlist);
                }
                publishReviewdatapathlistServiceImpl.saveBatch(publishReviewdatapathlists);
            }

            ArrayList<String> xreviewGroupLists = publishDTO.getXreviewGroupList();
            if(CollUtil.isNotEmpty(xreviewGroupLists)){
                List<PpEPublishReviewgrouplist> publishReviewgrouplists = new ArrayList<>();
                for (String xreviewGroupList : xreviewGroupLists) {
                    PpEPublishReviewgrouplist ppEPublishReviewgrouplist = new PpEPublishReviewgrouplist();
                    ppEPublishReviewgrouplist.setPublishXid(publishXid);
                    ppEPublishReviewgrouplist.setXreviewGroupList(xreviewGroupList);

                    publishReviewgrouplists.add(ppEPublishReviewgrouplist);
                }
                publishReviewgrouplistServiceImpl.saveBatch(publishReviewgrouplists);
            }

            ArrayList<String> xreviewUnitLists = publishDTO.getXreviewUnitList();
            if(CollUtil.isNotEmpty(xreviewUnitLists)){
                List<PpEPublishReviewunitlist> publishReviewunitlists = new ArrayList<>();
                for (String xreviewUnitList : xreviewUnitLists) {
                    PpEPublishReviewunitlist ppEPublishReviewunitlist = new PpEPublishReviewunitlist();
                    ppEPublishReviewunitlist.setPublishXid(publishXid);
                    ppEPublishReviewunitlist.setXreviewUnitList(xreviewUnitList);

                    publishReviewunitlists.add(ppEPublishReviewunitlist);
                }
                publishReviewunitlistServiceImpl.saveBatch(publishReviewunitlists);
            }

            ArrayList<String> xreviewIdentityLists = publishDTO.getXreviewIdentityList();
            if(CollUtil.isNotEmpty(xreviewIdentityLists)){
                List<PpEPublishReviewidentitylist> publishReviewidentitylists = new ArrayList<>();
                for (String xreviewIdentityList : xreviewIdentityLists) {
                    PpEPublishReviewidentitylist ppEPublishReviewidentitylist = new PpEPublishReviewidentitylist();
                    ppEPublishReviewidentitylist.setPublishXid(publishXid);
                    ppEPublishReviewidentitylist.setXreviewIdentityList(xreviewIdentityList);

                    publishReviewidentitylists.add(ppEPublishReviewidentitylist);
                }
                publishReviewidentitylistServiceImpl.saveBatch(publishReviewidentitylists);
            }
        }

        //插入delay表
        ArrayList<DelayDTO> delayList = modifyProcessOrAddProcessDTO.getDelayList();
        DelayDTO delayDTO = delayList.get(0);
        if(BeanUtil.isNotEmpty(delayDTO)){
            PpEDelay ppEDelay = BeanUtil.copyProperties(delayDTO, PpEDelay.class);
            delayServiceImpl.save(ppEDelay);
            String delayXid = ppEDelay.getXid();

            ArrayList<String> xreadDataPathLists = delayDTO.getXreadDataPathList();
            if(CollUtil.isNotEmpty(xreadDataPathLists)){
                List<PpEDelayReaddatapathlist> delayReaddatapathlists = new ArrayList<>();
                for (String xreadDataPathList : xreadDataPathLists) {
                    PpEDelayReaddatapathlist ppEDelayReaddatapathlist = new PpEDelayReaddatapathlist();
                    ppEDelayReaddatapathlist.setDelayXid(delayXid);
                    ppEDelayReaddatapathlist.setXreadDataPathList(xreadDataPathList);

                    delayReaddatapathlists.add(ppEDelayReaddatapathlist);
                }
                delayReaddatapathlistServiceImpl.saveBatch(delayReaddatapathlists);
            }


            ArrayList<String> xreadGroupLists = delayDTO.getXreadGroupList();
            if(CollUtil.isNotEmpty(xreadGroupLists)){
                List<PpEDelayReadgrouplist> delayReadgrouplists = new ArrayList<>();
                for (String xreadGroupList : xreadGroupLists) {
                    PpEDelayReadgrouplist ppEDelayReadgrouplist = new PpEDelayReadgrouplist();
                    ppEDelayReadgrouplist.setDelayXid(delayXid);
                    ppEDelayReadgrouplist.setXreadGroupList(xreadGroupList);

                    delayReadgrouplists.add(ppEDelayReadgrouplist);
                }
                delayReadgrouplistServiceImpl.saveBatch(delayReadgrouplists);
            }

            ArrayList<String> xreadUnitLists = delayDTO.getXreadUnitList();
            if(CollUtil.isNotEmpty(xreadUnitLists)){
                List<PpEDelayReadunitlist> delayReadunitlists = new ArrayList<>();
                for (String xreadUnitList : xreadUnitLists) {
                    PpEDelayReadunitlist ppEDelayReadunitlist = new PpEDelayReadunitlist();
                    ppEDelayReadunitlist.setDelayXid(delayXid);
                    ppEDelayReadunitlist.setXreadUnitList(xreadUnitList);

                    delayReadunitlists.add(ppEDelayReadunitlist);
                }
                delayReadunitlistServiceImpl.saveBatch(delayReadunitlists);
            }


            ArrayList<String> xreadIdentityLists = delayDTO.getXreadIdentityList();
            if(CollUtil.isNotEmpty(xreadIdentityLists)){
                List<PpEDelayReadidentitylist> delayReadidentitylists = new ArrayList<>();
                for (String xreadIdentityList : xreadIdentityLists) {
                    PpEDelayReadidentitylist ppEDelayReadidentitylist = new PpEDelayReadidentitylist();
                    ppEDelayReadidentitylist.setDelayXid(delayXid);
                    ppEDelayReadidentitylist.setXreadIdentityList(xreadIdentityList);

                    delayReadidentitylists.add(ppEDelayReadidentitylist);
                }
                delayReadidentitylistServiceImpl.saveBatch(delayReadidentitylists);
            }

            ArrayList<String> xreviewDataPathLists = delayDTO.getXreviewDataPathList();
            if(CollUtil.isNotEmpty(xreviewDataPathLists)){
                List<PpEDelayReviewdatapathlist> delayReviewdatapathlists = new ArrayList<>();
                for (String xreviewDataPathList : xreviewDataPathLists) {
                    PpEDelayReviewdatapathlist ppEDelayReviewdatapathlist = new PpEDelayReviewdatapathlist();
                    ppEDelayReviewdatapathlist.setDelayXid(delayXid);
                    ppEDelayReviewdatapathlist.setXreviewDataPathList(xreviewDataPathList);

                    delayReviewdatapathlists.add(ppEDelayReviewdatapathlist);
                }
                delayReviewdatapathlistServiceImpl.saveBatch(delayReviewdatapathlists);
            }

            ArrayList<String> xreviewGroupLists = delayDTO.getXreviewGroupList();
            if(CollUtil.isNotEmpty(xreviewGroupLists)){
                List<PpEDelayReviewgrouplist> delayReviewgrouplists = new ArrayList<>();
                for (String xreviewGroupList : xreviewGroupLists) {
                    PpEDelayReviewgrouplist ppEDelayReviewgrouplist = new PpEDelayReviewgrouplist();
                    ppEDelayReviewgrouplist.setDelayXid(delayXid);
                    ppEDelayReviewgrouplist.setXreviewGroupList(xreviewGroupList);

                    delayReviewgrouplists.add(ppEDelayReviewgrouplist);
                }
                delayReviewgrouplistServiceImpl.saveBatch(delayReviewgrouplists);
            }

            ArrayList<String> xreviewUnitLists = delayDTO.getXreviewUnitList();
            if(CollUtil.isNotEmpty(xreviewUnitLists)){
                List<PpEDelayReviewunitlist> delayReviewunitlists = new ArrayList<>();
                for (String xreviewUnitList : xreviewUnitLists) {
                    PpEDelayReviewunitlist ppEDelayReviewunitlist = new PpEDelayReviewunitlist();
                    ppEDelayReviewunitlist.setDelayXid(delayXid);
                    ppEDelayReviewunitlist.setXreviewUnitList(xreviewUnitList);

                    delayReviewunitlists.add(ppEDelayReviewunitlist);
                }
                delayReviewunitlistServiceImpl.saveBatch(delayReviewunitlists);
            }

            ArrayList<String> xreviewIdentityLists = delayDTO.getXreviewIdentityList();
            if(CollUtil.isNotEmpty(xreviewIdentityLists)){
                List<PpEDelayReviewidentitylist> delayReviewidentitylists = new ArrayList<>();
                for (String xreviewIdentityList : xreviewIdentityLists) {
                    PpEDelayReviewidentitylist ppEDelayReviewidentitylist = new PpEDelayReviewidentitylist();
                    ppEDelayReviewidentitylist.setDelayXid(delayXid);
                    ppEDelayReviewidentitylist.setXreviewIdentityList(xreviewIdentityList);

                    delayReviewidentitylists.add(ppEDelayReviewidentitylist);
                }
                delayReviewidentitylistServiceImpl.saveBatch(delayReviewidentitylists);
            }
        }

        //插入invoke表
        ArrayList<InvokeDTO> invokeList = modifyProcessOrAddProcessDTO.getInvokeList();
        InvokeDTO invokeDTO = invokeList.get(0);
        if(BeanUtil.isNotEmpty(invokeDTO)){
            PpEInvoke ppEInvoke = BeanUtil.copyProperties(invokeDTO, PpEInvoke.class);
            invokeServiceImpl.save(ppEInvoke);
            String invokeXid = ppEInvoke.getXid();

            ArrayList<String> xreadDataPathLists = invokeDTO.getXreadDataPathList();
            if(CollUtil.isNotEmpty(xreadDataPathLists)){
                List<PpEInvokeReaddatapathlist> invokeReaddatapathlists = new ArrayList<>();
                for (String xreadDataPathList : xreadDataPathLists) {
                    PpEInvokeReaddatapathlist ppEInvokeReaddatapathlist = new PpEInvokeReaddatapathlist();
                    ppEInvokeReaddatapathlist.setInvokeXid(invokeXid);
                    ppEInvokeReaddatapathlist.setXreadDataPathList(xreadDataPathList);

                    invokeReaddatapathlists.add(ppEInvokeReaddatapathlist);
                }
                invokeReaddatapathlistServiceImpl.saveBatch(invokeReaddatapathlists);
            }


            ArrayList<String> xreadGroupLists = invokeDTO.getXreadGroupList();
            if(CollUtil.isNotEmpty(xreadGroupLists)){
                List<PpEInvokeReadgrouplist> invokeReadgrouplists = new ArrayList<>();
                for (String xreadGroupList : xreadGroupLists) {
                    PpEInvokeReadgrouplist ppEInvokeReadgrouplist = new PpEInvokeReadgrouplist();
                    ppEInvokeReadgrouplist.setInvokeXid(invokeXid);
                    ppEInvokeReadgrouplist.setXreadGroupList(xreadGroupList);

                    invokeReadgrouplists.add(ppEInvokeReadgrouplist);
                }
                invokeReadgrouplistServiceImpl.saveBatch(invokeReadgrouplists);
            }

            ArrayList<String> xreadUnitLists = invokeDTO.getXreadUnitList();
            if(CollUtil.isNotEmpty(xreadUnitLists)){
                List<PpEInvokeReadunitlist> invokeReadunitlists = new ArrayList<>();
                for (String xreadUnitList : xreadUnitLists) {
                    PpEInvokeReadunitlist ppEInvokeReadunitlist = new PpEInvokeReadunitlist();
                    ppEInvokeReadunitlist.setInvokeXid(invokeXid);
                    ppEInvokeReadunitlist.setXreadUnitList(xreadUnitList);

                    invokeReadunitlists.add(ppEInvokeReadunitlist);
                }
                invokeReadunitlistServiceImpl.saveBatch(invokeReadunitlists);
            }


            ArrayList<String> xreadIdentityLists = invokeDTO.getXreadIdentityList();
            if(CollUtil.isNotEmpty(xreadIdentityLists)){
                List<PpEInvokeReadidentitylist> invokeReadidentitylists = new ArrayList<>();
                for (String xreadIdentityList : xreadIdentityLists) {
                    PpEInvokeReadidentitylist ppEInvokeReadidentitylist = new PpEInvokeReadidentitylist();
                    ppEInvokeReadidentitylist.setInvokeXid(invokeXid);
                    ppEInvokeReadidentitylist.setXreadIdentityList(xreadIdentityList);

                    invokeReadidentitylists.add(ppEInvokeReadidentitylist);
                }
                invokeReadidentitylistServiceImpl.saveBatch(invokeReadidentitylists);
            }

            ArrayList<String> xreviewDataPathLists = invokeDTO.getXreviewDataPathList();
            if(CollUtil.isNotEmpty(xreviewDataPathLists)){
                List<PpEInvokeReviewdatapathlist> invokeReviewdatapathlists = new ArrayList<>();
                for (String xreviewDataPathList : xreviewDataPathLists) {
                    PpEInvokeReviewdatapathlist ppEInvokeReviewdatapathlist = new PpEInvokeReviewdatapathlist();
                    ppEInvokeReviewdatapathlist.setInvokeXid(invokeXid);
                    ppEInvokeReviewdatapathlist.setXreviewDataPathList(xreviewDataPathList);

                    invokeReviewdatapathlists.add(ppEInvokeReviewdatapathlist);
                }
                invokeReviewdatapathlistServiceImpl.saveBatch(invokeReviewdatapathlists);
            }

            ArrayList<String> xreviewGroupLists = invokeDTO.getXreviewGroupList();
            if(CollUtil.isNotEmpty(xreviewGroupLists)){
                List<PpEInvokeReviewgrouplist> invokeReviewgrouplists = new ArrayList<>();
                for (String xreviewGroupList : xreviewGroupLists) {
                    PpEInvokeReviewgrouplist ppEInvokeReviewgrouplist = new PpEInvokeReviewgrouplist();
                    ppEInvokeReviewgrouplist.setInvokeXid(invokeXid);
                    ppEInvokeReviewgrouplist.setXreviewGroupList(xreviewGroupList);

                    invokeReviewgrouplists.add(ppEInvokeReviewgrouplist);
                }
                invokeReviewgrouplistServiceImpl.saveBatch(invokeReviewgrouplists);
            }

            ArrayList<String> xreviewUnitLists = invokeDTO.getXreviewUnitList();
            if(CollUtil.isNotEmpty(xreviewUnitLists)){
                List<PpEInvokeReviewunitlist> invokeReviewunitlists = new ArrayList<>();
                for (String xreviewUnitList : xreviewUnitLists) {
                    PpEInvokeReviewunitlist ppEInvokeReviewunitlist = new PpEInvokeReviewunitlist();
                    ppEInvokeReviewunitlist.setInvokeXid(invokeXid);
                    ppEInvokeReviewunitlist.setXreviewUnitList(xreviewUnitList);

                    invokeReviewunitlists.add(ppEInvokeReviewunitlist);
                }
                invokeReviewunitlistServiceImpl.saveBatch(invokeReviewunitlists);
            }

            ArrayList<String> xreviewIdentityLists = invokeDTO.getXreviewIdentityList();
            if(CollUtil.isNotEmpty(xreviewIdentityLists)){
                List<PpEInvokeReviewidentitylist> invokeReviewidentitylists = new ArrayList<>();
                for (String xreviewIdentityList : xreviewIdentityLists) {
                    PpEInvokeReviewidentitylist ppEInvokeReviewidentitylist = new PpEInvokeReviewidentitylist();
                    ppEInvokeReviewidentitylist.setInvokeXid(invokeXid);
                    ppEInvokeReviewidentitylist.setXreviewIdentityList(xreviewIdentityList);

                    invokeReviewidentitylists.add(ppEInvokeReviewidentitylist);
                }
                invokeReviewidentitylistServiceImpl.saveBatch(invokeReviewidentitylists);
            }
        }

        //插入agent表
        ArrayList<AgentDTO> agentList = modifyProcessOrAddProcessDTO.getAgentList();
        AgentDTO agentDTO = agentList.get(0);
        if(BeanUtil.isNotEmpty(agentDTO)){
            PpEAgent ppEAgent = BeanUtil.copyProperties(agentDTO, PpEAgent.class);
            agentServiceImpl.save(ppEAgent);
            String agentXid = ppEAgent.getXid();

            ArrayList<String> xreadDataPathLists = agentDTO.getXreadDataPathList();
            if(CollUtil.isNotEmpty(xreadDataPathLists)){
                List<PpEAgentReaddatapathlist> agentReaddatapathlists = new ArrayList<>();
                for (String xreadDataPathList : xreadDataPathLists) {
                    PpEAgentReaddatapathlist ppEAgentReaddatapathlist = new PpEAgentReaddatapathlist();
                    ppEAgentReaddatapathlist.setAgentXid(agentXid);
                    ppEAgentReaddatapathlist.setXreadDataPathList(xreadDataPathList);

                    agentReaddatapathlists.add(ppEAgentReaddatapathlist);
                }
                agentReaddatapathlistServiceImpl.saveBatch(agentReaddatapathlists);
            }


            ArrayList<String> xreadGroupLists = agentDTO.getXreadGroupList();
            if(CollUtil.isNotEmpty(xreadGroupLists)){
                List<PpEAgentReadgrouplist> agentReadgrouplists = new ArrayList<>();
                for (String xreadGroupList : xreadGroupLists) {
                    PpEAgentReadgrouplist ppEAgentReadgrouplist = new PpEAgentReadgrouplist();
                    ppEAgentReadgrouplist.setAgentXid(agentXid);
                    ppEAgentReadgrouplist.setXreadGroupList(xreadGroupList);

                    agentReadgrouplists.add(ppEAgentReadgrouplist);
                }
                agentReadgrouplistServiceImpl.saveBatch(agentReadgrouplists);
            }

            ArrayList<String> xreadUnitLists = agentDTO.getXreadUnitList();
            if(CollUtil.isNotEmpty(xreadUnitLists)){
                List<PpEAgentReadunitlist> agentReadunitlists = new ArrayList<>();
                for (String xreadUnitList : xreadUnitLists) {
                    PpEAgentReadunitlist ppEAgentReadunitlist = new PpEAgentReadunitlist();
                    ppEAgentReadunitlist.setAgentXid(agentXid);
                    ppEAgentReadunitlist.setXreadUnitList(xreadUnitList);

                    agentReadunitlists.add(ppEAgentReadunitlist);
                }
                agentReadunitlistServiceImpl.saveBatch(agentReadunitlists);
            }


            ArrayList<String> xreadIdentityLists = agentDTO.getXreadIdentityList();
            if(CollUtil.isNotEmpty(xreadIdentityLists)){
                List<PpEAgentReadidentitylist> agentReadidentitylists = new ArrayList<>();
                for (String xreadIdentityList : xreadIdentityLists) {
                    PpEAgentReadidentitylist ppEAgentReadidentitylist = new PpEAgentReadidentitylist();
                    ppEAgentReadidentitylist.setAgentXid(agentXid);
                    ppEAgentReadidentitylist.setXreadIdentityList(xreadIdentityList);

                    agentReadidentitylists.add(ppEAgentReadidentitylist);
                }
                agentReadidentitylistServiceImpl.saveBatch(agentReadidentitylists);
            }

            ArrayList<String> xreviewDataPathLists = agentDTO.getXreviewDataPathList();
            if(CollUtil.isNotEmpty(xreviewDataPathLists)){
                List<PpEAgentReviewdatapathlist> agentReviewdatapathlists = new ArrayList<>();
                for (String xreviewDataPathList : xreviewDataPathLists) {
                    PpEAgentReviewdatapathlist ppEAgentReviewdatapathlist = new PpEAgentReviewdatapathlist();
                    ppEAgentReviewdatapathlist.setAgentXid(agentXid);
                    ppEAgentReviewdatapathlist.setXreviewDataPathList(xreviewDataPathList);

                    agentReviewdatapathlists.add(ppEAgentReviewdatapathlist);
                }
                agentReviewdatapathlistServiceImpl.saveBatch(agentReviewdatapathlists);
            }

            ArrayList<String> xreviewGroupLists = agentDTO.getXreviewGroupList();
            if(CollUtil.isNotEmpty(xreviewGroupLists)){
                List<PpEAgentReviewgrouplist> agentReviewgrouplists = new ArrayList<>();
                for (String xreviewGroupList : xreviewGroupLists) {
                    PpEAgentReviewgrouplist ppEAgentReviewgrouplist = new PpEAgentReviewgrouplist();
                    ppEAgentReviewgrouplist.setAgentXid(agentXid);
                    ppEAgentReviewgrouplist.setXreviewGroupList(xreviewGroupList);

                    agentReviewgrouplists.add(ppEAgentReviewgrouplist);
                }
                agentReviewgrouplistServiceImpl.saveBatch(agentReviewgrouplists);
            }

            ArrayList<String> xreviewUnitLists = agentDTO.getXreviewUnitList();
            if(CollUtil.isNotEmpty(xreviewUnitLists)){
                List<PpEAgentReviewunitlist> agentReviewunitlists = new ArrayList<>();
                for (String xreviewUnitList : xreviewUnitLists) {
                    PpEAgentReviewunitlist ppEAgentReviewunitlist = new PpEAgentReviewunitlist();
                    ppEAgentReviewunitlist.setAgentXid(agentXid);
                    ppEAgentReviewunitlist.setXreviewUnitList(xreviewUnitList);

                    agentReviewunitlists.add(ppEAgentReviewunitlist);
                }
                agentReviewunitlistServiceImpl.saveBatch(agentReviewunitlists);
            }

            ArrayList<String> xreviewIdentityLists = agentDTO.getXreviewIdentityList();
            if(CollUtil.isNotEmpty(xreviewIdentityLists)){
                List<PpEAgentReviewidentitylist> agentReviewidentitylists = new ArrayList<>();
                for (String xreviewIdentityList : xreviewIdentityLists) {
                    PpEAgentReviewidentitylist ppEAgentReviewidentitylist = new PpEAgentReviewidentitylist();
                    ppEAgentReviewidentitylist.setAgentXid(agentXid);
                    ppEAgentReviewidentitylist.setXreviewIdentityList(xreviewIdentityList);

                    agentReviewidentitylists.add(ppEAgentReviewidentitylist);
                }
                agentReviewidentitylistServiceImpl.saveBatch(agentReviewidentitylists);
            }
        }

        //插入service表
        ArrayList<ServiceDTO> serviceList = modifyProcessOrAddProcessDTO.getServiceList();
        ServiceDTO serviceDTO = serviceList.get(0);
        if(BeanUtil.isNotEmpty(serviceDTO)){
            PpEService ppEService = BeanUtil.copyProperties(serviceDTO, PpEService.class);
            serviceServiceImpl.save(ppEService);
            String serviceXid = ppEService.getXid();

            ArrayList<String> xreadDataPathLists = serviceDTO.getXreadDataPathList();
            if(CollUtil.isNotEmpty(xreadDataPathLists)){
                List<PpEServiceReaddatapathlist> serviceReaddatapathlists = new ArrayList<>();
                for (String xreadDataPathList : xreadDataPathLists) {
                    PpEServiceReaddatapathlist ppEServiceReaddatapathlist = new PpEServiceReaddatapathlist();
                    ppEServiceReaddatapathlist.setServiceXid(serviceXid);
                    ppEServiceReaddatapathlist.setXreadDataPathList(xreadDataPathList);

                    serviceReaddatapathlists.add(ppEServiceReaddatapathlist);
                }
                serviceReaddatapathlistServiceImpl.saveBatch(serviceReaddatapathlists);
            }


            ArrayList<String> xreadGroupLists = serviceDTO.getXreadGroupList();
            if(CollUtil.isNotEmpty(xreadGroupLists)){
                List<PpEServiceReadgrouplist> serviceReadgrouplists = new ArrayList<>();
                for (String xreadGroupList : xreadGroupLists) {
                    PpEServiceReadgrouplist ppEServiceReadgrouplist = new PpEServiceReadgrouplist();
                    ppEServiceReadgrouplist.setServiceXid(serviceXid);
                    ppEServiceReadgrouplist.setXreadGroupList(xreadGroupList);

                    serviceReadgrouplists.add(ppEServiceReadgrouplist);
                }
                serviceReadgrouplistServiceImpl.saveBatch(serviceReadgrouplists);
            }

            ArrayList<String> xreadUnitLists = serviceDTO.getXreadUnitList();
            if(CollUtil.isNotEmpty(xreadUnitLists)){
                List<PpEServiceReadunitlist> serviceReadunitlists = new ArrayList<>();
                for (String xreadUnitList : xreadUnitLists) {
                    PpEServiceReadunitlist ppEServiceReadunitlist = new PpEServiceReadunitlist();
                    ppEServiceReadunitlist.setServiceXid(serviceXid);
                    ppEServiceReadunitlist.setXreadUnitList(xreadUnitList);

                    serviceReadunitlists.add(ppEServiceReadunitlist);
                }
                serviceReadunitlistServiceImpl.saveBatch(serviceReadunitlists);
            }


            ArrayList<String> xreadIdentityLists = serviceDTO.getXreadIdentityList();
            if(CollUtil.isNotEmpty(xreadIdentityLists)){
                List<PpEServiceReadidentitylist> serviceReadidentitylists = new ArrayList<>();
                for (String xreadIdentityList : xreadIdentityLists) {
                    PpEServiceReadidentitylist ppEServiceReadidentitylist = new PpEServiceReadidentitylist();
                    ppEServiceReadidentitylist.setServiceXid(serviceXid);
                    ppEServiceReadidentitylist.setXreadIdentityList(xreadIdentityList);

                    serviceReadidentitylists.add(ppEServiceReadidentitylist);
                }
                serviceReadidentitylistServiceImpl.saveBatch(serviceReadidentitylists);
            }

            ArrayList<String> xreviewDataPathLists = serviceDTO.getXreviewDataPathList();
            if(CollUtil.isNotEmpty(xreviewDataPathLists)){
                List<PpEServiceReviewdatapathlist> serviceReviewdatapathlists = new ArrayList<>();
                for (String xreviewDataPathList : xreviewDataPathLists) {
                    PpEServiceReviewdatapathlist ppEServiceReviewdatapathlist = new PpEServiceReviewdatapathlist();
                    ppEServiceReviewdatapathlist.setServiceXid(serviceXid);
                    ppEServiceReviewdatapathlist.setXreviewDataPathList(xreviewDataPathList);

                    serviceReviewdatapathlists.add(ppEServiceReviewdatapathlist);
                }
                serviceReviewdatapathlistServiceImpl.saveBatch(serviceReviewdatapathlists);
            }

            ArrayList<String> xreviewGroupLists = serviceDTO.getXreviewGroupList();
            if(CollUtil.isNotEmpty(xreviewGroupLists)){
                List<PpEServiceReviewgrouplist> serviceReviewgrouplists = new ArrayList<>();
                for (String xreviewGroupList : xreviewGroupLists) {
                    PpEServiceReviewgrouplist ppEServiceReviewgrouplist = new PpEServiceReviewgrouplist();
                    ppEServiceReviewgrouplist.setServiceXid(serviceXid);
                    ppEServiceReviewgrouplist.setXreviewGroupList(xreviewGroupList);

                    serviceReviewgrouplists.add(ppEServiceReviewgrouplist);
                }
                serviceReviewgrouplistServiceImpl.saveBatch(serviceReviewgrouplists);
            }

            ArrayList<String> xreviewUnitLists = serviceDTO.getXreviewUnitList();
            if(CollUtil.isNotEmpty(xreviewUnitLists)){
                List<PpEServiceReviewunitlist> serviceReviewunitlists = new ArrayList<>();
                for (String xreviewUnitList : xreviewUnitLists) {
                    PpEServiceReviewunitlist ppEServiceReviewunitlist = new PpEServiceReviewunitlist();
                    ppEServiceReviewunitlist.setServiceXid(serviceXid);
                    ppEServiceReviewunitlist.setXreviewUnitList(xreviewUnitList);

                    serviceReviewunitlists.add(ppEServiceReviewunitlist);
                }
                serviceReviewunitlistServiceImpl.saveBatch(serviceReviewunitlists);
            }

            ArrayList<String> xreviewIdentityLists = serviceDTO.getXreviewIdentityList();
            if(CollUtil.isNotEmpty(xreviewIdentityLists)){
                List<PpEServiceReviewidentitylist> serviceReviewidentitylists = new ArrayList<>();
                for (String xreviewIdentityList : xreviewIdentityLists) {
                    PpEServiceReviewidentitylist ppEServiceReviewidentitylist = new PpEServiceReviewidentitylist();
                    ppEServiceReviewidentitylist.setServiceXid(serviceXid);
                    ppEServiceReviewidentitylist.setXreviewIdentityList(xreviewIdentityList);

                    serviceReviewidentitylists.add(ppEServiceReviewidentitylist);
                }
                serviceReviewidentitylistServiceImpl.saveBatch(serviceReviewidentitylists);
            }

            ArrayList<String> xtrustAddressLists = serviceDTO.getXtrustAddressList();
            if(CollUtil.isNotEmpty(xtrustAddressLists)){
                List<PpEServiceTrustaddresslist> serviceTrustaddresslists = new ArrayList<>();

                for (String xtrustAddressList : xtrustAddressLists) {
                    PpEServiceTrustaddresslist ppEServiceTrustaddresslist = new PpEServiceTrustaddresslist();
                    ppEServiceTrustaddresslist.setServiceXid(serviceXid);
                    ppEServiceTrustaddresslist.setXtrustAddressList(xtrustAddressList);

                    serviceTrustaddresslists.add(ppEServiceTrustaddresslist);
                }
                serviceTrustaddresslistServiceImpl.saveBatch(serviceTrustaddresslists);
            }
        }

        //插入manual表
        ArrayList<ManualDTO> manualList = modifyProcessOrAddProcessDTO.getManualList();
        ManualDTO manualDTO = manualList.get(0);
        if(BeanUtil.isNotEmpty(manualDTO)){
            PpEManual ppEManual = BeanUtil.copyProperties(manualDTO, PpEManual.class);
            manualServiceImpl.save(ppEManual);
            String manualXid = ppEManual.getXid();

            ArrayList<String> xreadDataPathLists = manualDTO.getXreadDataPathList();
            if(CollUtil.isNotEmpty(xreadDataPathLists)){
                List<PpEManualReaddatapathlist> manualReaddatapathlists = new ArrayList<>();
                for (String xreadDataPathList : xreadDataPathLists) {
                    PpEManualReaddatapathlist ppEManualReaddatapathlist = new PpEManualReaddatapathlist();
                    ppEManualReaddatapathlist.setManualXid(manualXid);
                    ppEManualReaddatapathlist.setXreadDataPathList(xreadDataPathList);

                    manualReaddatapathlists.add(ppEManualReaddatapathlist);
                }
                manualReaddatapathlistServiceImpl.saveBatch(manualReaddatapathlists);
            }


            ArrayList<String> xreadGroupLists = manualDTO.getXreadGroupList();
            if(CollUtil.isNotEmpty(xreadGroupLists)){
                List<PpEManualReadgrouplist> manualReadgrouplists = new ArrayList<>();
                for (String xreadGroupList : xreadGroupLists) {
                    PpEManualReadgrouplist ppEManualReadgrouplist = new PpEManualReadgrouplist();
                    ppEManualReadgrouplist.setManualXid(manualXid);
                    ppEManualReadgrouplist.setXreadGroupList(xreadGroupList);

                    manualReadgrouplists.add(ppEManualReadgrouplist);
                }
                manualReadgrouplistServiceImpl.saveBatch(manualReadgrouplists);
            }

            ArrayList<String> xreadUnitLists = manualDTO.getXreadUnitList();
            if(CollUtil.isNotEmpty(xreadUnitLists)){
                List<PpEManualReadunitlist> manualReadunitlists = new ArrayList<>();
                for (String xreadUnitList : xreadUnitLists) {
                    PpEManualReadunitlist ppEManualReadunitlist = new PpEManualReadunitlist();
                    ppEManualReadunitlist.setManualXid(manualXid);
                    ppEManualReadunitlist.setXreadUnitList(xreadUnitList);

                    manualReadunitlists.add(ppEManualReadunitlist);
                }
                manualReadunitlistServiceImpl.saveBatch(manualReadunitlists);
            }


            ArrayList<String> xreadIdentityLists = manualDTO.getXreadIdentityList();
            if(CollUtil.isNotEmpty(xreadIdentityLists)){
                List<PpEManualReadidentitylist> manualReadidentitylists = new ArrayList<>();
                for (String xreadIdentityList : xreadIdentityLists) {
                    PpEManualReadidentitylist ppEManualReadidentitylist = new PpEManualReadidentitylist();
                    ppEManualReadidentitylist.setManualXid(manualXid);
                    ppEManualReadidentitylist.setXreadIdentityList(xreadIdentityList);

                    manualReadidentitylists.add(ppEManualReadidentitylist);
                }
                manualReadidentitylistServiceImpl.saveBatch(manualReadidentitylists);
            }

            ArrayList<String> xreviewDataPathLists = manualDTO.getXreviewDataPathList();
            if(CollUtil.isNotEmpty(xreviewDataPathLists)){
                List<PpEManualReviewdatapathlist> manualReviewdatapathlists = new ArrayList<>();
                for (String xreviewDataPathList : xreviewDataPathLists) {
                    PpEManualReviewdatapathlist ppEManualReviewdatapathlist = new PpEManualReviewdatapathlist();
                    ppEManualReviewdatapathlist.setManualXid(manualXid);
                    ppEManualReviewdatapathlist.setXreviewDataPathList(xreviewDataPathList);

                    manualReviewdatapathlists.add(ppEManualReviewdatapathlist);
                }
                manualReviewdatapathlistServiceImpl.saveBatch(manualReviewdatapathlists);
            }

            ArrayList<String> xreviewGroupLists = manualDTO.getXreviewGroupList();
            if(CollUtil.isNotEmpty(xreviewGroupLists)){
                List<PpEManualReviewgrouplist> manualReviewgrouplists = new ArrayList<>();
                for (String xreviewGroupList : xreviewGroupLists) {
                    PpEManualReviewgrouplist ppEManualReviewgrouplist = new PpEManualReviewgrouplist();
                    ppEManualReviewgrouplist.setManualXid(manualXid);
                    ppEManualReviewgrouplist.setXreviewGroupList(xreviewGroupList);

                    manualReviewgrouplists.add(ppEManualReviewgrouplist);
                }
                manualReviewgrouplistServiceImpl.saveBatch(manualReviewgrouplists);
            }

            ArrayList<String> xreviewUnitLists = manualDTO.getXreviewUnitList();
            if(CollUtil.isNotEmpty(xreviewUnitLists)){
                List<PpEManualReviewunitlist> manualReviewunitlists = new ArrayList<>();
                for (String xreviewUnitList : xreviewUnitLists) {
                    PpEManualReviewunitlist ppEManualReviewunitlist = new PpEManualReviewunitlist();
                    ppEManualReviewunitlist.setManualXid(manualXid);
                    ppEManualReviewunitlist.setXreviewUnitList(xreviewUnitList);

                    manualReviewunitlists.add(ppEManualReviewunitlist);
                }
                manualReviewunitlistServiceImpl.saveBatch(manualReviewunitlists);
            }

            ArrayList<String> xreviewIdentityLists = manualDTO.getXreviewIdentityList();
            if(CollUtil.isNotEmpty(xreviewIdentityLists)){
                List<PpEManualReviewidentitylist> manualReviewidentitylists = new ArrayList<>();
                for (String xreviewIdentityList : xreviewIdentityLists) {
                    PpEManualReviewidentitylist ppEManualReviewidentitylist = new PpEManualReviewidentitylist();
                    ppEManualReviewidentitylist.setManualXid(manualXid);
                    ppEManualReviewidentitylist.setXreviewIdentityList(xreviewIdentityList);

                    manualReviewidentitylists.add(ppEManualReviewidentitylist);
                }
                manualReviewidentitylistServiceImpl.saveBatch(manualReviewidentitylists);
            }

            ArrayList<String> xtaskDataPathLists = manualDTO.getXtaskDataPathList();
            if(CollUtil.isNotEmpty(xtaskDataPathLists)){
                List<PpEManualTaskdatapathlist> manualTaskdatapathlists = new ArrayList<>();
                for (String xtaskDataPathList : xtaskDataPathLists) {
                    PpEManualTaskdatapathlist ppEManualTaskdatapathlist = new PpEManualTaskdatapathlist();
                    ppEManualTaskdatapathlist.setManualXid(manualXid);
                    ppEManualTaskdatapathlist.setXtaskDataPathList(xtaskDataPathList);

                    manualTaskdatapathlists.add(ppEManualTaskdatapathlist);
                }
                manualTaskdatapathlistServiceImpl.saveBatch(manualTaskdatapathlists);
            }

            ArrayList<String> xtaskGroupLists = manualDTO.getXtaskGroupList();
            if(CollUtil.isNotEmpty(xtaskGroupLists)){
                List<PpEManualTaskgrouplist> manualTaskgrouplists = new ArrayList<>();
                for (String xtaskGroupList : xtaskGroupLists) {
                    PpEManualTaskgrouplist ppEManualTaskgrouplist = new PpEManualTaskgrouplist();
                    ppEManualTaskgrouplist.setManualXid(manualXid);
                    ppEManualTaskgrouplist.setXtaskGroupList(xtaskGroupList);

                    manualTaskgrouplists.add(ppEManualTaskgrouplist);
                }
                manualTaskgrouplistServiceImpl.saveBatch(manualTaskgrouplists);
            }

            ArrayList<String> xtaskUnitLists = manualDTO.getXtaskUnitList();
            if(CollUtil.isNotEmpty(xtaskUnitLists)){
                List<PpEManualTaskunitlist> manualTaskunitlists = new ArrayList<>();
                for (String xtaskUnitList : xtaskUnitLists) {
                    PpEManualTaskunitlist ppEManualTaskunitlist = new PpEManualTaskunitlist();
                    ppEManualTaskunitlist.setManualXid(manualXid);
                    ppEManualTaskunitlist.setXtaskUnitList(xtaskUnitList);

                    manualTaskunitlists.add(ppEManualTaskunitlist);
                }
                manualTaskunitlistServiceImpl.saveBatch(manualTaskunitlists);
            }

            ArrayList<String> xtaskIdentityLists = manualDTO.getXtaskIdentityList();
            if(CollUtil.isNotEmpty(xtaskIdentityLists)){
                List<PpEManualTaskidentitylist> manualTaskidentitylists = new ArrayList<>();
                for (String xtaskIdentityList : xtaskIdentityLists) {
                    PpEManualTaskidentitylist ppEManualTaskidentitylist = new PpEManualTaskidentitylist();
                    ppEManualTaskidentitylist.setManualXid(manualXid);
                    ppEManualTaskidentitylist.setXtaskIdentityList(xtaskIdentityList);

                    manualTaskidentitylists.add(ppEManualTaskidentitylist);
                }
                manualTaskidentitylistServiceImpl.saveBatch(manualTaskidentitylists);
            }

            ArrayList<String> xrouteLists = manualDTO.getXrouteList();
            if(CollUtil.isNotEmpty(xrouteLists)){
                List<PpEManualRoutelist> manualRoutelists = new ArrayList<>();
                for (String xrouteList : xrouteLists) {
                    PpEManualRoutelist ppEManualRoutelist = new PpEManualRoutelist();
                    ppEManualRoutelist.setManualXid(manualXid);
                    ppEManualRoutelist.setXrouteList(xrouteList);

                    manualRoutelists.add(ppEManualRoutelist);
                }
                manualRoutelistServiceImpl.saveBatch(manualRoutelists);
            }


        }

        ModifyProcessOrAddProcessVO modifyProcessOrAddProcessVO = new ModifyProcessOrAddProcessVO();
        modifyProcessOrAddProcessVO.setXid(processDTO.getXid());
        return JsonVO.success(modifyProcessOrAddProcessVO);
    }

    @Override
    public DeleteProcessVO deleteProcess(String id) {

        //删除process本身
        PpEprocessMapper.deleteById(id);
        processControllerlistServiceImpl.removeById(id);
        processStartablegrouplistServiceImpl.removeById(id);
        processStartableidentitylistServiceImpl.removeById(id);
        processStartableunitlistServiceImpl.removeById(id);


        //删除process中的agent
        QueryWrapper<PpEAgent> queryWrapper_PpEAgent = new QueryWrapper<>();
        queryWrapper_PpEAgent.eq("xprocess", id)
                .select("xid");
        List<String> ids_PpEAgent = agentServiceImpl.list(queryWrapper_PpEAgent)
                .stream()
                .map(PpEAgent::getXid)
                .collect(Collectors.toList());
        for(String id_PpEAgent:ids_PpEAgent){
            agentServiceImpl.removeById(id_PpEAgent);
            agentReaddatapathlistServiceImpl.removeById(id_PpEAgent);
            agentReadgrouplistServiceImpl.removeById(id_PpEAgent);
            agentReadidentitylistServiceImpl.removeById(id_PpEAgent);
            agentReadunitlistServiceImpl.removeById(id_PpEAgent);
            agentReviewdatapathlistServiceImpl.removeById(id_PpEAgent);
            agentReviewgrouplistServiceImpl.removeById(id_PpEAgent);
            agentReviewidentitylistServiceImpl.removeById(id_PpEAgent);
            agentReviewunitlistServiceImpl.removeById(id_PpEAgent);
        }

        //删除process中的begin
        QueryWrapper<PpEBegin> queryWrapper_PpEBegin = new QueryWrapper<>();
        queryWrapper_PpEBegin.eq("xprocess", id)
                .select("xid");
        List<String> ids_PpEBegin = beginServiceImpl.list(queryWrapper_PpEBegin)
                .stream()
                .map(PpEBegin::getXid)
                .collect(Collectors.toList());
        for(String id_PpEBegin:ids_PpEBegin){
            beginServiceImpl.removeById(id_PpEBegin);
            beginReaddatapathlistServiceImpl.removeById(id_PpEBegin);
            beginReadgrouplistServiceImpl.removeById(id_PpEBegin);
            beginReadidentitylistServiceImpl.removeById(id_PpEBegin);
            beginReadunitlistServiceImpl.removeById(id_PpEBegin);
            beginReviewdatapathlistServiceImpl.removeById(id_PpEBegin);
            beginReviewgrouplistServiceImpl.removeById(id_PpEBegin);
            beginReviewidentitylistServiceImpl.removeById(id_PpEBegin);
            beginReviewunitlistServiceImpl.removeById(id_PpEBegin);
        }


        //删除process中的cancel
        QueryWrapper<PpECancel> queryWrapper_PpECancel = new QueryWrapper<>();
        queryWrapper_PpECancel.eq("xprocess", id);
        List<String> ids_PpECancel = cancelServiceImpl.list(queryWrapper_PpECancel)
                .stream()
                .map(PpECancel::getXid)
                .collect(Collectors.toList());
        for(String id_PpEBegin:ids_PpECancel){
            cancelServiceImpl.removeById(id_PpEBegin);
            cancelReaddatapathlistServiceImpl.removeById(id_PpEBegin);
            cancelReadgrouplistServiceImpl.removeById(id_PpEBegin);
            cancelReadidentitylistServiceImpl.removeById(id_PpEBegin);
            cancelReadunitlistServiceImpl.removeById(id_PpEBegin);
            cancelReviewdatapathlistServiceImpl.removeById(id_PpEBegin);
            cancelReviewgrouplistServiceImpl.removeById(id_PpEBegin);
            cancelReviewidentitylistServiceImpl.removeById(id_PpEBegin);
            cancelReviewunitlistServiceImpl.removeById(id_PpEBegin);
        }



        //删除process中的choice
        QueryWrapper<PpEChoice> queryWrapper_PpEChoice = new QueryWrapper<>();
        queryWrapper_PpEChoice.eq("xprocess", id);
        List<String> ids_PpEChoice = choiceServiceImpl.list(queryWrapper_PpEChoice)
                .stream()
                .map(PpEChoice::getXid)
                .collect(Collectors.toList());
        for(String id_PpEChoice:ids_PpEChoice){
            choiceServiceImpl.removeById(id_PpEChoice);
            choiceReaddatapathlistServiceImpl.removeById(id_PpEChoice);
            choiceReadgrouplistServiceImpl.removeById(id_PpEChoice);
            choiceReadidentitylistServiceImpl.removeById(id_PpEChoice);
            choiceReadunitlistServiceImpl.removeById(id_PpEChoice);
            choiceReviewdatapathlistServiceImpl.removeById(id_PpEChoice);
            choiceReviewgrouplistServiceImpl.removeById(id_PpEChoice);
            choiceReviewidentitylistServiceImpl.removeById(id_PpEChoice);
            choiceReviewunitlistServiceImpl.removeById(id_PpEChoice);
            choiceRoutelistServiceImpl.removeById(id_PpEChoice);
        }


        //删除process中的delay
        QueryWrapper<PpEDelay> queryWrapper_PpEDelay = new QueryWrapper<>();
        queryWrapper_PpEDelay.eq("xprocess", id);
        List<String> ids_PpEDelay = delayServiceImpl.list(queryWrapper_PpEDelay)
                .stream()
                .map(PpEDelay::getXid)
                .collect(Collectors.toList());
        for(String id_PpEDealy:ids_PpEDelay){
            delayServiceImpl.removeById(id_PpEDealy);
            delayReaddatapathlistServiceImpl.removeById(id_PpEDealy);
            delayReadgrouplistServiceImpl.removeById(id_PpEDealy);
            delayReadidentitylistServiceImpl.removeById(id_PpEDealy);
            delayReadunitlistServiceImpl.removeById(id_PpEDealy);
            delayReviewdatapathlistServiceImpl.removeById(id_PpEDealy);
            delayReviewgrouplistServiceImpl.removeById(id_PpEDealy);
            delayReviewidentitylistServiceImpl.removeById(id_PpEDealy);
            delayReviewunitlistServiceImpl.removeById(id_PpEDealy);
        }


        //删除process中的embed
        QueryWrapper<PpEEmbed> queryWrapper_PpEEmbed = new QueryWrapper<>();
        queryWrapper_PpEEmbed.eq("xprocess", id);
        List<String> ids_PpEEmbed = embedServiceImpl.list(queryWrapper_PpEEmbed)
                .stream()
                .map(PpEEmbed::getXid)
                .collect(Collectors.toList());
        for(String id_PpEEmbed:ids_PpEEmbed){
            embedServiceImpl.removeById(id_PpEEmbed);
            embedReaddatapathlistServiceImpl.removeById(id_PpEEmbed);
            embedReadgrouplistServiceImpl.removeById(id_PpEEmbed);
            embedReadidentitylistServiceImpl.removeById(id_PpEEmbed);
            embedReadunitlistServiceImpl.removeById(id_PpEEmbed);
            embedReviewdatapathlistServiceImpl.removeById(id_PpEEmbed);
            embedReviewgrouplistServiceImpl.removeById(id_PpEEmbed);
            embedReviewidentitylistServiceImpl.removeById(id_PpEEmbed);
            embedReviewunitlistServiceImpl.removeById(id_PpEEmbed);
        }


        //删除process中的end
        QueryWrapper<PpEEnd> queryWrapper_PpEEnd = new QueryWrapper<>();
        queryWrapper_PpEEnd.eq("xprocess", id);
        List<String> ids_PpEEnd = endServiceImpl.list(queryWrapper_PpEEnd)
                .stream()
                .map(PpEEnd::getXid)
                .collect(Collectors.toList());
        for(String id_PpEEnd:ids_PpEEnd){
            endServiceImpl.removeById(id_PpEEnd);
            endReaddatapathlistServiceImpl.removeById(id_PpEEnd);
            endReadgrouplistServiceImpl.removeById(id_PpEEnd);
            endReadidentitylistServiceImpl.removeById(id_PpEEnd);
            endReadunitlistServiceImpl.removeById(id_PpEEnd);
            endReviewdatapathlistServiceImpl.removeById(id_PpEEnd);
            endReviewgrouplistServiceImpl.removeById(id_PpEEnd);
            endReviewidentitylistServiceImpl.removeById(id_PpEEnd);
            endReviewunitlistServiceImpl.removeById(id_PpEEnd);
        }


        //删除process中的invoke
        QueryWrapper<PpEInvoke> queryWrapper_PpEInvoke = new QueryWrapper<>();
        queryWrapper_PpEInvoke.eq("xprocess", id);
        List<String> ids_PpEInvoke = invokeServiceImpl.list(queryWrapper_PpEInvoke)
                .stream()
                .map(PpEInvoke::getXid)
                .collect(Collectors.toList());
        for(String id_PpEInvoke:ids_PpEInvoke){
            invokeServiceImpl.removeById(id_PpEInvoke);
            invokeReaddatapathlistServiceImpl.removeById(id_PpEInvoke);
            invokeReadgrouplistServiceImpl.removeById(id_PpEInvoke);
            invokeReadidentitylistServiceImpl.removeById(id_PpEInvoke);
            invokeReadunitlistServiceImpl.removeById(id_PpEInvoke);
            invokeReviewdatapathlistServiceImpl.removeById(id_PpEInvoke);
            invokeReviewgrouplistServiceImpl.removeById(id_PpEInvoke);
            invokeReviewidentitylistServiceImpl.removeById(id_PpEInvoke);
            invokeReviewunitlistServiceImpl.removeById(id_PpEInvoke);
        }



        //删除process中的manual
        QueryWrapper<PpEManual> queryWrapper_PpEManual = new QueryWrapper<>();
        queryWrapper_PpEManual.eq("xprocess", id);
        List<String> ids_PpEManual = manualServiceImpl.list(queryWrapper_PpEManual)
                .stream()
                .map(PpEManual::getXid)
                .collect(Collectors.toList());
        for(String id_PpEManual:ids_PpEManual){
            manualServiceImpl.removeById(id_PpEManual);
            manualReaddatapathlistServiceImpl.removeById(id_PpEManual);
            manualReadgrouplistServiceImpl.removeById(id_PpEManual);
            manualReadidentitylistServiceImpl.removeById(id_PpEManual);
            manualReadunitlistServiceImpl.removeById(id_PpEManual);
            manualReviewdatapathlistServiceImpl.removeById(id_PpEManual);
            manualReviewgrouplistServiceImpl.removeById(id_PpEManual);
            manualReviewidentitylistServiceImpl.removeById(id_PpEManual);
            manualReviewunitlistServiceImpl.removeById(id_PpEManual);
            manualRoutelistServiceImpl.removeById(id_PpEManual);
            manualTaskdatapathlistServiceImpl.removeById(id_PpEManual);
            manualTaskgrouplistServiceImpl.removeById(id_PpEManual);
            manualTaskidentitylistServiceImpl.removeById(id_PpEManual);
            manualTaskunitlistServiceImpl.removeById(id_PpEManual);
        }


        //删除process中的merge
        QueryWrapper<PpEMerge> queryWrapper_PpEMerge = new QueryWrapper<>();
        queryWrapper_PpEMerge.eq("xprocess", id);
        List<String> ids_PpEMerge = mergeServiceImpl.list(queryWrapper_PpEMerge)
                .stream()
                .map(PpEMerge::getXid)
                .collect(Collectors.toList());
        for(String id_PpEMerge:ids_PpEMerge){
            mergeServiceImpl.removeById(id_PpEMerge);
            mergeReaddatapathlistServiceImpl.removeById(id_PpEMerge);
            mergeReadgrouplistServiceImpl.removeById(id_PpEMerge);
            mergeReadidentitylistServiceImpl.removeById(id_PpEMerge);
            mergeReadunitlistServiceImpl.removeById(id_PpEMerge);
            mergeReviewdatapathlistServiceImpl.removeById(id_PpEMerge);
            mergeReviewgrouplistServiceImpl.removeById(id_PpEMerge);
            mergeReviewidentitylistServiceImpl.removeById(id_PpEMerge);
            mergeReviewunitlistServiceImpl.removeById(id_PpEMerge);
        }


        //删除process中的parallel
        QueryWrapper<PpEParallel> queryWrapper_PpEParallel = new QueryWrapper<>();
        queryWrapper_PpEParallel.eq("xprocess", id);
        List<String> ids_PpEParallel = parallelServiceImpl.list(queryWrapper_PpEParallel)
                .stream()
                .map(PpEParallel::getXid)
                .collect(Collectors.toList());
        for(String id_PpEParallel:ids_PpEParallel){
            parallelServiceImpl.removeById(id_PpEParallel);
            parallelReaddatapathlistServiceImpl.removeById(id_PpEParallel);
            parallelReadgrouplistServiceImpl.removeById(id_PpEParallel);
            parallelReadidentitylistServiceImpl.removeById(id_PpEParallel);
            parallelReadunitlistServiceImpl.removeById(id_PpEParallel);
            parallelReviewdatapathlistServiceImpl.removeById(id_PpEParallel);
            parallelReviewgrouplistServiceImpl.removeById(id_PpEParallel);
            parallelReviewidentitylistServiceImpl.removeById(id_PpEParallel);
            parallelReviewunitlistServiceImpl.removeById(id_PpEParallel);
            parallelRoutelistServiceImpl.removeById(id_PpEParallel);
        }


        //删除process中的publish
        QueryWrapper<PpEPublish> queryWrapper_PpEPublish = new QueryWrapper<>();
        queryWrapper_PpEPublish.eq("xprocess", id);
        List<String> ids_PpEPublish = publishServiceImpl.list(queryWrapper_PpEPublish)
                .stream()
                .map(PpEPublish::getXid)
                .collect(Collectors.toList());
        for(String id_PpEPublish:ids_PpEPublish){
            publishServiceImpl.removeById(id_PpEPublish);
            publishReaddatapathlistServiceImpl.removeById(id_PpEPublish);
            publishReadgrouplistServiceImpl.removeById(id_PpEPublish);
            publishReadidentitylistServiceImpl.removeById(id_PpEPublish);
            publishReadunitlistServiceImpl.removeById(id_PpEPublish);
            publishReviewdatapathlistServiceImpl.removeById(id_PpEPublish);
            publishReviewgrouplistServiceImpl.removeById(id_PpEPublish);
            publishReviewidentitylistServiceImpl.removeById(id_PpEPublish);
            publishReviewunitlistServiceImpl.removeById(id_PpEPublish);
        }


        //删除process中的service
        QueryWrapper<PpEService> queryWrapper_PpEService = new QueryWrapper<>();
        queryWrapper_PpEService.eq("xprocess", id);
        List<String> ids_PpEService = serviceServiceImpl.list(queryWrapper_PpEService)
                .stream()
                .map(PpEService::getXid)
                .collect(Collectors.toList());
        for(String id_PpEService:ids_PpEService){
            serviceServiceImpl.removeById(id_PpEService);
            serviceReaddatapathlistServiceImpl.removeById(id_PpEService);
            serviceReadgrouplistServiceImpl.removeById(id_PpEService);
            serviceReadidentitylistServiceImpl.removeById(id_PpEService);
            serviceReadunitlistServiceImpl.removeById(id_PpEService);
            serviceReviewdatapathlistServiceImpl.removeById(id_PpEService);
            serviceReviewgrouplistServiceImpl.removeById(id_PpEService);
            serviceReviewidentitylistServiceImpl.removeById(id_PpEService);
            serviceReviewunitlistServiceImpl.removeById(id_PpEService);
            serviceTrustaddresslistServiceImpl.removeById(id_PpEService);
        }



        //删除process中的split
        QueryWrapper<PpESplit> queryWrapper_PpESplit = new QueryWrapper<>();
        queryWrapper_PpESplit.eq("xprocess", id);
        List<String> ids_PpESplit = splitServiceImpl.list(queryWrapper_PpESplit)
                .stream()
                .map(PpESplit::getXid)
                .collect(Collectors.toList());
        for(String id_PpESplit:ids_PpESplit){
            splitServiceImpl.removeById(id_PpESplit);
            splitReaddatapathlistServiceImpl.removeById(id_PpESplit);
            splitReadgrouplistServiceImpl.removeById(id_PpESplit);
            splitReadidentitylistServiceImpl.removeById(id_PpESplit);
            splitReadunitlistServiceImpl.removeById(id_PpESplit);
            splitReviewdatapathlistServiceImpl.removeById(id_PpESplit);
            splitReviewgrouplistServiceImpl.removeById(id_PpESplit);
            splitReviewidentitylistServiceImpl.removeById(id_PpESplit);
            splitReviewunitlistServiceImpl.removeById(id_PpESplit);
        }



        DeleteProcessVO deleteProcessVO=new DeleteProcessVO();
        deleteProcessVO.xid=id;
        return deleteProcessVO;
    }


    @Override
    public ModifyProcessOrAddProcessVO modifyProcessOrAddProcess(ModifyProcessOrAddProcessDTO modifyProcessOrAddProcessDTO) {
        String id=modifyProcessOrAddProcessDTO.processDTO.xid;
        PpEProcess PpEprocess=PpEprocessMapper.selectById(id);
        if(PpEprocess==null){  //这是添加流程操作

        }else{    //这是修改流程操作
            PpEProcess updatePpEProcess = msMapper.processDTOToProcess(modifyProcessOrAddProcessDTO.processDTO);
            PpEprocessMapper.updateById(updatePpEProcess);


            ArrayList<AgentDTO> agentList=modifyProcessOrAddProcessDTO.agentList;
            for(AgentDTO agentDTO:agentList){
                PpEAgent updatePpEAgent= msMapper.agentDTOToAgent(agentDTO);
                agentServiceImpl.updateById(updatePpEAgent);
            }


            PpEBegin updatePpEBegin = msMapper.beginDTOToPpEBegin(modifyProcessOrAddProcessDTO.beginDTO);
            beginServiceImpl.updateById(updatePpEBegin);


            ArrayList<CancelDTO> cancelList=modifyProcessOrAddProcessDTO.cancelList;
            for(CancelDTO cancelDTO:cancelList){
                PpECancel updatePpECancel= msMapper.cancelDTOToPpECancel(cancelDTO);
                cancelServiceImpl.updateById(updatePpECancel);
            }


            ArrayList<ChoiceDTO> choiceList=modifyProcessOrAddProcessDTO.choiceList;
            for(ChoiceDTO choiceDTO:choiceList){
                PpEChoice updatePpEChoice= msMapper.choiceDTOToPpEChoice(choiceDTO);
                choiceServiceImpl.updateById(updatePpEChoice);
            }




        }
        ModifyProcessOrAddProcessVO modifyProcessOrAddProcessVO = new ModifyProcessOrAddProcessVO();
        modifyProcessOrAddProcessVO.xid=id;
        return modifyProcessOrAddProcessVO;
    }


}
