#include "stdafx.h"
#include "MeetingRoomSelectService.h"
#include "../../dao/MeetingRoomSelect/MeetingRoomSelectDAO.h"

MeetingRoomSelectPageDTO::Wrapper MeetingRoomSelectService::listAll(const MeetingRoomSelectQuery::Wrapper& query)
{
    // 构建返回对象
    auto pages = MeetingRoomSelectPageDTO::createShared();
    pages->pageIndex = query->pageIndex;
    pages->pageSize = query->pageSize;

    // 查询数据总条数
    MeetingRoomSelectDAO dao;
    uint64_t count = dao.count(query);
    if (count <= 0)
    {
        return pages;
    }

    // 分页查询数据
    pages->total = count;
    pages->calcPages();
    list<MeetingRoomSelectDO> result = dao.selectWithPage(query);

    // 将DO转换成DTO
    for (const auto& sub : result)
    {
        auto dto = MeetingRoomSelectDTO::createShared();

        // 手动映射DO字段到DTO
        dto->meetingRoomId = sub.getRoomId();
        dto->meetingRoomName = sub.getRoomName();
        dto->scheduledDateTime = sub.getScheduledDateTime();
        dto->durationHours = sub.getDurationHours();
        dto->durationMinutes = sub.getDurationMinutes();

        // 将转换后的DTO添加到分页结果中
        pages->addData(dto);
    }

    return pages;
}

uint64_t MeetingRoomSelectService::saveData(const MeetingRoomSelectDTO::Wrapper& dto)
{
    // 组装DO数据
    MeetingRoomSelectDO data;

    // 手动映射DTO字段到DO
   // 直接映射DTO字段到DO
    data.setRoomId(dto->meetingRoomId);
    data.setRoomName(dto->meetingRoomName);
    data.setScheduledDateTime(dto->scheduledDateTime);
    data.setDurationHours(dto->durationHours);
    data.setDurationMinutes(dto->durationMinutes);

    // 执行数据添加
    MeetingRoomSelectDAO dao;
    return dao.insert(data);
}

bool MeetingRoomSelectService::updateData(const MeetingRoomSelectDTO::Wrapper& dto)
{
    // 组装DO数据
    MeetingRoomSelectDO data;

    // 手动映射DTO字段到DO
    data.setRoomId(dto->meetingRoomId.getValue(0));
    data.setRoomName(dto->meetingRoomName.getValue(""));
    data.setScheduledDateTime(dto->scheduledDateTime.getValue(""));
    data.setDurationHours(dto->durationHours.getValue(0));
    data.setDurationMinutes(dto->durationMinutes.getValue(0));

    // 执行数据修改
    MeetingRoomSelectDAO dao;
    return dao.update(data) == 1;
}

bool MeetingRoomSelectService::removeData(uint64_t id)
{
    MeetingRoomSelectDAO dao;
    return dao.deleteById(id) == 1;
}

