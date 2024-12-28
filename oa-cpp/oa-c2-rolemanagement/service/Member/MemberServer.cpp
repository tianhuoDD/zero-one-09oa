#include"stdafx.h"
#include"service/Member/MemberServer.h"
#include"dao/Member/MemberDAO.h"
uint64_t MemberService::saveData(const MemberDTO::Wrapper& dto)
{
	// 组装DO数据
	MemberDo data;
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));

	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,Id, id);
		// 执行数据添加
	MemberDAO dao;
	return dao.insert(data);
}

bool MemberService::removeData(uint64_t id)
{
	MemberDAO dao;
	return dao.deleteById(id) == 1;
}
