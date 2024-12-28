#pragma once

#ifndef _CALENDERINFODTO_H_
#define _CALENDERINFODTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//	日历信息操作对象
class CalenderInfoDTO : public oatpp::DTO {
	DTO_INIT(CalenderInfoDTO, DTO);

	//	日历ID
	API_DTO_FIELD(String, xid, ZH_WORDS_GETTER("calender.field.xid"), true, "123");
	//	日历名称
	API_DTO_FIELD(String, xname, ZH_WORDS_GETTER("calender.field.xname"), true, "aaa");
	//	颜色
	API_DTO_FIELD(String, xcolor, ZH_WORDS_GETTER("calender.field.xcolor"), true, "red");
	//	类型
	API_DTO_FIELD(String, xtype, ZH_WORDS_GETTER("calender.field.xtype"), true, "PERSON");
	//	是否公开
	API_DTO_FIELD(Int32, xisPublic, ZH_WORDS_GETTER("calender.field.xisPublic"), true, 1);
	//	备注
	API_DTO_FIELD(String, xdescription, ZH_WORDS_GETTER("calender.field.xdescription"), false, "");
	//	所属组织
	API_DTO_FIELD(String, xtarget, ZH_WORDS_GETTER("calender.field.xtarget"), true, "admin");
	//	管理者
	API_DTO_FIELD(String, xmanageablePersonList, ZH_WORDS_GETTER("calender.field.xmanageablePersonList"), true, "x@1@P");
	//	可见范围
	API_DTO_FIELD(String, xview, ZH_WORDS_GETTER("calender.field.xview"), false, "person unit group");
	//	可新建范围
	API_DTO_FIELD(String, xpublish, ZH_WORDS_GETTER("calender.field.xpublish"), false, "person unit group");
	//	是否启用
	API_DTO_FIELD(String, xstatus, ZH_WORDS_GETTER("calender.field.xstatus"), true, "yes");
	//	创建时间
	//API_DTO_FIELD(String, xcreatetime, ZH_WORDS_GETTER("calender.field.xcreatetime"), true, "yyyy-mm-dd");
	//	更新时间
	//API_DTO_FIELD(String, xupdatetime, ZH_WORDS_GETTER("calender.field.xupdatetime"), true, "yyyy-mm-dd");
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_CALENDERINFODTO_H_