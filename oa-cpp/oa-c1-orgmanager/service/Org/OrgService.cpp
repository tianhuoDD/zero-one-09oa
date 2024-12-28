#include "OrgService.h"
#include "domain/do/Org/OrgDO.h"
#include "dao/Org/OrgDAO.h"
#include <iostream>

int32_t OrgService::createOrg(const CreateOrgDTO::Wrapper& dto)
{
	OrgDAO dao;
	//将dto数据转成对应的do数据
	CreateOrgDO cOrgData;
	std::list<std::string> nativeTypeList;
	cOrgData.setXlevel(dto->xlevel.getValue(1));
	cOrgData.setXname(dto->xname.getValue(""));
	cOrgData.setXunique(dto->xunique.getValue(""));
	cOrgData.setXtypeList(dto->xtypeList.getValue(""));

	//if (dto->xtypeList)
	//{
	//	for (const auto& oatppStr : *dto->xtypeList)
	//	{
	//		nativeTypeList.push_back(oatppStr->c_str());  // 使用 c_str() 将 oatpp::String 转换为 std::string
	//	}
	//}
	//cOrgData.setXtypeList(nativeTypeList);

	cOrgData.setXshortName(dto->xshortName.getValue(""));
	cOrgData.setXdescription(dto->xdescription.getValue(""));

	nativeTypeList.clear();
	if (dto->xcontrollerList)
	{
		for (const auto& oatppStr : *dto->xcontrollerList)
		{
			nativeTypeList.push_back(oatppStr->c_str());
		}

	}
	cOrgData.setXcontrollerList(nativeTypeList);

	cOrgData.setXsuperior(dto->xsuperior.getValue(""));
	cOrgData.setXunique(dto->xunique.getValue(""));
	cOrgData.setXorderNumber(dto->xorderNumber.getValue(-999999));
	cOrgData.setXpinyin(dto->xpinyin.getValue(""));
	cOrgData.setXpinyinInitial(dto->xpinyinInitial.getValue(""));

	//debug
	/*for (auto& str : cOrgData.getXtypeList())
	{
		std::cout << "xtypeList: " << str << std::endl;
	}*/

	//插入操作
	int row = dao.insert(cOrgData);
	return row;

}

int32_t OrgService::deleteOrg(const DeleteOrgDTO::Wrapper& dto)
{
	//将dto数据转成对应的do数据
	DeleteOrgDO dOrgData;
	//std::list<std::string> nativeTypeList;
	//for (const auto& oatppStr : *dto->xuniqueList)
	//{
	//	nativeTypeList.push_back(oatppStr->c_str());  // 使用 c_str() 将 oatpp::String 转换为 std::string
	//}
	//dOrgData.setXuniqueList(nativeTypeList);

	dOrgData.setXid(dto->xid.getValue(""));

	//删除操作
	OrgDAO dao;
	int cnt = 0;
	dao.batchDelete(dOrgData, cnt);
	return cnt;
}
