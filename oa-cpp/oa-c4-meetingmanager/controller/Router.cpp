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
#include "meetingInfo/MeetingInfoController.h"
#ifdef HTTP_SERVER_DEMO
#include "user/UserController.h"
#include "sample/SampleController.h"
#include "file/FileController.h"
#include "ws/WSController.h"
#endif
#include"Meetingroom/Meetingroomcontroller.h"
#include "room/setting/RoomSettingController.h"
//<<<<<<< HEAD
#include "meeting/acceptrefuse/AcReController.h"
#include "meeting/end/EndController.h"
//=======
#include "meetingselect/MeetingSelectController.h"
#include "meetingroomselect/MeetingRoomSelectController.h"
#include "MEETING_ADD/AddMeetingController.h"
#include "MEETING_CANCEL/CancelMeetingController.h"
#include "meeting/checkinmeeting/CheckinMeetingController.h"
#include "metting/mettinglist/MettingListController.h" //��֪���Ƿ�������
#include "metting/mettingroom/MettingRoomController.h"
#include "metting/mettingroomlist/MettingRoomListController.h"
#include "meeting/uploadattachment/UploadAttachmentController.h"
#include "./Mtroompos/mtroomposcontroller.h"
#include "metting/mettingcreate/MettingCreateController.h" //��֪���Ƿ�������


//>>>>>>> d02c9778f6594f9bc78cd2fad0050ee8ac17fb5b

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
#endif

	//#TIP :ϵͳ��չ·�ɶ��壬д���������
	ROUTER_SIMPLE_BIND(RoomSettingController);
	ROUTER_SIMPLE_BIND(MeetingroomController);
	ROUTER_SIMPLE_BIND(EndController);
	ROUTER_SIMPLE_BIND(AcReController);
	//ROUTER_SIMPLE_BIND(RoomSettingController);
	ROUTER_SIMPLE_BIND(MeetingSelectController);
	ROUTER_SIMPLE_BIND(MeetingRoomSelectController);
	ROUTER_SIMPLE_BIND(AddMeetingController);
	ROUTER_SIMPLE_BIND(CancelMeetingController);
	ROUTER_SIMPLE_BIND(CheckinMeetingController);
	ROUTER_SIMPLE_BIND(MettingRoomController);
	ROUTER_SIMPLE_BIND(MettingRoomListController);
	ROUTER_SIMPLE_BIND(UploadAttachmentController);
	ROUTER_SIMPLE_BIND(MtroomposController);
	//ROUTER_SIMPLE_BIND(MettingListController);
	//ROUTER_SIMPLE_BIND(MettingCreateController);
	//#TIP :ϵͳ��չ·�ɶ��壬д���������
	ROUTER_SIMPLE_BIND(MeetingInfoController);
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
