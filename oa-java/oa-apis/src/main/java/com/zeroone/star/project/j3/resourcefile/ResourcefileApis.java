package com.zeroone.star.project.j3.resourcefile;

import com.zeroone.star.project.j3.resourcefile.dto.CmsFileDTO;
import com.zeroone.star.project.j3.resourcefile.vo.CmsFileVO;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.web.multipart.MultipartFile;

import java.util.List;

public interface ResourcefileApis {

    /**
     * @Description 获得附件列表
     * @Param [xappId] 附件列表编号
     * @return Long
     */
    public JsonVO<List<CmsFileVO>> queryFlieAttachmentList(String xappId);

    /**
     * @Description 获得附件详情
     * @Param [xid] 附件编号
     * @return Long
     */
    public JsonVO<CmsFileVO> queryAttachmentDetail(String xid);

    /**
     * @Description 新增附件
     * @Param [fileAttachmentVTO] vo
     * @return Long
     */
    public JsonVO<Integer> addfile(MultipartFile file, String username, String xappId);

    /**
     * @Description 删除附件
     * @Param [xid] 附件编号
     * @return Long
    */
    public JsonVO<Integer> removefile(String xid);

    /**
     * @Description 修改附件
     * @Param [CmsFileDTO] dto
     * @return Long
    */
    public JsonVO<Integer> modifyfile(CmsFileDTO CmsFileDTO);
}
