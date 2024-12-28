/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:13:11

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
#include "stdafx.h"
#include "DataConfigService.h"
#include "../../dao/data-config/DataConfigDAO.h"
#include "../../../lib-common/include/SnowFlake.h"
#include "../../../lib-common/include/SimpleDateTimeFormat.h"
#include "cJSON.h"
#include "cJSON.c"

int flag = 1;
vector<ItemDO> Items;
// ���ڱ����丸�ڵ���Ϣ�������丸�ڵ�����ظ�����ÿ��xpath·�������ظ�����Ϊÿ��xpath����һ��ӳ��
map<string, cJSON*> MapXpath0, MapXpath1, MapXpath2, MapXpath3, MapXpath4, MapXpath5, MapXpath6;

//����json�ַ�������ʼ��ÿ��item������ÿ��item��ӵ�vector������
void AnalyzeJson(cJSON* root, vector<string> path) {
	if (root == NULL) return;

	if (flag == 1) {  //���ڱ������㣬��root��㣬����flag��ֻ֤��ʼ��һ�������
		cout << "/" << endl;
		flag = 0;
		ItemDO item1;
		item1.setXpath0("");
		if (root->type == cJSON_Object) { // �����Ϊobject����
			item1.setXitemType("o");
			Items.push_back(item1);
		}
		else if (root->type == cJSON_Array) { // �����Ϊarray����
			item1.setXitemType("a");
			Items.push_back(item1);
		}
	}
	// ���item�Ƕ�������飬���������ӵ�·����
	if ((root->type == cJSON_Object || root->type == cJSON_Array) && root->string != NULL) {
		path.push_back(root->string);
	}

	for (int j = 0; j < cJSON_GetArraySize(root); j++) {
		//��������飬�Զ����������±�·��
		if (root->type == cJSON_Array) {
			path.push_back(to_string(j));
		}
		cJSON* item = cJSON_GetArrayItem(root, j);
		if (item->type == cJSON_Object) {//����
			if (item != NULL) {
				ItemDO item1;
				item1.setXitemType("o");
				// ��·���ӽ�ȥ
				for (size_t i = 0; i < path.size(); ++i) { // �����Ǹ����
					cout << "/";
					cout << path[i];
					if (i == 0) {
						item1.setXpath0(path[0]);
					}
					if (i == 1) {
						item1.setXpath1(path[1]);
					}
					if (i == 2) {
						item1.setXpath2(path[2]);
					}
					if (i == 3) {
						item1.setXpath3(path[3]);
					}
					if (i == 4) {
						item1.setXpath4(path[4]);
					}
					if (i == 5) {
						item1.setXpath5(path[5]);
					}
					if (i == 6) {
						item1.setXpath6(path[6]);
					}
					if (i == 7) {
						item1.setXpath7(path[7]);
					}
				}

				//��ǰ������������֣���������Ҫ�����ּӵ�·����
				if (item->string)//���ܴ��ڶ�����ΪNULL{"key":"value"}������ΪNULL   )
				{
					cout << "/" << item->string << endl;
					if (path.size() == 0) {
						item1.setXpath0(item->string);
					}
					if (path.size() == 1) {
						item1.setXpath1(item->string);
					}
					if (path.size() == 2) {
						item1.setXpath2(item->string);
					}
					if (path.size() == 3) {
						item1.setXpath3(item->string);
					}
					if (path.size() == 4) {
						item1.setXpath4(item->string);
					}
					if (path.size() == 5) {
						item1.setXpath5(item->string);
					}
					if (path.size() == 6) {
						item1.setXpath6(item->string);
					}
					if (path.size() == 7) {
						item1.setXpath7(item->string);
					}
					Items.push_back(item1);
				}
				//û���ֲ���Ҫ�ӵ�·����
				else {
					Items.push_back(item1);
				}

				cout << endl;
				AnalyzeJson(item, path);
				//�ڵݹ����AnalyzeJson�����item���������ͣ��뽫path����һ������Ϊ����·��������±�
				if (root->type == cJSON_Array) {
					path.pop_back();
				}
			}
		}
		else if (item->type == cJSON_Array) {
			if (item != NULL) {//����
				ItemDO item1;
				item1.setXitemType("a");
				for (size_t i = 0; i < path.size(); ++i) {
					cout << "/";
					cout << path[i];
					if (i == 0) {
						item1.setXpath0(path[0]);
					}
					if (i == 1) {
						item1.setXpath1(path[1]);
					}
					if (i == 2) {
						item1.setXpath2(path[2]);
					}
					if (i == 3) {
						item1.setXpath3(path[3]);
					}
					if (i == 4) {
						item1.setXpath4(path[4]);
					}
					if (i == 5) {
						item1.setXpath5(path[5]);
					}
					if (i == 6) {
						item1.setXpath6(path[6]);
					}
					if (i == 7) {
						item1.setXpath7(path[7]);
					}
				}
				if (item->string)
				{
					cout << "/" << item->string << endl;
					if (path.size() == 0) {
						item1.setXpath0(item->string);
					}
					if (path.size() == 1) {
						item1.setXpath1(item->string);
					}
					if (path.size() == 2) {
						item1.setXpath2(item->string);
					}
					if (path.size() == 3) {
						item1.setXpath3(item->string);
					}
					if (path.size() == 4) {
						item1.setXpath4(item->string);
					}
					if (path.size() == 5) {
						item1.setXpath5(item->string);
					}
					if (path.size() == 6) {
						item1.setXpath6(item->string);
					}
					if (path.size() == 7) {
						item1.setXpath7(item->string);
					}
					Items.push_back(item1);
				}
				else {
					Items.push_back(item1);
				}

				cout << endl;
				AnalyzeJson(item, path);
				if (root->type == cJSON_Array) {
					path.pop_back();
				}
			}
		}
		else {
			if (item != NULL) {//��ֵ�ԣ�ע�������
				ItemDO item1;
				//���·��
				for (size_t i = 0; i < path.size(); ++i) {
					cout << "/";
					cout << path[i];
					if (i == 0) {
						item1.setXpath0(path[0]);
					}
					if (i == 1) {
						item1.setXpath1(path[1]);
					}
					if (i == 2) {
						item1.setXpath2(path[2]);
					}
					if (i == 3) {
						item1.setXpath3(path[3]);
					}
					if (i == 4) {
						item1.setXpath4(path[4]);
					}
					if (i == 5) {
						item1.setXpath5(path[5]);
					}
					if (i == 6) {
						item1.setXpath6(path[6]);
					}
					if (i == 7) {
						item1.setXpath7(path[7]);
					}
				}
				if (item->type == cJSON_String && item->string != NULL) // string����	
				{
					cout << "/" << item->string << ":" << item->valuestring << endl;
					item1.setXitemPrimitiveType("s");
					item1.setXitemStringValueType("s");
					item1.setXstringShortValue(item->valuestring);
					if (path.size() == 0) {
						item1.setXpath0(item->string);
					}
					if (path.size() == 1) {
						item1.setXpath1(item->string);
					}
					if (path.size() == 2) {
						item1.setXpath2(item->string);
					}
					if (path.size() == 3) {
						item1.setXpath3(item->string);
					}
					if (path.size() == 4) {
						item1.setXpath4(item->string);
					}
					if (path.size() == 5) {
						item1.setXpath5(item->string);
					}
					if (path.size() == 6) {
						item1.setXpath6(item->string);
					}
					if (path.size() == 7) {
						item1.setXpath7(item->string);
					}
					Items.push_back(item1);
				}
				if (item->type == cJSON_Number && item->string != NULL) // ��ֵ����
				{
					cout << "/" << item->string << ":" << item->valuedouble << endl;
					item1.setXitemPrimitiveType("n");
					item1.setXnumberValue(item->valuedouble);
					if (path.size() == 0) {
						item1.setXpath0(item->string);
					}
					if (path.size() == 1) {
						item1.setXpath1(item->string);
					}
					if (path.size() == 2) {
						item1.setXpath2(item->string);
					}
					if (path.size() == 3) {
						item1.setXpath3(item->string);
					}
					if (path.size() == 4) {
						item1.setXpath4(item->string);
					}
					if (path.size() == 5) {
						item1.setXpath5(item->string);
					}
					if (path.size() == 6) {
						item1.setXpath6(item->string);
					}
					if (path.size() == 7) {
						item1.setXpath7(item->string);
					}
					Items.push_back(item1);
				}
				if ((item->type == cJSON_True || item->type == cJSON_False) && item->string != NULL) // boll����
				{
					cout << "/" << item->string << ":" << item->valueint << endl;
					item1.setXitemPrimitiveType("b");
					item1.setXbooleanValue(item->valueint);
					if (path.size() == 0) {
						item1.setXpath0(item->string);
					}
					if (path.size() == 1) {
						item1.setXpath1(item->string);
					}
					if (path.size() == 2) {
						item1.setXpath2(item->string);
					}
					if (path.size() == 3) {
						item1.setXpath3(item->string);
					}
					if (path.size() == 4) {
						item1.setXpath4(item->string);
					}
					if (path.size() == 5) {
						item1.setXpath5(item->string);
					}
					if (path.size() == 6) {
						item1.setXpath6(item->string);
					}
					if (path.size() == 7) {
						item1.setXpath7(item->string);
					}
					Items.push_back(item1);
				}
				//�������Ϊ�յ����
				if (item->type == cJSON_String && item->string == NULL) // string����
				{
					cout << ":" << item->valuestring << endl;
					item1.setXitemPrimitiveType("s");
					item1.setXitemStringValueType("s");
					item1.setXstringShortValue(item->valuestring);

					Items.push_back(item1);
					//�������������Զ������±�·���������item����������������·������Ҫ����
					path.pop_back();
				}
				if (item->type == cJSON_Number && item->string == NULL) // ��ֵ����
				{
					cout << ":" << item->valuedouble << endl;
					item1.setXitemPrimitiveType("n");
					item1.setXnumberValue(item->valuedouble);

					Items.push_back(item1);
					path.pop_back();
				}
				if ((item->type == cJSON_True || item->type == cJSON_False) && item->string == NULL) // ��ֵ����
				{
					cout << ":" << item->valueint << endl;
					item1.setXitemPrimitiveType("b");
					item1.setXbooleanValue(item->valueint);

					Items.push_back(item1);
					path.pop_back();
				}
			}
		}
	}
}

