#pragma once

#ifndef _DeleteContents_CONTROLLER_
#define _DeleteContents_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
//#include "../../domain/query/sample/SampleQuery.h"
#include "domain/dto/remove/CdeleteDTO.h"
#include "domain/vo/remove/CdeleteVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class DeleteContentsController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(DeleteContentsController);
	// 3 定义接口
public:

	// 3.1 定义 删除目录 接口描述
	ENDPOINT_INFO(DeleteContent) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("Myfile.delete.summary"), StringJsonVO::Wrapper);
	}
	// 3.2 定义删除接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/companynetdisk/delete-folder/{xid}", DeleteContent, PATH(String, xid), execRemoveSample(xid));


	// 3.1 定义 重命名目录 接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("Myfile.rename.summary"), modifySample, StringJsonVO::Wrapper);
	// 3.2 定义修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/companynetdisk/modify-folder", modifySample, BODY_DTO(CdeleteDTO::Wrapper, dto), execModifySample(dto, authObject->getPayload()));
private:
	// 删除目录 接口 执行函数
	StringJsonVO::Wrapper execRemoveSample(const String& xid);
	// 重命名目录 接口 执行函数
	StringJsonVO::Wrapper execModifySample(const CdeleteDTO::Wrapper& dto, const PayloadDTO& payload);
	//StringJsonVO
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_


