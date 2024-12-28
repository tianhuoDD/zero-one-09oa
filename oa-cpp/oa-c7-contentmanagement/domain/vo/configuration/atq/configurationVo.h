#pragma once
#ifndef  _CONFIGURATIONVO
#define _CONFIGURATIONVO
#include "../../../GlobalInclude.h"

#include"../../../dto/configuration/atq/configurationDto.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���������
 */
//class configurationVo : public oatpp::DTO
//{
//	DTO_INIT(configurationVo, DTO);
//	//ѡ������
//	API_DTO_FIELD(String, xcreatorUnitName, ZH_WORDS_GETTER("configuration.atq.choose.summary"), true, ZH_WORDS_GETTER("configuration.atq.choose.edit"));//xappId
//	//�����ʶ
//	API_DTO_FIELD(String, xappId, ZH_WORDS_GETTER("configuration.atq.basic.logo"), true, "abababababab");//xid
//	//�������
//	API_DTO_FIELD(String, xalias, ZH_WORDS_GETTER("configuration.atq.basic.name"), true, "newfile");//xalias
//	//�ĵ�����
//	API_DTO_FIELD(String, xdocumentType, ZH_WORDS_GETTER("configuration.atq.basic.type"), true, "Information");//xname
//	//����ʱ�Ƿ�����Ϣ
//	API_DTO_FIELD(String, xsendNotify, ZH_WORDS_GETTER("configuration.atq.basic.auto"), true, "yes");//xdata
//	//ʹ������
//	API_DTO_FIELD(String, process, ZH_WORDS_GETTER("configuration.atq.process"), true, "from 1 to 2");//xsequence
//	//�ɼ���Χ
//	API_DTO_FIELD(String, range, ZH_WORDS_GETTER("configuration.atq.range"), true, "everyone");//xdescription
//	//������
//	API_DTO_FIELD(String, xcreatorPerson, ZH_WORDS_GETTER("configuration.atq.publish"), true, "xiaohe");//xeditor
//	//������
//	API_DTO_FIELD(String, xmanagePerson, ZH_WORDS_GETTER("configuration.atq.manage"), true, "xadmin");//xproperties
//};

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class ConfigurationVO : public JsonVO<ConfigurationDTO::Wrapper> {
	DTO_INIT(ConfigurationVO, JsonVO<ConfigurationDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class ConfigurationPageJsonVO : public JsonVO<ConfigurationPageDTO::Wrapper> {
	DTO_INIT(ConfigurationPageJsonVO, JsonVO<ConfigurationPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_ CONFIGURATIONDTO_H_