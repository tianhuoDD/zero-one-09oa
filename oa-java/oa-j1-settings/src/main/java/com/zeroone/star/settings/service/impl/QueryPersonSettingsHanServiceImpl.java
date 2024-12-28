package com.zeroone.star.settings.service.impl;

import com.zeroone.star.project.vo.j1.person.setting.PersonInfohanVO;
import com.zeroone.star.settings.entity.OrgPerson;
import com.zeroone.star.settings.mapper.QueryPersonSettingsHanMapper;
import com.zeroone.star.settings.service.IqueryPersonSettingsHanService;
import com.zeroone.star.settings.service.IqueryPersonSettingsHanService;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

@Service
public class QueryPersonSettingsHanServiceImpl implements IqueryPersonSettingsHanService {

    @Resource
    QueryPersonSettingsHanMapper queryPersonSettingsHanMapper;

    /**
     * 查询个人信息
     * @param id
     * @return //xid, xlanguage, xmail, xmobile, xname, xofficePhone, xqq, xweixin, xdescription, xemployee, xnickName, xipAddress
     *
     */
    @Override
    public PersonInfohanVO getPersonInfohan(String id) {
        OrgPerson orgPerson = queryPersonSettingsHanMapper.getOrgPersonById(id);
        PersonInfohanVO personInfohanVO = new PersonInfohanVO();
        if (orgPerson == null) {
            return personInfohanVO;
        }
        System.out.println(orgPerson.getXmail());
        if (orgPerson != null) {

            personInfohanVO.setId(orgPerson.getXid());
            personInfohanVO.setLanguage(orgPerson.getXlanguage());
            personInfohanVO.setName(orgPerson.getXname());
            personInfohanVO.setMail(orgPerson.getXmail());
            personInfohanVO.setTelphone(orgPerson.getXmobile());
            personInfohanVO.setPhone(orgPerson.getXofficePhone());
            personInfohanVO.setQq(orgPerson.getXqq());
            personInfohanVO.setWeixin(orgPerson.getXweixin());
            personInfohanVO.setSingle(orgPerson.getXsignature());
            personInfohanVO.setNumber(orgPerson.getXemployee());
            personInfohanVO.setBbsname(orgPerson.getXnickName());
            personInfohanVO.setHead(orgPerson.getXipAddress());
            return personInfohanVO;
        }
        return personInfohanVO;
    }
}
