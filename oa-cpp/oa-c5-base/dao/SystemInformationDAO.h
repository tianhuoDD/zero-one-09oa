/*
 Copyright Zero One Star. All rights reserved.

 @Author: Detachment
 @Date: 2024/10/19 17:09:44

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
#ifndef _SYSTEM_INFORMATIONDAO_H_
#define _SYSTEM_INFORMATIONDAO_H_
#include "BaseDAO.h"
#include"../domain/GlobalInclude.h"
#include"../domain/do/SystemInformationDO.h"

#include "Macros.h"
#include "NacosClient.h"
#include "MongoClient.h"
#include <iostream>
#include <bsoncxx/json.hpp>

#include "gtest/gtest.h"

class SystemInformationDAO
{
public:
	inline SystemInformationDO select(string n) {
		YamlHelper y;
		MongoClient c("mongodb://c2:c2-123456qaq@8.148.21.89:27020/oac2");
		using namespace bsoncxx::builder::basic;
		SystemInformationDO sys_do;
		c.execute("system_information", [&](mongocxx::collection* collection) {
			using namespace bsoncxx::builder::basic;
			auto cursor = collection->find(make_document(kvp("name", n)));
			for (auto doc : cursor) {
				cout << bsoncxx::to_json(doc) << endl;
				sys_do.setinformation(bsoncxx::to_json(doc));

			}
			});
		sys_do.setinformation("haha");
		return sys_do;
	}

};
#endif // !_SYSTEM_INFORMATIONDAO_H_