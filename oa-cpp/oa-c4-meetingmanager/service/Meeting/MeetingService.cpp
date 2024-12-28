#include"MeetingService.h"
//��Listdo�н���Ա������ȡ��MeetingDTO��

#define HANDLE_LIST_DO_TO_DTO(target, src) \
if(!src.empty())\
for(const CurrentListDO& lst : src){\
	target->##src->push_back(oatpp::String(lst.getXlist().c_str())); \
}


//����curList��꣬��������ɾ������
#define HANDLE_LIST_UPDATE(target,src,_MT_DAO_) \
_MT_DAO_.deleteCurrenListById(src->meetingId, #target); \
for(int i = 0 ; i < src->##target->size(); i++){ \
		CurrentListDO curDO; \
		curDO.setMeetingId(src->meetingId.getValue("")); \
		curDO.setXlist(src->##target[i].getValue(""));\
		curDO.setOrderColumn(i); \
		_MT_DAO_.insertCurrenList(curDO, #target); \
}


MeetingInfoVO::Wrapper MeetingService::queryMeetingInfoById(const oatpp::String& mtId)
{
	//����һ��Ҫ���صĶ���
	auto res = MeetingInfoVO::createShared();
	//����DAO��
	MeetingDAO mt_dao;
	list<meetingDO> mt_list = mt_dao.selectById(mtId.getValue(""));
	//δ��ѯ����ǰ����
	if (mt_list.size() == 0)return res;
	//����Id��Ψһ�ģ�����н��list�Ĵ�Сֻ����1
	meetingDO mt_do = mt_list.front();
	//�������ں�ʱ��
	string beginTime = mt_do.getStartTime(), completedTime = mt_do.getCompletedTime();
	res->startTime = oatpp::String(beginTime.c_str());
	res->completedTime = oatpp::String(completedTime.c_str());
	//��ȡ������
	RoomDO rm_do = mt_dao.selectRoomByRoomId(mt_do.getRoom());
	BuildingDO building_do = mt_dao.selectBuildingByBuildingId(rm_do.getBuildId());
	string room = rm_do.getRoomName() + '(' + building_do.getBuildName() + ')';
	res->room = oatpp::String(room.c_str());
	//������Ҫ�ֶ�
	ZO_STAR_DOMAIN_DO_TO_DTO(res, mt_do, applicant, Applicant, type, _Type, hostPerson, HostPerson, hostUnit, HostUnit,
		subject, Subject, summary, Summary, pinyin, Pinyin, pinyinInitial, PinyinInitial);

	//��ѯ���鸽��
	AttachmentDAO att_dao;
	auto att_lst = att_dao.selectByMeetingId(mtId.getValue(""));
	for (AttachmentDO att_da : att_lst) {
		//��������DTO��ʵ��
		AttachmentInfo::Wrapper att = AttachmentInfo::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(att, att_da, id, Id, name, Name, lastUpdateTime, LastUpdateTime, lastUpdatePerson, LastUpdatePerson, meetingId, MeetingId,
			encryptKey, EncryptKey, deepPath, DeepPath, extension, Extension, length, Length, storage, Storage, summary, Summary, createTime, CreateTime);
		res->document->push_back(att);
	}

	//��ȡ�λ���Ա��ǩ����Ա��
	list<CurrentListDO> inviteDelPersonList, acceptPersonList, rejectPersonList, checkinPersonList, inviteMemberList, invitePersonList;
	inviteDelPersonList = mt_dao.selectListById(mtId.getValue(""), "inviteDelPersonList");
	acceptPersonList = mt_dao.selectListById(mtId.getValue(""), "acceptPersonList");
	rejectPersonList = mt_dao.selectListById(mtId.getValue(""), "rejectPersonList");
	checkinPersonList = mt_dao.selectListById(mtId.getValue(""), "checkinPersonList");
	inviteMemberList = mt_dao.selectListById(mtId.getValue(""), "inviteMemberList");
	invitePersonList = mt_dao.selectListById(mtId.getValue(""), "invitePersonList");
	if (!inviteDelPersonList.empty())for (const CurrentListDO& lst : inviteDelPersonList) {
		res->inviteDelPersonList->push_back(oatpp::String(lst.getXlist().c_str()));
	};
	if (!acceptPersonList.empty())for (const CurrentListDO& lst : acceptPersonList) {
		res->acceptPersonList->push_back(oatpp::String(lst.getXlist().c_str()));
	};
	if (!rejectPersonList.empty())for (const CurrentListDO& lst : rejectPersonList) {
		res->rejectPersonList->push_back(oatpp::String(lst.getXlist().c_str()));
	};
	if (!checkinPersonList.empty())for (const CurrentListDO& lst : checkinPersonList) {
		res->checkinPersonList->push_back(oatpp::String(lst.getXlist().c_str()));
	};
	if (!inviteMemberList.empty())for (const CurrentListDO& lst : inviteMemberList) {
		res->inviteMemberList->push_back(oatpp::String(lst.getXlist().c_str()));
	};
	if (!invitePersonList.empty())for (const CurrentListDO& lst : invitePersonList) {
		res->invitePersonList->push_back(oatpp::String(lst.getXlist().c_str()));
	};
	return res;
}

bool MeetingService::modifyMeetingInfo(const MeetingInfo::Wrapper& meetingInfo)
{
	MeetingDAO mt_dao;
	//��װmeeting����Ҫ����
	meetingDO mt_do;
	ZO_STAR_DOMAIN_DTO_TO_DO(mt_do, meetingInfo, _Type, meetingtype, HostPerson, hostPerson, HostUnit, hostUnit,
		Subject, subject, Summary, summary, Room, roomId, MeetingId, meetingId, Pinyin, pinyin, PinyinInitial, pinyinInitial);

	string startTime = meetingInfo->startTime;
	string completedTime = meetingInfo->completedTime;
	mt_do.setStartTime(startTime);
	mt_do.setCompletedTime(completedTime);
	//��������
	mt_dao.update(mt_do);
	//������
	//��ȡ�����б�
	AttachmentDAO att_dao;
	auto att_lst = att_dao.selectByMeetingId(meetingInfo->meetingId.getValue(""));
	//��¼�Ѵ��ڵĸ���
	unordered_map<string, bool> att_map, notVisited;
	for (const AttachmentDO& tem_att_do : att_lst) {
		notVisited[tem_att_do.getId()] = att_map[tem_att_do.getId()] = true;
	}
	//���DTO�����ĸ����Ƿ��ڱ��У����ڵĻ�Ҫ������벢����ʱ��
	auto tem_att_lst = meetingInfo->document;
	for (auto it = tem_att_lst->begin(); it != tem_att_lst->end(); it++) {
		//�����иø�����
		if (att_map[(*it)->id.getValue("")]) {
			notVisited.erase((*it)->id.getValue(""));
			continue;
		}
		//δ�ҵ��Ļ����в���
		AttachmentDO tem_att_do;
		ZO_STAR_DOMAIN_DTO_TO_DO(tem_att_do, (*it), Id, id, Name, name, LastUpdateTime, lastUpdateTime, LastUpdatePerson, lastUpdatePerson, MeetingId, meetingId, CreateTime, createTime
			, EncryptKey, encryptKey, DeepPath, deepPath, Extension, extension, Length, length, Storage, storage, Summary, summary);
		att_dao.insert(tem_att_do);
	}
	//�����ڱ��У�����DTO�в����ڣ�����ɾ��
	for (auto it = notVisited.begin(); it != notVisited.end(); it++) {
		att_dao.deleteByAttachmentId(it->first);
	}


	//����λ���Ա��������Ա��
	CurrentListDO inviteDelPersonList, acceptPersonList, rejectPersonList, checkinPersonList, inviteMemberList, invitePersonList;
	mt_dao.deleteCurrenListById(meetingInfo->meetingId, "inviteDelPersonList"); for (int i = 0; i < meetingInfo->inviteDelPersonList->size(); i++) {
		CurrentListDO curDO; curDO.setMeetingId(meetingInfo->meetingId.getValue("")); curDO.setXlist(meetingInfo->inviteDelPersonList[i].getValue("")); curDO.setOrderColumn(i); mt_dao.insertCurrenList(curDO, "inviteDelPersonList");
	};
	mt_dao.deleteCurrenListById(meetingInfo->meetingId, "acceptPersonList"); for (int i = 0; i < meetingInfo->acceptPersonList->size(); i++) {
		CurrentListDO curDO; curDO.setMeetingId(meetingInfo->meetingId.getValue("")); curDO.setXlist(meetingInfo->acceptPersonList[i].getValue("")); curDO.setOrderColumn(i); mt_dao.insertCurrenList(curDO, "acceptPersonList");
	};
	mt_dao.deleteCurrenListById(meetingInfo->meetingId, "rejectPersonList"); for (int i = 0; i < meetingInfo->rejectPersonList->size(); i++) {
		CurrentListDO curDO; curDO.setMeetingId(meetingInfo->meetingId.getValue("")); curDO.setXlist(meetingInfo->rejectPersonList[i].getValue("")); curDO.setOrderColumn(i); mt_dao.insertCurrenList(curDO, "rejectPersonList");
	};
	mt_dao.deleteCurrenListById(meetingInfo->meetingId, "checkinPersonList"); for (int i = 0; i < meetingInfo->checkinPersonList->size(); i++) {
		CurrentListDO curDO; curDO.setMeetingId(meetingInfo->meetingId.getValue("")); curDO.setXlist(meetingInfo->checkinPersonList[i].getValue("")); curDO.setOrderColumn(i); mt_dao.insertCurrenList(curDO, "checkinPersonList");
	};
	mt_dao.deleteCurrenListById(meetingInfo->meetingId, "inviteMemberList"); for (int i = 0; i < meetingInfo->inviteMemberList->size(); i++) {
		CurrentListDO curDO; curDO.setMeetingId(meetingInfo->meetingId.getValue("")); curDO.setXlist(meetingInfo->inviteMemberList[i].getValue("")); curDO.setOrderColumn(i);
		mt_dao.insertCurrenList(curDO, "inviteMemberList");
	};
	mt_dao.deleteCurrenListById(meetingInfo->meetingId, "invitePersonList"); for (int i = 0; i < meetingInfo->invitePersonList->size(); i++) {
		CurrentListDO curDO; curDO.setMeetingId(meetingInfo->meetingId.getValue("")); curDO.setXlist(meetingInfo->invitePersonList[i].getValue("")); curDO.setOrderColumn(i); mt_dao.insertCurrenList(curDO, "invitePersonList");
	};


	return 1;
}
