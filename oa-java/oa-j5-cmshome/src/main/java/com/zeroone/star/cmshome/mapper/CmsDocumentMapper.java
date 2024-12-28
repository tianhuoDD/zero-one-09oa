package com.zeroone.star.cmshome.mapper;

import com.baomidou.mybatisplus.core.conditions.Wrapper;
import com.zeroone.star.cmshome.entity.CmsDocument;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

/**
 * <p>
 *  Mapper 接口
 * </p>
 *
 * @author yuanzijie
 * @since 2024-10-24
 */
@Mapper
public interface CmsDocumentMapper extends BaseMapper<CmsDocument> {

    CmsDocument selectDocumentByXid(@Param("xid") String xid);
}
