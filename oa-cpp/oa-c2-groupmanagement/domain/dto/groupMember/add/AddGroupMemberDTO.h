//
// Created by asd on 2024/10/19.
//

#ifndef ADDGROUPMEMBERDTO_H
#define ADDGROUPMEMBERDTO_H

#include "../../../GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class AddGroupMemberReqDTO : public oatpp::DTO {
public:
	DTO_INIT(AddGroupMemberReqDTO, DTO);
	//这两者之间是所属关系
	//这个是所属的群组id
	API_DTO_FIELD_DEFAULT(String, gruopId, ZH_WORDS_GETTER("groupMember.add.field.groupId"));
	//这个是群组id列表
	API_DTO_FIELD_DEFAULT(List<String>, groupList, ZH_WORDS_GETTER("groupMember.add.field.groupList"));
	/*//这个应该是用来表示呈现数据的排序规则的，也有可能是计数用的
	API_DTO_FIELD_DEFAULT(UInt64, orderColumn, ZH_WORDS_GETTER("groupMember.add.field.orderColumn"));*/
};

class AddGroupMemberRespDTO : public oatpp::DTO {
public:
	DTO_INIT(AddGroupMemberRespDTO, DTO);
	//在前端显示的一个是群组名称 对应数据库表字段（xname），另一个是群组全称（xdistinguishedName）
	//所以返回一个列表，里面包含若干条这样的信息。
	API_DTO_FIELD_DEFAULT(String, groupId, ZH_WORDS_GETTER("groupMember.add.field.myGroupId") );
	API_DTO_FIELD_DEFAULT(String, groupName, ZH_WORDS_GETTER("groupMember.add.field.groupName"));
	API_DTO_FIELD_DEFAULT(String, distinguishedName, ZH_WORDS_GETTER("groupMember.add.field.groupFullName"));
};

#include OATPP_CODEGEN_END(DTO)

#endif //ADDGROUPMEMBERDTO_H
