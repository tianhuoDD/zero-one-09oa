#ifndef _ORG_ROLE_DO_
#define _ORG_ROLE_DO_
#include "../../DoInclude.h"
#include"ctime"

/**
 * ʾ�����ݿ�ʵ����
 */
class OrgRoleDO
{
	//���ݿ�����,��Щ�����ò��ϣ����������Ű�
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

	//�Լ��������
	CC_SYNTHESIZE(string, last_xunique, LastXUnique);
public:
	OrgRoleDO() :
		xid(""), xcreateTime(""), xsequence(""), xupdateTime(""),
		xdistributeFactor(""), xdescription(""), xdistinguishedName(""), xname(""),
		xorderNumber(-1), xpinyin(""), xpinyinInitail(""), xunique(""),
		last_xunique("") {}
};

#endif // !_ORG_ROLE_DO_
