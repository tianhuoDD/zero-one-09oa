package com.zeroone.star.systemhome.service;

import com.zeroone.star.project.dto.j1.systemhome.DiskFileDTO;

import java.util.List;

/**
 * @author 李云毅
 * @version 1.0.0
 * 2024/10/24
 */
public interface DiskFileInfoService {

    /**
     * 获取文件信息
     * @param person 用户名
     * @return 文件信息
     */
    List<DiskFileDTO> listDiskFileInfo(String person);

}
