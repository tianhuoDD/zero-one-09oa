#pragma once
#ifndef _PERSON_DTO_
#define _PRESON_DTO_
#include"../../GlobalInclude.h"
#include"domain/dto/Unit/UnitDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)
class PersonDTO : public oatpp::DTO {

    DTO_INIT(PersonDTO, DTO)
    DTO_FIELD(String, id);  // 唯一标识符，用于标识对象的 ID

    DTO_FIELD(String, genderType);  // 性别类型，"m" 表示男性，"f" 表示女性
    DTO_FIELD(String, signature);  // 签名字段
    DTO_FIELD(String, pinyin);  // 名字的拼音
    DTO_FIELD(String, pinyinInitial);  // 名字拼音的首字母
    DTO_FIELD(String, description);  // 该字段的详细描述
    DTO_FIELD(String, name);  // 人员或单位的
    DTO_FIELD(String, employee);  // 员工编号或代号
    DTO_FIELD(String, unique);  // 唯一字符串
    DTO_FIELD(String, distinguishedName);  // 显示名称
    DTO_FIELD(Int64, orderNumber);  // 排序号
    DTO_FIELD(String, superior);  // 上级或直接管理者的标识符
    DTO_FIELD(String, ipAddress);  // IP 地址
    DTO_FIELD(String, mail);  // 邮件地址
    DTO_FIELD(String, weixin);  // 微信号
    DTO_FIELD(String, qq);  // QQ号
    DTO_FIELD(String, mobile);  // 手机号码
    DTO_FIELD(String, officePhone);  // 办公电话
    DTO_FIELD(String, status);  // 状态
    DTO_FIELD(String, createTime);  // 创建时间
    DTO_FIELD(String, updateTime);  // 更新时间

};
class WoPerson : public PersonDTO {
    DTO_INIT(WoPerson, PersonDTO);
    DTO_FIELD(List<String>, controllerList);  // 控制者列表
    DTO_FIELD(List<String>, topUnitList);  // 顶级单位列表
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_PERSON_DTO_
