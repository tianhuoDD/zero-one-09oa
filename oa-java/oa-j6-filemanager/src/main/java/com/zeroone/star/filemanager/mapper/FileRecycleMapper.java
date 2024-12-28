package com.zeroone.star.filemanager.mapper;

import com.zeroone.star.filemanager.entity.FileRecycle;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.dto.j6.file.ReceivedFileDTO;
import com.zeroone.star.project.dto.j6.file.ReceivedUserDTO;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Select;

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
public interface FileRecycleMapper extends BaseMapper<FileRecycle> {
    /**
     * 获取所有接收文件的用户ID（去重）
     *
     * @return 用户ID列表
     */
    @Select("SELECT DISTINCT xperson AS userId " +
            "FROM file_recycle " +
            "WHERE xperson IS NOT NULL AND xperson <> ''")
    List<String> selectAllReceivedUserIds();

    /**
     * 获取指定用户的接收文件列表（分页）
     *
     * @param userId 用户ID
     * @return 接收文件列表
     */
    @Select("SELECT fr.xid AS fileId, " +
            "fr.xname AS fileName, " +
            "fr.xlength AS fileSize, " +
            "fr.xextension AS fileType, " +
            "DATE_FORMAT(fr.xcreateTime, '%Y-%m-%dT%H:%i:%s') AS receivedTime, " +
            "fr.xperson AS userId, " +
            "CONCAT(fr.xstorage, '/', fr.xfolder, '/', fr.xid, '.', fr.xextension) AS fileUrl " +
            "FROM file_recycle fr " +
            "WHERE fr.xperson = #{userId} " +
            "ORDER BY fr.xupdateTime DESC")
    List<ReceivedFileDTO> selectReceivedFilesOfUser(@Param("userId") String userId);

    /**
     * 统计指定用户的接收文件总数
     *
     * @param userId 用户ID
     * @return 文件总数
     */
    @Select("SELECT COUNT(*) " +
            "FROM file_recycle " +
            "WHERE xperson = #{userId}")
    Long countReceivedFilesOfUser(@Param("userId") String userId);

    /**
     * 获取接收用户列表（分页）
     *
     * @param start 起始位置
     * @param limit 分页大小
     * @return 接收用户列表
     */
    @Select("SELECT DISTINCT xperson AS userId, COUNT(*) AS fileCount " +
            "FROM file_recycle " +
            "WHERE xperson IS NOT NULL AND xperson <> '' " +
            "GROUP BY xperson " +
            "ORDER BY fileCount DESC " +
            "LIMIT #{start}, #{limit}")
    List<ReceivedUserDTO> selectReceivedUserList(@Param("start") int start, @Param("limit") int limit);

}