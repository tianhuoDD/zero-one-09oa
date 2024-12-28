#include "stdafx.h"
#include "FormService.h"
#include "dao/content/management/FormDAO.h"
#include "domain/dto/content/management/ModifyFormDTO.h"

bool FormService::removeData(string id)
{	
	FormDAO dao;
	return dao.deleteById(id) == 1;
}

bool FormService::updateData(const ModifyFormDTO::Wrapper& dto)
{	
	//×é×°DO
	FormDO formdo;
	formdo.setAlias(dto->xalias.getValue(""));
	formdo.setDescription(dto->xdescription.getValue(""));
	formdo.setEditor(dto->xeditor.getValue(""));
	formdo.setProperties(dto->xproperties.getValue(""));

	FormDAO dao;
	return dao.update(formdo);
}
