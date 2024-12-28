package com.zeroone.star.bizcenter.service.impl;

import com.zeroone.star.bizcenter.service.IPpEManualService;
import com.zeroone.star.bizcenter.entity.PpEManual;
import com.zeroone.star.bizcenter.mapper.PpEManualMapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.utils.date.DateUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.time.LocalDateTime;
import java.util.UUID;

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author xiongjian
 * @since 2024-10-25
 */
@Service
public class PpEManualServiceImpl extends ServiceImpl<PpEManualMapper, PpEManual> implements IPpEManualService {

    @Autowired
    private PpEManualMapper ppEManualMapper;

    /**
     * 保存流程模板
     * @param processId 流程id
     */
    public String savePpEManualWithProcessId(String processId){
        String uuid = UUID.randomUUID().toString();

        PpEManual ppEManual = PpEManual.builder()
                .xid(uuid)
                .xcreateTime(LocalDateTime.now())
                .xsequence(DateUtils.getDateToString() + uuid)
                .xupdateTime(LocalDateTime.now())
                .xdistributeFactor(null)
                .xallowDeleteWork(false)
                .xallowReroute(true)
                .xallowRerouteTo(true)
                .xallowReset(true)
                .xallowRetract(true)
//                .xedition()
//                .xform()
                .xmanualMode("single")
                .xname("拟稿")
                .xproperties(null)
                .xposition(processId)
                .xresetCount(0)
                .xresetRange("department")
                .xtaskExpireType("never")
                .build();
        int affectRows = ppEManualMapper.insert(ppEManual);
        if (affectRows<=0){
            throw new RuntimeException("保存流程模板失败");
        }
        return uuid;
    }

    /**
     * 根据流程模板id查询流程模板
     * @param id 流程模板id
     * @return
     */
    @Override
    public PpEManual getPpEManualById(String id) {
        return ppEManualMapper.selectById(id);
    }
}
