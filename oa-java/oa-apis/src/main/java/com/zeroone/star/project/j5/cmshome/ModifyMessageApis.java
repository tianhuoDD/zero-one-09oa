package com.zeroone.star.project.j5.cmshome;

import com.zeroone.star.project.dto.j5.cmshome.ModifyEditMessageDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j5.cmshome.modifyMessage.ModifyEditVO;


public interface ModifyMessageApis {

    /**
     * 获取修改消息的编辑面板信息
     * @param  xid 新建消息id
     * @return 获取到的信息
     */
    JsonVO<ModifyEditVO> queryNewEdit(String xid);

    /**
     * 更新上传修改消息信息
     * @param
     * @return 修改结果
     */
    JsonVO<Boolean> updateEditMessage(ModifyEditMessageDTO modifyEditMessageDTO);
}
