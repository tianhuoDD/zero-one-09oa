#pragma once
#ifndef _CALENDER_SERVICE_
#define _CALENDER_SERVICE_
#include <list>
#include "../../domain/vo/calender/CalenderInfoVO.h"
#include "../../domain/dto/calender/CalenderInfoDTO.h"


class CalenderDAO;

class CalenderService
{
private:
	//判断分割是否全部成功  -1为传入数据有问题 
	int divisionsuccess = 999;
	// 分割数据
	list<string> division(string waitDivision);
	//组合可见范围，可新建范围数据
	uint64_t packaging(const CalenderInfoDTO::Wrapper& dto, CalenderDAO& dao, const string& loaddisName, const string& xid);

public:
	// 保存数据
	uint64_t saveData(const CalenderInfoDTO::Wrapper& dto, const string& loaddisName);
	// 修改数据
	uint64_t updateData(const CalenderInfoDTO::Wrapper& dto, const string& loaddisName);
	// 通过ID删除数据
	bool removeData(string xid);

};

#endif // !_CALENDER_SERVICE_