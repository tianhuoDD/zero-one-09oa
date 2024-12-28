#pragma once

#ifndef _ROLERESOURCEDO_H_
#define _ROLERESOURCEDO_H_

//#include "../DoInclude.h"
#include "../../DoInclude.h"		

class RoleResourceDO
{
	//��Դid
	CC_SYNTHESIZE(string, id, Id);
	// ��Դ�ı�����
	CC_SYNTHESIZE(string, text, Text);
	// ͼ������
	CC_SYNTHESIZE(uint32_t, is_button, Is_button);
	// �˵�����
	CC_SYNTHESIZE(uint32_t, menu_type, Menu_type);
	// ���ڵ�ID  ����Դ
	CC_SYNTHESIZE(string, parentId, ParentId);

public:
	RoleResourceDO(){}
	RoleResourceDO(string id, string text, uint32_t Is_button, uint32_t Menu_type, string parentId)
	{
		this->id = id;
		this->text = text;
		this->is_button = Is_button;
		this->menu_type = Menu_type;
		this->parentId = parentId;
	}
};






#endif // !_ROLERESOURCEDO_H_
