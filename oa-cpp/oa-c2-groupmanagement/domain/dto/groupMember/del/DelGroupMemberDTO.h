//
// Created by asd on 2024/10/20.
//

#ifndef DELGROUPMEMBERDTO_H
#define DELGROUPMEMBERDTO_H

#include "../../../GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)


class DelGroupMemberDTO : public oatpp::DTO {
public:
	DTO_INIT(DelGroupMemberDTO, DTO);
	//这两者之间是所属关系
	//这个是所属的群组id
	API_DTO_FIELD_DEFAULT(String, gruopId, ZH_WORDS_GETTER("groupMember.del.field.groupId"));
	//这个是群组id列表
	API_DTO_FIELD_DEFAULT(List<String>, groupList, ZH_WORDS_GETTER("groupMember.del.field.groupList"));
	/*//这个应该是用来表示呈现数据的排序规则的，也有可能是计数用的
	API_DTO_FIELD_DEFAULT(UInt64, orderColumn, ZH_WORDS_GETTER("groupMember.add.field.orderColumn"));*/
private:
};

#include OATPP_CODEGEN_END(DTO)

#endif //DELGROUPMEMBERDTO_H
