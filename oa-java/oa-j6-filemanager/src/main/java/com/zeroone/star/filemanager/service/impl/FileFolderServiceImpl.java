package com.zeroone.star.filemanager.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.zeroone.star.filemanager.entity.FileFolder;
import com.zeroone.star.filemanager.mapper.FileFolderMapper;
import com.zeroone.star.filemanager.service.IFileFolderService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.j6.file.FileFolderDTO;
import com.zeroone.star.project.dto.j6.file.FolderDTO;
import com.zeroone.star.project.query.j6.file.FolderQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j6.file.FileFolderVO;
import com.zeroone.star.project.vo.j6.file.FolderVO;
import org.springframework.beans.BeanUtils;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.Resource;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.*;

import javax.annotation.Resource;
import java.text.SimpleDateFormat;
import java.time.LocalDateTime;

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author j6
 * @since 2024-10-23
 */
@Service
public class FileFolderServiceImpl extends ServiceImpl<FileFolderMapper, FileFolder> implements IFileFolderService {

    @Resource
    private FileFolderMapper fileFolderMapper;

    @Override
    public Integer insertFolder(FileFolderDTO fileFolderDTO) {
        if (fileFolderDTO.getXname().length() == 0 || fileFolderDTO.getXname() == null){
            return -1;
        }
        FileFolder fileFolder = new FileFolder();

        // 定义日期时间格式
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyyMMddHHmmssSSS");

//        添加创建、更新时间，sequence，
        fileFolder.setXid(UUID.randomUUID().toString());//UUID随机生成id
        fileFolder.setXcreateTime(LocalDateTime.now());
        fileFolder.setXupdateTime(LocalDateTime.now());
        fileFolder.setXsequence(fileFolder.getXcreateTime().format(formatter) + fileFolder.getXid());
        fileFolder.setXsuperior(fileFolderDTO.getXsuperior());
        fileFolder.setXname(fileFolderDTO.getXname());
        fileFolder.setXperson(fileFolderDTO.getXperson());
//        插入数据库
        return fileFolderMapper.insertFileFolder(fileFolder);
    }

    @Transactional
    @Override
    public Integer rmFolderById(String folderId) {
//        删除目录内文件
        int row1 = fileFolderMapper.deleteAttachmentsByFolderId(folderId);
//        删除子目录
        int row2 = fileFolderMapper.deleteFolderByFolderId(folderId);
//        删除目标目录本身
        int row3 = fileFolderMapper.deleteByFolderId(folderId);
//        返回删除项目条数
        return row1+row2+row3;
    }

    /**
     * 分页查询指定文件夹下的文件夹
     * @return
     */
    @Override
    public List<FileFolderVO> getPageFolder(FolderQuery folderQuery) {
// 1.准备分页条件
        Page<FileFolder> page = new Page<>(folderQuery.getPageIndex(), folderQuery.getPageSize());

// 2.分页查询
        // 2.1.创建查询条件 Wrapper
        QueryWrapper<FileFolder> queryWrapper = new QueryWrapper<>();
        // 2.2.查询
        if(folderQuery.getXid() != null){
            queryWrapper.eq("xsuperior", folderQuery.getXid());
        }else{
            queryWrapper.eq("xsuperior", "");
        }
        Page<FileFolder> p = fileFolderMapper.selectPage(page,queryWrapper);

// 3.解析
        List<FileFolder> records = p.getRecords();

// 4.复制属性到VO
        List<FileFolderVO> fileFolderVOs = new ArrayList<>();
        for (FileFolder record : records) {
            FileFolderVO vo = BeanUtil.copyProperties(record, FileFolderVO.class);
            fileFolderVOs.add(vo);//加入List
        }
        return fileFolderVOs;
    }

    /**
     * 重命名目录
     * @param xid
     * @param new_xname
     * @param xsuperior
     * @return
     */
    @Transactional
    @Override
    public boolean updateFileFolderName(String xid, String new_xname,String xsuperior) {

        if(fileFolderMapper.selectById(xid)==null){
            return false;
        }

        // 检查新名称是否已存在
        QueryWrapper<FileFolder> nameCheckWrapper = new QueryWrapper<>();
        if (xsuperior == null) {
            nameCheckWrapper.isNull("xsuperior");
        } else {
            nameCheckWrapper.eq("xsuperior", xsuperior);
        }
        nameCheckWrapper.eq("xname", new_xname);
        nameCheckWrapper.ne("xid", xid);  // 排除当前文件
        Long count = fileFolderMapper.selectCount(nameCheckWrapper);
        if (count > 0) {
            return false;  // 新名称已存在，操作失败
        }

        FileFolder fileFolder = new FileFolder();
        fileFolder.setXname(new_xname);

        SimpleDateFormat formatter = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
        LocalDateTime formattedDate = LocalDateTime.now();
        fileFolder.setXupdateTime(formattedDate);

        QueryWrapper<FileFolder> wq = new QueryWrapper<>();
        wq.eq("xid",xid);
        int result1 = this.fileFolderMapper.update(fileFolder,wq);

        return result1>0;
    }


}
