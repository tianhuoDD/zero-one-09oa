#pragma once
#ifndef _PROCESSLIST_VO_
#define _PROCESSLIST_VO_

#include "../../GlobalInclude.h"
#include "../../dto/process/ProcessListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �����б���ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class ProcessListJsonVO : public JsonVO<ProcessListDTO::Wrapper> {
	DTO_INIT(ProcessListJsonVO, JsonVO<ProcessListDTO::Wrapper>);
};

/**
 * �����б��ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class ProcessListPageJsonVO : public JsonVO<ProcessListPageDTO::Wrapper> {
	DTO_INIT(ProcessListPageJsonVO, JsonVO<ProcessListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)



#endif // !_PROCESSLIST_VO_
