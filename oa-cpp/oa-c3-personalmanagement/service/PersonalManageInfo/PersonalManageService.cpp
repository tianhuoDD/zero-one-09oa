#include "stdafx.h"
#include "PersonalManageService.h"
#include "../../dao/PersonalManageDAO/PersonalManageDAO.h"
#include "bcrypt/bcrypt.h"
#include  <chrono> 

std::string get_current_time_string() {
    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);
    std::ostringstream oss;
    oss << std::put_time(std::localtime(&now_time), "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

PersonalManageInfoDTO::Wrapper PersonalManageService::queryPersonalManageInfo(const string& xunique)
{
	PersonalManageDAO dao;
    org_personDO res = dao.selectbyxunique(xunique);
	auto dto = PersonalManageInfoDTO::createShared();
    ZO_STAR_DOMAIN_DO_TO_DTO(dto, res,
        xunique, Xunique,                       // 唯一编码
        xname, Xname,                           // 姓名
        xmobile, Xmobile,                       // 手机号码
        xofficePhone, XofficePhone,             // 工作电话
        xgenderType, XgenderType,               // 性别
        xmail, Xmail,                         // 邮箱
        xqq, Xqq,                               // QQ号码
        xweixin, Xweixin,                       // 微信号
        xboardDate, XboardDate,                 // 入职时间
        xipAddress, XipAddress,                 // 登录IP
        xsubjectSecurityClearance, XsubjectSecurityClearance, // 密级标识
        xemployee, Xemployee,                   // 工号
        xbirthday, Xbirthday,                   // 生日
        xdescription, Xdescription,             // 描述
        xstatus, Xstatus,                       // 状态
        xsuperior, Xsuperior,                 // 汇报对象
		xid, Xid);							 // ID
	return dto;
}

bool PersonalManageService::modifyPersonalManageInfo(const PersonalManageInfoDTO::Wrapper& dto)
{
    org_personDO data;
	//    cout << dto->xname->c_str() << endl;
	string time = get_current_time_string();
	data.setXupdateTime(time);
    string distinguishedName = string(dto->xname->c_str()) + '@' + string(dto->xunique->c_str()) + '@' + 'P';
    data.setXdistinguishedName(distinguishedName);
    //string pinyin = getLetter(string(dto->xname->c_str()));
    //string pinyinInitial = getLetter(string(dto->xname->c_str()), true);
    string mobile = dto->xmobile->c_str();
	string password = mobile.substr(mobile.length() - 6, 6);
	password = bcrypt::generateHash(password);
	data.setXpassword(password);
	//    cout << pinyin << pinyinInitial << endl;
    ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,
        Xunique, xunique,                       // 唯一编码
        Xname, xname,                           // 姓名
        Xmobile, xmobile,                       // 手机号码
        XofficePhone, xofficePhone,             // 工作电话
        XgenderType, xgenderType,               // 性别
        Xmail, xmail,                         // 邮箱
        Xqq, xqq,                               // QQ号码
        Xweixin, xweixin,                       // 微信号
        XboardDate, xboardDate,                 // 入职时间
        XipAddress, xipAddress,                 // 登录IP
        XsubjectSecurityClearance, xsubjectSecurityClearance, // 密级标识
        Xemployee, xemployee,                   // 工号
        Xbirthday, xbirthday,                   // 生日
        Xdescription, xdescription,             // 描述
		Xstatus, xstatus,                       // 状态 // 状态不可修改
        Xsuperior, xsuperior,                   // 汇报对象
		Xid, xid);							 // ID
    //data.setXpinyin(pinyin);
   // data.setXpinyinInitial(pinyinInitial);
	PersonalManageDAO dao;
	return dao.update(data) == 1;
	//return false;
}

