#include "stdafx.h"
#include "SendFilesService.h"
#include "../../dao/myfilesendshare/SendFilesDAO.h"
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"
#include <SnowFlake.h>




uint64_t SendFilesService::saveData(const SendFilesDTO::Wrapper& dto)
{
	// 组装DO数据
	file_attachment_editorlistDO data;
	data.setattachment_xid(dto->ATTACHMENT_XID.getValue(""));
	data.setXeditorList(dto->xeditorList.getValue(""));
	data.setXorderColumn(dto->xorderColumn.getValue(1));
	//ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Attachment_Xid, ATTACHMENT_XID, XeditorList, xeditorList, XorderColumn, xorderColumn)
		// 执行数据添加
	SendFilesDAO dao;
	return dao.insert(data);
}
uint64_t SendFilesService::insertSendLog(const FileLogDTO::Wrapper& ddto) {
	SnowFlake sff(1, 1);
	unsigned int aa = sff.nextId();
	std::string str = std::to_string(aa);
	ddto->xid = str;

	FileLogDO dataa;

	ZO_STAR_DOMAIN_DTO_TO_DO(dataa, ddto, Xid, xid, XOperationType, xOperationType, \
		XFromPerson, xFromPerson, XToPerson, xToPerson, XOperationTime, xOperationTime, File_attachment_id, file_attachment_id)

		SendFilesDAO daoo;

	return daoo.insertsendlog(dataa);
}


