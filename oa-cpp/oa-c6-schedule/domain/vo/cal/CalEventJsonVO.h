#pragma once
#ifndef _CALEVENTJSONVO_H_
#define _CALEVENTJSONVO_H_
#include "../../GlobalInclude.h"
#include "CalEventVO.h"
#include "CalEventsVO.h"

#include OATPP_CODEGEN_BEGIN(DTO)
//������ʾJsonVO��������Ӧ���ͻ��˵�Json����
//��һ������
//�������������ֶ�

class CalEventJsonVO :public JsonVO<CalEventVO::Wrapper>
{
	DTO_INIT(CalEventJsonVO,JsonVO<CalEventVO::Wrapper>);
};

//�����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
//���������ݣ���־�б�
//�������������ֶ�

/*class CalEventsJsonVO :public JsonVO<CalEventsVO::Wrapper>
{
	DTO_INIT(CalEventsJsonVO, JsonVO < CalEventsVO::Wrapper>);
};

*/
//�ṩһ���ܵ�jsonVO���ض��󣬺��������ݷ�װΪ���Ϸ���

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