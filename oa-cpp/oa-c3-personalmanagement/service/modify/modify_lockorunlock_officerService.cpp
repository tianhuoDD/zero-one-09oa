#include "stdafx.h"
#include "modify_lockorunlock_officerService.h"
#include "dao/modify/modify_lockorunlock_officerDAO.h"
#include "domain/do/org_personDo/org_personDO.h"

bool modify_lockorunlock_officerService::updateData(const modify_lockorunlock_officerDTO::Wrapper& dto)
{
	// 组装DO数据
	org_personDO data;
	data.setXid(dto->xid.getValue(""));
	data.setXlockTime(dto->xlockTime.getValue("")); 
	data.setXstatusDes(dto->xstatusDes.getValue("")); 
	data.setXstatus(dto->xstatus.getValue(""));

	// 执行数据修改
	modify_lockorunlock_officerDAO dao;
	return dao.update(data) == 1;
}
