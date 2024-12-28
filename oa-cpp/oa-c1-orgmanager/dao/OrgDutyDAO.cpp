#include "OrgDutyDAO.h"
#include "../service/OrgDutyService.h"

string OrgDutyDAO::insert(const OrgDutyDO& iObj)
{
    // 1.================================================================xid
    SnowFlake sf(1, 1);  //  雪花算法生成随机xid
    uint64_t id = sf.nextId();
    stringstream str;
    str << id;
    string xid = str.str();

    // 2.================================================================xcreateTime
    auto now = std::chrono::system_clock::now();
    std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);
    std::tm now_tm = *std::localtime(&now_time_t);
    stringstream ct;
    ct << std::put_time(&now_tm, "%Y-%m-%d %H:%M:%S"); // 当前时间
    string xcreateTime = ct.str();

    // 3.================================================================xsequence
    stringstream se;
    se << std::put_time(&now_tm, "%Y%m%d%H%M%S") << xid;
    string xsequence = se.str();

    // 4.================================================================xupdateTime
    string xupdateTime = xcreateTime;

    // 5.================================================================xdistributeFactor
    int xdistributeFactor = 0;

    // 6.================================================================xdistinguishedName
    stringstream dis; 
    dis << (string)(iObj.getXname()) << "@" << xid << "@UD";
    string xdistinguishedName = dis.str();

    // 7.================================================================xorderNumber
    std::random_device rd; // 随机数设备，用于获取种子
    std::mt19937 gen(rd()); // 以随机设备生成的种子初始化Mersenne Twister生成器
    std::uniform_int_distribution<> dist(200000000, 300000000); // 定义分布范围
    int xorderNumber = dist(gen);
#if 0
    // 8.================================================================xpinyin
    uint32_t bufLen;
    auto xname = iObj.getXname();
    char pinyinBuf[128] = { 0 };
    getPinyin(xname.c_str(), pinyinBuf, 128, &bufLen, enmPinyinMode_AllLower); //获取汉字拼音并且全小写
    string xpinyin = pinyinBuf;

    // 9.================================================================xpinyinInitial
    char pinyinBufInit[128] = { 0 };
    getPinyin(xname.c_str(), pinyinBufInit, 128, &bufLen, enmPinyinMode_FirstUpper);  //首字母大写
    string xpinyinInitial;
    for (auto c : pinyinBufInit)
    {
        if (c >= 'A' && c <= 'Z')
        {
            xpinyinInitial.push_back(c + 32);  //如果为大写则转换成小写加入数组中
        }
    }
#endif
    // 10.================================================================xuinique
    string xunique = xid;

    // 11.================================================================xunit
    string xunit = "76bc9bc2-b2d6-4d74-bfb3-5599ce4d6743";


    string sql = "INSERT INTO `org_unitduty` ("
        "`xid`, `xcreateTime`, `xsequence`, `xupdateTime`, "
        "`xdescription`, `xdistinguishedName`, `xname`, `xorderNumber`, `xpinyin`, "
        "`xpinyinInitial`, `xunique`, `xunit`"
        ") VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";

    string formatInsert = "%s%s%s%s%s%s%s%i%s%s%s%s";

    sqlSession->executeInsert(sql.c_str(), formatInsert.c_str(),
        xid,
        xcreateTime,
        xsequence,
        xupdateTime, 
        iObj.getXdescription(),
        xdistinguishedName,
        iObj.getXname(),
        xorderNumber,
        iObj.getXpinyin(),
        iObj.getXpinyinInitial(),
        xunique,
        xunit);

    return xid;
}

int OrgDutyDAO::update(const OrgDutyDO& uObj)
{

    // updateTime
    auto now = std::chrono::system_clock::now();
    std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);
    std::tm now_tm = *std::localtime(&now_time_t);
    stringstream ut;
    ut << std::put_time(&now_tm, "%Y-%m-%d %H:%M:%S"); // 当前时间
    string xupdateTime = ut.str();

    stringstream dis;
    dis << (string)(uObj.getXname()) << "@" << (string)uObj.getXid() << "@UD";
    string xdistinguishedName = dis.str();

    string sql = "UPDATE `org_unitduty` SET \
        `xname`=?, `xdescription`=?,\
        `xupdateTime`=?, `xpinyin`=?, \
        `xpinyinInitial`=?, `xdistinguishedName`=? \
        WHERE `xid`=?";
    string formatUpdate = "%s%s%s%s%s%s%s";
    return sqlSession->executeUpdate(sql, formatUpdate.c_str(), \
        uObj.getXname(), uObj.getXdescription(), \
        xupdateTime, uObj.getXpinyin(), \
        uObj.getXpinyinInitial(), xdistinguishedName, \
        uObj.getXid());
}
