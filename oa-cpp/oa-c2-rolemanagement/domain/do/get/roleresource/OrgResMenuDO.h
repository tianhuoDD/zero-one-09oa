#pragma once

#ifndef _ORGRESMENUDO_H_
#define _ORGRESMENUDO_H_

#include "../../DoInclude.h"

class OrgResMenuDO
{
	//�˵�id
	CC_SYNTHESIZE(string, menu_id, Menu_id);
	// �˵�����
	CC_SYNTHESIZE(string, menu_name, Menu_name);
	// �˵�������(1Ϊ��ͨ�˵�2ΪĿ¼3Ϊ��ǶiFrame4Ϊ������ת)
	CC_SYNTHESIZE(string, menu_type, Menu_type);
	// ���˵�id
	CC_SYNTHESIZE(string, parent_id, Parent_id);
	// �Ƿ�ť
	CC_SYNTHESIZE(string, is_button, Is_button);
	// Ȩ�ޱ�־
	CC_SYNTHESIZE(string, permission, Permission);
	// �˵�״̬��1����  0ͣ�ã�
	CC_SYNTHESIZE(string, status, Status);
	// ��ע
	CC_SYNTHESIZE(string, remark, Remark);
	// ������id
	CC_SYNTHESIZE(string, creator_id, Creator_id);
	// ����ʱ��
	CC_SYNTHESIZE(string, create_time, Create_time);
	//������id
	CC_SYNTHESIZE(string, updater_id, Updater_id);
	//����ʱ��
	CC_SYNTHESIZE(string, update_time, Update_time);
	//�߼�ɾ��
	CC_SYNTHESIZE(string, deleted, Deleted);


public:
	OrgResMenuDO(){}
	OrgResMenuDO(string menuID, string menuName, uint16_t menuType, string parentId, uint8_t isButton,
		string permission, uint16_t status, string remark, string creatorId, string createTime, 
		string updaterId,string updateTime, uint8_t deleted)
	{
		this->menu_id = menuID;
		this->menu_name = menuName;
		this->menu_type = menuType;
		this->parent_id = parentId;
		this->is_button = isButton;
		this->permission = permission;
		this->status = status;
		this->remark = remark;
		this->creator_id = creatorId;
		this->create_time = createTime;
		this->updater_id = updaterId;
		this->update_time = updateTime;
		this->deleted = deleted;

	}
};


#endif // !_ORGRESMENUDO_H_
