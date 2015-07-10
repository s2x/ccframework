#include "../include/ccframework/ccFramework.h"
#include <pcre.h>
#include <ccArray.h>

using namespace ccFramework;

int main() {
    ccArray nodes;
    std::string request_string = "test1[test2][test3]";
    std::vector<std::string> items = ccCommon::array_elements(request_string);
    std::cout << "Test string: " << request_string << std::endl;
    for (std::vector<std::string>::iterator it = items.begin(); it != items.end(); ++it)
        std::cout << "\t*" << *it << "\n";


    request_string = "test1[test1]";
    ccCommon::set_array_element_by_path(&nodes,request_string,"test_val1");
    request_string = "test1[test2]";
    ccCommon::set_array_element_by_path(&nodes,request_string,"test_val2");

    std::cout<<"Test val: "<<nodes["test1"]["test2"]<<std::endl;
    std::cout<<"Test val: "<<nodes["test1"]["test1"]<<std::endl;

    return 0;
}
