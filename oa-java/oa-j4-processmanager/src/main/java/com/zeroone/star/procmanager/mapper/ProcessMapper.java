package com.zeroone.star.procmanager.mapper;
import java.util.List;
import org.apache.ibatis.annotations.Param;


import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.procmanager.entity.PpEProcess;
import org.apache.ibatis.annotations.Mapper;

/**
 * <p>
 *  Mapper 接口
 * </p>
 *
 * @author awei
 * @since 2024-10-21
 */
@Mapper
public interface ProcessMapper extends BaseMapper<PpEProcess> {
    /**
     * 查询应用的流程
     * @param id
     * @return
     */

    List<String> selectNameById(@Param("xid") String id);
}
