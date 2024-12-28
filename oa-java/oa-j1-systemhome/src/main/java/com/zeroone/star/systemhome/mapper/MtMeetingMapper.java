package com.zeroone.star.systemhome.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.systemhome.entity.file.MtMeeting;
import org.apache.ibatis.annotations.Mapper;

/**
 * <p>
 *  mapper接口，对应mt_meeting表格，MtMeetingMapper实体类
 * </p>
 *
 * @author j1.rabbit
 * @since 2024-10-27
 */
@Mapper
public interface MtMeetingMapper extends BaseMapper<MtMeeting> {
}
