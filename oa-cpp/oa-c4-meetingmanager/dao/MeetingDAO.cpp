#include "stdafx.h"
#include"MeetingDAO.h"
#include "../lib-common/include/SnowFlake.h"

uint64_t MeetingDAO::addMeeting(const MeetingDO& meetingdo) {

    //������Ҫ������Ϣ
    string sql = "INSERT INTO `mt_meeting` "
        "(`xid`,`xtype`,`xsequence`,`xcreateTime`, `xupdateTime`, "
        " `xstartTime`, `xcompletedTime`, `xroom`, "
        "`xhostUnit`, `xhostPerson`, `xapplicant`, `xsubject`, "
        "`xsummary`) "
        "VALUES (?, ?, ?, ? ,?, ?,?,? ,?, ?,?, ?, ?);";
    if(!sqlSession->executeUpdate(sql,
        "%s%s%s%s%s%s%s%s%s%s%s%s%s",
        // ��ʽ���ַ���
        meetingdo.getId(),            // ����ID
        meetingdo.getType(),          // ��������
        meetingdo.getSequence(),       // �������
        meetingdo.getCreateTime(),     // ����ʱ��
        meetingdo.getUpdateTime(),    // ����ʱ��
        meetingdo.getStartTime(),        // ��ʼʱ��
        meetingdo.getCompletedTime(),     // ���ʱ��
        meetingdo.getRoom(),           // ������ID
        meetingdo.getHostUnit(),          // ���쵥λ
        meetingdo.getHostPerson(),        // ������
        meetingdo.getApplicant(),       // ������
        meetingdo.getSubject(),           // ����
        meetingdo.getSummary())          // ����
        )
        return 0;


    //�����������Ϣ
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


//ȡ������
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
        return 1; // �ɹ�
    }
    catch (const std::exception& e) {
        cerr << "error: " << e.what() << endl; // ��ӡ������Ϣ
        return 0; // ���ش�����
    }


}

//��ѯ����ʱ���Ƿ��ͻ
bool MeetingDAO::checkMeetingTimeConflict(const string start_time, const string end_time, const string xroom) {
    if (end_time <= start_time) {
        return false; // ����ʱ�����ڿ�ʼʱ�䣬�����޳�ͻ
    }
    MeetingTimeMapper mapper;
    string time_sql = "SELECT xstartTime, xcompletedTime FROM mt_meeting WHERE xroom = ?";
    
    try {
        // ��ѯ��ʼʱ��
        auto TimeList = sqlSession->executeQuery<MeetingDO, MeetingTimeMapper>(time_sql, mapper, "%s", xroom);
        vector<string> startTimeList;
        vector<string> endTimeList;
        for (auto i = TimeList.begin(); i != TimeList.end(); i++) {
            startTimeList.push_back(i->getStartTime());
            endTimeList.push_back(i->getCompletedTime());
        }
       

        // ����Ƿ���ʱ���ͻ
        if (!startTimeList.empty() || !endTimeList.empty()) {
            for (auto i = startTimeList.begin(), j = endTimeList.begin();
                i != startTimeList.end() && j != endTimeList.end();
                i++, j++) {

                if ((*i <= start_time && *j >= end_time) ||
                    (*i <= start_time && *j >= start_time) ||
                    (*i <= end_time && *j >= end_time) ||
                    (*i >= start_time && *j <= end_time)) {
                    return false; // ���ڳ�ͻ
                }
            }
        }
        return true; // û�г�ͻ
    }
    catch (const std::exception& e) {
        std::cerr << "Error querying meeting times: " << e.what() << std::endl;
        return false; // ��ѯ����ʱ����false
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