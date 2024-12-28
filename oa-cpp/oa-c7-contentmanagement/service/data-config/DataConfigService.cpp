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
// 用于保存其父节点信息，由于其父节点可能重复，而每个xpath路径不能重复，故为每个xpath设置一个映射
map<string, cJSON*> MapXpath0, MapXpath1, MapXpath2, MapXpath3, MapXpath4, MapXpath5, MapXpath6;

//解析json字符串并初始化每个item，并将每个item添加到vector容器中
void AnalyzeJson(cJSON* root, vector<string> path) {
	if (root == NULL) return;

	if (flag == 1) {  //用于保存根结点，即root结点，利用flag保证只初始化一个根结点
		cout << "/" << endl;
		flag = 0;
		ItemDO item1;
		item1.setXpath0("");
		if (root->type == cJSON_Object) { // 根结点为object类型
			item1.setXitemType("o");
			Items.push_back(item1);
		}
		else if (root->type == cJSON_Array) { // 根结点为array类型
			item1.setXitemType("a");
			Items.push_back(item1);
		}
	}
	// 如果item是对象或数组，将其键名添加到路径中
	if ((root->type == cJSON_Object || root->type == cJSON_Array) && root->string != NULL) {
		path.push_back(root->string);
	}

	for (int j = 0; j < cJSON_GetArraySize(root); j++) {
		//如果是数组，自动加上数组下标路径
		if (root->type == cJSON_Array) {
			path.push_back(to_string(j));
		}
		cJSON* item = cJSON_GetArrayItem(root, j);
		if (item->type == cJSON_Object) {//对象
			if (item != NULL) {
				ItemDO item1;
				item1.setXitemType("o");
				// 把路径加进去
				for (size_t i = 0; i < path.size(); ++i) { // 我真是个天才
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

				//当前对象可能有名字，有名字需要把名字加到路径中
				if (item->string)//可能存在对象名为NULL{"key":"value"}对象名为NULL   )
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
				//没名字不需要加到路径中
				else {
					Items.push_back(item1);
				}

				cout << endl;
				AnalyzeJson(item, path);
				//在递归调用AnalyzeJson后，如果item是数组类型，须将path弹出一个，因为数组路径会包含下标
				if (root->type == cJSON_Array) {
					path.pop_back();
				}
			}
		}
		else if (item->type == cJSON_Array) {
			if (item != NULL) {//数组
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
			if (item != NULL) {//键值对，注意键类型
				ItemDO item1;
				//添加路径
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
				if (item->type == cJSON_String && item->string != NULL) // string类型	
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
				if (item->type == cJSON_Number && item->string != NULL) // 数值类型
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
				if ((item->type == cJSON_True || item->type == cJSON_False) && item->string != NULL) // boll类型
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
				//数组里键为空的情况
				if (item->type == cJSON_String && item->string == NULL) // string类型
				{
					cout << ":" << item->valuestring << endl;
					item1.setXitemPrimitiveType("s");
					item1.setXitemStringValueType("s");
					item1.setXstringShortValue(item->valuestring);

					Items.push_back(item1);
					//由于数组类型自动加了下标路径，如果该item在数组里，则在添加完路径后需要弹出
					path.pop_back();
				}
				if (item->type == cJSON_Number && item->string == NULL) // 数值类型
				{
					cout << ":" << item->valuedouble << endl;
					item1.setXitemPrimitiveType("n");
					item1.setXnumberValue(item->valuedouble);

					Items.push_back(item1);
					path.pop_back();
				}
				if ((item->type == cJSON_True || item->type == cJSON_False) && item->string == NULL) // 数值类型
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
	//遍历vec容器，组装cjson数据
	//首先创建根结点，先遍历所有items找到根结点，判断其类型，初始化根结点
	for (int i = 0; i < Items.size(); i++) {
		if (Items[i].getXpath0() == "") {
			if (Items[i].getXitemType() == "a") {
				cJSON* root = cJSON_CreateArray(); // 根结点类型为array
				MapXpath0.insert(make_pair("root", root)); // 将根结点插入到Map容器中
			}
			else if (Items[i].getXitemType() == "o")
			{
				cJSON* root = cJSON_CreateObject(); // 根结点类型为object
				MapXpath0.insert(make_pair("root", root)); // 将根结点插入到Map容器中
			}
		}
	}

	//遍历所有路径和所有item
	for (int j = 0; j <= 7; j++) {
		for (int i = 0; i < Items.size(); i++) {
			if (j == 0) { // 访问xpath0
				// 根据item的类型创建对应结点
				if (Items[i].getXpath1() == "" && (Items[i].getXpath0() != "")) // 保证该item是其父节点的子结点
				{
					if (Items[i].getXitemType() == "o") { // objec类型且为根目录的子节点
						cJSON* objectItem = cJSON_CreateObject();
						MapXpath0.insert(make_pair(Items[i].getXpath0(), objectItem)); // 保存该结点路径
						if (MapXpath0["root"]->type == cJSON_Object) { // 其父节点为object类型
							cJSON_AddItemToObject(MapXpath0["root"], Items[i].getXpath0().c_str(), objectItem); // 将该对象插入到根结点
						}
						else if (MapXpath0["root"]->type == cJSON_Array) { // 其父节点为array类型
							cJSON_AddItemToArray(MapXpath0["root"], objectItem);
						}
					}
					if (Items[i].getXitemType() == "a") { // arrray类型且为根目录的子节点
						cJSON* arrayItem = cJSON_CreateArray();
						MapXpath0.insert(make_pair(Items[i].getXpath0(), arrayItem)); // 保存该结点路径
						if (MapXpath0["root"]->type == cJSON_Object) { // 其父节点为object类型
							cJSON_AddItemToObject(MapXpath0["root"], Items[i].getXpath0().c_str(), arrayItem); // 将该数组插入到根结点
						}
						else if (MapXpath0["root"]->type == cJSON_Array) { // 其父节点为array类型
							cJSON_AddItemToArray(MapXpath0["root"], arrayItem);
						}

					}
					if (Items[i].getXitemPrimitiveType() == "n") { // number类型且为根目录的子节点
						if (MapXpath0["root"]->type == cJSON_Object) { // 其父节点为object类型
							cJSON_AddItemToObject(MapXpath0["root"], Items[i].getXpath0().c_str(), cJSON_CreateNumber(Items[i].getXnumberValue())); // 将该item插入到根结点
						}
						else if (MapXpath0["root"]->type == cJSON_Array) { // 其父节点为array类型
							cJSON_AddItemToArray(MapXpath0["root"], cJSON_CreateNumber(Items[i].getXnumberValue()));
						}
					}
					if (Items[i].getXitemPrimitiveType() == "s") { // string类型且为根目录的子节点
						if (MapXpath0["root"]->type == cJSON_Object) { // 其父节点为object类型
							cJSON_AddItemToObject(MapXpath0["root"], Items[i].getXpath0().c_str(), cJSON_CreateString(Items[i].getXstringShortValue().c_str())); // 将该item插入到根结点
						}
						else if (MapXpath0["root"]->type == cJSON_Array) { // 其父节点为array类型
							cJSON_AddItemToArray(MapXpath0["root"], cJSON_CreateString(Items[i].getXstringShortValue().c_str()));
						}
					}
					if (Items[i].getXitemPrimitiveType() == "b") { // boolean类型且为根目录的子节点
						if (MapXpath0["root"]->type == cJSON_Object) { // 其父节点为object类型
							cJSON_AddItemToObject(MapXpath0["root"], Items[i].getXpath0().c_str(), cJSON_CreateBool(Items[i].getXbooleanValue())); // 将该item插入到根结点
						}
						else if (MapXpath0["root"]->type == cJSON_Array) { // 其父节点为array类型
							cJSON_AddItemToArray(MapXpath0["root"], cJSON_CreateBool(Items[i].getXbooleanValue()));
						}
					}
				}
			}

			if (j == 1) { // 访问xpath1
				// 根据item的类型创建对应结点
				if (Items[i].getXpath2() == "" && (Items[i].getXpath1() != "")) // 保证该item是其父节点的子结点
				{
					if (Items[i].getXitemType() == "o") { // objec类型且为根目录的子节点
						cJSON* objectItem = cJSON_CreateObject();
						MapXpath1.insert(make_pair(Items[i].getXpath1(), objectItem)); // 保存该结点路径
						if (MapXpath0[Items[i].getXpath0()]->type == cJSON_Object) { // 其父节点为object类型
							cJSON_AddItemToObject(MapXpath0[Items[i].getXpath0()], Items[i].getXpath1().c_str(), objectItem); // 将该对象插入到根结点
						}
						else if (MapXpath0[Items[i].getXpath0()]->type == cJSON_Array) { // 其父节点为array类型
							cJSON_AddItemToArray(MapXpath0[Items[i].getXpath0()], objectItem);
						}

					}
					if (Items[i].getXitemType() == "a") { // arrray类型且为根目录的子节点
						cJSON* arrayItem = cJSON_CreateArray();
						MapXpath1.insert(make_pair(Items[i].getXpath1(), arrayItem)); // 保存该结点路径
						if (MapXpath0[Items[i].getXpath0()]->type == cJSON_Object) { // 其父节点为object类型
							cJSON_AddItemToObject(MapXpath0[Items[i].getXpath0()], Items[i].getXpath1().c_str(), arrayItem); // 将该数组插入到根结点
						}
						else if (MapXpath0[Items[i].getXpath0()]->type == cJSON_Array) { // 其父节点为array类型
							cJSON_AddItemToArray(MapXpath0[Items[i].getXpath0()], arrayItem);
						}

					}
					if (Items[i].getXitemPrimitiveType() == "n") { // number类型且为根目录的子节点
						if (MapXpath0[Items[i].getXpath0()]->type == cJSON_Object) { // 其父节点为object类型
							cJSON_AddItemToObject(MapXpath0[Items[i].getXpath0()], Items[i].getXpath1().c_str(), cJSON_CreateNumber(Items[i].getXnumberValue())); // 将该item插入到根结点
						}
						else if (MapXpath0[Items[i].getXpath0()]->type == cJSON_Array) { // 其父节点为array类型
							cJSON_AddItemToArray(MapXpath0[Items[i].getXpath0()], cJSON_CreateNumber(Items[i].getXnumberValue()));
						}
					}
					if (Items[i].getXitemPrimitiveType() == "s") { // string类型且为根目录的子节点
						if (MapXpath0[Items[i].getXpath0()]->type == cJSON_Object) { // 其父节点为object类型
							cJSON_AddItemToObject(MapXpath0[Items[i].getXpath0()], Items[i].getXpath1().c_str(), cJSON_CreateString(Items[i].getXstringShortValue().c_str())); // 将该item插入到根结点
						}
						else if (MapXpath0[Items[i].getXpath0()]->type == cJSON_Array) { // 其父节点为array类型
							cJSON_AddItemToArray(MapXpath0[Items[i].getXpath0()], cJSON_CreateString(Items[i].getXstringShortValue().c_str()));
						}
					}
					if (Items[i].getXitemPrimitiveType() == "b") { // boolean类型且为根目录的子节点
						if (MapXpath0[Items[i].getXpath0()]->type == cJSON_Object) { // 其父节点为object类型
							cJSON_AddItemToObject(MapXpath0[Items[i].getXpath0()], Items[i].getXpath1().c_str(), cJSON_CreateBool(Items[i].getXbooleanValue())); // 将该item插入到根结点
						}
						else if (MapXpath0[Items[i].getXpath0()]->type == cJSON_Array) { // 其父节点为array类型
							cJSON_AddItemToArray(MapXpath0[Items[i].getXpath0()], cJSON_CreateBool(Items[i].getXbooleanValue()));
						}
					}
				}
			}

			if (j == 2) { // 访问xpath2
				// 根据item的类型创建对应结点
				if (Items[i].getXpath3() == "" && (Items[i].getXpath2() != "")) // 保证该item是其父节点的子结点
				{
					if (Items[i].getXitemType() == "o") { // objec类型且为根目录的子节点
						cJSON* objectItem = cJSON_CreateObject();
						MapXpath2.insert(make_pair(Items[i].getXpath2(), objectItem)); // 保存该结点路径
						if (MapXpath1[Items[i].getXpath1()]->type == cJSON_Object) { // 其父节点为object类型
							cJSON_AddItemToObject(MapXpath1[Items[i].getXpath1()], Items[i].getXpath2().c_str(), objectItem); // 将该对象插入到根结点
						}
						else if (MapXpath1[Items[i].getXpath1()]->type == cJSON_Array) { // 其父节点为array类型
							cJSON_AddItemToArray(MapXpath1[Items[i].getXpath1()], objectItem);
						}

					}
					if (Items[i].getXitemType() == "a") { // arrray类型且为根目录的子节点
						cJSON* arrayItem = cJSON_CreateArray();
						MapXpath2.insert(make_pair(Items[i].getXpath2(), arrayItem)); // 保存该结点路径
						if (MapXpath1[Items[i].getXpath1()]->type == cJSON_Object) { // 其父节点为object类型
							cJSON_AddItemToObject(MapXpath1[Items[i].getXpath1()], Items[i].getXpath2().c_str(), arrayItem); // 将该数组插入到根结点
						}
						else if (MapXpath1[Items[i].getXpath1()]->type == cJSON_Array) { // 其父节点为array类型
							cJSON_AddItemToArray(MapXpath1[Items[i].getXpath1()], arrayItem);
						}

					}
					if (Items[i].getXitemPrimitiveType() == "n") { // number类型且为根目录的子节点
						if (MapXpath1[Items[i].getXpath1()]->type == cJSON_Object) { // 其父节点为object类型
							cJSON_AddItemToObject(MapXpath1[Items[i].getXpath1()], Items[i].getXpath2().c_str(), cJSON_CreateNumber(Items[i].getXnumberValue())); // 将该item插入到根结点
						}
						else if (MapXpath1[Items[i].getXpath1()]->type == cJSON_Array) { // 其父节点为array类型
							cJSON_AddItemToArray(MapXpath1[Items[i].getXpath1()], cJSON_CreateNumber(Items[i].getXnumberValue()));
						}
					}
					if (Items[i].getXitemPrimitiveType() == "s") { // string类型且为根目录的子节点
						if (MapXpath1[Items[i].getXpath1()]->type == cJSON_Object) { // 其父节点为object类型
							cJSON_AddItemToObject(MapXpath1[Items[i].getXpath1()], Items[i].getXpath2().c_str(), cJSON_CreateString(Items[i].getXstringShortValue().c_str())); // 将该item插入到根结点
						}
						else if (MapXpath1[Items[i].getXpath1()]->type == cJSON_Array) { // 其父节点为array类型
							cJSON_AddItemToArray(MapXpath1[Items[i].getXpath1()], cJSON_CreateString(Items[i].getXstringShortValue().c_str()));
						}
					}
					if (Items[i].getXitemPrimitiveType() == "b") { // boolean类型且为根目录的子节点
						if (MapXpath1[Items[i].getXpath1()]->type == cJSON_Object) { // 其父节点为object类型
							cJSON_AddItemToObject(MapXpath1[Items[i].getXpath1()], Items[i].getXpath2().c_str(), cJSON_CreateBool(Items[i].getXbooleanValue())); // 将该item插入到根结点
						}
						else if (MapXpath1[Items[i].getXpath1()]->type == cJSON_Array) { // 其父节点为array类型
							cJSON_AddItemToArray(MapXpath1[Items[i].getXpath1()], cJSON_CreateBool(Items[i].getXbooleanValue()));
						}
					}
				}
			}

			if (j == 3) { // 访问xpath3
				// 根据item的类型创建对应结点
				if (Items[i].getXpath4() == "" && (Items[i].getXpath3() != "")) // 保证该item是其父节点的子结点
				{
					if (Items[i].getXitemType() == "o") { // objec类型且为根目录的子节点
						cJSON* objectItem = cJSON_CreateObject();
						MapXpath3.insert(make_pair(Items[i].getXpath3(), objectItem)); // 保存该结点路径
						if (MapXpath2[Items[i].getXpath2()]->type == cJSON_Object) { // 其父节点为object类型
							cJSON_AddItemToObject(MapXpath2[Items[i].getXpath2()], Items[i].getXpath3().c_str(), objectItem); // 将该对象插入到根结点
						}
						else if (MapXpath2[Items[i].getXpath2()]->type == cJSON_Array) { // 其父节点为array类型
							cJSON_AddItemToArray(MapXpath2[Items[i].getXpath2()], objectItem);
						}

					}
					if (Items[i].getXitemType() == "a") { // arrray类型且为根目录的子节点
						cJSON* arrayItem = cJSON_CreateArray();
						MapXpath3.insert(make_pair(Items[i].getXpath3(), arrayItem)); // 保存该结点路径
						if (MapXpath2[Items[i].getXpath2()]->type == cJSON_Object) { // 其父节点为object类型
							cJSON_AddItemToObject(MapXpath2[Items[i].getXpath2()], Items[i].getXpath3().c_str(), arrayItem); // 将该数组插入到根结点
						}
						else if (MapXpath2[Items[i].getXpath2()]->type == cJSON_Array) { // 其父节点为array类型
							cJSON_AddItemToArray(MapXpath2[Items[i].getXpath2()], arrayItem);
						}

					}
					if (Items[i].getXitemPrimitiveType() == "n") { // number类型且为根目录的子节点
						if (MapXpath2[Items[i].getXpath2()]->type == cJSON_Object) { // 其父节点为object类型
							cJSON_AddItemToObject(MapXpath2[Items[i].getXpath2()], Items[i].getXpath3().c_str(), cJSON_CreateNumber(Items[i].getXnumberValue())); // 将该item插入到根结点
						}
						else if (MapXpath2[Items[i].getXpath2()]->type == cJSON_Array) { // 其父节点为array类型
							cJSON_AddItemToArray(MapXpath2[Items[i].getXpath2()], cJSON_CreateNumber(Items[i].getXnumberValue()));
						}
					}
					if (Items[i].getXitemPrimitiveType() == "s") { // string类型且为根目录的子节点
						if (MapXpath2[Items[i].getXpath2()]->type == cJSON_Object) { // 其父节点为object类型
							cJSON_AddItemToObject(MapXpath2[Items[i].getXpath2()], Items[i].getXpath3().c_str(), cJSON_CreateString(Items[i].getXstringShortValue().c_str())); // 将该item插入到根结点
						}
						else if (MapXpath2[Items[i].getXpath2()]->type == cJSON_Array) { // 其父节点为array类型
							cJSON_AddItemToArray(MapXpath2[Items[i].getXpath2()], cJSON_CreateString(Items[i].getXstringShortValue().c_str()));
						}
					}
					if (Items[i].getXitemPrimitiveType() == "b") { // boolean类型且为根目录的子节点
						if (MapXpath2[Items[i].getXpath2()]->type == cJSON_Object) { // 其父节点为object类型
							cJSON_AddItemToObject(MapXpath2[Items[i].getXpath2()], Items[i].getXpath3().c_str(), cJSON_CreateBool(Items[i].getXbooleanValue())); // 将该item插入到根结点
						}
						else if (MapXpath2[Items[i].getXpath2()]->type == cJSON_Array) { // 其父节点为array类型
							cJSON_AddItemToArray(MapXpath2[Items[i].getXpath2()], cJSON_CreateBool(Items[i].getXbooleanValue()));
						}
					}
				}
			}

			if (j == 4) { // 访问xpath4
				// 根据item的类型创建对应结点
				if (Items[i].getXpath5() == "" && (Items[i].getXpath4() != "")) // 保证该item是其父节点的子结点
				{
					if (Items[i].getXitemType() == "o") { // objec类型且为根目录的子节点
						cJSON* objectItem = cJSON_CreateObject();
						MapXpath4.insert(make_pair(Items[i].getXpath4(), objectItem)); // 保存该结点路径
						if (MapXpath3[Items[i].getXpath3()]->type == cJSON_Object) { // 其父节点为object类型
							cJSON_AddItemToObject(MapXpath3[Items[i].getXpath3()], Items[i].getXpath4().c_str(), objectItem); // 将该对象插入到根结点
						}
						else if (MapXpath3[Items[i].getXpath3()]->type == cJSON_Array) { // 其父节点为array类型
							cJSON_AddItemToArray(MapXpath3[Items[i].getXpath3()], objectItem);
						}

					}
					if (Items[i].getXitemType() == "a") { // arrray类型且为根目录的子节点
						cJSON* arrayItem = cJSON_CreateArray();
						MapXpath4.insert(make_pair(Items[i].getXpath4(), arrayItem)); // 保存该结点路径
						if (MapXpath3[Items[i].getXpath3()]->type == cJSON_Object) { // 其父节点为object类型
							cJSON_AddItemToObject(MapXpath3[Items[i].getXpath3()], Items[i].getXpath4().c_str(), arrayItem); // 将该数组插入到根结点
						}
						else if (MapXpath3[Items[i].getXpath3()]->type == cJSON_Array) { // 其父节点为array类型
							cJSON_AddItemToArray(MapXpath3[Items[i].getXpath3()], arrayItem);
						}

					}
					if (Items[i].getXitemPrimitiveType() == "n") { // number类型且为根目录的子节点
						if (MapXpath3[Items[i].getXpath3()]->type == cJSON_Object) { // 其父节点为object类型
							cJSON_AddItemToObject(MapXpath3[Items[i].getXpath3()], Items[i].getXpath4().c_str(), cJSON_CreateNumber(Items[i].getXnumberValue())); // 将该item插入到根结点
						}
						else if (MapXpath3[Items[i].getXpath3()]->type == cJSON_Array) { // 其父节点为array类型
							cJSON_AddItemToArray(MapXpath3[Items[i].getXpath3()], cJSON_CreateNumber(Items[i].getXnumberValue()));
						}
					}
					if (Items[i].getXitemPrimitiveType() == "s") { // string类型且为根目录的子节点
						if (MapXpath3[Items[i].getXpath3()]->type == cJSON_Object) { // 其父节点为object类型
							cJSON_AddItemToObject(MapXpath3[Items[i].getXpath3()], Items[i].getXpath4().c_str(), cJSON_CreateString(Items[i].getXstringShortValue().c_str())); // 将该item插入到根结点
						}
						else if (MapXpath3[Items[i].getXpath3()]->type == cJSON_Array) { // 其父节点为array类型
							cJSON_AddItemToArray(MapXpath3[Items[i].getXpath3()], cJSON_CreateString(Items[i].getXstringShortValue().c_str()));
						}
					}
					if (Items[i].getXitemPrimitiveType() == "b") { // boolean类型且为根目录的子节点
						if (MapXpath3[Items[i].getXpath3()]->type == cJSON_Object) { // 其父节点为object类型
							cJSON_AddItemToObject(MapXpath3[Items[i].getXpath3()], Items[i].getXpath4().c_str(), cJSON_CreateBool(Items[i].getXbooleanValue())); // 将该item插入到根结点
						}
						else if (MapXpath3[Items[i].getXpath3()]->type == cJSON_Array) { // 其父节点为array类型
							cJSON_AddItemToArray(MapXpath3[Items[i].getXpath3()], cJSON_CreateBool(Items[i].getXbooleanValue()));
						}
					}
				}
			}

			if (j == 5) { // 访问xpath5
				// 根据item的类型创建对应结点
				if (Items[i].getXpath6() == "" && (Items[i].getXpath5() != "")) // 保证该item是其父节点的子结点
				{
					if (Items[i].getXitemType() == "o") { // objec类型且为根目录的子节点
						cJSON* objectItem = cJSON_CreateObject();
						MapXpath5.insert(make_pair(Items[i].getXpath5(), objectItem)); // 保存该结点路径
						if (MapXpath4[Items[i].getXpath4()]->type == cJSON_Object) { // 其父节点为object类型
							cJSON_AddItemToObject(MapXpath4[Items[i].getXpath4()], Items[i].getXpath5().c_str(), objectItem); // 将该对象插入到根结点
						}
						else if (MapXpath4[Items[i].getXpath4()]->type == cJSON_Array) { // 其父节点为array类型
							cJSON_AddItemToArray(MapXpath4[Items[i].getXpath4()], objectItem);
						}

					}
					if (Items[i].getXitemType() == "a") { // arrray类型且为根目录的子节点
						cJSON* arrayItem = cJSON_CreateArray();
						MapXpath5.insert(make_pair(Items[i].getXpath5(), arrayItem)); // 保存该结点路径
						if (MapXpath4[Items[i].getXpath4()]->type == cJSON_Object) { // 其父节点为object类型
							cJSON_AddItemToObject(MapXpath4[Items[i].getXpath4()], Items[i].getXpath5().c_str(), arrayItem); // 将该数组插入到根结点
						}
						else if (MapXpath4[Items[i].getXpath4()]->type == cJSON_Array) { // 其父节点为array类型
							cJSON_AddItemToArray(MapXpath4[Items[i].getXpath4()], arrayItem);
						}

					}
					if (Items[i].getXitemPrimitiveType() == "n") { // number类型且为根目录的子节点
						if (MapXpath4[Items[i].getXpath4()]->type == cJSON_Object) { // 其父节点为object类型
							cJSON_AddItemToObject(MapXpath4[Items[i].getXpath4()], Items[i].getXpath5().c_str(), cJSON_CreateNumber(Items[i].getXnumberValue())); // 将该item插入到根结点
						}
						else if (MapXpath4[Items[i].getXpath4()]->type == cJSON_Array) { // 其父节点为array类型
							cJSON_AddItemToArray(MapXpath4[Items[i].getXpath4()], cJSON_CreateNumber(Items[i].getXnumberValue()));
						}
					}
					if (Items[i].getXitemPrimitiveType() == "s") { // string类型且为根目录的子节点
						if (MapXpath4[Items[i].getXpath4()]->type == cJSON_Object) { // 其父节点为object类型
							cJSON_AddItemToObject(MapXpath4[Items[i].getXpath4()], Items[i].getXpath5().c_str(), cJSON_CreateString(Items[i].getXstringShortValue().c_str())); // 将该item插入到根结点
						}
						else if (MapXpath4[Items[i].getXpath4()]->type == cJSON_Array) { // 其父节点为array类型
							cJSON_AddItemToArray(MapXpath4[Items[i].getXpath4()], cJSON_CreateString(Items[i].getXstringShortValue().c_str()));
						}
					}
					if (Items[i].getXitemPrimitiveType() == "b") { // boolean类型且为根目录的子节点
						if (MapXpath4[Items[i].getXpath4()]->type == cJSON_Object) { // 其父节点为object类型
							cJSON_AddItemToObject(MapXpath4[Items[i].getXpath4()], Items[i].getXpath5().c_str(), cJSON_CreateBool(Items[i].getXbooleanValue())); // 将该item插入到根结点
						}
						else if (MapXpath4[Items[i].getXpath4()]->type == cJSON_Array) { // 其父节点为array类型
							cJSON_AddItemToArray(MapXpath4[Items[i].getXpath4()], cJSON_CreateBool(Items[i].getXbooleanValue()));
						}
					}
				}
			}

			if (j == 6) { // 访问xpath6
				// 根据item的类型创建对应结点
				if (Items[i].getXpath7() == "" && (Items[i].getXpath6() != "")) // 保证该item是其父节点的子结点
				{
					if (Items[i].getXitemType() == "o") { // objec类型且为根目录的子节点
						cJSON* objectItem = cJSON_CreateObject();
						MapXpath6.insert(make_pair(Items[i].getXpath6(), objectItem)); // 保存该结点路径
						if (MapXpath5[Items[i].getXpath5()]->type == cJSON_Object) { // 其父节点为object类型
							cJSON_AddItemToObject(MapXpath5[Items[i].getXpath5()], Items[i].getXpath6().c_str(), objectItem); // 将该对象插入到根结点
						}
						else if (MapXpath5[Items[i].getXpath5()]->type == cJSON_Array) { // 其父节点为array类型
							cJSON_AddItemToArray(MapXpath5[Items[i].getXpath5()], objectItem);
						}

					}
					if (Items[i].getXitemType() == "a") { // arrray类型且为根目录的子节点
						cJSON* arrayItem = cJSON_CreateArray();
						MapXpath6.insert(make_pair(Items[i].getXpath6(), arrayItem)); // 保存该结点路径
						if (MapXpath5[Items[i].getXpath5()]->type == cJSON_Object) { // 其父节点为object类型
							cJSON_AddItemToObject(MapXpath5[Items[i].getXpath5()], Items[i].getXpath6().c_str(), arrayItem); // 将该数组插入到根结点
						}
						else if (MapXpath5[Items[i].getXpath5()]->type == cJSON_Array) { // 其父节点为array类型
							cJSON_AddItemToArray(MapXpath5[Items[i].getXpath5()], arrayItem);
						}

					}
					if (Items[i].getXitemPrimitiveType() == "n") { // number类型且为根目录的子节点
						if (MapXpath5[Items[i].getXpath5()]->type == cJSON_Object) { // 其父节点为object类型
							cJSON_AddItemToObject(MapXpath5[Items[i].getXpath5()], Items[i].getXpath6().c_str(), cJSON_CreateNumber(Items[i].getXnumberValue())); // 将该item插入到根结点
						}
						else if (MapXpath5[Items[i].getXpath5()]->type == cJSON_Array) { // 其父节点为array类型
							cJSON_AddItemToArray(MapXpath5[Items[i].getXpath5()], cJSON_CreateNumber(Items[i].getXnumberValue()));
						}
					}
					if (Items[i].getXitemPrimitiveType() == "s") { // string类型且为根目录的子节点
						if (MapXpath5[Items[i].getXpath5()]->type == cJSON_Object) { // 其父节点为object类型
							cJSON_AddItemToObject(MapXpath5[Items[i].getXpath5()], Items[i].getXpath6().c_str(), cJSON_CreateString(Items[i].getXstringShortValue().c_str())); // 将该item插入到根结点
						}
						else if (MapXpath5[Items[i].getXpath5()]->type == cJSON_Array) { // 其父节点为array类型
							cJSON_AddItemToArray(MapXpath5[Items[i].getXpath5()], cJSON_CreateString(Items[i].getXstringShortValue().c_str()));
						}
					}
					if (Items[i].getXitemPrimitiveType() == "b") { // boolean类型且为根目录的子节点
						if (MapXpath5[Items[i].getXpath5()]->type == cJSON_Object) { // 其父节点为object类型
							cJSON_AddItemToObject(MapXpath5[Items[i].getXpath5()], Items[i].getXpath6().c_str(), cJSON_CreateBool(Items[i].getXbooleanValue())); // 将该item插入到根结点
						}
						else if (MapXpath5[Items[i].getXpath5()]->type == cJSON_Array) { // 其父节点为array类型
							cJSON_AddItemToArray(MapXpath5[Items[i].getXpath5()], cJSON_CreateBool(Items[i].getXbooleanValue()));
						}
					}
				}
			}

			if (j == 7) { // 访问xpath7
				// 根据item的类型创建对应结点
				if (Items[i].getXpath7() != "") // 保证该item是其父节点的子结点
				{
					if (Items[i].getXitemType() == "o") { // objec类型且为根目录的子节点
						cJSON* objectItem = cJSON_CreateObject();
						if (MapXpath6[Items[i].getXpath6()]->type == cJSON_Object) { // 其父节点为object类型
							cJSON_AddItemToObject(MapXpath6[Items[i].getXpath6()], Items[i].getXpath7().c_str(), objectItem); // 将该对象插入到根结点
						}
						else if (MapXpath6[Items[i].getXpath6()]->type == cJSON_Array) { // 其父节点为array类型
							cJSON_AddItemToArray(MapXpath6[Items[i].getXpath6()], objectItem);
						}

					}
					if (Items[i].getXitemType() == "a") { // arrray类型且为根目录的子节点
						cJSON* arrayItem = cJSON_CreateArray();
						if (MapXpath6[Items[i].getXpath6()]->type == cJSON_Object) { // 其父节点为object类型
							cJSON_AddItemToObject(MapXpath6[Items[i].getXpath6()], Items[i].getXpath7().c_str(), arrayItem); // 将该数组插入到根结点
						}
						else if (MapXpath6[Items[i].getXpath6()]->type == cJSON_Array) { // 其父节点为array类型
							cJSON_AddItemToArray(MapXpath6[Items[i].getXpath6()], arrayItem);
						}

					}
					if (Items[i].getXitemPrimitiveType() == "n") { // number类型且为根目录的子节点
						if (MapXpath6[Items[i].getXpath6()]->type == cJSON_Object) { // 其父节点为object类型
							cJSON_AddItemToObject(MapXpath6[Items[i].getXpath6()], Items[i].getXpath7().c_str(), cJSON_CreateNumber(Items[i].getXnumberValue())); // 将该item插入到根结点
						}
						else if (MapXpath6[Items[i].getXpath6()]->type == cJSON_Array) { // 其父节点为array类型
							cJSON_AddItemToArray(MapXpath6[Items[i].getXpath6()], cJSON_CreateNumber(Items[i].getXnumberValue()));
						}
					}
					if (Items[i].getXitemPrimitiveType() == "s") { // string类型且为根目录的子节点
						if (MapXpath6[Items[i].getXpath6()]->type == cJSON_Object) { // 其父节点为object类型
							cJSON_AddItemToObject(MapXpath6[Items[i].getXpath6()], Items[i].getXpath7().c_str(), cJSON_CreateString(Items[i].getXstringShortValue().c_str())); // 将该item插入到根结点
						}
						else if (MapXpath6[Items[i].getXpath6()]->type == cJSON_Array) { // 其父节点为array类型
							cJSON_AddItemToArray(MapXpath6[Items[i].getXpath6()], cJSON_CreateString(Items[i].getXstringShortValue().c_str()));
						}
					}
					if (Items[i].getXitemPrimitiveType() == "b") { // boolean类型且为根目录的子节点
						if (MapXpath6[Items[i].getXpath6()]->type == cJSON_Object) { // 其父节点为object类型
							cJSON_AddItemToObject(MapXpath6[Items[i].getXpath5()], Items[i].getXpath7().c_str(), cJSON_CreateBool(Items[i].getXbooleanValue())); // 将该item插入到根结点
						}
						else if (MapXpath6[Items[i].getXpath6()]->type == cJSON_Array) { // 其父节点为array类型
							cJSON_AddItemToArray(MapXpath6[Items[i].getXpath6()], cJSON_CreateBool(Items[i].getXbooleanValue()));
						}
					}
				}
			}
		}
	}
	char* cPrint = cJSON_Print(MapXpath0["root"]);
	char* cPrintUnformatted = cJSON_PrintUnformatted(MapXpath0["root"]);
	printf("cJSON_Print：\n%s\n", cPrint);		// cJSON_Print：有做格式调整
	printf("cJSON_PrintUnformatted：\n%s\n", cPrintUnformatted);	// cJSON_PrintUnformatted：没有做格式调整
	return cPrintUnformatted;
}


string DataConfigService::saveData(const AddDataConfigDTO::Wrapper& dto) {
	//存储数据到cms_appndict表中
	//利用雪花算法生成字典id
	SnowFlake snowflake(16, 16);
	uint64_t id = snowflake.nextId();
	string xid = to_string(id);
	//获取创建时间
	SimpleDateTimeFormat datetime;
	string xcreateTime = datetime.format();
	//组装xsequence
	string createTime = datetime.format("%Y%m%d%H%M%S");
	string xsequence = createTime + xid;
	// 组装DictDO数据
	DictDO dictdata;
	dictdata.setXid(xid);
	dictdata.setXcreateTime(xcreateTime);
	dictdata.setXsequence(xsequence);
	dictdata.setXupdateTime(xcreateTime);          // 更新时间为当前创建时间
	ZO_STAR_DOMAIN_DTO_TO_DO(dictdata, dto, Xalias, xalias, Xdescription, xdescription, Xname, xname, XappId, xappId)
		// 执行数据添加
		DataConfigDAO dao;
	dao.insertDict(dictdata);
	// 存储数据到cms_appdictitem表中
	// 组装ItemDO数据
	// 对前端传过来的allitems数据进行解析并存储到cms_appdictitem表中
	//对allitems数据进行解析（json格式）
	string allitems = dto->allitems.getValue("");
	cJSON* root = cJSON_Parse(allitems.c_str());

	vector<string> v;
	AnalyzeJson(root, v);
	// 调用完AnalyzeJson方法后将flag置为1,以便再次调用时可以继续保存根结点数据
	flag = 1;
	cJSON_Delete(root);  // 释放掉root
	cout << "----------------------------" << endl;
	for (int i = 0; i < Items.size(); i++)
	{
		cout << Items[i].getXpath0() << "/" << Items[i].getXpath1() << "/" << Items[i].getXpath2() << "/" << Items[i].getXpath3() << "/" << Items[i].getXpath4() << endl;
	}
	//遍历容器，添加公共值
	for (int i = 0; i < Items.size(); i++)
	{
		//利用雪花算法生成itemid
		uint64_t itemid = snowflake.nextId();
		string xitemid = to_string(itemid);
		//组装xsequence
		xsequence = createTime + xitemid;
		//组装公共数据
		Items[i].setXid(xitemid);
		Items[i].setXcreateTime(xcreateTime);
		Items[i].setXsequence(xsequence);
		Items[i].setXupdateTime(xcreateTime);
		Items[i].setXappId(dto->xappId.getValue(""));
		Items[i].setXbundle(xid);
	}

	// 执行数据添加
	dao.insertItem(Items);

	//清空vector容器
	Items.clear();
	return xid;
}

bool DataConfigService::updateData(const ModifyDataConfigDTO::Wrapper& dto) {
	//鄙人能力有限，不会更新数据，只好把原有数据删除，重新插入数据
	//先执行数据的删除,执行删除前先获取到appId
	//appId通过查询数据库得到
	DataConfigDAO dao;
	list<DictDO> l;
	l = dao.selectDictByXid(dto->xid);
	auto it = l.begin();
	string xappId = it->getXappId();
	dao.deleteById(dto->xid);

	//再执行数据的插入
	//存储数据到cms_appndict表中
	SnowFlake snowflake(16, 16);
	//获取创建时间
	SimpleDateTimeFormat datetime;
	string xcreateTime = datetime.format();
	//组装xsequence
	string createTime = datetime.format("%Y%m%d%H%M%S");
	string xsequence = createTime + dto->xid;
	// 组装DictDO数据
	DictDO dictdata;
	dictdata.setXid(dto->xid);
	dictdata.setXcreateTime(xcreateTime);
	dictdata.setXsequence(xsequence);
	dictdata.setXupdateTime(xcreateTime);
	dictdata.setXappId(xappId);
	// 更新时间为当前创建时间
	ZO_STAR_DOMAIN_DTO_TO_DO(dictdata, dto, Xalias, xalias, Xdescription, xdescription, Xname, xname)
		// 执行数据添加
		dao.insertDict(dictdata);
	// 存储数据到cms_appdictitem表中
	// 组装ItemDO数据
	// 对前端传过来的allitems数据进行解析并存储到cms_appdictitem表中
	//对allitems数据进行解析（json格式）
	string allitems = dto->allitems.getValue("");
	cJSON* root = cJSON_Parse(allitems.c_str());

	vector<string> v;
	AnalyzeJson(root, v);
	// 调用完AnalyzeJson方法后将flag置为1,以便再次调用时可以继续保存根结点数据
	flag = 1;
	cJSON_Delete(root);  // 释放掉root
	cout << "----------------------------" << endl;
	for (int i = 0; i < Items.size(); i++)
	{
		cout << Items[i].getXpath0() << "/" << Items[i].getXpath1() << "/" << Items[i].getXpath2() << "/" << Items[i].getXpath3() << "/" << Items[i].getXpath4() << endl;
	}
	//遍历容器，添加公共值
	for (int i = 0; i < Items.size(); i++)
	{
		//利用雪花算法生成itemid
		uint64_t itemid = snowflake.nextId();
		string xitemid = to_string(itemid);
		//组装xsequence
		xsequence = createTime + xitemid;
		//组装公共数据
		Items[i].setXid(xitemid);
		Items[i].setXcreateTime(xcreateTime);
		Items[i].setXsequence(xsequence);
		Items[i].setXupdateTime(xcreateTime);
		Items[i].setXappId(xappId);
		Items[i].setXbundle(dto->xid);
	}

	// 执行数据添加
	dao.insertItem(Items);

	//清空vector容器
	Items.clear();
	return true;
}

DataConfigVO::Wrapper DataConfigService::queryByXid(const string& xid) {
	// 构建返回对象
	auto dict = DataConfigVO::createShared();

	DataConfigDAO dao;
	// 查询字典信息
	list<DictDO> l;
	l = dao.selectDictByXid(xid);
	auto it = l.begin();
	string xname = it->getXname();
	string xalias = it->getXalias();
	string xdescription = it->getXdescription();

	// 查询所有item数据
	list<ItemDO> result = dao.selectItemByXid(xid);
	//将list转换为vector
	std::copy(result.begin(), result.end(), std::back_inserter(Items));
	//组装json数据
	string allitems = CreateJson(Items);

	// 组装DTO
	dict->xid = xid;
	dict->xname = xname;
	dict->xalias = xalias;
	dict->xdescription = xdescription;
	dict->allitems = allitems;

	//清空vector容器和map容器
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