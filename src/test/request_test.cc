#include "../include/ccframework/ccFramework.h"
#include <pcre.h>
using namespace ccFramework; 
int main() {
	std::string request_string = "test[fuckmej][2]";
	std::vector<std::string> items = ccCommon::array_elements(request_string);
	std::cout<<"Test string: "<<request_string<<std::endl;
	for (std::vector<std::string>::iterator it = items.begin() ; it != items.end(); ++it)
     		std::cout <<"\t*"<< *it<<"\n";
	
        request_string = "test[jebal_to_pies[test][test2]";
        items = ccCommon::array_elements(request_string);
        std::cout<<"Test string: "<<request_string<<std::endl;
        for (std::vector<std::string>::iterator it = items.begin() ; it != items.end(); ++it)
                std::cout <<"\t*"<< *it<<"\n";

return 0;
}
