#pragma once
#ifndef _UPLOADATTACHMENTCONTROLLER_SERVICE_
#define _UPLOADATTACHMENTCONTROLLER_SERVICE_
#include <list>

#include "domain/dto/Meeting/uploadattachment/UploadAttachmentDTO.h"

/**
 * �����ļ��ϴ�����ʵ��
 */
class UploadAttachmentService
{
public:
	// ��������
	uint64_t saveData(const UploadAttachmentDTO::Wrapper& dto);
};

#endif // !_UPLOADATTACHMENTCONTROLLER_SERVICE_