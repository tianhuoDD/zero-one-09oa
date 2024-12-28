package com.zeroone.star.login.service;

import com.zeroone.star.project.dto.login.Oauth2TokenDTO;
import com.zeroone.star.project.vo.JsonVO;

public interface ISmsLoginService {

    JsonVO<Oauth2TokenDTO> loginPersonByPhoneCode(String phoneCode, String id);

    String getPhoneCode(String id);
}
