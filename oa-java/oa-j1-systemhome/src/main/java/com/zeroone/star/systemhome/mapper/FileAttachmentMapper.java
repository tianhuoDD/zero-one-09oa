package com.zeroone.star.systemhome.mapper;

import com.zeroone.star.systemhome.entity.file.FileAttachment;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;

import java.util.Date;
import java.util.List;

/**
 * <p>
 *  Mapper 接口
 * </p>
 *
 * @author 李云毅
 * @since 2024-10-21
 */
@Mapper
public interface FileAttachmentMapper extends BaseMapper<FileAttachment> {

    List<FileAttachment> selectByPerson(String person);

    Integer countUploadFile(String xperson, Date startDate, Date endDate);
}
