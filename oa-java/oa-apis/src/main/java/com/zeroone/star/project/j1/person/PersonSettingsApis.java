package com.zeroone.star.project.j1.person;

import com.zeroone.star.project.vo.j1.person.setting.PersonInfoVo;
import com.zeroone.star.project.vo.JsonVO;

/**
 * 用户修改信息接口
 * @author Unicorn
 */
public interface PersonSettingsApis {
    /**
     * 获取个人信息
     * @param id 用户id
     * @return 获取到的用户信息
     */
    JsonVO<PersonInfoVo> queryPersonInfo(String id);

    /**
     * 修改个人信息
     * @param personInfoVo 要修改的参数
     * @return 返回修改结果
     */
    JsonVO<Boolean> modifyPersonInfo(PersonInfoVo personInfoVo);

}
