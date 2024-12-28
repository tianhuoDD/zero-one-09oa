#ifndef _ORGSTRUCT_DO_
#define _ORGSTRUCT_DO_
#include "../DoInclude.h"


/*
	 功能 : 书山: CC_SYNTHESIZE 宏定义用于创建 get 与 set 方法
			获取组织成员的Get Set 方法
 */
class OrgStructDO
{
	//获得get set方法 用于 set 值
	CC_SYNTHESIZE(uint64_t, pageindex, PageIndex);
	CC_SYNTHESIZE(uint64_t, pagesize, PageSize);
	//姓名
	CC_SYNTHESIZE(std::string, xname, Xname);
	//带有唯一标识的姓名
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