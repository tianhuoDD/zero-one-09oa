package com.zeroone.star.columnsetting.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.columnsetting.entity.CmsFile;
import com.zeroone.star.project.j3.resourcefile.dto.CmsFileDTO;
import com.zeroone.star.project.j3.resourcefile.vo.CmsFileVO;
import org.apache.ibatis.annotations.Param;

import java.util.List;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author lfh59 and trigger
 * @since 2024-10-26
 */
public interface ICmsFileService extends IService<CmsFile> {

    /**
     * @return List<CmsFileDTO>
     * @Description 获得附件列表
     */
    List<CmsFileVO> getAttachmentList(@Param("xappId") String xappId);

    /**
     * @return java.lang.Long
     * @Description 获得附件详情
     * @Param @Param [xid] 附件ID
     */
    CmsFileVO getAttachmentDetail(@Param("xid") String xid);

    /**
     * @return CmsFileDTO
     * @Description 新增附件
     * @Param [xid] [CmsFileDTO]  dto
     */
    Integer insertfile(CmsFileDTO CmsFileDTO,String username,String appId);


    /**
     * @Description 删除附件
     * @Param [xid] 需要删除的编号
     * @return java.lang.Long
     */
    Integer deletefile( String xid);
    /**
     * @Description  修改附件
     * @Param [CmsFileDTO]  dto
     * @return java.lang.Long
     */

    Integer updatefile(CmsFileDTO CmsFileDTO);
}
