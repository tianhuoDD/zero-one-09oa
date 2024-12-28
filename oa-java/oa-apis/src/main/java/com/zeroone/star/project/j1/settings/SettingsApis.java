package com.zeroone.star.project.j1.settings;

import com.zeroone.star.project.dto.j1.settings.ModifyPasswordDTO;
import com.zeroone.star.project.dto.j1.settings.SaveInfoDTO;
import com.zeroone.star.project.vo.JsonVO;

public interface SettingsApis {
    JsonVO<Boolean> ModifyPassword(ModifyPasswordDTO data);

    JsonVO<Boolean> SaveInfo(SaveInfoDTO data);
}
