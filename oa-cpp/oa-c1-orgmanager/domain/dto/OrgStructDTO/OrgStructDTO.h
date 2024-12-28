#pragma once

#ifndef _ORGSTRUCT_DTO_
#define _ORGSTRUCT_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)


class OrgStructDTO : public oatpp::DTO
{
	DTO_INIT(OrgStructDTO, DTO);
	DTO_FIELD(String, xunique);
	DTO_FIELD(String, xdistinguishedName);
	DTO_FIELD(String, xemployee);
	DTO_FIELD(String, xmail);
	DTO_FIELD(String, xmobile);
	DTO_FIELD(String, xiconLdpi);
	DTO_FIELD(String, xname);
	DTO_FIELD(String, xid);
};

/*
	 OrgStruct��ҳ�������
 */
class OrgStructPageDTO : public PageDTO<OrgStructDTO::Wrapper>
{
	DTO_INIT(OrgStructPageDTO, PageDTO<OrgStructDTO::Wrapper>);
};


/*
	���� : ������Ĳ����Ƿ��ظ�ǰ�˵Ĳ���
*/
class OrgStaffDTO : public oatpp::DTO
{
	DTO_INIT(OrgStaffDTO, DTO);
	//ͷ��base64
	DTO_FIELD(String, xiconLdpi);
	DTO_FIELD(String, xdistinguishedName);
	DTO_FIELD(String, xname);
	DTO_FIELD(String, xemployee);
	DTO_FIELD(String, xmail);
	DTO_FIELD(String, xmobile);
};

class OrgStaffPageDTO : public PageDTO<OrgStaffDTO::Wrapper>
{
	DTO_INIT(OrgStaffPageDTO, PageDTO<OrgStaffDTO::Wrapper>);
};

class DeleteOrgmeberDTO : public oatpp::DTO
{
	DTO_INIT(DeleteOrgmeberDTO, DTO);
	DTO_FIELD(String, xdistinguishedName);
	DTO_FIELD(String, Delete);
	DTO_FIELD(String, xemployee);
};


#include OATPP_CODEGEN_END(DTO)
#endif // _ORGSTRUCTDTO_H_