package com.zeroone.star.systemhome.service.impl;

import com.zeroone.star.project.dto.j1.systemhome.DiskFileDTO;
import com.zeroone.star.systemhome.entity.file.FileAttachment;
import com.zeroone.star.systemhome.mapper.FileAttachmentMapper;
import com.zeroone.star.systemhome.service.DiskFileInfoService;
import org.mapstruct.Mapper;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.ArrayList;
import java.util.List;

@Mapper(componentModel = "spring")
interface MsDiskFileMapper{
    /**
     * 将FileAttachment转换成DiskFileInfo
     * @param fileAttachment do对象
     * @return 转换结果
     */
    DiskFileDTO FileAttachment2FileStaticsDTO(FileAttachment fileAttachment);
}
/**
 * @author 李云毅
 * @version 1.0.0
 * 2024/10/24
 */
@Service
public class DiskFileInfoServiceImpl implements DiskFileInfoService {

    @Resource
    FileAttachmentMapper fileAttachmentMapper;

    @Resource
    MsDiskFileMapper msDiskFileMapper;

    @Override
    public List<DiskFileDTO> listDiskFileInfo(String person) {
        //查询我的文件
        List<FileAttachment> fileList = fileAttachmentMapper.selectByPerson(person);
        if (fileList == null) return null;
        //将 fileList 转换为 diskFileDTOList
        List<DiskFileDTO> diskFileDTOList = new ArrayList<>();
        fileList.forEach(f -> {
            DiskFileDTO diskFileDTO = msDiskFileMapper.FileAttachment2FileStaticsDTO(f);
            diskFileDTOList.add(diskFileDTO);
        });
        return diskFileDTOList;
    }
}
