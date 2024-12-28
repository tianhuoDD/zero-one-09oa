package com.zeroone.star.columnsetting.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.columnsetting.entity.CmsFile;
import com.zeroone.star.project.j3.resourcefile.dto.CmsFileDTO;
import com.zeroone.star.project.j3.resourcefile.vo.CmsFileVO;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

import java.util.List;

/**
 * <p>
 *  Mapper 接口
 * </p>
 *
 * @author lfh59 and trigger
 * @since 2024-10-26
 */
@Mapper
public interface CmsFileMapper extends BaseMapper<CmsFile> {
    /**
     * @Description 获得附件列表
     * @return List<CmsFileDTO>
     */
    List<CmsFileVO> getFileAttachmentList();

    /**
     * @Description  获得附件详情
     * @Param @Param [xid] 附件ID
     * @return CmsFileVO
     */
    CmsFileVO getFileAttachmentDetail(@Param("xid") String xid);

    /**
     * @Description  新增附件
     * @Param [xid] [CmsFileVO]  vo
     * @return java.lang.Long
     */
    CmsFileVO insertfile(CmsFileDTO CmsFileDTO);

    /**
     * @Description 删除附件
     * @Param [xid] 需要删除的编号
     * @return java.lang.Long
     */
    //public Boolean deletefile(String xid);

    /**
     * @Description  修改附件
     * @Param [CmsFileDTO]  dto
     * @return java.lang.Long
     */

    //public Boolean updatefile(CmsFileDTO CmsFileDTO);
}
