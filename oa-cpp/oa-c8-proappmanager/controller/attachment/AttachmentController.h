#ifndef _ATTACHMENT_CONTROLLER_
#define _ATTACHMENT_CONTROLLER_
#include "domain/vo/BaseJsonVO.h"
#include "domain/GlobalInclude.h"

#include "ApiHelper.h"
#include "ServerInfo.h"
#include "../../domain/vo/attachment/AttachmentVO.h"
#include "../../domain/dto/attachment/AttachmentAddDTO.h"
#include "domain/vo/attachment/AttachmentDetailVO.h"
#include "domain/vo/attachment/AttachmentListVO.h"
#include "../../service/attachment/AttachmentService.h"
#include "domain/dto/attachment/AttachmentOperateDTO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class AttachmentController : public oatpp::web::server::api::ApiController {
	//�����������ķ��ʵ����
	API_ACCESS_DECLARE(AttachmentController);
public: //����ӿ�

	// --------------------�ϴ�����--------------------------------------------------
	// ��������
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("attachment.post.summary"), addAttachment, StringJsonVO::Wrapper);
	//API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("attachment.post.summary"), addAttachment, StringJsonVO::Wrapper);
	// ����˵�
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/process-app-manager/attachment/add", addAttachment, REQUEST(std::shared_ptr<IncomingRequest>, request), execAddAttachement(request, authObject->getPayload()));
	//API_HANDLER_ENDPOINT(API_M_POST, "/process-app-manager/attachment/add", addAttachment, REQUEST(std::shared_ptr<IncomingRequest>, request), execAddAttachement(request, {}));
	// ------------------------end--------------------------------------------------------------------------------------


	// ---------------------------����dto�޸ĸ�����Ϣ---------------------------------------------------------------------
	// �����ϴ�������Ϣ�ӿ�
	ENDPOINT_INFO(updateAttachment) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("attachment.put.summary"));
		// ����Ȩ��У�� 
		API_DEF_ADD_AUTH();
		// ������Ӧ����
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// ��������
		//API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("attachment.field.name"), "xxx.png", true);
		//API_DEF_ADD_QUERY_PARAMS(String, "alais", ZH_WORDS_GETTER("attachment.field.alias"), "alias", false);
		//API_DEF_ADD_QUERY_PARAMS(String, "attachmentInfo", ZH_WORDS_GETTER("attachment.field.attachmentInfo"), "xxx.png", true);
		//API_DEF_ADD_QUERY_PARAMS(String, "attachment", ZH_WORDS_GETTER("attachment.field.attachment"), "xxx.png", true);

	}
	ENDPOINT(API_M_PUT, "/process-app-manager/attachment/update", updateAttachment, BODY_DTO(AttachmentOperateDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ִ���ļ������߼�
		API_HANDLER_RESP_VO(execUpdateAttachment(dto, authObject->getPayload()));
	}
	// --------------------------------end-----------------------------------

	// -------------------------����ɾ��------------------------------------------------------
	// �����ϴ�������Ϣ�ӿ�
	ENDPOINT_INFO(delAttachment) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("attachment.del.summary"));
		// ����Ȩ��У�� 
		API_DEF_ADD_AUTH();
		// ������Ӧ����

		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// ��������
		API_DEF_ADD_PATH_PARAMS(String, "id", ZH_WORDS_GETTER("attachment.field.id"), "", true);
	}
	ENDPOINT(API_M_DEL, "/process-app-manager/attachment/delete/{id}", delAttachment, PATH(String, id), API_HANDLER_AUTH_PARAME) {
		// ִ��ɾ���߼�
		API_HANDLER_RESP_VO(execDeleteAttachment(id));
	}

	// -----------------------------endl--------------------------------------------------------------------

	// 1.��ȡ�����б�ӿ�
	 // �����ѯ�ӿ�����
	ENDPOINT_INFO(queryAttachmentsList) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("process.attachments.getlist.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(AttachmentListJsonVO);
		//׷�Ӳ�ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "applicationID", ZH_WORDS_GETTER("application.field.id"), "A", true);
	}
	ENDPOINT(API_M_GET, "/process-app-manager/attahcment/query-list", queryAttachmentsList, QUERY(String, applicationID), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryAttachmentList(applicationID));
	}


	// 2.��ȡ������ϸ�ӿ�
	 // �����ѯ�ӿ�����
	ENDPOINT_INFO(queryAttachmentsDetail) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("process.attachments.getdetail.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(AttachmentDetailJsonVO);
		//׷�Ӳ�ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "attachmentID", ZH_WORDS_GETTER("process.attachments.field.id"), "A", true);
	}
	// �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/process-app-manager/attahcment/query-detail", queryAttachmentsDetail, QUERY(String, attachmentID), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execQueryAttachmentDetail(attachmentID));
	}

private: // ����ӿڵ�ִ�к���
	StringJsonVO::Wrapper execAddAttachement(std::shared_ptr<IncomingRequest> request, const PayloadDTO& payload);
	StringJsonVO::Wrapper execUpdateAttachment(const AttachmentOperateDTO::Wrapper dto, const PayloadDTO& payload);
	StringJsonVO::Wrapper execDeleteAttachment(const String attachmentId);
	AttachmentListJsonVO::Wrapper execQueryAttachmentList(const oatpp::String& applicationID);
	AttachmentDetailJsonVO::Wrapper execQueryAttachmentDetail(const oatpp::String& attachmentID);
};

// ��β
#include OATPP_CODEGEN_END(ApiController)

#endif //! _ATTACHMENT_CONTROLLER_
