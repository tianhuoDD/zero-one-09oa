#include"ShareFilesController.h"
#include"stdafx.h"
#include "../../service/myfilesendshare/ShareFilesService.h"
#include <iostream>
StringJsonVO::Wrapper ShareFilesController::executeShareFiles(const ShareFilesDTO::Wrapper& params, const PayloadDTO& payload) {
    auto response = StringJsonVO::createShared();

    if (!params->xshareList || params->xshareList->empty()) {
        // response->setStatus("");
        response->fail(params->xshareList);
        // response->setmessage("未指定接收者");
        return response;
    }

    // 检查文件 ID 是否有效
    if (!params->ATTACHMENT_XID || params->ATTACHMENT_XID->empty()) {
        response->fail(params->ATTACHMENT_XID);
        return response;
    }
    else {
        response->success(params->ATTACHMENT_XID);
    }

    ShareFilesService service;
    // 执行数据新增
    uint64_t id = service.saveData(params);
    if (id > 0) {
        response->success(String(id));
    }
    else
    {
        response->fail(String(id));
    }

    //数据库新增日志
    auto ddto = FileLogDTO::createShared();
    ddto->file_attachment_id = params->ATTACHMENT_XID;
    ddto->xFromPerson = payload.getUsername();
    ddto->xToPerson = params->xshareList;
    cout << ddto->file_attachment_id.getValue("") << " " << ddto->xFromPerson.getValue("") << " " << ddto->xToPerson.getValue("") << " ";
    uint64_t idd = service.insertShareLog(ddto);
    auto jvoo = StringJsonVO::createShared();
    if (idd > 0) {
        jvoo->success(ddto->xid);
    }
    else
    {
        jvoo->fail(ddto->xid);
        return jvoo;
    }

    //响应结果
    return response;
}