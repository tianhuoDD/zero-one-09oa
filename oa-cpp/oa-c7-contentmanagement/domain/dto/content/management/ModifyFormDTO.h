#pragma once
#ifndef _MODIFYFORM_DTO_
#define _MODIFYFORM_DTO_
#include "../../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
	修改栏目表单传输对象
	author：niuniu
*/
class ModifyFormDTO : public oatpp::DTO {
	DTO_INIT(ModifyFormDTO, DTO);
    //表单id
    API_DTO_FIELD_DEFAULT(String, xid, ZH_WORDS_GETTER("content.management.field.xid"));
    // 创建时间 (不可修改，通常在创建时生成)
    API_DTO_FIELD_DEFAULT(String, xcreateTime, ZH_WORDS_GETTER("content.management.field.xcreateTime"));
    // 序列 (可修改)
    API_DTO_FIELD_DEFAULT(Int32, xsequence, ZH_WORDS_GETTER("content.management.field.xsequence"));
    // 更新时间 (通常由系统设置，不需要传入)
    API_DTO_FIELD_DEFAULT(String, xupdateTime, ZH_WORDS_GETTER("content.management.field.xupdateTime"));
    // 分发因子 (可修改)
    API_DTO_FIELD_DEFAULT(Int32, xdistributeFactor, ZH_WORDS_GETTER("content.management.field.xdistributeFactor"));
    // 别名 (可修改)
    API_DTO_FIELD_DEFAULT(String, xalias, ZH_WORDS_GETTER("content.management.field.xalias"));
    // 应用ID (可修改)
    API_DTO_FIELD_DEFAULT(String, xappId, ZH_WORDS_GETTER("content.management.field.xappId"));
    // 数据 (可修改)
    API_DTO_FIELD_DEFAULT(String, xdata, ZH_WORDS_GETTER("content.management.field.xdata"));
    // 描述 (可修改)
    API_DTO_FIELD_DEFAULT(String, xdescription, ZH_WORDS_GETTER("content.management.field.xdescription"));
    // 编辑者 (可修改)
    API_DTO_FIELD_DEFAULT(String, xeditor, ZH_WORDS_GETTER("content.management.field.xeditor"));
    // 名称 (可修改)
    API_DTO_FIELD_DEFAULT(String, xname, ZH_WORDS_GETTER("content.management.field.xname"));
    // 属性 (可修改)
    API_DTO_FIELD_DEFAULT(String, xproperties, ZH_WORDS_GETTER("content.management.field.xproperties"));
};

#include OATPP_CODEGEN_END(DTO)
#endif //! _MODIFYFORM_DTO_
