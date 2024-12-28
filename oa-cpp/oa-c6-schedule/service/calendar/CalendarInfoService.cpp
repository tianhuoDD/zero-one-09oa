#include "stdafx.h"
#include "CalendarInfoService.h"
#include "../../dao/calendar/CalendarInfoDAO.h"

string CalendarInfoService::getName(const string& xdistinguishedname) {

	string result;
	int length = xdistinguishedname.size();
	int first = 0;
	int second = xdistinguishedname.find("@");
	result = xdistinguishedname.substr(first, second);
	return result;
}

uint64_t CalendarInfoService::packaging() {


	return {};
}


CalenderInfoDTO::Wrapper CalendarInfoService::queryCalendarInfo(const string& cal_xid) {

	//	�������ض���
	auto dto = CalenderInfoDTO::createShared();

	
	//	��ѯ����
	CalendarInfoDAO dao;
	list<cal_calendarDO> basicInfo_do = dao.selectCalendarInfoById(cal_xid);
	list<cal_calendar_manageablepersonlistDO> managerInfo_do = dao.selectManageablePersonById(cal_xid);
	list<cal_calendar_publishablegrouplistDO> publishGroup_do = dao.selectPublishableGroupById(cal_xid);
	list<cal_calendar_publishablepersonlistDO> publishPerson_do = dao.selectPublishablePersonById(cal_xid);
	list<cal_calendar_publishableunitlistDO> publishUnit_do = dao.selectPublishableUnitById(cal_xid);
	list<cal_calendar_viewablegrouplistDO> viewGroup_do = dao.selectViewableGroupById(cal_xid);
	list<cal_calendar_viewablepersonlistDO> viewPerson_do = dao.selectViewablePersonById(cal_xid);
	list<cal_calendar_viewableunitlistDO> viewUnit_do = dao.selectViewableUnitById(cal_xid);

	//	��DOת��ΪDTO
	stringstream able;	//	�������ܷ�Χ��string��

	//	�������id
	dto->xid = cal_xid;


	//	��������
	for (cal_calendar_manageablepersonlistDO one : managerInfo_do) {
		able << getName(one.getFiled()) << " ";
	}
	dto->xmanageablePersonList = able.str();
	able.str("");

	//	�����½���Χ
	for (cal_calendar_publishablegrouplistDO one : publishGroup_do) {
		able << getName(one.getFiled()) << " ";
	}
	for (cal_calendar_publishablepersonlistDO one : publishPerson_do) {
		able << getName(one.getFiled()) << " ";
	}
	for (cal_calendar_publishableunitlistDO one : publishUnit_do) {
		able << getName(one.getFiled()) << " ";
	}
	dto->xpublish = able.str();
	able.str("");

	//	���ɼ���Χ
	for (cal_calendar_viewablegrouplistDO one : viewGroup_do) {
		able << getName(one.getFiled()) << " ";
	}
	for (cal_calendar_viewablepersonlistDO one : viewPerson_do) {
		able << getName(one.getFiled()) << " ";
	}
	for (cal_calendar_viewableunitlistDO one : viewUnit_do) {
		able << getName(one.getFiled()) << " ";
	}
	dto->xview = able.str();
	able.str("");

	//	�������������Ϣ
	for (cal_calendarDO one : basicInfo_do) {
		
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, one, xname, xName, xcolor, xColor, xisPublic, xIsPublic, xstatus, xStatus, 
			xdescription,xDescription, xtype, xType);
		dto->xtarget = getName(one.getxTarget());
	}

	return dto;
	

}
