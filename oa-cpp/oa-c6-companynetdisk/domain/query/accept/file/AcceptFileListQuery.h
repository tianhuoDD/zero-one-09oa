#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/12/03 11:01:02

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
#ifndef _ACCEPTFILELIST_QUERY_H_
#define _ACCEPTFILELIST_QUERY_H_

#include "../../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例分页查询对象
 */
class AcceptFileListQuery : public PageQuery
{
	// 定义初始化
	DTO_INIT(AcceptFileListQuery, PageQuery);
	//文件名
	DTO_FIELD(String, xname);
	DTO_FIELD_INFO(xname) {
		info->description = ZH_WORDS_GETTER("accept.file.name");
	}
	// 上传用户唯一id
	DTO_FIELD(String, xid);
	DTO_FIELD_INFO(xid) {
		info->description = ZH_WORDS_GETTER("accept.file.upload");
	}
	//用户名名字
	DTO_FIELD(String, xperson);
	DTO_FIELD_INFO(xperson) {
		info->description = ZH_WORDS_GETTER("accept.user.name");
	}
	//文件上传时间
	DTO_FIELD(String, xcreateTime);
	DTO_FIELD_INFO(xcreateTime) {
		info->description = ZH_WORDS_GETTER("accept.file.unload");
	}
	//文件修改时间
	DTO_FIELD(String, xlastupdateTime);
	DTO_FIELD_INFO(xlastupdateTime) {
		info->description = ZH_WORDS_GETTER("accept.file.changed");
	}

	//文件大小
	DTO_FIELD(Int64, xlength);
	DTO_FIELD_INFO(xlength) {
		info->description = ZH_WORDS_GETTER("accept.file.size");
	}
	////文件分享
	//DTO_FIELD(String, xlength);
	//DTO_FIELD_INFO(xlength) {
	//	info->description = ZH_WORDS_GETTER("accept.file.share");
	//}
	////文件发送
	//DTO_FIELD(String, xlength);
	//DTO_FIELD_INFO(xlength) {
	//	info->description = ZH_WORDS_GETTER("accept.file.send");
	//}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_