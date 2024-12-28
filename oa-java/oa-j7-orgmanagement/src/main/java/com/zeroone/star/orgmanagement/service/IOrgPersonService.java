package com.zeroone.star.orgmanagement.service;

import com.zeroone.star.orgmanagement.entity.OrgPerson;
import com.baomidou.mybatisplus.extension.service.IService;
import org.springframework.web.multipart.MultipartFile;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author zlw
 * @since 2024-10-18
 */
public interface IOrgPersonService extends IService<OrgPerson> {

    /**
     * 人员导入
     * @param file
     */
    void importPerson(MultipartFile file);

    /**
     * 人员导出
     */
    void exportPerson();
}
