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
#ifndef _DICT_DO_
#define _DICT_DO_
#include "../DoInclude.h"


/**
 * ��Ӧ���ݿ�cms_appndict��
 */
class DictDO
{
	/*`xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
	`xcreateTime` datetime NULL DEFAULT NULL,
	`xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
	`xupdateTime` datetime NULL DEFAULT NULL,
	`xdistributeFactor` int NULL DEFAULT NULL,
	`xalias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
	`xappId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
	`xcreatorUid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
	`xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
	`xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,*/
	// �ֵ�id
	CC_SYNTHESIZE(string, xid, Xid);
	// �ֵ䴴��ʱ��
	CC_SYNTHESIZE(string, xcreateTime, XcreateTime);
	// �ֵ�xsequence������ʱ��+id��
	CC_SYNTHESIZE(string, xsequence, Xsequence);
	// �ֵ����ʱ��
	CC_SYNTHESIZE(string, xupdateTime, XupdateTime);
	//xdistributeFactor
	CC_SYNTHESIZE(int, xdistributeFactor, XdistributeFactor);
	// �ֵ����
	CC_SYNTHESIZE(string, xalias, Xalias);
	// xappId
	CC_SYNTHESIZE(string, xappId, XappId);
	// xcreatorUid
	CC_SYNTHESIZE(string, xcreatorUid, XcreatorUid);
	// �ֵ�����
	CC_SYNTHESIZE(string, xdescription, Xdescription);
	// �ֵ�����
	CC_SYNTHESIZE(string, xname, Xname);
public:
	DictDO() {
		xid = "213";
		xcreateTime = "2024-10-29 10:23:21";
		xsequence = "";
		xupdateTime = "2024-10-29 10:23:21";
		xdistributeFactor = 0;
		xalias = "";
		xappId = "";
		xcreatorUid = "";
		xdescription = "";
		xname = "";
	}
};

#endif // !_DICT_DO_

