#pragma once

#ifndef _Ddelete_VO_
#define _Ddelete_VO_

#include "../../GlobalInclude.h"
#include "../../dto/remove/DdeleteDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//	删除目录VO
class DdeleteVO : public oatpp::DTO
{
	DTO_INIT(DdeleteVO, DTO);

	// id
	API_DTO_FIELD(String, xid, ZH_WORDS_GETTER("Myfile.fiel.xid"), true, "123456789");
	// 新名称
	API_DTO_FIELD(String, xname, ZH_WORDS_GETTER("Myfile.fiel.xname"), true, "C6");
	// 目录更新时间
	//API_DTO_FIELD(String, xupdateTime, ZH_WORDS_GETTER("Myfile.field.xupdateTime"), true, "0");
};
/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class DdeleteJsonVO : public JsonVO<DdeleteVO::Wrapper> {
	DTO_INIT(DdeleteJsonVO, JsonVO<DdeleteVO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_

