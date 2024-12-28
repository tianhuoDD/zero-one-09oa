#pragma once

#ifndef _FILERESPONSEDTO_H_
#define _FILERESPONSEDTO_H_


#include "../../GlobalInclude.h"
#include "oatpp/core/Types.hpp"
#include "oatpp/core/macro/codegen.hpp"


// excel上传返回的Json格式
// DTO 定义
#include OATPP_CODEGEN_BEGIN(DTO)
class ImportResponseDTO : public oatpp::DTO
{
	DTO_INIT(ImportResponseDTO, DTO);

	DTO_FIELD(String, type);
	DTO_FIELD(String, message);
	DTO_FIELD(String, date);
	//DTO_FIELD(Int32, spent);
	DTO_FIELD(Int32, size);		
	DTO_FIELD(Int32, count);
	//DTO_FIELD(Int32, pos);
public:
	ImportResponseDTO()
	{
		this->type = "";
		this->message = "";
		this->date = "";
		//spent = -1;
		this->size = -1;
		this->count = -1;
		//pos = -1;
	}

};
#include OATPP_CODEGEN_END(DTO)




#endif // !_FILERESPONSEDTO_H_
