#pragma once
#ifndef _FORM_SERVICE_H
#define _FORM_SERVICE_H

#include "../../../domain/dto/content/management/ModifyFormDTO.h"

class FormService{
public:
	//ͨ��idɾ����Ŀ��
	bool updateData(const ModifyFormDTO::Wrapper& dto);
	bool removeData(string id);
};

#endif // !_FORM_SERVICE_H
