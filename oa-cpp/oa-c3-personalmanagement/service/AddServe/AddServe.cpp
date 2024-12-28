#include "AddServe.h"
#include "SnowFlake.h"
#include "bcrypt/bcrypt.h"
#include "dao/AddDao/AddDao.h"
#include "dao/DeleteDao/DeleteDao.h"

uint64_t AddServe::saveData(const PersioninfoDTO::Wrapper& dto) {
	SnowFlake sw(1, 31);
	org_personDO data;
	//data.setRenyuanmingcheng(dto->renyuanmingcheng.getValue());
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Xname, renyuanmingcheng, Xdescription, miaoshu, XipAddress,dengluip, XofficePhone,shoujihaoma);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,  Xmobile, shoujihaoma, XofficePhone, bangongdianhua, Xmail,dianziyouxiang);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Xunique, weiyibianma , XboardDate, ruzhishijian, Xemployee, renyuangonghao, Xqq,qqhaoma);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, XipAddress, dengluip, Xmail,dianziyouxiang,Xqq, qqhaoma , Xdescription,miaoshu, Xemployee,renyuangonghao);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Xsuperior,huibaoduixiang, Xweixin,weixinhao);
	//设置随机xid
	string xid = to_string(sw.nextId());
	data.setXid(xid);
	//获取创建时间
	string creatTime = getTime();
	data.setXcreateTime(creatTime);
	data.setXupdateTime(creatTime);//添加时创建时间等于更新时间
	//获取序列号
	string sequence = getSequence(creatTime, xid);
	data.setXsequence(sequence);
	//有出生日期的话
	
	if (dto->chushengriqi->size()) {
		data.setXbirthday(string(dto->chushengriqi->c_str()));
		int age = getAge(creatTime,string(dto->chushengriqi->c_str()));
		data.setXage(age);
	}
	//性别判定
	if (string(dto->xingbie->c_str()) == "m") {
		data.setXgenderType("m");
	}
	else if (string(dto->xingbie->c_str()) == "f") {
		data.setXgenderType("f");
	}
	else {
		data.setXgenderType("d");
	}
	 

	//显著名称
	string distinguishedName = string(dto->renyuanmingcheng->c_str()) + '@' + string(dto->weiyibianma->c_str());
	 
	data.setXdistinguishedName(distinguishedName);

	//// 订单号(时间戳)
	data.setXorderNumber(std::time(nullptr));

	//密码(默认手机尾号后六位）
	std::string password = string(dto->shoujihaoma).substr(5);
	std::string hash = bcrypt::generateHash(password);
	data.setXpassword(hash);

	// 上任日期
	if (string(dto->ruzhishijian->c_str()).size()) {
		data.setXboardDate(string(dto->ruzhishijian->c_str()));
	}
	// 主体安全许可(密级标识)
	string miji=string(dto->mijibiaoshi->c_str());
	if (miji.size() != 0) {
		int tmiji = 0;
		if (miji == "100")tmiji = 100;
		else if (miji == "200")tmiji = 200;
		else if (miji == "300")tmiji = 300;
		else if (miji == "400")tmiji = 400;
		data.setXsubjectSecurityClearance(tmiji);
	}
	 
	//设置拼音字段
	//获取人名的拼音
	string pinyin = string(dto->pinyin->c_str());
	//获取拼音缩写
	string suoxie= string(dto->pinyinsuoxie->c_str());
	data.setXpinyin(pinyin);
	data.setXpinyinInitial(suoxie);

	AddDao dao;
return	 dao.insert(data)==1;
	 
}

bool AddServe::removeData(string id)
{
	DeleteDao dao;
	return dao.deleteById(id) == 1;
}

string AddServe::getTime()
{
	string ans;
	// 获取当前时间
	std::time_t t = std::time(nullptr);
	// 将时间转换为本地时间
	std::tm* localTime = std::localtime(&t);
	ans += to_string(localTime->tm_year+1900);
	ans += '-';
	if (to_string(localTime->tm_mon).size() == 1) {
		ans += '0';
	}
	ans += to_string(localTime->tm_mon+1);
	ans += '-';
	if (to_string(localTime->tm_mday).size() == 1) {
		ans += '0';
	}
	ans += to_string(localTime->tm_mday );
	ans += ' ';
	if (to_string(localTime->tm_hour).size() == 1) {
		ans += '0';
	}
	ans += to_string(localTime->tm_hour);
	ans += ':';

	if (to_string(localTime->tm_min).size() == 1) {
		ans += '0';
	}
	ans += to_string(localTime->tm_min);
	ans += ':';



	if (to_string(localTime->tm_sec).size() == 1) {
		ans += '0';
	}
	ans += to_string(localTime->tm_sec);




	cout << ans;
	 
	return  ans;
}

string AddServe::getSequence(string time, string id)
{
	string ans;
	//去除符号
	for (auto i : time) {
		if (i == '-' || i == ' ' || i == ':')continue;
		ans += i;
	}
	ans += id;
	return ans;
}

int AddServe::getAge(string time, string birth)
{	
	 
	int cur = 0, bir = 0;
	for (int i = 0; i < 4; i++) {
		cur = cur * 10 + (time[i] - '0');
		bir = bir * 10 + (birth[i] - '0');
	}

	return cur-bir;
}
