#include "../include/ccframework/ccFramework.h"
#include <pcre.h>

using namespace ccFramework;


int main() {
	std::string request_string = "test[fuckmej][2]";
	ccCommon::array_elements(request_string);
	return 0;
}
