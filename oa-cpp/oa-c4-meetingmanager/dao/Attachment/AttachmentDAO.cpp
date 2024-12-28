#include "AttachmentDAO.h"
list<AttachmentDO> AttachmentDAO::selectByMeetingId(const string& meetingId)
{
	string sql = "SELECT\
					xid,xname,xextension,xlastUpdateTime,xlastUpdatePerson, \
					xdeepPath,xencryptKey,xstorage,xlength,xsummary,xmeeting,xcreateTime \
				  FROM    \
					mt_attachment \
				  where\
					xmeeting = ?\
		";
	AttachmentMapper mapper;
	
	return sqlSession->executeQuery<AttachmentDO, AttachmentMapper>(sql, mapper, "%s", meetingId);
}

int AttachmentDAO::deleteByAttachmentId(const string& attachmentId)
{
	string sql = "DELETE FROM \
					mt_attachment \
				  WHERE \
					xmeeting = ?";
	int res = sqlSession->executeUpdate(sql, "%s", attachmentId);
	return res;
}

uint64_t AttachmentDAO::insert(AttachmentDO& attachmentDO)
{
	//处理sequence字段
	string sequence = "";
	int begin = 0;
	string createTime = attachmentDO.getCreateTime();
	for (int i = 0; i < createTime.size(); i++) {
		if (createTime[i] == ' ') {
			begin = i + 1;
			continue;
		}
		if (createTime[i] == '-' || createTime[i] == ':') {
			sequence += createTime.substr(begin, i - begin);
			begin = i + 1;
		}
	}
	sequence += createTime.substr(begin);//把最后两位算上
	sequence += attachmentDO.getId();
	string updateTime = attachmentDO.getLastUpdateTime();
	string sql = "INSERT INTO \
					mt_attachment (xid, xcreateTime, xsequence, xupdateTime, xdeepPath, xextension, xlastUpdatePerson, xlastUpdateTime, xlastUpdateTime, xlength, xmeeting, xname, xstorage, xsummary) \
					VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?) \
			";
	auto res = sqlSession->executeInsert(sql, "%s%s%s%s%b%s%s%s%s%s%s%s%s%b",
		attachmentDO.getId(), attachmentDO.getCreateTime(), sequence, updateTime, attachmentDO.getDeepPath(), attachmentDO.getExtension(),
		attachmentDO.getLastUpdatePerson(), attachmentDO.getLastUpdateTime(), attachmentDO.getLength(), attachmentDO.getMeetingId(), attachmentDO.getName(), attachmentDO.getStorage(), attachmentDO.getSummary()
	);
	return res;
}
