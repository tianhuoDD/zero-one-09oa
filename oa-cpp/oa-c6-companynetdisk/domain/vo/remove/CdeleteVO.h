#pragma once

#ifndef _Cdelete_VO_
#define _Cdelete_VO_

#include "../../GlobalInclude.h"
#include "../../dto/remove/CdeleteDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//	ɾ��Ŀ¼VO
class CdeleteVO : public oatpp::DTO
{
	DTO_INIT(CdeleteVO, DTO);

	// id
	API_DTO_FIELD(String, xid, ZH_WORDS_GETTER("Myfile.field.xid"), true, "123456789");
	// ������
	API_DTO_FIELD(String, xname, ZH_WORDS_GETTER("Myfile.field.xname"), true, "C6");
	// Ŀ¼����ʱ��
	//API_DTO_FIELD(String, xupdateTime, ZH_WORDS_GETTER("Myfile.field.xupdateTime"), true, "0");
};
/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class CdeleteJsonVO : public JsonVO<CdeleteVO::Wrapper> {
	DTO_INIT(CdeleteJsonVO, JsonVO<CdeleteVO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_
