package com.zeroone.star.project.j3.dataconfig;


import com.zeroone.star.project.j3.dataconfig.vo.dataConfigDetailVO;
import com.zeroone.star.project.j3.dataconfig.vo.dataConfigVO;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

public interface DataConfigApis {
        /**
         * 获取数据配置列表
         * @return dataConfigVO
         */
        public JsonVO<List<dataConfigVO>> queryDataConfigList();

        /**
         * 获取数据配置详情
         * @param xid 数据配置要查找的表的ID
         * @return dataConfigVO
         */
        public JsonVO<dataConfigDetailVO> queryDataConfigDetail(String xid);
}
