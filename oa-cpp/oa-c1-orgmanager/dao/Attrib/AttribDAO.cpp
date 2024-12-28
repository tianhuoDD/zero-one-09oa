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
#include "AttribDAO.h"
#include "AttribMapper.h"
#include <sstream>
#include "oatpp/core/utils/String.hpp"
//�������������꣬�����ظ�����  
#define ATTRIB_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->id) { \
	sql << " AND xinxitable.id=? "; \
	SQLPARAMS_PUSH(params, "i", int, query->id.getValue(0)); \
}\
if (query->id) { \
    sql << " AND shuxingtable.id=? "; \
	SQLPARAMS_PUSH(params, "i", int, query->id.getValue(0)); \
}\
if (query->name) { \
	sql << " AND xinxitable.name=? "; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
} \

//�����ݿ���в���

//��ѯ������������
uint64_t AttribDAO::count(const AttribQuery::Wrapper& query)
{
	stringstream sql;
	//sql << "SELECT COUNT(*) FROM sample";
	sql << "SELECT COUNT(*) FROM shuxingtable,xinxitable WHERE xinxitable.id=" << query->id << " AND shuxingtable.id = xinxitable.id";
	//SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr);
}
//��ѯ���Բ���ҳ
std::list<AttribDO> AttribDAO::selectWithPage(const AttribQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT xinxitable.id,xinxitable.name,shuxingtable.shuxing,shuxingtable.value FROM xinxitable,shuxingtable ";
	//SAMPLE_TERAM_PARSE(query, sql); //��sql��伯�ɵ�params���sql��(���ɵ�һ��)����������
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	AttribMapper mapper;
	string sqlStr = sql.str();
	cout << sql.str() << endl;
	return sqlSession->executeQuery<AttribDO, AttribMapper>(sqlStr, mapper);//ȥ���ݿ�ִ��sql����������
}
//��������
uint64_t AttribDAO::insert(const AttribDO& iObj)
{
	string sql = "INSERT INTO `shuxingtable` (`id`, `shuxing`, `value`) VALUES (?, ?, ?)";
	//cout << iObj.getId() << "\t" << iObj.getName() << endl;
	return sqlSession->executeInsert(sql, "%i%s%i", iObj.getId(), iObj.getShuxing(), iObj.getValue());
}
//�������id������
int AttribDAO::update(const AttribDO& uObj)
{
	string sql = "UPDATE `xinxitable` SET `id`=?, `name`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%i%s%i", uObj.getId(), uObj.getName(), uObj.getId());
}
//ɾ�����id������
int AttribDAO::deleteById(uint64_t id)
{
	string sql = "DELETE FROM `xinxitable` WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%ull", id);
}