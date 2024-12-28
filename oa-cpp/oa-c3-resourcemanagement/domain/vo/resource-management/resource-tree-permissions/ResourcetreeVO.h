#pragma once
#ifndef _SAMPLE_VO_
#define _SAMPLE_VO_

#include "../../../GlobalInclude.h"
#include "domain/dto/resource-tree-permissios/ResourcetreeDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class PermissionsJsonVO : public JsonVO<oatpp::data::mapping::type::List<ResourcetreeDTO::Wrapper>> {
    DTO_INIT(PermissionsJsonVO, JsonVO<oatpp::data::mapping::type::List<ResourcetreeDTO::Wrapper>>);
public:
    // 在构造函数中实例化data列表
    PermissionsJsonVO() {
        this->data = oatpp::data::mapping::type::List<ResourcetreeDTO::Wrapper>::createShared();
    }
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_
