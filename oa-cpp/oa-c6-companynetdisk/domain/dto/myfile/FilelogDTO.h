#pragma once

#ifndef _FILELOG_H_
#define _FILELOG_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * editor图片信息传输数据对象
 */
class FileLogDTO : public oatpp::DTO
{
	DTO_INIT(FileLogDTO, DTO);

	// xid 日志唯一标识
	API_DTO_FIELD(String, xid, ZH_WORDS_GETTER("myfile.Filelog.xid"), true, { "233" });
	//xextension 上传类型'1-发送，2-分享，3-删除，4-上传',
	API_DTO_FIELD(Int32, xOperationType, ZH_WORDS_GETTER("myfile.Filelog.xoperationtype"), true, 0);
	//xlastUpdatePerson '发起者',
	API_DTO_FIELD(String, xFromPerson, ZH_WORDS_GETTER("myfile.Filelog.xFromPerson"), true, {});
	//xToPerson '接收者'
	API_DTO_FIELD(String, xToPerson, ZH_WORDS_GETTER("myfile.Filelog.xToPerson"), true, {});
	//xOperationTime 操作时间
	API_DTO_FIELD(String, xOperationTime, ZH_WORDS_GETTER("myfile.Filelog.xOperationTime"), true, {});
	//file_attachment_id  操作文件的唯一标识
	API_DTO_FIELD(String, file_attachment_id, ZH_WORDS_GETTER("myfile.Filelog.file_attachment_id"), true, {});
};
#include OATPP_CODEGEN_END(DTO)

#endif // !_FILEDTO_H_