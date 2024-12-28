package com.zeroone.star.project.dto.j6.file;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Nonnull;

/**
 * @program: oa-java
 * @description:
 * @author: Mr.Wang
 * @create: 2024-11-02 14:45
 **/
@Data
@NoArgsConstructor
@AllArgsConstructor
@ApiModel("上传文件数据封装")
public class UploadFileDTO {
    @ApiModelProperty(value = "文件",required = true)
    @Nonnull
    private MultipartFile file;
    @ApiModelProperty(value = "所在文件夹ID",example = "")
    private String xfolder;
}
