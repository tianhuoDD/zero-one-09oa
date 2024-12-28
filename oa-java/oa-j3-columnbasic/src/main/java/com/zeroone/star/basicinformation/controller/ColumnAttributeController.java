package com.zeroone.star.basicinformation.controller;


import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.zeroone.star.basicinformation.entity.CmsAppinfo;
import com.zeroone.star.basicinformation.entity.CmsAppinfoManageablepersonlist;
import com.zeroone.star.basicinformation.entity.CmsAppinfoPublishablepersonlist;
import com.zeroone.star.basicinformation.entity.CmsAppinfoViewablepersonlist;
import com.zeroone.star.basicinformation.mapper.CmsAppinfoManageablepersonlistMapper;
import com.zeroone.star.basicinformation.mapper.CmsAppinfoMapper;
import com.zeroone.star.basicinformation.mapper.CmsAppinfoPublishablepersonlistMapper;
import com.zeroone.star.basicinformation.mapper.CmsAppinfoViewablepersonlistMapper;
import com.zeroone.star.basicinformation.service.ColumnAttributeService;
import com.zeroone.star.project.components.fastdfs.FastDfsClientComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsFileInfo;
import com.zeroone.star.project.j3.ColumnAttribute.dto.*;
import com.zeroone.star.project.j3.ColumnAttribute.vo.ColumnAttributeVO;
import com.zeroone.star.project.j3.colunAttribute.ColumnAttributeApi;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.SneakyThrows;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;
import java.time.LocalDateTime;
import java.util.List;

/**
 * <p>
 * 前端控制器
 * </p>
 *
 * @author 阿伟
 * @since 2024-10-20
 */
@RestController
@RequestMapping("columnattribute")
@Api(tags = "栏目属性")
public class ColumnAttributeController implements ColumnAttributeApi {

    @Resource
    private CmsAppinfoManageablepersonlistMapper cmsAppinfoManageablepersonlistMapper;

    @Resource
    private CmsAppinfoPublishablepersonlistMapper cmsAppinfoPublishablepersonlistMapper;

    @Resource
    private CmsAppinfoViewablepersonlistMapper cmsAppinfoViewablepersonlistMapper;

    @Resource
    private CmsAppinfoMapper cmsAppinfoMapper;

    @Autowired
    private ColumnAttributeService columnAttributeService;

    /**
     * 查询栏目属性
     *
     * @param id
     * @return
     */
    @GetMapping("query-columnattribute")
    @ApiOperation(value = "查询栏目属性")
    @Override
    public JsonVO<ColumnAttributeVO> queryColumnAttribute(String id) {
        return  JsonVO.success(columnAttributeService.queryColumnAttribute(id));
    }

    /**
     * 更新栏目属性
     * @param columnAttributeDTO
     * @return
     */
    @PostMapping("update-columnattribute")
    @ApiOperation(value = "更新栏目属性")
    @Override
    public JsonVO<Boolean> modifyColumnAttribute(@RequestBody ColumnAttributeDTO columnAttributeDTO) {
        return JsonVO.success(columnAttributeService.modifyCmsForm(columnAttributeDTO));
    }

    /**
     * 更新可见范围
     * @param columnViewableListDTO
     * @return
     */
    @PostMapping("update-column-viewable-list")
    @ApiOperation("更新可见范围")
    public JsonVO<Boolean> modifyColumnViewableList(@RequestBody ColumnViewableListDTO columnViewableListDTO){
        String xid = columnViewableListDTO.getXid();
        cmsAppinfoViewablepersonlistMapper.deleteById(xid);
        List<String> arr = columnViewableListDTO.getXviewablePersonList();
        Integer i=0;
        for(String s:arr){
            CmsAppinfoViewablepersonlist cmsAppinfoViewablepersonlist = new CmsAppinfoViewablepersonlist();
            cmsAppinfoViewablepersonlist.setAPPINFO_XID(xid);
            cmsAppinfoViewablepersonlist.setXviewablePersonList(s);
            cmsAppinfoViewablepersonlist.setXorderColumn(i);
            cmsAppinfoViewablepersonlistMapper.insert(cmsAppinfoViewablepersonlist);
            i++;
        }
        if(arr!=null){
            CmsAppinfo cmsAppinfo = new CmsAppinfo();
            cmsAppinfo.setXallPeopleView(false);
            cmsAppinfo.setXupdateTime(LocalDateTime.now());
            QueryWrapper<CmsAppinfo> queryWrapper = new QueryWrapper<CmsAppinfo>().eq("xid", xid);
            cmsAppinfoMapper.update(cmsAppinfo, queryWrapper);
        }
        return JsonVO.success(true);
    }

