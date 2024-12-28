package com.zeroone.star.meetingmanagement.service.impl;

import com.zeroone.star.meetingmanagement.entity.MtAttachment;
import com.zeroone.star.meetingmanagement.mapper.MtAttachmentMapper;
import com.zeroone.star.meetingmanagement.service.IMtAttachmentService;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.components.fastdfs.FastDfsClientComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsFileInfo;
import com.zeroone.star.project.dto.meetingmangement.AttachmentDTO;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Service;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;
import java.time.LocalDateTime;
import java.util.Objects;
import java.util.Optional;
import java.util.UUID;

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author caifeng
 * @since 2024-10-24
 */
@Service
public class MtAttachmentServiceImpl extends ServiceImpl<MtAttachmentMapper, MtAttachment> implements IMtAttachmentService {

    @Resource
    private FastDfsClientComponent fastDfsClientComponent;

    @Resource
    private MtAttachmentMapper mtAttachmentMapper;

//    @Value("${fastdfs.nginx.server}")
    private String fastdfsUrl;

    @Value("${server.port}")
    private int serverPort;

    @Override
    public JsonVO<String> upload(AttachmentDTO attachmentDTO) {
        // TODO id
        int userId = 1;
        String username = "caifeng";

        MultipartFile file = attachmentDTO.getFile();

        String fileName = Objects.requireNonNull(file.getOriginalFilename());
        String suffix = fileName.substring(fileName.lastIndexOf("."));

        FastDfsFileInfo fastDfsFileInfo = null;

        try {
            fastDfsFileInfo = Optional
                    .ofNullable(fastDfsClientComponent.uploadFile(file.getBytes(), suffix))
                    .orElseThrow(RuntimeException::new);
        } catch (Exception e) {
            System.err.println(e.getMessage());
            return JsonVO.fail("上传失败");
        }

        LocalDateTime now = LocalDateTime.now();
        MtAttachment attachment = new MtAttachment();
        String id = UUID.randomUUID().toString();
        attachment.setXid(id);
        attachment.setXcreateTime(now);
        attachment.setXsequence(id + "-v0");
        attachment.setXupdateTime(now);
        attachment.setXdistributeFactor(5);
        attachment.setXdeepPath(true);
        attachment.setXextension(suffix);
        attachment.setXlastUpdatePerson(username);
        attachment.setXlastUpdateTime(now);
        attachment.setXlength(file.getSize());
        attachment.setXmeeting(String.valueOf(attachmentDTO.getMeetingXid()));
        attachment.setXname(fileName);
        attachment.setXstorage(fastDfsFileInfo.getGroup() + "/" + fastDfsFileInfo.getStorageId());

        mtAttachmentMapper.insert(attachment);
        return JsonVO.success(
//                fastDfsClientComponent.fetchUrl(fastDfsFileInfo, fastdfsUrl, true)
                null
        );
    }
}
