#include "stdafx.h"
#include "DutySettingService.h"
#include "dao/OrgManagement/PersonalManagement/DutySettingDAO.h"

int DutySettingService::DutySetting(const DutySettingDTO::Wrapper& dto)
{
	list<org_unitduty_identitylistDO> data;
	//for(auto& it=dto->unitduty_xid->begin())
	for (oatpp::String it : *(dto->unitduty_xid)) {
		org_unitduty_identitylistDO temp;
		temp.setUNITDUTY_XID(it.getValue(""));
		temp.setXidentityList(dto->xidentity.getValue(""));
		temp.setXorderColumn(0);
		data.push_back(temp);
	}
	DutySettingDAO dao;
	dao.deleteByIdentity(dto);
	return dao.insert(data);
}
