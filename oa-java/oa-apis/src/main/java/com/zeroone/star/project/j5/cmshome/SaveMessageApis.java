package com.zeroone.star.project.j5.cmshome;

import com.zeroone.star.project.dto.j5.cmshome.NewMessageDTO;
import com.zeroone.star.project.dto.j5.cmshome.PublishMessageDTO;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
 * 保存草稿接口
 * @author wxf
 */
public interface SaveMessageApis {


    /**
     * 保存草稿
     * @param publishMessageDTO
     * @return
     */
    JsonVO<Boolean> saveMessage(PublishMessageDTO publishMessageDTO);




}
