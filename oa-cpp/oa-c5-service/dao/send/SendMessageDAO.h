#pragma once
#ifndef _SENDMESSAGE_DAO_
#define _SENDMESSAGE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/send/MsgMessageDO.h"
#include "../../domain/dto/send/sendDTO.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class SendMessageDAO : public BaseDAO
{
public:

	bool insertMessage(const string code, const string phone);

	// ͳ����������
	//uint64_t count(const SampleQuery::Wrapper& query);
	//// ��ҳ��ѯ����
	//list<SampleDO> selectWithPage(const SampleQuery::Wrapper& query);
	//// ͨ��������ѯ����
	//list<SampleDO> selectByName(const string& name);
	//// ��������
	//uint64_t insert(const SampleDO& iObj);
	//// �޸�����
	//int update(const SampleDO& uObj);
	//// ͨ��IDɾ������
	//int deleteById(uint64_t id);
};
#endif // !_SAMPLE_DAO_
