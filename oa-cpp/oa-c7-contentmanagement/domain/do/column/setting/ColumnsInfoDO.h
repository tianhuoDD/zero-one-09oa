#pragma once
#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:52:32

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _ColumnsInfo_DO_
#define _ColumnsInfo_DO_
#include "../../DoInclude.h"

/**
 * 示例数据库实体类
 */

//class SampleDO
//{
//	// 编号
//	CC_SYNTHESIZE(uint64_t, id, Id);
//	// 姓名
//	CC_SYNTHESIZE(string, name, Name);
//	// 性别
//	CC_SYNTHESIZE(string, sex, Sex);
//	// 年龄
//	CC_SYNTHESIZE(int, age, Age);
//public:
//	SampleDO() {
//		id = 0;
//		name = "";
//		sex = "";
//		age = -1;
//	}
//};
//

/**
 * CMS 应用信息数据库实体类
 */
class ColumnsInfoDO
{
    // 主键 ID
    CC_SYNTHESIZE(string, xid, Xid);
    // 创建时间
    CC_SYNTHESIZE(string, xcreateTime, XcreateTime);
    // 序列
    CC_SYNTHESIZE(string, xsequence, Xsequence);
    // 更新时间
    CC_SYNTHESIZE(string, xupdateTime, XupdateTime);
    // 分发因子
    CC_SYNTHESIZE(int, xdistributeFactor, XdistributeFactor);
    // 所有人发布权限
    CC_SYNTHESIZE(bool, xallPeoplePublish, XallPeoplePublish);
    // 所有人查看权限
    CC_SYNTHESIZE(bool, xallPeopleView, XallPeopleView);
    // 显示所有文档
    CC_SYNTHESIZE(bool, xshowAllDocuments, XshowAllDocuments);
    // 匿名访问
    CC_SYNTHESIZE(bool, xanonymousAble, XanonymousAble);
    // 应用别名
    CC_SYNTHESIZE(string, xappAlias, XappAlias);
    // 应用图标
    CC_SYNTHESIZE(string, xappIcon, XappIcon);
    // 应用信息序列
    CC_SYNTHESIZE(string, xappInfoSeq, XappInfoSeq);
    // 备注
    CC_SYNTHESIZE(string, xappMemo, XappMemo);
    // 应用名称
    CC_SYNTHESIZE(string, xappName, XappName);
    // 应用类型
    CC_SYNTHESIZE(string, xappType, XappType);
    // 创建者身份
    CC_SYNTHESIZE(string, xcreatorIdentity, XcreatorIdentity);
    // 创建者
    CC_SYNTHESIZE(string, xcreatorPerson, XcreatorPerson);
    // 创建者顶级单位名称
    CC_SYNTHESIZE(string, xcreatorTopUnitName, XcreatorTopUnitName);
    // 创建者单位名称
    CC_SYNTHESIZE(string, xcreatorUnitName, XcreatorUnitName);
    // 默认编辑表单
    CC_SYNTHESIZE(string, xdefaultEditForm, XdefaultEditForm);
    // 默认阅读表单
    CC_SYNTHESIZE(string, xdefaultReadForm, XdefaultReadForm);
    // 描述
    CC_SYNTHESIZE(string, xdescription, Xdescription);
    // 文档类型
    CC_SYNTHESIZE(string, xdocumentType, XdocumentType);
    // 图标颜色
    CC_SYNTHESIZE(string, xiconColor, XiconColor);
    // 发送通知
    CC_SYNTHESIZE(bool, xsendNotify, XsendNotify);

public:
    ColumnsInfoDO() {
        xid = "";
        xcreateTime = "";
        xsequence = "";
        xupdateTime = "";
        xdistributeFactor = 0;
        xallPeoplePublish = false;
        xallPeopleView = false;
        xshowAllDocuments = false;
        xanonymousAble = false;
        xappAlias = "";
        xappIcon = "";
        xappInfoSeq = "";
        xappMemo = "";
        xappName = "";
        xappType = "";
        xcreatorIdentity = "";
        xcreatorPerson = "";
        xcreatorTopUnitName = "";
        xcreatorUnitName = "";
        xdefaultEditForm = "";
        xdefaultReadForm = "";
        xdescription = "";
        xdocumentType = "";
        xiconColor = "";
        xsendNotify = false;
    }
};


