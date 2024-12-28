//#ifdef USE_MONGO
//
//// MongoDB使用需要的相关头文件
//#include "Macros.h"
//#include "NacosClient.h"
//#include "MongoClient.h"
//#include <iostream>
//#include <bsoncxx/json.hpp>
//#include "ServerInfo.h"
//
//#include "gtest/gtest.h"
//
//void testMongo()
//{
//	MongoClient c("mongodb://localhost:27017/user");
//	using namespace bsoncxx::builder::basic;
//	std::vector<bsoncxx::document::value> password_settings;
//    // 密码配置页面上的字段
//    password_settings.push_back(make_document(
//        kvp("field_name", "新创建用户的初始密码"),
//        kvp("description", "创建新用户时, 会按以下设定生成用户初始密码, 用户可登录系统后自行修改")
//    ));
//
//    password_settings.push_back(make_document(
//        kvp("field_name", "用户初始密码"),
//        kvp("value", "手机号码后六位") // 假设这是输入框里的值
//    ));
//
//    password_settings.push_back(make_document(
//        kvp("field_name", "密码过期天数"),
//        kvp("description", "超过此设定天数未修改密码的用户, 登录后会强制要求修改密码, 否则无法进入系统。设置为0表示密码永不过期")
//    ));
//
//    password_settings.push_back(make_document(
//        kvp("field_name", "编辑密码过期天数"),
//        kvp("current_value", 0), // 当前显示的天数
//        kvp("action", "点击按钮以编辑") // 描述操作
//    ));
//
//    password_settings.push_back(make_document(
//        kvp("field_name", "密码复杂度设置"),
//        kvp("description", "设置用户密码强度要求")
//    ));
//
//    password_settings.push_back(make_document(
//        kvp("field_name", "密码长度"),
//        kvp("min_length", 20),
//        kvp("max_length", 30)
//    ));
//
//    password_settings.push_back(make_document(
//        kvp("field_name", "密码规则"),
//        kvp("rule", "必须包含小写字母"),
//        kvp("rule", "必须包含数字"),
//        kvp("rule", "必须包含大写字母"), 
//        kvp("enabled", false),
//        kvp("rule", "必须包含特殊字符(#?!@$%^&*-等)"), 
//        kvp("enabled", false)
//
//    password_settings.push_back(make_document(
//        kvp("field_name", "密码加密传输"),
//        kvp("description", "系统默认使用明文传输, 您可以启用此选项, 以启用密码的加密传输。(修改后需要重启服务器)")
//    ));
//
//    password_settings.push_back(make_document(
//        kvp("field_name", "密码加密传输开关"),
//        kvp("status", "禁用") // 假设当前状态是禁用
//    ));
//
//    password_settings.push_back(make_document(
//        kvp("field_name", "密码强制修改"),
//        kvp("description", "如需需要用户首次登录的时候强制修改密码, 可以开启此选项")
//    ));
//
//    password_settings.push_back(make_document(
//        kvp("field_name", "密码强制修改开关"),
//        kvp("status", "禁用") // 假设当前状态是禁用
//    ));
//
//	c.addMultiple("myCollection", password_settings);
//}
//#endif // USE_MONGO
