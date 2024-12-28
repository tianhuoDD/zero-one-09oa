#pragma once
#ifndef _MEETINGSELECT_DAO_
#define _MEETINGSELECT_DAO_

#include "BaseDAO.h"
#include "../../domain/do/MeetingSelect/MeetingSelectDO.h"
#include "../../domain/query/MeetingSelect/MeetingSelectQuery.h"

/**
 * ����ѡ������ݿ����ʵ����
 */
class MeetingSelectDAO : public BaseDAO
{
public:
    /**
     * ͳ�Ʒ��ϲ�ѯ�����Ļ����¼��
     * @param query �����ѯ����
     * @return ���������Ļ����¼����
     */
    uint64_t count(const MeetingSelectQuery::Wrapper& query);

    /**
     * ���ݷ�ҳ������ѯ�����¼
     * @param query ��ѯ����
     * @return ���������Ļ����¼�б�
     */
    std::list<MeetingSelectDO> selectWithPage(const MeetingSelectQuery::Wrapper& query);

    ///**
    // * ���ݻ�������ѯ�����¼
    // * @param title �������
    // * @return ���������Ļ����¼�б�
    // */
    std::list<MeetingSelectDO> selectByTitle(const std::string& title);

    ///**
    // * �����µĻ����¼
    // * @param iObj �������ݶ���
    // * @return �²����¼��ID
    // */
    //uint64_t insert(const MeetingSelectDO& iObj);

    ///**
    // * ���»����¼
    // * @param uObj ���µĻ������ݶ���
    // * @return ���²�����Ӱ�������
    // */
    //int update(const MeetingSelectDO& uObj);

    ///**
    // * ����IDɾ�������¼
    // * @param id �����¼ID
    // * @return ɾ��������Ӱ�������
    // */
   // int deleteById(uint64_t id);
};

#endif // _MEETINGSELECT_DAO_
