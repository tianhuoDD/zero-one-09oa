package com.zeroone.star.basicinformation.controller;


import cn.hutool.core.lang.UUID;
import cn.hutool.core.util.ObjectUtil;
import com.zeroone.star.basicinformation.entity.CmsAppinfo;
import com.zeroone.star.basicinformation.service.ICmsAppinfoConfigService;
import com.zeroone.star.basicinformation.service.ICmsAppinfoService;
import com.zeroone.star.project.components.fastdfs.FastDfsClientComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsFileInfo;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j3.appinfo.AppinfoApis;
import com.zeroone.star.project.j3.appinfo.dto.AppDTO;
import com.zeroone.star.project.j3.appinfo.dto.AppTypeDTO;
import com.zeroone.star.project.j3.appinfo.query.AppQuery;
import com.zeroone.star.project.j3.columnbasicinformation.ColumnBasicinformationApis;
import com.zeroone.star.project.j3.columnbasicinformation.dto.AppinfoConfigDTO;
import com.zeroone.star.project.j3.columnbasicinformation.dto.AppinfoDTO;
import com.zeroone.star.project.j3.columnbasicinformation.dto.BasicinformationDTO;
import com.zeroone.star.project.j3.columnbasicinformation.query.BasicinformationQuery;
import com.zeroone.star.project.j3.columnbasicinformation.vo.BasicinformationVo;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.SneakyThrows;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.time.format.DateTimeFormatterBuilder;
import java.util.List;

/**
 * <p>
 *  新建及删除栏目
 *  前端控制器
 *  查询栏目类型及栏目
 * </p>
 *
 * @author Kokoro
 * @since 2024-10-20
 */
@RestController
@RequestMapping("app")
@Api(tags = "栏目基础信息管理")
public class CmsAppinfoController implements AppinfoApis , ColumnBasicinformationApis {

    @Resource
    private ICmsAppinfoService cmsAppinfoService;

    @Resource
    private FastDfsClientComponent dfsClient;

    @Value("${fastdfs.nginx-servers}")
    private String fileServerUrl;

    @Resource
    private ICmsAppinfoConfigService cmsAppinfoConfigService;


    /**
     * 查询所有的栏目类型
     * @return
     */
    @GetMapping("query-all-type")
    @ApiOperation("查询所有的栏目类型")
    @Override
    public JsonVO<List<AppTypeDTO>> queryAllType() {
        List<AppTypeDTO> appTypes = cmsAppinfoService.listAllType();
        return JsonVO.success(appTypes);
    }

    /**
     * 查询栏目基础信息
     *
     * @param basicinformationQuery
     * @return
     */
    @GetMapping("query-one")
    @ApiOperation(value = "查询栏目基础信息")
    public JsonVO<BasicinformationVo> queryBasicinformation(BasicinformationQuery basicinformationQuery){
        BasicinformationVo basicinformationVo = cmsAppinfoService.queryBasicinformation(basicinformationQuery);

        return JsonVO.success(basicinformationVo);
    }

    /**
     * 根据条件查询栏目
     * @param condition 查询条件
     * @return
     */
    @GetMapping("query-condition")
    @ApiOperation("根据条件查询栏目")
    @Override
    public JsonVO<PageDTO<AppDTO>> queryApp(AppQuery condition) {
        PageDTO<AppDTO> appDTOPageDTO = cmsAppinfoService.listApp(condition);
        return JsonVO.success(appDTOPageDTO);

    }

    /**
     * 更新栏目基础信息
     * @param basicinformationDTO 栏目基础信息
     * @return
     */
    @SneakyThrows
    @Transactional
    @PutMapping("update-appinfo")
    @ApiOperation(value = "更新栏目基础信息")
    public JsonVO<BasicinformationVo> modifyBasicinformation(BasicinformationDTO basicinformationDTO, MultipartFile file){
        String xid = basicinformationDTO.getXid();

        CmsAppinfo delappinfo = cmsAppinfoService.getById(xid);
        int i = 0;
        String xappIcon = delappinfo.getXappIcon();

        String[] split = xappIcon.split("/");
        String group = split[1];
        String groupAndStorage = delappinfo.getXappIcon().substring(delappinfo.getXappIcon().indexOf("/") + 1);
        String storageId = groupAndStorage.substring(groupAndStorage.indexOf("/") + 1);

        System.out.println(group);
        System.out.println(storageId);
        //删除旧文件
        try {
            i = dfsClient.deleteFile(FastDfsFileInfo.builder().group(group).storageId(storageId).build());
        } catch (Exception e) {
            throw new RuntimeException(e);
        }

        //获取文件后缀名
        String filename = file.getOriginalFilename();
        assert filename != null;
        String suffix = filename.substring(filename.lastIndexOf(".")+1);
        //上传文件到fastDfs
        FastDfsFileInfo fastDfsFileInfo = dfsClient.uploadFile(file.getBytes(), suffix);
        //获取group + filedId
        if (fastDfsFileInfo != null){
            String s = "/" + fastDfsFileInfo.getGroup() +'/'+ fastDfsFileInfo.getStorageId();
            basicinformationDTO.setXappIcon(s);
        }else {
            throw new RuntimeException("上传失败");
        }
        BasicinformationVo basicinformationVo = cmsAppinfoService.updateBasicinformation(basicinformationDTO);
        return JsonVO.success(basicinformationVo);
    }


