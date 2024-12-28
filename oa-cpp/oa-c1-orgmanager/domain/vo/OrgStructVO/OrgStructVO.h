#pragma once

#ifndef _ORGSTRUCT_VO_H_
#define _ORGSTRUCT_VO_H_

#include "../../GlobalInclude.h"
#include "../../dto/OrgStructDTO/OrgStructDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个用户信息显示JsonVO对象，用于响应给客户端
 */

//class OrgStructListJsonVO : public JsonVO<OrgStaffDTO::Wrapper>
//{
//	DTO_INIT(OrgStructListJsonVO, JsonVO<OrgStaffDTO::Wrapper>);
//};
/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class OrgStructPageJsonVO : public JsonVO<OrgStructPageDTO::Wrapper> {
	DTO_INIT(OrgStructPageJsonVO, JsonVO<OrgStructPageDTO::Wrapper>);
};


/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class OrgStaffPageJsonVO : public JsonVO<OrgStaffPageDTO::Wrapper> {
	DTO_INIT(OrgStaffPageJsonVO, JsonVO<OrgStaffPageDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif // _ORGSTRUCT_VO_H_