
#pragma once

#ifndef _NewDTO_H_
#define _NewDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class NewDTO : public oatpp::DTO
{
    DTO_INIT(NewDTO, DTO);

    API_DTO_FIELD_DEFAULT(String, xappicon, ZH_WORDS_GETTER("newdto.put.picture"));
    API_DTO_FIELD_DEFAULT(String, xallPeopleViem, ZH_WORDS_GETTER("newdto.put.fw"));
    API_DTO_FIELD_DEFAULT(String, xallPeoplePublish, ZH_WORDS_GETTER("newdto.put.publisher"));
    API_DTO_FIELD_DEFAULT(String, xcreatorPerson, ZH_WORDS_GETTER("newdto.put.administrators"));
   // API_DTO_FIELD_DEFAULT(String, xicon, ZH_WORDS_GETTER("newdto.get.logo"));
    API_DTO_FIELD_DEFAULT(String, xappIcon, ZH_WORDS_GETTER("newdto.get.logo"));
    API_DTO_FIELD_DEFAULT(String, xappName, ZH_WORDS_GETTER("newdto.get.name"));
    API_DTO_FIELD_DEFAULT(String, xappAlias, ZH_WORDS_GETTER("newdto.get.as"));
    API_DTO_FIELD_DEFAULT(String, xdescription, ZH_WORDS_GETTER("newdto.get.ds"));
    API_DTO_FIELD_DEFAULT(String, xsequence, ZH_WORDS_GETTER("newdto.get.sort1"));
    //API_DTO_FIELD_DEFAULT(String, type, ZH_WORDS_GETTER("newdto.get.type"));
    API_DTO_FIELD_DEFAULT(String, xdocumentType, ZH_WORDS_GETTER("newdto.get.document"));
    //API_DTO_FIELD_DEFAULT(String, type, ZH_WORDS_GETTER("newdto.get.type"));
    API_DTO_FIELD_DEFAULT(String, ignore1, ZH_WORDS_GETTER("newdto.get.ignore"));
    API_DTO_FIELD_DEFAULT(String, timed, ZH_WORDS_GETTER("newdto.get.timed"));
    API_DTO_FIELD_DEFAULT(String, xappType, ZH_WORDS_GETTER("newdto.get.type"));
    API_DTO_FIELD_DEFAULT(String, xshowAllDocuments, ZH_WORDS_GETTER("newdto.get.column"));
    API_DTO_FIELD_DEFAULT(String, autosave, ZH_WORDS_GETTER("newdto.get.autosave"));
    API_DTO_FIELD_DEFAULT(String, xdefaultEditForm, ZH_WORDS_GETTER("newdto.get.edit"));
    API_DTO_FIELD_DEFAULT(String, xdefaultReadForm, ZH_WORDS_GETTER("newdto.get.read"));

   


};
class  NewPageDTO : public PageDTO< NewDTO::Wrapper>
{
    DTO_INIT(NewPageDTO, PageDTO< NewDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)


#endif