#include "ExportController.h"
#include "../../../dao/downexcel/DownExcelDAO.h"


bool ExportController::check_permission(std::list<std::string> authorities)
{
    bool flag = false;
    for (auto role : authorities)
        if (role == "PersonManager")
            flag = true;

    return flag;
}

oatpp::String ExportController::get_excel_binary()
{
    // 创建 Excel 文件的结构并写入内容
    ExcelComponent excel;

    DownExcelDAO down;
    std::pair<std::string, std::vector<std::vector<std::string>>> sheet;
    std::string& sheetname = sheet.first;
    std::vector<std::vector<std::string>>& data = sheet.second;

    sheet = down.get_sheet1();
    excel.writeVectorToBuff(sheetname, data);
    sheet = down.get_sheet2();
    excel.writeVectorToBuff(sheetname, data);
    sheet = down.get_sheet3();
    excel.writeVectorToBuff(sheetname, data);
    sheet = down.get_sheet4();
    excel.writeVectorToBuff(sheetname, data);
    sheet = down.get_sheet5();
    excel.writeVectorToBuff(sheetname, data);
    sheet = down.get_sheet6();
    std::vector<std::uint8_t> body = excel.writeVectorToBuff(sheetname, data);

    // 将生成的 xlsx 内容作为 Body 返回
    auto bodyStr = oatpp::String(reinterpret_cast<const char*>(body.data()), body.size());

    return bodyStr;
}

