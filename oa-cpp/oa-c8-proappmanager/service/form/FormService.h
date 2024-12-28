#pragma once
#ifndef _FORM_SERVICE_
#define _FORM_SERVICE_
#include "stdafx.h"
#include <list>
#include "domain/vo/form/FormCategoryVO.h"
#include "domain/query/form/FormListQuery.h"
#include "domain/vo/form/FormInfoVO.h"
#include "domain/vo/form/FormListVO.h"
#include "domain/do/form/FormDO.h"
#include "domain/dto/form/FormListDTO.h"
#include "domain/dto/form/OperateFormDTO.h"


/**
 * 流程表单服务实现
 */
class FormService {
public:
	// 添加表单
	string saveForm(const OperateFormDTO::Wrapper& dto, const PayloadDTO& payload);
	// 修改表单
	bool updateForm(const OperateFormDTO::Wrapper& dto, const PayloadDTO& payload);
	// 删除表单(通过id删除)
	bool deleteForm(const oatpp::String& id);

	// 查询所有类别及其数量
	oatpp::List<FormCategoryDTO::Wrapper> listCategory(const char* xapplication);
	// 分页查询所有表单
	FormListPageDTO::Wrapper listAllForm(const FormListQuery::Wrapper& userQuery);
	// 查询表单详情
	FormInfoDTO::Wrapper listFormInfo(const char* xid);
};

#endif // !_FORM_SERVICE_