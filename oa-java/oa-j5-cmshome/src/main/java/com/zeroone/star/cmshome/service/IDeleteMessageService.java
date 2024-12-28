package com.zeroone.star.cmshome.service;


import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.cmshome.entity.PublishMessage;
import com.zeroone.star.cmshome.entity.QryItem;
import com.zeroone.star.project.dto.j5.cmshome.NewMessageDTO;

import java.util.List;

/**
 * <p>
 * 删除消息
 * </p>
 * @author wxf
 */
public interface IDeleteMessageService extends IService<QryItem> {


    boolean delete(List<String> ids);


}
