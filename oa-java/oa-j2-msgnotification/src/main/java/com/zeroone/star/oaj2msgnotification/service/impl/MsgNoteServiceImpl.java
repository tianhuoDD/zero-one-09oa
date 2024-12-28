package com.zeroone.star.oaj2msgnotification.service.impl;

import com.baomidou.mybatisplus.core.conditions.update.LambdaUpdateWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.oaj2msgnotification.entity.MsgInstant;
import com.zeroone.star.oaj2msgnotification.entity.MsgMessage;
import com.zeroone.star.oaj2msgnotification.mapper.MsgNoteMapper;
import com.zeroone.star.oaj2msgnotification.service.IMsgNoteService;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.j2.message.notification.MsgInstantDTO;
import com.zeroone.star.project.vo.JsonVO;
import lombok.extern.slf4j.Slf4j;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.Resource;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;
@Slf4j
@Service
public class MsgNoteServiceImpl extends ServiceImpl<MsgNoteMapper, MsgMessage> implements IMsgNoteService {
    @Resource
    private UserHolder userHolder;

    /**
     * 修改消息状态
     * @param msgInstantDTO 消息实例DTO对象
     * @return 修改后的消息对象
     */
    @Transactional
    @Override
    public JsonVO<MsgInstantDTO> modifyStatus(MsgInstantDTO msgInstantDTO) {
        //判断消息状态是否已读
        if(msgInstantDTO.getXconsumed()!=Boolean.FALSE){
            return JsonVO.success(msgInstantDTO);
        }
        //改变数据库消息状态
        LambdaUpdateWrapper<MsgMessage> updateWrapper = new LambdaUpdateWrapper<>();
        updateWrapper.eq(MsgMessage::getXid, msgInstantDTO.getXid())
                .set(MsgMessage::getXconsumed,true);
        baseMapper.update(null, updateWrapper);
        //返回修改后的对象
        msgInstantDTO.setXconsumed(true);
        return JsonVO.success(msgInstantDTO);
    }

    /**
     * 清空消息
     * @param xIds 消息ID字符串
     * @return 清空结果
     */
    @Transactional
    @Override
    public JsonVO<Boolean> deleteAllMsg(String xIds) {
        List<String>ids= Arrays.stream(xIds.split(",")).collect(Collectors.toList());
        //清空数据的消息
        baseMapper.deleteBatchIds(ids);
        return JsonVO.success(true);
    }
}
