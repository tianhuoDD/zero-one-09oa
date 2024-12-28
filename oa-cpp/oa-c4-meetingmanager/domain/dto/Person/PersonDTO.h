#pragma once
#ifndef _PERSON_DTO_
#define _PRESON_DTO_
#include"../../GlobalInclude.h"
#include"domain/dto/Unit/UnitDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)
class PersonDTO : public oatpp::DTO {

    DTO_INIT(PersonDTO, DTO)
    DTO_FIELD(String, id);  // Ψһ��ʶ�������ڱ�ʶ����� ID

    DTO_FIELD(String, genderType);  // �Ա����ͣ�"m" ��ʾ���ԣ�"f" ��ʾŮ��
    DTO_FIELD(String, signature);  // ǩ���ֶ�
    DTO_FIELD(String, pinyin);  // ���ֵ�ƴ��
    DTO_FIELD(String, pinyinInitial);  // ����ƴ��������ĸ
    DTO_FIELD(String, description);  // ���ֶε���ϸ����
    DTO_FIELD(String, name);  // ��Ա��λ��
    DTO_FIELD(String, employee);  // Ա����Ż����
    DTO_FIELD(String, unique);  // Ψһ�ַ���
    DTO_FIELD(String, distinguishedName);  // ��ʾ����
    DTO_FIELD(Int64, orderNumber);  // �����
    DTO_FIELD(String, superior);  // �ϼ���ֱ�ӹ����ߵı�ʶ��
    DTO_FIELD(String, ipAddress);  // IP ��ַ
    DTO_FIELD(String, mail);  // �ʼ���ַ
    DTO_FIELD(String, weixin);  // ΢�ź�
    DTO_FIELD(String, qq);  // QQ��
    DTO_FIELD(String, mobile);  // �ֻ�����
    DTO_FIELD(String, officePhone);  // �칫�绰
    DTO_FIELD(String, status);  // ״̬
    DTO_FIELD(String, createTime);  // ����ʱ��
    DTO_FIELD(String, updateTime);  // ����ʱ��

};
class WoPerson : public PersonDTO {
    DTO_INIT(WoPerson, PersonDTO);
    DTO_FIELD(List<String>, controllerList);  // �������б�
    DTO_FIELD(List<String>, topUnitList);  // ������λ�б�
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_PERSON_DTO_
