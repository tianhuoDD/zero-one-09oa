#include "ImportController.h"
#include "ExcelComponent.h"
#include "../../dao/excel/UpExcelDAO.h"


ImportResponseDTO::Wrapper ImportController::check_validity(std::shared_ptr<IncomingRequest> request, std::list<std::string>& authorities)
{
	// 1.不合法情况排除

	auto ret = ImportResponseDTO::createShared();

	// 先检查是否有权限
	/*bool flag=false;
	for (auto role : authorities)
		if (role == "PersonManager")
			flag = true;*/

			//if(!flag)	// 没有权限
			//{
			//	ret->type = "error";
			//	ret->message = "You dont't have the right to import persion";
			//	ret->date = SimpleDateTimeFormat::format();
			//	ret->size = -1;
			//	ret->count = 0;

			//	return ret;
			//}

			// 检查是否是excel文件还有文件是否损坏
	API_MULTIPART_INIT(container, reader);
	API_MULTIPART_CONFIG_MEMO_DEFAULT(reader, -1);

	request->transferBody(&reader);
	OATPP_LOGD("Multipart", "parts_count=%d", container->count());/* 打印上传总部分数 */


	API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);

	if (file)
	{
		/* 打印文件名称 */
		string filename = partfile->getFilename().getValue("");
		OATPP_LOGD("Multipart", "file='%s'", filename.c_str());
		if (filename.substr(filename.find_last_of(".")) != ".xlsx")	// 检查.xlsx后缀
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

	// 2. 合法情况
	ret->type = "success";
	ret->message = "Submit OK";

	// 读取上传的文件到excel格式，顺便加载到UpExcelDAO中
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
