#pragma once
#ifndef _SAMPLE_SERVICE_
#define _SAMPLE_SERVICE_
#include <list>
#include <string>

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class DelRoleService
{
public:

	// ͨ��IDɾ������
	bool removeData(std::string id);
};

#endif // !_SAMPLE_SERVICE_