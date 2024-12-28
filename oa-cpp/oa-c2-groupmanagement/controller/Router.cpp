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

#include "./groupmanagement/GroupManagementController.h"


//#include "unitMember/addDel/AddDelUnitMemberController.h"
//#include "groupMember/addDel/AddDelGroupMemberController.h"

#ifdef HTTP_SERVER_DEMO
#include "user/UserController.h"
#include "sample/SampleController.h"
#include "file/FileController.h"
#include "ws/WSController.h"

#endif
//#include "organization/group/OrganizationGroupController.h"
//#include "interface/interfaceController.h"
//#include "groupmanagement/GroupManagementController.h"
//
////#include "organization/group/OrganizationGroupController.h"
//#include "groupmanagement/groupmanagementController.h"
//#include "test/testController.h"

//#include "organization/group/OrganizationGroupController.h"
//#include "interface/interfaceController.h"
//#include "test/testController.h"
//#include "groupInfo/groupInfoController.h"
//#include "groupInfo/groupInfoController.h"

//#include "groupInfo/groupInfoController.h"


// ��������˹ر�Swagger�ĵ���
#ifdef CLOSE_SWAGGER_DOC
// �򻯰󶨿������궨��
#define ROUTER_SIMPLE_BIND(__CLASS__) \
router->addController(__CLASS__::createShared())
#else
// �򻯰󶨿������궨��
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
	// ��ʾ��������
#endif
	// ��ʾ��������
	//ROUTER_SIMPLE_BIND(interfaceController);
	////#TIP :ϵͳ��չ·�ɶ��壬д���������
	//ROUTER_SIMPLE_BIND(GetGroupListController);
	//ROUTER_SIMPLE_BIND(AddGroupController);
	//ROUTER_SIMPLE_BIND(TestController);
	//ROUTER_SIMPLE_BIND(groupInfoController);
	//ROUTER_SIMPLE_BIND(OrganizationGroupController);
	//ROUTER_SIMPLE_BIND(AddDelUnitMemberController);
	//ROUTER_SIMPLE_BIND(AddDelGroupMemberController);
	//ROUTER_SIMPLE_BIND(groupInfoController);

	//ֻ����һ��
	ROUTER_SIMPLE_BIND(GroupManagementController);
	////ֻ����һ��
	//ROUTER_SIMPLE_BIND(GroupController);
}

#ifdef HTTP_SERVER_DEMO
void Router::createSampleRouter()
{
	// ��ʾ��������
	ROUTER_SIMPLE_BIND(SampleController);
	// ���û�������
	ROUTER_SIMPLE_BIND(UserController);
	// ���ļ�������
	ROUTER_SIMPLE_BIND(FileController);

	// ��WebSocket������
	router->addController(WSContorller::createShared());
}
#endif
