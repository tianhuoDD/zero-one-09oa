package com.zeroone.star.oaj2sysbasic.service.impl;

import cn.hutool.core.bean.BeanUtil;
import cn.hutool.core.collection.CollectionUtil;
import cn.hutool.extra.spring.SpringUtil;
import com.zeroone.star.oaj2sysbasic.constant.SysBasicConstant;
import com.zeroone.star.oaj2sysbasic.entity.SystemBasicInformation;
import com.zeroone.star.oaj2sysbasic.mapper.SystemBasicInformationRepository;
import com.zeroone.star.oaj2sysbasic.service.SystemBasicInformationService;
import com.zeroone.star.project.vo.j2.system.basic.information.SystemBasicInformationVO;
import org.apache.commons.lang.StringUtils;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.Resource;
import java.util.List;

/**
 * @ClassName: SystemBasicInformationServiceImpl
 * @Package: com.zeroone.star.oaj2sysbasic.service.impl
 * @Description: 系统基本信息service层实现类
 * @Author: zk
 * @Create: 2024/10/24 - 下午12:37
 */
@Service
public class SystemBasicInformationServiceImpl implements SystemBasicInformationService {

    @Resource
    private SystemBasicInformationRepository repository;

    @Override
    public SystemBasicInformationVO getSysBasicInfo() {
        List<SystemBasicInformation> basInfo = repository.findAll();
        SystemBasicInformationVO vo = new SystemBasicInformationVO();
        SystemBasicInformation systemBasicInformation;
        if (!CollectionUtil.isEmpty(basInfo)) {
            // 如果不为空
            systemBasicInformation = basInfo.get(0);
        } else {
            systemBasicInformation = new SystemBasicInformation();
            systemBasicInformation.setEnable(false);
            systemBasicInformation.setSslEnable(false);
            systemBasicInformation.setAppPackCoverAppUrl(false);
            systemBasicInformation = repository.save(systemBasicInformation);
        }
        // 属性拷贝
        BeanUtil.copyProperties(systemBasicInformation, vo, true);

        if (StringUtils.isBlank(vo.getTitle())) {
            vo.setTitle("企业办公平台");
        }
        if (StringUtils.isBlank(vo.getFooter())) {
            vo.setFooter("www.o2oa.net");
        }
        return vo;
    }

    @Override
    @Transactional
    public String updateSysTitle(String sysTitle) {
        try {
            // 先获取
            SystemBasicInformation systemBasicInformation = repository.findAll().get(0);
            String id = systemBasicInformation.getId();
            // 再删除
            repository.deleteById(id);
            // 最后新增
            systemBasicInformation.setTitle(sysTitle);
            repository.save(systemBasicInformation);
            return SysBasicConstant.MODIFY_SUCCESS;
        } catch (Exception e) {
            e.printStackTrace();
            return SysBasicConstant.MODIFY_ERROR;
        }
    }

    @Override
    @Transactional
    public String updateSysFooter(String sysFooter) {
        try {
            // 先获取
            SystemBasicInformation systemBasicInformation = repository.findAll().get(0);
            String id = systemBasicInformation.getId();
            // 再删除
            repository.deleteById(id);
            // 最后新增
            systemBasicInformation.setFooter(sysFooter);
            repository.save(systemBasicInformation);
            return SysBasicConstant.MODIFY_SUCCESS;
        } catch (Exception e) {
            e.printStackTrace();
            return SysBasicConstant.MODIFY_ERROR;
        }
    }
}
