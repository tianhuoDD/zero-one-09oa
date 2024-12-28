#pragma once
#ifndef _ORG_SERVICE_
#define _ORG_SERVICE_
#include "domain/dto/Org/CreateOrgDTO.h"
#include "domain/dto/Org/DeleteOrgDTO.h"

class OrgService
{
public:
	int32_t createOrg(const CreateOrgDTO::Wrapper& dto);
	int32_t deleteOrg(const DeleteOrgDTO::Wrapper& dto);
};

#endif // !_ORGSERVICE_H_