#pragma once
#ifndef _FORM_DO_
#define _FORM_DO_
#include "../DoInclude.h"

/**
 * 流程表单数据库实体类
 */
class FormDO {
	// 表单标识
	CC_SYNTHESIZE(string, xid, Id);
	// 创建时间
	CC_SYNTHESIZE(string, xcreateTime, CreateTime);
	// 序列
	CC_SYNTHESIZE(string, xsequence, Sequence);
	// 更新时间
	CC_SYNTHESIZE(string, xupdateTime, UpdateTime);
	// 分布式因子（distributeFactor）？
	CC_SYNTHESIZE(string, xdistributeFactor, DistributeFactor);
	// 别名
	CC_SYNTHESIZE(string, xalias, Alias);
	// 应用标识
	CC_SYNTHESIZE(string, xapplication, Application);
	// 类别
	CC_SYNTHESIZE(string, xcategory, Category);
	// 数据
	CC_SYNTHESIZE(string, xdata, Data);
	// 描述
	CC_SYNTHESIZE(string, xdescription, Description);
	// 是否支持移动端（1不支持，0支持）？
	CC_SYNTHESIZE(bool, xhasMobile, HasMobile);
	// 图标
	CC_SYNTHESIZE(string, xicon, Icon);
	// 上一次更新用户
	CC_SYNTHESIZE(string, xlastUpdatePerson, LastUpdatePerson);
	// 上一次更新时间
	CC_SYNTHESIZE(string, xlastUpdateTime, LastUpdateTime);
	// 移动端数据
	CC_SYNTHESIZE(string, xmobileData, MobileData);
	// 名称
	CC_SYNTHESIZE(string, xname, Name);
	// 属性
	CC_SYNTHESIZE(string, xproperties, Properties);
	// 该类型对应数量（添加）
	CC_SYNTHESIZE(int, xnum, Num);
	// 创建表版本备份添加-表单id
	CC_SYNTHESIZE(string, xform, Form);
	// 创建表版本备份添加-修改人
	CC_SYNTHESIZE(string, xperson, Person);
};

#endif // !_FORM_DO_
