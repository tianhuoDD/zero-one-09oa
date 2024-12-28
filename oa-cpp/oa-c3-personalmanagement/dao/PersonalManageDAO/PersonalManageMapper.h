#ifndef PERSONALMANAGEMAPPER
#define PERSONALMANAGEMAPPER
#include "Mapper.h"
//#include "../../domain/do/PersonalManageDO/PersonalManageDO.h"
#include "../../domain/do/org_personDo/org_personDO.h"

class PersonalManageMapper : public Mapper<org_personDO>{
public:
	org_personDO mapper(ResultSet* res) const override {
		org_personDO data;
		data.setXunique(res->getString("xunique"));
		data.setXname(res->getString("xname"));
		data.setXmobile(res->getString("xmobile"));
		data.setXofficePhone(res->getString("xofficePhone"));
		data.setXgenderType(res->getString("xgenderType"));
		data.setXmail(res->getString("xmail"));
		data.setXqq(res->getString("xqq"));
		data.setXweixin(res->getString("xweixin"));
		data.setXboardDate(res->getString("xboardDate"));
		data.setXipAddress(res->getString("xipAddress"));
		data.setXsubjectSecurityClearance(res->getUInt64("xsubjectSecurityClearance"));
		data.setXemployee(res->getString("xemployee"));
		data.setXbirthday(res->getString("xbirthday"));
		data.setXdescription(res->getString("xdescription"));
		data.setXstatus(res->getString("xstatus"));
		data.setXsuperior(res->getString("xsuperior"));
		data.setXid(res->getString("xid"));
		return data;
}
};

#endif