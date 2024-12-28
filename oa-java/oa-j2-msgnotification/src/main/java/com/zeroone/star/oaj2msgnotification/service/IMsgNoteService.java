package com.zeroone.star.oaj2msgnotification.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.oaj2msgnotification.entity.MsgInstant;
import com.zeroone.star.oaj2msgnotification.entity.MsgMessage;
import com.zeroone.star.project.dto.j2.message.notification.MsgInstantDTO;
import com.zeroone.star.project.vo.JsonVO;


public interface IMsgNoteService extends IService<MsgMessage> {
    /**
     * 修改消息状态
     * @param msgInstantDTO 消息实例DTO对象
     * @return 修改后的对象
     */
    JsonVO<MsgInstantDTO> modifyStatus(MsgInstantDTO msgInstantDTO);

    /**
     * 清空消息
     * @param xIds 消息ID字符串
     * @return 清空结果
     */
    JsonVO<Boolean> deleteAllMsg(String xIds);
}
