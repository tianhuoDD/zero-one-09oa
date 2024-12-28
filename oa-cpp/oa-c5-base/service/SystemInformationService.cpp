#include "SystemInformationService.h"

SystemInformationDTO::Wrapper SystemInformationService::listAll(const std::string& name)
{
	auto message = SystemInformationDTO::createShared();
	
	SystemInformationDAO dao;
	SystemInformationDO do_ = dao.select(name);

	message->systeminformaton = do_.getinformation();
	//message->systeminformaton = dao.selectdd(name);

	return message;
}
