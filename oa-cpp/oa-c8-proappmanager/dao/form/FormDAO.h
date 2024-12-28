#pragma once
#ifndef _FORM_DAO_
#define _FORM_DAO_
#include "BaseDAO.h"
#include "domain/do/form/FormDO.h"
#include "domain/do/form/FormNameDO.h"
#include "domain/query/form/FormListQuery.h"


/**
 * 流程表单数据库操作实现
 */
class FormDAO : public BaseDAO {
public:
	// 创建表单
	uint64_t insertToForm(const FormDO& data);
	int update(const FormDO& data);
	int deleteById(const oatpp::String& id);
	// 创建表单版本备份 (pp_e_formversion)
	uint64_t insertToFormVersion(const FormDO& data);
	int deleteVersionByFormId(const string& formId);
	// 查询当前应用所有分类
	list<FormDO> selectcategoryAndnumByApp(const char* xapplication);

	// 根据标识id查询表单详情
	list<FormDO> selectInfoById(const char* xid);

	// 统计数据条数
	uint64_t count(const FormListQuery::Wrapper& query);
	// 分页查询数据
	list<FormDO> selectFormWithPage(const FormListQuery::Wrapper& query);

	list<FormNameDO> selectNameById(const string& xid);

};
#endif // !_FORM_DAO_
