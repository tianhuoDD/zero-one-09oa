#pragma once

#ifndef  _DOWNEXCELDAO_H_
#define _DOWNEXCELDAO_H_

#include "BaseDAO.h"
#include "./SheetMapper.h"
#include "domain/GlobalInclude.h"


class DownExcelDAO : public BaseDAO
{
public:
	
	std::pair<std::string, std::vector<std::vector<std::string>>> get_sheet1();
	std::pair<std::string, std::vector<std::vector<std::string>>> get_sheet2();
	std::pair<std::string, std::vector<std::vector<std::string>>> get_sheet3();
	std::pair<std::string, std::vector<std::vector<std::string>>> get_sheet4();
	std::pair<std::string, std::vector<std::vector<std::string>>> get_sheet5();
	std::pair<std::string, std::vector<std::vector<std::string>>> get_sheet6();

};

#endif //  _UPEXCELDAO_H_
