#include "PersonalAttributeService.h"
#include "stdafx.h"
#include "../../dao/PersonAttributeDAO/PersonAttributeDAO.h"
#include "SimpleDateTimeFormat.h"

#define INFO 

// 查询
PersonAttributeDTO::Wrapper PersonalAttributeService::queryPersonAttribute(const std::string& id) {
    PersonAttributeDAO dao; // 创建一个 PersonAttributeDAO 对象 dao，用于访问数据库。
    org_PersonAttributeDO res = dao.selectByUniqueID(id); // 调用 dao 的 selectByUniqueID 方法，根据 id 查询 PersonAttribute 对象，并将结果存储在 res 中。
    auto dto = PersonAttributeDTO::createShared(); // 创建一个 PersonAttributeDTO 的共享指针 dto，用于存储转换后的数据。

    ZO_STAR_DOMAIN_DO_TO_DTO(dto, res,
        xid, Xid,                       // 唯一标识
        xsequence, Xsequence,           // 序列号
        xupdateTime, XupdateTime,       // 更新时间
        xcreateTime, XcreateTime,       // 创建时间
        xdistributeFactor, XDistributeFactor, // 分配因子
        xdescription, Xdescription,     // 描述
        xdistinguishedName, XDistinguishedName, // 区分名
        xname, Xname,                   // 名称
        xorderNumber, XorderNumber,     // 排序号
        xperson, Xperson,               // 人员
        xpinyin, Xpinyin,               // 拼音
        xpinyinInitial, XpinyinInitial  // 拼音首字母
    )

        return dto;
}

// 修改
//bool PersonalAttributeService::modifyPersonalAttribute(const PersonAttributeDTO::Wrapper& dto)
//{
//    org_PersonAttributeDO data;
//    ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,
//        Xid, xid,                       // 标识
//        XcreateTime, xcreateTime,       // 创建时间
//        Xsequence, xsequence,           // 序列号
//        XupdateTime, xupdateTime,       // 更新时间
//        XDistributeFactor, xdistributeFactor, // 分配因子
//        Xdescription, xdescription,     // 描述
//        XDistinguishedName, xdistinguishedName, // 区分名
//        Xname, xname,                   // 名称
//        XorderNumber, xorderNumber,     // 排序号
//        Xperson, xperson,               // 人员
//        Xpinyin, xpinyin,               // 拼音
//        XpinyinInitial, xpinyinInitial,  // 拼音首字母
//        Xunique, xunique
//    )
//        PersonAttributeDAO dao;
//    return dao.update(data) == 1;
//}
bool PersonalAttributeService::modifyPersonalAttribute(const PersonAttributeDTO::Wrapper& dto)
{
    org_PersonAttributeDO data;
    ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,
        Xdescription, xdescription,     // 描述
        Xunique, xunique
    )
        //根据xunique 修改xdescription
    PersonAttributeDAO dao;
    return dao.update(data) == 1;
}

// 添加
bool PersonalAttributeService::addPersonAttribute(const PersonAttributeDTO::Wrapper& dto)
{
    org_PersonAttributeDO data;
    dto->xcreateTime = SimpleDateTimeFormat::format();
    dto->xupdateTime = SimpleDateTimeFormat::format();

    ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,
        Xid, xid,                       // 标识
        XcreateTime, xcreateTime,       // 创建时间
        Xsequence, xsequence,           // 序列号
        XupdateTime, xupdateTime,       // 更新时间
        XDistributeFactor, xdistributeFactor, // 分配因子
        Xdescription, xdescription,     // 描述
        XDistinguishedName, xdistinguishedName, // 区分名
        Xname, xname,                   // 名称
        XorderNumber, xorderNumber,     // 排序号
        Xperson, xperson,               // 人员
        Xpinyin, xpinyin,               // 拼音
        XpinyinInitial, xpinyinInitial,  // 拼音首字母
        Xunique, xunique
    )
        PersonAttributeDAO dao;
    return dao.insert(data) == 1;
}

// 删除
bool PersonalAttributeService::removePersonAttribute(const std::string& id)
{
    PersonAttributeDAO dao;
    return dao.deleteByUniqueID(id) == 1;
}