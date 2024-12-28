#include "stdafx.h"
#include "AddroleService.h"
#include <SimpleDateTimeFormat.h>
#include <SnowFlake.h>
#include <chrono>
#include "dao/rolemanagement/RoleManagementDAO/put/addrole/AddroleDAO.h"

uint64_t AddroleService::addRole(const AddroleDTO::Wrapper& dto) {
	// ��װDO����
	AddroleDO data;
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Xname, name, Xunique, unique, Xdescription, description);
    // ����Xid
    SnowFlake sf(1,1);
    data.setXid( std::to_string(sf.nextId()));
    // ����XcreateTime
    data.setXcreateTime(SimpleDateTimeFormat::format());
    // ����Xsequence
    std::string Xsequence = data.getXcreateTime();
    Xsequence.erase(std::remove(Xsequence.begin(), Xsequence.end(), ' '));
    Xsequence.erase(std::remove(Xsequence.begin(), Xsequence.end(), '-'));
    Xsequence.erase(std::remove(Xsequence.begin(), Xsequence.end(), ':'));
    Xsequence += string(data.getXid());
    data.setXsequence(Xsequence);
    // ����updateTime
    data.setXupdateTime(data.getXcreateTime());
    // XdistributeFactor������
    // ����XdistinguishedName
    std::string XdistinguishedName = data.getXname() + "@" + data.getXname() + "SystemRole@R";
    data.setXdistinguishedName(XdistinguishedName);
    // ����xorderNumber
    auto now = std::chrono::system_clock::now();    
    data.setXorderNumber(std::chrono::system_clock::to_time_t(now));     
    // ����xpinyin
    std::string Xpinyin = data.getXname();
    std::transform(Xpinyin.begin(), Xpinyin.end(), Xpinyin.begin(), [](unsigned char c) {
        return std::tolower(c);
        });
    data.setXpinyin(Xpinyin);
    // ����xpinyinInitial
    data.setXpinyinInitial(Xpinyin);
	// ִ���������
	AddroleDAO dao;
    if (dao.count(data) != 0) {
        return 0;
    }
	return dao.insert(data);
}