#ifndef _ORG_ROLE_PERSON_LIST_DO_
#define _ORG_ROLE_PERSON_LIST_DO_
#include "../../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class OrgRolePersonListDO
{
	//CC_SYNTHESIZE(string, role_xid, Role_Xid);
	//CC_SYNTHESIZE(string,xpersonlist, XPersonList);
	//CC_SYNTHESIZE(uint64_t, xordercolumn, XOrderColumn);
	//����
	CC_SYNTHESIZE(string, xname, XName);
	//����
	CC_SYNTHESIZE(string, xemployee, XEmployee);
	//�绰
	CC_SYNTHESIZE(string, xmobile, XMobile);
	//����
	CC_SYNTHESIZE(string, xmail, XMail);

	CC_SYNTHESIZE(string, xid, Xid);
public:
	OrgRolePersonListDO() : xname(""), xemployee(""), xmobile(""), xmail(""),xid(""){}
};

#endif // !_ORG_ROLE_PERSON_LIST_DO_