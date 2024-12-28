#pragma once
#ifndef _ORG_PERSONDO_
#define _ORG_PERSONDO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class org_personDO
{
	//// 人员名称
	//CC_SYNTHESIZE(string, renyuanmingcheng, Renyuanmingcheng);
	//// 手机号码
	//CC_SYNTHESIZE(string, shoujihaoma, Shoujihaoma);
	//// 性别
	//CC_SYNTHESIZE(string, xingbie, Xingbie);
	//// 电子邮箱
	//CC_SYNTHESIZE(string, dianziyouxiang, Dianziyouxiang);
	//// qq号码
	//CC_SYNTHESIZE(string, qqhaoma, Qqhaoma);
	//// 入职时间
	//CC_SYNTHESIZE(string, ruzhishijian, Ruzhishijian);
	//// 登录ip
	//CC_SYNTHESIZE(string, dengluip, Dengluip);
	////密集标识
	//CC_SYNTHESIZE(string, mijibiaoshi, Mijibiaoshi);
	//// 唯一编码
	//CC_SYNTHESIZE(string, weiyibianma, Weiyibianma);
	//// 人员工号
	//CC_SYNTHESIZE(string, renyuangonghao, Renyuangonghao);
	//// 汇报对象
	//CC_SYNTHESIZE(string, huibaoduixiang, Huibaoduixiang);
	//// 微信号
	//CC_SYNTHESIZE(string, weixinhao, Weixinhao);
	//// 办公电话
	//CC_SYNTHESIZE(string, bangongdianhua, Bangongdianhua);
	//// 出生日期
	//CC_SYNTHESIZE(string, chushengriqi, Chushengriqi);
	//// 描述
	//CC_SYNTHESIZE(string, miaoshu, Miaoshu);
	//// 状态
	//CC_SYNTHESIZE(string, zhuangtai, Zhuangtai);
	// 唯一标识符
	CC_SYNTHESIZE(string, xid, Xid);

	// 创建时间
	CC_SYNTHESIZE(string, xcreateTime, XcreateTime);

	// 序列号
	CC_SYNTHESIZE(string, xsequence, Xsequence);

	// 更新时间
	CC_SYNTHESIZE(string, xupdateTime, XupdateTime);

	// 分配因子
	CC_SYNTHESIZE(int, xdistributeFactor, XdistributeFactor);

	// 年龄
	CC_SYNTHESIZE(int, xage, Xage);

	// 关联的 FX 哈希值
	CC_SYNTHESIZE(string, xandFxHash, XandFxHash);

	// 关联的 FX ID
	CC_SYNTHESIZE(string, xandFxId, XandFxId);

	// 生日
	CC_SYNTHESIZE(string, xbirthday, Xbirthday);

	// 上任日期
	CC_SYNTHESIZE(string, xboardDate, XboardDate);

	// 修改密码时间
	CC_SYNTHESIZE(string, xchangePasswordTime, XchangePasswordTime);

	// 描述
	CC_SYNTHESIZE(string, xdescription, Xdescription);

	// 钉钉哈希值
	CC_SYNTHESIZE(string, xdingdingHash, XdingdingHash);

	// 钉钉 ID
	CC_SYNTHESIZE(string, xdingdingId, XdingdingId);

	// 显著名称
	CC_SYNTHESIZE(string, xdistinguishedName, XdistinguishedName);

	// 员工
	CC_SYNTHESIZE(string, xemployee, Xemployee);

	// 失败计数
	CC_SYNTHESIZE(int, xfailureCount, XfailureCount);

	// 失败时间
	CC_SYNTHESIZE(string, xfailureTime, XfailureTime);

	// 性别类型
	CC_SYNTHESIZE(string, xgenderType, XgenderType);

	// 隐藏的手机号码
	CC_SYNTHESIZE(bool, xhiddenMobile, XhiddenMobile);

	// 图标
	CC_SYNTHESIZE(string, xicon, Xicon);

	// 低密度图标
	CC_SYNTHESIZE(string, xiconLdpi, XiconLdpi);

	// 中密度图标
	CC_SYNTHESIZE(string, xiconMdpi, XiconMdpi);

	// IP 地址
	CC_SYNTHESIZE(string, xipAddress, XipAddress);

	// 语言
	CC_SYNTHESIZE(string, xlanguage, Xlanguage);

	// 最近登录地址
	CC_SYNTHESIZE(string, xlastLoginAddress, XlastLoginAddress);

	// 最近登录客户端
	CC_SYNTHESIZE(string, xlastLoginClient, XlastLoginClient);

	// 最近登录时间
	CC_SYNTHESIZE(string, xlastLoginTime, XlastLoginTime);

	// 锁定时间
	CC_SYNTHESIZE(string, xlockTime, XlockTime);

	// 邮箱
	CC_SYNTHESIZE(string, xmail, Xmail);

	// 手机号码
	CC_SYNTHESIZE(string, xmobile, Xmobile);

	// 微信开放 ID
	CC_SYNTHESIZE(string, xmpwxopenId, XmpwxopenId);

	// 姓名
	CC_SYNTHESIZE(string, xname, Xname);

	// 昵称
	CC_SYNTHESIZE(string, xnickName, XnickName);

	// 办公电话
	CC_SYNTHESIZE(string, xofficePhone, XofficePhone);

	// 第一个开放 ID
	CC_SYNTHESIZE(string, xopen1Id, Xopen1Id);

	// 第二个开放 ID
	CC_SYNTHESIZE(string, xopen2Id, Xopen2Id);

	// 第三个开放 ID
	CC_SYNTHESIZE(string, xopen3Id, Xopen3Id);

	// 第四个开放 ID
	CC_SYNTHESIZE(string, xopen4Id, Xopen4Id);

	// 第五个开放 ID
	CC_SYNTHESIZE(string, xopen5Id, Xopen5Id);

	// 订单号
	CC_SYNTHESIZE(int, xorderNumber, XorderNumber);

	// 密码
	CC_SYNTHESIZE(string, xpassword, Xpassword);

	// 密码过期时间
	CC_SYNTHESIZE(string, xpasswordExpiredTime, XpasswordExpiredTime);

	// 拼音
	CC_SYNTHESIZE(string, xpinyin, Xpinyin);

	// 拼音首字母
	CC_SYNTHESIZE(string, xpinyinInitial, XpinyinInitial);

	// 企业微信哈希值
	CC_SYNTHESIZE(string, xqiyeweixinHash, XqiyeweixinHash);

	// 企业微信 ID
	CC_SYNTHESIZE(string, xqiyeweixinId, XqiyeweixinId);

	// QQ
	CC_SYNTHESIZE(string, xqq, Xqq);

	// 签名
	CC_SYNTHESIZE(string, xsignature, Xsignature);

	// 状态
	CC_SYNTHESIZE(string, xstatus, Xstatus);

	// 状态描述
	CC_SYNTHESIZE(string, xstatusDes, XstatusDes);

	// 主体安全许可
	CC_SYNTHESIZE(int, xsubjectSecurityClearance, XsubjectSecurityClearance);

	// 上级
	CC_SYNTHESIZE(string, xsuperior, Xsuperior);

	// 唯一性
	CC_SYNTHESIZE(string, xunique, Xunique);

	// 微链接哈希值
	CC_SYNTHESIZE(string, xweLinkHash, XweLinkHash);

	// 微链接 ID
	CC_SYNTHESIZE(string, xweLinkId, XweLinkId);

	// 微信
	CC_SYNTHESIZE(string, xweixin, Xweixin);

	// 政务钉钉哈希值
	CC_SYNTHESIZE(string, xzhengwuDingdingHash, XzhengwuDingdingHash);

	// 政务钉钉 ID
	CC_SYNTHESIZE(string, xzhengwuDingdingId, XzhengwuDingdingId);


public:
	org_personDO() {
		xid = "";
		xcreateTime = "";
		xsequence = "";
		xupdateTime = "";
		xdistributeFactor = 0;
		xage = 0;
		xandFxHash = "";
		xandFxId = "";
		xbirthday = "";
		xboardDate = "";
		xchangePasswordTime = "";
		xdescription = "";
		xdingdingHash = "";
		xdingdingId = "";
		xdistinguishedName = "";
		xemployee = "";
		xfailureCount = 0;
		xfailureTime = "";
		xgenderType = "";
		xhiddenMobile = false;
		xicon = "";
		xiconLdpi = "";
		xiconMdpi = "";
		xipAddress = "";
		xlanguage = "";
		xlastLoginAddress = "";
		xlastLoginClient = "";
		xlastLoginTime = "";
		xlockTime = "";
		xmail = "";
		xmobile = "";
		xmpwxopenId = "";
		xname = "";
		xnickName = "";
		xofficePhone = "";
		xopen1Id = "";
		xopen2Id = "";
		xopen3Id = "";
		xopen4Id = "";
		xopen5Id = "";
		xorderNumber = 0;
		xpassword = "";
		xpasswordExpiredTime = "";
		xpinyin = "";
		xpinyinInitial = "";
		xqiyeweixinHash = "";
		xqiyeweixinId = "";
		xqq = "";
		xsignature = "";
		xstatus = "";
		xstatusDes = "";
		xsubjectSecurityClearance = 0;
		xsuperior = "";
		xunique = "";
		xweLinkHash = "";
		xweLinkId = "";
		xweixin = "";
		xzhengwuDingdingHash = "";
		xzhengwuDingdingId = "";
	}
};

#endif 