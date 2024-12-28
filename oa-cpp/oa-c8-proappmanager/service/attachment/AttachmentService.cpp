#include "stdafx.h"
#include "SnowFlake.h"
#include "AttachmentService.h"
#include "../../dao/attachment/AttachmentDAO.h"

AttachmentListVO::Wrapper AttachmentService::listAll(const string& xapplication)//
{
	auto atList = AttachmentListVO::createShared();//构建返回对象
	AttachmentDAO dao;
	uint64_t count = dao.count(xapplication);//数有多少个记录数
	if (count <= 0) {
		return atList;
	}
	list<AttachmentListDO> result = dao.GetList(xapplication);
	for (AttachmentListDO sub : result) {
		auto vo = AttachmentVO::createShared();
		//DO转换成VO
		//vo->id = sub.getXid();
		//vo->name = sub.getXname();
		ZO_STAR_DOMAIN_DO_TO_DTO(vo, sub, id, Xid, name, Xname,
			alias, Xalias, description, Xdescription, application, Xapplication,
			lastUpdatePerson, XlastUpdatePerson, lastUpdateTime, XlastUpdateTime,
			fileName, XfileName, length, Xlength, createTime, XcreateTime, updateTime, XupdateTime);//vo的id被sub的Xid赋值
		atList->addData(vo);


	}
	return atList;
}

AttachmentDetailVO::Wrapper AttachmentService::Detail(const string& xid) {
	auto atDetail = AttachmentDetailVO::createShared();
	AttachmentDAO dao;
	list<AttachmentDetailDO> detail = dao.selectByID(xid);
	AttachmentDetailDO detaildo;
	if (detail.empty()) {
		return atDetail;
	}
	detaildo = detail.front();
	//atDetail->id = detaildo.getXid();
	//atDetail->name = detaildo.getXname();
	//DO转换成VO
	ZO_STAR_DOMAIN_DO_TO_DTO(atDetail, detaildo, id, Xid, name, Xname,
		alias, Xalias, description, Xdescription, application, Xapplication,
		lastUpdatePerson, XlastUpdatePerson, lastUpdateTime, XlastUpdateTime, data, Xdata,
		fileName, XfileName, length, Xlength, createTime, XcreateTime, updateTime, XupdateTime);
	return atDetail;
}

static string getCurrTimeWithMillis() {
	auto now = std::chrono::system_clock::now();
	auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;
	time_t now_c = std::chrono::system_clock::to_time_t(now);
	tm* ltm = localtime(&now_c);
	char timeStr[24];
	strftime(timeStr, sizeof(timeStr), "%Y%m%d%H%M%S", ltm);
	snprintf(timeStr + 14, sizeof(timeStr) - 14, "%03d", static_cast<int>(millis.count()));
	return string(timeStr);
}

static string getCurrTime() {
	// 获取当前时间:2021-01-01 12:00:00
	time_t now = time(0);
	tm* ltm = localtime(&now);
	char timeStr[20];
	strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S", ltm);
	return string(timeStr);
}

static string generateId() {
	SnowFlake sf(8, 4);
	uint64_t id;
	do {
		id = sf.nextId();
	} while (id == 0);
	return to_string(id);
}

string AttachmentService::saveFile(const AttachmentOperateDTO::Wrapper& dto, const PayloadDTO& payload) {
	AttachmentDetailDO detailDO;
	ZO_STAR_DOMAIN_DTO_TO_DO(detailDO, dto, Xid, id, XcreateTime, createTime, Xsequence, sequence, XupdateTime, updateTime,
		XdistributeFactor, distributeFactor, Xalias, alias, Xapplication, application, Xdata, data, Xdescription, description,
		XfileName, fileName, XlastUpdatePerson, lastUpdatePerson, XlastUpdateTime, lastUpdateTime, Xlength, length, Xname, name);
	AttachmentDAO dao;
	string idStr = generateId();
	detailDO.setXid(idStr);
	string timeStr = getCurrTime();
	detailDO.setXcreateTime(timeStr);
	detailDO.setXupdateTime(timeStr);
	detailDO.setXlastUpdateTime(timeStr);
	string serialNumber = getCurrTimeWithMillis() + idStr;
	detailDO.setXsequence(serialNumber);
	detailDO.setXlastUpdatePerson(payload.getUsername());
	if (detailDO.getXdescription().empty()) {
		detailDO.setXdescription(detailDO.getXname() + " " + to_string(detailDO.getXlength() * 1.0 / 1000) + " K");
	}
	if (detailDO.getXfileName().empty()) {
		detailDO.setXfileName(detailDO.getXname());
	}

	if (dao.saveAttachment(detailDO) == 1) {
		return idStr;
	}
	return "faild -> service";
}

bool AttachmentService::updateFile(const AttachmentOperateDTO::Wrapper& dto, const PayloadDTO& payload) {
	AttachmentDetailDO detailDO;
	ZO_STAR_DOMAIN_DTO_TO_DO(detailDO, dto, Xid, id, XupdateTime, updateTime,
		XdistributeFactor, distributeFactor, Xalias, alias,
		XlastUpdatePerson, lastUpdatePerson, XlastUpdateTime, lastUpdateTime, Xname, name);
	AttachmentDAO dao;
	string timeStr = getCurrTime();
	detailDO.setXupdateTime(timeStr);
	detailDO.setXlastUpdateTime(timeStr);
	detailDO.setXlastUpdatePerson(payload.getUsername());
	return dao.updateAttachment(detailDO) == 1;
}

string AttachmentService::deleteFile(const string& xid) {
	AttachmentDAO dao;
	string url = "";
	auto detail = dao.selectByID(xid);
	if (!detail.empty()) {
		url = detail.front().getXdata();
	}
	dao.deleteAttachment(xid);
	return url;
}
