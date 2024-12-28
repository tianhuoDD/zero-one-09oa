package com.zeroone.star.filemanager.service.impl;

import com.zeroone.star.filemanager.entity.FileAttachmentEditorlist;
import com.zeroone.star.filemanager.entity.FileAttachmentSharelist;
import com.zeroone.star.filemanager.mapper.FileAttachmentSharelistMapper;
import com.zeroone.star.filemanager.service.IFileAttachmentSharelistService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j6.file.ShareFileDTO;
import com.zeroone.star.project.dto.j6.file.ShareUserDTO;
import com.zeroone.star.project.query.j6.file.ShareFileQuery;
import com.zeroone.star.project.query.j6.file.ShareUserQuery;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.ComponentScan;
import com.zeroone.star.project.dto.j6.file.DownLoadShareDTO;
import com.zeroone.star.project.dto.j6.file.SendEditShareDTO;
import org.springframework.stereotype.Service;
import java.util.*;
import java.util.stream.Collectors;


/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author j6
 * @since 2024-10-23
 */
@Service
@ComponentScan(basePackages = "com.zeroone.star.project.components.user")
@ComponentScan(basePackages = "com.zeroone.star.project.components.jwt")
public class FileAttachmentSharelistServiceImpl extends ServiceImpl<FileAttachmentSharelistMapper, FileAttachmentSharelist> implements IFileAttachmentSharelistService {
    @Autowired
    private FileAttachmentSharelistMapper fileAttachmentSharelistMapper;

    @Autowired
    private UserHolder userHolder;

    @Override
    public Boolean downLoadAbleFile(DownLoadShareDTO downLoadShareDTO) {
        FileAttachmentSharelist fileAttachmentSharelist = new FileAttachmentSharelist();
        fileAttachmentSharelist.setAttachmentXid(downLoadShareDTO.getATTACHMENT_XID());
        fileAttachmentSharelist.setXorderColumn(new Random().nextInt());
        fileAttachmentSharelist.setXshareList(downLoadShareDTO.getXshareList().toString());
        return fileAttachmentSharelistMapper.insertDownSharelist(fileAttachmentSharelist);
    }

    @Override
    public Boolean editAbleFile(SendEditShareDTO sendShareFileDTO) {
        FileAttachmentEditorlist fileAttachmentEditorlist = new FileAttachmentEditorlist();
        fileAttachmentEditorlist.setAttachmentXid(sendShareFileDTO.getATTACHMENT_XID());
        fileAttachmentEditorlist.setXorderColumn(new Random().nextInt());
        fileAttachmentEditorlist.setXeditorList(sendShareFileDTO.getXeditorList().toString());
        return fileAttachmentSharelistMapper.insertEditSharelist(fileAttachmentEditorlist);
    }

@Override
public PageDTO<ShareUserDTO> getShareUserList(ShareUserQuery query) {
    // 获取所有共享用户的用户名，并去重
    Set<String> uniqueUserSet = fileAttachmentSharelistMapper.selectAllShareUserNames()
            .stream()
            .filter(shareList -> shareList != null && !shareList.isEmpty())
            .flatMap(shareList -> Arrays.stream(shareList.split(",")))
            .map(String::trim)
            .filter(username -> !username.isEmpty())
            .collect(Collectors.toSet());

    // 转换为 ShareUserDTO 列表
    List<ShareUserDTO> shareUserDTOList = uniqueUserSet.stream()
            .map(this::buildShareUserDTO)
            .collect(Collectors.toList());

    // 应用查询过滤，实现模糊查询
    if (query.getUsername() != null && !query.getUsername().isEmpty()) {
        shareUserDTOList = shareUserDTOList.stream()
                .filter(dto -> dto.getUsername() != null && dto.getUsername().contains(query.getUsername()))
                .collect(Collectors.toList());
    }

    // 计算分页参数
    int total = shareUserDTOList.size();
    int pageIndex = (int) query.getPageIndex();
    int pageSize = (int) query.getPageSize();
    int fromIndex = (pageIndex - 1) * pageSize;
    fromIndex = Math.max(fromIndex, 0);
    int toIndex = Math.min(fromIndex + pageSize, total);

    List<ShareUserDTO> paginatedList = new ArrayList<>();
    if (fromIndex < toIndex) {
        paginatedList = shareUserDTOList.subList(fromIndex, toIndex);
    }

    // 构建分页返回对象
    PageDTO<ShareUserDTO> pageDTO = new PageDTO<>();
    pageDTO.setTotal((long) total);
    pageDTO.setRows(paginatedList);
    pageDTO.setPageIndex((long) pageIndex);
    pageDTO.setPageSize((long) pageSize);
    pageDTO.setPages((long) ((total + pageSize - 1) / pageSize));

    return pageDTO;
}

