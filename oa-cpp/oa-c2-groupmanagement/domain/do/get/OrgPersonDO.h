#pragma once
/*
 @Author: LemonFlavoredSoda
 @Date: 2024年 10月 23日 星期三 23:19:41 CST
*/
#ifndef _ORGPERSON_DO_
#define _ORGPERSON_DO_
#include "../../../Macros.h"

/**
 * 示例数据库实体类
 */
class OrgPersonDO
{

	// 编号
	//CC_SYNTHESIZE(uint64_t, id, Id);

	//人员标识
	CC_SYNTHESIZE(string, xid, Xid);
	CC_SYNTHESIZE(string, xcreateTime, Xcreate_time);
	CC_SYNTHESIZE(string, xsequence, Xsequence);
	CC_SYNTHESIZE(string, xupdateTime, Xupdate_time);
	CC_SYNTHESIZE(string, xdistributeFactor, Xdistribute_factor);
	CC_SYNTHESIZE(string, xage, Xage);
	CC_SYNTHESIZE(string, xandFxHash, Xand_fx_hash);
	CC_SYNTHESIZE(string, xandFxId, Xand_fx_id);
	CC_SYNTHESIZE(string, xbirthday, Xbirthday);
	CC_SYNTHESIZE(string, xboardDate, Xboard_date);
	CC_SYNTHESIZE(string, xchangePasswordTime, Xchange_password_time);
	CC_SYNTHESIZE(string, xdescription, Xdescription);
	CC_SYNTHESIZE(string, xdingdingHash, Xdingding_hash);
	CC_SYNTHESIZE(string, xdingdingId, Xdingding_id);
	CC_SYNTHESIZE(string, xdistinguishedName, Xdistinguished_name);
	CC_SYNTHESIZE(string, xemployee, Xemployee);
	CC_SYNTHESIZE(string, xfailureCount, Xfailure_count);
	CC_SYNTHESIZE(string, xfailureTime, Xfailure_time);
	CC_SYNTHESIZE(string, xgenderType, Xgender_type);
	CC_SYNTHESIZE(string, xhiddenMobile, Xhidden_mobile);
	CC_SYNTHESIZE(string, xicon, Xicon);
	CC_SYNTHESIZE(string, xiconLdpi, Xicon_ldpi);
	CC_SYNTHESIZE(string, xiconMdpi, Xicon_mdpi);
	CC_SYNTHESIZE(string, xipAddress, Xip_address);
	CC_SYNTHESIZE(string, xlastLoginAddress, Xlast_login_address);
	CC_SYNTHESIZE(string, xlastLoginClient, Xlast_login_client);
	CC_SYNTHESIZE(string, xlastLoginTime, Xlast_login_time);
	CC_SYNTHESIZE(string, xlockTime, Xlock_time);
	CC_SYNTHESIZE(string, xmail, Xmail);
	//电话号码
	CC_SYNTHESIZE(string, xmobile, Xmobile);
	CC_SYNTHESIZE(string, xmpwxopenId, Xmpwxopen_id);
	//人员名称
	CC_SYNTHESIZE(string, xname, Xname);
	CC_SYNTHESIZE(string, xnickName, Xnick_name);
	CC_SYNTHESIZE(string, xofficePhone, Xoffice_phone);
	CC_SYNTHESIZE(string, xopen1Id, Xopen1_id);
	CC_SYNTHESIZE(string, xopen2Id, Xopen2_id);
	CC_SYNTHESIZE(string, xopen3Id, Xopen3_id);
	CC_SYNTHESIZE(string, xopen4Id, Xopen4_id);
	CC_SYNTHESIZE(string, xopen5Id, Xopen5_id);
	CC_SYNTHESIZE(string, xorderNumber, Xorder_number);
	CC_SYNTHESIZE(string, xpasswordExpiredTime, Xpassword_expired_time);
	CC_SYNTHESIZE(string, xpinyin, Xpinyin);
	CC_SYNTHESIZE(string, xpinyinInitial, Xpinyin_initial);
	CC_SYNTHESIZE(string, xqiyeweixinHash, Xqiyeweixin_hash);
	CC_SYNTHESIZE(string, xqiyeweixinId, Xqiyeweixin_id);
	CC_SYNTHESIZE(string, xqq, Xqq);							
	CC_SYNTHESIZE(string, xsignature, Xsignature);
	CC_SYNTHESIZE(string, xstatus, Xstatus);
	CC_SYNTHESIZE(string, xstatusDes, Xstatus_des);
	CC_SYNTHESIZE(string, xsubjectSecurityClearance, Xsubject_security_clearance);
	CC_SYNTHESIZE(string, xsuperior, Xsuperior);
	CC_SYNTHESIZE(string, xunique, Xunique);
	CC_SYNTHESIZE(string, xweLinkHash, Xwe_link_hash);
	CC_SYNTHESIZE(string, xweLinkId, Xwe_link_id);
	CC_SYNTHESIZE(string, xweixin, Xweixin);
	CC_SYNTHESIZE(string, xzhengwuDingdingHash, Xzhengwu_dingding_hash);
	CC_SYNTHESIZE(string, xzhengwuDingdingId, Xzhengwu_dingding_id);
	
public:
	/*OrgPersonDO() {
		
	}*/
};

#endif // !_ORGPERSON_DO_
