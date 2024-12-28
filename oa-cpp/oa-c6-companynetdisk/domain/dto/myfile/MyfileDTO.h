#pragma once

#ifndef _MYFILEDTO_H_
#define _MYFILEDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * editor图片信息传输数据对象
 */
class MyfileDTO : public oatpp::DTO
{
	DTO_INIT(MyfileDTO, DTO);

	// xid 唯一标识
	API_DTO_FIELD(String, xid, ZH_WORDS_GETTER("myfile.field.xid"), true, { "233" });
	//xcreateTime创建时间
	API_DTO_FIELD(String, xcreateTime, ZH_WORDS_GETTER("myfile.field.xcreateTime"), true, {});
	//xsequence 加上时间戳的唯一标识

	//xupdateTime修改时间
	API_DTO_FIELD(String, xupdateTime, ZH_WORDS_GETTER("myfile.field.xupdateTime"), true, {});
	//xdeepth 深度
	API_DTO_FIELD(String, xdeepPath, ZH_WORDS_GETTER("myfile.field.xdeepPath"), true, {});
	//xextension 文件格式
	API_DTO_FIELD(String, xextension, ZH_WORDS_GETTER("myfile.field.xextension"), true, {});
	//xfolder 父文件夹xid（当为文件）
	API_DTO_FIELD(String, xfolder, ZH_WORDS_GETTER("myfile.field.xfolder"), true, {});
	//xlastUpdatePerson 最后更新人
	API_DTO_FIELD(String, xlastUpdatePerson, ZH_WORDS_GETTER("myfile.field.lastUpdatePerson"), true, {});
	//xlastUpdateTime 最后更新时间
	API_DTO_FIELD(String, xlastUpdateTime, ZH_WORDS_GETTER("myfile.field.xlastUpdateTime"), true, {});
	//xlength -bigint 容量大小
	API_DTO_FIELD(Int32, xlength, ZH_WORDS_GETTER("myfile.field.xlength"), true, 0);
	//xname 文件名称
	API_DTO_FIELD(String, xname, ZH_WORDS_GETTER("myfile.field.xname"), true, {});
	//xperson上传用户
	API_DTO_FIELD(String, xperson, ZH_WORDS_GETTER("myfile.field.xperson"), true, {});

	// 
	//xstorage
	API_DTO_FIELD(String, xstorage, ZH_WORDS_GETTER("myfile.field.xstorage"), true, {});
	// xsuperior父文件夹xid （当问文件夹）

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