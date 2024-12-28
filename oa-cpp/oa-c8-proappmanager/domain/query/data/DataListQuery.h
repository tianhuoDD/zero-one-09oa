#ifndef _DATALISTQUERY_H_
#define _DATALISTQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ���������б��ѯ����
 */
class DataListQuery : public PageQuery {
    DTO_INIT(DataListQuery, PageQuery);

    // Ӧ�ó���Ψһ��ʶ��
    API_DTO_FIELD(String, appid, ZH_WORDS_GETTER("config.detail.field.dataid"), true, "123213213");

    API_DTO_FIELD(String, dataid, ZH_WORDS_GETTER("config.detail.field.dataid"), true, "123213213");
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_DATALIST_QUERY_
