#pragma once

#ifndef _APPLICATIONPROPERTIES_DTO_
#define _APPLICATIONPROPERTIES_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �������
 */
class AvailableIdentityListDTO : public oatpp::DTO {
	DTO_INIT(AvailableIdentityListDTO, DTO);
	//���  ��0��1��2����  
	API_DTO_FIELD(UInt64, xorderColumn, ZH_WORDS_GETTER("application.app-properties.field.xorderColumn"), false, 1);
	//�������  ����֯��Ա���������ۺϱ��{identity.name}@{top-unit.unique}_{person.unique}@I��  
	API_DTO_FIELD(String, xavailableIdentityList, ZH_WORDS_GETTER("application.app-properties.field.xavailableIdentityList"), false, "");

};

/**
 * ������֯�����ţ�
 */
class AvailableUnitListDTO : public oatpp::DTO {
	DTO_INIT(AvailableUnitListDTO, DTO);
	//���  ��0��1��2����  
	API_DTO_FIELD(UInt64, xorderColumn, ZH_WORDS_GETTER("application.app-properties.field.xorderColumn"), false, 1);
	//������֯  ����֯��������org-unit��distinguishedName��  
	API_DTO_FIELD(String, xavailableUnitList, ZH_WORDS_GETTER("application.app-properties.field.xavailableUnitList"), false, "");

};

/**
 * ���÷���
 */
class AvailableGroupListDTO : public oatpp::DTO {
	DTO_INIT(AvailableGroupListDTO, DTO);
	//���  ��0��1��2����  
	API_DTO_FIELD(UInt64, xorderColumn, ZH_WORDS_GETTER("application.app-properties.field.xorderColumn"), false, 1);
	//���÷���    
	API_DTO_FIELD(String, xavailableGroupList, ZH_WORDS_GETTER("application.app-properties.field.xavailableGroupList"), false, "");

};

/**
 * ������
 */
class ControllerListDTO : public oatpp::DTO {
	DTO_INIT(ControllerListDTO, DTO);
	//���  ��0��1��2����  
	API_DTO_FIELD(UInt64, xorderColumn, ZH_WORDS_GETTER("application.app-properties.field.xorderColumn"), false, 1);
	//������  ����Ա��������org-person��distinguishedName��  
	API_DTO_FIELD(String, xcontrollerList, ZH_WORDS_GETTER("application.app-properties.field.xcontrollerList"), false, "");

};

/**
 * Ӧ�����Դ������
 */
class ApplicationPropertiesDTO : public oatpp::DTO {
	DTO_INIT(ApplicationPropertiesDTO, DTO);
	//Ӧ��ID    
	API_DTO_FIELD(String, xid, ZH_WORDS_GETTER("application.pp_e_application.field.xid"), true, "");
	//Ĭ�ϱ�  ����id��pp_e_form��xid��  
	API_DTO_FIELD(String, xdefaultForm, ZH_WORDS_GETTER("application.pp_e_application.field.xdefaultForm"), false, "");
	//����ά����  ����֯��Ա��������org-identity��distinguishedName��  
	API_DTO_FIELD(String, maintenanceIdentity, ZH_WORDS_GETTER("application.app-properties.tip.xmaintenanceIdentity"), false, "");
	//Ӧ������    
	API_DTO_FIELD(String, xname, ZH_WORDS_GETTER("application.pp_e_application.field.xname"), false, "");
	//Ӧ�ñ���    
	API_DTO_FIELD(String, xalias, ZH_WORDS_GETTER("application.pp_e_application.field.xalias"), false, "");
	//Ӧ������    
	API_DTO_FIELD(String, xdescription, ZH_WORDS_GETTER("application.pp_e_application.field.xdescription"), false, "");
	//Ӧ������    
	API_DTO_FIELD(String, xapplicationCategory, ZH_WORDS_GETTER("application.pp_e_application.field.xapplicationCategory"), false, "");
	//Ӧ��ͼ��    
	API_DTO_FIELD(String, xicon, ZH_WORDS_GETTER("application.pp_e_application.field.xicon"), false, "url");
	//Ӧ��ͼ��ɫ��    
	//API_DTO_FIELD(String, xiconHue, ZH_WORDS_GETTER("application.pp_e_application.field.xiconHue"), false, "");
	//Ӧ������  ��{Ĭ�ϱ�,����ά����}��  
	API_DTO_FIELD(String, xproperties, ZH_WORDS_GETTER("application.pp_e_application.field.xproperties"), false, "{\"defaultForm\": \"7a0a3dee-50a4-482e-a71f-7258061c1039\"}");
	//�������  
	API_DTO_FIELD_DEFAULT(List<AvailableIdentityListDTO::Wrapper>, xavailableIdentityList, "");
	//������֯  
	API_DTO_FIELD_DEFAULT(List<AvailableUnitListDTO::Wrapper>, xavailableUnitList, "");
	//���÷���  
	API_DTO_FIELD_DEFAULT(List<AvailableGroupListDTO::Wrapper>, xavailableGroupList, "");
	//������  
	API_DTO_FIELD_DEFAULT(List<ControllerListDTO::Wrapper>, xcontrollerList, "");
	API_DTO_FIELD(String, xcreateTime, ZH_WORDS_GETTER("application.field.createTime"), false, "");
	API_DTO_FIELD(String, xcreatorPerson, ZH_WORDS_GETTER("application.field.creatorPerson"), false, "");
	API_DTO_FIELD(String, xlastUpdatePerson, ZH_WORDS_GETTER("application.field.lastUpdatePerson"), false, "");
	API_DTO_FIELD(String, xlastUpdateTime, ZH_WORDS_GETTER("application.field.lastUpdateTime"), false, "");
	API_DTO_FIELD(String, xupdateTime, ZH_WORDS_GETTER("application.field.updateTime"), false, "");
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_APPLICATIONPROPERTIES_DTO_
