#pragma once
#ifndef _OrgUnitIdentityTREEVO_H_
#define _OrgUnitIdentityTREEVO_H_
#include "../../GlobalInclude.h"
#include "../../dto/OrgUnitTree/OrgUnitIdentityTreeDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ��ʾ����֯��Ա��ʾJsonVO����������Ӧ��ǰ��
 */
class OrgUnitIdentityTreeJsonVO : public JsonVO<List<OrgUnitIdentityTreeDTO::Wrapper>>
{
	DTO_INIT(OrgUnitIdentityTreeJsonVO, JsonVO<List<OrgUnitIdentityTreeDTO::Wrapper>>);
public:
	// �ڹ��캯����ʵ����data�б�
	OrgUnitIdentityTreeJsonVO() {
		this->data = {};
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_OrgUnitIdentityTREEVO_H_
