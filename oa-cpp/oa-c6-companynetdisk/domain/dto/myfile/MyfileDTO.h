#pragma once

#ifndef _MYFILEDTO_H_
#define _MYFILEDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * editorͼƬ��Ϣ�������ݶ���
 */
class MyfileDTO : public oatpp::DTO
{
	DTO_INIT(MyfileDTO, DTO);

	// xid Ψһ��ʶ
	API_DTO_FIELD(String, xid, ZH_WORDS_GETTER("myfile.field.xid"), true, { "233" });
	//xcreateTime����ʱ��
	API_DTO_FIELD(String, xcreateTime, ZH_WORDS_GETTER("myfile.field.xcreateTime"), true, {});
	//xsequence ����ʱ�����Ψһ��ʶ

	//xupdateTime�޸�ʱ��
	API_DTO_FIELD(String, xupdateTime, ZH_WORDS_GETTER("myfile.field.xupdateTime"), true, {});
	//xdeepth ���
	API_DTO_FIELD(String, xdeepPath, ZH_WORDS_GETTER("myfile.field.xdeepPath"), true, {});
	//xextension �ļ���ʽ
	API_DTO_FIELD(String, xextension, ZH_WORDS_GETTER("myfile.field.xextension"), true, {});
	//xfolder ���ļ���xid����Ϊ�ļ���
	API_DTO_FIELD(String, xfolder, ZH_WORDS_GETTER("myfile.field.xfolder"), true, {});
	//xlastUpdatePerson ��������
	API_DTO_FIELD(String, xlastUpdatePerson, ZH_WORDS_GETTER("myfile.field.lastUpdatePerson"), true, {});
	//xlastUpdateTime ������ʱ��
	API_DTO_FIELD(String, xlastUpdateTime, ZH_WORDS_GETTER("myfile.field.xlastUpdateTime"), true, {});
	//xlength -bigint ������С
	API_DTO_FIELD(Int32, xlength, ZH_WORDS_GETTER("myfile.field.xlength"), true, 0);
	//xname �ļ�����
	API_DTO_FIELD(String, xname, ZH_WORDS_GETTER("myfile.field.xname"), true, {});
	//xperson�ϴ��û�
	API_DTO_FIELD(String, xperson, ZH_WORDS_GETTER("myfile.field.xperson"), true, {});

	// 
	//xstorage
	API_DTO_FIELD(String, xstorage, ZH_WORDS_GETTER("myfile.field.xstorage"), true, {});
	// xsuperior���ļ���xid �������ļ��У�

//public:
//	MyfileDTO() {}
//	MyfileDTO(String url, String alt = "", String href = "")
//	{
//		this->url = url;
//		this->alt = alt;
//		this->href = href;
//	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_FILEDTO_H_