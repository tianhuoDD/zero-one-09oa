#include "OrgDutyService.h"
string OrgDutyService::saveData(const OrgDutyDTO::Wrapper& dto)
{

    OrgDutyDO data;

    ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Xname, xname, \
        Xdescription, xdescription, \
        Xpinyin, xpinyin, \
        XpinyinInitial, xpinyinInitial);
#if 0
    ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, \
        Xname, xname, \
        Xdescription, xdescription, \
        Xid, xid, \
        XcreateTime, xcreateTime, \
        Xsequence, xsequence, \
        XupdateTime, xupdateTime, \
        XdistributeFactor, xdistributeFactor, \
        XdistinguishedName, xdistinguishedName, \
        XorderNumber, xorderNumber, \
        Xpinyin, xpinyin, \
        XpinyinInitial, xpinyinInitial, \
        Xunique, xunique, \
        Xunit, xunit \
    );
#endif
    OrgDutyDAO dao;

    return dao.insert(data);
}

bool OrgDutyService::updateData(const OrgDutyDTO::Wrapper& dto)
{
    OrgDutyDO data;

    ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Xname, xname, \
        Xdescription, xdescription,\
        Xid, xid,\
        Xpinyin, xpinyin,\
        XpinyinInitial, xpinyinInitial);

    OrgDutyDAO dao;

    return dao.update(data) == 1;
}