    private ShareUserDTO buildShareUserDTO(String username) {
        try {
            UserDTO currentUser = userHolder.getCurrentUser();
            return ShareUserDTO.builder()
                    .username(username)
                    .build();
        } catch (Exception e) {
            log.error("解析用户失败！！！", e);
            ShareUserDTO dto = new ShareUserDTO();
            dto.setUsername(username);
            return dto;
        }
    }


    @Override
    public PageDTO<ShareFileDTO> getShareFilesOfUser(ShareFileQuery query) {
        Long userId = query.getUserId();
        String fileType = query.getFileType();
        String sortField = query.getSortField();
        String sortOrder = query.getSortOrder();
        // 获取共享文件列表
        List<ShareFileDTO> shareFileList = fileAttachmentSharelistMapper.selectShareFilesOfUser(userId);

        // 过滤文件类型
        if (fileType != null && !fileType.isEmpty()) {
            shareFileList = shareFileList.stream()
                    .filter(dto -> dto.getFileType() != null && dto.getFileType().equalsIgnoreCase(fileType))
                    .collect(Collectors.toList());
        }

        // 排序（如果需要）
        if ((sortField != null && !sortField.isEmpty()) && (sortOrder != null && !sortOrder.isEmpty())) {
            Comparator<ShareFileDTO> comparator;
            switch (sortField) {
                case "shareTime":
                    comparator = Comparator.comparing(ShareFileDTO::getSharedTime, Comparator.nullsLast(String::compareTo));
                    break;
                case "fileName":
                    comparator = Comparator.comparing(ShareFileDTO::getFileName, Comparator.nullsLast(String::compareTo));
                    break;
                case "fileSize":
                    comparator = Comparator.comparing(ShareFileDTO::getFileSize, Comparator.nullsLast(Long::compareTo));
                    break;
                default:
                    comparator = Comparator.comparing(ShareFileDTO::getSharedTime, Comparator.nullsLast(String::compareTo));
            }
            if ("desc".equalsIgnoreCase(sortOrder)) {
                comparator = comparator.reversed();
            }
            shareFileList.sort(comparator);
        }

        // 计算分页参数
        int total = shareFileList.size();
        int pageIndex = (int) query.getPageIndex();
        int pageSize = (int) query.getPageSize();
        int fromIndex = (pageIndex - 1) * pageSize;
        fromIndex = Math.max(fromIndex, 0);
        int toIndex = Math.min(fromIndex + pageSize, total);

        List<ShareFileDTO> paginatedList = new ArrayList<>();
        if (fromIndex < toIndex) {
            paginatedList = shareFileList.subList(fromIndex, toIndex);
        }

        // 构建分页返回对象
        PageDTO<ShareFileDTO> pageDTO = new PageDTO<>();
        pageDTO.setTotal((long) total);
        pageDTO.setRows(paginatedList);
        pageDTO.setPageIndex((long) pageIndex);
        pageDTO.setPageSize((long) pageSize);
        pageDTO.setPages((long) ((total + pageSize - 1) / pageSize));

        return pageDTO;
    }
}
