#pragma once
#ifndef _GETROLEVO_H_
#define _GETROLEVO_H_

#include "../../GlobalInclude.h" //����Ŀ¼
#include "domain/dto/get/GetroleDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)//���DTO�ඨ��ĺ�


class GetroleVO :public oatpp::DTO
{
	DTO_INIT(GetroleVO, DTO);


	//��ɫ����
	API_DTO_FIELD(String, name, ZH_WORDS_GETTER("addroleDTO.field.name"), false, "");
	//Ψһ����
	API_DTO_FIELD(String, key, ZH_WORDS_GETTER("addroleDTO.field.key"), true, ""); 
	//��ɫ����
	API_DTO_FIELD(String, refer, ZH_WORDS_GETTER("addroleDTO.field.refer"), false, "");

	API_DTO_FIELD(String, fullName, ZH_WORDS_GETTER("addroleDTO.field.fullName"), false, "");

	//��ɫ������
	API_DTO_FIELD(String, startTime, ZH_WORDS_GETTER("addroleDTO.field.startTime"), false, "");

	//����޸���
	API_DTO_FIELD(String, endTime, ZH_WORDS_GETTER("addroleDTO.field.endTime"), false, "");



};




//������Ϣ��ʾJsonVO
class GetroleJsonVO : public JsonVO<GetroleVO::Wrapper> {
	DTO_INIT(GetroleJsonVO, JsonVO<GetroleVO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_GETROLEVO_H_
