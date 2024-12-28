#ifndef _ORGSTRUCT_DO_
#define _ORGSTRUCT_DO_
#include "../DoInclude.h"


/*
	 ���� : ��ɽ: CC_SYNTHESIZE �궨�����ڴ��� get �� set ����
			��ȡ��֯��Ա��Get Set ����
 */
class OrgStructDO
{
	//���get set���� ���� set ֵ
	CC_SYNTHESIZE(uint64_t, pageindex, PageIndex);
	CC_SYNTHESIZE(uint64_t, pagesize, PageSize);
	//����
	CC_SYNTHESIZE(std::string, xname, Xname);
	//����Ψһ��ʶ������
	CC_SYNTHESIZE(std::string, xdistinguishedName, XdistinguishedName);
	CC_SYNTHESIZE(std::string, xemployee, Xemployee);
	CC_SYNTHESIZE(std::string, xmail, Xmail);
	CC_SYNTHESIZE(std::string, xmobile, Xmobile);
	CC_SYNTHESIZE(std::string, xunique, Xunique);
	CC_SYNTHESIZE(std::string, xiconLdpi, XiconLdpi);
	CC_SYNTHESIZE(std::string, xid, Xid);
public:
	OrgStructDO() {
		pageindex = 0;
		pagesize = 0;
	}
};

#endif // !_ORGSTRUCT_DO_