
package com.zeroone.star.project.j1.person;

import com.zeroone.star.project.dto.j1.person.setting.PersonInfohanDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j1.person.setting.PersonInfohanVO;

/**
 * 用户个人设置相关接口声明
 */
public interface PersonSettingApishan {
    /**
     * 获取个人信息
     *
     * @param id 用户id
     * @return 获取到的信息
     */
    JsonVO<PersonInfohanVO> queryPersonInfo(String id);

    /**
     * 修改个人信息
     *
     * @param personInfoDTO 要修改的信息
     * @return 修改结果
     */
//    JsonVO<Boolean> modifyPersonInfo(PersonInfohanDTO personInfoDTO);


}
