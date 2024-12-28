#pragma once

#ifndef _DdeleteDTO_H_
#define _DdeleteDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
 * ʾ���������
 */
class DdeleteDTO : public oatpp::DTO
{
	DTO_INIT(DdeleteDTO, DTO);
	// �ļ�id
	API_DTO_FIELD_DEFAULT(String, xid, ZH_WORDS_GETTER("Myfile.file.xid"));
	// new name
	API_DTO_FIELD_DEFAULT(String, xname, ZH_WORDS_GETTER("Myfile.file.xname"));

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_