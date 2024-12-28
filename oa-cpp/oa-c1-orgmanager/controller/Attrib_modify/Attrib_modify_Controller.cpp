
#include "stdafx.h"
#include "Attrib_modify_Controller.h"
#include "../../service/Attrib_modify/Attrib_modify_Service.h"
#include "../ApiDeclarativeServicesHelper.h"

//modify 修改属性值需要发两个属性数据过来，原属性值和要修改为的属性值
Uint64JsonVO::Wrapper Attrib_modify_Controller::execModifyAttrib(const Attrib_modify_DTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	if (dto->xid == "0") {
		jvo->init(UInt64(-1), ResultStatus(ZH_WORDS_GETTER("Attrib_modify.message_error.two"), 9993));
		return jvo;
	}
	// id有效值校验(数据库中是否存在这个id和属性)
	Attrib_modify_Service service_id_name;
	uint64_t sample_id = service_id_name.select_id(dto);
	if (sample_id <= 0) {//说明数据库没有这个id
		jvo->init(UInt64(-1), ResultStatus(ZH_WORDS_GETTER("Attrib_modify.message_error.three"), 9994));
		return jvo;
	}

	//查找 要修改的组织属性，去数据库查找该id的属性值是否存在，一般来说是存在的，除非前端发属性时把属性变化了

	// 定义一个Service
	Attrib_modify_Service service;
	// 执行数据修改
	if (service.updateData(dto)) {
		jvo->success(1);
	}
	else
	{
		jvo->fail(1);
	}
	// 响应结果
	return jvo;
}
