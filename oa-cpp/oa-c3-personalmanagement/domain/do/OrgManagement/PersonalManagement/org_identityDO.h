#pragma once
#ifndef _ORG_IDENTITYDO_H_
#define _ORG_IDENTITYDO_H_
#include "../../DoInclude.h"

/**
 * 职工身份数据库实体类
 */
class org_identityDO
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
	// 职工全称
	CC_SYNTHESIZE(string, xdistinguishedName, XdistinguishedName);
	//
	CC_SYNTHESIZE(bool, xmajor, Xmajor);
	// 担任的角色名称
	CC_SYNTHESIZE(string, xname, Xname);
	//
	CC_SYNTHESIZE(int, xorderNumber, XorderNumber);
	//rog_person表的主键
	CC_SYNTHESIZE(string, xperson, Xperson);
	//中文拼音
	CC_SYNTHESIZE(string, xpinyin, Xpinyin);
	//中文首字母拼音
	CC_SYNTHESIZE(string, xpinyinInitial, XpinyinInitial);
	//唯一标识
	CC_SYNTHESIZE(string, xunique, Xunique);
	//所属公司的主键
	CC_SYNTHESIZE(string, xunit, Xunit);
	//所属公司的级别
	CC_SYNTHESIZE(int, xunitLevel, XunitLevel);
	//分公司全称
	CC_SYNTHESIZE(string, xunitLevelName, XunitLevelName);
	//总公司名称
	CC_SYNTHESIZE(string, xunitName, XunitName);
public:
	org_identityDO() {
		xid = "";
		xcreateTime = "";
		xsequence = "";
		xupdateTime = "";
		xdistributeFactor = 0;
		xdescription = "";
		xdistinguishedName = "";
		xmajor = false;
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

#endif // !_ORG_IDENTITYDO_H_
