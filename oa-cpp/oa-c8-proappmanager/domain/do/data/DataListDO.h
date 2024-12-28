#pragma once
#ifndef _DATALIST_DO_
#define _DATALIST_DO_
#include "../DoInclude.h"

/**
 * 列表数据库实体类
 */
class DataListDO
{
	
	// 数据唯一标识符
	CC_SYNTHESIZE(string, dataid, DataId);
	//应用程序
	CC_SYNTHESIZE(string, application, Application);
	// 配置项名称
	CC_SYNTHESIZE(string, name, Name);
	// 别名
	CC_SYNTHESIZE(string, alias, Alias);
	// 描述
	CC_SYNTHESIZE(string, description, Description);
	//创建时间
	CC_SYNTHESIZE(string, creatTime, CreatTime);
	//更新时间
	CC_SYNTHESIZE(string, updateTime, UpdateTime);
	
public:
	DataListDO() {
		dataid = "";
		application = "";
		name = "";
		alias = "";
		description = "";
		creatTime = "";
		updateTime = "";
	}
};

#endif // !_SAMPLE_DO_
