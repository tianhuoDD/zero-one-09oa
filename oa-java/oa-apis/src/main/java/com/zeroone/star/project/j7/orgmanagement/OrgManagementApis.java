package com.zeroone.star.project.j7.orgmanagement;

import com.zeroone.star.project.vo.JsonVO;
import org.springframework.http.ResponseEntity;
import org.springframework.web.multipart.MultipartFile;

public interface OrgManagementApis {

    /**
     * 获取导入模板
     * @return
     */
    ResponseEntity<byte[]> getImportTemplate();

    /**
     * 人员导入
     * @param file 文件
     */
    public JsonVO importPerson(MultipartFile file);

    /**
     * 人员导出
     */
    public JsonVO exportPerson();
}
