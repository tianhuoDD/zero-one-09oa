#pragma once
#ifndef _FORM_DAO_
#define _FORM_DAO_
#include "BaseDAO.h"
#include "domain/do/form/FormDO.h"
#include "domain/do/form/FormNameDO.h"
#include "domain/query/form/FormListQuery.h"


/**
 * ���̱����ݿ����ʵ��
 */
class FormDAO : public BaseDAO {
public:
	// ������
	uint64_t insertToForm(const FormDO& data);
	int update(const FormDO& data);
	int deleteById(const oatpp::String& id);
	// �������汾���� (pp_e_formversion)
	uint64_t insertToFormVersion(const FormDO& data);
	int deleteVersionByFormId(const string& formId);
	// ��ѯ��ǰӦ�����з���
	list<FormDO> selectcategoryAndnumByApp(const char* xapplication);

	// ���ݱ�ʶid��ѯ������
	list<FormDO> selectInfoById(const char* xid);

	// ͳ����������
	uint64_t count(const FormListQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<FormDO> selectFormWithPage(const FormListQuery::Wrapper& query);

	list<FormNameDO> selectNameById(const string& xid);

};
#endif // !_FORM_DAO_
