package com.zeroone.star.project.j5.cmshome;


import com.zeroone.star.project.dto.j5.cmshome.NewMessageDTO;
import com.zeroone.star.project.query.j5.cmshome.newMessage.NewMessageQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j5.cmshome.newMessage.NewEditVO;
import com.zeroone.star.project.vo.j5.cmshome.newMessage.NewMessageVO;

public interface NewMessageApis {

    /**
     * 获取新建消息面板信息
     * @param  newQuery 查询条件
     * @return 获取到的信息
     */
    JsonVO<NewMessageVO> queryNewMessage(NewMessageQuery newQuery);

    /**
     * 获取新建消息的编辑面板信息
     * @param  xid 新建消息id
     * @return 获取到的信息
     */
    JsonVO<NewEditVO> queryNewEdit(String xid);

    /**
     * 上传新建的消息
     * @param  newMessageDTO 新建消息信息
     * @return 是否新建成功
     */
    JsonVO<Boolean> addNewMessage(NewMessageDTO newMessageDTO);

    /**
     * 上传编辑的新建消息
     * @param  newEditDTO 编辑新建消息信息
     * @return 是否编辑成功

    JsonVO<Boolean> addNewMessageEdit(NewEditDTO newEditDTO);*/
}
