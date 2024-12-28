#include "SendMessageService.h"
#include "sms/aliyun/AliSmsSender.h"
#include "sms/aliyun/AliKeyConfig.h"
#include "dao/send/SendMessageDAO.h"


bool SendMessageService::sendMessage(const string code,const oatpp::String phone)
{
	AliSmsSender sender;
	bool result = false;
	// 注意：因为参数中有中文字符，所以所有中文字从中文词典中获取，不然会发送短信失败
#if 0
	std::cout << std::endl;
	std::cout << AliKeyConfig::region << std::endl;
	std::cout << AliKeyConfig::ak << std::endl;
	std::cout << AliKeyConfig::sk << std::endl;
	std::cout << std::endl;
#endif
	string strCode = "{\"code\":\"" + code + "\"}";
	std::cout << "strCode:  " << strCode << std::endl;
	std::shared_ptr<AliSmsResult> res = sender.sendSms(phone, "01oa", "SMS_475025636", strCode);
	SendMessageDAO dao;
	std::cout <<"res->code: " << res->Code() << std::endl;
	if (res->Code()=="OK")
	{
		std::cout
			<< "code:  " << res->Code() << std::endl
			<< "msg:   " << res->Message() << std::endl
			<< "bizid: " << res->BizId() << std::endl
			<< "reqid: " << res->RequestId() << std::endl;
		bool re = dao.insertMessage(code,phone);
		if (re)
		{
			result = true;
		}
	}

	return result;
}
