#pragma once
#ifndef _ORGUNIT_DO_
#define _ORGUNIT_DO_
#include "DoInclude.h"


class OrgUnitDO
{
	//org_unit����; ��֯id; xid; varchar
	CC_SYNTHESIZE(string, xid, Xid);
	//org_unit����; ��֯����; unit_xname; varchar
	CC_SYNTHESIZE(string, unit_xname, Unit_xname);
	//org_unit����; Ψһ����; xunique; varchar
	CC_SYNTHESIZE(string, xunique, Xunique);
	//org_unit_typelist����; ��֯���; xtypeList; varchar
	CC_SYNTHESIZE(string, xtypeList, XtypeList);
	//org_unit����; ��֯���; xshortName; varchar
	CC_SYNTHESIZE(string, xshortName, XshortName);
	//org_unit����; ��֯����; xdescription; varchar
	CC_SYNTHESIZE(string, xdescription, Xdescription);
	//org_person����; ������; person_xname; varchar
	CC_SYNTHESIZE(string, person_xname, Person_xname);
	//org_unit����; �ϼ���֯; xsuperior; varchar
	CC_SYNTHESIZE(string, xsuperior, Xsuperior);
	//org_unit����; ����ֵ; xorderNumber; int
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
