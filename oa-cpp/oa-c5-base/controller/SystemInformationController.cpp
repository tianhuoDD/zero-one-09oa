#include "SystemInformationController.h"

SystemInformationJsonVO::Wrapper SystemInformationController::execSystemInformation(const SystemInformationQuery::Wrapper& query)
{
	SystemInformationService service;
	auto result = service.listAll(query->name);
	auto jvo = SystemInformationJsonVO::createShared();
	jvo->success(result);

	//return jvo;
	//std::cout << std::string(query->name);
	//std::cout << "\nstart\n";
	//MongoClient c("mongodb://c2:c2-123456qaq@8.148.21.89:27020/oac2");
	//using namespace bsoncxx::builder::basic;
	//c.addOne("test", make_document(kvp("name", "Mongo's Burgers")));
	//std::cout << "endl\n";
	//c.execute("oac2",[])




	return jvo;
}
