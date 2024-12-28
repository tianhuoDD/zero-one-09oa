#ifndef _DATADETAILQUERY_H_
#define _DATADETAILQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 数据配置详情查询对象
 */
class DataDetailQuery : public PageQuery {
    DTO_INIT(DataDetailQuery, PageQuery);

    // 应用唯一标识符
    API_DTO_FIELD(String, appid, ZH_WORDS_GETTER("config.detail.field.appid"), true, "123213213");
    // 数据唯一标识符
    API_DTO_FIELD(String, dataid, ZH_WORDS_GETTER("config.detail.field.dataid"), true, "1652736172");
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_DATADETAILQUERY_H_
