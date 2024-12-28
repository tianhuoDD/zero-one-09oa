#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/12/09 20:32:13

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
#ifndef _OTHERCOMMPONENT_H_
#define _OTHERCOMMPONENT_H_
#include "AbstractComponentReg.h"


#include "oatpp-websocket/ConnectionHandler.hpp"
#include "oatpp/web/client/HttpRequestExecutor.hpp"
#include "oatpp/network/tcp/client/ConnectionProvider.hpp"
#include "ServerInfo.h"



/**
 * ����Oatpp���ע�ḽ�������������Ҫ�������������������������ⲿ����
 */
class OtherComponent : public AbstractComponentReg
{
	
	//// ����һ��WebSocket���������ʾWebSocket��ʹ��
	//OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::network::ConnectionHandler>, websocketConnectionHandler)("websocket", [] {
	//	auto connectionHandler1 = oatpp::websocket::ConnectionHandler::createShared();
	//	connectionHandler1->setSocketInstanceListener(std::make_shared<WSInstanceListener>());
	//	return connectionHandler1;
	//	}());
	// ����һ��ʾ��RequestExecutor������ڷ���api����
	OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::web::client::HttpRequestExecutor>, sampleApiExecutor)("sample-api", [] {
		auto connectionProvider = oatpp::network::tcp::client::ConnectionProvider::createShared({ "192.168.31.99", 10100 });
		return oatpp::web::client::HttpRequestExecutor::createShared(connectionProvider);
		}());

	//������Ϣ�м���ڵ���Ϣ
    OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::network::ConnectionHandler>, websocketConnectionHandler)("sendMessage", [] {
        auto connectionHandler = oatpp::websocket::ConnectionHandler::createShared();
    ServerInfo::getInstance().setWsInstanceListener(std::make_shared<WSInstanceListener>());
    connectionHandler->setSocketInstanceListener(ServerInfo::getInstance().getWsInstanceListener());
    return connectionHandler;
        }());

};

#endif // _OTHERCOMMPONENT_H_