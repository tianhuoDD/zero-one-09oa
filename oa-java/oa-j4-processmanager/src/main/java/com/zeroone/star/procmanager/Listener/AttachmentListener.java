package com.zeroone.star.procmanager.Listener;

import com.zeroone.star.procmanager.entity.PpEFile;
import com.zeroone.star.procmanager.service.FileService;
import com.zeroone.star.procmanager.sink.AttachmentSink;
import com.zeroone.star.procmanager.utils.DfsUtils;
import com.zeroone.star.project.components.fastdfs.FastDfsClientComponent;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.cloud.stream.annotation.StreamListener;
import org.springframework.messaging.Message;
import org.springframework.stereotype.Component;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;


@Component
public class AttachmentListener {
    @Autowired
    FastDfsClientComponent fastDfsClient;

    @Value("${fastdfs.nginx-servers}")
    private String fileServerAdd;
    @Autowired
    private FileService fileService;

    @StreamListener(AttachmentSink.ATTACHMENT_UPLOAD_INPUT)
    public void upload(Message<byte[]> message){
        System.out.println("接收到消息: " + message);
        //从message消息头中获取所需信息
        String suffix = (String)message.getHeaders().get("suffix");
        String xid = (String)message.getHeaders().get("xid");

        PpEFile file = fileService
                .lambdaQuery()
                .select(PpEFile::getXid,PpEFile::getXurl)
                .eq(PpEFile::getXid, xid)
                .one();

        if(file.getXurl() != null){
            //若该附件本身就存在，则先在dfs删除该附件文件
            String groupAndRemoteFileName = DfsUtils.getGroupAndRemoteFileName(file.getXurl());
            String fileGroup =  groupAndRemoteFileName.substring(0,groupAndRemoteFileName.indexOf("/"));
            String remoteFileName = groupAndRemoteFileName.substring(groupAndRemoteFileName.indexOf("/")+1);
            //从dfs中删除文件
            Integer i = DfsUtils.deleteFromDfs(fileGroup, remoteFileName, fastDfsClient);
            if(i != 0){
                throw new RuntimeException("文件删除失败");
            }
        }

        String url = DfsUtils.uploadToDfs(message.getPayload(), suffix, fastDfsClient, fileServerAdd);

        fileService.lambdaUpdate()
                .set(PpEFile::getXurl,url)
                .set(PpEFile::getXsequence,
                        LocalDateTime.now().format(DateTimeFormatter.ofPattern("yyyyMMddHHmmss"))+xid)
                .eq(PpEFile::getXid,xid)
                .update();
    }
}
