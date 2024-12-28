

#include "UpExcelDAO.h"
#include <string>
#include "../../domain/do/personimport/SheetDO.h"



//std::string init_pwd(const std::string& phone) {
//	// 检查手机号是否有效
//	if (phone.length() != 11) {
//		throw std::invalid_argument("手机号长度应为11位");
//	}
//
//	// 提取后六位
//	std::string last_six = phone.substr(5, 6);
//
//	// 生成11位密码（简单示例：在后六位前加一些字符）
//	std::string password = "P@ssw" + last_six;  // 可以根据需要自定义生成逻辑
//
//	// 使用 bcrypt 进行哈希
//	std::string hashed_pwd = BCrypt::generateHash(password);
//
//	return hashed_pwd;
//}

int UpExcelDAO::FindSuperior(string p_orgunique)
{
	int i = 0;
	int n = sheet1.size();
	for (; i < n; i++)
	{
		if (sheet1[i].getOrg_uqcode() == p_orgunique)
			return i;
	}

	return -1;
}

void UpExcelDAO::init_and_insertsheet1(std::vector<std::vector<std::string>> data)
{
	int n = data.size();		// n条数据

	// 先存入内存
	SnowFlake sf(1, 1);
	for (int i = 0; i < n; i++)
	{
		std::vector<string> row = data[i];
		// 先生成xid
		string xid = to_string(sf.nextId());
		// 先保存
		Sheet1DO tmp;
		tmp.setUnit_xid(xid);
		tmp.setOrg_name(row[0]);
		tmp.setOrg_uqcode(row[1]);
		tmp.setOrg_typename(row[2]);
		tmp.setOrg_porgcode(row[3]);
		tmp.setOrg_description(row[4]);
		tmp.setOrg_sortorder(std::stoi(row[5]));

		sheet1.push_back(tmp);
	}



	// 执行插入数据库
	for (int i = 0; i < n; i++)
	{
		Sheet1DO tmp = sheet1[i];

		std::vector<std::string> fields = {
		"xid", "xcreateTime", "xsequence", "xupdateTime",\
		"xdescription", "xdistinguishedName", "xlevelname", "xlevelOrderNumber", \
		"xname", "xorderNumber", "xpinyin", "xpinyinInitial",\
		"xsuperior", "xunique"\
		};


		string xid = tmp.getUnit_xid();
		std::string time = SimpleDateTimeFormat::format();
		std::string xsequence = time + xid;
		string xupdateTime = time;

		string xdescription = tmp.getOrg_description();
		string xdistinguishedName = tmp.getOrg_name() + "@" + tmp.getOrg_uqcode() + "@" + "U";
		char level = (tmp.getOrg_name())[0];

		int xorderNumber;
		if (level == L'一')	xorderNumber = 1;
		else if (level == L'二')	xorderNumber = 2;
		else if (level == L'三')	xorderNumber = 3;
		else if (level == L'四')	xorderNumber = 4;
		else if (level == L'五') xorderNumber = 5;
		string xname = tmp.getOrg_name();


		// 一直找上级组织
		string xlevelname = xname;
		string xlevelOrderNumber = formatNumber(xorderNumber);
		int j = FindSuperior(tmp.getOrg_porgcode());
		string xsuperior = sheet1[j].getUnit_xid();
		while (j != -1)
		{
			xlevelname = sheet1[j].getOrg_name() + "/" + xlevelname;
			xlevelOrderNumber = formatNumber(sheet1[j].getOrg_sortorder()) + "/" + xlevelname;

			j = FindSuperior(sheet1[j].getOrg_porgcode());
		}

		string xunique = tmp.getOrg_uqcode();
		string xpinyin = xname;
		string xpinyinInitial = xname;


		insert("org_unit", fields, \
			xid, time, xsequence, xupdateTime, \
			xdescription, xdistinguishedName, xlevelname, xlevelOrderNumber, \
			xname, xorderNumber, xpinyin, xpinyinInitial, \
			xsuperior, xunique\
		);
	}

}

void UpExcelDAO::init_and_insertsheet2(std::vector<std::vector<std::string>> data)
{

	int n = data.size();		// n条数据
	SnowFlake sf(1, 1);
	for (int i = 0; i < n; i++)
	{
		std::vector<string> row = data[i];
		// 先生成xid
		string xid = to_string(sf.nextId());
		// 先保存
		Sheet2DO tmp;
		tmp.setPerson_xid(xid);
		tmp.setperson_name(row[0]);
		tmp.setperson_uqcode(row[1]);
		tmp.setperson_mobilenumber(row[2]);
		tmp.setperson_id(row[3]);
		tmp.setperson_officephone(row[4]);
		tmp.setperson_gender(row[5]);
		tmp.setperson_email(row[6]);

		sheet2.push_back(tmp);

		// 执行插入数据库
		std::vector<std::string> fields = {
		"xid", "xcreateTime", "xsequence", "xupdateTime",\
		"xdistinguishedName", "xemployee", "xgenderType",\
		"xmail", "xmobile", "xname", "xofficePhone",\
		"xorderNumber", "xpassword", "xpinyin",\
		"xpinyinInitial", "xstatus", "xunique"\
		};


		std::string time = SimpleDateTimeFormat::format();
		std::string xsequence = time + xid;

		string xdistinguishedName = tmp.getperson_name() + "@" + tmp.getperson_uqcode() + "@" + "P";
		string xemployee = tmp.getperson_id();
		string xgendertype = tmp.getperson_gender();

		string xmail = tmp.getperson_email();
		string xmobile = tmp.getperson_mobilenumber();
		string xname = tmp.getperson_name();
		string xofficePhone = tmp.getperson_officephone();

		int xorderNumber = sqlSession->executeQueryNumerical("SELECT UNIX_TIMESTAMP(NOW()) - UNIX_TIMESTAMP('2024-01-01 00:00:00')");
		string xpassword = "Linux";
		string xpinyin = xname;

		string xpinyinInitial = xname;
		int xstatus = 0;
		string xunique = tmp.getperson_uqcode();
		insert("org_person", fields, \
			xid, time, xsequence, time, \
			xdistinguishedName, xemployee, xgendertype, \
			xmail, xmobile, xname, xofficePhone, \
			xorderNumber, xpassword, xpinyin, \
			xpinyinInitial, xstatus, xunique
		);


	}


}
