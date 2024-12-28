#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: siri
 @Date: 2024/10/20 19:30:58

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _UPLOADATTACHMENTVO_H_
#define _UPLOADATTACHMENTVO_H_

#include "../../../GlobalInclude.h"
#include "../../../dto/meeting/uploadattachment/UploadAttachment.h"

#include OATPP_CODEGEN_BEGIN(DTO)

///**
// * 上传文件信息显示对象   ？？？？好像不需要
// */
//class UploadAttachmentVO : public oatpp::DTO
//{
//	DTO_INIT(UploadAttachmentVO, DTO);
//	// 附件src
//	API_DTO_FIELD(String, url, ZH_WORDS_GETTER("file.field.attachment-url"), true, {});
//	// 附件文字描述
//	API_DTO_FIELD_DEFAULT(String, alt, ZH_WORDS_GETTER("file.field.attachment-alt"));
//};
//
///**
// * 上传文件信息显示VO，用于响应给客户端的Json结果   ？？？？好像不需要
// */
//class UploadAttachmentJsonVO : public JsonVO<UploadAttachmentVO::Wrapper>
//{
//	DTO_INIT(UploadAttachmentJsonVO, JsonVO<UploadAttachmentVO::Wrapper>);
//};

#include OATPP_CODEGEN_END(DTO)

#endif // !_UPLOADATTACHMENTVO_H_