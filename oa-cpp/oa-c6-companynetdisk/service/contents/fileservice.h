#pragma once

#ifndef _SAMPLE_SERVICE_
#define _SAMPLE_SERVICE_
#include <list>
#include "domain/vo/remove/DdeleteVO.h"
//#include "domain/query/sample/SampleQuery.h"
#include "domain/dto/remove/DdeleteDTO.h"
//#include "../../service/contents/contentsservice.h"
/**
 * 示例服务实现，演示基础的示例服务实现
 */
class FileService
{
public:
	// 重命名目录和文件
	bool updateContents(const DdeleteDTO::Wrapper& dto);

};

#endif // !_SAMPLE_SERVICE_