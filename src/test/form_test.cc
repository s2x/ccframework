#include <ccJsonSerializer.h>
#include "../include/ccframework/ccFramework.h"

using namespace ccFramework;


int main() {

	ccArray test_data;
	test_data["dupa"]["dupa"] = "test2";
	test_data["array"][""] = "test2";
	test_data["array"][""] = "test2";
	test_data["array"][""] = "test2";
	test_data["dapa"] = "test";

	std::cout<<ccJsonSerializer::Dump(test_data)<<std::endl;

	return 0;
	//controller.genUrl("default",{}).c_str()
}
