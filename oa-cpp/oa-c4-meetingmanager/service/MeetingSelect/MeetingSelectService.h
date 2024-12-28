#pragma once
#ifndef _MEETINGSELECT_SERVICE_
#define _MEETINGSELECT_SERVICE_

#include <list>
#include "../../domain/vo/orgmanager/MeetingSelectVO.h"
#include "../../domain/query/MeetingSelect/MeetingSelectQuery.h"
#include "../../domain/dto/orgmanager/meetingselect/MeetingSelectDTO.h"

/**
 * ����ѡ�����ʵ����
 */
class MeetingSelectService
{
public:
    /**
     * ��ҳ��ѯ���л�������
     * @param query ��ѯ����
     * @return �������������Ļ������ݵķ�ҳ����
     */
    MeetingSelectPageDTO::Wrapper listAll(const MeetingSelectQuery::Wrapper& query);

    /**
     * �����������
     * @param dto ����Ҫ��������ݵ�DTO
     * @return �²���Ļ����¼ID
     */
    //uint64_t saveData(const MeetingSelectDTO::Wrapper& dto);

    /**
     * �޸Ļ�������
     * @param dto ����Ҫ���µ����ݵ�DTO
     * @return ���²����Ƿ�ɹ�
     */
    //bool updateData(const MeetingSelectDTO::Wrapper& dto);

    /**
     * ����IDɾ����������
     * @param id Ҫɾ���Ļ����¼ID
     * @return ɾ�������Ƿ�ɹ�
     */
    //bool removeData(uint64_t id);
};

#endif // !_MEETINGSELECT_SERVICE_
