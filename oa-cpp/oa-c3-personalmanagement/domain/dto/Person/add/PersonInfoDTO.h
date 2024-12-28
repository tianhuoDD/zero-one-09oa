#pragma once
#ifndef _PERSONINFODTO_H_
#define _PERSONINFODTO_H_

#include "../../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * editorͼƬ��Ϣ�������ݶ���
 */
class PersioninfoDTO : public oatpp::DTO
{
	DTO_INIT(PersioninfoDTO, DTO);
	//��Ա����
	API_DTO_FIELD(String, renyuanmingcheng, ZH_WORDS_GETTER("person.add.name"), true, "ddg");
	//�ֻ�����
	API_DTO_FIELD(String, shoujihaoma, ZH_WORDS_GETTER("person.add.number"), true, "13800000000");
	//�Ա�
	API_DTO_FIELD(String, xingbie, ZH_WORDS_GETTER("person.add.sex"), true, "m");
	//��������
	API_DTO_FIELD(String, dianziyouxiang, ZH_WORDS_GETTER("person.add.email"), false, "01@qq.com");
	//QQ����
	API_DTO_FIELD(String, qqhaoma, ZH_WORDS_GETTER("person.add.qqhaoma"), false, "12345678");
	//��ְʱ��
	API_DTO_FIELD(String, ruzhishijian, ZH_WORDS_GETTER("person.add.ruzhishijian"), false, "2024-10-31");
	//��¼ip
	API_DTO_FIELD(String, dengluip, ZH_WORDS_GETTER("person.add.dengluip"), false, "1.1.1.0");
	//�ܼ���ʶ
	API_DTO_FIELD(String, mijibiaoshi, ZH_WORDS_GETTER("person.add.mijibiaoshi"), false, "100");
	//Ψһ����
	API_DTO_FIELD(String, weiyibianma, ZH_WORDS_GETTER("person.add.weiyibianma"), true, "111");
	//��Ա����
	API_DTO_FIELD(String, renyuangonghao, ZH_WORDS_GETTER("person.add.renyuangonghao"), false, "987456");
	//�㱨����
	API_DTO_FIELD(String, huibaoduixiang, ZH_WORDS_GETTER("person.add.huibaoduixiang"), false, "");
	//΢�ź�
	API_DTO_FIELD(String, weixinhao, ZH_WORDS_GETTER("person.add.weixinhao"), false, "666");
	//�칫�绰
	API_DTO_FIELD(String, bangongdianhua, ZH_WORDS_GETTER("person.add.bangongdianhua"), false, "400123123");
	//��������
	API_DTO_FIELD(String, chushengriqi, ZH_WORDS_GETTER("person.add.chushengriqi"), false, "2023-10-03");
	//����
	API_DTO_FIELD(String, miaoshu, ZH_WORDS_GETTER("person.add.miaoshu"), false, "hh");
	//״̬
	API_DTO_FIELD(String, zhuangtai, ZH_WORDS_GETTER("person.add.zhuangtai"), false, "0");
	//ƴ��
	API_DTO_FIELD(String, pinyin, ZH_WORDS_GETTER("person.add.pinyin"), false, "");
	//ƴ����д
	API_DTO_FIELD(String, pinyinsuoxie, ZH_WORDS_GETTER("person.add.pinyinsuoxie"), false, "");




	 






	 
public:
	PersioninfoDTO() {}
 
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_FILEDTO_H_