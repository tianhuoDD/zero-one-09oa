#pragma once
#ifndef _SENDMESSAGE_DAO_
#define _SENDMESSAGE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/send/MsgMessageDO.h"
#include "../../domain/dto/send/sendDTO.h"

/**
 * 示例表数据库操作实现
 */
class SendMessageDAO : public BaseDAO
{
public:

	bool insertMessage(const string code, const string phone);

	// 统计数据条数
	//uint64_t count(const SampleQuery::Wrapper& query);
	//// 分页查询数据
	//list<SampleDO> selectWithPage(const SampleQuery::Wrapper& query);
	//// 通过姓名查询数据
	//list<SampleDO> selectByName(const string& name);
	//// 插入数据
	//uint64_t insert(const SampleDO& iObj);
	//// 修改数据
	//int update(const SampleDO& uObj);
	//// 通过ID删除数据
	//int deleteById(uint64_t id);
};
#endif // !_SAMPLE_DAO_
