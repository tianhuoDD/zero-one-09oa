#pragma once
#ifndef _ACCEPTFILELISTDTO_H_
#define _ACCEPTFILELISTDTO_H_
#include "../../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class AcceptFileListDTO : public oatpp::DTO
{
	DTO_INIT(AcceptFileListDTO, DTO);
	//文件名
	API_DTO_FIELD(String, xname, ZH_WORDS_GETTER("accept.file.name"), false, "titok");
	//上传的文件名
	API_DTO_FIELD(String, xunique, ZH_WORDS_GETTER("accept.user.id"), false, "12345");
	//上传时间
	API_DTO_FIELD(String, xcreateTime, ZH_WORDS_GETTER("accept.file.unload"), false, "2024-03-11-13:21:32");
	//最近修改时间
	API_DTO_FIELD(String, xlastupdateTime, ZH_WORDS_GETTER("accept.file.changed"), false, "2024-03-14-17:23:32");
	//文件大小
	API_DTO_FIELD(Int64, xlength, ZH_WORDS_GETTER("accept.file.size"), false, 323);
	////文件分享
	//API_DTO_FIELD(String, xlength, ZH_WORDS_GETTER("accept.file.share"), false, "22");
	////文件发送
	//API_DTO_FIELD(String, xlength, ZH_WORDS_GETTER("accept.file.send"), false, "22");


};
class AcceptFilesPageDTO : public PageDTO<AcceptFileListDTO::Wrapper>
{
	DTO_INIT(AcceptFilesPageDTO, PageDTO<AcceptFileListDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_