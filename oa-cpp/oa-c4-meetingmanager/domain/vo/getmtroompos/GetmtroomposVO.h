#pragma once

#ifndef _GETMTROOMPOS_VO_
#define _GETMTROOMPOS_VO_

#include "../../GlobalInclude.h"
#include "../../dto/getmtroompos/GetmtroomposDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class GetmtroomposJsonVO : public JsonVO<GetmtroomposDTO::Wrapper> {
	DTO_INIT(GetmtroomposJsonVO, JsonVO<GetmtroomposDTO::Wrapper>);
	//DTO_FIELD(Vector<Object<GetmtroomposDTO>>, rows);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class GetmtroomposPageJsonVO : public JsonVO<GetmtroomposPageDTO::Wrapper> {
	DTO_INIT(GetmtroomposPageJsonVO, JsonVO<GetmtroomposPageDTO::Wrapper>);
	//DTO_FIELD(Vector<Object<GetmtroomposPageDTO>>, rows);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_GETMTROOMPOS_VO_