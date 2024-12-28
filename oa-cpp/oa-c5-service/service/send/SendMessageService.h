#pragma once

#ifndef _SENDMESSAGESERVICE_H_
#define _SENDMESSAGESERVICE_H_

#include "Macros.h"
#include "domain/dto/send/sendDTO.h"
#include <iostream>

class SendMessageService
{
public:
	bool sendMessage(const string code, const oatpp::String phone);
};


#endif // 
