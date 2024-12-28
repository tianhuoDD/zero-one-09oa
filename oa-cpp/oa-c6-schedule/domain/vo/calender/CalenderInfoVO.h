#pragma once

#ifndef _CALENDERINFOVO_H_
#define _CALENDERINFOVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/calender/CalenderInfoDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)


//	日历信息显示对象
class CalenderInfoVO : public oatpp::DTO {
	DTO_INIT(CalenderInfoVO, DTO);

	//	日历ID，这个似乎不用显示
	//API_DTO_FIELD_DEFAULT(String, xid, ZH_WORDS_GETTER("calender.field.xid"));
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
	API_DTO_FIELD(String, xview, ZH_WORDS_GETTER("calender.field.xview"), false, "");
	//	可新建范围
	API_DTO_FIELD(String, xpublish, ZH_WORDS_GETTER("calender.field.xpublish"), false, "");
	//	是否启用
	API_DTO_FIELD(String, xstatus, ZH_WORDS_GETTER("calender.field.xstatus"), true, "yes");
	//	创建时间
	//API_DTO_FIELD(String, xcreatetime, ZH_WORDS_GETTER("calender.field.xcreatetime"), true, "yyyy-mm-dd");
	//	更新时间
	//API_DTO_FIELD(String, xupdatetime, ZH_WORDS_GETTER("calender.field.xupdatetime"), true, "yyyy-mm-dd");
};

/**
 * 定义状态提示信息
 */
#ifdef LINUX
#define RS_CALENDERNAME_FAIL ResultStatus(u8"the calendar name cannot be empty", 9991)
#define RS_CALENDERXTARGETRMPTY_FAIL ResultStatus(u8"the organization field cannot be empty", 9992)
#define RS_CALENDERDESCRIPTION_FAIL ResultStatus(u8"the description is too long", 9993)
#else
#define RS_CALENDERNAME_FAIL ResultStatus(u8"日历名称不能为空", 9991)
#define RS_CALENDERXTARGETRMPTY_FAIL ResultStatus(u8"所属组织不能为空", 9992)
#define RS_CALENDERDESCRIPTION_FAIL ResultStatus(u8"备注过长", 9993)
#endif

//	日历信息显示JsonVO，用于响应给客户端的Json对象
class CalenderInfoJsonVo : public JsonVO<CalenderInfoDTO::Wrapper> {
	DTO_INIT(CalenderInfoJsonVo, JsonVO<CalenderInfoDTO::Wrapper>);

	// 数据对象
	DTO_FIELD(CalenderInfoDTO::Wrapper, data, "data");
	DTO_FIELD_INFO(data) {
#ifndef LINUX
		info->description = u8"数据对象";
#else
		info->description = "data object";
#endif
	}

public:
	// 设置状态
	void setStatus(ResultStatus resultStatus) {
		this->message = resultStatus.getMessage();
		this->code = resultStatus.getCode();
	}
	// 初始化
	void init(ResultStatus resultStatus) {
		this->setStatus(resultStatus);
	}
	// 构建成功消息
	void success(CalenderInfoDTO::Wrapper data) {
		this->setStatus(RS_SUCCESS);
		this->data = data;
	}
	// 重载构建成功消息
	void success() {
		this->setStatus(RS_SUCCESS);
	}

	// 构建失败消息
	void fail(uint64_t data) {
		if (88 == data)
		{
			this->setStatus(RS_PARAMS_INVALID);
		}
		else
			this->setStatus(RS_FAIL);
	}

};

#include OATPP_CODEGEN_END(DTO)




#endif // !_CALENDERINFOVO_H_