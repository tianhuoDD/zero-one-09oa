#ifndef _DATADETAILQUERY_H_
#define _DATADETAILQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �������������ѯ����
 */
class DataDetailQuery : public PageQuery {
    DTO_INIT(DataDetailQuery, PageQuery);

    // Ӧ��Ψһ��ʶ��
    API_DTO_FIELD(String, appid, ZH_WORDS_GETTER("config.detail.field.appid"), true, "123213213");
    // ����Ψһ��ʶ��
    API_DTO_FIELD(String, dataid, ZH_WORDS_GETTER("config.detail.field.dataid"), true, "1652736172");
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_DATADETAILQUERY_H_
