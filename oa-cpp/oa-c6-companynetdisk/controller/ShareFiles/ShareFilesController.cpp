#include"ShareFilesController.h"
#include"stdafx.h"
#include "../../service/myfilesendshare/ShareFilesService.h"
#include <iostream>
StringJsonVO::Wrapper ShareFilesController::executeShareFiles(const ShareFilesDTO::Wrapper& params, const PayloadDTO& payload) {
    auto response = StringJsonVO::createShared();

    if (!params->xshareList || params->xshareList->empty()) {
        // response->setStatus("");
        response->fail(params->xshareList);
        // response->setmessage("δָ��������");
        return response;
    }

    // ����ļ� ID �Ƿ���Ч
    if (!params->ATTACHMENT_XID || params->ATTACHMENT_XID->empty()) {
        response->fail(params->ATTACHMENT_XID);
        return response;
    }
    else {
        response->success(params->ATTACHMENT_XID);
    }

    ShareFilesService service;
    // ִ����������
    uint64_t id = service.saveData(params);
    if (id > 0) {
        response->success(String(id));
    }
    else
    {
        response->fail(String(id));
    }

    //���ݿ�������־
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

    //��Ӧ���
    return response;
}