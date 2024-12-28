#include "stdafx.h"
#include "SendController.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "Macros.h"
#include "NacosClient.h"
#include "EmailSender.h"
#include "../../ServerInfo.h"


StringJsonVO::Wrapper SendController::execSendMail(const SendQuery::Wrapper& query, const PayloadDTO& payload) {
	auto jvo = StringJsonVO::createShared();

	if (std::string(query->type->c_str()) == ZH_WORDS_GETTER("send.typename.mail"))
	{
		// 发送邮件
		/** 定义一个Nacos客户端对象，用于获取配置 */
		NacosClient _ns(ServerInfo::getInstance().getNacosAddr(), ServerInfo::getInstance().getNacosNs());
		/** 读取配置数据节点 */
		auto _keyConfig = _ns.getConfig("key-config.yaml");
		/** 定义客户端对象 */
		YamlHelper _yh;
		EmailSender emailSender(
			_yh.getString(&_keyConfig, "spring.mail.host"),
			std::stoi(_yh.getString(&_keyConfig, "spring.mail.port")),
			_yh.getString(&_keyConfig, "spring.mail.password"),
			_yh.getString(&_keyConfig, "spring.mail.username"),
			_yh.getString(&_keyConfig, "spring.mail.properties.name"));
		emailSender.setCharset("utf8");
		std::string body = ZH_WORDS_GETTER("email.body1");
		emailSender.addRecvEmailAddr(query->mail->c_str());
		emailSender.setEmailContent(query->code->c_str(), body);
		if (emailSender.send())
		{
			jvo->success("success");
		}
		else
		{
			jvo->fail("fail");
		}
	}
	else
	{
		jvo->fail("unkown type");
	}

	return jvo;
}

SendJsonVO::Wrapper SendController::execSendMessage(const SendDTO::Wrapper& dto)
{
    auto jvo = SendJsonVO::createShared();
    if (dto->phone->empty())
    {
        jvo->init({}, RS_PARAMS_INVALID);
        return jvo;
    }
    auto list = dto->phone.get();
    for (auto item : *list)
    {
        if (!validatePhoneNumber(item.getValue({})))
        {
            jvo.get()->data->type = "invalid phone number.";
            jvo->init({}, RS_PARAMS_INVALID);
            return jvo;
        }
    }

    SendMessageService service;
    uint64_t res = 0;

    for (size_t i = 0; i < list->size(); i++)
    {
        res += service.sendMessage(dto->code[i].getValue({}), dto->phone[i].getValue({}));
    }
    if (res)
    {
        jvo->success({});
    }
    else
    {
        jvo->fail({});
    }
    return jvo;
}

bool SendController::validatePhoneNumber(const std::string& phoneNumber) {
    // 正则表达式：以1开头，后面跟9位数字
    std::regex phone_regex("^1[3-9]\\d{9}$");

    std::smatch matchResult;

    // 正则匹配
    if (std::regex_match(phoneNumber, matchResult, phone_regex)) {
        // 打印子表达式结果
        for (size_t i = 0; i < matchResult.size(); ++i) {
            std::cout << "Match: " << matchResult[i] << std::endl;
        }
        return true; // 验证成功
    }
    else {
        std::cout << "Not Match!" << std::endl;
        return false; // 验证失败
    }
}