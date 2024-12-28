#pragma once

#ifndef _DATADETAILSDTO_H_
#define _DATADETAILSDTO_H
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)


class DataDetailsDTO : public oatpp::DTO {
	DTO_INIT(DataDetailsDTO, DTO);
	//表单id
	API_DTO_FIELD_DEFAULT(String, xid, ZH_WORDS_GETTER("data.details.bs"));
	API_DTO_FIELD_DEFAULT(String, xname, ZH_WORDS_GETTER("data.details.name"));
	API_DTO_FIELD_DEFAULT(String, xdescription, ZH_WORDS_GETTER("data.details.ms"));
	API_DTO_FIELD_DEFAULT(String, xalias, ZH_WORDS_GETTER("data.details.xalias"));
	
//details:
//bs: 标识
//name : 名称
//ms : 描述
//reado : 是否只读
//ys : 表单样式
//picture : 图标
//dy : 打印
//sc : 脚本
//type : 样式
//attr : 属性
};

#include OATPP_CODEGEN_END(DTO)
#endif