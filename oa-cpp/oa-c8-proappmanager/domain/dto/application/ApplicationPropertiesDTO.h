#pragma once

#ifndef _APPLICATIONPROPERTIES_DTO_
#define _APPLICATIONPROPERTIES_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 可用身份
 */
class AvailableIdentityListDTO : public oatpp::DTO {
	DTO_INIT(AvailableIdentityListDTO, DTO);
	//序号  （0、1、2…）  
	API_DTO_FIELD(UInt64, xorderColumn, ZH_WORDS_GETTER("application.app-properties.field.xorderColumn"), false, 1);
	//可用身份  （组织成员名称树，综合表→{identity.name}@{top-unit.unique}_{person.unique}@I）  
	API_DTO_FIELD(String, xavailableIdentityList, ZH_WORDS_GETTER("application.app-properties.field.xavailableIdentityList"), false, "");

};

/**
 * 可用组织（部门）
 */
class AvailableUnitListDTO : public oatpp::DTO {
	DTO_INIT(AvailableUnitListDTO, DTO);
	//序号  （0、1、2…）  
	API_DTO_FIELD(UInt64, xorderColumn, ZH_WORDS_GETTER("application.app-properties.field.xorderColumn"), false, 1);
	//可用组织  （组织名称树，org-unit：distinguishedName）  
	API_DTO_FIELD(String, xavailableUnitList, ZH_WORDS_GETTER("application.app-properties.field.xavailableUnitList"), false, "");

};

/**
 * 可用分组
 */
class AvailableGroupListDTO : public oatpp::DTO {
	DTO_INIT(AvailableGroupListDTO, DTO);
	//序号  （0、1、2…）  
	API_DTO_FIELD(UInt64, xorderColumn, ZH_WORDS_GETTER("application.app-properties.field.xorderColumn"), false, 1);
	//可用分组    
	API_DTO_FIELD(String, xavailableGroupList, ZH_WORDS_GETTER("application.app-properties.field.xavailableGroupList"), false, "");

};

/**
 * 管理者
 */
class ControllerListDTO : public oatpp::DTO {
	DTO_INIT(ControllerListDTO, DTO);
	//序号  （0、1、2…）  
	API_DTO_FIELD(UInt64, xorderColumn, ZH_WORDS_GETTER("application.app-properties.field.xorderColumn"), false, 1);
	//管理者  （人员名称树，org-person：distinguishedName）  
	API_DTO_FIELD(String, xcontrollerList, ZH_WORDS_GETTER("application.app-properties.field.xcontrollerList"), false, "");

};

/**
 * 应用属性传输对象
 */
class ApplicationPropertiesDTO : public oatpp::DTO {
	DTO_INIT(ApplicationPropertiesDTO, DTO);
	//应用ID    
	API_DTO_FIELD(String, xid, ZH_WORDS_GETTER("application.pp_e_application.field.xid"), true, "");
	//默认表单  （表单id，pp_e_form：xid）  
	API_DTO_FIELD(String, xdefaultForm, ZH_WORDS_GETTER("application.pp_e_application.field.xdefaultForm"), false, "");
	//流程维护人  （组织成员名称树，org-identity：distinguishedName）  
	API_DTO_FIELD(String, maintenanceIdentity, ZH_WORDS_GETTER("application.app-properties.tip.xmaintenanceIdentity"), false, "");
	//应用名称    
	API_DTO_FIELD(String, xname, ZH_WORDS_GETTER("application.pp_e_application.field.xname"), false, "");
	//应用别名    
	API_DTO_FIELD(String, xalias, ZH_WORDS_GETTER("application.pp_e_application.field.xalias"), false, "");
	//应用描述    
	API_DTO_FIELD(String, xdescription, ZH_WORDS_GETTER("application.pp_e_application.field.xdescription"), false, "");
	//应用类型    
	API_DTO_FIELD(String, xapplicationCategory, ZH_WORDS_GETTER("application.pp_e_application.field.xapplicationCategory"), false, "");
	//应用图标    
	API_DTO_FIELD(String, xicon, ZH_WORDS_GETTER("application.pp_e_application.field.xicon"), false, "url");
	//应用图标色调    
	//API_DTO_FIELD(String, xiconHue, ZH_WORDS_GETTER("application.pp_e_application.field.xiconHue"), false, "");
	//应用属性  （{默认表单,流程维护人}）  
	API_DTO_FIELD(String, xproperties, ZH_WORDS_GETTER("application.pp_e_application.field.xproperties"), false, "{\"defaultForm\": \"7a0a3dee-50a4-482e-a71f-7258061c1039\"}");
	//可用身份  
	API_DTO_FIELD_DEFAULT(List<AvailableIdentityListDTO::Wrapper>, xavailableIdentityList, "");
	//可用组织  
	API_DTO_FIELD_DEFAULT(List<AvailableUnitListDTO::Wrapper>, xavailableUnitList, "");
	//可用分组  
	API_DTO_FIELD_DEFAULT(List<AvailableGroupListDTO::Wrapper>, xavailableGroupList, "");
	//管理者  
	API_DTO_FIELD_DEFAULT(List<ControllerListDTO::Wrapper>, xcontrollerList, "");
	API_DTO_FIELD(String, xcreateTime, ZH_WORDS_GETTER("application.field.createTime"), false, "");
	API_DTO_FIELD(String, xcreatorPerson, ZH_WORDS_GETTER("application.field.creatorPerson"), false, "");
	API_DTO_FIELD(String, xlastUpdatePerson, ZH_WORDS_GETTER("application.field.lastUpdatePerson"), false, "");
	API_DTO_FIELD(String, xlastUpdateTime, ZH_WORDS_GETTER("application.field.lastUpdateTime"), false, "");
	API_DTO_FIELD(String, xupdateTime, ZH_WORDS_GETTER("application.field.updateTime"), false, "");
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_APPLICATIONPROPERTIES_DTO_
