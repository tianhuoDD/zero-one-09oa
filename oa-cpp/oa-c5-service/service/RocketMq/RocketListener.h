#pragma once
#ifndef _ROCKETLISTENER_H_
#define _ROCKETLISTENER_H_

#include <iostream>
#include "Macros.h"
#include "NacosClient.h"
#include "../../domain/dto/System/inform/SystemInformDTO.h"
#include "RocketClient.h"
#include "../../controller/WSocket/WSInstanceListener.h"


class RocketListener : public RocketClient::RConsumerListener {
private:
	//是否发送成功的标志
	bool send_status;
public:
	void receiveMessage(std::string payload) override {
		// 解析JSON消息到DTO中
		RC_RECEIVER_MSG_CONVERT(dto, SystemInformDTO, payload);
		string id = dto->id.getValue("");
		string result = ServerInfo::getInstance().getWsInstanceListener()->sendMessage(id, payload);
		//发送消息的目标用户不在线
		if (result != "true") {
			// 另一个 RocketMQ 生产者，用于发送未发送的消息
			RocketClient* unsendClient;
			//获取配置
			NacosClient nacosClient(TEST_NS_ADDR, TEST_NS_NAMESPACE);
#ifdef LINUX
			YAML::Node node = nacosClient.getConfig("third-services.yaml");
#else
			YAML::Node node = nacosClient.getConfig("./conf/third-services.yaml");
#endif
			string namesrv = YamlHelper().getString(&node, "rocket-mq.name-server");
			unsendClient = new RocketClient(namesrv);
			unsendClient->productMsgSync("unsend", result);
			delete unsendClient;
		}
	}
};


#endif // !_ROCKETLISTENER_H_