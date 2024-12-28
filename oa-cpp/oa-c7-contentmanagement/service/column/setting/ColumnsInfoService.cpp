#include "ColumnsInfoService.h"
#include "../../../dao/column/setting/ColumnsInfoDAO.h"
#include<ctime>


// 分页查询所有数据
//SamplePageDTO::Wrapper ColumnsInfoService::listAll(const SampleQuery::Wrapper& query) {
//
//}
// 
// 

std::string get_time() {
	auto t = std::time(nullptr);
	std::ostringstream os;
	os << std::put_time(std::localtime(&t), "%Y%m%d%H%M%S");
	std::string NowTime = os.str();
	return NowTime;
}



bool ColumnsInfoService::QueryData(const ColumnsInfoDTO::Wrapper& dto) {
	ColumnsInfoDO data;

	//ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Xid, id, XcategoryName, name, XcategoryAlias, othername, Xdescription, description, XcategorySeq, sort, XdocumentType, type, XformId, defaultEditForm, XreadFormId, defaultReadForm, XcategoryIcon, image);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Xid, id, XappName, name, XappAlias, othername, Xdescription, description, XappInfoSeq, sort, XappType, type, XdefaultEditForm, defaultEditForm, XdefaultReadForm, defaultReadForm, XappIcon, image);

	ColumnsInfoDAO dao;
	
	
	return dao.QueryByName(data);

}


ColumnsInfoDTO::Wrapper ColumnsInfoService::QueryDataById(const ColumnsInfoDTO::Wrapper& dto) {
	ColumnsInfoDO data;

	//ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Xid, id, XcategoryName, name, XcategoryAlias, othername, Xdescription, description, XcategorySeq, sort, XdocumentType, type, XformId, defaultEditForm, XreadFormId, defaultReadForm, XcategoryIcon, image);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Xid, id, XappName, name, XappAlias, othername, Xdescription, description, XappInfoSeq, sort, XappType, type, XdefaultEditForm, defaultEditForm, XdefaultReadForm, defaultReadForm, XappIcon, image);

	ColumnsInfoDAO dao;

	auto res = ColumnsInfoDTO::createShared();
	ColumnsInfoDO it=*dao.QueryById(data).begin();
	std::cout <<"it.getXid()= " << it.getXid() << "   it.getXappName()=" << it.getXappName() << std::endl;

	//for(auto i: it){
	//}
	ZO_STAR_DOMAIN_FILED_DO_TO_DTO(res,it,id,Xid);
	res->name = it.getXappName();
	res->name = it.getXappName();


return res;

}


// 保存数据
uint64_t ColumnsInfoService::saveData(const ColumnsInfoDTO::Wrapper& dto, const PayloadDTO& payload) {
	
	ColumnsInfoDO data;
	
	string admin_name = payload.getUsername();
	//字段匹配         `XcategoryName`, `XcategoryAlias`, `Xdescription`,`XcategorySeq`,`XdocumentType`,`XformId`,`XreadFormId`,`XcategoryIcon`
	ZO_STAR_DOMAIN_DTO_TO_DO(data,dto, Xid,id,XappName,name, XappAlias,othername, Xdescription,description, XappInfoSeq,sort, XappType,type ,XdefaultEditForm, defaultEditForm ,XdefaultReadForm,defaultReadForm , XappIcon, image);
	data.setXcreatorIdentity(admin_name);
	data.setXcreatorPerson(admin_name);
	data.setXcreatorUnitName(admin_name);
	data.setXcreatorTopUnitName(admin_name);
	//data.setXcreateTime(get_time());
	//data.setXupdateTime(get_time());
	data.setXsequence(get_time() + dto->id->c_str());
	ColumnsInfoDAO dao;
   auto it=	dao.insert(data);
	//auto it = dao.update(data);
   return it;
}


// 修改数据
bool ColumnsInfoService::updateData(const ColumnsInfoDTO::Wrapper& dto) {
	
	ColumnsInfoDO data;

	//ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Xid, id,XcategoryName, name, XcategoryAlias, othername, Xdescription, description, XcategorySeq, sort, XdocumentType, type, XformId, defaultEditForm, XreadFormId, defaultReadForm, XcategoryIcon, image);
	//ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Xid, id, XcategoryName, name, XcategoryAlias, othername, Xdescription, description, XcategorySeq, sort, XdocumentType, type, XformId, defaultEditForm, XreadFormId, defaultReadForm, XcategoryIcon, image);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Xid, id, XappName, name, XappAlias, othername, Xdescription, description, XappInfoSeq, sort, XappType, type, XdefaultEditForm, defaultEditForm, XdefaultReadForm, defaultReadForm, XappIcon, image);
	data.setXupdateTime(get_time());


	ColumnsInfoDAO dao;
	return dao.update(data);	
}

// 通过ID删除数据
bool ColumnsInfoService::removeData(uint64_t id) {

	ColumnsInfoDO data;

	//ZO_STAR_DOMAIN_DTO_TO_DO(data,dto,Name,name);
	
	ColumnsInfoDAO dao;


	return dao.deleteById(id);


}
