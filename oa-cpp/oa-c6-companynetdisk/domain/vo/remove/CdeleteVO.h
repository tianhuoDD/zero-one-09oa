#pragma once

#ifndef _Cdelete_VO_
#define _Cdelete_VO_

#include "../../GlobalInclude.h"
#include "../../dto/remove/CdeleteDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//	删除目录VO
class CdeleteVO : public oatpp::DTO
{
	DTO_INIT(CdeleteVO, DTO);

	// id
	API_DTO_FIELD(String, xid, ZH_WORDS_GETTER("Myfile.field.xid"), true, "123456789");
	// 新名称
	API_DTO_FIELD(String, xname, ZH_WORDS_GETTER("Myfile.field.xname"), true, "C6");
	// 目录更新时间
	//API_DTO_FIELD(String, xupdateTime, ZH_WORDS_GETTER("Myfile.field.xupdateTime"), true, "0");
};
/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class CdeleteJsonVO : public JsonVO<CdeleteVO::Wrapper> {
	DTO_INIT(CdeleteJsonVO, JsonVO<CdeleteVO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_
