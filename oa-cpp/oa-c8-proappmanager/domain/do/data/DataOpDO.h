#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:51:41

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
#ifndef _DATAOP_DO_
#define _DATAOP_DO_

#include "Macros.h"
#include <string>
#include <list>
using namespace std;

class DataOpDO
{
	// ������������ID
	CC_SYNTHESIZE(string, id, Id);

	//	item - id : ����ID��
	CC_SYNTHESIZE(string, itemid, ItemId);
	
	//����������������
	CC_SYNTHESIZE(string, name, Name);
	
	//�����������ñ���
	CC_SYNTHESIZE(string, alias, Alias);
	
	//����������������
	CC_SYNTHESIZE(string, description, Description);

	//�����������ô���ʱ�䣨ʱ������date��
	CC_SYNTHESIZE(string, createtime, CreateTime);

	//�����������ø���ʱ��
	CC_SYNTHESIZE(string, updatetime, UpdateTime);

	//������������Ӧ�ú�
	CC_SYNTHESIZE(string, application, Application);

	//���������������к�
	CC_SYNTHESIZE(string, sequence, Sequence);

	//�������÷�������
	CC_SYNTHESIZE(uint64_t, distributefactor, DistributeFactor);

	//		bundle : ����������������ID��
	CC_SYNTHESIZE(string, bundle, Bundle);

	//		item - type : object���ͼ�� �����object��Ϊo ��Ϊp
	CC_SYNTHESIZE(string, itemtype, ItemType);

	//		item - primitive - type : ����ԭʼ�������� ������ĸСд����ʾ�ñ��е�ֵ������
	CC_SYNTHESIZE(string, itemprimitivetype, ItemPrimitiveType);

	//		item - string - value - type : ���Ƿ�Ϊ�ַ��������� sΪ��string uΪ������������
	CC_SYNTHESIZE(string, itemstringvaluetype, ItemStringValueType);

	//		item - category : ��Ŀ���� �˱��������ĸ���Ŀ��
	CC_SYNTHESIZE(string, itemcategory, ItemCategory);

	//		number - value : number������ֵ
	CC_SYNTHESIZE(double_t, numbervalue, NumberValue);

	//		boolean - value : ����������ֵ
	CC_SYNTHESIZE(bool, boolvalue, BoolValue);

	//		date - time - value : ��ʱ������ֵ(��ʱ��)
	CC_SYNTHESIZE(string, datetimevalue, DateTimeValue);

	//		date - value : ��ʱ������ֵ(����)
	CC_SYNTHESIZE(string, datevalue, DateValue);

	//�ı�ֵ����
	CC_SYNTHESIZE(string, text, Text);

	//   time-value: ��ʱ������ֵ
	CC_SYNTHESIZE(string,timevalue,TimeValue);

	//�����ֶ� ���������ݶ��ȴ��������Ȼ����зֲ�ͷ���
	CC_SYNTHESIZE(string, data, Data);




	public:
	DataOpDO() {
		id = " ";
		itemid = " ";
		name = " ";
		alias = " ";
		description = " ";
		createtime = " ";
		updatetime = " ";
		application = " ";
		sequence = " ";
		distributefactor = 0;
		bundle = " ";
		itemtype = "o";
		itemprimitivetype = "o";
		itemstringvaluetype = "o";
		itemcategory = "pp_dict";
		numbervalue = 0.0;
		boolvalue = false;
		datetimevalue = "2000/1/1 00:00";
		datevalue = "2000/1/1";
		data = " ";
	}
};


class DataOpItemDO
{

	//	item - id : ����ID��
	CC_SYNTHESIZE(string, itemid, ItemId);


	// ������������ID
	CC_SYNTHESIZE(string, id, Id);


	public:
		DataOpItemDO() {
			id = " ";
			itemid = " ";
		}

};


#endif // !_DO_INCLUDE_
