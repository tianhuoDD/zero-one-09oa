#pragma once
#ifndef _PERSONLISTVO_H_
#define _PERSONLISTVO_H_
#include "../../GlobalInclude.h"
#include "domain/query/gets-person-lists/Personlistquery.h"
#include "domain/dto/gets-person-lists/PersonlistDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class PersonlistPageJsonVO : public JsonVO<PersonlistPageDTO::Wrapper> {
	DTO_INIT(PersonlistPageJsonVO, JsonVO<PersonlistPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_