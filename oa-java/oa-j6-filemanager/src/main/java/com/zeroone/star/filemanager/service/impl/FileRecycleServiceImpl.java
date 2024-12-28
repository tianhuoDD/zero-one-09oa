package com.zeroone.star.filemanager.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.zeroone.star.filemanager.entity.FileRecycle;
import com.zeroone.star.filemanager.mapper.FileRecycleMapper;
import com.zeroone.star.filemanager.service.IFileRecycleService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j6.file.ReceivedFileDTO;
import com.zeroone.star.project.dto.j6.file.ReceivedUserDTO;
import com.zeroone.star.project.query.j6.file.ReceivedFileQuery;
import com.zeroone.star.project.query.j6.file.ReceivedUserQuery;
import lombok.Builder;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author j6
 * @since 2024-10-23
 */

@Builder
@Service
public class FileRecycleServiceImpl extends ServiceImpl<FileRecycleMapper, FileRecycle> implements IFileRecycleService {
    @Autowired
    private FileRecycleMapper fileRecycleMapper;

    @Override
    public PageDTO<ReceivedUserDTO> getReceivedUserList(ReceivedUserQuery query) {
        QueryWrapper<FileRecycle> wrapper = new QueryWrapper<>();
        if (query.getXperson() != null && !query.getXperson().isEmpty()) {
            wrapper.lambda().like(FileRecycle::getXperson, query.getXperson());
        }
        List<FileRecycle> recycleUserList = fileRecycleMapper.selectList(wrapper);

        List<ReceivedUserDTO> recycleUserDTOList = recycleUserList.stream()
                .map(this::buildRecycleUserDTO)
                .collect(Collectors.toList());

        int total = recycleUserDTOList.size();
        int pageIndex = (int) query.getPageIndex();
        int pageSize = (int) query.getPageSize();
        int fromIndex = Math.max((pageIndex - 1) * pageSize, 0);
        int toIndex = Math.min(fromIndex + pageSize, total);

        List<ReceivedUserDTO> paginatedList = new ArrayList<>();
        if (fromIndex < toIndex) {
            paginatedList = recycleUserDTOList.subList(fromIndex, toIndex);
        }

        PageDTO<ReceivedUserDTO> pageDTO = new PageDTO<>();
        pageDTO.setTotal((long) total);
        pageDTO.setRows(paginatedList);
        pageDTO.setPageIndex((long) pageIndex);
        pageDTO.setPageSize((long) pageSize);
        pageDTO.setPages((long) ((total + pageSize - 1) / pageSize));

        return pageDTO;
    }

    private ReceivedUserDTO buildRecycleUserDTO(FileRecycle fileRecycle) {
        return ReceivedUserDTO.builder()
                .xid(fileRecycle.getXid())
                .xcreateTime(fileRecycle.getXcreateTime())
                .xname(fileRecycle.getXname())
                .xlength(fileRecycle.getXlength())
                .xperson(fileRecycle.getXperson())
                .xfileType(fileRecycle.getXfileType())
                .build();
    }


    @Override
    public PageDTO<ReceivedFileDTO> getReceivedFileList(ReceivedFileQuery query) {
        QueryWrapper<FileRecycle> wrapper = new QueryWrapper<>();
        if (query.getXname() != null && !query.getXname().isEmpty()) {
            wrapper.lambda().like(FileRecycle::getXname, query.getXname());
        }
        List<FileRecycle> recycleFileList = fileRecycleMapper.selectList(wrapper);

        List<ReceivedFileDTO> recycleFileDTOList = recycleFileList.stream()
                .map(this::buildRecycleFileDTO)
                .collect(Collectors.toList());


        int total = recycleFileDTOList.size();
        int pageIndex = (int) query.getPageIndex();
        int pageSize = (int) query.getPageSize();
        int fromIndex = Math.max((pageIndex - 1) * pageSize, 0);
        int toIndex = Math.min(fromIndex + pageSize, total);

        List<ReceivedFileDTO> paginatedList = new ArrayList<>();
        if (fromIndex < toIndex) {
            paginatedList = recycleFileDTOList.subList(fromIndex, toIndex);
        }

        PageDTO<ReceivedFileDTO> pageDTO = new PageDTO<>();
        pageDTO.setTotal((long) total);
        pageDTO.setRows(paginatedList);
        pageDTO.setPageIndex((long) pageIndex);
        pageDTO.setPageSize((long) pageSize);
        pageDTO.setPages((long) ((total + pageSize - 1) / pageSize));

        return pageDTO;
    }

    private ReceivedFileDTO buildRecycleFileDTO(FileRecycle fileRecycle) {
        return ReceivedFileDTO.builder()
                .xid(fileRecycle.getXid())
                .xcreateTime(fileRecycle.getXcreateTime())
                .xname(fileRecycle.getXname())
                .xlength(fileRecycle.getXlength())
                .xperson(fileRecycle.getXperson())
                .xfileType(fileRecycle.getXfileType())
                .build();
    }
}
