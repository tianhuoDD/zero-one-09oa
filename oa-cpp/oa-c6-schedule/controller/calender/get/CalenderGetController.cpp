#include "stdafx.h"
#include "CalenderGetController.h"
#include "../../../service/calendar/CalendarListService.h"
#include "../../../service/calendar/CalendarInfoService.h"
#include <iostream>

CalenderInfoJsonVo::Wrapper CalenderGetController::execQueryCalenderInfo(const String& xid, const PayloadDTO& payload) {

	//	�����������
	
	if (!xid) {
		std::cout << "��������Ҫ��ѯ������ID" << std::endl;
		return {};
	}
	else {
		//	Service��
		CalendarInfoService service;
		//	��ѯ������ϸ
		auto result = service.queryCalendarInfo(xid);
		//	��Ӧ���
		auto jvo = CalenderInfoJsonVo::createShared();
		jvo->success(result);

		return jvo;
	}

	
	//return {};
}

CalenderListJsonVO::Wrapper CalenderGetController::execQueryCalenderList(const PayloadDTO& payload) {

	//std::cout << "����controller��" << std::endl;

	//	���ݼ���:  ��������ӿ����޲ε�...
	string id = payload.getId();
	//	Service��
	CalendarListService service;
	//	��ѯ�����б�
	auto result = service.queryCalenderList(id);	//	�Ӹ������ó��û�id��Ϊ��ѯ����
	//	��Ӧ���
	auto jvo = CalenderListJsonVO::createShared();

	jvo->success(result);

	return jvo;
}