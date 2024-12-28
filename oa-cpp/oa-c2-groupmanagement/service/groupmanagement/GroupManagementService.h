//
// Created by asd on 2024/10/23.
//
#ifndef GROUPMANAGEMENTSERVICE_H
#define GROUPMANAGEMENTSERVICE_H
#include <domain/dto/groupMember/del/DelGroupMemberDTO.h>
#include <domain/dto/unitMember/del/DelUnitMemberDTO.h>
#include <domain/dto/groupMember/add/AddGroupMemberDTO.h>
#include <domain/dto/unitMember/add/AddUnitMemberDTO.h>

#include <domain/vo/groupMember/add/AddGroupMemberVO.h>
#include <domain/vo/unitMember/add/AddUnitMemberVO.h>


class GroupManagementService {
public:
	// 删除群组成员
	bool delGroupMember(const DelGroupMemberDTO::Wrapper& dto);
    // 删除组织成员
	bool delUnitMember(const DelUnitMemberDTO::Wrapper& dto);

	// 添加群组成员
	AddGroupMemberJsonVO::Wrapper addGroupMember( const AddGroupMemberReqDTO::Wrapper& dto );
	// 添加组织成员
	AddUnitMemberJsonVO::Wrapper addUnitMember( const AddUnitMemberReqDTO::Wrapper& dto );
};



#endif //GROUPMANAGEMENTSERVICE_H
