#pragma once
/*
 @Author: LemonFlavoredSoda
 @Date: 2024�� 10�� 25�� ������ 19:27:32 CST
*/
#ifndef _ADDPERSON_VO_
#define _ADDPERSON_VO_

#include "../../GlobalInclude.h"
#include "../../dto/put/AddPersonDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class AddPersonJsonVO : public JsonVO<AddPersonDTO::Wrapper> {
	DTO_INIT(AddPersonJsonVO, JsonVO<AddPersonDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_ADDPERSON_VO_