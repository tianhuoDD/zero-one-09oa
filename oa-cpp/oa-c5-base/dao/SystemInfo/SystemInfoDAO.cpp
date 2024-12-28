// MongoDB使用需要的相关头文件
#include "Macros.h"
#include "ServerInfo.h"
#include "NacosClient.h"
#include "MongoClient.h"
#include <iostream>
#include <bsoncxx/json.hpp>


#include "SystemInfoDAO.h"
#include "ServerInfo.h"


//修改系统副标题
bool SysteminfoDAO::modifySystemSubtitle(const SystemInfoDTO::Wrapper& dto)
{
	// 获取配置
	// 创建ServerInfo类的对象
	ServerInfo& serverInfo = ServerInfo::getInstance();
	// 通过对象调用成员函数获取nacosAddr
	string nacosAddr = serverInfo.getNacosAddr();
	// 通过对象调用成员函数获取NacosAddr
	string NacosAddr = serverInfo.getNacosNs();

	NacosClient nacosClient(nacosAddr, NacosAddr);
#ifdef LINUX
	YAML::Node node = nacosClient.getConfig("data-source.yaml");
#else
	YAML::Node node = nacosClient.getConfig("./conf/data-source.yaml");
#endif
	// 获取mongodb相关配置
	YamlHelper yaml;
	string uri = yaml.getString(&node, "spring.data.mongodb.uri");

	// 创建连接对象
	MongoClient* mc = new MongoClient(uri);
	using namespace bsoncxx::builder::basic;
	auto res = mc->execute("sang_collect",
		[&](mongocxx::collection* collection) {
			try {
				// 构建筛选条件
				auto update_doc = make_document(kvp("$set", make_document(kvp("subtitle", dto->subtitle.getValue("")))));
				auto result = collection->update_one({}, update_doc.view());
				if (result->matched_count()){//如果成功修改数据
					return true;
				}
				else {
					// 创建数据
					auto result = collection->insert_one(make_document(kvp("subtitle", dto->subtitle.getValue(""))));
					return true;
				}

			}
			catch (const std::exception& e) {
				std::cerr << "Error updating subtitle: " << e.what() << std::endl;
				return false;
			}
		});
	return 1;
}

//修改系统名称
bool SysteminfoDAO::modifySystemName(const SystemInfoDTO::Wrapper& dto)
{
	// 获取配置
	// 创建ServerInfo类的对象
	ServerInfo& serverInfo = ServerInfo::getInstance();
	// 通过对象调用成员函数获取nacosAddr
	string nacosAddr = serverInfo.getNacosAddr();
	// 通过对象调用成员函数获取NacosAddr
	string NacosAddr = serverInfo.getNacosNs();

	NacosClient nacosClient(nacosAddr, NacosAddr);
#ifdef LINUX
	YAML::Node node = nacosClient.getConfig("data-source.yaml");
#else
	YAML::Node node = nacosClient.getConfig("./conf/data-source.yaml");
#endif
	// 获取mongodb相关配置
	YamlHelper yaml;
	string uri = yaml.getString(&node, "spring.data.mongodb.uri");

	// 创建连接对象
	MongoClient* mc = new MongoClient(uri);
	using namespace bsoncxx::builder::basic;
	auto res = mc->execute("sang_collect",
		[&](mongocxx::collection* collection) {
			try {
				// 构建筛选条件
				auto update_doc = make_document(kvp("$set", make_document(kvp("name", dto->name.getValue("")))));
				auto result = collection->update_one({}, update_doc.view());
				if (result->matched_count()) {//如果成功修改数据
					return true;
				}
				else {
					// 创建数据
					auto result = collection->insert_one(make_document(kvp("name", dto->name.getValue(""))));
					return true;
				}

			}
			catch (const std::exception& e) {
				std::cerr << "Error updating name: " << e.what() << std::endl;
				return false;
			}
		});
	return 1;
}