//class ColumnsInfoDO
//{
//    // 主键
//    CC_SYNTHESIZE(string, xid, Xid);
//    // 创建时间
//    CC_SYNTHESIZE(string, xcreateTime, XcreateTime);
//    // 序列
//    CC_SYNTHESIZE(string, xsequence, Xsequence);
//    // 更新时间
//    CC_SYNTHESIZE(string, xupdateTime, XupdateTime);
//    // 分发因子
//    CC_SYNTHESIZE(int, xdistributeFactor, XdistributeFactor);
//    // 是否允许所有人发布
//    CC_SYNTHESIZE(bool, xallPeoplePublish, XallPeoplePublish);
//    // 是否允许所有人查看
//    CC_SYNTHESIZE(bool, xallPeopleView, XallPeopleView);
//    // 是否允许匿名访问
//    CC_SYNTHESIZE(bool, xanonymousAble, XanonymousAble);
//    // 应用 ID
//    CC_SYNTHESIZE(string, xappId, XappId);
//    // 应用名称
//    CC_SYNTHESIZE(string, xappName, XappName);
//    // 是否对所有人发送通知
//    CC_SYNTHESIZE(bool, xblankToAllNotify, XblankToAllNotify);
//    // 栏目别名
//    CC_SYNTHESIZE(string, xcategoryAlias, XcategoryAlias);
//    // 栏目图标
//    CC_SYNTHESIZE(string, xcategoryIcon, XcategoryIcon);
//    // 栏目备注
//    CC_SYNTHESIZE(string, xcategoryMemo, XcategoryMemo);
//    // 栏目名称
//    CC_SYNTHESIZE(string, xcategoryName, XcategoryName);
//    // 栏目序列
//    CC_SYNTHESIZE(string, xcategorySeq, XcategorySeq);
//    // 创建者身份
//    CC_SYNTHESIZE(string, xcreatorIdentity, XcreatorIdentity);
//    // 创建者
//    CC_SYNTHESIZE(string, xcreatorPerson, XcreatorPerson);
//    // 创建者顶级单位
//    CC_SYNTHESIZE(string, xcreatorTopUnitName, XcreatorTopUnitName);
//    // 创建者单位
//    CC_SYNTHESIZE(string, xcreatorUnitName, XcreatorUnitName);
//    // 默认视图 ID
//    CC_SYNTHESIZE(string, xdefaultViewId, XdefaultViewId);
//    // 默认视图名称
//    CC_SYNTHESIZE(string, xdefaultViewName, XdefaultViewName);
//    // 描述
//    CC_SYNTHESIZE(string, xdescription, Xdescription);
//    // 文档类型
//    CC_SYNTHESIZE(string, xdocumentType, XdocumentType);
//    // 关联的表单 ID
//    CC_SYNTHESIZE(string, xformId, XformId);
//    // 关联的表单名称
//    CC_SYNTHESIZE(string, xformName, XformName);
//    // 导入视图应用 ID
//    CC_SYNTHESIZE(string, ximportViewAppId, XimportViewAppId);
//    // 导入视图 ID
//    CC_SYNTHESIZE(string, ximportViewId, XimportViewId);
//    // 导入视图名称
//    CC_SYNTHESIZE(string, ximportViewName, XimportViewName);
//    // 父栏目 ID
//    CC_SYNTHESIZE(string, xparentId, XparentId);
//    // 投影
//    CC_SYNTHESIZE(string, xprojection, Xprojection);
//    // 阅读表单 ID
//    CC_SYNTHESIZE(string, xreadFormId, XreadFormId);
//    // 阅读表单名称
//    CC_SYNTHESIZE(string, xreadFormName, XreadFormName);
//    // 是否发送通知
//    CC_SYNTHESIZE(bool, xsendNotify, XsendNotify);
//    // 工作流应用 ID
//    CC_SYNTHESIZE(string, xworkflowAppId, XworkflowAppId);
//    // 工作流应用名称
//    CC_SYNTHESIZE(string, xworkflowAppName, XworkflowAppName);
//    // 工作流标志
//    CC_SYNTHESIZE(string, xworkflowFlag, XworkflowFlag);
//    // 工作流名称
//    CC_SYNTHESIZE(string, xworkflowName, XworkflowName);
//    // 工作流类型
//    CC_SYNTHESIZE(string, xworkflowType, XworkflowType);
//
//public:
//    // 默认构造函数
//    ColumnsInfoDO() {
//        xid = "";
//        xcreateTime = "";
//        xsequence = "";
//        xupdateTime = "";
//        xdistributeFactor = 0;
//        xallPeoplePublish = false;
//        xallPeopleView = false;
//        xanonymousAble = false;
//        xappId = "";
//        xappName = "";
//        xblankToAllNotify = false;
//        xcategoryAlias = "";
//        xcategoryIcon = "";
//        xcategoryMemo = "";
//        xcategoryName = "";
//        xcategorySeq = "";
//        xcreatorIdentity = "";
//        xcreatorPerson = "";
//        xcreatorTopUnitName = "";
//        xcreatorUnitName = "";
//        xdefaultViewId = "";
//        xdefaultViewName = "";
//        xdescription = "";
//        xdocumentType = "";
//        xformId = "";
//        xformName = "";
//        ximportViewAppId = "";
//        ximportViewId = "";
//        ximportViewName = "";
//        xparentId = "";
//        xprojection = "";
//        xreadFormId = "";
//        xreadFormName = "";
//        xsendNotify = false;
//        xworkflowAppId = "";
//        xworkflowAppName = "";
//        xworkflowFlag = "";
//        xworkflowName = "";
//        xworkflowType = "";
//    }
//};


#endif // !_ColumnsInfo_DO_
