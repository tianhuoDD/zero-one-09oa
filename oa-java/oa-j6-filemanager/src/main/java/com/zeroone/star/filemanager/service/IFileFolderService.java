package com.zeroone.star.filemanager.service;

import com.zeroone.star.filemanager.entity.FileFolder;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.j6.file.FileFolderDTO;
import com.zeroone.star.project.dto.j6.file.FolderDTO;
import com.zeroone.star.project.query.j6.file.FolderQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j6.file.FileFolderVO;
import com.zeroone.star.project.vo.j6.file.FolderVO;

import java.util.List;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author j6
 * @since 2024-10-23
 */
public interface IFileFolderService extends IService<FileFolder> {
    /**
     * 重命名目录
     * @param xid
     * @param new_xname
     * @param xsuperior
     * @return
     */
    public boolean updateFileFolderName(String xid,String new_xname,String xsuperior);
    /**
     * 添加目录
     * @param fileFolderDTO
     * @return
     */
    Integer insertFolder(FileFolderDTO fileFolderDTO);

    /**
     * 删除目录和该目录下所有内容
     * @param id
     * @return
     */
    Integer rmFolderById(String id);


    /**
     * 分页查询指定目录内的文件夹
     * @return
     */
    List<FileFolderVO> getPageFolder(FolderQuery folderQuery);
}
