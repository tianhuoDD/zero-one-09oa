#include "UserPasswordDAO.h"
#include "ServerInfo.h"
#include "NacosClient.h"
#include "MongoClient.h"
#include <iostream>
#include <bsoncxx/json.hpp>

bool UserPasswordDAO::modifyUserPasswordSettings(const UserPasswordDTO::Wrapper& dto) {
    ServerInfo& serverInfo = ServerInfo::getInstance();
    std::string nacosAddr = serverInfo.getNacosAddr();
    std::string NacosAddr = serverInfo.getNacosNs();

    NacosClient nacosClient(nacosAddr, NacosAddr);
#ifdef LINUX
    YAML::Node node = nacosClient.getConfig("data-source.yaml");
#else
    YAML::Node node = nacosClient.getConfig("./conf/data-source.yaml");
#endif

    YamlHelper yaml;
    std::string uri = yaml.getString(&node, "spring.data.mongodb.uri");

    MongoClient mc(uri);
    using namespace bsoncxx::builder::basic;

    auto res = mc.execute("sang_collect", [&](mongocxx::collection* collection) {
        try {
            // 使用字段名和 DTO 中的值，更新所有需要更新的字段
            auto updateDoc = make_document(
                kvp("$set", make_document(
                    kvp("init_password_description", dto->init_password_description),
                    kvp("init_password_value", dto->init_password_value),
                    kvp("expiry_days_description", dto->expiry_days_description),
                    kvp("expiry_days", dto->expiry_days),
                    kvp("complexity_description", dto->complexity_description),
                    kvp("min_length", dto->min_length),
                    kvp("max_length", dto->max_length),
                    kvp("rule_lowercase", dto->rule_lowercase),
                    kvp("rule_number", dto->rule_number),
                    kvp("rule_uppercase", dto->rule_uppercase),
                    kvp("rule_special_character", dto->rule_special_character),
                    kvp("encryption_description", dto->encryption_description),
                    kvp("encryption_status", dto->encryption_status),
                    kvp("force_change_description", dto->force_change_description),
                    kvp("force_change_status", dto->force_change_status)
                ))
            );

            auto result = collection->update_one({}, updateDoc.view());

            if (result->matched_count() == 0) {
                collection->insert_one(make_document(
                    kvp("init_password_description", dto->init_password_description),
                    kvp("init_password_value", dto->init_password_value),
                    kvp("expiry_days_description", dto->expiry_days_description),
                    kvp("expiry_days", dto->expiry_days),
                    kvp("complexity_description", dto->complexity_description),
                    kvp("min_length", dto->min_length),
                    kvp("max_length", dto->max_length),
                    kvp("rule_lowercase", dto->rule_lowercase),
                    kvp("rule_number", dto->rule_number),
                    kvp("rule_uppercase", dto->rule_uppercase),
                    kvp("rule_special_character", dto->rule_special_character),
                    kvp("encryption_description", dto->encryption_description),
                    kvp("encryption_status", dto->encryption_status),
                    kvp("force_change_description", dto->force_change_description),
                    kvp("force_change_status", dto->force_change_status)
                ));
            }

            return true;
        }
        catch (const std::exception& e) {
            std::cerr << "Error updating password settings: " << e.what() << std::endl;
            return false;
        }
        });

    return res;
}
