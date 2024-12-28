package com.zeroone.star.filemanager.mapper;

import com.baomidou.mybatisplus.core.metadata.IPage;
import com.baomidou.mybatisplus.core.toolkit.Constants;
import com.zeroone.star.filemanager.entity.FileFolder;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.vo.j6.file.FolderVO;
import org.apache.ibatis.annotations.Delete;
import org.apache.ibatis.annotations.Insert;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;
import org.apache.poi.ss.formula.functions.T;

import java.sql.Wrapper;
import java.util.Map;

/**
 * <p>
 *  Mapper 接口
 * </p>
 *
 * @author j6
 * @since 2024-10-23
 */
@Mapper
public interface FileFolderMapper extends BaseMapper<FileFolder> {

    int deleteAttachmentsByFolderId(@Param("folderId") String folderId);
    int deleteFolderByFolderId(@Param("folderId") String folderId);

    @Delete("delete from file_folder where xid = #{folderId}")
    int deleteByFolderId(String folderId);

//    IPage<T> queryTest(IPage<T> page, @Param(Constants.WRAPPER) Wrapper<T> wrapper);

    @Insert("insert into file_folder(xid, xname, xperson, xsuperior, xcreateTime, xupdateTime, xsequence) " +
            "values(#{xid}, #{xname}, #{xperson}, #{xsuperior}, #{xcreateTime}, #{xupdateTime}, #{xsequence})")
    int insertFileFolder(FileFolder fileFolder);

    int updateFolderByFolderId(Map<String,Object> params);
}
