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
#include "OrgManagement/PersonalManagementController.h"
#include"AddPerson/AddPerson.h"
#include"DeletePerson/DeletePerson.h"
#include "./PersonalManageInfo/PersonalManageInfoController/PersonalManageInfoController.h"

#include "ChangePersonProfile/ChangePersonProfileController.h"
#include "DisableUnbanPerson/DisableUnbanPersonController.h"

#include "modify/modify_personal_identityController.h"
#include "modify/modify_lockorunlock_officerController.h"
#include "list/list_personal_identityController.h"
#ifdef HTTP_SERVER_DEMO
#include "user/UserController.h"
#include "sample/SampleController.h"
#include "file/FileController.h"
#include "ws/WSController.h"
#endif

// 如果定义了关闭Swagger文档宏
#include "gets-person-lists/PersonlistController.h"
#include "PasswdExpiredTime/PasswdExpiredTimeController.h"
#include "ResetPasswd/ResetPasswdController.h"
#include "PersonAttribute/PersonAttributeController.h"// 如果定义了关闭Swagger文档宏
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

	//#TIP :系统扩展路由定义，写在这个后面
	ROUTER_SIMPLE_BIND(PersonManagementController);
	ROUTER_SIMPLE_BIND(PersonlistController);
	/**
	 * 密码到期时间
	 * 负责人: 。好
	 */
	ROUTER_SIMPLE_BIND(PasswdExpiredTimeController);

	ROUTER_SIMPLE_BIND(PersonManagementController);
	/*
	/ 更改人员头像，负责人：HY
	*/
	ROUTER_SIMPLE_BIND(ChangePersonProfileController);
	ROUTER_SIMPLE_BIND(DisableUnbanPersonController);
	ROUTER_SIMPLE_BIND(PersonlistController);
	/**
	 * 密码到期时间
	 * 负责人: 。好
	 */
	ROUTER_SIMPLE_BIND(PasswdExpiredTimeController);

	/**
	 * 重置人员密码
	 * 负责人：。好
	 */
	ROUTER_SIMPLE_BIND(ResetPasswdController);
	
	/**
	 * 人员属性
	 * 负责人：zygg
	 */
	ROUTER_SIMPLE_BIND(PersonAttributeController);
	ROUTER_SIMPLE_BIND(AddPersonController);
	ROUTER_SIMPLE_BIND(DeletePersonController);
	ROUTER_SIMPLE_BIND(PersonalManageInfoController); 


	/**
	 * 重置人员密码
	 * 负责人：。好
	 */
	ROUTER_SIMPLE_BIND(ResetPasswdController);
	
	/**
	 * 人员属性
	 * 负责人：zygg
	 */
	ROUTER_SIMPLE_BIND(PersonAttributeController);
	ROUTER_SIMPLE_BIND(AddPersonController);
	ROUTER_SIMPLE_BIND(DeletePersonController);
	ROUTER_SIMPLE_BIND(PersonalManageInfoController); 

	/**
	 * 修改个人身份
	 * 负责人：upup
	 */
	ROUTER_SIMPLE_BIND(modify_personalidentityController);
	/**
	 * 锁定/解锁人员
	 * 负责人：upup
	 */
	ROUTER_SIMPLE_BIND(modify_lockorunlock_officerController);
	/**
	 * 获取个人身份（分页）
	 * 负责人：upup
	 */
	ROUTER_SIMPLE_BIND(list_personal_identityController);

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
	
	// 绑定WebSocket控制器
	router->addController(WSContorller::createShared());
}
#endif
