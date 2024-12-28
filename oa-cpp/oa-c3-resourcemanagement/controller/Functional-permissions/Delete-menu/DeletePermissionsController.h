#pragma once
#ifndef _DELETECONTROLLER_H_
#define _DELETECONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"//导入领域模型的basejson
#include "../../../domain/GlobalInclude.h"
#include "../../../domain/dto/Functional-permissions/Delete-menu/DeletemenuDTO.h"
#include "../../../domain/vo/Functional-permissions/Delete-menu/DeletemenuVO.h"
#include "oatpp/web/server/api/ApiController.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController)//oatp中的apiController

class DeletePermissionsController :public oatpp::web::server::api::ApiController//继承aipController
{
    //定义控制器访问入口
    API_ACCESS_DECLARE(DeletePermissionsController);
public: //定义接口/端点
    // 3.1 定义删除接口描述
    ENDPOINT_INFO(DeletemenuPermissions) {
        // 定义标题和返回类型以及授权支持
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("Functional-permissions.Delete-menu.delete.summary"));
        // 定义其他路径参数说明
        API_DEF_ADD_AUTH();
        API_DEF_ADD_RSP_JSON_WRAPPER(DeletemenuJsonVO);
    }
    ///////////////////////////////
    // 3.2 定义删除接口处理
    
    ENDPOINT(API_M_DEL, "resource-management/functional-permissions/delete-menu", DeletemenuPermissions, BODY_DTO(DeletemenuDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
        //解析参数                                                        //BODY_DTO这里要自己写具体的领域模型了
        API_HANDLER_RESP_VO(execDeletemenu(dto));

    }
private://定义接口执行函数
   
    DeletemenuJsonVO::Wrapper execDeletemenu(const DeletemenuDTO::Wrapper& dto);
};
#include OATPP_CODEGEN_END(ApiController)
#endif//!_TESTCONTROLLER_H_

