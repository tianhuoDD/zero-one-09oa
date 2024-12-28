#pragma once

#ifndef _GETGROUPINFOSERVICE_H_
#define _GETGROUPINFOSERVICE_H_

#include "../../../domain/dto/get/GetGroupInfoDTO/GetGroupInfoDTO.h"
#include "../../../domain/vo/get/GetGroupInfo/GetGroupInfoVO.h"
#include "../../../dao/get/GetGroupInfo/GetGroupInfoDAO.h"


class GetGroupInfoService
{
public:
	// ��ѯȺ����Ϣ
	//GetGroupInfoDTO::Wrapper listAll(const GetGroupInfoQuery::Wrapper& query);
	// ͨ��id��ѯȺ����Ϣ
	GetGroupInfoVO::Wrapper getGroupInfoById(const string groupId);
	// ͨ��name��ѯȺ����Ϣ
	GetGroupInfoVO::Wrapper getGroupInfoByName(const string groupName);
};

#endif // !_GETGROUPINFOSERVICE_H_