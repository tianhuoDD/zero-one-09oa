#include "stdafx.h"
#include "CalenderService.h"
#include "../../dao/calendar/CalenderDAO.h"
#include "../../../lib-common/include/SimpleDateTimeFormat.h"
#include <regex>
#include "../lib-common/include/SnowFlake.h"


list<string> CalenderService::division(string waitDivision)
{
	list<string> divisionData;
	int waitDivisionLength = waitDivision.size();
	for (int indexOne = 0, indexTwo = 0; indexOne < waitDivisionLength; indexOne = indexTwo + 3)
	{
		int first = indexOne;
		indexOne = waitDivision.find("@", indexOne);
		indexTwo = waitDivision.find("@", indexOne + 1);
		//�жϴ�������к��Ƿ�Ϸ�
		if (-1 == indexOne || -1 == indexTwo)
		{
			divisionsuccess = -1;
			return divisionData;
		}
		string data = waitDivision.substr(first, indexTwo + 2 - first);
		divisionData.push_back(data);
	}
	divisionsuccess = 999;
	return divisionData;
}
uint64_t CalenderService::packaging(const CalenderInfoDTO::Wrapper& dto, CalenderDAO& dao, const string& loaddisName, const string& xid)
{
	int ans = 1;  //�ۼƲ����ķ���ֵ
	//����������б�  ���贫�ݵ�������xdistinguishedName�ֶ�
	list<string> divisionData = division(dto->xmanageablePersonList);

	//���ڷǷ����к�
	if (-1 == divisionsuccess)
		return divisionsuccess;

	//����������б��ȴ�����ɼ���Χ�����б�
	list<string> waitData = divisionData;

	//��װDO����
	cal_calendar_manageablepersonlistDO MPdata;
	MPdata.setCalenderId(xid);
	//��ӵ�˳��
	int personColumn = 0;
	for (string insertData : divisionData)
	{
		MPdata.setFiled(insertData);
		MPdata.setxOrderColumn(personColumn);
		personColumn++;
		ans = ans & dao.insert(MPdata);
	}
	//����������ӵ�ǰ��¼�����к�
	MPdata.setFiled(loaddisName);
	MPdata.setxOrderColumn(personColumn);
	ans = ans & dao.insert(MPdata);

	//����ɼ���Χ
	divisionData = division(dto->xview);

	//���ڷǷ����к�
	if (-1 == divisionsuccess)
		return divisionsuccess;

	cal_calendar_viewablepersonlistDO VPdata;
	cal_calendar_viewableunitlistDO VUdata;
	cal_calendar_viewablegrouplistDO VGdata;

	VPdata.setCalenderId(xid);
	VUdata.setCalenderId(xid);
	VGdata.setCalenderId(xid);

	//��ʼ��˳��
	personColumn = 0;
	int groupColumn = 0;
	int unitColumn = 0;
	for (string insertData : divisionData)
	{
		int datasize = insertData.size();

		switch (insertData[datasize - 1])
		{
		case 'P':   //��
			VPdata.setFiled(insertData);
			VPdata.setxOrderColumn(personColumn);
			personColumn++;
			ans = ans & dao.insert(VPdata);
			break;
		case 'U':   //��֯
			VUdata.setFiled(insertData);
			VUdata.setxOrderColumn(groupColumn);
			groupColumn++;
			ans = ans & dao.insert(VUdata);
			break;
		case 'G':   //Ⱥ��
			VGdata.setFiled(insertData);
			VGdata.setxOrderColumn(unitColumn);
			unitColumn++;
			ans = ans & dao.insert(VGdata);
			break;
		}
	}
	//�ɼ���Χ���˵��б�����ӹ�����
	for (string insertData : waitData)
	{
		VPdata.setFiled(insertData);
		VPdata.setxOrderColumn(personColumn);
		personColumn++;
		ans = ans & dao.insert(MPdata);
	}

	//�ɼ���Χ���˵��б�����ӵ�ǰ��¼�����к�
	VPdata.setFiled(loaddisName);
	VPdata.setxOrderColumn(personColumn);
	ans = ans & dao.insert(VPdata);

	//������½���Χ
	divisionData = division(dto->xpublish);

	//���ڷǷ����к�
	if (-1 == divisionsuccess)
		return divisionsuccess;

	cal_calendar_publishablepersonlistDO PPdata;
	cal_calendar_publishableunitlistDO PUdata;
	cal_calendar_publishablegrouplistDO PGdata;

	PPdata.setCalenderId(xid);
	PUdata.setCalenderId(xid);
	PGdata.setCalenderId(xid);

	//��ʼ��˳��
	personColumn = 0;
	groupColumn = 0;
	unitColumn = 0;
	for (string insertData : divisionData)
	{
		int datasize = insertData.size();

		switch (insertData[datasize - 1])
		{
		case 'P':   //��
			PPdata.setFiled(insertData);
			PPdata.setxOrderColumn(personColumn);
			personColumn++;
			ans = ans & dao.insert(PPdata);
			break;
		case 'U':   //��֯
			PUdata.setFiled(insertData);
			PUdata.setxOrderColumn(groupColumn);
			groupColumn++;
			ans = ans & dao.insert(PUdata);
			break;
		case 'G':   //Ⱥ��
			PGdata.setFiled(insertData);
			PGdata.setxOrderColumn(unitColumn);
			unitColumn++;
			ans = ans & dao.insert(PGdata);
			break;
		}
	}
	//���½���Χ���˵��б�����ӵ�ǰ��¼�����к�
	PPdata.setFiled(loaddisName);
	PPdata.setxOrderColumn(personColumn);
	personColumn++;
	ans = ans & dao.insert(PPdata);

	return ans;
}

