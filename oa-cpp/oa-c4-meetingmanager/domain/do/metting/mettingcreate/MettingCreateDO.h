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
#ifndef _MettingCreate_DO_
#define _MettingCreate_DO_
#include "../../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class MettingCreateDO
{
	// ��������
	CC_SYNTHESIZE(std::string, mettingtype, MettingType);
	// ����		
	CC_SYNTHESIZE(std::string, date1, Date);
	// ���鿪ʼʱ��
	CC_SYNTHESIZE(std::string, timestart, TimeStart);
	// �������ʱ��
	CC_SYNTHESIZE(std::string, timeend, TimeEnd);
	// ������	
	CC_SYNTHESIZE(std::string, mettingroom, MettingRoom);
	// ����title	
	CC_SYNTHESIZE(std::string, mettingtitle, MettingTitle);
	// member	  
	CC_SYNTHESIZE(std::string, member, Member);
	// hoster	  
	CC_SYNTHESIZE(std::string, hoster, Hoster);
	// department
	CC_SYNTHESIZE(std::string, department, Department);
	// description
	CC_SYNTHESIZE(std::string, description, Description);
	
public:
	MettingCreateDO() {
		mettingtype = "";

		date1 = "";

		timestart = "";

		mettingroom = "";

		mettingtitle = "";

		member = "";

		hoster = "";

		department = "";

		description = "";
	}

};

#endif // !_MettingCreate_DO_
