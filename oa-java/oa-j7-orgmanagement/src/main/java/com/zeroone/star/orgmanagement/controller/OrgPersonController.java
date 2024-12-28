package com.zeroone.star.orgmanagement.controller;


import com.zeroone.star.orgmanagement.entity.OrgPerson;
import com.zeroone.star.orgmanagement.service.IOrgPersonService;
import com.zeroone.star.orgmanagement.utils.ExcelTemplate;
import com.zeroone.star.project.j7.orgmanagement.OrgManagementApis;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import org.springframework.web.multipart.MultipartFile;
import com.zeroone.star.project.j7.orgmanagement.OrgManagementApis;
import lombok.SneakyThrows;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import javax.annotation.Resource;
import java.io.ByteArrayOutputStream;


/**
 * <p>
 *  前端控制器
 * </p>
 *
 * @author zlw
 * @since 2024-10-18
 */
@RestController
@RequestMapping("/org-person")
@Api(tags = "组织管理人员导入导出控制器")
public class OrgPersonController implements OrgManagementApis {

    @Autowired
    private IOrgPersonService orgPersonService;
    @Resource
    ExcelTemplate excelTemplate;

    @Override
    @GetMapping(value = "get-import-template",produces = "application/octet-stream")
    @ApiOperation("获取导入模板")
    @SneakyThrows
    public ResponseEntity<byte[]> getImportTemplate() {
        // 创建输出流
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        //导出模板文件
        excelTemplate.export("人员导入模板",out, OrgPerson.class);
        // 将文件数据响应给前端
        HttpHeaders headers = new HttpHeaders();
        String filename =  "input_person_template"+ ".xlsx";
        headers.setContentDispositionFormData("attachment", filename);
        headers.setContentType(MediaType.APPLICATION_OCTET_STREAM);
        ResponseEntity<byte[]> result = new ResponseEntity<>(out.toByteArray(), headers, HttpStatus.CREATED);
        out.close();
        return result;
    }


    @Override
    @PostMapping("/import-person/{file}")
    @ApiOperation("组织管理 - 人员导入")
    public JsonVO importPerson(MultipartFile file) {
        orgPersonService.importPerson(file);
        return JsonVO.success(null);
    }

    @Override
    @PostMapping("/export-person")
    @ApiOperation("组织管理 - 人员导出")
    public JsonVO exportPerson() {
        orgPersonService.exportPerson();
        return JsonVO.success(null);
    }
}

