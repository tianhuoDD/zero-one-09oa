#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:52:32

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _ITEM_DO_
#define _ITEM_DO_
#include "../DoInclude.h"

/**
 * 对应数据库cms_appdictitem表
 */
class ItemDO
{
	/*`xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
	`xcreateTime` datetime NULL DEFAULT NULL,
	`xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
	`xupdateTime` datetime NULL DEFAULT NULL,
	`xdistributeFactor` int NULL DEFAULT NULL,
	`xappId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
	`xbooleanValue` bit(1) NULL DEFAULT NULL,
	`xbundle` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
	`xdateTimeValue` datetime NULL DEFAULT NULL,
	`xdateValue` date NULL DEFAULT NULL,
	`xitemCategory` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
	`xitemPrimitiveType` varchar(1) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
	`xitemStringValueType` varchar(2) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
	`xitemType` varchar(1) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
	`xnumberValue` double NULL DEFAULT NULL,
	`xpath0` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
	`xpath0Location` int NULL DEFAULT NULL,
	`xpath1` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
	`xpath1Location` int NULL DEFAULT NULL,
	`xpath2` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
	`xpath2Location` int NULL DEFAULT NULL,
	`xpath3` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
	`xpath3Location` int NULL DEFAULT NULL,
	`xpath4` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
	`xpath4Location` int NULL DEFAULT NULL,
	`xpath5` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
	`xpath5Location` int NULL DEFAULT NULL,
	`xpath6` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
	`xpath6Location` int NULL DEFAULT NULL,
	`xpath7` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
	`xpath7Location` int NULL DEFAULT NULL,
	`xstringLongValue` longtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
	`xstringShortValue` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
	`xtimeValue` time NULL DEFAULT NULL,*/
	// 项目id
	CC_SYNTHESIZE(string, xid, Xid);
	// 项目创建时间
	CC_SYNTHESIZE(string, xcreateTime, XcreateTime);
	// 项目xsequence（项目创建时间+项目id）
	CC_SYNTHESIZE(string, xsequence, Xsequence);
	// 项目更新时间
	CC_SYNTHESIZE(string, xupdateTime, XupdateTime);
	// xdistributeFactor
	CC_SYNTHESIZE(int, xdistributeFactor, XdistributeFactor);
	// xappId
	CC_SYNTHESIZE(string, xappId, XappId);
	// 布尔值
	CC_SYNTHESIZE(bool, xbooleanValue, XbooleanValue);
	// 所属字典id
	CC_SYNTHESIZE(string, xbundle, Xbundle);
	// 项目datetime值
	CC_SYNTHESIZE(string, xdateTimeValue, XdateTimeValue);
	// 项目date值
	CC_SYNTHESIZE(string, xdateValue, XdateValue);
	// pp_dict
	CC_SYNTHESIZE(string, xitemCategory, XitemCategory);
	// 项目原始类型
	CC_SYNTHESIZE(string, xitemPrimitiveType, XitemPrimitiveType);
	// 项目字符串值类型
	CC_SYNTHESIZE(string, xitemStringValueType, XitemStringValueType);
	// 项目类型
	CC_SYNTHESIZE(string, xitemType, XitemType);
	// 项目数值类型值
	CC_SYNTHESIZE(double, xnumberValue, XnumberValue);
	// xpath0
	CC_SYNTHESIZE(string, xpath0, Xpath0);
	// Xpath0LocationId号
	CC_SYNTHESIZE(string, xpath0Location, Xpath0Location);
	// xpath1
	CC_SYNTHESIZE(string, xpath1, Xpath1);
	// xpath1Location
	CC_SYNTHESIZE(string, xpath1Location, Xpath1Location);
	// xpath2
	CC_SYNTHESIZE(string, xpath2, Xpath2);
	// xpath2Location
	CC_SYNTHESIZE(string, xpath2Location, Xpath2Location);
	// xpath3
	CC_SYNTHESIZE(string, xpath3, Xpath3);
	// xpath3Location
	CC_SYNTHESIZE(string, xpath3Location, Xpath3Location);
	// xpath4
	CC_SYNTHESIZE(string, xpath4, Xpath4);
	// xpath4Location
	CC_SYNTHESIZE(string, xpath4Location, Xpath4Location);
	// xpath5
	CC_SYNTHESIZE(string, xpath5, Xpath5);
	// xpath5Location
	CC_SYNTHESIZE(string, xpath5Location, Xpath5Location);
	// xpath6
	CC_SYNTHESIZE(string, xpath6, Xpath6);
	// xpath6Location
	CC_SYNTHESIZE(string, xpath6Location, Xpath6Location);
	// xpath7
	CC_SYNTHESIZE(string, xpath7, Xpath7);
	// xpath7Location
	CC_SYNTHESIZE(string, xpath7Location, Xpath7Location);
	// 长字符型值
	CC_SYNTHESIZE(string, xstringLongValue, XstringLongValue);
	// 短字符型值
	CC_SYNTHESIZE(string, xstringShortValue, XstringShortValue);
	// 时间值
	CC_SYNTHESIZE(string, xtimeValue, XtimeValue);
	
public:
	ItemDO() {
		xid = "";
		xcreateTime = "";
		xsequence = "";
		xupdateTime = "";
		xdistributeFactor = 0;
		xappId = "";
		xbooleanValue = 0;
		xbundle = "";
		xdateTimeValue = "";
		xdateValue = "";
		xitemCategory = "pp_dict";
		xitemPrimitiveType = "u";
		xitemStringValueType = "u";
		xitemType = "p";
		xnumberValue = 0.0;
		xpath0 = "";
		xpath0Location = "-1";
		xpath1 = "";
		xpath1Location = "-1";
		xpath2 = "";
		xpath2Location = "-1";
		xpath3 = "";
		xpath3Location = "-1";
		xpath4 = "";
		xpath4Location = "-1";
		xpath5 = "";
		xpath5Location = "-1";
		xpath6 = "";
		xpath6Location = "-1";
		xpath7 = "";
		xpath7Location = "-1";
		xstringLongValue = "";
		xstringShortValue = "";
		xtimeValue = "";
	}
};

#endif // !_ITEM_DO_

