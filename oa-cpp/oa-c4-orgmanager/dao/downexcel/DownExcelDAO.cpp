#include "DownExcelDAO.h"

std::pair<std::string, std::vector<std::vector<std::string>>> DownExcelDAO::get_sheet1()
{
	std::pair<std::string, std::vector<std::vector<std::string>>> ret;
	ret.first = ZH_WORDS_GETTER("excel.sheetname.sheet1");

	std::vector<std::vector<std::string>>& data = ret.second;
    // 填充每一行数据
    data.push_back({ "" });
    data.push_back({ "" });
    data.push_back({ ZH_WORDS_GETTER("excel.sheet1.head") });
    data.push_back({ "" });
    data.push_back({ ZH_WORDS_GETTER("excel.sheet1.line1") });
    data.push_back({ "" });
    data.push_back({ ZH_WORDS_GETTER("excel.sheet1.line2") });
    data.push_back({ "" });
    data.push_back({ ZH_WORDS_GETTER("excel.sheet1.line3") });
    data.push_back({ "" });
    data.push_back({ ZH_WORDS_GETTER("excel.sheet1.line4") });
    data.push_back({ "" });
    data.push_back({ ZH_WORDS_GETTER("excel.sheet1.line5") });

    return ret;
}

std::pair<std::string, std::vector<std::vector<std::string>>> DownExcelDAO::get_sheet2()
{
    std::pair<std::string, std::vector<std::vector<std::string>>> ret;
    ret.first = ZH_WORDS_GETTER("excel.sheetname.sheet2");

    std::vector<std::vector<std::string>>& data = ret.second;

    // 先手工填充第一行标题列
    data.push_back({
                       ZH_WORDS_GETTER("excel.column_name.sheet1.A1"),
                       ZH_WORDS_GETTER("excel.column_name.sheet1.B1"),
                       ZH_WORDS_GETTER("excel.column_name.sheet1.C1"),
                       ZH_WORDS_GETTER("excel.column_name.sheet1.D1"),
                       ZH_WORDS_GETTER("excel.column_name.sheet1.E1"),
                       ZH_WORDS_GETTER("excel.column_name.sheet1.F1"),
        });

    // 从数据库中读取内容到data
    string sql = "SELECT \
        unit1.xname,\
        unit1.xunique,\
        typelist.xtypeList,\
        unit2.xunique,\
        unit1.xdescription,\
        unit1.xorderNumber\
        FROM\
        org_unit AS unit1\
        JOIN\
        org_unit_typelist AS typelist ON unit1.xid = typelist.UNIT_XID\
        LEFT JOIN\
        org_unit AS unit2 ON unit1.xsuperior = unit2.xid;\
    ";

    Sheet1Mapper mapper;
    list<Sheet1DO> rows = sqlSession->executeQuery<Sheet1DO, Sheet1Mapper>(sql, mapper);
    for(auto row:rows)
    {
        std::vector<std::string> tmp;
        tmp.push_back(row.getOrg_name());
        tmp.push_back(row.getOrg_uqcode());
        tmp.push_back(row.getOrg_typename());
        tmp.push_back(row.getOrg_porgcode());
        tmp.push_back(row.getOrg_description());
        tmp.push_back(row.getOrg_sortorder());

        data.push_back(tmp);
    }

    return ret;
}

