#pragma once
#ifndef _ORGUNIT_DTO_
#define _ORGUNIT_DTO_

#include "../GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class OrgUnitDTO : public oatpp::DTO
{
	DTO_INIT(OrgUnitDTO, DTO);
	//org_unit����; ��֯id; xid; varchar
	DTO_FIELD(String, xid);
	DTO_FIELD_INFO(xid) {
		info->description = ZH_WORDS_GETTER("org.unit.xid");
	}
	//org_unit����; ��֯����; unit_xname; varchar
	DTO_FIELD(String, unit_xname);
	DTO_FIELD_INFO(unit_xname) {
		info->description = ZH_WORDS_GETTER("org.unit.unit_xname");
	}
	//org_unit����; Ψһ����; xunique; varchar
	DTO_FIELD(String, xunique);
	DTO_FIELD_INFO(xunique) {
		info->description = ZH_WORDS_GETTER("org.unit.xunique");
	}
	//org_unit_typelist����; ��֯���; xtypeList; varchar
	DTO_FIELD(String, xtypeList);
	DTO_FIELD_INFO(xtypeList) {
		info->description = ZH_WORDS_GETTER("org.unit.typelist.xtypeList");
	}
	//org_unit����; ��֯���; xshortName; varchar
	DTO_FIELD(String, xshortName);
	DTO_FIELD_INFO(xshortName) {
		info->description = ZH_WORDS_GETTER("org.unit.xshortName");
	}
	//org_unit����; ��֯����; xdescription; varchar
	DTO_FIELD(String, xdescription);
	DTO_FIELD_INFO(xdescription) {
		info->description = ZH_WORDS_GETTER("org.unit.xdescription");
	}
	//org_person����; ������; person_xname; varchar
	DTO_FIELD(String, person_xname);
	DTO_FIELD_INFO(person_xname) {
		info->description = ZH_WORDS_GETTER("org.person.person_xname");
	}
	//org_unit����; �ϼ���֯; xsuperior; varchar
	DTO_FIELD(String, xsuperior);
	DTO_FIELD_INFO(xsuperior) {
		info->description = ZH_WORDS_GETTER("org.unit.xsuperior");
	}
	//org_unit����; ����ֵ; xorderNumber; int
	DTO_FIELD(UInt64, xorderNumber);
	DTO_FIELD_INFO(xorderNumber) {
		info->description = ZH_WORDS_GETTER("org.unit.xorderNumber");
	}
};

/**
 * ��ҳ�������
 */
class OrgUnitPageDTO : public PageDTO<OrgUnitDTO::Wrapper>
{
	DTO_INIT(OrgUnitPageDTO, PageDTO<OrgUnitDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_ORGUNIT_DTO_
