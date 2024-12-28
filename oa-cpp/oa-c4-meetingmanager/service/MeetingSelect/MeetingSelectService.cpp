#include "stdafx.h"
#include "MeetingSelectService.h"
#include "../../dao/MeetingSelect/MeetingSelectDAO.h"

/**
 * ��ҳ��ѯ���л�������
 * @param query ��ѯ����
 * @return �������������Ļ������ݵķ�ҳ����
 */
MeetingSelectPageDTO::Wrapper MeetingSelectService::listAll(const MeetingSelectQuery::Wrapper& query)
{
    // ������ҳ���ض���
    auto pages = MeetingSelectPageDTO::createShared();
    pages->pageIndex = query->page.getValue(1);
    pages->pageSize = query->pageSize.getValue(10);

    // ��ѯ�ܼ�¼��
    MeetingSelectDAO dao;
    uint64_t count = dao.count(query);
    if (count <= 0) {
        return pages; // ���޼�¼�����ؿշ�ҳ����
    }

    // �����ܼ�¼��������ҳ��
    pages->total = count;
    pages->calcPages();

    // ��ҳ��ѯ����
    std::list<MeetingSelectDO> result = dao.selectWithPage(query);

    // �ֶ�����ѯ����� DO ת��Ϊ DTO
    for (const auto& sub : result) {
        auto dto = MeetingSelectDTO::createShared();
        dto->id = sub.getId();
        dto->applicant = sub.getApplicant();
        //dto->date = sub.getDate();
        dto->time = sub.getTime();
        dto->title = sub.getTitle();
        dto->meetingRoom = sub.getMeetingRoom();
        //dto->type = sub.getType();
        //dto->status = sub.getStatuS();

        pages->addData(dto);
    }

    return pages;
}

///**
// * �����������
// * @param dto ����Ҫ��������ݵ�DTO
// * @return �²���Ļ����¼ID
// */
//uint64_t MeetingSelectService::saveData(const MeetingSelectDTO::Wrapper& dto)
//{
//    // �������ݶ��� (DO) ���ֶ���ֵ����
//    MeetingSelectDO data;
//    data.setApplicant(dto->applicant);
//    //data.setDate(dto->date);
//    data.setTime(dto->time);
//    data.setTitle(dto->title);
//    data.setMeetingRoom(dto->meetingRoom);
//    //data.setType(dto->type);
//    //data.setStatuS(dto->status);
//
//    // ��������
//    MeetingSelectDAO dao;
//    return dao.insert(data);
//}

///**
// * �޸Ļ�������
// * @param dto ����Ҫ���µ����ݵ�DTO
// * @return ���²����Ƿ�ɹ�
// */
//bool MeetingSelectService::updateData(const MeetingSelectDTO::Wrapper& dto)
//{
//    // �������ݶ��� (DO) ���ֶ���ֵ����
//    MeetingSelectDO data;
//    data.setId(dto->id);
//    data.setApplicant(dto->applicant);
//    //data.setDate(dto->date);
//    data.setTime(dto->time);
//    data.setTitle(dto->title);
//    data.setMeetingRoom(dto->meetingRoom);
//    //data.setType(dto->type);
//    //data.setStatuS(dto->status);
//
//    // ��������
//    MeetingSelectDAO dao;
//    return dao.update(data) == 1;
//}
//
///**
// * ����IDɾ����������
// * @param id Ҫɾ���Ļ����¼ID
// * @return ɾ�������Ƿ�ɹ�
// */
//bool MeetingSelectService::removeData(uint64_t id)
//{
//    MeetingSelectDAO dao;
//    return dao.deleteById(id) == 1;
//}
