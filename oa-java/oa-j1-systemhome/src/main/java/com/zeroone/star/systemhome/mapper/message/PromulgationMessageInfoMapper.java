package com.zeroone.star.systemhome.mapper.message;

import com.zeroone.star.project.dto.j1.message.getting.PromulgationMessageInfoDTO;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

@Mapper
public interface PromulgationMessageInfoMapper {
    /**
     * 获取公告信息
     * @param personId 登录人id
     * @return 结果
     */
    List<PromulgationMessageInfoDTO> selectPMI(String personId);
}
