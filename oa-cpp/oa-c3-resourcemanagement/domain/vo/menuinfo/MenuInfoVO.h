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
#ifndef _MENUINFO_VO_
#define _MENUINFO_VO_

#include "../../GlobalInclude.h"
#include "../../dto/menuinfo/MenuInfoDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �˵���Ϣ��ʾ����
 */
//class MenuInfoVO : public oatpp::DTO
//{
//	DTO_INIT(MenuInfoVO, DTO);
//	//---------���Ϸ�header(�޸��õ�DTO���ܲ���Ҫ��header��һ������ݣ���ʾ��VO���о���)
//	//// ͼ������(����ͼ���ַʹ��)
//	//API_DTO_FIELD(String, icon, ZH_WORDS_GETTER("menuinfo.header.orgicon"), false, "NULL");
//	// �˵�����
//	API_DTO_FIELD(String, menu_name, ZH_WORDS_GETTER("menuinfo.header.orgname"), true, "01 ju xing");
//	//// �˵����
//	//API_DTO_FIELD(String, orgabbreviation1, ZH_WORDS_GETTER("menuinfo.header.orgabbreviation"), true, "01 xing qiu");
//	//--------�·�һϵ�в˵���Ϣ
//	// Ψһ����
//	API_DTO_FIELD(String, menu_id, ZH_WORDS_GETTER("menuinfo.field.id"), true,"007");
//	// �˵����
//	API_DTO_FIELD(UInt64, menu_type, ZH_WORDS_GETTER("menuinfo.field.orgcategory"), true, 1);
//	//// �˵����
//	//API_DTO_FIELD(String, orgabbreviation2, ZH_WORDS_GETTER("menuinfo.field.orgabbreviation"), false, "01 xing qiu");
//	//// �˵�����
//	//API_DTO_FIELD(String, orgdescription, ZH_WORDS_GETTER("menuinfo.field.orgdescription"), false, "zan shi mei you");
//	//// ������
//	//API_DTO_FIELD(String, manager, ZH_WORDS_GETTER("menuinfo.field.manager"), false, "mei you guan li");
//	// �ϼ��˵�
//	API_DTO_FIELD(String, parent_id, ZH_WORDS_GETTER("menuinfo.field.orgup"), false, "zan wu cai dan");
//	//// ����ֵ
//	//API_DTO_FIELD(UInt64, sortingvalue, ZH_WORDS_GETTER("menuinfo.field.sortingvalue"), true, 006);
//};





/**
 * �˵���Ϣ��ʾVO��������Ӧ���ͻ��˵�Json����
 */
class MenuInfoJsonVO : public JsonVO<MenuInfoDTO::Wrapper> {
	DTO_INIT(MenuInfoJsonVO, JsonVO<MenuInfoDTO::Wrapper>);

};
//*�ڸĵ�������Ҫ�õ�����
//class MenuInfoListJsonVO : public JsonVO<MenuInfoListVO::Wrapper> {
//	DTO_INIT(MenuInfoListJsonVO, JsonVO<MenuInfoListVO::Wrapper>);
//	
//};

/**
 *  *��ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json���� �ϸ���arch-demoд�ģ�Ϊ�˸�menuinfoctroller.cpp�ṩ����
 */
class MenuInfoPageJsonVO : public JsonVO<MenuInfoPageDTO::Wrapper> {
	DTO_INIT(MenuInfoPageJsonVO, JsonVO<MenuInfoPageDTO::Wrapper>);
};





#include OATPP_CODEGEN_END(DTO)

#endif // !_MENUINFO_VO_