#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:34:14

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
#ifndef _FileInfoVO_H_
#define _FileInfoVO_H_

#include "../../GlobalInclude.h"
#include "domain/dto/myfile/FileInfoDTO.h"
#include "domain/dto/folder/folderqueryDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �ļ���Ϣ��ʾ����
 */


 /**
  * ָ��Ŀ¼��ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
  */

class FileInfoPageJsonVO : public JsonVO<FolderQueryPageDTO::Wrapper> {
	DTO_INIT(FileInfoPageJsonVO, JsonVO<FolderQueryPageDTO::Wrapper>);
    // ���� success ����
    void success(FolderQueryPageDTO::Wrapper data) {
        ResultStatus resultStatus(ZH_WORDS_GETTER("Myfile.get.success"));
        this->setStatus(resultStatus);
        this->data = data;
    }
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_FileInfoVO_H_