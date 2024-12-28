#pragma once
#ifndef _USERDO_H_
#define _USERDO_H_

#include "../DoInclude.h"
/**
 * ���Բ˵����ݿ�ʵ��
 */
class UserDO
{
	// ��Ա����
	CC_SYNTHESIZE(string, name, Name);
	// ��Ա����
	CC_SYNTHESIZE(uint64_t, id, Id);
	// �ֻ�����
	CC_SYNTHESIZE(string, phone, Phone);
	// �ʼ���ַ
	CC_SYNTHESIZE(string, mail, Mail);
public:
	/*UserDO() {}
	UserDO(string id, string name, string phone, string mail)
	{
		this->id = id;
		this->name = name;
		this->phone = phone;
		this->mail = mail;
	}*/
	UserDO() {
		id = 0;
		name = "";
		phone = "";
		mail = "";
	}
};

#endif // !_USERDO_H_