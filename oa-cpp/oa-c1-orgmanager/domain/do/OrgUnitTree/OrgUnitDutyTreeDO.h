#pragma once
#ifndef _ORGUNITDUTYTREEDO_H_
#define _ORGUNITDUTYTREEDO_H_

#include "../DoInclude.h"

/**
 * ��ְ֯�����ݿ�ʵ��
 */
class OrgUnitDutyTreeDO {
    CC_SYNTHESIZE(string, xid, Xid);             // ΨһID
    CC_SYNTHESIZE(string, xname, Xname);         // ְ������
    CC_SYNTHESIZE(string, xunique, Xunique);     // ְ��Ψһ��ʶ
    CC_SYNTHESIZE(string, xunit, Xunit);         // ��Ӧ��֯��λ��ID
};

#endif // !_ORGUNITDUTYTREEDO_H_
