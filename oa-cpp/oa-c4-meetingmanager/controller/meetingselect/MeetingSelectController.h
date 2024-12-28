#pragma once
#ifndef _MEETINGSELECT_CONTROLLER_
#define _MEETINGSELECT_CONTROLLER_

#include "../../domain/vo/orgmanager/MeetingSelectVO.h"
#include "../../domain/dto/orgmanager/meetingselect/MeetingSelectDTO.h"
#include "../../domain/query/MeetingSelect/MeetingSelectQuery.h"
#include "domain/vo/BaseJsonVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ����ѡ�������
 * �������ڲ�ѯ�����桢���º�ɾ�������¼�� API �˵�
 */
class MeetingSelectController : public oatpp::web::server::api::ApiController {
    API_ACCESS_DECLARE(MeetingSelectController);

public:
    // ��ѯ����ȡ�����¼�Ľӿڣ��ۺ�ɸѡ�������ѯ���ܣ�
    ENDPOINT_INFO(queryMeetingWithDetails) {
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("orgmanager.meetingselect.get.summary"));
        API_DEF_ADD_AUTH();
        API_DEF_ADD_RSP_JSON_WRAPPER(MeetingSelectPageJsonVO);
        API_DEF_ADD_PAGE_PARAMS();

        // ��ѯ����
        API_DEF_ADD_QUERY_PARAMS(String, "type", ZH_WORDS_GETTER("orgmanager.meetingselect.field.type"), "0", true); // ���룺1�����룺2
        API_DEF_ADD_QUERY_PARAMS(String, "status", ZH_WORDS_GETTER("orgmanager.meetingselect.field.status"), "a", true); // δ��ʼ��a�������У�b���ѽ�����c
        //UInt64 id_value = std::stoull("0");
        API_DEF_ADD_QUERY_PARAMS(String, "applicant", ZH_WORDS_GETTER("orgmanager.meetingselect.field.applicant"), "0", false); // ��ѡ��id���������ڲ�ѯ������������
    }

    ENDPOINT(API_M_GET, "/meeting/query-one", queryMeetingWithDetails,
        QUERY(String, type, "type"),            // �������ͣ����룺1�����룺2��
        QUERY(String, status, "status"),               // ����״̬��δ��ʼ��a�������У�b���ѽ�����c��
        QUERY(String, applicant, "applicant"), // ��ѡ�Ļ��� ID��Ĭ��ֵΪ 0 ��ʾ��ָ���������
        API_HANDLER_AUTH_PARAME) {

        if (applicant != "0") {
            // ����ṩ�� id ���������ѯ���������¼����ϸ��Ϣ
            API_HANDLER_RESP_VO(execQueryOneMeeting(applicant, authObject->getPayload()));
        }
        else {
            // ���δ�ṩ id ����������� type �� status ɸѡ�����б�
            MeetingSelectQuery::Wrapper userQuery = MeetingSelectQuery::createShared();
            userQuery->type = type;
            userQuery->status = status;

            // ִ�ж��������¼�Ĳ�ѯ�����ؽ��
           API_HANDLER_RESP_VO(execQueryMeeting(userQuery, authObject->getPayload()));
        }
    }


    //// ��ѯ���л����¼�Ľӿ�
    //ENDPOINT_INFO(queryAllMeetings) {
    //    API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("orgmanager.meetingselect.query-all.summary"), MeetingSelectPageJsonVO::Wrapper);
    //    API_DEF_ADD_PAGE_PARAMS();

    //    API_DEF_ADD_QUERY_PARAMS(String, "title", ZH_WORDS_GETTER("orgmanager.meetingselect.field.title"), "", false);
    //}
    //// 3.2 �����������ʽ������õĽӿ�1����
    //API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/meeting/query-all", queryAllMeetings, MeetingSelectQuery, execQueryAllMeetings(query, authObject->getPayload()));

private:
private:
    // ��ѯ���������¼
    MeetingSelectPageJsonVO::Wrapper execQueryMeeting(const MeetingSelectQuery::Wrapper& query, const PayloadDTO& payload);

    // ��ѯ���������¼
    MeetingSelectJsonVO::Wrapper execQueryOneMeeting(const String& applicant, const PayloadDTO& payload);

    //// ��ѯ���л����¼
    //MeetingSelectPageJsonVO::Wrapper execQueryAllMeetings(const MeetingSelectQuery::Wrapper& query, const PayloadDTO& payload);

};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _MEETINGSELECT_CONTROLLER_
