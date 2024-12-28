#pragma once
#ifndef _MEETINGSELECT_CONTROLLER_
#define _MEETINGSELECT_CONTROLLER_

#include "../../domain/vo/orgmanager/MeetingSelectVO.h"
#include "../../domain/dto/orgmanager/meetingselect/MeetingSelectDTO.h"
#include "../../domain/query/MeetingSelect/MeetingSelectQuery.h"
#include "domain/vo/BaseJsonVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 会议选择控制器
 * 定义用于查询、保存、更新和删除会议记录的 API 端点
 */
class MeetingSelectController : public oatpp::web::server::api::ApiController {
    API_ACCESS_DECLARE(MeetingSelectController);

public:
    // 查询并获取会议记录的接口（综合筛选和详情查询功能）
    ENDPOINT_INFO(queryMeetingWithDetails) {
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("orgmanager.meetingselect.get.summary"));
        API_DEF_ADD_AUTH();
        API_DEF_ADD_RSP_JSON_WRAPPER(MeetingSelectPageJsonVO);
        API_DEF_ADD_PAGE_PARAMS();

        // 查询参数
        API_DEF_ADD_QUERY_PARAMS(String, "type", ZH_WORDS_GETTER("orgmanager.meetingselect.field.type"), "0", true); // 申请：1，邀请：2
        API_DEF_ADD_QUERY_PARAMS(String, "status", ZH_WORDS_GETTER("orgmanager.meetingselect.field.status"), "a", true); // 未开始：a，进行中：b，已结束：c
        //UInt64 id_value = std::stoull("0");
        API_DEF_ADD_QUERY_PARAMS(String, "applicant", ZH_WORDS_GETTER("orgmanager.meetingselect.field.applicant"), "0", false); // 可选的id参数，用于查询单条会议详情
    }

    ENDPOINT(API_M_GET, "/meeting/query-one", queryMeetingWithDetails,
        QUERY(String, type, "type"),            // 会议类型（申请：1，邀请：2）
        QUERY(String, status, "status"),               // 会议状态（未开始：a，进行中：b，已结束：c）
        QUERY(String, applicant, "applicant"), // 可选的会议 ID，默认值为 0 表示不指定具体会议
        API_HANDLER_AUTH_PARAME) {

        if (applicant != "0") {
            // 如果提供了 id 参数，则查询单条会议记录的详细信息
            API_HANDLER_RESP_VO(execQueryOneMeeting(applicant, authObject->getPayload()));
        }
        else {
            // 如果未提供 id 参数，则根据 type 和 status 筛选会议列表
            MeetingSelectQuery::Wrapper userQuery = MeetingSelectQuery::createShared();
            userQuery->type = type;
            userQuery->status = status;

            // 执行多条会议记录的查询并返回结果
           API_HANDLER_RESP_VO(execQueryMeeting(userQuery, authObject->getPayload()));
        }
    }


    //// 查询所有会议记录的接口
    //ENDPOINT_INFO(queryAllMeetings) {
    //    API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("orgmanager.meetingselect.query-all.summary"), MeetingSelectPageJsonVO::Wrapper);
    //    API_DEF_ADD_PAGE_PARAMS();

    //    API_DEF_ADD_QUERY_PARAMS(String, "title", ZH_WORDS_GETTER("orgmanager.meetingselect.field.title"), "", false);
    //}
    //// 3.2 定义测试声明式服务调用的接口1处理
    //API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/meeting/query-all", queryAllMeetings, MeetingSelectQuery, execQueryAllMeetings(query, authObject->getPayload()));

private:
private:
    // 查询多条会议记录
    MeetingSelectPageJsonVO::Wrapper execQueryMeeting(const MeetingSelectQuery::Wrapper& query, const PayloadDTO& payload);

    // 查询单条会议记录
    MeetingSelectJsonVO::Wrapper execQueryOneMeeting(const String& applicant, const PayloadDTO& payload);

    //// 查询所有会议记录
    //MeetingSelectPageJsonVO::Wrapper execQueryAllMeetings(const MeetingSelectQuery::Wrapper& query, const PayloadDTO& payload);

};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _MEETINGSELECT_CONTROLLER_
