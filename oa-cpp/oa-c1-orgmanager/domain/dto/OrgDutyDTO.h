#ifndef _ORGDUTY_DTO_
#define _ORGDUTY_DTO_

#include "../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
// 组织职务传输对象
class OrgDutyDTO : public oatpp::DTO
{
    DTO_INIT(OrgDutyDTO, DTO);

    // 职务ID
    DTO_FIELD(String, xid);
    DTO_FIELD_INFO(xid) {
        info->description = ZH_WORDS_GETTER("duty.field.xid");
    }

    // 职务名称
    DTO_FIELD(String, xname);
    DTO_FIELD_INFO(xname) {
        info->description = ZH_WORDS_GETTER("duty.field.xname");
    }

    // 职务描述
    DTO_FIELD(String, xdescription);
    DTO_FIELD_INFO(xdescription) {
        info->description = ZH_WORDS_GETTER("duty.field.xdescription");
    }

    // 拼音
    DTO_FIELD(String, xpinyin);
    DTO_FIELD_INFO(xpinyin) {
        info->description = ZH_WORDS_GETTER("duty.field.xpinyin");
    }

    // 拼音首字母
    DTO_FIELD(String, xpinyinInitial);
    DTO_FIELD_INFO(xpinyinInitial) {
        info->description = ZH_WORDS_GETTER("duty.field.xpinyinInitial");
    }
#if 0
    // 创建时间
    DTO_FIELD(String, xcreateTime);
    DTO_FIELD_INFO(xcreateTime) {
        info->description = ZH_WORDS_GETTER("duty.field.xid");
    }

    // 序列
    DTO_FIELD(String, xsequence);
    DTO_FIELD_INFO(xsequence) {
        info->description = ZH_WORDS_GETTER("duty.field.xsequence");
    }

    // 修改时间
    DTO_FIELD(String, xupdateTime);
    DTO_FIELD_INFO(xupdateTime) {
        info->description = ZH_WORDS_GETTER("duty.field.xupdateTime");
    }

    // 分布要素
    DTO_FIELD(Int32, xdistributeFactor);
    DTO_FIELD_INFO(xdistributeFactor) {
        info->description = ZH_WORDS_GETTER("duty.field.xdistributeFactor");
    }

    // 标识名
    DTO_FIELD(String, xdistinguishedName);
    DTO_FIELD_INFO(xdistinguishedName) {
        info->description = ZH_WORDS_GETTER("duty.field.xdistinguishedName");
    }

    // 排序编号
    DTO_FIELD(Int32, xorderNumber);
    DTO_FIELD_INFO(xorderNumber) {
        info->description = ZH_WORDS_GETTER("duty.field.xorderNumber");
    }

    // 唯一标识
    DTO_FIELD(String, xunique);
    DTO_FIELD_INFO(xunique) {
        info->description = ZH_WORDS_GETTER("duty.field.xunique");
    }

	//单元
    DTO_FIELD(String, xunit);
    DTO_FIELD_INFO(xunit) {
        info->description = ZH_WORDS_GETTER("duty.field.xunit");
    }
#endif
};

#include OATPP_CODEGEN_END(DTO)
#endif