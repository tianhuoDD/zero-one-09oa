#pragma once
#ifndef _ORG_DO_
#define _ORG_DO_
#include "../../do/DoInclude.h"

class CreateOrgDO
{
	//组织名称
	CC_SYNTHESIZE(string, xname, Xname);
	//唯一编码
	CC_SYNTHESIZE(string, xunique, Xunique);
	//组织类别
	//CC_SYNTHESIZE(list<string>, xtypeList, XtypeList);
	CC_SYNTHESIZE(string, xtypeList, XtypeList);
	//组织简称
	CC_SYNTHESIZE(string, xshortName, XshortName);
	//组织描述
	CC_SYNTHESIZE(string, xdescription, Xdescription);
	//组织全称
	CC_SYNTHESIZE(string, xdistinguishedName, XdistinguishedName);
	//组织层级
	CC_SYNTHESIZE(int, xlevel, Xlevel);
	//组织层级名
	CC_SYNTHESIZE(string, xlevelName, XlevelName);
	//管理者
	CC_SYNTHESIZE(list<string>, xcontrollerList, XcontrollerList);
	//上级组织
	CC_SYNTHESIZE(string, xsuperior, Xsuperior);
	//排序值
	CC_SYNTHESIZE(int, xorderNumber, XorderNumber);
	//组织名称拼音
	CC_SYNTHESIZE(string, xpinyin, Xpinyin);
	//组织名称拼音的首字母
	CC_SYNTHESIZE(string, xpinyinInitial, XpinyinInitial);
public:
	CreateOrgDO()
	{
		xlevel = 1;
		xname = "";
		xunique = "";
		//xtypeList = { "" };
		xtypeList = "";
		xshortName = "";
		xdescription = "";
		xcontrollerList = { "" };
		xsuperior = "";
		xorderNumber = 1;
		xpinyin = "";
		xpinyinInitial = "";
	}
};

class DeleteOrgDO
{
	// 要删除的组织唯一编码列表
	CC_SYNTHESIZE(string, xid, Xid);
public:
	DeleteOrgDO()
	{
		xid = "";
	}
};


#endif // !_ORG_DO_