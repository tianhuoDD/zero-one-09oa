#pragma once
#ifndef _ORG_PERSONDO_
#define _ORG_PERSONDO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class org_personDO
{
	//// ��Ա����
	//CC_SYNTHESIZE(string, renyuanmingcheng, Renyuanmingcheng);
	//// �ֻ�����
	//CC_SYNTHESIZE(string, shoujihaoma, Shoujihaoma);
	//// �Ա�
	//CC_SYNTHESIZE(string, xingbie, Xingbie);
	//// ��������
	//CC_SYNTHESIZE(string, dianziyouxiang, Dianziyouxiang);
	//// qq����
	//CC_SYNTHESIZE(string, qqhaoma, Qqhaoma);
	//// ��ְʱ��
	//CC_SYNTHESIZE(string, ruzhishijian, Ruzhishijian);
	//// ��¼ip
	//CC_SYNTHESIZE(string, dengluip, Dengluip);
	////�ܼ���ʶ
	//CC_SYNTHESIZE(string, mijibiaoshi, Mijibiaoshi);
	//// Ψһ����
	//CC_SYNTHESIZE(string, weiyibianma, Weiyibianma);
	//// ��Ա����
	//CC_SYNTHESIZE(string, renyuangonghao, Renyuangonghao);
	//// �㱨����
	//CC_SYNTHESIZE(string, huibaoduixiang, Huibaoduixiang);
	//// ΢�ź�
	//CC_SYNTHESIZE(string, weixinhao, Weixinhao);
	//// �칫�绰
	//CC_SYNTHESIZE(string, bangongdianhua, Bangongdianhua);
	//// ��������
	//CC_SYNTHESIZE(string, chushengriqi, Chushengriqi);
	//// ����
	//CC_SYNTHESIZE(string, miaoshu, Miaoshu);
	//// ״̬
	//CC_SYNTHESIZE(string, zhuangtai, Zhuangtai);
	// Ψһ��ʶ��
	CC_SYNTHESIZE(string, xid, Xid);

	// ����ʱ��
	CC_SYNTHESIZE(string, xcreateTime, XcreateTime);

	// ���к�
	CC_SYNTHESIZE(string, xsequence, Xsequence);

	// ����ʱ��
	CC_SYNTHESIZE(string, xupdateTime, XupdateTime);

	// ��������
	CC_SYNTHESIZE(int, xdistributeFactor, XdistributeFactor);

	// ����
	CC_SYNTHESIZE(int, xage, Xage);

	// ������ FX ��ϣֵ
	CC_SYNTHESIZE(string, xandFxHash, XandFxHash);

	// ������ FX ID
	CC_SYNTHESIZE(string, xandFxId, XandFxId);

	// ����
	CC_SYNTHESIZE(string, xbirthday, Xbirthday);

	// ��������
	CC_SYNTHESIZE(string, xboardDate, XboardDate);

	// �޸�����ʱ��
	CC_SYNTHESIZE(string, xchangePasswordTime, XchangePasswordTime);

	// ����
	CC_SYNTHESIZE(string, xdescription, Xdescription);

	// ������ϣֵ
	CC_SYNTHESIZE(string, xdingdingHash, XdingdingHash);

	// ���� ID
	CC_SYNTHESIZE(string, xdingdingId, XdingdingId);

	// ��������
	CC_SYNTHESIZE(string, xdistinguishedName, XdistinguishedName);

	// Ա��
	CC_SYNTHESIZE(string, xemployee, Xemployee);

	// ʧ�ܼ���
	CC_SYNTHESIZE(int, xfailureCount, XfailureCount);

	// ʧ��ʱ��
	CC_SYNTHESIZE(string, xfailureTime, XfailureTime);

	// �Ա�����
	CC_SYNTHESIZE(string, xgenderType, XgenderType);

	// ���ص��ֻ�����
	CC_SYNTHESIZE(bool, xhiddenMobile, XhiddenMobile);

	// ͼ��
	CC_SYNTHESIZE(string, xicon, Xicon);

	// ���ܶ�ͼ��
	CC_SYNTHESIZE(string, xiconLdpi, XiconLdpi);

	// ���ܶ�ͼ��
	CC_SYNTHESIZE(string, xiconMdpi, XiconMdpi);

	// IP ��ַ
	CC_SYNTHESIZE(string, xipAddress, XipAddress);

	// ����
	CC_SYNTHESIZE(string, xlanguage, Xlanguage);

	// �����¼��ַ
	CC_SYNTHESIZE(string, xlastLoginAddress, XlastLoginAddress);

	// �����¼�ͻ���
	CC_SYNTHESIZE(string, xlastLoginClient, XlastLoginClient);

	// �����¼ʱ��
	CC_SYNTHESIZE(string, xlastLoginTime, XlastLoginTime);

	// ����ʱ��
	CC_SYNTHESIZE(string, xlockTime, XlockTime);

	// ����
	CC_SYNTHESIZE(string, xmail, Xmail);

	// �ֻ�����
	CC_SYNTHESIZE(string, xmobile, Xmobile);

	// ΢�ſ��� ID
	CC_SYNTHESIZE(string, xmpwxopenId, XmpwxopenId);

	// ����
	CC_SYNTHESIZE(string, xname, Xname);

	// �ǳ�
	CC_SYNTHESIZE(string, xnickName, XnickName);

	// �칫�绰
	CC_SYNTHESIZE(string, xofficePhone, XofficePhone);

	// ��һ������ ID
	CC_SYNTHESIZE(string, xopen1Id, Xopen1Id);

	// �ڶ������� ID
	CC_SYNTHESIZE(string, xopen2Id, Xopen2Id);

	// ���������� ID
	CC_SYNTHESIZE(string, xopen3Id, Xopen3Id);

	// ���ĸ����� ID
	CC_SYNTHESIZE(string, xopen4Id, Xopen4Id);

	// ��������� ID
	CC_SYNTHESIZE(string, xopen5Id, Xopen5Id);

	// ������
	CC_SYNTHESIZE(int, xorderNumber, XorderNumber);

	// ����
	CC_SYNTHESIZE(string, xpassword, Xpassword);

	// �������ʱ��
	CC_SYNTHESIZE(string, xpasswordExpiredTime, XpasswordExpiredTime);

	// ƴ��
	CC_SYNTHESIZE(string, xpinyin, Xpinyin);

	// ƴ������ĸ
	CC_SYNTHESIZE(string, xpinyinInitial, XpinyinInitial);

	// ��ҵ΢�Ź�ϣֵ
	CC_SYNTHESIZE(string, xqiyeweixinHash, XqiyeweixinHash);

	// ��ҵ΢�� ID
	CC_SYNTHESIZE(string, xqiyeweixinId, XqiyeweixinId);

	// QQ
	CC_SYNTHESIZE(string, xqq, Xqq);

	// ǩ��
	CC_SYNTHESIZE(string, xsignature, Xsignature);

	// ״̬
	CC_SYNTHESIZE(string, xstatus, Xstatus);

	// ״̬����
	CC_SYNTHESIZE(string, xstatusDes, XstatusDes);

	// ���尲ȫ���
	CC_SYNTHESIZE(int, xsubjectSecurityClearance, XsubjectSecurityClearance);

	// �ϼ�
	CC_SYNTHESIZE(string, xsuperior, Xsuperior);

	// Ψһ��
	CC_SYNTHESIZE(string, xunique, Xunique);

	// ΢���ӹ�ϣֵ
	CC_SYNTHESIZE(string, xweLinkHash, XweLinkHash);

	// ΢���� ID
	CC_SYNTHESIZE(string, xweLinkId, XweLinkId);

	// ΢��
	CC_SYNTHESIZE(string, xweixin, Xweixin);

	// ���񶤶���ϣֵ
	CC_SYNTHESIZE(string, xzhengwuDingdingHash, XzhengwuDingdingHash);

	// ���񶤶� ID
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