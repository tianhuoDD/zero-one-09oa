#pragma once
#pragma once
#ifndef PERSONALATTRIBUTE_SERVICE_H
#define PERSONALATTRIBUTE_SERVICE_H

#include <string>
#include "domain/dto/PersonAttribute/PersonAttributeDTO.h"
#include "domain/vo/PersonAttribute/PersonAttributeVO.h"
#include "domain/GlobalInclude.h"

class PersonalAttributeService {
public:
    
    PersonAttributeDTO::Wrapper queryPersonAttribute(const std::string& id);
    bool modifyPersonalAttribute(const PersonAttributeDTO::Wrapper& dto);
    bool addPersonAttribute(const PersonAttributeDTO::Wrapper& dto);
    bool removePersonAttribute(const std::string& id);
};

#endif 