string CreateJson(vector<ItemDO> Items) {
	//����vec��������װcjson����
	//���ȴ�������㣬�ȱ�������items�ҵ�����㣬�ж������ͣ���ʼ�������
	for (int i = 0; i < Items.size(); i++) {
		if (Items[i].getXpath0() == "") {
			if (Items[i].getXitemType() == "a") {
				cJSON* root = cJSON_CreateArray(); // ���������Ϊarray
				MapXpath0.insert(make_pair("root", root)); // ���������뵽Map������
			}
			else if (Items[i].getXitemType() == "o")
			{
				cJSON* root = cJSON_CreateObject(); // ���������Ϊobject
				MapXpath0.insert(make_pair("root", root)); // ���������뵽Map������
			}
		}
	}

	//��������·��������item
	for (int j = 0; j <= 7; j++) {
		for (int i = 0; i < Items.size(); i++) {
			if (j == 0) { // ����xpath0
				// ����item�����ʹ�����Ӧ���
				if (Items[i].getXpath1() == "" && (Items[i].getXpath0() != "")) // ��֤��item���丸�ڵ���ӽ��
				{
					if (Items[i].getXitemType() == "o") { // objec������Ϊ��Ŀ¼���ӽڵ�
						cJSON* objectItem = cJSON_CreateObject();
						MapXpath0.insert(make_pair(Items[i].getXpath0(), objectItem)); // ����ý��·��
						if (MapXpath0["root"]->type == cJSON_Object) { // �丸�ڵ�Ϊobject����
							cJSON_AddItemToObject(MapXpath0["root"], Items[i].getXpath0().c_str(), objectItem); // ���ö�����뵽�����
						}
						else if (MapXpath0["root"]->type == cJSON_Array) { // �丸�ڵ�Ϊarray����
							cJSON_AddItemToArray(MapXpath0["root"], objectItem);
						}
					}
					if (Items[i].getXitemType() == "a") { // arrray������Ϊ��Ŀ¼���ӽڵ�
						cJSON* arrayItem = cJSON_CreateArray();
						MapXpath0.insert(make_pair(Items[i].getXpath0(), arrayItem)); // ����ý��·��
						if (MapXpath0["root"]->type == cJSON_Object) { // �丸�ڵ�Ϊobject����
							cJSON_AddItemToObject(MapXpath0["root"], Items[i].getXpath0().c_str(), arrayItem); // ����������뵽�����
						}
						else if (MapXpath0["root"]->type == cJSON_Array) { // �丸�ڵ�Ϊarray����
							cJSON_AddItemToArray(MapXpath0["root"], arrayItem);
						}

					}
					if (Items[i].getXitemPrimitiveType() == "n") { // number������Ϊ��Ŀ¼���ӽڵ�
						if (MapXpath0["root"]->type == cJSON_Object) { // �丸�ڵ�Ϊobject����
							cJSON_AddItemToObject(MapXpath0["root"], Items[i].getXpath0().c_str(), cJSON_CreateNumber(Items[i].getXnumberValue())); // ����item���뵽�����
						}
						else if (MapXpath0["root"]->type == cJSON_Array) { // �丸�ڵ�Ϊarray����
							cJSON_AddItemToArray(MapXpath0["root"], cJSON_CreateNumber(Items[i].getXnumberValue()));
						}
					}
					if (Items[i].getXitemPrimitiveType() == "s") { // string������Ϊ��Ŀ¼���ӽڵ�
						if (MapXpath0["root"]->type == cJSON_Object) { // �丸�ڵ�Ϊobject����
							cJSON_AddItemToObject(MapXpath0["root"], Items[i].getXpath0().c_str(), cJSON_CreateString(Items[i].getXstringShortValue().c_str())); // ����item���뵽�����
						}
						else if (MapXpath0["root"]->type == cJSON_Array) { // �丸�ڵ�Ϊarray����
							cJSON_AddItemToArray(MapXpath0["root"], cJSON_CreateString(Items[i].getXstringShortValue().c_str()));
						}
					}
					if (Items[i].getXitemPrimitiveType() == "b") { // boolean������Ϊ��Ŀ¼���ӽڵ�
						if (MapXpath0["root"]->type == cJSON_Object) { // �丸�ڵ�Ϊobject����
							cJSON_AddItemToObject(MapXpath0["root"], Items[i].getXpath0().c_str(), cJSON_CreateBool(Items[i].getXbooleanValue())); // ����item���뵽�����
						}
						else if (MapXpath0["root"]->type == cJSON_Array) { // �丸�ڵ�Ϊarray����
							cJSON_AddItemToArray(MapXpath0["root"], cJSON_CreateBool(Items[i].getXbooleanValue()));
						}
					}
				}
			}

			if (j == 1) { // ����xpath1
				// ����item�����ʹ�����Ӧ���
				if (Items[i].getXpath2() == "" && (Items[i].getXpath1() != "")) // ��֤��item���丸�ڵ���ӽ��
				{
					if (Items[i].getXitemType() == "o") { // objec������Ϊ��Ŀ¼���ӽڵ�
						cJSON* objectItem = cJSON_CreateObject();
						MapXpath1.insert(make_pair(Items[i].getXpath1(), objectItem)); // ����ý��·��
						if (MapXpath0[Items[i].getXpath0()]->type == cJSON_Object) { // �丸�ڵ�Ϊobject����
							cJSON_AddItemToObject(MapXpath0[Items[i].getXpath0()], Items[i].getXpath1().c_str(), objectItem); // ���ö�����뵽�����
						}
						else if (MapXpath0[Items[i].getXpath0()]->type == cJSON_Array) { // �丸�ڵ�Ϊarray����
							cJSON_AddItemToArray(MapXpath0[Items[i].getXpath0()], objectItem);
						}

					}
					if (Items[i].getXitemType() == "a") { // arrray������Ϊ��Ŀ¼���ӽڵ�
						cJSON* arrayItem = cJSON_CreateArray();
						MapXpath1.insert(make_pair(Items[i].getXpath1(), arrayItem)); // ����ý��·��
						if (MapXpath0[Items[i].getXpath0()]->type == cJSON_Object) { // �丸�ڵ�Ϊobject����
							cJSON_AddItemToObject(MapXpath0[Items[i].getXpath0()], Items[i].getXpath1().c_str(), arrayItem); // ����������뵽�����
						}
						else if (MapXpath0[Items[i].getXpath0()]->type == cJSON_Array) { // �丸�ڵ�Ϊarray����
							cJSON_AddItemToArray(MapXpath0[Items[i].getXpath0()], arrayItem);
						}

					}
					if (Items[i].getXitemPrimitiveType() == "n") { // number������Ϊ��Ŀ¼���ӽڵ�
						if (MapXpath0[Items[i].getXpath0()]->type == cJSON_Object) { // �丸�ڵ�Ϊobject����
							cJSON_AddItemToObject(MapXpath0[Items[i].getXpath0()], Items[i].getXpath1().c_str(), cJSON_CreateNumber(Items[i].getXnumberValue())); // ����item���뵽�����
						}
						else if (MapXpath0[Items[i].getXpath0()]->type == cJSON_Array) { // �丸�ڵ�Ϊarray����
							cJSON_AddItemToArray(MapXpath0[Items[i].getXpath0()], cJSON_CreateNumber(Items[i].getXnumberValue()));
						}
					}
					if (Items[i].getXitemPrimitiveType() == "s") { // string������Ϊ��Ŀ¼���ӽڵ�
						if (MapXpath0[Items[i].getXpath0()]->type == cJSON_Object) { // �丸�ڵ�Ϊobject����
							cJSON_AddItemToObject(MapXpath0[Items[i].getXpath0()], Items[i].getXpath1().c_str(), cJSON_CreateString(Items[i].getXstringShortValue().c_str())); // ����item���뵽�����
						}
						else if (MapXpath0[Items[i].getXpath0()]->type == cJSON_Array) { // �丸�ڵ�Ϊarray����
							cJSON_AddItemToArray(MapXpath0[Items[i].getXpath0()], cJSON_CreateString(Items[i].getXstringShortValue().c_str()));
						}
					}
					if (Items[i].getXitemPrimitiveType() == "b") { // boolean������Ϊ��Ŀ¼���ӽڵ�
						if (MapXpath0[Items[i].getXpath0()]->type == cJSON_Object) { // �丸�ڵ�Ϊobject����
							cJSON_AddItemToObject(MapXpath0[Items[i].getXpath0()], Items[i].getXpath1().c_str(), cJSON_CreateBool(Items[i].getXbooleanValue())); // ����item���뵽�����
						}
						else if (MapXpath0[Items[i].getXpath0()]->type == cJSON_Array) { // �丸�ڵ�Ϊarray����
							cJSON_AddItemToArray(MapXpath0[Items[i].getXpath0()], cJSON_CreateBool(Items[i].getXbooleanValue()));
						}
					}
				}
			}

			if (j == 2) { // ����xpath2
				// ����item�����ʹ�����Ӧ���
				if (Items[i].getXpath3() == "" && (Items[i].getXpath2() != "")) // ��֤��item���丸�ڵ���ӽ��
				{
					if (Items[i].getXitemType() == "o") { // objec������Ϊ��Ŀ¼���ӽڵ�
						cJSON* objectItem = cJSON_CreateObject();
						MapXpath2.insert(make_pair(Items[i].getXpath2(), objectItem)); // ����ý��·��
						if (MapXpath1[Items[i].getXpath1()]->type == cJSON_Object) { // �丸�ڵ�Ϊobject����
							cJSON_AddItemToObject(MapXpath1[Items[i].getXpath1()], Items[i].getXpath2().c_str(), objectItem); // ���ö�����뵽�����
						}
						else if (MapXpath1[Items[i].getXpath1()]->type == cJSON_Array) { // �丸�ڵ�Ϊarray����
							cJSON_AddItemToArray(MapXpath1[Items[i].getXpath1()], objectItem);
						}

					}
					if (Items[i].getXitemType() == "a") { // arrray������Ϊ��Ŀ¼���ӽڵ�
						cJSON* arrayItem = cJSON_CreateArray();
						MapXpath2.insert(make_pair(Items[i].getXpath2(), arrayItem)); // ����ý��·��
						if (MapXpath1[Items[i].getXpath1()]->type == cJSON_Object) { // �丸�ڵ�Ϊobject����
							cJSON_AddItemToObject(MapXpath1[Items[i].getXpath1()], Items[i].getXpath2().c_str(), arrayItem); // ����������뵽�����
						}
						else if (MapXpath1[Items[i].getXpath1()]->type == cJSON_Array) { // �丸�ڵ�Ϊarray����
							cJSON_AddItemToArray(MapXpath1[Items[i].getXpath1()], arrayItem);
						}

					}
					if (Items[i].getXitemPrimitiveType() == "n") { // number������Ϊ��Ŀ¼���ӽڵ�
						if (MapXpath1[Items[i].getXpath1()]->type == cJSON_Object) { // �丸�ڵ�Ϊobject����
							cJSON_AddItemToObject(MapXpath1[Items[i].getXpath1()], Items[i].getXpath2().c_str(), cJSON_CreateNumber(Items[i].getXnumberValue())); // ����item���뵽�����
						}
						else if (MapXpath1[Items[i].getXpath1()]->type == cJSON_Array) { // �丸�ڵ�Ϊarray����
							cJSON_AddItemToArray(MapXpath1[Items[i].getXpath1()], cJSON_CreateNumber(Items[i].getXnumberValue()));
						}
					}
					if (Items[i].getXitemPrimitiveType() == "s") { // string������Ϊ��Ŀ¼���ӽڵ�
						if (MapXpath1[Items[i].getXpath1()]->type == cJSON_Object) { // �丸�ڵ�Ϊobject����
							cJSON_AddItemToObject(MapXpath1[Items[i].getXpath1()], Items[i].getXpath2().c_str(), cJSON_CreateString(Items[i].getXstringShortValue().c_str())); // ����item���뵽�����
						}
						else if (MapXpath1[Items[i].getXpath1()]->type == cJSON_Array) { // �丸�ڵ�Ϊarray����
							cJSON_AddItemToArray(MapXpath1[Items[i].getXpath1()], cJSON_CreateString(Items[i].getXstringShortValue().c_str()));
						}
					}
					if (Items[i].getXitemPrimitiveType() == "b") { // boolean������Ϊ��Ŀ¼���ӽڵ�
						if (MapXpath1[Items[i].getXpath1()]->type == cJSON_Object) { // �丸�ڵ�Ϊobject����
							cJSON_AddItemToObject(MapXpath1[Items[i].getXpath1()], Items[i].getXpath2().c_str(), cJSON_CreateBool(Items[i].getXbooleanValue())); // ����item���뵽�����
						}
						else if (MapXpath1[Items[i].getXpath1()]->type == cJSON_Array) { // �丸�ڵ�Ϊarray����
							cJSON_AddItemToArray(MapXpath1[Items[i].getXpath1()], cJSON_CreateBool(Items[i].getXbooleanValue()));
						}
					}
				}
			}

			if (j == 3) { // ����xpath3
				// ����item�����ʹ�����Ӧ���
				if (Items[i].getXpath4() == "" && (Items[i].getXpath3() != "")) // ��֤��item���丸�ڵ���ӽ��
				{
					if (Items[i].getXitemType() == "o") { // objec������Ϊ��Ŀ¼���ӽڵ�
						cJSON* objectItem = cJSON_CreateObject();
						MapXpath3.insert(make_pair(Items[i].getXpath3(), objectItem)); // ����ý��·��
						if (MapXpath2[Items[i].getXpath2()]->type == cJSON_Object) { // �丸�ڵ�Ϊobject����
							cJSON_AddItemToObject(MapXpath2[Items[i].getXpath2()], Items[i].getXpath3().c_str(), objectItem); // ���ö�����뵽�����
						}
						else if (MapXpath2[Items[i].getXpath2()]->type == cJSON_Array) { // �丸�ڵ�Ϊarray����
							cJSON_AddItemToArray(MapXpath2[Items[i].getXpath2()], objectItem);
						}

					}
					if (Items[i].getXitemType() == "a") { // arrray������Ϊ��Ŀ¼���ӽڵ�
						cJSON* arrayItem = cJSON_CreateArray();
						MapXpath3.insert(make_pair(Items[i].getXpath3(), arrayItem)); // ����ý��·��
						if (MapXpath2[Items[i].getXpath2()]->type == cJSON_Object) { // �丸�ڵ�Ϊobject����
							cJSON_AddItemToObject(MapXpath2[Items[i].getXpath2()], Items[i].getXpath3().c_str(), arrayItem); // ����������뵽�����
						}
						else if (MapXpath2[Items[i].getXpath2()]->type == cJSON_Array) { // �丸�ڵ�Ϊarray����
							cJSON_AddItemToArray(MapXpath2[Items[i].getXpath2()], arrayItem);
						}

					}
					if (Items[i].getXitemPrimitiveType() == "n") { // number������Ϊ��Ŀ¼���ӽڵ�
						if (MapXpath2[Items[i].getXpath2()]->type == cJSON_Object) { // �丸�ڵ�Ϊobject����
							cJSON_AddItemToObject(MapXpath2[Items[i].getXpath2()], Items[i].getXpath3().c_str(), cJSON_CreateNumber(Items[i].getXnumberValue())); // ����item���뵽�����
						}
						else if (MapXpath2[Items[i].getXpath2()]->type == cJSON_Array) { // �丸�ڵ�Ϊarray����
							cJSON_AddItemToArray(MapXpath2[Items[i].getXpath2()], cJSON_CreateNumber(Items[i].getXnumberValue()));
						}
					}
					if (Items[i].getXitemPrimitiveType() == "s") { // string������Ϊ��Ŀ¼���ӽڵ�
						if (MapXpath2[Items[i].getXpath2()]->type == cJSON_Object) { // �丸�ڵ�Ϊobject����
							cJSON_AddItemToObject(MapXpath2[Items[i].getXpath2()], Items[i].getXpath3().c_str(), cJSON_CreateString(Items[i].getXstringShortValue().c_str())); // ����item���뵽�����
						}
						else if (MapXpath2[Items[i].getXpath2()]->type == cJSON_Array) { // �丸�ڵ�Ϊarray����
							cJSON_AddItemToArray(MapXpath2[Items[i].getXpath2()], cJSON_CreateString(Items[i].getXstringShortValue().c_str()));
						}
					}
					if (Items[i].getXitemPrimitiveType() == "b") { // boolean������Ϊ��Ŀ¼���ӽڵ�
						if (MapXpath2[Items[i].getXpath2()]->type == cJSON_Object) { // �丸�ڵ�Ϊobject����
							cJSON_AddItemToObject(MapXpath2[Items[i].getXpath2()], Items[i].getXpath3().c_str(), cJSON_CreateBool(Items[i].getXbooleanValue())); // ����item���뵽�����
						}
						else if (MapXpath2[Items[i].getXpath2()]->type == cJSON_Array) { // �丸�ڵ�Ϊarray����
							cJSON_AddItemToArray(MapXpath2[Items[i].getXpath2()], cJSON_CreateBool(Items[i].getXbooleanValue()));
						}
					}
				}
			}

			if (j == 4) { // ����xpath4
				// ����item�����ʹ�����Ӧ���
				if (Items[i].getXpath5() == "" && (Items[i].getXpath4() != "")) // ��֤��item���丸�ڵ���ӽ��
				{
					if (Items[i].getXitemType() == "o") { // objec������Ϊ��Ŀ¼���ӽڵ�
						cJSON* objectItem = cJSON_CreateObject();
						MapXpath4.insert(make_pair(Items[i].getXpath4(), objectItem)); // ����ý��·��
						if (MapXpath3[Items[i].getXpath3()]->type == cJSON_Object) { // �丸�ڵ�Ϊobject����
							cJSON_AddItemToObject(MapXpath3[Items[i].getXpath3()], Items[i].getXpath4().c_str(), objectItem); // ���ö�����뵽�����
						}
						else if (MapXpath3[Items[i].getXpath3()]->type == cJSON_Array) { // �丸�ڵ�Ϊarray����
							cJSON_AddItemToArray(MapXpath3[Items[i].getXpath3()], objectItem);
						}

					}
					if (Items[i].getXitemType() == "a") { // arrray������Ϊ��Ŀ¼���ӽڵ�
						cJSON* arrayItem = cJSON_CreateArray();
						MapXpath4.insert(make_pair(Items[i].getXpath4(), arrayItem)); // ����ý��·��
						if (MapXpath3[Items[i].getXpath3()]->type == cJSON_Object) { // �丸�ڵ�Ϊobject����
							cJSON_AddItemToObject(MapXpath3[Items[i].getXpath3()], Items[i].getXpath4().c_str(), arrayItem); // ����������뵽�����
						}
						else if (MapXpath3[Items[i].getXpath3()]->type == cJSON_Array) { // �丸�ڵ�Ϊarray����
							cJSON_AddItemToArray(MapXpath3[Items[i].getXpath3()], arrayItem);
						}

					}
					if (Items[i].getXitemPrimitiveType() == "n") { // number������Ϊ��Ŀ¼���ӽڵ�
						if (MapXpath3[Items[i].getXpath3()]->type == cJSON_Object) { // �丸�ڵ�Ϊobject����
							cJSON_AddItemToObject(MapXpath3[Items[i].getXpath3()], Items[i].getXpath4().c_str(), cJSON_CreateNumber(Items[i].getXnumberValue())); // ����item���뵽�����
						}
						else if (MapXpath3[Items[i].getXpath3()]->type == cJSON_Array) { // �丸�ڵ�Ϊarray����
							cJSON_AddItemToArray(MapXpath3[Items[i].getXpath3()], cJSON_CreateNumber(Items[i].getXnumberValue()));
						}
					}
					if (Items[i].getXitemPrimitiveType() == "s") { // string������Ϊ��Ŀ¼���ӽڵ�
						if (MapXpath3[Items[i].getXpath3()]->type == cJSON_Object) { // �丸�ڵ�Ϊobject����
							cJSON_AddItemToObject(MapXpath3[Items[i].getXpath3()], Items[i].getXpath4().c_str(), cJSON_CreateString(Items[i].getXstringShortValue().c_str())); // ����item���뵽�����
						}
						else if (MapXpath3[Items[i].getXpath3()]->type == cJSON_Array) { // �丸�ڵ�Ϊarray����
							cJSON_AddItemToArray(MapXpath3[Items[i].getXpath3()], cJSON_CreateString(Items[i].getXstringShortValue().c_str()));
						}
					}
					if (Items[i].getXitemPrimitiveType() == "b") { // boolean������Ϊ��Ŀ¼���ӽڵ�
						if (MapXpath3[Items[i].getXpath3()]->type == cJSON_Object) { // �丸�ڵ�Ϊobject����
							cJSON_AddItemToObject(MapXpath3[Items[i].getXpath3()], Items[i].getXpath4().c_str(), cJSON_CreateBool(Items[i].getXbooleanValue())); // ����item���뵽�����
						}
						else if (MapXpath3[Items[i].getXpath3()]->type == cJSON_Array) { // �丸�ڵ�Ϊarray����
							cJSON_AddItemToArray(MapXpath3[Items[i].getXpath3()], cJSON_CreateBool(Items[i].getXbooleanValue()));
						}
					}
				}
			}

			if (j == 5) { // ����xpath5
				// ����item�����ʹ�����Ӧ���
				if (Items[i].getXpath6() == "" && (Items[i].getXpath5() != "")) // ��֤��item���丸�ڵ���ӽ��
				{
					if (Items[i].getXitemType() == "o") { // objec������Ϊ��Ŀ¼���ӽڵ�
						cJSON* objectItem = cJSON_CreateObject();
						MapXpath5.insert(make_pair(Items[i].getXpath5(), objectItem)); // ����ý��·��
						if (MapXpath4[Items[i].getXpath4()]->type == cJSON_Object) { // �丸�ڵ�Ϊobject����
							cJSON_AddItemToObject(MapXpath4[Items[i].getXpath4()], Items[i].getXpath5().c_str(), objectItem); // ���ö�����뵽�����
						}
						else if (MapXpath4[Items[i].getXpath4()]->type == cJSON_Array) { // �丸�ڵ�Ϊarray����
							cJSON_AddItemToArray(MapXpath4[Items[i].getXpath4()], objectItem);
						}

					}
					if (Items[i].getXitemType() == "a") { // arrray������Ϊ��Ŀ¼���ӽڵ�
						cJSON* arrayItem = cJSON_CreateArray();
						MapXpath5.insert(make_pair(Items[i].getXpath5(), arrayItem)); // ����ý��·��
						if (MapXpath4[Items[i].getXpath4()]->type == cJSON_Object) { // �丸�ڵ�Ϊobject����
							cJSON_AddItemToObject(MapXpath4[Items[i].getXpath4()], Items[i].getXpath5().c_str(), arrayItem); // ����������뵽�����
						}
						else if (MapXpath4[Items[i].getXpath4()]->type == cJSON_Array) { // �丸�ڵ�Ϊarray����
							cJSON_AddItemToArray(MapXpath4[Items[i].getXpath4()], arrayItem);
						}

					}
					if (Items[i].getXitemPrimitiveType() == "n") { // number������Ϊ��Ŀ¼���ӽڵ�
						if (MapXpath4[Items[i].getXpath4()]->type == cJSON_Object) { // �丸�ڵ�Ϊobject����
							cJSON_AddItemToObject(MapXpath4[Items[i].getXpath4()], Items[i].getXpath5().c_str(), cJSON_CreateNumber(Items[i].getXnumberValue())); // ����item���뵽�����
						}
						else if (MapXpath4[Items[i].getXpath4()]->type == cJSON_Array) { // �丸�ڵ�Ϊarray����
							cJSON_AddItemToArray(MapXpath4[Items[i].getXpath4()], cJSON_CreateNumber(Items[i].getXnumberValue()));
						}
					}
					if (Items[i].getXitemPrimitiveType() == "s") { // string������Ϊ��Ŀ¼���ӽڵ�
						if (MapXpath4[Items[i].getXpath4()]->type == cJSON_Object) { // �丸�ڵ�Ϊobject����
							cJSON_AddItemToObject(MapXpath4[Items[i].getXpath4()], Items[i].getXpath5().c_str(), cJSON_CreateString(Items[i].getXstringShortValue().c_str())); // ����item���뵽�����
						}
						else if (MapXpath4[Items[i].getXpath4()]->type == cJSON_Array) { // �丸�ڵ�Ϊarray����
							cJSON_AddItemToArray(MapXpath4[Items[i].getXpath4()], cJSON_CreateString(Items[i].getXstringShortValue().c_str()));
						}
					}
					if (Items[i].getXitemPrimitiveType() == "b") { // boolean������Ϊ��Ŀ¼���ӽڵ�
						if (MapXpath4[Items[i].getXpath4()]->type == cJSON_Object) { // �丸�ڵ�Ϊobject����
							cJSON_AddItemToObject(MapXpath4[Items[i].getXpath4()], Items[i].getXpath5().c_str(), cJSON_CreateBool(Items[i].getXbooleanValue())); // ����item���뵽�����
						}
						else if (MapXpath4[Items[i].getXpath4()]->type == cJSON_Array) { // �丸�ڵ�Ϊarray����
							cJSON_AddItemToArray(MapXpath4[Items[i].getXpath4()], cJSON_CreateBool(Items[i].getXbooleanValue()));
						}
					}
				}
			}

			if (j == 6) { // ����xpath6
				// ����item�����ʹ�����Ӧ���
				if (Items[i].getXpath7() == "" && (Items[i].getXpath6() != "")) // ��֤��item���丸�ڵ���ӽ��
				{
					if (Items[i].getXitemType() == "o") { // objec������Ϊ��Ŀ¼���ӽڵ�
						cJSON* objectItem = cJSON_CreateObject();
						MapXpath6.insert(make_pair(Items[i].getXpath6(), objectItem)); // ����ý��·��
						if (MapXpath5[Items[i].getXpath5()]->type == cJSON_Object) { // �丸�ڵ�Ϊobject����
							cJSON_AddItemToObject(MapXpath5[Items[i].getXpath5()], Items[i].getXpath6().c_str(), objectItem); // ���ö�����뵽�����
						}
						else if (MapXpath5[Items[i].getXpath5()]->type == cJSON_Array) { // �丸�ڵ�Ϊarray����
							cJSON_AddItemToArray(MapXpath5[Items[i].getXpath5()], objectItem);
						}

					}
					if (Items[i].getXitemType() == "a") { // arrray������Ϊ��Ŀ¼���ӽڵ�
						cJSON* arrayItem = cJSON_CreateArray();
						MapXpath6.insert(make_pair(Items[i].getXpath6(), arrayItem)); // ����ý��·��
						if (MapXpath5[Items[i].getXpath5()]->type == cJSON_Object) { // �丸�ڵ�Ϊobject����
							cJSON_AddItemToObject(MapXpath5[Items[i].getXpath5()], Items[i].getXpath6().c_str(), arrayItem); // ����������뵽�����
						}
						else if (MapXpath5[Items[i].getXpath5()]->type == cJSON_Array) { // �丸�ڵ�Ϊarray����
							cJSON_AddItemToArray(MapXpath5[Items[i].getXpath5()], arrayItem);
						}

					}
					if (Items[i].getXitemPrimitiveType() == "n") { // number������Ϊ��Ŀ¼���ӽڵ�
						if (MapXpath5[Items[i].getXpath5()]->type == cJSON_Object) { // �丸�ڵ�Ϊobject����
							cJSON_AddItemToObject(MapXpath5[Items[i].getXpath5()], Items[i].getXpath6().c_str(), cJSON_CreateNumber(Items[i].getXnumberValue())); // ����item���뵽�����
						}
						else if (MapXpath5[Items[i].getXpath5()]->type == cJSON_Array) { // �丸�ڵ�Ϊarray����
							cJSON_AddItemToArray(MapXpath5[Items[i].getXpath5()], cJSON_CreateNumber(Items[i].getXnumberValue()));
						}
					}
					if (Items[i].getXitemPrimitiveType() == "s") { // string������Ϊ��Ŀ¼���ӽڵ�
						if (MapXpath5[Items[i].getXpath5()]->type == cJSON_Object) { // �丸�ڵ�Ϊobject����
							cJSON_AddItemToObject(MapXpath5[Items[i].getXpath5()], Items[i].getXpath6().c_str(), cJSON_CreateString(Items[i].getXstringShortValue().c_str())); // ����item���뵽�����
						}
						else if (MapXpath5[Items[i].getXpath5()]->type == cJSON_Array) { // �丸�ڵ�Ϊarray����
							cJSON_AddItemToArray(MapXpath5[Items[i].getXpath5()], cJSON_CreateString(Items[i].getXstringShortValue().c_str()));
						}
					}
					if (Items[i].getXitemPrimitiveType() == "b") { // boolean������Ϊ��Ŀ¼���ӽڵ�
						if (MapXpath5[Items[i].getXpath5()]->type == cJSON_Object) { // �丸�ڵ�Ϊobject����
							cJSON_AddItemToObject(MapXpath5[Items[i].getXpath5()], Items[i].getXpath6().c_str(), cJSON_CreateBool(Items[i].getXbooleanValue())); // ����item���뵽�����
						}
						else if (MapXpath5[Items[i].getXpath5()]->type == cJSON_Array) { // �丸�ڵ�Ϊarray����
							cJSON_AddItemToArray(MapXpath5[Items[i].getXpath5()], cJSON_CreateBool(Items[i].getXbooleanValue()));
						}
					}
				}
			}

			if (j == 7) { // ����xpath7
				// ����item�����ʹ�����Ӧ���
				if (Items[i].getXpath7() != "") // ��֤��item���丸�ڵ���ӽ��
				{
					if (Items[i].getXitemType() == "o") { // objec������Ϊ��Ŀ¼���ӽڵ�
						cJSON* objectItem = cJSON_CreateObject();
						if (MapXpath6[Items[i].getXpath6()]->type == cJSON_Object) { // �丸�ڵ�Ϊobject����
							cJSON_AddItemToObject(MapXpath6[Items[i].getXpath6()], Items[i].getXpath7().c_str(), objectItem); // ���ö�����뵽�����
						}
						else if (MapXpath6[Items[i].getXpath6()]->type == cJSON_Array) { // �丸�ڵ�Ϊarray����
							cJSON_AddItemToArray(MapXpath6[Items[i].getXpath6()], objectItem);
						}

					}
					if (Items[i].getXitemType() == "a") { // arrray������Ϊ��Ŀ¼���ӽڵ�
						cJSON* arrayItem = cJSON_CreateArray();
						if (MapXpath6[Items[i].getXpath6()]->type == cJSON_Object) { // �丸�ڵ�Ϊobject����
							cJSON_AddItemToObject(MapXpath6[Items[i].getXpath6()], Items[i].getXpath7().c_str(), arrayItem); // ����������뵽�����
						}
						else if (MapXpath6[Items[i].getXpath6()]->type == cJSON_Array) { // �丸�ڵ�Ϊarray����
							cJSON_AddItemToArray(MapXpath6[Items[i].getXpath6()], arrayItem);
						}

					}
					if (Items[i].getXitemPrimitiveType() == "n") { // number������Ϊ��Ŀ¼���ӽڵ�
						if (MapXpath6[Items[i].getXpath6()]->type == cJSON_Object) { // �丸�ڵ�Ϊobject����
							cJSON_AddItemToObject(MapXpath6[Items[i].getXpath6()], Items[i].getXpath7().c_str(), cJSON_CreateNumber(Items[i].getXnumberValue())); // ����item���뵽�����
						}
						else if (MapXpath6[Items[i].getXpath6()]->type == cJSON_Array) { // �丸�ڵ�Ϊarray����
							cJSON_AddItemToArray(MapXpath6[Items[i].getXpath6()], cJSON_CreateNumber(Items[i].getXnumberValue()));
						}
					}
					if (Items[i].getXitemPrimitiveType() == "s") { // string������Ϊ��Ŀ¼���ӽڵ�
						if (MapXpath6[Items[i].getXpath6()]->type == cJSON_Object) { // �丸�ڵ�Ϊobject����
							cJSON_AddItemToObject(MapXpath6[Items[i].getXpath6()], Items[i].getXpath7().c_str(), cJSON_CreateString(Items[i].getXstringShortValue().c_str())); // ����item���뵽�����
						}
						else if (MapXpath6[Items[i].getXpath6()]->type == cJSON_Array) { // �丸�ڵ�Ϊarray����
							cJSON_AddItemToArray(MapXpath6[Items[i].getXpath6()], cJSON_CreateString(Items[i].getXstringShortValue().c_str()));
						}
					}
					if (Items[i].getXitemPrimitiveType() == "b") { // boolean������Ϊ��Ŀ¼���ӽڵ�
						if (MapXpath6[Items[i].getXpath6()]->type == cJSON_Object) { // �丸�ڵ�Ϊobject����
							cJSON_AddItemToObject(MapXpath6[Items[i].getXpath5()], Items[i].getXpath7().c_str(), cJSON_CreateBool(Items[i].getXbooleanValue())); // ����item���뵽�����
						}
						else if (MapXpath6[Items[i].getXpath6()]->type == cJSON_Array) { // �丸�ڵ�Ϊarray����
							cJSON_AddItemToArray(MapXpath6[Items[i].getXpath6()], cJSON_CreateBool(Items[i].getXbooleanValue()));
						}
					}
				}
			}
		}
	}
	char* cPrint = cJSON_Print(MapXpath0["root"]);
	char* cPrintUnformatted = cJSON_PrintUnformatted(MapXpath0["root"]);
	printf("cJSON_Print��\n%s\n", cPrint);		// cJSON_Print��������ʽ����
	printf("cJSON_PrintUnformatted��\n%s\n", cPrintUnformatted);	// cJSON_PrintUnformatted��û������ʽ����
	return cPrintUnformatted;
}


