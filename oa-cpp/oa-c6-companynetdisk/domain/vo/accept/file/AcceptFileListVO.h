#pragma once
#ifndef _ACCEPTFILELISTVO_H_
#define _ACCEPTFILELISTVO_H_
#include "../../../GlobalInclude.h"
#include "../../../dto/accept/file/AcceptFileListDTO.h"


#include OATPP_CODEGEN_BEGIN(DTO)


/*
	���ļ�����Ϣ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
*/
class AcceptFileListJsonVO : public JsonVO<AcceptFilesPageDTO::Wrapper>
{
	DTO_INIT(AcceptFileListJsonVO, JsonVO<AcceptFilesPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_

