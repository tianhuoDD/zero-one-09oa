package com.zeroone.star.filemanager.mapper;

import com.zeroone.star.filemanager.entity.FileAttachment;
import com.zeroone.star.filemanager.entity.FileAttachmentEditorlist;
import com.zeroone.star.filemanager.entity.FileAttachmentSharelist;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.dto.j6.file.ShareFileDTO;
import com.zeroone.star.project.dto.j6.file.ShareUserDTO;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Select;
import org.mapstruct.Mapping;

import java.util.List;

/**
 * <p>
 *  Mapper 接口
 * </p>
 *
 * @author j6
 * @since 2024-10-23
 */
@Mapper
public interface FileAttachmentSharelistMapper extends BaseMapper<FileAttachmentSharelist> {
//    /**
//     * 将 FileAttachment 转换为 SharedFileDTO
//     *
//     * @param attachment 文件附件实体
//     * @return 共享文件 DTO
//     */
//    @Mapping(source = "xid", target = "fileId")
//    @Mapping(source = "xname", target = "fileName")
//    @Mapping(source = "xlength", target = "fileSize")
//    @Mapping(source = "xextension", target = "fileType")
//    @Mapping(expression = "java(com.zeroone.star.project.j6.file_management.service.impl.FileManagementServiceImpl.generateFileUrl(attachment))", target = "fileUrl")
//    @Mapping(source = "xupdateTime", target = "sharedTime", dateFormat = "yyyy-MM-dd'T'HH:mm:ss")
//    ShareFileDTO fileAttachmentToSharedFileDTO(FileAttachment attachment);
//
//    /**
//     * 将用户名转换为 SharedUserDTO
//     *
//     * @param username 用户名
//     * @return 共享用户 DTO
//     */
//    ShareUserDTO usernameToSharedUserDTO(String username);

    /**
     * 获取所有共享用户的用户名（去重）
     *
     * @return 用户名列表
     */
//    @Select("SELECT DISTINCT TRIM(SUBSTRING_INDEX(SUBSTRING_INDEX(xshareList, ',', numbers.n), ',', -1)) AS username " +
//            "FROM file_attachment_sharelist " +
//            "JOIN (SELECT @rownum := @rownum + 1 AS n FROM " +
//            "(SELECT 1 UNION ALL SELECT 2 UNION ALL SELECT 3 UNION ALL SELECT 4 UNION ALL SELECT 5 UNION ALL SELECT 6 UNION ALL SELECT 7 UNION ALL SELECT 8 UNION ALL SELECT 9 UNION ALL SELECT 10) t1, " +
//            "(SELECT @rownum := 0) t2) numbers " +
//            "WHERE numbers.n <= LENGTH(xshareList) - LENGTH(REPLACE(xshareList, ',', '')) + 1 " +
//            "ORDER BY username")
//     List<String> selectAllShareUserNames();
    @Select("SELECT DISTINCT TRIM(SUBSTRING_INDEX(SUBSTRING_INDEX(xshareList, ',', numbers.n), ',', -1)) AS username " +
            "FROM file_attachment_sharelist " +
            "JOIN (SELECT @rownum := @rownum + 1 AS n FROM " +
            "(SELECT 1 UNION ALL SELECT 2 UNION ALL SELECT 3 UNION ALL SELECT 4 UNION ALL SELECT 5 UNION ALL SELECT 6 UNION ALL SELECT 7 UNION ALL SELECT 8 UNION ALL SELECT 9 UNION ALL SELECT 10) t1, " +
            "(SELECT @rownum := 0) t2) numbers " +
            "WHERE numbers.n <= LENGTH(xshareList) - LENGTH(REPLACE(xshareList, ',', '')) + 1 " +
            "AND TRIM(SUBSTRING_INDEX(SUBSTRING_INDEX(xshareList, ',', numbers.n), ',', -1)) <> '' " +
            "ORDER BY username")
    List<String> selectAllShareUserNames();



    /**
     * 获取指定共享用户的共享文件列表（分页）
     *
     * @param userId 用户ID
     * @return 共享文件列表
     */
    @Select("SELECT fa.xid AS fileId, " +
            "fa.xname AS fileName, " +
            "fa.xlength AS fileSize, " +
            "fa.xextension AS fileType, " +
            "DATE_FORMAT(fa.xcreatetime, '%Y-%m-%dT%H:%i:%s') AS uploadTime, " +
            "DATE_FORMAT(fa.xlastUpdateTime, '%Y-%m-%dT%H:%i:%s') AS sharedTime, " +
            "fa.xperson AS sharedUserId, " +
            "CONCAT(fa.xstorage, '/', fa.xfolder, '/', fa.xid, '.', fa.xextension) AS fileUrl, " +
            "fa.xupdateTime " +
            "FROM file_attachment fa " +
            "JOIN file_attachment_sharelist fas ON fa.xid = fas.attachment_xid " +
            "WHERE FIND_IN_SET(#{userId}, fas.xshareList) " +
            "ORDER BY fas.xorderColumn DESC")
    List<ShareFileDTO> selectShareFilesOfUser(@Param("userId") Long userId);
    /**
     * 统计指定共享用户的共享文件总数
     *
     * @param userId 用户ID
     * @return 总数
     */
    @Select("SELECT COUNT(*) " +
            "FROM file_attachment_sharelist " +
            "WHERE FIND_IN_SET(#{userId}, xshareList)")
    Long countShareFilesOfUser(@Param("userId") Long userId);


    Boolean insertDownSharelist(FileAttachmentSharelist fileAttachmentSharelist);

    Boolean insertEditSharelist(FileAttachmentEditorlist fileAttachmentEditorlist);
}
