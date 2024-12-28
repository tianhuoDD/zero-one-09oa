package com.zeroone.star.procmanager.utils;

import com.zeroone.star.project.components.fastdfs.FastDfsClientComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsFileInfo;
import org.springframework.web.multipart.MultipartFile;

public class DfsUtils {
    /**
     * 删除dfs中文件
     *
     * @param fileGroup
     * @param remoteFileName
     * @param fastDfsClient
     * @return java.lang.String
     * @author 夜寻
     * @create 2024/10/27
     **/
    public static Integer deleteFromDfs(String fileGroup , String remoteFileName, FastDfsClientComponent fastDfsClient){
        int i;
        try {
            i = fastDfsClient.deleteFile(FastDfsFileInfo.builder()
                    .group(fileGroup)
                    .storageId(remoteFileName)
                    .build());
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
        return i;
    }
    /**
     * 上传文件到dfs
     *
     * @param multipartFile
     * @param suffix
     * @param fastDfsClient
     * @param fileServerAdd
     * @return java.lang.String
     * @author 夜寻
     * @create 2024/10/27
     **/
    public static String uploadToDfs(MultipartFile multipartFile,
                               String suffix,
                               FastDfsClientComponent fastDfsClient,
                               String fileServerAdd){
        FastDfsFileInfo fastDfsFileInfo = null;
        //上传文件到dfs
        try {
            fastDfsFileInfo = fastDfsClient.uploadFile(multipartFile.getBytes(), suffix);
        } catch (Exception e) {
            throw new RuntimeException(e);
        }

        if (fastDfsFileInfo == null ){
            return null;
        }

        return fastDfsClient.fetchUrl(fastDfsFileInfo,fileServerAdd,true);
    }

    /**
     * 上传文件到dfs
     *
     * @param bytes
     * @param suffix
     * @param fastDfsClient
     * @param fileServerAdd
     * @return java.lang.String
     * @author 夜寻
     * @create  2024/10/27
     **/

    public static String uploadToDfs(byte[] bytes,
                                     String suffix,
                                     FastDfsClientComponent fastDfsClient,
                                     String fileServerAdd){
        FastDfsFileInfo fastDfsFileInfo = null;
        //上传文件到dfs
        try {
            fastDfsFileInfo = fastDfsClient.uploadFile(bytes, suffix);
        } catch (Exception e) {
            throw new RuntimeException(e);
        }

        if (fastDfsFileInfo == null ){
            throw new RuntimeException("上传文件失败");
        }

        return fastDfsClient.fetchUrl(fastDfsFileInfo,fileServerAdd,true);
    }

    /**
     * 根据url获取文件存储在dfs中的信息
     *
     * @param url
     * @return java.lang.String
     * @author 夜寻
     * @create 2024/10/23
     **/

    public static String getGroupAndRemoteFileName(String url) {
        // 移除协议部分
        String pathAndQuery = url.substring(url.indexOf("//") + 2);
        // 分割路径和查询参数
        String[] pathAndQueryParts = pathAndQuery.split("\\?");
        //获取path
        String path = pathAndQueryParts[0];

        //获取文件存储在dfs的信息
        String groupAndRemoteFileName = path.substring(path.indexOf("/") + 1);
        return groupAndRemoteFileName;
    }
}
