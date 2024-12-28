#pragma once

#ifndef _PUTDTO_H_
#define _PUTDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class PutDTO : public oatpp::DTO
{
    DTO_INIT(PutDTO, DTO);

    API_DTO_FIELD_DEFAULT(String, xappicon, ZH_WORDS_GETTER("newdto.put.picture"));
    API_DTO_FIELD_DEFAULT(String, xallPeopleViem, ZH_WORDS_GETTER("newdto.put.fw"));
    API_DTO_FIELD_DEFAULT(String, xallPeoplePublish, ZH_WORDS_GETTER("newdto.put.publisher"));
    API_DTO_FIELD_DEFAULT(String, xcreatorPerson, ZH_WORDS_GETTER("newdto.put.administrators"));
    // API_DTO_FIELD_DEFAULT(String, xicon, ZH_WORDS_GETTER("newdto.get.logo"));
   



};

#include OATPP_CODEGEN_END(DTO)


#endif