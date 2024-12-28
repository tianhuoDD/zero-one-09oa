#include "stdafx.h"
#include "PersonAttributeController.h"
#include "../../service/PersonalManageAttribute/PersonalAttributeService.h"

PersonAttributeJsonVO::Wrapper PersonAttributeController::execQueryPersonAttribute(const String& id)
{
    PersonalAttributeService service;
    auto res = service.queryPersonAttribute(id);
    auto jvo = PersonAttributeJsonVO::createShared();
    jvo->success(res);
    return jvo;
}

StringJsonVO::Wrapper PersonAttributeController::execAddPersonAttribute(const PersonAttributeDTO::Wrapper& dto)
{
    auto jvo = StringJsonVO::createShared();
    PersonalAttributeService service;
    if (service.addPersonAttribute(dto)) {
        jvo->success(dto->xid);
    }
    else {
        jvo->fail(dto->xid);
    }
    return jvo;
}



StringJsonVO::Wrapper PersonAttributeController::execModifyPersonAttribute(const PersonAttributeDTO::Wrapper& dto)
{
    auto jvo = StringJsonVO::createShared();
    PersonalAttributeService service;
    if (service.modifyPersonalAttribute(dto)) {
        jvo->success(dto->xid);
    }
    else {
        jvo->fail(dto->xid);
    }
    return jvo;
}

StringJsonVO::Wrapper PersonAttributeController::execRemovePersonAttribute(const String& id)
{
    auto jvo = StringJsonVO::createShared();
    PersonalAttributeService service;
    if (service.removePersonAttribute(id)) {
        jvo->success(id);
    }
    else
    {
        jvo->fail(id);
    }
    return jvo;
}