#include "ChangePersonProfileController.h"
#include "stdafx.h"


// FastDFS��Ҫ�����ͷ
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"

#include "../../service/ChangePersonProfile/ChangePersonProfileService.h"
#include "../ApiDeclarativeServicesHelper.h"

StringJsonVO::Wrapper ChangePersonProfileController::executeModifyUser(const String& fileBody, const ChangePersonProfileDTO::Wrapper& dto)
{
	// ��ͷ���ϴ���FastDFS�ļ�������
	ZO_CREATE_DFS_CLIENT_URL(dfs, urlPrefix);
	std::string fieldName = dfs.uploadFile(fileBody->data(), fileBody->size(), "png");
	//std::cout << "upload fieldname is : " << fieldName << std::endl;

	// ƴ���ļ�����·��
	std::stringstream ss;
	ss << urlPrefix << fieldName;

	dto->xicon = String(ss.str().c_str());
	dto->xiconLdpi = dto->xicon;
	dto->xiconMdpi = dto->xicon;
	// TODO:�����û����ݵ����ݿ�����Թ�
	auto vo = StringJsonVO::createShared();
	ChangePersonProfileService service;
	if (service.updateData(dto)) {
		vo->success("1");
	}
	else
	{
		vo->fail("2");
	}

	// ������Ӧ����
	/*auto vo = StringJsonVO::createShared();
	vo->success(String(ss.str().c_str()));*/
	return vo;
}

