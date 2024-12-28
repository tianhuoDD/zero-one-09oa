#pragma once
#ifndef _ADD_DEL_MEMBERCONTROLLER_H_
#define _ADD_DEL_MEMBERCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/add_del_PersonMember/MemberVO.h"
#include "service/Member/MemberServer.h"
#include"domain/dto/add_del_PersonMember/MemberDTO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class add_del_MemberController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(add_del_MemberController);
public:// 3 ����ӿ�
	//������ӽӿ�����
	ENDPOINT_INFO(addMember) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("add_del_PersonMember.post.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	//���������ӿڴ���
	ENDPOINT(API_M_POST, "/add_Member", addMember, BODY_DTO(MemberDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddMember(dto));
	}
	//����ɾ���ӿ�����
	ENDPOINT_INFO(removeMember) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("add_del_PersonMember.delete.summary"), Uint64JsonVO::Wrapper);
		// ��������·������˵��
		API_DEF_ADD_PATH_PARAMS(UInt64, "id", ZH_WORDS_GETTER("add_del_PersonMember.field.id"), 1, true);
	}
	// ����ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/Member/{id}", removeMember, PATH(UInt64, id), execRemoveMember(id));
private:
	// ���Ӹ��˳�Ա
	Uint64JsonVO::Wrapper execAddMember(const MemberDTO::Wrapper& dto);
	// ɾ����Ա
	Uint64JsonVO::Wrapper execRemoveMember(const UInt64& id);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif //!_ADD_DEL_MEMBERCONTROLLER_H_