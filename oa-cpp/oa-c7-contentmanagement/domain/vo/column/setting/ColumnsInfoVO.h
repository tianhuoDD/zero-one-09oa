#pragma once


#ifndef _COLUMNSINFO_VO_
#define _COLUMNSINFO_VO_

#include "../../../GlobalInclude.h"
#include "../../../dto/column/setting/ColumnsInfoDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class ColumnsInfoVO : public oatpp::DTO
{
	DTO_INIT(ColumnsInfoVO, DTO);
	// 栏目唯一键值
	API_DTO_FIELD(String, id, ZH_WORDS_GETTER("column.field.id"), true, "123123");
	// 栏目名字
	API_DTO_FIELD(String, name, ZH_WORDS_GETTER("column.field.name"), true, "yxqf");
	// 栏目别名
	API_DTO_FIELD(String, othername, ZH_WORDS_GETTER("column.field.other-name"), false, "234234");
	// 栏目描述
	API_DTO_FIELD(String, description, ZH_WORDS_GETTER("column.field.description"), false, "qwerqwer");
	// 栏目排序
	API_DTO_FIELD(String, sort, ZH_WORDS_GETTER("column.field.sort"), false, "asdf");
	// 栏目类型
	API_DTO_FIELD(String, type, ZH_WORDS_GETTER("column.field.type"), false, "zxcv");
	// 默认编辑表单
	API_DTO_FIELD(String, defaultEditForm, ZH_WORDS_GETTER("column.field.default-edit-form"), false, "azxcv");
	// 默认阅读表
	API_DTO_FIELD(String, defaultReadForm, ZH_WORDS_GETTER("column.field.default-read-form"), false, "aytui");
	// 栏目图标
	API_DTO_FIELD(String, image, ZH_WORDS_GETTER("column.field.image"), false, "image");

	//// 创建时间
	//API_DTO_FIELD(String, xcreateTime, ZH_WORDS_GETTER("cms_appinfo.field.xcreate-time"), true, "2024-01-01T00:00:00Z");
	//// 排序或表示状态的序列
	//API_DTO_FIELD(String, xsequence, ZH_WORDS_GETTER("cms_appinfo.field.xsequence"), false, "1.0.0");
	//// 最后更新时间
	//API_DTO_FIELD(String, xupdateTime, ZH_WORDS_GETTER("cms_appinfo.field.xupdate-time"), false, "2024-01-01T00:00:00Z");
	//// 分发因素
	//API_DTO_FIELD(Int32, xdistributeFactor, ZH_WORDS_GETTER("cms_appinfo.field.xdistribute-factor"), false, 0);
	//// 是否允许所有人发布内容
	//API_DTO_FIELD(Boolean, xallPeoplePublish, ZH_WORDS_GETTER("cms_appinfo.field.xall-people-publish"), false, false);
	//// 是否允许所有人查看内容
	//API_DTO_FIELD(Boolean, xallPeopleView, ZH_WORDS_GETTER("cms_appinfo.field.xall-people-view"), false, false);
	//// 是否显示所有文档
	//API_DTO_FIELD(Boolean, xshowAllDocuments, ZH_WORDS_GETTER("cms_appinfo.field.xshow-all-documents"), false, false);
	//// 是否允许匿名访问
	//API_DTO_FIELD(Boolean, xanonymousAble, ZH_WORDS_GETTER("cms_appinfo.field.xanonymous-able"), false, false);

	//// 应用程序的备注
	//API_DTO_FIELD(String, xappMemo, ZH_WORDS_GETTER("cms_appinfo.field.xapp-memo"), false, "应用备注");
	//// 创建者的身份标识
	//API_DTO_FIELD(String, xcreatorIdentity, ZH_WORDS_GETTER("cms_appinfo.field.xcreator-identity"), false, "用户ID");
	//// 创建者的姓名
	//API_DTO_FIELD(String, xcreatorPerson, ZH_WORDS_GETTER("cms_appinfo.field.xcreator-person"), false, "创建者姓名");
	//// 创建者所在的顶级单位名称
	//API_DTO_FIELD(String, xcreatorTopUnitName, ZH_WORDS_GETTER("cms_appinfo.field.xcreator-top-unit-name"), false, "顶级单位");
	//// 创建者所在的单位名称
	//API_DTO_FIELD(String, xcreatorUnitName, ZH_WORDS_GETTER("cms_appinfo.field.xcreator-unit-name"), false, "单位名称");
	//// 文档类型
	//API_DTO_FIELD(String, xdocumentType, ZH_WORDS_GETTER("cms_appinfo.field.xdocument-type"), false, "文档类型");
	//// 应用程序图标的颜色
	//API_DTO_FIELD(String, xiconColor, ZH_WORDS_GETTER("cms_appinfo.field.xicon-color"), false, "图标颜色");
	//// 是否发送通知
	//API_DTO_FIELD(Boolean, xsendNotify, ZH_WORDS_GETTER("cms_appinfo.field.xsend-notify"), false, false);

};


/**
 * 定义一个栏目信息显示JsonVO对象，用于响应给客户端
 */
class ColumnsInfoJsonVO : public JsonVO<ColumnsInfoDTO::Wrapper>
{
	DTO_INIT(ColumnsInfoJsonVO, JsonVO<ColumnsInfoDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif //!_COLUMNSINFO_VO_
