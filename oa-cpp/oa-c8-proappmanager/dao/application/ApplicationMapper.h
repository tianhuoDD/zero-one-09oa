/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2024/10/24 21:32:35

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
#ifndef _APPLICATIONMAPPER_H_
#define _APPLICATIONMAPPER_H_

//将数据库查询结构转化成do
class ApplicationMapper : public Mapper<ApplicationDO>
{
public:
	ApplicationDO mapper(ResultSet* resultSet) const override
	{
		ApplicationDO data;
		data.setName(resultSet->getString(1));
		data.setAlias(resultSet->getString(2));
		data.setApplicationCategory(resultSet->getString(3));
		data.setDescription(resultSet->getString(4));
		data.setId(resultSet->getString(5));
		data.setCreateTime(resultSet->getString(6));
		data.setSequence(resultSet->getString(7));
		data.setUpdateTime(resultSet->getString(8));
		data.setDistributeFactor(resultSet->getInt(9));
		data.setCreatorPerson(resultSet->getString(10));
		data.setIcon(resultSet->getString(11));
		data.setIconHue(resultSet->getString(12));
		data.setLastUpdatePerson(resultSet->getString(13));
		data.setLastUpdateTime(resultSet->getString(14));
		data.setProperties(resultSet->getString(15));
		return data;
	}
};


#endif // !_APPLICATIONMAPPER_H_