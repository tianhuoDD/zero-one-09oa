#pragma once

#ifndef _FILELOG_H_
#define _FILELOG_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * editorͼƬ��Ϣ�������ݶ���
 */
class FileLogDTO : public oatpp::DTO
{
	DTO_INIT(FileLogDTO, DTO);

	// xid ��־Ψһ��ʶ
	API_DTO_FIELD(String, xid, ZH_WORDS_GETTER("myfile.Filelog.xid"), true, { "233" });
	//xextension �ϴ�����'1-���ͣ�2-����3-ɾ����4-�ϴ�',
	API_DTO_FIELD(Int32, xOperationType, ZH_WORDS_GETTER("myfile.Filelog.xoperationtype"), true, 0);
	//xlastUpdatePerson '������',
	API_DTO_FIELD(String, xFromPerson, ZH_WORDS_GETTER("myfile.Filelog.xFromPerson"), true, {});
	//xToPerson '������'
	API_DTO_FIELD(String, xToPerson, ZH_WORDS_GETTER("myfile.Filelog.xToPerson"), true, {});
	//xOperationTime ����ʱ��
	API_DTO_FIELD(String, xOperationTime, ZH_WORDS_GETTER("myfile.Filelog.xOperationTime"), true, {});
	//file_attachment_id  �����ļ���Ψһ��ʶ
	API_DTO_FIELD(String, file_attachment_id, ZH_WORDS_GETTER("myfile.Filelog.file_attachment_id"), true, {});
};
#include OATPP_CODEGEN_END(DTO)

#endif // !_FILEDTO_H_