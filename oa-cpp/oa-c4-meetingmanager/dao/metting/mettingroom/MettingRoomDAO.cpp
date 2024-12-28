/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:26:52

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
#include "MettingRoomDAO.h"
#include "MettingRoomMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码

std::list<MettingBuildDO> MettingRoomDAO::select()
{
	string sql = "SELECT xaddress FROM mt_building";
	MettingBuildMapper mapper;
	return sqlSession->executeQuery<MettingBuildDO, MettingBuildMapper>(sql, mapper);
}

uint64_t MettingRoomDAO::insert(const MettingRoomDO& iObj)
{
	SimpleDateTimeFormat Time1;
	SnowFlake snow(1,1);

	auto timetmp = Time1.format();
	auto snowtmp = snow.nextId();

	string tmp1 = std::to_string(snowtmp);
	string tmp2;
	for (auto tmp : tmp1)
	{
		if (std::isalnum(tmp))
		{
			tmp2 += tmp;
		}
	}
	string tmp3 = tmp1 + tmp2;
	string sql = "INSERT INTO `mt_room` (`xid`,`xdistributeFactor`,`xavailable`,`xbuilding`,`xcapacity`,`xdevice`,`xfloor`,`xname`,`xroomnumber`,`xcreateTime`,`xsequence`) VALUES (?,?,?,?,?,?,?,?,?,?,?)";
	return sqlSession->executeUpdate(sql,"%s%nul%b%s%nul%s%nul%s%s%s%s" ,tmp1, iObj.getDis(), iObj.getAvailable(), iObj.getBuild(), iObj.getcapacity(), iObj.getDevice(), iObj.getFloor(), iObj.getNames(), iObj.getRoomnumber(),timetmp,tmp3);
}
