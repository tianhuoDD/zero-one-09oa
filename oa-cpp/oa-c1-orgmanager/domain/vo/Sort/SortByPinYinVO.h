#pragma once
#ifndef _SortByPinYin_VO_
#define _SortByPinYin_VO_

#include "../../GlobalInclude.h"
#include "../../dto/Sort/SortByPinYinDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class SortByPinYinJsonVO : public JsonVO<SortByPinYinDTO::Wrapper> {
	DTO_INIT(SortByPinYinJsonVO, JsonVO<SortByPinYinDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class SortByPinYinPageJsonVO : public JsonVO<SortByPinYinPageDTO::Wrapper> {//!!!!!!!!!
	DTO_INIT(SortByPinYinPageJsonVO, JsonVO<SortByPinYinPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_