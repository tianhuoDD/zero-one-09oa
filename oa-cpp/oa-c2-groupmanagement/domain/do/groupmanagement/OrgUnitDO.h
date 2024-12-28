//
// Created by asd on 2024/10/26.
//

#ifndef ORGUNITDO_H
#define ORGUNITDO_H

#include <Macros.h>

class OrgUnitDO {
	CC_SYNTHESIZE(std::string, unitId, xid);
	CC_SYNTHESIZE(std::string, createTime, xcreateTime);
	CC_SYNTHESIZE(std::string, sequence, xsequence);
	CC_SYNTHESIZE(std::string, updateTime, xupdateTime);
	CC_SYNTHESIZE(int, distributeFactor, xdistributeFactor );
	CC_SYNTHESIZE(std::string, xandFxHash, xandFxHash);
	CC_SYNTHESIZE(std::string, xandFxId, xandFxId);
	CC_SYNTHESIZE(std::string, description, xdescription);
	CC_SYNTHESIZE(std::string, dingdingHash, xdingdingHash);
	CC_SYNTHESIZE(std::string, dingdingId, xdingdingId);
	CC_SYNTHESIZE(std::string, distinguishedName, xdistinguishedName);
	CC_SYNTHESIZE(int, level, xlevel);
	CC_SYNTHESIZE(std::string, levelName, xlevelName);
	CC_SYNTHESIZE(std::string, levelOrderNumber, xlevelOrderNumber);
	CC_SYNTHESIZE(std::string, name, xname);
	CC_SYNTHESIZE(int, orderNumber, xorderNumber);
	CC_SYNTHESIZE(std::string, pinyin, xpinyin);
	CC_SYNTHESIZE(std::string, pinyinInitial, xpinyinInitial);
	CC_SYNTHESIZE(std::string, qiyeweixinHash, xqiyeweixinHash);
	CC_SYNTHESIZE(std::string, qiyeweixinId, xqiyeweixinId);
	CC_SYNTHESIZE(std::string, shortName, xshortName);
	CC_SYNTHESIZE(std::string, superior, xsuperior);
	CC_SYNTHESIZE(std::string, unique, xunique);
	CC_SYNTHESIZE(std::string, weLinkHash, xweLinkHash);
	CC_SYNTHESIZE(std::string, weLinkId, xweLinkId);
	CC_SYNTHESIZE(std::string, zhengwuDingdingHash, xzhengwuDingdingHash);
	CC_SYNTHESIZE(std::string, zhengwuDingdingId, xzhengwuDingdingId);

	OrgUnitDO() {
		unitId = "";
		createTime = "";
		sequence = "";
		updateTime = "";
		distributeFactor = -1;
		xandFxHash = "";
		xandFxId = "";
		description = "";
		dingdingHash = "";
		dingdingId = "";
		distinguishedName = "";
		level = -1;
		levelName = "";
		levelOrderNumber = "";
		name = "";
		orderNumber = -1;
		pinyin = "";
		pinyinInitial = "";
		qiyeweixinHash = "";
		qiyeweixinId = "";
		shortName = "";
		unique = "";
		weLinkHash = "";
		weLinkId = "";
		zhengwuDingdingHash = "";
		zhengwuDingdingId = "";
		superior = "";
	}
};

#endif //ORGUNITDO_H
