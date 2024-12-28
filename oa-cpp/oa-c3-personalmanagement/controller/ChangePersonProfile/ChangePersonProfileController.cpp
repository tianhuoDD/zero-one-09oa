#include "ChangePersonProfileController.h"
#include "stdafx.h"


// FastDFS需要导入的头
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"

#include "../../service/ChangePersonProfile/ChangePersonProfileService.h"
#include "../ApiDeclarativeServicesHelper.h"

StringJsonVO::Wrapper ChangePersonProfileController::executeModifyUser(const String& fileBody, const ChangePersonProfileDTO::Wrapper& dto)
{
	// 将头像上传到FastDFS文件服务器
	ZO_CREATE_DFS_CLIENT_URL(dfs, urlPrefix);
	std::string fieldName = dfs.uploadFile(fileBody->data(), fileBody->size(), "png");
	//std::cout << "upload fieldname is : " << fieldName << std::endl;

	// 拼接文件下载路径
	std::stringstream ss;
	ss << urlPrefix << fieldName;

	dto->xicon = String(ss.str().c_str());
	dto->xiconLdpi = dto->xicon;
	dto->xiconMdpi = dto->xicon;
	// TODO:保存用户数据到数据库过程略过
	auto vo = StringJsonVO::createShared();
	ChangePersonProfileService service;
	if (service.updateData(dto)) {
		vo->success("1");
	}
	else
	{
		vo->fail("2");
	}

	// 创建响应数据
	/*auto vo = StringJsonVO::createShared();
	vo->success(String(ss.str().c_str()));*/
	return vo;
}

