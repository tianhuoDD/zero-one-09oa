#ifndef _ORGDUTY_DTO_
#define _ORGDUTY_DTO_

#include "../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
// ��ְ֯�������
class OrgDutyDTO : public oatpp::DTO
{
    DTO_INIT(OrgDutyDTO, DTO);

    // ְ��ID
    DTO_FIELD(String, xid);
    DTO_FIELD_INFO(xid) {
        info->description = ZH_WORDS_GETTER("duty.field.xid");
    }

    // ְ������
    DTO_FIELD(String, xname);
    DTO_FIELD_INFO(xname) {
        info->description = ZH_WORDS_GETTER("duty.field.xname");
    }

    // ְ������
    DTO_FIELD(String, xdescription);
    DTO_FIELD_INFO(xdescription) {
        info->description = ZH_WORDS_GETTER("duty.field.xdescription");
    }

    // ƴ��
    DTO_FIELD(String, xpinyin);
    DTO_FIELD_INFO(xpinyin) {
        info->description = ZH_WORDS_GETTER("duty.field.xpinyin");
    }

    // ƴ������ĸ
    DTO_FIELD(String, xpinyinInitial);
    DTO_FIELD_INFO(xpinyinInitial) {
        info->description = ZH_WORDS_GETTER("duty.field.xpinyinInitial");
    }
#if 0
    // ����ʱ��
    DTO_FIELD(String, xcreateTime);
    DTO_FIELD_INFO(xcreateTime) {
        info->description = ZH_WORDS_GETTER("duty.field.xid");
    }

    // ����
    DTO_FIELD(String, xsequence);
    DTO_FIELD_INFO(xsequence) {
        info->description = ZH_WORDS_GETTER("duty.field.xsequence");
    }

    // �޸�ʱ��
    DTO_FIELD(String, xupdateTime);
    DTO_FIELD_INFO(xupdateTime) {
        info->description = ZH_WORDS_GETTER("duty.field.xupdateTime");
    }

    // �ֲ�Ҫ��
    DTO_FIELD(Int32, xdistributeFactor);
    DTO_FIELD_INFO(xdistributeFactor) {
        info->description = ZH_WORDS_GETTER("duty.field.xdistributeFactor");
    }

    // ��ʶ��
    DTO_FIELD(String, xdistinguishedName);
    DTO_FIELD_INFO(xdistinguishedName) {
        info->description = ZH_WORDS_GETTER("duty.field.xdistinguishedName");
    }

    // ������
    DTO_FIELD(Int32, xorderNumber);
    DTO_FIELD_INFO(xorderNumber) {
        info->description = ZH_WORDS_GETTER("duty.field.xorderNumber");
    }

    // Ψһ��ʶ
    DTO_FIELD(String, xunique);
    DTO_FIELD_INFO(xunique) {
        info->description = ZH_WORDS_GETTER("duty.field.xunique");
    }

	//��Ԫ
    DTO_FIELD(String, xunit);
    DTO_FIELD_INFO(xunit) {
        info->description = ZH_WORDS_GETTER("duty.field.xunit");
    }
#endif
};

#include OATPP_CODEGEN_END(DTO)
#endif