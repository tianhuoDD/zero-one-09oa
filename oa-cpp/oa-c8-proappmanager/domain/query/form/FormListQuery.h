#ifndef _FORMLISTQUERY_H_
#define _FORMLISTQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ����ѯ���б�����ݴ���ģ��
 */
class FormListQuery : public PageQuery
{
	// �����ʼ��
	DTO_INIT(FormListQuery, PageQuery);
	// ����
	API_DTO_FIELD_DEFAULT(String, xcategory, ZH_WORDS_GETTER("form.field.xcategory"));
	// Ӧ�ñ�ʶ
	API_DTO_FIELD_DEFAULT(String, xapplication, ZH_WORDS_GETTER("form.field.xapplication"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_FORMLISTQUERY_H_