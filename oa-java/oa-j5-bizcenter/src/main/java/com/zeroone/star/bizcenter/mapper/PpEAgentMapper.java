package com.zeroone.star.bizcenter.mapper;

import com.zeroone.star.bizcenter.entity.PpEAgent;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.bizcenter.entity.PpEAgentReaddatapathlist;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

/**
 * <p>
 *  Mapper 接口
 * </p>
 *
 * @author xiongjian
 * @since 2024-10-27
 */
@Mapper
public interface PpEAgentMapper extends BaseMapper<PpEAgent> {

    List<PpEAgentReaddatapathlist> getReaddatapathlist(List<String> ids);
}
