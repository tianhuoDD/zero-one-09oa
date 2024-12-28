#pragma once
#ifndef _CALEVENTJSONVO_H_
#define _CALEVENTJSONVO_H_
#include "../../GlobalInclude.h"
#include "CalEventVO.h"
#include "CalEventsVO.h"

#include OATPP_CODEGEN_BEGIN(DTO)
//定义显示JsonVO，用于响应给客户端的Json对象
//即一条数据
//几乎包含所有字段

class CalEventJsonVO :public JsonVO<CalEventVO::Wrapper>
{
	DTO_INIT(CalEventJsonVO,JsonVO<CalEventVO::Wrapper>);
};

//定义分页显示JsonVO，用于响应给客户端的Json对象
//即多条数据（日志列表）
//包含部分所需字段

/*class CalEventsJsonVO :public JsonVO<CalEventsVO::Wrapper>
{
	DTO_INIT(CalEventsJsonVO, JsonVO < CalEventsVO::Wrapper>);
};

*/
//提供一个总的jsonVO返回对象，后面是数据分装为集合返回

/*
class CalAllEventsJsonVO :public JsonVO<list<CalEventsVO::Wrapper>>
{
	DTO_INIT(CalAllEventsJsonVO, JsonVO<list<CalEventsVO::Wrapper>>);
};
*/

class CalAllEventsJsonVO :public JsonVO<CalAllEventsVO::Wrapper>
{
	DTO_INIT(CalAllEventsJsonVO, JsonVO<CalAllEventsVO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_CALEVENTVO_H_