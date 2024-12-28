/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/12/03 14:58:34

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
#include "Router.h"
#include "ApiHelper.h"

#ifdef HTTP_SERVER_DEMO
#include "user/UserController.h"
#include "sample/SampleController.h"
#include "file/FileController.h"
#include "ws/WSController.h"
#endif
//#include "OrgMemController.h"
//#include "OrgUnitController.h"
//#include "SelectOrgNameTreeController.h"
//#include "file/FileController.h"
//#include"../arch-organization/controller/OrgStructController/OrgStructController.h";
#include "AddDutyController.h"
#include "ModifyDutyController.h"
#include"OrgMemController.h";
#include"OrgUnitController.h"
#include"SelectOrgNameTreeController.h";
#include"Attrib_add/Attrib_add_Controller.h"
#include"Attrib_modify/Attrib_modify_Controller.h"
#include "OrgUnitattributeController.h"
#include "OrgUnitTree/OrgUnitTreeController.h"
#include "sort/SortByValueController.h"
#include "sort/SortByPinYinController.h"
#include "AddDutyController.h"
#include "ModifyDutyController.h"
#include "Org/OrgController.h"
#include "controller/OrgStructController/OrgStructController.h"
// 如果定义了关闭Swagger文档宏
#ifdef CLOSE_SWAGGER_DOC
// 简化绑定控制器宏定义
#define ROUTER_SIMPLE_BIND(__CLASS__) \
router->addController(__CLASS__::createShared())
#else
// 简化绑定控制器宏定义
#define ROUTER_SIMPLE_BIND(__CLASS__) \
BIND_CONTROLLER(docEndpoints, router, __CLASS__)
#endif

Router::Router(Endpoints* docEndpoints, HttpRouter* router)
{
	this->docEndpoints = docEndpoints;
	this->router = router;
}

void Router::initRouter()
{
#ifdef HTTP_SERVER_DEMO
	createSampleRouter();
#endif

#if 0
	//#TIP :系统扩展路由定义，写在这个后面
	//组织成员相关的控制器
	ROUTER_SIMPLE_BIND(OrgMemController);
	//组织信息相关的控制器
	////组织信息相关的控制器
	ROUTER_SIMPLE_BIND(OrgUnitController);
	ROUTER_SIMPLE_BIND(OrgController);
	ROUTER_SIMPLE_BIND(SelectOrgNameTreeController);
#endif
	//ROUTER_SIMPLE_BIND(OrgMemController);
	//ROUTER_SIMPLE_BIND(AttribController);
	//ROUTER_SIMPLE_BIND(OrgStructController);
	ROUTER_SIMPLE_BIND(OrgMemController);
	//ROUTER_SIMPLE_BIND(AddRoleController);
	//ROUTER_SIMPLE_BIND(ModifyRoleController);
	ROUTER_SIMPLE_BIND(OrgController);
	//组织属性相关控制器
	////组织属性相关控制器
	ROUTER_SIMPLE_BIND(OrgUnitattributeController);
	ROUTER_SIMPLE_BIND(AddDutyController);
	//ROUTER_SIMPLE_BIND(FileController);
	ROUTER_SIMPLE_BIND(ModifyDutyController);
	ROUTER_SIMPLE_BIND(OrgUnitController);
	ROUTER_SIMPLE_BIND(SelectOrgNameTreeController);
	ROUTER_SIMPLE_BIND(Attrib_add_Controller);
	ROUTER_SIMPLE_BIND(Attrib_modify_Controller);
	ROUTER_SIMPLE_BIND(OrgUnitTreeController);
	//根据组织排序值排序
	ROUTER_SIMPLE_BIND(SortByValueController);
	//根据拼音排序
	ROUTER_SIMPLE_BIND(SortByPinYinController);
	ROUTER_SIMPLE_BIND(OrgStructController);
}


#ifdef HTTP_SERVER_DEMO
void Router::createSampleRouter()
{
	// 绑定示例控制器
	ROUTER_SIMPLE_BIND(SampleController);
	// 绑定用户控制器
	ROUTER_SIMPLE_BIND(UserController);
	// 绑定文件控制器
	ROUTER_SIMPLE_BIND(FileController);
	ROUTER_SIMPLE_BIND(AddDutyController);
	ROUTER_SIMPLE_BIND(ModifyDutyController);
	// 绑定WebSocket控制器
	router->addController(WSContorller::createShared());
}
#endif