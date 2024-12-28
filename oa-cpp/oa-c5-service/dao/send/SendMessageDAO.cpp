#include "SendMessageDAO.h"
#include "domain/do/send/MsgMessageDO.h"
#include "SimpleDateTimeFormat.h"
#include "SnowFlake.h"

bool SendMessageDAO::insertMessage(const string code ,const string phone)
{
	std::string person = phone;
	MsgMessageDO msgDO;
	string time = SimpleDateTimeFormat::format();
	msgDO.setxcreateTime(time);
	msgDO.setxupdateTime(time);
	msgDO.setxbody(code);
	msgDO.setxtitle("send to" + person);
	msgDO.setxtype("sms");
	msgDO.setxperson(person);
	msgDO.setxconsumed(true);
	msgDO.setxconsumer(person);
	SnowFlake sf(1, 2);
	string id = std::to_string(sf.nextId());
	msgDO.setxid(id);
	msgDO.setxsequence(id + "-" + time);
	string sql = "INSERT INTO `msg_message` (xcreateTime, xupdateTime, xbody,xtitle,xtype,xperson,xconsumed,xconsumer,xid,xsequence) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%i%s%s%s", msgDO.getxcreateTime(),msgDO.getxupdateTime(),
		msgDO.getxbody(),msgDO.getxtitle(),msgDO.getxtype(),msgDO.getxperson(),msgDO.getxconsumed(),msgDO.getxconsumer(),msgDO.getxid()
	,msgDO.getxsequence());
}
