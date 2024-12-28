package com.zeroone.star.settings.service;

import com.zeroone.star.project.dto.j1.settings.ModifyPasswordDTO;
import com.zeroone.star.project.dto.j1.settings.SaveInfoDTO;
import com.zeroone.star.settings.entity.OrgPerson;
import com.baomidou.mybatisplus.extension.service.IService;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author juhao
 * @since 2024-10-21
 */
public interface IOrgPersonService extends IService<OrgPerson> {
    Boolean updatePassword(ModifyPasswordDTO data);

    void updatePersonInfo(SaveInfoDTO data);
}
