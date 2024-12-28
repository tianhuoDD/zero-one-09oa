/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:13:11

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "NewService.h"
#include "../../dao/NEW/NewDAO.h"

NewDTO::Wrapper NewService::listAll(string id)
{
	// 构建返回对象
	auto re = NewDTO::createShared();
	
	NewDAO dao;
	list<NewDO> result = dao.selectById(id);

	
	NewDO sub = result.front();

	
	re->xappicon = sub.getxappIcon(); re->xappName = sub.getxappName(); re->xappAlias = sub.getxappAlias(); re->xdescription = sub.getxdescription(); re->xsequence = sub.getxsequence(); re->xdocumentType = sub.getxdocumentType(); re->ignore1 = sub.getignore1(); re->timed = sub.gettimed(); re->xappType = sub.getxappType(); re->xshowAllDocuments = sub.getxshowAlldocuments(); re->autosave = sub.getautosave(); re->xdefaultEditForm = sub.getxdefaultEditForm(); re->xdefaultReadForm = sub.getxdefaultReadForm();
	
	return re;
}
