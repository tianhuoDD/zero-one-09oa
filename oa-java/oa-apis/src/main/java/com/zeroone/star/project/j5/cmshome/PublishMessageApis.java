package com.zeroone.star.project.j5.cmshome;

import com.zeroone.star.project.dto.j5.cmshome.NewMessageDTO;
import com.zeroone.star.project.dto.j5.cmshome.PublishMessageDTO;
import com.zeroone.star.project.vo.JsonVO;


/**
 * 发布消息接口
 * @author wxf
 */
public interface PublishMessageApis {
    /**
     * 发布新建的消息
     *
     * @param  publishMessageDTO
     * @return
     */
    JsonVO<Boolean> publishMessage(PublishMessageDTO publishMessageDTO);



}
