#include "ImportController.h"
#include "ExcelComponent.h"
#include "../../dao/excel/UpExcelDAO.h"


ImportResponseDTO::Wrapper ImportController::check_validity(std::shared_ptr<IncomingRequest> request, std::list<std::string>& authorities)
{
	// 1.���Ϸ�����ų�

	auto ret = ImportResponseDTO::createShared();

	// �ȼ���Ƿ���Ȩ��
	/*bool flag=false;
	for (auto role : authorities)
		if (role == "PersonManager")
			flag = true;*/

			//if(!flag)	// û��Ȩ��
			//{
			//	ret->type = "error";
			//	ret->message = "You dont't have the right to import persion";
			//	ret->date = SimpleDateTimeFormat::format();
			//	ret->size = -1;
			//	ret->count = 0;

			//	return ret;
			//}

			// ����Ƿ���excel�ļ������ļ��Ƿ���
	API_MULTIPART_INIT(container, reader);
	API_MULTIPART_CONFIG_MEMO_DEFAULT(reader, -1);

	request->transferBody(&reader);
	OATPP_LOGD("Multipart", "parts_count=%d", container->count());/* ��ӡ�ϴ��ܲ����� */


	API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);

	if (file)
	{
		/* ��ӡ�ļ����� */
		string filename = partfile->getFilename().getValue("");
		OATPP_LOGD("Multipart", "file='%s'", filename.c_str());
		if (filename.substr(filename.find_last_of(".")) != ".xlsx")	// ���.xlsx��׺
		{
			ret->type = "error";
			ret->message = "No valid entries or contents found, this is not a valid OOXML (Office Open XML) file";
			ret->date = SimpleDateTimeFormat::format();
			ret->size = -1;
			ret->count = 0;

			return ret;
		}

	}
	else
	{
		ret->type = "error";
		ret->message = "No valid entries or contents found, this is not a valid OOXML (Office Open XML) file";
		ret->date = SimpleDateTimeFormat::format();
		ret->size = -1;
		ret->count = 0;

		return ret;
	}

	// 2. �Ϸ����
	ret->type = "success";
	ret->message = "Submit OK";

	// ��ȡ�ϴ����ļ���excel��ʽ��˳����ص�UpExcelDAO��
	ExcelComponent excel;
	std::vector<std::vector<std::string>> data;

	UpExcelDAO up;

	// data = excel.readIntoVector(reinterpret_cast<const char*>(file->data()), file->size(), ZH_WORDS_GETTER("excel.sheetname.sheet2"));
	// up.init_and_insertsheet1(data);

	data = excel.readIntoVector(reinterpret_cast<const char*>(file->data()), file->size(), ZH_WORDS_GETTER("excel.sheetname.sheet3"));
	up.init_and_insertsheet2(data);

	//data = excel.readIntoVector(reinterpret_cast<const char*>(file->data()), file->size(), ZH_WORDS_GETTER("excel.sheetname.sheet4"));
	//up.init_and_insertsheet3(data);

	//data = excel.readIntoVector(reinterpret_cast<const char*>(file->data()), file->size(), ZH_WORDS_GETTER("excel.sheetname.sheet5"));
	//up.init_and_insertsheet4(data);

	//data = excel.readIntoVector(reinterpret_cast<const char*>(file->data()), file->size(), ZH_WORDS_GETTER("excel.sheetname.sheet6"));
	//up.init_and_insertsheet5(data);

	//up.insert_othertables();


	return ret;
}
