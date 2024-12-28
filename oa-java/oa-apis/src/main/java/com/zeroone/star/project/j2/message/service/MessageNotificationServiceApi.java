package com.zeroone.star.project.j2.message.service;


import com.zeroone.star.project.dto.j2.message.service.MessageNotifyServiceDTO;
import com.zeroone.star.project.vo.JsonVO;

public interface MessageNotificationServiceApi {

    /**
     * 处理系统通知
     * @param message
     * @return
     */
    public JsonVO<String> sysmsg(MessageNotifyServiceDTO message);

}