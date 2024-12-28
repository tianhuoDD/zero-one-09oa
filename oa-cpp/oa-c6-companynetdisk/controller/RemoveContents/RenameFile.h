#pragma once

#ifndef _RenameFile_CONTROLLER_
#define _RenameFile_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
//#include "../../domain/query/sample/SampleQuery.h"
#include "domain/dto/remove/DdeleteDTO.h"
#include "domain/vo/remove/DdeleteVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen
/**
 * 示例控制器，演示基础接口的使用
 */
class RenameFileController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(RenameFileController);
	// 3 定义接口
public:
	// 3.1 定义 重命名文件 接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("Myfile.rename.summary_file"), modifySample, StringJsonVO::Wrapper);
	// 3.2 定义修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/companynetdisk/modify-file", modifySample, BODY_DTO(DdeleteDTO::Wrapper, dto), execModifySample(dto, authObject->getPayload()));
private:
	// 重命名文件 接口 执行函数
	StringJsonVO::Wrapper execModifySample(const DdeleteDTO::Wrapper& dto, const PayloadDTO& payload);
	//StringJsonVO
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_

