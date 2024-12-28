#pragma once
#ifndef _UPLOADATTACHMENTCONTROLLER_SERVICE_
#define _UPLOADATTACHMENTCONTROLLER_SERVICE_
#include <list>

#include "domain/dto/Meeting/uploadattachment/UploadAttachmentDTO.h"

/**
 * 会议文件上传服务实现
 */
class UploadAttachmentService
{
public:
	// 保存数据
	uint64_t saveData(const UploadAttachmentDTO::Wrapper& dto);
};

#endif // !_UPLOADATTACHMENTCONTROLLER_SERVICE_