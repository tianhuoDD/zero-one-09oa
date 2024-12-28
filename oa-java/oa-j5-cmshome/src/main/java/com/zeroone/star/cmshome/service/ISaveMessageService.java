package com.zeroone.star.cmshome.service;


import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.cmshome.entity.PublishMessage;
import com.zeroone.star.cmshome.entity.QryItem;
import com.zeroone.star.project.dto.j5.cmshome.NewMessageDTO;
import com.zeroone.star.project.dto.j5.cmshome.PublishMessageDTO;

/**
 * <p>
 * 描述：保存草稿
 * </p>
 * @author wxf
 */
public interface ISaveMessageService extends IService<QryItem> {


    boolean save(PublishMessageDTO publishMessageDTO);


}
