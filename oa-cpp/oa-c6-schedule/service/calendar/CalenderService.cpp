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
		//判断传入的序列号是否合法
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
	int ans = 1;  //累计操作的返回值
	//处理管理者列表  假设传递的数据是xdistinguishedName字段
	list<string> divisionData = division(dto->xmanageablePersonList);

	//存在非法序列号
	if (-1 == divisionsuccess)
		return divisionsuccess;

	//保存管理者列表，等待加入可见范围的人列表
	list<string> waitData = divisionData;

	//组装DO数据
	cal_calendar_manageablepersonlistDO MPdata;
	MPdata.setCalenderId(xid);
	//添加的顺序
	int personColumn = 0;
	for (string insertData : divisionData)
	{
		MPdata.setFiled(insertData);
		MPdata.setxOrderColumn(personColumn);
		personColumn++;
		ans = ans & dao.insert(MPdata);
	}
	//管理者中添加当前登录的序列号
	MPdata.setFiled(loaddisName);
	MPdata.setxOrderColumn(personColumn);
	ans = ans & dao.insert(MPdata);

	//处理可见范围
	divisionData = division(dto->xview);

	//存在非法序列号
	if (-1 == divisionsuccess)
		return divisionsuccess;

	cal_calendar_viewablepersonlistDO VPdata;
	cal_calendar_viewableunitlistDO VUdata;
	cal_calendar_viewablegrouplistDO VGdata;

	VPdata.setCalenderId(xid);
	VUdata.setCalenderId(xid);
	VGdata.setCalenderId(xid);

	//初始化顺序
	personColumn = 0;
	int groupColumn = 0;
	int unitColumn = 0;
	for (string insertData : divisionData)
	{
		int datasize = insertData.size();

		switch (insertData[datasize - 1])
		{
		case 'P':   //人
			VPdata.setFiled(insertData);
			VPdata.setxOrderColumn(personColumn);
			personColumn++;
			ans = ans & dao.insert(VPdata);
			break;
		case 'U':   //组织
			VUdata.setFiled(insertData);
			VUdata.setxOrderColumn(groupColumn);
			groupColumn++;
			ans = ans & dao.insert(VUdata);
			break;
		case 'G':   //群组
			VGdata.setFiled(insertData);
			VGdata.setxOrderColumn(unitColumn);
			unitColumn++;
			ans = ans & dao.insert(VGdata);
			break;
		}
	}
	//可见范围的人的列表中添加管理者
	for (string insertData : waitData)
	{
		VPdata.setFiled(insertData);
		VPdata.setxOrderColumn(personColumn);
		personColumn++;
		ans = ans & dao.insert(MPdata);
	}

	//可见范围的人的列表中添加当前登录的序列号
	VPdata.setFiled(loaddisName);
	VPdata.setxOrderColumn(personColumn);
	ans = ans & dao.insert(VPdata);

	//处理可新建范围
	divisionData = division(dto->xpublish);

	//存在非法序列号
	if (-1 == divisionsuccess)
		return divisionsuccess;

	cal_calendar_publishablepersonlistDO PPdata;
	cal_calendar_publishableunitlistDO PUdata;
	cal_calendar_publishablegrouplistDO PGdata;

	PPdata.setCalenderId(xid);
	PUdata.setCalenderId(xid);
	PGdata.setCalenderId(xid);

	//初始化顺序
	personColumn = 0;
	groupColumn = 0;
	unitColumn = 0;
	for (string insertData : divisionData)
	{
		int datasize = insertData.size();

		switch (insertData[datasize - 1])
		{
		case 'P':   //人
			PPdata.setFiled(insertData);
			PPdata.setxOrderColumn(personColumn);
			personColumn++;
			ans = ans & dao.insert(PPdata);
			break;
		case 'U':   //组织
			PUdata.setFiled(insertData);
			PUdata.setxOrderColumn(groupColumn);
			groupColumn++;
			ans = ans & dao.insert(PUdata);
			break;
		case 'G':   //群组
			PGdata.setFiled(insertData);
			PGdata.setxOrderColumn(unitColumn);
			unitColumn++;
			ans = ans & dao.insert(PGdata);
			break;
		}
	}
	//可新建范围的人的列表中添加当前登录的序列号
	PPdata.setFiled(loaddisName);
	PPdata.setxOrderColumn(personColumn);
	personColumn++;
	ans = ans & dao.insert(PPdata);

	return ans;
}

uint64_t CalenderService::saveData(const CalenderInfoDTO::Wrapper& dto, const string& loaddisName)
{
	// 执行数据添加
	CalenderDAO dao;
	//判断是否已经插入
	if (dao.executeCount("cal_calendar", dto->xid, "xid"))
		return 0;

	// 组装DO数据
	cal_calendarDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, xColor, xcolor, xDescription, xdescription, xIsPublic, xisPublic,
		xName, xname, xStatus, xstatus, xTarget, xtarget, xType, xtype);

	//获取日历id
	SnowFlake snowflake(30, 30);
	string xid = to_string(snowflake.nextId());
	data.setxId(xid);

	//获取新建和更新时间
	data.setxCreateTime(SimpleDateTimeFormat::format());
	data.setxUpdateTime(SimpleDateTimeFormat::format());

	//组装创建者
	data.setxCreateor(loaddisName);

	//组装xsequence和xsource
	std::regex pattern("(\\d{4})-(\\d{2})-(\\d{2}) (\\d{2}):(\\d{2}):(\\d{2})");
	string xsequence = regex_replace(data.getxCreateTime(), pattern, "$1$2$3$4$5$6") + data.getxId();
	data.setxSequence(xsequence);
	data.setxSource("PERSON");

	//判断日历类型
	if ("PERSON" == data.getxType())    //个人日历
	{
		return dao.insert(data);
	}
	else  //组织日历
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
	// 执行数据添加
	CalenderDAO dao;
	//判断是否已经存在
	if (!dao.executeCount("cal_calendar", dto->xid, "xid"))
		return 0;

	// 组装DO数据
	cal_calendarDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, xId, xid, xColor, xcolor, xDescription, xdescription, xIsPublic, xisPublic,
		xName, xname, xStatus, xstatus, xTarget, xtarget, xType, xtype)
	//获取更改时间
	data.setxUpdateTime(SimpleDateTimeFormat::format());

	if ("PERSON" == data.getxType())  //个人日历
	{
		return dao.update(data) == 1;
	}
	else  //组织日历
	{
		//更新主数据
		int ans = dao.update(data);
		//进行数据覆盖，先删除，再添加
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