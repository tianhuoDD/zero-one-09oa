#ifndef _SortByValue_DTO_
#define _SortByValue_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
// ��ְ֯�������
class SortByValueDTO : public oatpp::DTO
{
    DTO_INIT(SortByValueDTO, DTO);
    // ְ��ID
    DTO_FIELD(UInt64, xid);
    DTO_FIELD_INFO(xid) {
        info->description = ZH_WORDS_GETTER("ְ��ID");
    }

    // ����ʱ��
    DTO_FIELD(String, xcreateTime);
    DTO_FIELD_INFO(xcreateTime) {
        info->description = ZH_WORDS_GETTER("����ʱ��");
    }


    // �޸�ʱ��
    DTO_FIELD(String, xupdateTime);
    DTO_FIELD_INFO(xupdateTime) {
        info->description = ZH_WORDS_GETTER("�޸�ʱ��");
    }


    // ����
    DTO_FIELD(String, xname);
    DTO_FIELD_INFO(xname) {
        info->description = ZH_WORDS_GETTER("����");
    }

    //org_unit����; ����ֵ; xorderNumber; int
    DTO_FIELD(UInt64, xorderNumber);
    DTO_FIELD_INFO(xorderNumber) {
        info->description = ZH_WORDS_GETTER("org.unit.xorderNumber");
    }

    // Ψһ��ʶ
    DTO_FIELD(String, xunique);
    DTO_FIELD_INFO(xunique) {
        info->description = ZH_WORDS_GETTER("Ψһ��ʶ");
    }


};

#include OATPP_CODEGEN_END(DTO)
#endif