#pragma once

#ifndef _CdeleteDTO_H_
#define _CdeleteDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
 * 示例传输对象
 */
class CdeleteDTO : public oatpp::DTO
{
	DTO_INIT(CdeleteDTO, DTO);
	// 文件id or 目录id
	API_DTO_FIELD_DEFAULT(String, xid, ZH_WORDS_GETTER("Myfile.filed.xid"));
	// new name
	API_DTO_FIELD_DEFAULT(String, xname, ZH_WORDS_GETTER("Myfile.filed.xname"));

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_