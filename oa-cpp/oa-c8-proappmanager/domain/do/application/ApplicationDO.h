#ifndef _APPLICATIONDO_H_
#define _APPLICATIONDO_H_
#include "../DoInclude.h"

class ApplicationDO {
	//应用名称
	CC_SYNTHESIZE(string, xname, Name);
	//应用别名
	CC_SYNTHESIZE(string, xalias, Alias);
	//应用类型
	CC_SYNTHESIZE(string, xapplicationCategory, ApplicationCategory);
	//应用描述
	CC_SYNTHESIZE(string, xdescription, Description);
	CC_SYNTHESIZE(string, xid, Id);
	CC_SYNTHESIZE(string, xcreateTime, CreateTime);
	CC_SYNTHESIZE(string, xsequence, Sequence);
	CC_SYNTHESIZE(string, xupdateTime, UpdateTime);
	CC_SYNTHESIZE(int32_t, xdistributeFactor, DistributeFactor);
	CC_SYNTHESIZE(string, xcreatorPerson, CreatorPerson);
	CC_SYNTHESIZE(string, xlastUpdatePerson, LastUpdatePerson);
	CC_SYNTHESIZE(string, xlastUpdateTime, LastUpdateTime);
	CC_SYNTHESIZE(string, xproperties, Properties);
	CC_SYNTHESIZE(string, xicon, Icon);
	CC_SYNTHESIZE(string, xiconHue, IconHue);
public:
	ApplicationDO() {
		xname = "";
		xalias = "";
		xdescription = "";
		xapplicationCategory = "";
		xid = "";
		xcreateTime = "";
		xsequence = "";
		xupdateTime = "";
		xdistributeFactor = 0;
		xcreatorPerson = "";
		xlastUpdatePerson = "";
		xlastUpdateTime = "";
		xproperties = "";
		xicon = "";
		xiconHue = "";
	}
};

#endif // !_APPLICATIONDO_H_