package com.zeroone.star.systemhome.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.zeroone.star.project.dto.j1.systemhome.FileStaticsDTO;
import com.zeroone.star.systemhome.entity.file.FileOperationLog;
import com.zeroone.star.systemhome.mapper.FileOperationLogMapper;
import com.zeroone.star.systemhome.service.FileStaticsService;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.Date;

/**
 * @author 李云毅
 * @version 1.0.0
 * 2024/10/25
 */
@Service
public class FileStaticsServiceImpl implements FileStaticsService {

    @Resource
    FileOperationLogMapper fileOperationLogMapper;

    @Override
    public FileStaticsDTO countFileStatistics(String xperson, Date startDate, Date endDate) {
        QueryWrapper<FileOperationLog> wrapper = new QueryWrapper<>();
        //查询上传文件数
        wrapper.like("xFromPerson",xperson).like("xOperationType",4).between("xOperationTime",startDate,endDate);
        Long updateCount = fileOperationLogMapper.selectCount(wrapper);
        //查询共享文件数
        wrapper = new QueryWrapper<>();
        wrapper.like("xFromPerson",xperson).like("xOperationType",2).between("xOperationTime",startDate,endDate);
        Long shareCount = fileOperationLogMapper.selectCount(wrapper);
        //查询发送文件数
        wrapper = new QueryWrapper<>();
        wrapper.like("xFromPerson",xperson).like("xOperationType",1).between("xOperationTime",startDate,endDate);
        Long sendCount = fileOperationLogMapper.selectCount(wrapper);
        //查询删除文件数
        wrapper = new QueryWrapper<>();
        wrapper.like("xFromPerson",xperson).like("xOperationType",3).between("xOperationTime",startDate,endDate);
        Long deleteCount = fileOperationLogMapper.selectCount(wrapper);
        return new FileStaticsDTO(updateCount,shareCount,sendCount,deleteCount);
    }


}
