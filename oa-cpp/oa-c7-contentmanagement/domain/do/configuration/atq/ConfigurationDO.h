#pragma once

#ifndef _CONFIGURATIONDO_
#define _CONFIGURATIONDO_
#include "../../DoInclude.h"

/**
 * 示例数据库实体类
 */
class ConfigurationDO
{
	//选择分类表单
	CC_SYNTHESIZE(string, xcreatorUnitName,XcreatorUnitName);
	//分类标识
	CC_SYNTHESIZE(string,  xappId, XappId);
	//分类别名
	CC_SYNTHESIZE(string, xalias, Xalias);
	//文档类型
	CC_SYNTHESIZE(string, xdocumentType, XdocumentType);
	//发布时是否发送消息
	CC_SYNTHESIZE(string, xsendNotify, XsendNotify);
	//使用流程
	CC_SYNTHESIZE(string, process, Process);
	//可见范围
	CC_SYNTHESIZE(string, range, Range);
	//发布者
	CC_SYNTHESIZE(string, xcreatorPerson, XcreatorPerson);
	//管理者
	CC_SYNTHESIZE(string, xmanagePerson, XmanagePerson);

	// 姓名
	CC_SYNTHESIZE(string, name, Name);
public:
	ConfigurationDO() {
		xcreatorUnitName = "";
		xappId = "";
		xalias = "";
		xdocumentType = "";
		xsendNotify = "";
		process = "";
		range = "";
		xcreatorPerson = "";
		xmanagePerson = "";
	}
};

#endif // !_SAMPLE_DO_
