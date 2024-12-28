#include "stdafx.h"
#include "UploadAttachmentDAO.h"
#include "UploadAttachmentMapper.h"
#include <sstream>

uint64_t UploadAttachmentDAO::insert(const UploadAttachmentDO& iObj)
{
	string sql = 
		"INSERT INTO `mt_attachment` (`xid`, `xcreateTime`, `xsequence`, `xupdateTime`, `xdeepPath`, `xextension`, `xlastUpdatePerson`, `xlastUpdateTime`, `xlength`, `xmeeting`, `xname`, `xstorage`, `xsummary`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	
	return sqlSession->executeUpdate(sql, "%s%s%s%s%i%s%s%s%ll%s%s%s%b", iObj.getXid(),
		iObj.getXcreateTime(), iObj.getXsequence(),iObj.getXupdateTime(), iObj.getXdeepPath(),
		iObj.getXextension(), iObj.getXlastUpdatePerson(), iObj.getXlastUpdateTime(),iObj.getXlength(),
		iObj.getXmeeting(), iObj.getXname(), iObj.getXstorage(), iObj.getXsummary());
}