std::pair<std::string, std::vector<std::vector<std::string>>> DownExcelDAO::get_sheet3()
{
    std::pair<std::string, std::vector<std::vector<std::string>>> ret;
    ret.first = ZH_WORDS_GETTER("excel.sheetname.sheet3");

    std::vector<std::vector<std::string>>& data = ret.second;

    // 先手工填充第一行标题列
    data.push_back({
                        ZH_WORDS_GETTER("excel.column_name.sheet2.A1"),
                        ZH_WORDS_GETTER("excel.column_name.sheet2.B1"),
                        ZH_WORDS_GETTER("excel.column_name.sheet2.C1"),
                        ZH_WORDS_GETTER("excel.column_name.sheet2.D1"),
                        ZH_WORDS_GETTER("excel.column_name.sheet2.E1"),
                        ZH_WORDS_GETTER("excel.column_name.sheet2.F1"),
                        ZH_WORDS_GETTER("excel.column_name.sheet2.G1")
        });

    // 从数据库中读取内容到data
    string sql = "SELECT xname, xunique, xmobile, xemployee, xofficePhone, xgenderType, xmail FROM org_person;";

    Sheet2Mapper mapper;
    list<Sheet2DO> rows = sqlSession->executeQuery<Sheet2DO, Sheet2Mapper>(sql, mapper);
    for (auto row : rows)
    {
        std::vector<std::string> tmp;
        tmp.push_back(row.getPerson_name());
        tmp.push_back(row.getPerson_uqcode());
        tmp.push_back(row.getPerson_mobilenumber());
        tmp.push_back(row.getPerson_id());
        tmp.push_back(row.getPerson_officephone());
        tmp.push_back(row.getPerson_gender());
        tmp.push_back(row.getPerson_email());

        data.push_back(tmp);
    }

    return ret;

}

std::pair<std::string, std::vector<std::vector<std::string>>> DownExcelDAO::get_sheet4()
{
    std::pair<std::string, std::vector<std::vector<std::string>>> ret;
    ret.first = ZH_WORDS_GETTER("excel.sheetname.sheet4");

    std::vector<std::vector<std::string>>& data = ret.second;

    // 先手工填充第一行标题列
    data.push_back({
                        ZH_WORDS_GETTER("excel.column_name.sheet3.A1"),
                        ZH_WORDS_GETTER("excel.column_name.sheet3.B1"),
                        ZH_WORDS_GETTER("excel.column_name.sheet3.C1"),
                        ZH_WORDS_GETTER("excel.column_name.sheet3.D1"),
        });

    // 从数据库中读取内容到data
    string sql = "SELECT\
        person.xunique, unit.xunique, identity.xunique, identity.xmajor\
        FROM\
        org_unit as unit, org_person as person, org_identity as identity\
        WHERE\
        identity.xperson = person.xid AND identity.xunit = unit.xid";

    Sheet3Mapper mapper;
    list<Sheet3DO> rows = sqlSession->executeQuery<Sheet3DO, Sheet3Mapper>(sql, mapper);
    for (auto row : rows)
    {
        std::vector<std::string> tmp;


        tmp.push_back(row.getPerson_uqcode());
        tmp.push_back(row.getOrg_uqcode());
        tmp.push_back(row.getOrg_identity());
        tmp.push_back(row.getPrimary());

        data.push_back(tmp);
    }

    return ret;

}

