#pragma once
#ifndef _MEETINGSELECT_DAO_
#define _MEETINGSELECT_DAO_

#include "BaseDAO.h"
#include "../../domain/do/MeetingSelect/MeetingSelectDO.h"
#include "../../domain/query/MeetingSelect/MeetingSelectQuery.h"

/**
 * 会议选择表数据库操作实现类
 */
class MeetingSelectDAO : public BaseDAO
{
public:
    /**
     * 统计符合查询条件的会议记录数
     * @param query 会议查询条件
     * @return 符合条件的会议记录总数
     */
    uint64_t count(const MeetingSelectQuery::Wrapper& query);

    /**
     * 根据分页条件查询会议记录
     * @param query 查询条件
     * @return 符合条件的会议记录列表
     */
    std::list<MeetingSelectDO> selectWithPage(const MeetingSelectQuery::Wrapper& query);

    ///**
    // * 根据会议标题查询会议记录
    // * @param title 会议标题
    // * @return 符合条件的会议记录列表
    // */
    std::list<MeetingSelectDO> selectByTitle(const std::string& title);

    ///**
    // * 插入新的会议记录
    // * @param iObj 会议数据对象
    // * @return 新插入记录的ID
    // */
    //uint64_t insert(const MeetingSelectDO& iObj);

    ///**
    // * 更新会议记录
    // * @param uObj 更新的会议数据对象
    // * @return 更新操作受影响的行数
    // */
    //int update(const MeetingSelectDO& uObj);

    ///**
    // * 根据ID删除会议记录
    // * @param id 会议记录ID
    // * @return 删除操作受影响的行数
    // */
   // int deleteById(uint64_t id);
};

#endif // _MEETINGSELECT_DAO_
