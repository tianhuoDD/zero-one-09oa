#pragma once

#ifndef _GETGROUPINFOSERVICE_H_
#define _GETGROUPINFOSERVICE_H_

#include "../../../domain/dto/get/GetGroupInfoDTO/GetGroupInfoDTO.h"
#include "../../../domain/vo/get/GetGroupInfo/GetGroupInfoVO.h"
#include "../../../dao/get/GetGroupInfo/GetGroupInfoDAO.h"


class GetGroupInfoService
{
public:
	// 查询群组信息
	//GetGroupInfoDTO::Wrapper listAll(const GetGroupInfoQuery::Wrapper& query);
	// 通过id查询群组信息
	GetGroupInfoVO::Wrapper getGroupInfoById(const string groupId);
	// 通过name查询群组信息
	GetGroupInfoVO::Wrapper getGroupInfoByName(const string groupName);
};

#endif // !_GETGROUPINFOSERVICE_H_