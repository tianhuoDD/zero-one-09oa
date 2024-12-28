package com.zeroone.star.cmshome.service;


import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.cmshome.entity.PublishMessage;
import com.zeroone.star.project.dto.j5.cmshome.NewMessageDTO;
import com.zeroone.star.project.dto.j5.cmshome.PublishMessageDTO;

/**
 * <p>
 * 发布消息
 * </p>
 * @author wxf
 */
public interface IPublishMessageService extends IService<PublishMessage> {


    boolean save(PublishMessageDTO publishMessageDTO);


}
