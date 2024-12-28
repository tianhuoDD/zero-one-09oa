#pragma once
#pragma once

#ifndef _NewVO_H_
#define _NewVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/New/NewDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class NewVO : public oatpp::DTO
{
    DTO_INIT(NewVO, DTO);
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

//logo: 栏目标识
//name : 栏目名称
//as : 栏目别名
//ds : 栏目描述
//sort1 : 栏目排序
//type : 栏目类型
//document : 文档类型
//ignore : 忽略标题
//check : 检查草稿
//timed : 定时视图
//column : 栏目视图
//autosave : 自动保存
//edit : 默认编辑表单
//read : 默认阅读表单
class NewJsonVO : public JsonVO<NewDTO::Wrapper>
{
    DTO_INIT(NewJsonVO, JsonVO<NewDTO::Wrapper>);

};

#include OATPP_CODEGEN_END(DTO)


#endif