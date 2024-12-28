#include "stdafx.h"
#include "SystemInfoService.h"
#include "../../dao/SystemInfo/SystemInfoDAO.h"

bool SystemInfoService::modifySystemSubtitle(const SystemInfoDTO::Wrapper& dto)
{
	SysteminfoDAO dao;
	return dao.modifySystemSubtitle(dto) == 1;
}

bool SystemInfoService::modifySystemName(const SystemInfoDTO::Wrapper& dto)
{
	SysteminfoDAO dao;
	return dao.modifySystemName(dto) == 1;
}