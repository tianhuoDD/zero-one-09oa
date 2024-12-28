/*
 Copyright Zero One Star. All rights reserved.

 @Author: amie
 @Date: 2023/02/20 16:29:31

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
#include "stdafx.h"
#include "AttachmentController.h"
#include "oatpp/core/utils/ConversionUtils.hpp"
#include <iostream>
#include <sstream>

// FastDFS需要导入的头
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"

/**
 * 注意：这里的部分代码本应该放到service层中，为了方便演示就写在一起了
 */

AddAttachmentJsonVO::Wrapper AttachmentController::execAddAttachment(const AddAttachmentDTO::Wrapper& dto)
{
	// 定义一个JsonVO对象
	auto vo = AddAttachmentJsonVO::createShared();
	return vo;
}
UpdateAttachmentJsonVO::Wrapper AttachmentController::execUpdateAttachment(const UpdateAttachmentDTO::Wrapper& dto2)
{
	auto vo = UpdateAttachmentJsonVO::createShared();
	return vo;
}