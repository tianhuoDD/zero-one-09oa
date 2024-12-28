#pragma once

#ifndef _GETMTROOMPOS_DTO_
#define _GETMTROOMPOS_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 会议室位置传输对象
 */
class GetmtroomposDTO : public oatpp::DTO
{
	DTO_INIT(GetmtroomposDTO, DTO);
	// 会议室位置
	//DTO_FIELD(String, xcreateTime);
	//DTO_FIELD_INFO(xcreateTime) {
	//	info->description = ZH_WORDS_GETTER("mtroom.get.xcreateTime");
	//}
	//DTO_FIELD(String, xupdateTime);
	//DTO_FIELD_INFO(xupdateTime) {
	//	info->description = ZH_WORDS_GETTER("mtroom.get.xupdateTime");
	//}
	DTO_FIELD(String, xid);
	DTO_FIELD_INFO(xid) {
		info->description = ZH_WORDS_GETTER("mtroom.get.xid");
	}
	DTO_FIELD(String, xaddress);
	DTO_FIELD_INFO(xaddress) {
		info->description = ZH_WORDS_GETTER("mtroom.get.xaddress");
	}
	DTO_FIELD(String, xname);
	DTO_FIELD_INFO(xname) {
		info->description = ZH_WORDS_GETTER("mtroom.get.xname");
	}
	//DTO_FIELD(String, xpinyin);
	//DTO_FIELD_INFO(xpinyin) {
	//	info->description = ZH_WORDS_GETTER("mtroom.get.xpinyin");
	//}
	//DTO_FIELD(String, xpinyinInitial);
	//DTO_FIELD_INFO(xpinyinInitial) {
	//	info->description = ZH_WORDS_GETTER("mtroom.get.xpinyinInitial");
	//}
};

/**
 * 会议室位置分页传输对象
 */
class GetmtroomposPageDTO : public PageDTO<GetmtroomposDTO::Wrapper>
{
	DTO_INIT(GetmtroomposPageDTO, PageDTO<GetmtroomposDTO::Wrapper>);
	//DTO_FIELD(Vector<Object<GetmtroomposDTO>>, rows);
};

class AddmtroomposDTO : public oatpp::DTO
{
	DTO_INIT(AddmtroomposDTO, DTO);
	// 会议室位置
	DTO_FIELD(String, xcreateTime);
	DTO_FIELD_INFO(xcreateTime) {
		info->description = ZH_WORDS_GETTER("mtroom.get.xcreateTime");
	}
	DTO_FIELD(String, xupdateTime);
	DTO_FIELD_INFO(xupdateTime) {
		info->description = ZH_WORDS_GETTER("mtroom.get.xupdateTime");
	}
	DTO_FIELD(String, xaddress);
	DTO_FIELD_INFO(xaddress) {
		info->description = ZH_WORDS_GETTER("mtroom.get.xaddress");
	}
	DTO_FIELD(String, xname);
	DTO_FIELD_INFO(xname) {
		info->description = ZH_WORDS_GETTER("mtroom.get.xname");
	}
	DTO_FIELD(String, xpinyin);
	DTO_FIELD_INFO(xpinyin) {
		info->description = ZH_WORDS_GETTER("mtroom.get.xpinyin");
	}
	DTO_FIELD(String, xpinyinInitial);
	DTO_FIELD_INFO(xpinyinInitial) {
		info->description = ZH_WORDS_GETTER("mtroom.get.xpinyinInitial");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_GETMTROOMPOS_DTO_