#pragma once
#ifndef _ATTACHMENTLIST_VO_
#define _ATTACHMENTLIST_VO_
#include "domain/GlobalInclude.h"
#include "AttachmentVO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 附件列表显示对象
 */
class AttachmentListVO : public oatpp::DTO {
	DTO_INIT(AttachmentListVO, DTO);

	//数据列表
	DTO_FIELD(List<AttachmentVO::Wrapper>, rows) = {};
	DTO_FIELD_INFO(rows) {
#ifndef LINUX
		info->description = u8"数据列表";
#else
		info->description = "data list";
#endif
	}
	void addData(const AttachmentVO::Wrapper& data) const {//向数据列表中加入数据
		rows->push_back(data);
	}
};

/**
 * 附件列表显示JsonVO，用于响应给客户端的Json对象
 */
class AttachmentListJsonVO : public JsonVO<AttachmentListVO::Wrapper> {
	DTO_INIT(AttachmentListJsonVO, JsonVO<AttachmentListVO::Wrapper>);
};



#include OATPP_CODEGEN_END(DTO)
#endif // !_ATTACHMENTLIST_VO_
