#include "stdafx.h"
#include "AcReService.h"
#include "../../dao/acceptrefuse/AcReDAO.h"

uint64_t AcReService::saveDataAccept(const string& meetingId, const string& userId)
{
	
	//// ��װDO����
	//SampleDO data;
	///*data.setName(dto->name.getValue(""));
	//data.setSex(dto->sex.getValue(""));
	//data.setAge(dto->age.getValue(1));*/
	//ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name, Sex, sex, Age, age)
		// ִ���������
	AcReDAO dao;
	return dao.insertAccept(meetingId,userId);

}

uint64_t AcReService::saveDataRefuse(const string& meetingId, const string& userId)
{
	//// ��װDO����
	//SampleDO data;
	///*data.setName(dto->name.getValue(""));
	//data.setSex(dto->sex.getValue(""));
	//data.setAge(dto->age.getValue(1));*/
	//ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name, Sex, sex, Age, age)
		// ִ���������
		AcReDAO dao;
	return dao.insertRefuse(meetingId, userId);
}
