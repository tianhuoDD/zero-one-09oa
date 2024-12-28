#pragma once

#ifndef _UPLOADATTACHMENT_DO_
#define _UPLOADATTACHMENT_DO_
#include "../../DoInclude.h"

/**
 * 会议文件表数据库实体类
 */
class UploadAttachmentDO
{
	// 文件编号
	CC_SYNTHESIZE(string, xid, Xid);
	// 文件创建时间
	CC_SYNTHESIZE(string, xcreateTime, XcreateTime);
	// 序列号
	CC_SYNTHESIZE(string, xsequence, Xsequence);
	// 文件更新时间
	CC_SYNTHESIZE(string, xupdateTime, XupdateTime);
	// 文件所在深度
	CC_SYNTHESIZE(int, xdeepPath, XdeepPath);
	// 文件扩展名，如pdf
	CC_SYNTHESIZE(string, xextension, Xextension);
	// 最后执行更新文件的用户
	CC_SYNTHESIZE(string, xlastUpdatePerson, XlastUpdatePerson);
	// 文件最近更新时间
	CC_SYNTHESIZE(string, xlastUpdateTime, XlastUpdateTime);
	// 文件大小
	CC_SYNTHESIZE(long, xlength, Xlength);
	// 会议ID
	CC_SYNTHESIZE(string, xmeeting, Xmeeting);
	// 文件名称
	CC_SYNTHESIZE(string, xname, Xname);
	// 文件存储路径 在FastDFS
	CC_SYNTHESIZE(string, xstorage, Xstorage);
	// 标记是否是会议摘要
	CC_SYNTHESIZE(bool, xsummary, Xsummary);
public:
	UploadAttachmentDO() {
		xid = "";
		xcreateTime = "";
		xsequence = "";
		xupdateTime = "";
		xdeepPath = 0;
		xextension = "";
		xlastUpdatePerson = "";
		xlength = 0;
		xmeeting = "";
		xname = "";
		xstorage = "";
		xsummary = false;	
	}
};

#endif // !_UPLOADATTACHMENT_DO_
