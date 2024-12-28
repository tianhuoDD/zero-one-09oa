package com.zeroone.star.procmanager.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.procmanager.entity.PpEFile;
import com.zeroone.star.procmanager.mapper.PpEAttachmentMapper;
import com.zeroone.star.procmanager.service.AttachmentQueryService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.procmanager.attachment.AttachmentDTO;
import com.zeroone.star.project.query.j4.procmanager.attachment.AttachmentQuery;
import org.mapstruct.Mapper;
import org.mapstruct.factory.Mappers;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Mapper(componentModel = "spring")
interface MsAttachmentMapper {
    /**
     * 将 PpEApplicationdictitem 转换为 AttachmentDTO
     * @param ppEFile PpEApplicationdictitem 对象
     * @return 转换结果
     */
    AttachmentDTO attachment2AttachmentDTO(PpEFile ppEFile);

    // 提供 MapStruct 映射器实例
    MsAttachmentMapper INSTANCE = Mappers.getMapper(MsAttachmentMapper.class);
}

@Service
public class AttachmentQueryServiceImpl implements AttachmentQueryService{

    @Autowired
    private MsAttachmentMapper msAttachmentMapper;
    @Autowired
    private PpEAttachmentMapper ppEAttachmentMapper;

    @Override
    public PageDTO<AttachmentDTO> queryAll(AttachmentQuery condition) {
       // 创建分页对象
       Page<PpEFile> page = new Page<>(condition.getPageIndex(), condition.getPageSize());

       //构建查询条件
       QueryWrapper<PpEFile> queryWrapper = new QueryWrapper<>();
       queryWrapper.like("xname",condition.getName());
       queryWrapper.like("xid",condition.getProcessInstanceId());

       // 执行分页查询
        Page<PpEFile> resultPage = ppEAttachmentMapper.selectPage(page,queryWrapper);

       // 使用 PageDTO 的静态方法创建分页数据对象
      return PageDTO.create(resultPage, msAttachmentMapper :: attachment2AttachmentDTO);

    }

    @Override
    public AttachmentDTO getById(int id) {
        PpEFile result = ppEAttachmentMapper.selectById(id);
        if (result != null){
            return msAttachmentMapper.attachment2AttachmentDTO(result);
        }
        return null;
    }
}


