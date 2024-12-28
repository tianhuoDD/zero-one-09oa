#pragma once
#ifndef _MEETING_QUERY_
#define _MEETING_QUERY_

#include "../../GlobalInclude.h"


#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例分页查询对象
 */
class MeetingQuery : public oatpp::DTO
{
	DTO_INIT(MeetingQuery, DTO);
	//会议的唯一ID
	DTO_FIELD(String, id);

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_MEETING_QUERY_