#pragma once
#ifndef _MEETING_QUERY_
#define _MEETING_QUERY_

#include "../../GlobalInclude.h"


#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ҳ��ѯ����
 */
class MeetingQuery : public oatpp::DTO
{
	DTO_INIT(MeetingQuery, DTO);
	//�����ΨһID
	DTO_FIELD(String, id);

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_MEETING_QUERY_