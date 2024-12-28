#include "stdafx.h"
#include "MeetingSelectService.h"
#include "../../dao/MeetingSelect/MeetingSelectDAO.h"

/**
 * 分页查询所有会议数据
 * @param query 查询条件
 * @return 包含符合条件的会议数据的分页对象
 */
MeetingSelectPageDTO::Wrapper MeetingSelectService::listAll(const MeetingSelectQuery::Wrapper& query)
{
    // 创建分页返回对象
    auto pages = MeetingSelectPageDTO::createShared();
    pages->pageIndex = query->page.getValue(1);
    pages->pageSize = query->pageSize.getValue(10);

    // 查询总记录数
    MeetingSelectDAO dao;
    uint64_t count = dao.count(query);
    if (count <= 0) {
        return pages; // 若无记录，返回空分页对象
    }

    // 设置总记录数并计算页数
    pages->total = count;
    pages->calcPages();

    // 分页查询数据
    std::list<MeetingSelectDO> result = dao.selectWithPage(query);

    // 手动将查询结果从 DO 转换为 DTO
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
// * 保存会议数据
// * @param dto 包含要保存的数据的DTO
// * @return 新插入的会议记录ID
// */
//uint64_t MeetingSelectService::saveData(const MeetingSelectDTO::Wrapper& dto)
//{
//    // 创建数据对象 (DO) 并手动赋值属性
//    MeetingSelectDO data;
//    data.setApplicant(dto->applicant);
//    //data.setDate(dto->date);
//    data.setTime(dto->time);
//    data.setTitle(dto->title);
//    data.setMeetingRoom(dto->meetingRoom);
//    //data.setType(dto->type);
//    //data.setStatuS(dto->status);
//
//    // 插入数据
//    MeetingSelectDAO dao;
//    return dao.insert(data);
//}

///**
// * 修改会议数据
// * @param dto 包含要更新的数据的DTO
// * @return 更新操作是否成功
// */
//bool MeetingSelectService::updateData(const MeetingSelectDTO::Wrapper& dto)
//{
//    // 创建数据对象 (DO) 并手动赋值属性
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
//    // 更新数据
//    MeetingSelectDAO dao;
//    return dao.update(data) == 1;
//}
//
///**
// * 根据ID删除会议数据
// * @param id 要删除的会议记录ID
// * @return 删除操作是否成功
// */
//bool MeetingSelectService::removeData(uint64_t id)
//{
//    MeetingSelectDAO dao;
//    return dao.deleteById(id) == 1;
//}
