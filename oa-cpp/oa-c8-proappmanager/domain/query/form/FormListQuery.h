#ifndef _FORMLISTQUERY_H_
#define _FORMLISTQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个查询表单列表的数据传输模型
 */
class FormListQuery : public PageQuery
{
	// 定义初始化
	DTO_INIT(FormListQuery, PageQuery);
	// 分类
	API_DTO_FIELD_DEFAULT(String, xcategory, ZH_WORDS_GETTER("form.field.xcategory"));
	// 应用标识
	API_DTO_FIELD_DEFAULT(String, xapplication, ZH_WORDS_GETTER("form.field.xapplication"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_FORMLISTQUERY_H_