    /**
     * 更新发布者
     * @param columnPublishableListDTO
     * @return
     */
    @PostMapping("update-column-publishable-list")
    @ApiOperation("更新发布者")
    public JsonVO<Boolean> modifyColumnPublishableList(@RequestBody ColumnPublishableListDTO columnPublishableListDTO){
        String xid = columnPublishableListDTO.getXid();
        cmsAppinfoPublishablepersonlistMapper.deleteById(xid);
        List<String> arr = columnPublishableListDTO.getXpublishablePersonList();
        Integer i=0;
        for(String s:arr){
            CmsAppinfoPublishablepersonlist cmsAppinfoPublishablepersonlist = new CmsAppinfoPublishablepersonlist();
            cmsAppinfoPublishablepersonlist.setAPPINFO_XID(xid);
            cmsAppinfoPublishablepersonlist.setXpublishablePersonList(s);
            cmsAppinfoPublishablepersonlist.setXorderColumn(i);
            cmsAppinfoPublishablepersonlistMapper.insert(cmsAppinfoPublishablepersonlist);
            i++;
        }
        if(arr!=null){
            CmsAppinfo cmsAppinfo = new CmsAppinfo();
            cmsAppinfo.setXallPeoplePublish(false);
            cmsAppinfo.setXupdateTime(LocalDateTime.now());
            QueryWrapper<CmsAppinfo> queryWrapper = new QueryWrapper<CmsAppinfo>().eq("xid", xid);
            cmsAppinfoMapper.update(cmsAppinfo, queryWrapper);
        }
        return JsonVO.success(true);
    }

    /**
     * 更新管理者
     * @param columnManageableListDTO
     * @return
     */
    @PostMapping("update-column-manageable-list")
    @ApiOperation("更新管理者")
    public JsonVO<Boolean> modifyColumnManageableList(@RequestBody ColumnManageableListDTO columnManageableListDTO){
        String xid = columnManageableListDTO.getXid();
        cmsAppinfoManageablepersonlistMapper.deleteById(xid);
        List<String> arr = columnManageableListDTO.getXmanageablePersonList();
        Integer i=0;
        for(String s:arr){
            CmsAppinfoManageablepersonlist cmsAppinfoManageablepersonlist = new CmsAppinfoManageablepersonlist();
            cmsAppinfoManageablepersonlist.setAPPINFO_XID(xid);
            cmsAppinfoManageablepersonlist.setXmanageablePersonList(s);
            cmsAppinfoManageablepersonlist.setXorderColumn(i);
            int x=cmsAppinfoManageablepersonlistMapper.insert(cmsAppinfoManageablepersonlist);
            i++;
        }
        CmsAppinfo cmsAppinfo = new CmsAppinfo();
        cmsAppinfo.setXupdateTime(LocalDateTime.now());
        QueryWrapper<CmsAppinfo> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("XID", xid);
        cmsAppinfoMapper.update(cmsAppinfo, queryWrapper);
        return JsonVO.success(true);
    }
    @Resource
    FastDfsClientComponent dfsClient;
    @Value("${fastdfs.nginx-servers}")
    private String fileServerUrl;
    @SneakyThrows
    @ApiOperation("修改图标")
    @PostMapping("update-icon")
    public JsonVO<String> upload(  ColumnAppIconDTO columnAppIconDTO)
    {
        //获取栏目识别id
        String xid =columnAppIconDTO.getXid();
        //获取文件
        MultipartFile file=columnAppIconDTO.getFile();
        //删除图标
        String oldIcon = cmsAppinfoMapper.getById(xid).getXappIcon();
        String[] parts = oldIcon.split("/", 3);
        String group = parts[1]; // group是第二部分
        String storageId = parts[2]; // 剩下的内容是第三部分
        dfsClient.deleteFile(FastDfsFileInfo.builder().group(group).storageId(storageId).build());
        //获取上传文件的后缀名称
        String filename = file.getOriginalFilename();
        assert filename != null;
        String suffix = filename.substring(filename.lastIndexOf(".") + 1);
        //上传文件
        FastDfsFileInfo fastDfsFileInfo = dfsClient.uploadFile(file.getBytes(), suffix);
        if(fastDfsFileInfo != null){
            CmsAppinfo cmsAppinfo = new CmsAppinfo();
            String xappIcon = "/"+fastDfsFileInfo.getGroup() + "/" + fastDfsFileInfo.getStorageId();
            cmsAppinfo.setXappIcon(xappIcon);
            cmsAppinfo.setXupdateTime(LocalDateTime.now());
            cmsAppinfo.setXiconColor(columnAppIconDTO.getXiconColor());
            QueryWrapper<CmsAppinfo> queryWrapper = new QueryWrapper<>();
            queryWrapper.eq("XID", xid);
            cmsAppinfoMapper.update(cmsAppinfo, queryWrapper);
            return JsonVO.success(dfsClient.fetchUrl(fastDfsFileInfo, fileServerUrl, true));
        }
        return JsonVO.fail("上传失败");
    }

}
