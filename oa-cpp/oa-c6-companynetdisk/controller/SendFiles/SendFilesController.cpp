#include"SendFilesController.h"
#include"stdafx.h"
#include "../../service/myfilesendshare/SendFilesService.h"
#include <iostream>
StringJsonVO::Wrapper SendFilesController::executeSendFiles(const SendFilesDTO::Wrapper& condition, const PayloadDTO& payload) {
    auto response = StringJsonVO::createShared();

    if (!condition->xeditorList || condition->xeditorList->empty()) {
        // response->setStatus("");
        response->fail(condition->xeditorList);
        // response->setmessage("未指定接收者");
        return response;
    }

    // 检查文件 ID 是否有效
    if (!condition->ATTACHMENT_XID || condition->ATTACHMENT_XID->empty()) {
        response->fail(condition->ATTACHMENT_XID);
        return response;
    }
    else {
        response->success(condition->ATTACHMENT_XID);
    }

    SendFilesService service;
    // 执行数据新增
    uint64_t id = service.saveData(condition);
    cout << id << endl;
    if (id > 0) {
        response->success(String(id));
    }
    else
    {
        response->fail(String(id));
    }


    //数据库新增日志
    auto ddto = FileLogDTO::createShared();
    ddto->file_attachment_id = condition->ATTACHMENT_XID;
    ddto->xFromPerson = payload.getUsername();
    ddto->xToPerson = condition->xeditorList;
    // cout << ddto->file_attachment_id.getValue("") << " " << ddto->xFromPerson.getValue("") << " " << ddto->xToPerson.getValue("") << " ";
    uint64_t idd = service.insertSendLog(ddto);
    auto jvoo = StringJsonVO::createShared();
    cout << idd << endl;
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

