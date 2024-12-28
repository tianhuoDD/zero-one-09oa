#ifndef _ORG_ROLE_DO_
#define _ORG_ROLE_DO_
#include "../../DoInclude.h"
#include"ctime"

/**
 * 示例数据库实体类
 */
class OrgRoleDO
{
	//数据库数据,有些数据用不上，但还是留着吧
	CC_SYNTHESIZE(string, xid, Xid);
	CC_SYNTHESIZE(string, xcreateTime, XCreateTime);
	CC_SYNTHESIZE(string, xsequence, XSequence);
	CC_SYNTHESIZE(string, xupdateTime, XUpdateTime);
	CC_SYNTHESIZE(string, xdistributeFactor, XDistributeFactor);
	CC_SYNTHESIZE(string, xdescription, XDescription);
	CC_SYNTHESIZE(string, xdistinguishedName, XDistinguishedName);
	CC_SYNTHESIZE(string, xname, XName);
	CC_SYNTHESIZE(uint64_t,xorderNumber, XorderNumber);
	CC_SYNTHESIZE(string, xpinyin, XPinYin);
	CC_SYNTHESIZE(string, xpinyinInitail, XPinYinInitail);
	CC_SYNTHESIZE(string, xunique, XUnique);

	//自己设的数据
	CC_SYNTHESIZE(string, last_xunique, LastXUnique);
public:
	OrgRoleDO() :
		xid(""), xcreateTime(""), xsequence(""), xupdateTime(""),
		xdistributeFactor(""), xdescription(""), xdistinguishedName(""), xname(""),
		xorderNumber(-1), xpinyin(""), xpinyinInitail(""), xunique(""),
		last_xunique("") {}
};

#endif // !_ORG_ROLE_DO_
