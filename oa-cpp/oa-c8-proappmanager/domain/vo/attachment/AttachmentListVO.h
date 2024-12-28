#pragma once
#ifndef _ATTACHMENTLIST_VO_
#define _ATTACHMENTLIST_VO_
#include "domain/GlobalInclude.h"
#include "AttachmentVO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �����б���ʾ����
 */
class AttachmentListVO : public oatpp::DTO {
	DTO_INIT(AttachmentListVO, DTO);

	//�����б�
	DTO_FIELD(List<AttachmentVO::Wrapper>, rows) = {};
	DTO_FIELD_INFO(rows) {
#ifndef LINUX
		info->description = u8"�����б�";
#else
		info->description = "data list";
#endif
	}
	void addData(const AttachmentVO::Wrapper& data) const {//�������б��м�������
		rows->push_back(data);
	}
};

/**
 * �����б���ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class AttachmentListJsonVO : public JsonVO<AttachmentListVO::Wrapper> {
	DTO_INIT(AttachmentListJsonVO, JsonVO<AttachmentListVO::Wrapper>);
};



#include OATPP_CODEGEN_END(DTO)
#endif // !_ATTACHMENTLIST_VO_
