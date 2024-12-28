#pragma once
/*
	//数据库表映射
	author：Niuniu
*/
#ifndef _FORM_DO_H_
#define _FORM_DO_H_
#include "../../DoInclude.h"

class FormDO {
	// 编号
	CC_SYNTHESIZE(string, xid, Id);
	//更新时间
	CC_SYNTHESIZE(string, xupdateTime, UpdateTime);
	//别名
	CC_SYNTHESIZE(string, xalias, Alias);
	//描述
	CC_SYNTHESIZE(string, xdescription, Description);
	//编辑者
	CC_SYNTHESIZE(string, xeditor, Editor);
	//表名
	CC_SYNTHESIZE(string, xname, FromName);
	//属性
	CC_SYNTHESIZE(string, xproperties, Properties);
public:
	FormDO() {
		xid = "xuehuasuanfa";
		xupdateTime = "";
		xalias = "FormTest";
		xdescription = "Use_Test";
		xeditor = "Niuniu";
		xname = "FormTest";
		xproperties = "i' don't know";
	}
};



#endif // !_FORM_DO_H_
