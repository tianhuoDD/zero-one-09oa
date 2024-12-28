#include "OrgController.h"
#include "service/Org/OrgService.h"

Int32JsonVO::Wrapper OrgController::execCreateOrg(const CreateOrgDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Int32JsonVO::createShared();
	//检查是否有 组织名称、组织名称全拼、首字母拼 和 唯一编码 以及是否为空
	if (!dto->xname || !dto->xpinyin || !dto->xpinyinInitial || !dto->xunique || dto->xname->empty() || dto->xpinyin->empty() || dto->xpinyinInitial->empty() || dto->xunique->empty())
	{
		jvo->init(Int32(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	OrgService service;
	int ret = service.createOrg(dto);
	if (ret > 0)
	{
		jvo->success(ret);
	}
	else if (ret == 0)
	{
		jvo->fail(ret);
	}
	else
	{
		if (ret == -2)
		{
			jvo->init(Int32(-2), ResultStatus(u8"xunique不唯一", 9995));
		}
		else if (ret == -3)
		{
			jvo->init(Int32(-3), ResultStatus(u8"无法根据提供的xlevel和上级组织名找到对应的上级组织", 9995));
		}
		else if (ret == -4)
		{
			jvo->init(Int32(-4), ResultStatus(u8"同一层的组织名不唯一", 9995));
		}
	}

	// 响应结果
	return jvo;
}

Int32JsonVO::Wrapper OrgController::execDeleteOrg(const DeleteOrgDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Int32JsonVO::createShared();
	//检查是否有 xid 以及是否为空
	if (!dto->xid || dto->xid->empty())
	{
		jvo->init(Int32(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	OrgService service;
	int ret = service.deleteOrg(dto);

	jvo->success(ret);

	// 响应结果
	return jvo;
}
