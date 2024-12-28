package com.zeroone.star.columnsetting.service.impl;

import cn.hutool.core.bean.BeanUtil;
import cn.hutool.core.util.ObjectUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.conditions.update.UpdateWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.columnsetting.entity.CmsFile;
import com.zeroone.star.columnsetting.mapper.CmsFileMapper;
import com.zeroone.star.columnsetting.service.ICmsFileService;
import com.zeroone.star.columnsetting.utils.UuidUtil;
import com.zeroone.star.project.j3.resourcefile.dto.CmsFileDTO;
import com.zeroone.star.project.j3.resourcefile.vo.CmsFileVO;
import org.springframework.beans.BeanUtils;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;
import java.util.stream.Collectors;

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author lfh59 and trigger
 * @since 2024-10-26
 */
@Service
public class CmsFileServiceImpl extends ServiceImpl<CmsFileMapper, CmsFile> implements ICmsFileService {
    @Resource
    private CmsFileMapper cmsFileMapper;

    @Override
    public List<CmsFileVO> getAttachmentList(String xappId) {
        if (ObjectUtil.isEmpty(xappId)) {
            throw new RuntimeException("查找附件列表id为空");
        }
        List<CmsFile> fileList = cmsFileMapper.selectList(new QueryWrapper<CmsFile>().lambda().eq(CmsFile::getXappId,xappId));
        return fileList.stream().map(file -> {
            CmsFileVO cmsFileVO = new CmsFileVO();
            BeanUtils.copyProperties(file, cmsFileVO);
            return cmsFileVO;
        }).collect(Collectors.toList());
    }

    @Override
    public CmsFileVO getAttachmentDetail(String xid) {
        if (ObjectUtil.isEmpty(xid)) {
            throw new RuntimeException("查找附件id为空");
        }
        CmsFile getfile = cmsFileMapper.selectById(xid);
        CmsFileVO cmsFileDetail = new CmsFileVO();
        BeanUtils.copyProperties(getfile, cmsFileDetail);
        if (ObjectUtil.isEmpty(getfile)) {
            throw new RuntimeException("查找附件失败");
        }
        return cmsFileDetail;
    }

    @Override
    public Integer insertfile(CmsFileDTO CmsFileDTO,String username,String xappId) {
        if (CmsFileDTO==null) {
            throw new RuntimeException("新增附件无效");
        }
        CmsFile cmsFile = BeanUtil.copyProperties(CmsFileDTO, CmsFile.class);
        int insert = cmsFileMapper.insert(cmsFile);
        if (insert==0) {
            throw new RuntimeException("新增附件失败");
        }
        return insert;
    }





    @Override
    public Integer deletefile(String xid) {
        if (ObjectUtil.isEmpty(xid)) {
            throw new RuntimeException("删除附件的id为空");
        }
        int delete = cmsFileMapper.deleteById(xid);
        if (delete==0) {
            throw new RuntimeException("删除附件失败");
        }
        return delete;
    }

    @Override
    public Integer updatefile(CmsFileDTO cmsFileDTO) {
        if (cmsFileDTO==null) {
            throw new RuntimeException("无法获取更新附件");
        }
        CmsFile cmsfile = BeanUtil.toBean(cmsFileDTO, CmsFile.class);
        cmsfile.setXsequence(UuidUtil.getUuid());
        UpdateWrapper<CmsFile> wrapper = new UpdateWrapper<>();
        wrapper.eq("xid",cmsFileDTO.getXid());
        int updateById = cmsFileMapper.update(cmsfile,wrapper );
        //int updateById = cmsFileMapper.updateById(cmsfile);
        if (updateById==0) {
            throw new RuntimeException("更新附件失败");
        }
        return updateById;
    }
}
