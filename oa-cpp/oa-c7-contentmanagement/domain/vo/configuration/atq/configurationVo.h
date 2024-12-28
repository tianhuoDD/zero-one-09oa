#pragma once
#ifndef  _CONFIGURATIONVO
#define _CONFIGURATIONVO
#include "../../../GlobalInclude.h"

#include"../../../dto/configuration/atq/configurationDto.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
//class configurationVo : public oatpp::DTO
//{
//	DTO_INIT(configurationVo, DTO);
//	//选择分类表单
//	API_DTO_FIELD(String, xcreatorUnitName, ZH_WORDS_GETTER("configuration.atq.choose.summary"), true, ZH_WORDS_GETTER("configuration.atq.choose.edit"));//xappId
//	//分类标识
//	API_DTO_FIELD(String, xappId, ZH_WORDS_GETTER("configuration.atq.basic.logo"), true, "abababababab");//xid
//	//分类别名
//	API_DTO_FIELD(String, xalias, ZH_WORDS_GETTER("configuration.atq.basic.name"), true, "newfile");//xalias
//	//文档类型
//	API_DTO_FIELD(String, xdocumentType, ZH_WORDS_GETTER("configuration.atq.basic.type"), true, "Information");//xname
//	//发布时是否发送消息
//	API_DTO_FIELD(String, xsendNotify, ZH_WORDS_GETTER("configuration.atq.basic.auto"), true, "yes");//xdata
//	//使用流程
//	API_DTO_FIELD(String, process, ZH_WORDS_GETTER("configuration.atq.process"), true, "from 1 to 2");//xsequence
//	//可见范围
//	API_DTO_FIELD(String, range, ZH_WORDS_GETTER("configuration.atq.range"), true, "everyone");//xdescription
//	//发布者
//	API_DTO_FIELD(String, xcreatorPerson, ZH_WORDS_GETTER("configuration.atq.publish"), true, "xiaohe");//xeditor
//	//管理者
//	API_DTO_FIELD(String, xmanagePerson, ZH_WORDS_GETTER("configuration.atq.manage"), true, "xadmin");//xproperties
//};

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class ConfigurationVO : public JsonVO<ConfigurationDTO::Wrapper> {
	DTO_INIT(ConfigurationVO, JsonVO<ConfigurationDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class ConfigurationPageJsonVO : public JsonVO<ConfigurationPageDTO::Wrapper> {
	DTO_INIT(ConfigurationPageJsonVO, JsonVO<ConfigurationPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_ CONFIGURATIONDTO_H_