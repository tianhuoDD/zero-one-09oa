#pragma once
#ifndef _ADDMENUCONTROLLER_H_
#define _ADDMENUCONTROLLER_H_

//#include "domain/vo/BaseJsonVO.h"//导入领域模型的basejson
#include "../../lib-oatpp/include/domain/vo/BaseJsonVO.h"
#include "../../../domain/vo/Functional-permissions/Add-menu/AddmenuVO.h"
#include "../../../domain/dto/Functional-permissions/Add-menu/AddmenuDTO.h"
//#include "domain/GlobalInclude.h"
#include "../../../domain/GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(ApiController)//oatp中的apiController

class AddPermissionsController :public oatpp::web::server::api::ApiController//继承aipController
{
    //定义控制器访问入口
    API_ACCESS_DECLARE(AddPermissionsController);
public: //定义接口/端点
  
    // 3.1 定义新增接口描述
    ENDPOINT_INFO(AddmenuPermissions) {
        // 定义接口标题
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("Functional-permissions.Add-menu.post.summary"));//中文词典中寻找
        // 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
        API_DEF_ADD_AUTH();
        // 定义响应参数格式
        //这个应该自己写一个VO响应格式为添加权限成功
        //要导入VO的头文件
        API_DEF_ADD_RSP_JSON_WRAPPER(AddmenuJsonVO);
    }
    ///////////////////////////////
    //定义新增接口处理
    ENDPOINT(API_M_POST, "resource-management/functional-permissions/add-menu", AddmenuPermissions, BODY_DTO(AddmenuDTO::Wrapper, dto),API_HANDLER_AUTH_PARAME) {
        //解析参数                                                        //BODY_DTO这里要自己写具体的领域模型了
        API_HANDLER_RESP_VO(execAddmenu(dto));
      
    }

private://定义接口执行函数
    
    AddmenuJsonVO::Wrapper execAddmenu(const AddmenuDTO::Wrapper& dto);
};
#include OATPP_CODEGEN_END(ApiController)
#endif//!_TESTCONTROLLER_H_
