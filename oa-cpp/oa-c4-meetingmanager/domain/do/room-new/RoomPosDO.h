#pragma once
#ifndef _ROOMPOSDO_H_
#define _ROOMPOSDO_H_
#include "../DoInclude.h"


class RoomPosDO {
	CC_SYNTHESIZE(string, xid, Id);
	CC_SYNTHESIZE(string, name, Name);
	CC_SYNTHESIZE(string, location,Location);
	CC_SYNTHESIZE(string,floor,Floor);
	CC_SYNTHESIZE(string,pnum,Pnum);
	CC_SYNTHESIZE(string, rnum,Rnum );
	CC_SYNTHESIZE(string, num,Num );
	CC_SYNTHESIZE(string, device,Device );
	CC_SYNTHESIZE(string, status,Status );
public:
	RoomPosDO() {
		xid = "";
		name = "";
		location = "";
		pnum = "";
		rnum = "";
		num = "";
		device = "";
		status = "";
	}
};

class RoomBuildingDO {
	CC_SYNTHESIZE(string, xid, Xid);
	CC_SYNTHESIZE(string, xcreateTime,XcreateTime);
	CC_SYNTHESIZE(string, xsequence, Xsequence);
	CC_SYNTHESIZE(string, xupdateTime, XupdateTime);
	CC_SYNTHESIZE(uint64_t, xdistributeFactor, XdistributeFactor);
	CC_SYNTHESIZE(string, xaddress, Xaddress);
	CC_SYNTHESIZE(string, xname, Xname);
	CC_SYNTHESIZE(string, xpinyin, Xpinyin);
	CC_SYNTHESIZE(string, xpinyinintial, Xpinyinintial);
public:
	RoomBuildingDO() : xid(""), xname(""),xpinyin(""),xpinyinintial(""),xcreateTime(""),xsequence(""),xupdateTime(""),xaddress("")
	{}
};


#endif