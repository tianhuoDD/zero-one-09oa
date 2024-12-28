#pragma once
#ifndef _ORGUNITDUTYTREEVO_H_
#define _ORGUNITDUTYTREEVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/OrgUnitTree/OrgUnitDutyTreeDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class OrgUnitDutyTreeJsonVO : public JsonVO<List<OrgUnitDutyTreeDTO::Wrapper>> {
    DTO_INIT(OrgUnitDutyTreeJsonVO, JsonVO<List<OrgUnitDutyTreeDTO::Wrapper>>);

public:
    OrgUnitDutyTreeJsonVO() {
        this->data = {};
    }
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_ORGUNITDUTYTREEVO_H_
