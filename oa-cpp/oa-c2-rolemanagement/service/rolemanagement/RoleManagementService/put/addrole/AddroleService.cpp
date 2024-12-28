#include "stdafx.h"
#include "AddroleService.h"
#include <SimpleDateTimeFormat.h>
#include <SnowFlake.h>
#include <chrono>
#include "dao/rolemanagement/RoleManagementDAO/put/addrole/AddroleDAO.h"

uint64_t AddroleService::addRole(const AddroleDTO::Wrapper& dto) {
	// 组装DO数据
	AddroleDO data;
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Xname, name, Xunique, unique, Xdescription, description);
    // 构造Xid
    SnowFlake sf(1,1);
    data.setXid( std::to_string(sf.nextId()));
    // 构造XcreateTime
    data.setXcreateTime(SimpleDateTimeFormat::format());
    // 构造Xsequence
    std::string Xsequence = data.getXcreateTime();
    Xsequence.erase(std::remove(Xsequence.begin(), Xsequence.end(), ' '));
    Xsequence.erase(std::remove(Xsequence.begin(), Xsequence.end(), '-'));
    Xsequence.erase(std::remove(Xsequence.begin(), Xsequence.end(), ':'));
    Xsequence += string(data.getXid());
    data.setXsequence(Xsequence);
    // 构造updateTime
    data.setXupdateTime(data.getXcreateTime());
    // XdistributeFactor不处理
    // 构造XdistinguishedName
    std::string XdistinguishedName = data.getXname() + "@" + data.getXname() + "SystemRole@R";
    data.setXdistinguishedName(XdistinguishedName);
    // 构造xorderNumber
    auto now = std::chrono::system_clock::now();    
    data.setXorderNumber(std::chrono::system_clock::to_time_t(now));     
    // 构造xpinyin
    std::string Xpinyin = data.getXname();
    std::transform(Xpinyin.begin(), Xpinyin.end(), Xpinyin.begin(), [](unsigned char c) {
        return std::tolower(c);
        });
    data.setXpinyin(Xpinyin);
    // 构造xpinyinInitial
    data.setXpinyinInitial(Xpinyin);
	// 执行数据添加
	AddroleDAO dao;
    if (dao.count(data) != 0) {
        return 0;
    }
	return dao.insert(data);
}