#include "stdafx.h"
#include"MeetingDAO.h"
#include "../lib-common/include/SnowFlake.h"

uint64_t MeetingDAO::addMeeting(const MeetingDO& meetingdo) {

    //插入主要会议信息
    string sql = "INSERT INTO `mt_meeting` "
        "(`xid`,`xtype`,`xsequence`,`xcreateTime`, `xupdateTime`, "
        " `xstartTime`, `xcompletedTime`, `xroom`, "
        "`xhostUnit`, `xhostPerson`, `xapplicant`, `xsubject`, "
        "`xsummary`) "
        "VALUES (?, ?, ?, ? ,?, ?,?,? ,?, ?,?, ?, ?);";
    if(!sqlSession->executeUpdate(sql,
        "%s%s%s%s%s%s%s%s%s%s%s%s%s",
        // 格式化字符串
        meetingdo.getId(),            // 会议ID
        meetingdo.getType(),          // 会议类型
        meetingdo.getSequence(),       // 会议序号
        meetingdo.getCreateTime(),     // 创建时间
        meetingdo.getUpdateTime(),    // 更新时间
        meetingdo.getStartTime(),        // 开始时间
        meetingdo.getCompletedTime(),     // 完成时间
        meetingdo.getRoom(),           // 会议室ID
        meetingdo.getHostUnit(),          // 主办单位
        meetingdo.getHostPerson(),        // 主办人
        meetingdo.getApplicant(),       // 申请人
        meetingdo.getSubject(),           // 主题
        meetingdo.getSummary())          // 描述
        )
        return 0;


    //插入参与人信息
    const auto participants = meetingdo.getParticipants();
    int size = participants.size();

    
    string sql1 = "INSERT INTO `mt_meeting_invitepersonlist` "
        "(`MEETING_XID`, `xinvitePersonList`, `xorderColumn`) VALUES (?, ?, ?)";
    string sql2 = "INSERT INTO `mt_meeting_invitememberlist` "
        "(`MEETING_XID`, `xinviteMemberList`, `xorderColumn`) VALUES (?, ?, ?)";
   const auto& list = meetingdo.getParticipants();
   auto j = list.begin();
   for (int i = 0; i < size && j != list.end(); i++, j++) {
       if (!sqlSession->executeUpdate(sql1, "%s%s%i",
           meetingdo.getId(),
           *j,
           i) 
           || 
           !sqlSession->executeUpdate(sql2, "%s%s%i", 
            meetingdo.getId(),
            *j,
            i) )
       return 0;;
   }
    return 1;
}


//取消会议
uint64_t MeetingDAO::celMeeting(string id) {
    string sql = "DELETE FROM `mt_meeting` WHERE `xid`=?";
    string sql1 = "DELETE FROM `mt_meeting_invitepersonlist` WHERE `MEETING_XID`=?";
    string sql2 = "DELETE FROM `mt_meeting_invitememberlist` WHERE `MEETING_XID`=?";
    try {
        if (!sqlSession->executeUpdate(sql1, "%s", id) ||
            !sqlSession->executeUpdate(sql2, "%s", id) ||
            !sqlSession->executeUpdate(sql, "%s", id)) {
            throw runtime_error(ZH_WORDS_GETTER("jvo.cencel.sql.fail") +" id: " + id);
        }
        return 1; // 成功
    }
    catch (const std::exception& e) {
        cerr << "error: " << e.what() << endl; // 打印错误信息
        return 0; // 返回错误码
    }


}

//查询会议时间是否冲突
bool MeetingDAO::checkMeetingTimeConflict(const string start_time, const string end_time, const string xroom) {
    if (end_time <= start_time) {
        return false; // 结束时间早于开始时间，返回无冲突
    }
    MeetingTimeMapper mapper;
    string time_sql = "SELECT xstartTime, xcompletedTime FROM mt_meeting WHERE xroom = ?";
    
    try {
        // 查询开始时间
        auto TimeList = sqlSession->executeQuery<MeetingDO, MeetingTimeMapper>(time_sql, mapper, "%s", xroom);
        vector<string> startTimeList;
        vector<string> endTimeList;
        for (auto i = TimeList.begin(); i != TimeList.end(); i++) {
            startTimeList.push_back(i->getStartTime());
            endTimeList.push_back(i->getCompletedTime());
        }
       

        // 检查是否有时间冲突
        if (!startTimeList.empty() || !endTimeList.empty()) {
            for (auto i = startTimeList.begin(), j = endTimeList.begin();
                i != startTimeList.end() && j != endTimeList.end();
                i++, j++) {

                if ((*i <= start_time && *j >= end_time) ||
                    (*i <= start_time && *j >= start_time) ||
                    (*i <= end_time && *j >= end_time) ||
                    (*i >= start_time && *j <= end_time)) {
                    return false; // 存在冲突
                }
            }
        }
        return true; // 没有冲突
    }
    catch (const std::exception& e) {
        std::cerr << "Error querying meeting times: " << e.what() << std::endl;
        return false; // 查询出错时返回false
    }
}
string MeetingDAO::convertDate(const string& date) {
    string pureDate;

    for (char ch : date) {
        if (ch != '-' && ch != ':' && ch != ' ')
            pureDate += ch;
    }
    return pureDate;
}

//bool MeetingDAO::checkRoomConflict(const string xroom) {
//    string sql = "SECECT xid FROM mt_meeting"; 
//    MeetingRoomMapper mapper;
//    list<MeetingRoom> room_list = sqlSession->executeQuery<MeetingRoom>(sql, mapper);
//    for (const auto& room : room_list) {
//        if (room.xid == xroom) {
//            return true;
//        }
//    }
//    return false;
//}