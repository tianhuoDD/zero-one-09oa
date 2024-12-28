#include "stdafx.h"
#include "SortByPinYinDAO.h"
#include "SortByPinYinMapper.h"
#include <sstream>
#include "oatpp/core/utils/String.hpp"
//�������������꣬�����ظ�����  
#define SortByPinYin_TERAM_PARSE(query, sql) \
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
uint64_t SortByPinYinDAO::count(const SortByPinYinQuery::Wrapper& query)
{
	stringstream sql;
	//sql << "SELECT COUNT(*) FROM sample";
	sql << "SELECT COUNT(*) FROM shuxingtable,xinxitable WHERE xinxitable.id=" << query->id << " AND shuxingtable.id = xinxitable.id";
	//SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr);
}
//��ѯ���Բ���ҳ
std::list<SortByPinYinDO> SortByPinYinDAO::selectWithPage(const SortByPinYinQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT xinxitable.id,xinxitable.name,shuxingtable.shuxing,shuxingtable.value FROM xinxitable,shuxingtable ";
	//SAMPLE_TERAM_PARSE(query, sql); //��sql��伯�ɵ�params���sql��(���ɵ�һ��)����������
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	SortByPinYinMapper mapper;
	string sqlStr = sql.str();
	cout << sql.str() << endl;
	return sqlSession->executeQuery<SortByPinYinDO, SortByPinYinMapper>(sqlStr, mapper);//ȥ���ݿ�ִ��sql����������
}
//��������
uint64_t SortByPinYinDAO::insert(const SortByPinYinDO& iObj)
{
	string sql = "INSERT INTO `shuxingtable` (`id`, `shuxing`, `value`) VALUES (?, ?, ?)";
	//cout << iObj.getId() << "\t" << iObj.getName() << endl;
	return sqlSession->executeInsert(sql, "%i%s%i", iObj.getXid(), iObj.getShuxing(), iObj.getValue());
}
//�������id������
int SortByPinYinDAO::update(const SortByPinYinDO& uObj)
{
	string sql = "UPDATE `xinxitable` SET `id`=?, `name`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%i%s%i", uObj.getXid(), uObj.getName(), uObj.getXid());
}
//ɾ�����id������
int SortByPinYinDAO::deleteById(uint64_t id)
{
	string sql = "DELETE FROM `xinxitable` WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%ull", id);
}