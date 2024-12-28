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
#ifndef _CAL_CALENDAR_DO_
#define _CAL_CALENDAR_DO_
#include "../DoInclude.h"
#include "cal_calendar_manageablepersonlistDO.h"
#include "cal_calendar_publishablegrouplistDO.h"
#include "cal_calendar_publishablepersonlistDO.h"
#include "cal_calendar_publishableunitlistDO.h"
#include "cal_calendar_viewablegrouplistDO.h"
#include "cal_calendar_viewablepersonlistDO.h"
#include "cal_calendar_viewableunitlistDO.h"

class cal_calendarDO{
	// ���
	CC_SYNTHESIZE(string, xid, xId);
	// ��ɫ
	CC_SYNTHESIZE(string, xcolor, xColor);
	// ��ע
	CC_SYNTHESIZE(string, xdescription, xDescription);
	// �Ƿ񹫿�
	CC_SYNTHESIZE(int, xispublic, xIsPublic);
	// ��������
	CC_SYNTHESIZE(string, xname, xName);
	// �Ƿ�����
	CC_SYNTHESIZE(string, xstatus, xStatus);
	// ������֯
	CC_SYNTHESIZE(string, xtarget, xTarget);
	// ��������
	CC_SYNTHESIZE(string, xtype, xType);
	// ����ʱ��
	CC_SYNTHESIZE(string, xcreatetime, xCreateTime);
	// ����ʱ��
	CC_SYNTHESIZE(string, xupdatetime, xUpdateTime);
	// ������
	CC_SYNTHESIZE(string, xcreateor, xCreateor);
	// xsequence
	CC_SYNTHESIZE(string, xsequence, xSequence);
	// xsource
	CC_SYNTHESIZE(string, xsource, xSource);
public:
	cal_calendarDO() {
		xid = "0";
		xcolor = "";
		xdescription = "";
		xispublic = 1;
		xname = "";
		xstatus = "OPEN";
		xtarget = "";
		xtype = "PERSON";
		xcreatetime = "";
		xupdatetime = "";
		xcreateor = "";
		xsequence = "";
		xsource = "";
	};
};

#endif //!_CAL_CALENDAR_DO_
