package com.zeroone.star.project.j1.message;


import com.zeroone.star.project.dto.j1.message.getting.PromulgationMessageInfoDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j1.message.getting.PromulgationMessageInfoVO;

import java.util.List;

/**
 * @BelongsProject: oa-java
 * @BelongsPackage: com.zeroone.star.project.j1.message
 * @Author: dashuai
 * @CreateTime: 2024-10-21  00:13
 * @Description: 发布的信息的消息的有关接口
 * @Version: 1.0
 */
public interface GetPromulgationMessageInfoApis {
    /**
     * @description: 消息发布对应的接口
     * @author: dashuai
     * @date: 2024/10/21 10:55
     * @param: [PersonId] 账号人对应的id
     * @return: List<JsonVO<PromulgationMessageInfoVO>> 消息集合
     **/
    JsonVO<List<PromulgationMessageInfoDTO>> queryPromulgationMessageInfo(String PersonId);
}
