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
	//声明控制器的访问的入口
	API_ACCESS_DECLARE(AttachmentController);
public: //定义接口

	// --------------------上传附件--------------------------------------------------
	// 定义描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("attachment.post.summary"), addAttachment, StringJsonVO::Wrapper);
	//API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("attachment.post.summary"), addAttachment, StringJsonVO::Wrapper);
	// 定义端点
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/process-app-manager/attachment/add", addAttachment, REQUEST(std::shared_ptr<IncomingRequest>, request), execAddAttachement(request, authObject->getPayload()));
	//API_HANDLER_ENDPOINT(API_M_POST, "/process-app-manager/attachment/add", addAttachment, REQUEST(std::shared_ptr<IncomingRequest>, request), execAddAttachement(request, {}));
	// ------------------------end--------------------------------------------------------------------------------------


	// ---------------------------根据dto修改附件信息---------------------------------------------------------------------
	// 定义上传附件信息接口
	ENDPOINT_INFO(updateAttachment) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("attachment.put.summary"));
		// 定义权限校验 
		API_DEF_ADD_AUTH();
		// 定义响应参数
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// 参数处理
		//API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("attachment.field.name"), "xxx.png", true);
		//API_DEF_ADD_QUERY_PARAMS(String, "alais", ZH_WORDS_GETTER("attachment.field.alias"), "alias", false);
		//API_DEF_ADD_QUERY_PARAMS(String, "attachmentInfo", ZH_WORDS_GETTER("attachment.field.attachmentInfo"), "xxx.png", true);
		//API_DEF_ADD_QUERY_PARAMS(String, "attachment", ZH_WORDS_GETTER("attachment.field.attachment"), "xxx.png", true);

	}
	ENDPOINT(API_M_PUT, "/process-app-manager/attachment/update", updateAttachment, BODY_DTO(AttachmentOperateDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 执行文件保存逻辑
		API_HANDLER_RESP_VO(execUpdateAttachment(dto, authObject->getPayload()));
	}
	// --------------------------------end-----------------------------------

	// -------------------------定义删除------------------------------------------------------
	// 定义上传附件信息接口
	ENDPOINT_INFO(delAttachment) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("attachment.del.summary"));
		// 定义权限校验 
		API_DEF_ADD_AUTH();
		// 定义响应参数

		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// 参数处理
		API_DEF_ADD_PATH_PARAMS(String, "id", ZH_WORDS_GETTER("attachment.field.id"), "", true);
	}
	ENDPOINT(API_M_DEL, "/process-app-manager/attachment/delete/{id}", delAttachment, PATH(String, id), API_HANDLER_AUTH_PARAME) {
		// 执行删除逻辑
		API_HANDLER_RESP_VO(execDeleteAttachment(id));
	}

	// -----------------------------endl--------------------------------------------------------------------

	// 1.获取附件列表接口
	 // 定义查询接口描述
	ENDPOINT_INFO(queryAttachmentsList) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("process.attachments.getlist.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(AttachmentListJsonVO);
		//追加查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "applicationID", ZH_WORDS_GETTER("application.field.id"), "A", true);
	}
	ENDPOINT(API_M_GET, "/process-app-manager/attahcment/query-list", queryAttachmentsList, QUERY(String, applicationID), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryAttachmentList(applicationID));
	}


	// 2.获取附件详细接口
	 // 定义查询接口描述
	ENDPOINT_INFO(queryAttachmentsDetail) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("process.attachments.getdetail.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(AttachmentDetailJsonVO);
		//追加查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "attachmentID", ZH_WORDS_GETTER("process.attachments.field.id"), "A", true);
	}
	// 定义查询接口处理
	ENDPOINT(API_M_GET, "/process-app-manager/attahcment/query-detail", queryAttachmentsDetail, QUERY(String, attachmentID), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execQueryAttachmentDetail(attachmentID));
	}

private: // 定义接口的执行函数
	StringJsonVO::Wrapper execAddAttachement(std::shared_ptr<IncomingRequest> request, const PayloadDTO& payload);
	StringJsonVO::Wrapper execUpdateAttachment(const AttachmentOperateDTO::Wrapper dto, const PayloadDTO& payload);
	StringJsonVO::Wrapper execDeleteAttachment(const String attachmentId);
	AttachmentListJsonVO::Wrapper execQueryAttachmentList(const oatpp::String& applicationID);
	AttachmentDetailJsonVO::Wrapper execQueryAttachmentDetail(const oatpp::String& attachmentID);
};

// 结尾
#include OATPP_CODEGEN_END(ApiController)

#endif //! _ATTACHMENT_CONTROLLER_
