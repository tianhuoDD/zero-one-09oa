#pragma once


#ifndef _SHEETDO_H_
#define _SHEETDO_H_
#include "../DoInclude.h"

// 组织信息表数据 org_unit
class Sheet1DO
{
	CC_SYNTHESIZE(string, unit_xid, Unit_xid);
	CC_SYNTHESIZE(string, org_name, Org_name);
	CC_SYNTHESIZE(string, org_uqcode, Org_uqcode);
	CC_SYNTHESIZE(string, org_typename, Org_typename);
	CC_SYNTHESIZE(string, org_porgcode, Org_porgcode);
	CC_SYNTHESIZE(string, org_description, Org_description);
	CC_SYNTHESIZE(int, org_sortorder, Org_sortorder);
};
// 人员基本信息表数据 org_person
class Sheet2DO
{
	CC_SYNTHESIZE(string, person_xid, Person_xid);
	CC_SYNTHESIZE(string, person_name, person_name);
	CC_SYNTHESIZE(string, person_uqcode, person_uqcode);
	CC_SYNTHESIZE(string, person_mobilenumber, person_mobilenumber);
	CC_SYNTHESIZE(string, person_id, person_id);
	CC_SYNTHESIZE(string, person_officephone, person_officephone);
	CC_SYNTHESIZE(string, person_gender, person_gender);
	CC_SYNTHESIZE(string, person_email, person_email);
};
// 人员身份信息表 org_identity
class Sheet3DO
{
	CC_SYNTHESIZE(string, identity_xid, Identity_xid);
	CC_SYNTHESIZE(string, person_uqcode, person_uqcode);
	CC_SYNTHESIZE(string, org_uqcode, Org_uqcode);
	CC_SYNTHESIZE(string, person_identity, Org_identity);
	CC_SYNTHESIZE(string, primary, Primary);
};
// 职务信息表 org_unitduty
class Sheet4DO
{
	CC_SYNTHESIZE(string, position_xid, Position_xid);
	CC_SYNTHESIZE(string, position_name, Position_name);
	CC_SYNTHESIZE(string, position_org_ucode, Position_org_ucode);
	CC_SYNTHESIZE(string, position_code, Position_code);
	CC_SYNTHESIZE(string, position_description, Position_description);
	CC_SYNTHESIZE(string, position_person_ucode, Position_person_ucode);
	CC_SYNTHESIZE(string, person_and_org_ucode_in_position, Person_and_org_ucode_in_position);
};
// 群组信息 org_group
class Sheet5DO
{
	CC_SYNTHESIZE(string, group_xid, Group_xid);
	CC_SYNTHESIZE(string, group_name, Group_name);
	CC_SYNTHESIZE(string, group_code, Group_code);
	CC_SYNTHESIZE(string, person_uqcode, person_uqcode);
	CC_SYNTHESIZE(string, person_identity, Org_identity);
	CC_SYNTHESIZE(string, org_uqcode, Org_uqcode);
	CC_SYNTHESIZE(string, subgroup_code, Subgroup_code);
	CC_SYNTHESIZE(string, group_description, Group_description);
};
#endif