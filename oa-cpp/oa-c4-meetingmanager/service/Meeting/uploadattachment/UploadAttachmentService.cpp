#include "stdafx.h"
#include "UploadAttachmentService.h"
#include "../../../dao/Meeting/uploadattachment/UploadAttachmentDAO.h"

uint64_t UploadAttachmentService::saveData(const UploadAttachmentDTO::Wrapper& dto)
{
	// ��װDO����
	UploadAttachmentDO data;

	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,
		Xid, xid, XcreateTime, xcreateTime, Xsequence, xsequence, XupdateTime, xupdateTime,
		XdeepPath, xdeepPath, Xextension, xextension, XlastUpdatePerson, xlastUpdatePerson, XlastUpdateTime, xlastUpdateTime,
		Xlength, xlength, Xmeeting, xmeeting, Xname, xname, Xstorage, xstorage, Xsummary, xsummary)

	// ִ���������
	UploadAttachmentDAO dao;
	return dao.insert(data);
}

