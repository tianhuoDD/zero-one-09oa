//
// Created by asd on 2024/10/19.
//

#ifndef ADDUNITMEMBERDTO_H
#define ADDUNITMEMBERDTO_H

#include "../../../GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class AddUnitMemberReqDTO : public oatpp::DTO {
public:
	DTO_INIT(AddUnitMemberReqDTO, DTO);
	//这两者之间是所属关系
	//这个是所属的群组id
	API_DTO_FIELD_DEFAULT(String, gruopId, ZH_WORDS_GETTER("unitMember.add.field.groupId"));
	//这个是组织id列表
	API_DTO_FIELD_DEFAULT(List<String>, unitList, ZH_WORDS_GETTER("unitMember.add.field.groupList"));
};

class AddUnitMemberRespDTO : public:: oatpp::DTO {
public:
	DTO_INIT(AddUnitMemberRespDTO, DTO);
	//在前端显示的一个是群组名称 对应数据库表字段（xname），另一个是层级名称（xlevelName）
	//所以返回一个列表，里面包含若干条这样的信息。
	API_DTO_FIELD_DEFAULT( String, unitId, ZH_WORDS_GETTER("unitMember.add.field.myUnitId") );
	API_DTO_FIELD_DEFAULT(String, unitName, ZH_WORDS_GETTER("unitMember.add.field.unitName"));
	API_DTO_FIELD_DEFAULT(String, levelName, ZH_WORDS_GETTER("unitMember.add.field.unitFullName"));
};

#include OATPP_CODEGEN_END(DTO)

#endif //ADDUNITMEMBERDTO_H
