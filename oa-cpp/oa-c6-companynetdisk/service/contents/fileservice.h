#pragma once

#ifndef _SAMPLE_SERVICE_
#define _SAMPLE_SERVICE_
#include <list>
#include "domain/vo/remove/DdeleteVO.h"
//#include "domain/query/sample/SampleQuery.h"
#include "domain/dto/remove/DdeleteDTO.h"
//#include "../../service/contents/contentsservice.h"
/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class FileService
{
public:
	// ������Ŀ¼���ļ�
	bool updateContents(const DdeleteDTO::Wrapper& dto);

};

#endif // !_SAMPLE_SERVICE_