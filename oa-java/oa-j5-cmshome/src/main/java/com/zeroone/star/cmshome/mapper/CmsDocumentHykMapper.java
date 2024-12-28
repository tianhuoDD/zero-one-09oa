package com.zeroone.star.cmshome.mapper;

import com.zeroone.star.cmshome.entity.CmsDocumentHyk;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.vo.j5.cmshome.GetColumnMessagesVO;

import com.zeroone.star.project.vo.j5.cmshome.GetDocumentsListVO;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

import java.util.List;

/**
 * <p>
 *  Mapper 接口
 * </p>
 *
 * @author hyk
 * @since 2024-10-30
 */
@Mapper
public interface CmsDocumentHykMapper extends BaseMapper<CmsDocumentHyk> {

    /**
     * 多表联查文档详细信息
     *
     * @param xcategoryName 文档类型
     * @return 文档详细信息列表
     * 单类查询
     */
    List<GetDocumentsListVO> getDocumentsWithDetails(@Param("xcategoryName") String xcategoryName,
                                                     @Param("pageSize") Long pageSize,
                                                     @Param("offset") Long offset);


    /**
     * 统计给定文档类型的总记录数
     *
     * @param xcategoryName 文档名
     * @return 文档总记录数
     * 获取栏目列表
     */
    Long countDocuments(@Param("xcategoryName") String xcategoryName);




    /**
     *
     *
     * @param xid
     * @return
     * 获取栏目详细
     */
    // 获取栏目信息
    List<GetColumnMessagesVO> selectColumnMessagesByXid(@Param("xid") String xid);



}
