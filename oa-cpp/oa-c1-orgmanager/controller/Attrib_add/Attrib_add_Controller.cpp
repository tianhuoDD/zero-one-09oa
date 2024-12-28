
#include "stdafx.h"
#include "Attrib_add_Controller.h"
#include "../../service/Attrib_add/Attrib_add_Service.h"
#include "../ApiDeclarativeServicesHelper.h"

//add
Uint64JsonVO::Wrapper Attrib_add_Controller::execAddAttrib(const Attrib_add_DTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	
	// 非空校验(组织名称和id不能为空，一般来说拿到的前端数据id肯定不为空)
	if (!dto->xname)
	{
		jvo->init(UInt64(-1), ResultStatus(ZH_WORDS_GETTER("Attrib_add.message_error.one"), 9990));//返回给前端消息message--上传参数异常
		return jvo;
	}
	if (dto->xid == "0") {
		jvo->init(UInt64(-1), ResultStatus(ZH_WORDS_GETTER("Attrib_add.message_error.two"), 9991));//返回给前端消息message--上传参数异常（其实这里应该写：为找到该id组织）
		return jvo;
	}
	// 有效值校验(数据库中是否存在这个id)
	Attrib_add_Service service_id_name;
	uint64_t sample_id = service_id_name.select_id(dto);
	if (sample_id <= 0) {//说明数据库没有这个id
		jvo->init(UInt64(-1), ResultStatus(ZH_WORDS_GETTER("Attrib_add.message_error.three"), 9995));//返回给前端消息message--上传参数异常（其实这里应该写：为找到该id组织）
		return jvo;
	}

	// 定义一个Service
	Attrib_add_Service service;
	// 执行数据新增
	//uint64_t id1 = service.saveData1(dto);//传id和属性
	uint64_t id2 = service.saveData2(dto);//传id和描述
	if (id2 > 0) {
		jvo->success(UInt64(1));//返回的data值
	}
	else
	{
		jvo->fail(UInt64(1));//返回的data值
	}
	//响应结果
	return jvo;
}
