#pragma once
/*
 @Author: LemonFlavoredSoda
 @Date: 2024年 10月 23日 星期三 23:19:41 CST
*/
//org_identity
#ifndef _ORGIDENTITY_DO_
#define _ORGIDENTITY_DO_
#include "../../../Macros.h"

/**
 * 示例数据库实体类
 */
class OrgIdentityDO
{

	// 编号
	//CC_SYNTHESIZE(uint64_t, id, Id);

	//人员标识
	CC_SYNTHESIZE(string, xid, Xid);
	CC_SYNTHESIZE(string, xcreateTime, Xcreate_time);
	CC_SYNTHESIZE(string, xsequence, Xsequence);
	CC_SYNTHESIZE(string, xupdateTime, Xupdate_time);
	CC_SYNTHESIZE(int, xdistributeFactor, Xdistribute_factor);
	CC_SYNTHESIZE(string, xdescription, Xdescription);
	CC_SYNTHESIZE(string, xdistinguishedName, Xdistinguished_name);
	CC_SYNTHESIZE(int64_t, xmajor, Xmajor);
	//姓名
	CC_SYNTHESIZE(string, xname, Xname);
	CC_SYNTHESIZE(int, xorderNumber, Xorder_number);
	CC_SYNTHESIZE(string, xperson, Xperson);
	CC_SYNTHESIZE(string, xpinyin, Xpinyin);
	CC_SYNTHESIZE(string, xpinyinInitial, Xpinyin_initial);
	CC_SYNTHESIZE(string, xunique, Xunique);
	CC_SYNTHESIZE(string, xunit, Xunit);
	CC_SYNTHESIZE(int, xunitLevel, Xunit_level);
	//层级名称
	CC_SYNTHESIZE(string, xunitLevelName, Xunit_level_name);
	CC_SYNTHESIZE(string, xunitName, Xunit_name);
public:
	OrgIdentityDO() {
		xid = "";
		xcreateTime = "";
		xsequence = "";
		xupdateTime = "";
		xdistributeFactor = 0;
		xdescription = "";
		xdistinguishedName = "";
		xmajor = 0;
		xname = "";
		xorderNumber = 0;
		xperson = "";
		xpinyin = "";
		xpinyinInitial = "";
		xunique = "";
		xunit = "";
		xunitLevel = 0;
		xunitLevelName = "";
		xunitName = "";
	}
};

#endif // !_ORGIDENTITY_DO_
