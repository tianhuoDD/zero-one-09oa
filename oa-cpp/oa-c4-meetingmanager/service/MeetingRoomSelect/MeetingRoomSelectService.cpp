#include "stdafx.h"
#include "MeetingRoomSelectService.h"
#include "../../dao/MeetingRoomSelect/MeetingRoomSelectDAO.h"

MeetingRoomSelectPageDTO::Wrapper MeetingRoomSelectService::listAll(const MeetingRoomSelectQuery::Wrapper& query)
{
    // �������ض���
    auto pages = MeetingRoomSelectPageDTO::createShared();
    pages->pageIndex = query->pageIndex;
    pages->pageSize = query->pageSize;

    // ��ѯ����������
    MeetingRoomSelectDAO dao;
    uint64_t count = dao.count(query);
    if (count <= 0)
    {
        return pages;
    }

    // ��ҳ��ѯ����
    pages->total = count;
    pages->calcPages();
    list<MeetingRoomSelectDO> result = dao.selectWithPage(query);

    // ��DOת����DTO
    for (const auto& sub : result)
    {
        auto dto = MeetingRoomSelectDTO::createShared();

        // �ֶ�ӳ��DO�ֶε�DTO
        dto->meetingRoomId = sub.getRoomId();
        dto->meetingRoomName = sub.getRoomName();
        dto->scheduledDateTime = sub.getScheduledDateTime();
        dto->durationHours = sub.getDurationHours();
        dto->durationMinutes = sub.getDurationMinutes();

        // ��ת�����DTO��ӵ���ҳ�����
        pages->addData(dto);
    }

    return pages;
}

uint64_t MeetingRoomSelectService::saveData(const MeetingRoomSelectDTO::Wrapper& dto)
{
    // ��װDO����
    MeetingRoomSelectDO data;

    // �ֶ�ӳ��DTO�ֶε�DO
   // ֱ��ӳ��DTO�ֶε�DO
    data.setRoomId(dto->meetingRoomId);
    data.setRoomName(dto->meetingRoomName);
    data.setScheduledDateTime(dto->scheduledDateTime);
    data.setDurationHours(dto->durationHours);
    data.setDurationMinutes(dto->durationMinutes);

    // ִ���������
    MeetingRoomSelectDAO dao;
    return dao.insert(data);
}

bool MeetingRoomSelectService::updateData(const MeetingRoomSelectDTO::Wrapper& dto)
{
    // ��װDO����
    MeetingRoomSelectDO data;

    // �ֶ�ӳ��DTO�ֶε�DO
    data.setRoomId(dto->meetingRoomId.getValue(0));
    data.setRoomName(dto->meetingRoomName.getValue(""));
    data.setScheduledDateTime(dto->scheduledDateTime.getValue(""));
    data.setDurationHours(dto->durationHours.getValue(0));
    data.setDurationMinutes(dto->durationMinutes.getValue(0));

    // ִ�������޸�
    MeetingRoomSelectDAO dao;
    return dao.update(data) == 1;
}

bool MeetingRoomSelectService::removeData(uint64_t id)
{
    MeetingRoomSelectDAO dao;
    return dao.deleteById(id) == 1;
}

