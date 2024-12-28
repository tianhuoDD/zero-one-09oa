#include "stdafx.h"
#include "SortByPinYinDAO.h"
#include "SortByPinYinMapper.h"
#include <sstream>
#include "oatpp/core/utils/String.hpp"
//定义条件解析宏，减少重复代码  
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

//对数据库进行操作

//查询总数据量个数
uint64_t SortByPinYinDAO::count(const SortByPinYinQuery::Wrapper& query)
{
	stringstream sql;
	//sql << "SELECT COUNT(*) FROM sample";
	sql << "SELECT COUNT(*) FROM shuxingtable,xinxitable WHERE xinxitable.id=" << query->id << " AND shuxingtable.id = xinxitable.id";
	//SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr);
}
//查询属性并分页
std::list<SortByPinYinDO> SortByPinYinDAO::selectWithPage(const SortByPinYinQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT xinxitable.id,xinxitable.name,shuxingtable.shuxing,shuxingtable.value FROM xinxitable,shuxingtable ";
	//SAMPLE_TERAM_PARSE(query, sql); //把sql语句集成到params这个sql中(集成到一起)，限制条件
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	SortByPinYinMapper mapper;
	string sqlStr = sql.str();
	cout << sql.str() << endl;
	return sqlSession->executeQuery<SortByPinYinDO, SortByPinYinMapper>(sqlStr, mapper);//去数据库执行sql并返回数据
}
//插入数据
uint64_t SortByPinYinDAO::insert(const SortByPinYinDO& iObj)
{
	string sql = "INSERT INTO `shuxingtable` (`id`, `shuxing`, `value`) VALUES (?, ?, ?)";
	//cout << iObj.getId() << "\t" << iObj.getName() << endl;
	return sqlSession->executeInsert(sql, "%i%s%i", iObj.getXid(), iObj.getShuxing(), iObj.getValue());
}
//更改这个id的数据
int SortByPinYinDAO::update(const SortByPinYinDO& uObj)
{
	string sql = "UPDATE `xinxitable` SET `id`=?, `name`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%i%s%i", uObj.getXid(), uObj.getName(), uObj.getXid());
}
//删除这个id的数据
int SortByPinYinDAO::deleteById(uint64_t id)
{
	string sql = "DELETE FROM `xinxitable` WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%ull", id);
}