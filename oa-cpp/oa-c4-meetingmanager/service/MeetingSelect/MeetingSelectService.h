#pragma once
#ifndef _MEETINGSELECT_SERVICE_
#define _MEETINGSELECT_SERVICE_

#include <list>
#include "../../domain/vo/orgmanager/MeetingSelectVO.h"
#include "../../domain/query/MeetingSelect/MeetingSelectQuery.h"
#include "../../domain/dto/orgmanager/meetingselect/MeetingSelectDTO.h"

/**
 * 会议选择服务实现类
 */
class MeetingSelectService
{
public:
    /**
     * 分页查询所有会议数据
     * @param query 查询条件
     * @return 包含符合条件的会议数据的分页对象
     */
    MeetingSelectPageDTO::Wrapper listAll(const MeetingSelectQuery::Wrapper& query);

    /**
     * 保存会议数据
     * @param dto 包含要保存的数据的DTO
     * @return 新插入的会议记录ID
     */
    //uint64_t saveData(const MeetingSelectDTO::Wrapper& dto);

    /**
     * 修改会议数据
     * @param dto 包含要更新的数据的DTO
     * @return 更新操作是否成功
     */
    //bool updateData(const MeetingSelectDTO::Wrapper& dto);

    /**
     * 根据ID删除会议数据
     * @param id 要删除的会议记录ID
     * @return 删除操作是否成功
     */
    //bool removeData(uint64_t id);
};

#endif // !_MEETINGSELECT_SERVICE_
