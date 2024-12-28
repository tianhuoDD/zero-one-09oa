package com.zeroone.star.settings.controller;

import com.zeroone.star.project.components.fastdfs.FastDfsClientComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsFileInfo;
import com.zeroone.star.project.j1.person.ModifyAvataApisLLL;;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;
import java.util.UUID;

@RestController
@RequestMapping("settings/modify-image")
@Api(tags = "个人头像管理")
@Slf4j
public class ModifyAvataApisController implements ModifyAvataApisLLL {


    @Resource
    private FastDfsClientComponent dfsClientComponent;

    @Value("${fastdfs.nginx-servers}")
    private String fastdfsNginxServerUrl;

    /**
     * 上传本地图片作为头像
     *
     * @param file 待上传的图片
     * @return 若上传成功则返回true，否则返回false
     */
    @PostMapping("upload-image")
    @ApiOperation("上传本地图片")
    public JsonVO<String> uploadLocalImage(@RequestParam("file") MultipartFile file) throws Exception {

        // 检查文件是否为空
        if (file == null || file.isEmpty()) {
            return JsonVO.create(null, ResultStatus.UPLOAD_FAIL);
        }

        // 获取文件名
        String fileName = file.getOriginalFilename();
        if (fileName == null) {
            return JsonVO.create(null, ResultStatus.UPLOAD_FAIL);
        }

        // 获取文件后缀
        String suffixName = "";
        int dotIndex = fileName.lastIndexOf(".");
        if (dotIndex > 0) {
            suffixName = fileName.substring(dotIndex + 1);
        } else {
            return JsonVO.create(null, ResultStatus.UPLOAD_FAIL);
        }

        // 生成新的文件名
        String objectName = UUID.randomUUID().toString() + "." + suffixName;

        // 上传文件
        FastDfsFileInfo filePath = dfsClientComponent.uploadFile(file.getBytes(), objectName);
        if (filePath == null) {
            return JsonVO.create(null, ResultStatus.UPLOAD_FAIL);
        }

        // 构建返回结果
        String url = dfsClientComponent.fetchUrl(filePath, fastdfsNginxServerUrl, true) + filePath;
        return JsonVO.create(url, ResultStatus.UPLOAD_SUCCESS);
    }



    /**
     * 预览已上传的图片
     *
     * @param uploadedImageId 已上传图片的唯一标识符
     * @return 若预览成功则返回true，否则返回false
     */
    public boolean previewImage(String uploadedImageId) {
        return false;
    }

    /**
     * 确认选中的图片为个人头像
     *
     * @param uploadedImageId 待设置为头像的图片标识符
     * @return 若确认成功则返回true，否则返回false
     */

    public boolean confirmImageAsAvatar(String uploadedImageId) {
        return false;
    }

    /**
     * 取消当前头像预览
     *
     * @return 若取消成功则返回true，否则返回false
     */
    public boolean cancelPreview() {
        return false;
    }
}
