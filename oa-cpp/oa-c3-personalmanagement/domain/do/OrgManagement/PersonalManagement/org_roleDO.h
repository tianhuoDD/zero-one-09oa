#pragma once
#ifndef _ORG_ROLEDO_H_
#define _ORG_ROLEDO_H_
#include "../../DoInclude.h"

/**
 * 角色数据库实体类
 */
class org_roleDO
{
	//主码
	CC_SYNTHESIZE(string, xid, Xid);
	//创建时间
	CC_SYNTHESIZE(string, xcreateTime, XcreateTime);
	//
	CC_SYNTHESIZE(string, xsequence, Xsequence);
	//更新时间
	CC_SYNTHESIZE(string, xupdateTime, XupdateTime);
	//
	CC_SYNTHESIZE(int, xdistributeFactor, XdistributeFactor);
	// 描述
	CC_SYNTHESIZE(string, xdescription, Xdescription);
	// 角色全称
	CC_SYNTHESIZE(string, xdistinguishedName, XdistinguishedName);
	// 担任的角色名称
	CC_SYNTHESIZE(string, xname, Xname);
	//
	CC_SYNTHESIZE(int, xorderNumber, XorderNumber);
	//中文拼音
	CC_SYNTHESIZE(string, xpinyin, Xpinyin);
	//中文首字母拼音
	CC_SYNTHESIZE(string, xpinyinInitial, XpinyinInitial);
	//唯一标识
	CC_SYNTHESIZE(string, xunique, Xunique);


	
	
	
public:
	org_roleDO() {
		xid = "";
		xcreateTime = "";
		xsequence = "";
		xupdateTime = "";
		xdistributeFactor = 0;
		xdescription = "";
		xdistinguishedName = "";
		xname = "";
		xorderNumber = 0;
		xpinyin = "";
		xpinyinInitial = "";
		xunique = "";
	}
};

#endif // !_ORG_ROLEDO_H_
