#pragma once
#ifndef _ORGUNIT_DO_
#define _ORGUNIT_DO_
#include "DoInclude.h"


class OrgUnitDO
{
	//org_unit表下; 组织id; xid; varchar
	CC_SYNTHESIZE(string, xid, Xid);
	//org_unit表下; 组织名称; unit_xname; varchar
	CC_SYNTHESIZE(string, unit_xname, Unit_xname);
	//org_unit表下; 唯一编码; xunique; varchar
	CC_SYNTHESIZE(string, xunique, Xunique);
	//org_unit_typelist表下; 组织类别; xtypeList; varchar
	CC_SYNTHESIZE(string, xtypeList, XtypeList);
	//org_unit表下; 组织简称; xshortName; varchar
	CC_SYNTHESIZE(string, xshortName, XshortName);
	//org_unit表下; 组织描述; xdescription; varchar
	CC_SYNTHESIZE(string, xdescription, Xdescription);
	//org_person表下; 管理者; person_xname; varchar
	CC_SYNTHESIZE(string, person_xname, Person_xname);
	//org_unit表下; 上级组织; xsuperior; varchar
	CC_SYNTHESIZE(string, xsuperior, Xsuperior);
	//org_unit表下; 排序值; xorderNumber; int
	CC_SYNTHESIZE(uint64_t, xorderNumber, XorderNumber);
public:
	OrgUnitDO() {
		xid = "";
		unit_xname = "";
		xunique = "";
		xtypeList = "";
		xshortName = "";
		xdescription = "";
		person_xname = "";
		xsuperior = "";
		xorderNumber = -1;
	}
};

#endif // !_ORGUNIT_DO_
