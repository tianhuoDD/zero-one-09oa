#pragma once

#ifndef _UPEXCELDAO_H_
#define _UPEXCELDAO_H_

#include "BaseDAO.h"
//#include <bcrypt/BCrypt.hpp>
#include<vector>
#include<string>
#include <iomanip>
#include "../../../lib-common/include/SnowFlake.h"
#include "../../../lib-common/include/SimpleDateTimeFormat.h"
#include "../../domain/do/personimport/SheetDO.h"

// 只负责上传，就不用构造DO了
class UpExcelDAO : public BaseDAO
{
private:
	std::vector<Sheet1DO> sheet1;
	std::vector<Sheet2DO> sheet2;
	std::vector<Sheet3DO> sheet3;
	std::vector<Sheet4DO> sheet4;
	std::vector<Sheet5DO> sheet5;
public:
	// 工具函数
	// 根据手机号后六位，利用bcrypt生成11位密码
	string init_pwd(string phone);

	// 找到上级组织,Sheet1DO中
	int FindSuperior(string p_orgunique);
	// 
	std::string formatNumber(int num) {
		std::ostringstream oss;
		oss << std::setw(9) << std::setfill('0') << num;
		return oss.str();
	}
	// 插入模版函数
	template<typename T0>
	std::string get_str(T0 value);
	template<typename T, typename... Ts>
	std::string get_str(T value, Ts... args);
	template<typename... Values>
	uint64_t insert(string table_name, std::vector<string> columns_name, Values... values);

	// 初始化各个sheet，并插入五个有xid的表
	void init_and_insertsheet1(std::vector<std::vector<std::string>> data);
	void init_and_insertsheet2(std::vector<std::vector<std::string>> data);
	void init_and_insertsheet3(std::vector<std::vector<std::string>> data);
	void init_and_insertsheet4(std::vector<std::vector<std::string>> data);
	void init_and_insertsheet5(std::vector<std::vector<std::string>> data);

	// 其他表插入
	void insert_othertables();

};


template<typename T0>
std::string UpExcelDAO::get_str(T0 value) {
	if constexpr (std::is_same_v<T0, std::string> || std::is_same_v<T0, const char*>) { // 处理 const char*
		return "'" + std::string(value) + "'";
	}
	else if constexpr (std::is_arithmetic_v<T0>) { // 数字类型
		return std::to_string(value);
	}
	else {
		std::ostringstream oss;
		oss << value;
		return oss.str();
	}
}
template<typename T, typename ...Ts>
std::string UpExcelDAO::get_str(T value, Ts ...args)
{
	return get_str(value) + ", " + get_str(args...);
}
template<typename ...Values>
uint64_t UpExcelDAO::insert(string table_name, std::vector<string> columns_name, Values... values)
{
	int n = columns_name.size();
	if (n != sizeof...(values))
		throw std::invalid_argument("列名和列值的数量不一致");

	// 构建sql插入语句
	std::string sql = "INSERT INTO " + table_name + " (";
	for (int i = 0; i < n; i++)
	{
		std::string s = columns_name[i];

		if (i == n - 1)	sql += s;
		else            sql += (s + ",");
	}

	sql += ") VALUES (";
	sql += get_str(values...);
	sql += ");";

	// 执行插入
	return sqlSession->executeInsert(sql);
}
#endif

