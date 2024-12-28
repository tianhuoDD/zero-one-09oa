#pragma once
#ifndef _ORG_UNITDO_H_
#define _ORG_UNITDO_H_
#include "../../DoInclude.h"

/**
 * 职务数据库实体类
 */
class org_unitDO
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
	//
	CC_SYNTHESIZE(string, xandFxHash, XandFxHash);
	//
	CC_SYNTHESIZE(string, xandFxId, XandFxId);
	// 描述
	CC_SYNTHESIZE(string, xdescription, Xdescription);
	//钉钉哈希
	CC_SYNTHESIZE(string, xdingdingHash, XdingdingHash);
	//钉钉id
	CC_SYNTHESIZE(string, xdingdingId, XdingdingId);
	// 公司全称
	CC_SYNTHESIZE(string, xdistinguishedName, XdistinguishedName);
	// 公司级别
	CC_SYNTHESIZE(int, xlevel, Xlevel);
	// 公司按级别升序全称
	CC_SYNTHESIZE(string, xlevelName, XlevelName);
	// 
	CC_SYNTHESIZE(string, xlevelOrderNumber, XlevelOrderNumber);
	// 担任的角色名称
	CC_SYNTHESIZE(string, xname, Xname);
	//
	CC_SYNTHESIZE(int, xorderNumber, XorderNumber);
	//中文拼音
	CC_SYNTHESIZE(string, xpinyin, Xpinyin);
	//中文首字母拼音
	CC_SYNTHESIZE(string, xpinyinInitial, XpinyinInitial);
	//企业微信哈希
	CC_SYNTHESIZE(string, xqiyeweixinHash, XqiyeweixinHash);
	//企业微信id
	CC_SYNTHESIZE(string, xqiyeweixinId, XqiyeweixinId);
	//简称
	CC_SYNTHESIZE(string, xshortName, XshortName);
	//上级公司的xid
	CC_SYNTHESIZE(string, xsuperior, Xsuperior);
	//唯一标识
	CC_SYNTHESIZE(string, xunique, Xunique);
	//
	CC_SYNTHESIZE(string, xweLinkHash, XweLinkHash);
	//
	CC_SYNTHESIZE(string, xweLinkId, XweLinkId);
	//政务钉钉哈希
	CC_SYNTHESIZE(string, xzhengwuDingdingHash, XzhengwuDingdingHash);
	//政务钉钉id
	CC_SYNTHESIZE(string, xzhengwuDingdingId, XzhengwuDingdingId);
public:
	org_unitDO() {
		xid = "";
		xcreateTime = "";
		xsequence = "";
		xupdateTime = "";
		xdistributeFactor = 0;
		xandFxHash = "";
		xandFxId = "";
		xdescription = "";
		xdingdingHash = "";
		xdingdingId = "";
		xdistinguishedName = "";
		xlevel = 0;
		xlevelName = "";
		xlevelOrderNumber = "";
		xname = "";
		xorderNumber = 0;
		xpinyin = "";
		xpinyinInitial = "";
		xqiyeweixinHash = "";
		xqiyeweixinId = "";
		xshortName = "";
		xsuperior = "";
		xunique = "";
		xweLinkHash = "";
		xweLinkId = "";
		xzhengwuDingdingHash = "";
		xzhengwuDingdingId = "";
	}
};

#endif // !_ORG_UNITDO_H_
