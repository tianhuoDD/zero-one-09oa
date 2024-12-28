#pragma once
#ifndef _SAMPLE_VO_
#define _SAMPLE_VO_

#include "../../../GlobalInclude.h"
#include "domain/dto/resource-tree-permissios/ResourcetreeDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class PermissionsJsonVO : public JsonVO<oatpp::data::mapping::type::List<ResourcetreeDTO::Wrapper>> {
    DTO_INIT(PermissionsJsonVO, JsonVO<oatpp::data::mapping::type::List<ResourcetreeDTO::Wrapper>>);
public:
    // �ڹ��캯����ʵ����data�б�
    PermissionsJsonVO() {
        this->data = oatpp::data::mapping::type::List<ResourcetreeDTO::Wrapper>::createShared();
    }
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_