    /**
     * 新建栏目
     * @param appinfoDTO 数据对象
     * @return 成功新建栏目的xid，失败返回对应提示信息
     */
    @SneakyThrows
    @Transactional
    @PostMapping("add-column")
    @ApiOperation("新建栏目")
    @Override
    public JsonVO<String> addAppinfo(@Validated AppinfoDTO appinfoDTO, MultipartFile file) {
        if(ObjectUtil.isEmpty(appinfoDTO.getXappName()) || ObjectUtil.isEmpty(appinfoDTO.getXappType())) {
            throw new Exception("栏目名称或者栏目类型为空");
        }
        //新增栏目
        LocalDateTime time = LocalDateTime.now();
        appinfoDTO.setXcreateTime(time);
        appinfoDTO.setXupdateTime(time);
        DateTimeFormatter formatter = new DateTimeFormatterBuilder().appendPattern("yyyyMMddHHmmss").toFormatter();
        String xSequence = time.format(formatter) + UUID.randomUUID();
        appinfoDTO.setXsequence(xSequence);

        if (ObjectUtil.isNotEmpty(file)) {
            // 获取上传图标文件的后缀名称
            String filename = file.getOriginalFilename();
            assert filename != null;
            String suffix = filename.substring(filename.lastIndexOf(".") + 1);
            // 上传图标文件
            FastDfsFileInfo fastDfsFileInfo = null;
            try {
                fastDfsFileInfo = dfsClient.uploadFile(file.getBytes(), suffix);
                if (fastDfsFileInfo != null) {
                    System.out.println(fastDfsFileInfo);
                    appinfoDTO.setXappIcon("/" + fastDfsFileInfo.getGroup() + "/" + fastDfsFileInfo.getStorageId());
                } else {
                    return JsonVO.fail("图标上传失败，请稍后重试。");
                }
            } catch (Exception e) {
                throw new RuntimeException(e);
            }
        }

        //执行新增栏目
        String xid = cmsAppinfoService.addColumn(appinfoDTO);
        //名字重复
        if (xid.equals("Name already exist")) {
            return JsonVO.fail("应用名称已被占用，无法继续保存数据。Name:" + appinfoDTO.getXappName());
        }

        //组装对应栏目的栏目配置
        AppinfoConfigDTO appinfoConfigDTO = new AppinfoConfigDTO();
        appinfoConfigDTO.setXid(xid);
        appinfoConfigDTO.setXcreateTime(time);
        appinfoConfigDTO.setXupdateTime(time);
        appinfoConfigDTO.setXsequence(xSequence);
        appinfoConfigDTO.setXconfig("{\"ignoreTitle\":false,\"latest\":true,\"saveDraftOnClose\":true}");
        //新增栏配置
        Integer addedColumnConfigSuccess = cmsAppinfoConfigService.addColumnConfig(appinfoConfigDTO);

        //成功则返回新建栏目xid
        if (xid != null && addedColumnConfigSuccess > 0) {
            return JsonVO.success(xid);
        }
        return JsonVO.fail("新建栏目失败，请稍后重试。");

    }

    /**
     * 删除栏目
     * @param xid 栏目标识
     * @return 返回删除提示
     */
    @SneakyThrows
    @Transactional
    @DeleteMapping("remove-column-by-id")
    @ApiOperation("删除栏目")
    @Override
    public JsonVO<String> removeAppinfoByXid(@RequestParam("xid") String xid) {

        String xappIcon = cmsAppinfoService.getById(xid).getXappIcon();
        if (xappIcon.startsWith("/")) {
            xappIcon = xappIcon.substring(1);
        }

        // 使用indexOf和substring方法分割字符串
        int index = xappIcon.indexOf('/');
        if (index != -1) {
            String group = xappIcon.substring(0, index);
            String storageId = xappIcon.substring(index + 1);

            try {
                int i = dfsClient.deleteFile(FastDfsFileInfo.builder().group(group).storageId(storageId).build());
            } catch (Exception e) {
                throw new RuntimeException(e);
            }
        }


        //删除对应栏目与栏目配置
        Integer deleteColumnSuccess = cmsAppinfoService.deleteColumn(xid);
        Integer deleteColumnConfigSuccess = cmsAppinfoConfigService.deleteColumnConfig(xid);
        //成功
        if (deleteColumnSuccess > 0 && deleteColumnConfigSuccess > 0) {
            return JsonVO.success("删除栏目成功。");
        }
        //失败
        return JsonVO.fail("删除栏目失败，请稍后重试。");
    }

}

