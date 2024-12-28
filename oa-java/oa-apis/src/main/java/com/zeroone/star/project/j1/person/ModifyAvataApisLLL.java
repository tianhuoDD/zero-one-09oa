package com.zeroone.star.project.j1.person;


import com.zeroone.star.project.vo.JsonVO;
import org.springframework.web.multipart.MultipartFile;

import java.io.IOException;

/**
 * 用户头像接口声明
 */
public interface ModifyAvataApisLLL {


    /**
     * 上传本地图片作为头像
     *
     * @param file 待上传的图片
     * @return 若上传成功则返回true，否则返回false
     */
    JsonVO<String> uploadLocalImage(MultipartFile file) throws Exception;

    /**
     * 预览已上传的图片
     *
     * @param uploadedImageId 已上传图片的唯一标识符
     * @return 若预览成功则返回true，否则返回false
     */
    boolean previewImage(String uploadedImageId);

    /**
     * 确认选中的图片为个人头像
     *
     * @param uploadedImageId 待设置为头像的图片标识符
     * @return 若确认成功则返回true，否则返回false
     */
    boolean confirmImageAsAvatar(String uploadedImageId);

    /**
     * 取消当前头像预览
     *
     * @return 若取消成功则返回true，否则返回false
     */
    boolean cancelPreview();
}
