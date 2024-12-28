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
	//�Ƿ��ͳɹ��ı�־
	bool send_status;
public:
	void receiveMessage(std::string payload) override {
		// ����JSON��Ϣ��DTO��
		RC_RECEIVER_MSG_CONVERT(dto, SystemInformDTO, payload);
		string id = dto->id.getValue("");
		string result = ServerInfo::getInstance().getWsInstanceListener()->sendMessage(id, payload);
		//������Ϣ��Ŀ���û�������
		if (result != "true") {
			// ��һ�� RocketMQ �����ߣ����ڷ���δ���͵���Ϣ
			RocketClient* unsendClient;
			//��ȡ����
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