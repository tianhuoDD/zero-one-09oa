package com.zeroone.star.bizcenter.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.bizcenter.entity.PPEApplication;
import com.zeroone.star.bizcenter.entity.zyPPEProcess;
import com.zeroone.star.bizcenter.mapper.PPEApplicationMapper;
import com.zeroone.star.bizcenter.service.PPEApplicationService;
import com.zeroone.star.bizcenter.service.zyPPEProcessService;
import com.zeroone.star.project.dto.j5.bizcenter.ProcessDTO;
import com.zeroone.star.project.vo.j5.bizcenter.ApplicationListVO;
import lombok.SneakyThrows;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;

@Service
public class PPEApplicationServiceImpl extends ServiceImpl<PPEApplicationMapper, PPEApplication> implements PPEApplicationService {
    @Autowired
    private PPEApplicationMapper ppeApplicationMapper;

    @Autowired
    private zyPPEProcessService zyPpeProcessService;

    /**
     * 获取应用列表
     * @return 应用列表
     */
    @SneakyThrows
    public List<ApplicationListVO> listApplications() {
        //1.获取所有应用列表
        List<PPEApplication> ppeApplications = ppeApplicationMapper.selectList(null);
        if (ppeApplications.isEmpty()) {
            throw new RuntimeException("应用列表为空");
        }

        List<ApplicationListVO> applicationListVOS = new ArrayList<>();
        for (PPEApplication ppeApplication : ppeApplications) {
            //2.根据应用名称查找应用id
            String appId = getApplicationIdByName(ppeApplication.getXname());
            //3.根据应用id 查找流程列表
            List<zyPPEProcess> zyPpeProcesses = zyPpeProcessService.listProcessListByAppId(appId);
            //4.将查找的流程列表成DTO对象
            List<ProcessDTO> processDTOS = new ArrayList<>();
            for (zyPPEProcess zyPpeProcess : zyPpeProcesses) {
                ProcessDTO processDTO = new ProcessDTO().builder()
                        .id(zyPpeProcess.getXid())
                        .application(zyPpeProcess.getXapplication())
                        .name(zyPpeProcess.getXname())
                        .creatorPerson(zyPpeProcess.getXcreatorPerson())
                        .lastUpdateTime(zyPpeProcess.getXlastUpdateTime())
                        .edition(zyPpeProcess.getXedition())
                        .editionName(zyPpeProcess.getXeditionName())
                        .editionEnable(zyPpeProcess.getXeditionEnable())
                        .editionNumber(zyPpeProcess.getXeditionNumber())
                        .createTime(zyPpeProcess.getXcreateTime())
                        .updateTime(zyPpeProcess.getXupdateTime())
                        .build();
                processDTOS.add(processDTO);
            }

            //5.将数据封装成VO对象
            ApplicationListVO applicationListVO = new ApplicationListVO().builder()
                    .id(ppeApplication.getXid())
                    .name(ppeApplication.getXname())
                    .applicationCategory(ppeApplication.getXapplicationCategory())
                    .icon(ppeApplication.getXicon())
                    .iconHue(ppeApplication.getXiconHue())
                    .lastUpdatePerson(ppeApplication.getXcreatorPerson())
                    .lastUpdateTime(ppeApplication.getXupdateTime())
                    .createTime(ppeApplication.getXcreateTime())
                    .updateTime(ppeApplication.getXupdateTime())
                    .processList(processDTOS).build();
            applicationListVOS.add(applicationListVO);
        }

        if (applicationListVOS.isEmpty()) {
            throw new RuntimeException("应用列表为空");
        }

        return applicationListVOS;
    }

    /**
     * 根据应用名称查询应用id
     * @param name 应用名称
     * @return 应用id
     */
    public String getApplicationIdByName(String name) {
        //2.根据应用名称查找应用id
        QueryWrapper<PPEApplication> queryWrapper = new QueryWrapper<>();
        queryWrapper.select("xid").eq("xname",name);
        PPEApplication result = ppeApplicationMapper.selectOne(queryWrapper);
        if (result == null){
            throw new RuntimeException("应用名对应的应用id不存在");
        }
        return result.getXid();
    }

}