uint64_t CalenderService::saveData(const CalenderInfoDTO::Wrapper& dto, const string& loaddisName)
{
	// ִ���������
	CalenderDAO dao;
	//�ж��Ƿ��Ѿ�����
	if (dao.executeCount("cal_calendar", dto->xid, "xid"))
		return 0;

	// ��װDO����
	cal_calendarDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, xColor, xcolor, xDescription, xdescription, xIsPublic, xisPublic,
		xName, xname, xStatus, xstatus, xTarget, xtarget, xType, xtype);

	//��ȡ����id
	SnowFlake snowflake(30, 30);
	string xid = to_string(snowflake.nextId());
	data.setxId(xid);

	//��ȡ�½��͸���ʱ��
	data.setxCreateTime(SimpleDateTimeFormat::format());
	data.setxUpdateTime(SimpleDateTimeFormat::format());

	//��װ������
	data.setxCreateor(loaddisName);

	//��װxsequence��xsource
	std::regex pattern("(\\d{4})-(\\d{2})-(\\d{2}) (\\d{2}):(\\d{2}):(\\d{2})");
	string xsequence = regex_replace(data.getxCreateTime(), pattern, "$1$2$3$4$5$6") + data.getxId();
	data.setxSequence(xsequence);
	data.setxSource("PERSON");

	//�ж���������
	if ("PERSON" == data.getxType())    //��������
	{
		return dao.insert(data);
	}
	else  //��֯����
	{
		int ans = dao.insert(data);
		int result = packaging(dto, dao, loaddisName, xid);
		if (-1 == result)
			return 88;
		return ans;
	}
}

uint64_t CalenderService::updateData(const CalenderInfoDTO::Wrapper& dto, const string& loaddisName)
{
	// ִ���������
	CalenderDAO dao;
	//�ж��Ƿ��Ѿ�����
	if (!dao.executeCount("cal_calendar", dto->xid, "xid"))
		return 0;

	// ��װDO����
	cal_calendarDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, xId, xid, xColor, xcolor, xDescription, xdescription, xIsPublic, xisPublic,
		xName, xname, xStatus, xstatus, xTarget, xtarget, xType, xtype)
	//��ȡ����ʱ��
	data.setxUpdateTime(SimpleDateTimeFormat::format());

	if ("PERSON" == data.getxType())  //��������
	{
		return dao.update(data) == 1;
	}
	else  //��֯����
	{
		//����������
		int ans = dao.update(data);
		//�������ݸ��ǣ���ɾ���������
		ans = ans & dao.deleteById(dto->xid, 0);
		int result = packaging(dto, dao, loaddisName, dto->xid);
		if (-1 == result)
			return 88;
		return ans;
	}
}

bool CalenderService::removeData(string xid)
{
	CalenderDAO dao;
	return dao.deleteById(xid) == 1;
}