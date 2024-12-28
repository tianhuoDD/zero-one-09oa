package com.zeroone.star.settings.service.impl;

import com.zeroone.star.project.dto.j1.settings.ModifyPasswordDTO;
import com.zeroone.star.project.dto.j1.settings.SaveInfoDTO;
import com.zeroone.star.settings.entity.OrgPerson;
import com.zeroone.star.settings.mapper.OrgPersonMapper;
import com.zeroone.star.settings.service.IOrgPersonService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import java.util.Date;

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author juhao
 * @since 2024-10-21
 */
@Service
public class OrgPersonServiceImpl extends ServiceImpl<OrgPersonMapper, OrgPerson> implements IOrgPersonService{

    @Transactional
    @Override
    public Boolean updatePassword(ModifyPasswordDTO data) {
        String password = baseMapper.selectPasswordById(data.getId());
        boolean equals = data.getPrePassword().equals(password);
        if(!equals)
        {
            return false;
        }
        baseMapper.updatePassword(data.getNewPassword(), data.getId());
        baseMapper.updateChangePasswordTime(new Date(), data.getId());
        return true;
    }

    @Override
    public void updatePersonInfo(SaveInfoDTO data) {
        baseMapper.updatePersonInfo(data);
        baseMapper.updateUpdateTime(new Date(), data.getId());
    }
}
