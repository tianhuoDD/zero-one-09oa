#pragma once

#ifndef _ORGSTRUCT_VO_H_
#define _ORGSTRUCT_VO_H_

#include "../../GlobalInclude.h"
#include "../../dto/OrgStructDTO/OrgStructDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ���û���Ϣ��ʾJsonVO����������Ӧ���ͻ���
 */

//class OrgStructListJsonVO : public JsonVO<OrgStaffDTO::Wrapper>
//{
//	DTO_INIT(OrgStructListJsonVO, JsonVO<OrgStaffDTO::Wrapper>);
//};
/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class OrgStructPageJsonVO : public JsonVO<OrgStructPageDTO::Wrapper> {
	DTO_INIT(OrgStructPageJsonVO, JsonVO<OrgStructPageDTO::Wrapper>);
};


/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class OrgStaffPageJsonVO : public JsonVO<OrgStaffPageDTO::Wrapper> {
	DTO_INIT(OrgStaffPageJsonVO, JsonVO<OrgStaffPageDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif // _ORGSTRUCT_VO_H_