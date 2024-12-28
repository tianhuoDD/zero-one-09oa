#pragma once
#ifndef _ADD_DEL_MEMBERCONTROLLER_H_
#define _ADD_DEL_MEMBERCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/add_del_PersonMember/MemberVO.h"
#include "service/Member/MemberServer.h"
#include"domain/dto/add_del_PersonMember/MemberDTO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class add_del_MemberController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(add_del_MemberController);
public:// 3 定义接口
	//定义添加接口描述
	ENDPOINT_INFO(addMember) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("add_del_PersonMember.post.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	//定义新增接口处理
	ENDPOINT(API_M_POST, "/add_Member", addMember, BODY_DTO(MemberDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddMember(dto));
	}
	//定义删除接口描述
	ENDPOINT_INFO(removeMember) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("add_del_PersonMember.delete.summary"), Uint64JsonVO::Wrapper);
		// 定义其他路径参数说明
		API_DEF_ADD_PATH_PARAMS(UInt64, "id", ZH_WORDS_GETTER("add_del_PersonMember.field.id"), 1, true);
	}
	// 定义删除接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/Member/{id}", removeMember, PATH(UInt64, id), execRemoveMember(id));
private:
	// 增加个人成员
	Uint64JsonVO::Wrapper execAddMember(const MemberDTO::Wrapper& dto);
	// 删除成员
	Uint64JsonVO::Wrapper execRemoveMember(const UInt64& id);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif //!_ADD_DEL_MEMBERCONTROLLER_H_