std::pair<std::string, std::vector<std::vector<std::string>>> DownExcelDAO::get_sheet5()
{
    std::pair<std::string, std::vector<std::vector<std::string>>> ret;
    ret.first = ZH_WORDS_GETTER("excel.sheetname.sheet5");

    std::vector<std::vector<std::string>>& data = ret.second;

    // 先手工填充第一行标题列
    data.push_back({
                        ZH_WORDS_GETTER("excel.column_name.sheet4.A1"),
                        ZH_WORDS_GETTER("excel.column_name.sheet4.B1"),
                        ZH_WORDS_GETTER("excel.column_name.sheet4.C1"),
                        ZH_WORDS_GETTER("excel.column_name.sheet4.D1"),
                        ZH_WORDS_GETTER("excel.column_name.sheet4.E1"),
                        ZH_WORDS_GETTER("excel.column_name.sheet4.F1"),
        });

    // 从数据库中读取内容到data
    string sql = "SELECT \
        unitduty.xname,\
        unit.xunique,\
        unitduty.xunique,\
        unitduty.xdescription,\
        person.xunique,\
        unit.xunique\
        FROM\
        org_unitduty AS unitduty\
        JOIN\
        org_unit AS unit ON unitduty.xunit = unit.xid\
        JOIN\
        org_unitduty_identitylist AS identityList ON unitduty.xid = identityList.UNITDUTY_XID\
        JOIN\
        org_identity AS identity ON identityList.xidentityList = identity.xid\
        JOIN\
        org_person AS person ON identity.xperson = person.xid\
        ";

    Sheet4Mapper mapper;
    list<Sheet4DO> rows = sqlSession->executeQuery<Sheet4DO, Sheet4Mapper>(sql, mapper);
    for (auto row : rows)
    {
        std::vector<std::string> tmp;


        tmp.push_back(row.getPosition_name());
        tmp.push_back(row.getPosition_org_ucode());
        tmp.push_back(row.getPosition_code());
        tmp.push_back(row.getPosition_description());
        tmp.push_back(row.getPosition_person_ucode());
        tmp.push_back(row.getPerson_and_org_ucode_in_position());

        data.push_back(tmp);
    }

    return ret;
}

std::pair<std::string, std::vector<std::vector<std::string>>> DownExcelDAO::get_sheet6()
{
    std::pair<std::string, std::vector<std::vector<std::string>>> ret;
    ret.first = ZH_WORDS_GETTER("excel.sheetname.sheet6");

    std::vector<std::vector<std::string>>& data = ret.second;

    // 先手工填充第一行标题列
    data.push_back({
                        ZH_WORDS_GETTER("excel.column_name.sheet5.A1"),
                        ZH_WORDS_GETTER("excel.column_name.sheet5.B1"),
                        ZH_WORDS_GETTER("excel.column_name.sheet5.C1"),
                        ZH_WORDS_GETTER("excel.column_name.sheet5.D1"),
                        ZH_WORDS_GETTER("excel.column_name.sheet5.E1"),
                        ZH_WORDS_GETTER("excel.column_name.sheet5.F1"),
                        ZH_WORDS_GETTER("excel.column_name.sheet5.G1"),
        });

    // 从数据库中读取内容到data
    string sql = "SELECT\
        org_group.xname,\
        org_group.xunique,\
        person.xunique,\
        identity.xunique,\
        unit.xunique,\
        org_group1.xunique,\
        org_group.xdescription\
        FROM	org_group\
        LEFT JOIN org_group_personlist ON org_group.xid = org_group_personlist.GROUP_XID\
        LEFT JOIN org_person as person ON org_group_personlist.xpersonList = person.xid\
        LEFT JOIN org_group_identitylist ON org_group.xid = org_group_identitylist.GROUP_XID\
        LEFT JOIN org_identity as identity ON org_group_identitylist.xidentityList = identity.xid\
        LEFT JOIN org_group_unitlist ON org_group.xid = org_group_unitlist.GROUP_XID\
        LEFT JOIN org_unit as unit ON org_group_unitlist.xunitList = unit.xid\
        LEFT JOIN org_group_grouplist ON org_group.xid = org_group_grouplist.GROUP_XID\
        LEFT JOIN org_group as org_group1 ON org_group_grouplist.xgroupList = org_group1.xid\
        ";

    Sheet5Mapper mapper;
    list<Sheet5DO> rows = sqlSession->executeQuery<Sheet5DO, Sheet5Mapper>(sql, mapper);
    for (auto row : rows)
    {
        std::vector<std::string> tmp;


        tmp.push_back(row.getGroup_name());
        tmp.push_back(row.getGroup_code());
        tmp.push_back(row.getPerson_uqcode());
        tmp.push_back(row.getOrg_identity());
        tmp.push_back(row.getOrg_uqcode());
        tmp.push_back(row.getSubgroup_code());
        tmp.push_back(row.getGroup_description());

        data.push_back(tmp);
    }

    return ret;
}


