package com.zeroone.star.user.controller;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.conditions.update.UpdateWrapper;
import com.zeroone.star.project.components.fastdfs.FastDfsClientComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsFileInfo;
import com.zeroone.star.project.dto.j8.user.user_info.UserInfoUpdateDTO;
import com.zeroone.star.project.j8.user.UserInfoApis;
import com.zeroone.star.project.query.j8.user.user_info.UserInfoQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j8.user.user_info.UserInfoVO;
import com.zeroone.star.user.entity.OrgPerson;
import com.zeroone.star.user.services.OrgPersonService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import javax.annotation.Resource;
import javax.validation.constraints.NotNull;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.multipart.MultipartFile;


/**
 * @author 西北卓越青年
 */
@Api(tags = "用户信息接口")
@RestController
@RequestMapping("/org/user/info")
@ComponentScan("com.zeroone.star.project.components.fastdfs")
public class UserInfoController implements UserInfoApis {

    private OrgPerson curPerson;

    @Resource
    OrgPersonService orgPersonService;

    @Value("${fastdfs.nginx-servers}")
    private String fileServerUrl;

    @Resource
    private FastDfsClientComponent dfsClient;

    @GetMapping("/query-user-info")
    @ApiOperation("查询用户信息")
    @Override
    public JsonVO<UserInfoVO> queryUserInfo(@RequestBody UserInfoQuery userInfoQuery) {
        try {
            curPerson = orgPersonService.getOne(new LambdaQueryWrapper<OrgPerson>()
                    .eq(OrgPerson::getXunique, userInfoQuery.getXunique()));
        } catch (Exception e) {
            return JsonVO.fail(null);
        }
        if (curPerson == null) {
            return JsonVO.fail(null);
        }
        UserInfoVO userInfoVO = new UserInfoVO();
        BeanUtils.copyProperties(curPerson, userInfoVO);
        return JsonVO.success(userInfoVO);
    }


    @Override
    @PutMapping("/modify-user-info")
    @ApiOperation("更新用户信息")
    public JsonVO<String> modifyUserInfo(@RequestBody UserInfoUpdateDTO userInfoUpdateDTO) {

        if (curPerson == null) {
            return JsonVO.fail("当前用户信息不存在，请重新查询用户信息");
        }

        if(userInfoUpdateDTO.getXunique()==null){
            return JsonVO.fail("唯一编码不能为空");
        }
        // 检查 xunique 是否存在重复
        OrgPerson duplicatePerson = orgPersonService.getOne(
                new QueryWrapper<OrgPerson>()
                        .eq("xunique", userInfoUpdateDTO.getXunique())
                        .ne("xunique", curPerson.getXunique())
        );

        if (duplicatePerson != null) {
            return JsonVO.fail("唯一编码重复");
        }

        OrgPerson person=new OrgPerson();
        BeanUtils.copyProperties(userInfoUpdateDTO,person);

        orgPersonService.update(person,new UpdateWrapper<OrgPerson>().eq("xunique",curPerson.getXunique()));
        return JsonVO.success(null);
    }

    @PutMapping("/modify-user-avatar")
    @ApiOperation("更新用户头像")
    public JsonVO modifyUserAvatar(@NotNull MultipartFile file) {
        try {
            // 检查文件是否为空
            if (file.isEmpty()) {
                return JsonVO.fail("文件不能为空");
            }


            // 获取文件的 MIME 类型并检查是否为图片
            String contentType = file.getContentType();
            if (contentType == null || !isImage(contentType)) {
                return JsonVO.fail("文件类型不支持，仅支持图片格式");
            }

            // 获取文件名并判断文件后缀
            String filename = file.getOriginalFilename();
            if (filename == null || !filename.contains(".")) {
                return JsonVO.fail("无效的文件名称");
            }
            String suffix = filename.substring(filename.lastIndexOf(".") + 1);

            // 上传文件到 FastDFS
            FastDfsFileInfo fastDfsFileInfo = dfsClient.uploadFile(file.getBytes(), suffix);
            if (fastDfsFileInfo == null) {
                return JsonVO.fail("上传失败");
            }

            // 获取文件的访问URL
            String fileUrl = dfsClient.fetchUrl(fastDfsFileInfo, fileServerUrl, true);

            // 设置 icon 字段并更新数据库
            if (curPerson == null) {
                return JsonVO.fail("当前用户信息不存在，请重新查询用户信息");
            }

            // 更新用户的 icon 字段,先设置成一样的
            curPerson.setXicon(fileUrl);
            curPerson.setXiconldpi(fileUrl);
            curPerson.setXiconmdpi(fileUrl);
            orgPersonService.updateById(curPerson);

            return JsonVO.success(fileUrl);

        } catch (Exception e) {
            return JsonVO.fail("文件上传过程中发生错误");
        }
    }


    private boolean isImage(String contentType) {
        // 常见图片的 MIME 类型
        return "image/jpeg".equals(contentType) ||
                "image/png".equals(contentType) ||
                "image/gif".equals(contentType) ||
                "image/bmp".equals(contentType) ||
                "image/webp".equals(contentType);
    }


}
