#ifndef _SortByValue_DTO_
#define _SortByValue_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
// 组织职务传输对象
class SortByValueDTO : public oatpp::DTO
{
    DTO_INIT(SortByValueDTO, DTO);
    // 职务ID
    DTO_FIELD(UInt64, xid);
    DTO_FIELD_INFO(xid) {
        info->description = ZH_WORDS_GETTER("职务ID");
    }

    // 创建时间
    DTO_FIELD(String, xcreateTime);
    DTO_FIELD_INFO(xcreateTime) {
        info->description = ZH_WORDS_GETTER("创建时间");
    }


    // 修改时间
    DTO_FIELD(String, xupdateTime);
    DTO_FIELD_INFO(xupdateTime) {
        info->description = ZH_WORDS_GETTER("修改时间");
    }


    // 名称
    DTO_FIELD(String, xname);
    DTO_FIELD_INFO(xname) {
        info->description = ZH_WORDS_GETTER("名称");
    }

    //org_unit表下; 排序值; xorderNumber; int
    DTO_FIELD(UInt64, xorderNumber);
    DTO_FIELD_INFO(xorderNumber) {
        info->description = ZH_WORDS_GETTER("org.unit.xorderNumber");
    }

    // 唯一标识
    DTO_FIELD(String, xunique);
    DTO_FIELD_INFO(xunique) {
        info->description = ZH_WORDS_GETTER("唯一标识");
    }


};

#include OATPP_CODEGEN_END(DTO)
#endif