string DataConfigService::saveData(const AddDataConfigDTO::Wrapper& dto) {
	//�洢���ݵ�cms_appndict����
	//����ѩ���㷨�����ֵ�id
	SnowFlake snowflake(16, 16);
	uint64_t id = snowflake.nextId();
	string xid = to_string(id);
	//��ȡ����ʱ��
	SimpleDateTimeFormat datetime;
	string xcreateTime = datetime.format();
	//��װxsequence
	string createTime = datetime.format("%Y%m%d%H%M%S");
	string xsequence = createTime + xid;
	// ��װDictDO����
	DictDO dictdata;
	dictdata.setXid(xid);
	dictdata.setXcreateTime(xcreateTime);
	dictdata.setXsequence(xsequence);
	dictdata.setXupdateTime(xcreateTime);          // ����ʱ��Ϊ��ǰ����ʱ��
	ZO_STAR_DOMAIN_DTO_TO_DO(dictdata, dto, Xalias, xalias, Xdescription, xdescription, Xname, xname, XappId, xappId)
		// ִ���������
		DataConfigDAO dao;
	dao.insertDict(dictdata);
	// �洢���ݵ�cms_appdictitem����
	// ��װItemDO����
	// ��ǰ�˴�������allitems���ݽ��н������洢��cms_appdictitem����
	//��allitems���ݽ��н�����json��ʽ��
	string allitems = dto->allitems.getValue("");
	cJSON* root = cJSON_Parse(allitems.c_str());

	vector<string> v;
	AnalyzeJson(root, v);
	// ������AnalyzeJson������flag��Ϊ1,�Ա��ٴε���ʱ���Լ���������������
	flag = 1;
	cJSON_Delete(root);  // �ͷŵ�root
	cout << "----------------------------" << endl;
	for (int i = 0; i < Items.size(); i++)
	{
		cout << Items[i].getXpath0() << "/" << Items[i].getXpath1() << "/" << Items[i].getXpath2() << "/" << Items[i].getXpath3() << "/" << Items[i].getXpath4() << endl;
	}
	//������������ӹ���ֵ
	for (int i = 0; i < Items.size(); i++)
	{
		//����ѩ���㷨����itemid
		uint64_t itemid = snowflake.nextId();
		string xitemid = to_string(itemid);
		//��װxsequence
		xsequence = createTime + xitemid;
		//��װ��������
		Items[i].setXid(xitemid);
		Items[i].setXcreateTime(xcreateTime);
		Items[i].setXsequence(xsequence);
		Items[i].setXupdateTime(xcreateTime);
		Items[i].setXappId(dto->xappId.getValue(""));
		Items[i].setXbundle(xid);
	}

	// ִ���������
	dao.insertItem(Items);

	//���vector����
	Items.clear();
	return xid;
}

