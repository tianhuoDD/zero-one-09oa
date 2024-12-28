#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: wangye
 @Date: 2023/10/20 14:59:38

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _MENUINFODTO_H_
#define _MENUINFODTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �˵���Ϣ�޸�DTO
 */
class MenuInfoDTO : public oatpp::DTO
{
	DTO_INIT(MenuInfoDTO, DTO);
	//---------���Ϸ�header(�޸��õ�DTO���ܲ���Ҫ��header��һ������ݣ���ʾ��VO���о���)
	// ͼ�����ƣ�����ͼ���ַʹ�ã�
	//API_DTO_FIELD_DEFAULT(String, icon, ZH_WORDS_GETTER("menuinfo.header.menuicon"));
	// Ψһ����
	API_DTO_FIELD_DEFAULT(String, menu_id, ZH_WORDS_GETTER("menuinfo.field.id"));
	// �˵�����
	API_DTO_FIELD_DEFAULT(String, menu_name, ZH_WORDS_GETTER("menuinfo.field.orgname"));
	//// �˵����
	//API_DTO_FIELD_DEFAULT(String, orgabbreviation, ZH_WORDS_GETTER("menuinfo.field.orgabbreviation"));
	//// ͼ�����ƣ�����ͼ���ַʹ�ã�
	//API_DTO_FIELD_DEFAULT(String, orgicon, ZH_WORDS_GETTER("menuinfo.header.orgicon"));
	//// ����ֵ
	//API_DTO_FIELD_DEFAULT(UInt64, orgsortingvalue, ZH_WORDS_GETTER("menuinfo.field.orgsortingvalue"));
	//// �˵�����
	//API_DTO_FIELD_DEFAULT(String, orgdescription, ZH_WORDS_GETTER("menuinfo.field.orgdescription"));
	// �˵����
	API_DTO_FIELD_DEFAULT(UInt64, menu_type, ZH_WORDS_GETTER("menuinfo.field.orgcategory"));
	// �ϼ��˵�
	API_DTO_FIELD_DEFAULT(String, parent_id, ZH_WORDS_GETTER("menuinfo.field.orgup"));
	//// ������
	//API_DTO_FIELD_DEFAULT(String, manager, ZH_WORDS_GETTER("menuinfo.field.manager"));
	// 
	// 
	// 
    //�Ƿ�ť
	API_DTO_FIELD_DEFAULT(UInt64, is_button, ZH_WORDS_GETTER("menuinfo.default.null"));
	//Ȩ�ޱ�ʶ
	API_DTO_FIELD_DEFAULT(String, permission, ZH_WORDS_GETTER("menuinfo.default.null"));
	//�˵�״̬��1���� 0ͣ�ã�
	API_DTO_FIELD_DEFAULT(UInt64, status, ZH_WORDS_GETTER("menuinfo.default.null"));
	//���ڲ��������ڿ��ٲ�ѯͬ���� 
	API_DTO_FIELD_DEFAULT(UInt64, level, ZH_WORDS_GETTER("menuinfo.default.null"));
	//������תҳ���ӦURL
	API_DTO_FIELD_DEFAULT(String, link_url, ZH_WORDS_GETTER("menuinfo.default.null"));
	//��ע
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("menuinfo.default.null"));
	//������ID
	API_DTO_FIELD_DEFAULT(String, creator_id, ZH_WORDS_GETTER("menuinfo.default.null"));
	//����ʱ��
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("menuinfo.default.null"));
	//������ID
	API_DTO_FIELD_DEFAULT(String, updater_id, ZH_WORDS_GETTER("menuinfo.default.null"));
	//����ʱ�� 
	API_DTO_FIELD_DEFAULT(String, update_time, ZH_WORDS_GETTER("menuinfo.default.null"));

};
/**
 * ʾ����ҳ�������
 */
class MenuInfoPageDTO : public PageDTO<MenuInfoDTO::Wrapper>
{
	DTO_INIT(MenuInfoPageDTO, PageDTO<MenuInfoDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_MENUINFODTO_H_
