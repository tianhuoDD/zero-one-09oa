package com.zeroone.star.project.j5.bizcenter;


import com.zeroone.star.project.query.j5.bizcenter.*;
import com.zeroone.star.project.vo.JsonVO;

/**
 * @program: oa-java
 * @description: 办公中心-获取流程列表(条件+分页)Api
 * @Author:或者火腿肠(hamhuo)
 * @CreateTime:10/19/202420:05
 **/
public interface QueryProcessListApis {

    /**
     * 查询获取流程列表-待办
     * @param ppCTaskQuery
     * @return
     */
    public JsonVO selectTaskListByPerson(PpCTaskQuery ppCTaskQuery);

    /**
     * 查询获取流程列表-参阅
     * @param ppCReviewQuery
     * @return
     */
    public JsonVO selectReviewListByPerson(PpCReviewQuery ppCReviewQuery);

    /**
     * 查询获取流程列表-待阅
     * @param ppCReadQuery
     * @return
     */
    public JsonVO selectReadListByPerson(PpCReadQuery ppCReadQuery);

    /**
     * 查询获取流程列表-草稿
     * @param ppCDraftQuery
     * @return
     */
    public JsonVO selectDraftListByPerson(PpCDraftQuery ppCDraftQuery);

    /**
     * 查询获取流程列表-已办
     * @param ppCTaskcompletedQuery
     * @return
     */
    public JsonVO selectTaskcompletedListByPerson(PpCTaskcompletedQuery ppCTaskcompletedQuery);

    /**
     * 查询获取流程列表-已阅
     * @param ppCReadcompletedQuery
     * @return
     */
    public JsonVO selectReadcompletedListByPerson(PpCReadcompletedQuery ppCReadcompletedQuery);

    /**
     * 查询获取流程列表-我创建的
     * @param ppCWorkQuery
     * @return
     */
    public JsonVO selectWorkListByPerson(PpCWorkQuery ppCWorkQuery);
}
