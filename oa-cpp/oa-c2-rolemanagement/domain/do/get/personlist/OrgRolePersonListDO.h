#ifndef _ORG_ROLE_PERSON_LIST_DO_
#define _ORG_ROLE_PERSON_LIST_DO_
#include "../../DoInclude.h"

/**
 * 示例数据库实体类
 */
class OrgRolePersonListDO
{
	//CC_SYNTHESIZE(string, role_xid, Role_Xid);
	//CC_SYNTHESIZE(string,xpersonlist, XPersonList);
	//CC_SYNTHESIZE(uint64_t, xordercolumn, XOrderColumn);
	//名字
	CC_SYNTHESIZE(string, xname, XName);
	//工号
	CC_SYNTHESIZE(string, xemployee, XEmployee);
	//电话
	CC_SYNTHESIZE(string, xmobile, XMobile);
	//邮箱
	CC_SYNTHESIZE(string, xmail, XMail);

	CC_SYNTHESIZE(string, xid, Xid);
public:
	OrgRolePersonListDO() : xname(""), xemployee(""), xmobile(""), xmail(""),xid(""){}
};

#endif // !_ORG_ROLE_PERSON_LIST_DO_