package com.zeroone.star.project.j5.cmshome;

import com.zeroone.star.project.dto.j5.cmshome.NewMessageDTO;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
 * 删除消息接口
 * @author wxf
 */
public interface DeleteMessageApis {


    /**
     * 删除消息
     * @param ids
     * @return
     */
    JsonVO<Boolean> deleteMessage(List<String> ids);


}
