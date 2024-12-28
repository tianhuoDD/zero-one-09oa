package com.zeroone.star.project.j5.cmshome;


import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j5.cmshome.GetColumnMessagesVO;


import java.util.List;


public interface GetColumnMessagesApis {

    /**
     * 获取栏目信息
     *
     * @return 获取到的信息
     */
    JsonVO<List<GetColumnMessagesVO>> queryColumnMessages(String xid);

}