bool DataConfigService::updateData(const ModifyDataConfigDTO::Wrapper& dto) {
	//�����������ޣ�����������ݣ�ֻ�ð�ԭ������ɾ�������²�������
	//��ִ�����ݵ�ɾ��,ִ��ɾ��ǰ�Ȼ�ȡ��appId
	//appIdͨ����ѯ���ݿ�õ�
	DataConfigDAO dao;
	list<DictDO> l;
	l = dao.selectDictByXid(dto->xid);
	auto it = l.begin();
	string xappId = it->getXappId();
	dao.deleteById(dto->xid);

	//��ִ�����ݵĲ���
	//�洢���ݵ�cms_appndict����
	SnowFlake snowflake(16, 16);
	//��ȡ����ʱ��
	SimpleDateTimeFormat datetime;
	string xcreateTime = datetime.format();
	//��װxsequence
	string createTime = datetime.format("%Y%m%d%H%M%S");
	string xsequence = createTime + dto->xid;
	// ��װDictDO����
	DictDO dictdata;
	dictdata.setXid(dto->xid);
	dictdata.setXcreateTime(xcreateTime);
	dictdata.setXsequence(xsequence);
	dictdata.setXupdateTime(xcreateTime);
	dictdata.setXappId(xappId);
	// ����ʱ��Ϊ��ǰ����ʱ��
	ZO_STAR_DOMAIN_DTO_TO_DO(dictdata, dto, Xalias, xalias, Xdescription, xdescription, Xname, xname)
		// ִ���������
		dao.insertDict(dictdata);
	// �洢���ݵ�cms_appdictitem����
	// ��װItemDO����
	// ��ǰ�˴�������allitems���ݽ��н������洢��cms_appdictitem����
	//��allitems���ݽ��н�����json��ʽ��
	string allitems = dto->allitems.getValue("");
	cJSON* root = cJSON_Parse(allitems.c_str());

	vector<string> v;
	AnalyzeJson(root, v);
	// ������AnalyzeJson������flag��Ϊ1,�Ա��ٴε���ʱ���Լ���������������
	flag = 1;
	cJSON_Delete(root);  // �ͷŵ�root
	cout << "----------------------------" << endl;
	for (int i = 0; i < Items.size(); i++)
	{
		cout << Items[i].getXpath0() << "/" << Items[i].getXpath1() << "/" << Items[i].getXpath2() << "/" << Items[i].getXpath3() << "/" << Items[i].getXpath4() << endl;
	}
	//������������ӹ���ֵ
	for (int i = 0; i < Items.size(); i++)
	{
		//����ѩ���㷨����itemid
		uint64_t itemid = snowflake.nextId();
		string xitemid = to_string(itemid);
		//��װxsequence
		xsequence = createTime + xitemid;
		//��װ��������
		Items[i].setXid(xitemid);
		Items[i].setXcreateTime(xcreateTime);
		Items[i].setXsequence(xsequence);
		Items[i].setXupdateTime(xcreateTime);
		Items[i].setXappId(xappId);
		Items[i].setXbundle(dto->xid);
	}

	// ִ���������
	dao.insertItem(Items);

	//���vector����
	Items.clear();
	return true;
}

DataConfigVO::Wrapper DataConfigService::queryByXid(const string& xid) {
	// �������ض���
	auto dict = DataConfigVO::createShared();

	DataConfigDAO dao;
	// ��ѯ�ֵ���Ϣ
	list<DictDO> l;
	l = dao.selectDictByXid(xid);
	auto it = l.begin();
	string xname = it->getXname();
	string xalias = it->getXalias();
	string xdescription = it->getXdescription();

	// ��ѯ����item����
	list<ItemDO> result = dao.selectItemByXid(xid);
	//��listת��Ϊvector
	std::copy(result.begin(), result.end(), std::back_inserter(Items));
	//��װjson����
	string allitems = CreateJson(Items);

	// ��װDTO
	dict->xid = xid;
	dict->xname = xname;
	dict->xalias = xalias;
	dict->xdescription = xdescription;
	dict->allitems = allitems;

	//���vector������map����
	Items.clear();
	MapXpath0.clear();
	MapXpath1.clear();
	MapXpath2.clear();
	MapXpath3.clear();
	MapXpath4.clear();
	MapXpath5.clear();
	MapXpath6.clear();
	return dict;
}