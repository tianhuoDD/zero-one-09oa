#pragma once

#ifndef _CALENDERLISTQUERY_H_
#define _CALENDERLISTQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//	���� ��ѯ�����б� �Ķ���
class CalenderListQuery : public PageQuery {
	DTO_INIT(CalenderListQuery, PageQuery);

	//	�û�id
	DTO_FIELD(String, xid);
	DTO_FIELD_INFO(xid) {
		info->description = ZH_WORDS_GETTER("calender.user.xid");
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_CALENDERLISTQUERY_H_
