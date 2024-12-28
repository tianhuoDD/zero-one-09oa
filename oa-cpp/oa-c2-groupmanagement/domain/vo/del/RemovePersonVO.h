#pragma once
/*
 @Author: LemonFlavoredSoda
 @Date: 2024�� 10�� 26�� ������ 09:37:55 CST
*/
#ifndef _REMOVEPERSON_VO_
#define _REMOVEPERSON_VO_

#include "../../GlobalInclude.h"
#include "../../dto/del/RemovePersonDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class RemovePersonJsonVO : public JsonVO<RemovePersonDTO::Wrapper> {
	DTO_INIT(RemovePersonJsonVO, JsonVO<RemovePersonDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_REMOVEPERSON_VO_