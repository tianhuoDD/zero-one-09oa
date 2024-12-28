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
 * ���̱�����ʵ��
 */
class FormService {
public:
	// ��ӱ�
	string saveForm(const OperateFormDTO::Wrapper& dto, const PayloadDTO& payload);
	// �޸ı�
	bool updateForm(const OperateFormDTO::Wrapper& dto, const PayloadDTO& payload);
	// ɾ����(ͨ��idɾ��)
	bool deleteForm(const oatpp::String& id);

	// ��ѯ�������������
	oatpp::List<FormCategoryDTO::Wrapper> listCategory(const char* xapplication);
	// ��ҳ��ѯ���б�
	FormListPageDTO::Wrapper listAllForm(const FormListQuery::Wrapper& userQuery);
	// ��ѯ������
	FormInfoDTO::Wrapper listFormInfo(const char* xid);
};

#endif // !_FORM_SERVICE_