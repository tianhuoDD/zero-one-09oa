package com.zeroone.star.settings.service;

import com.zeroone.star.project.dto.j1.person.setting.MotifyMailhanDTO;
import com.zeroone.star.project.dto.j1.person.setting.MotifyPhonehanDTO;

public interface IPersonSettingMotifyPMHanService {
    public String MotifyPhoneNumber(MotifyPhonehanDTO motifyPhonehanDTO);

    public String MotifyMailNumber(MotifyMailhanDTO motifyMailhanDTO);
}
