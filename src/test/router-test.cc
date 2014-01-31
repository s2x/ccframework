/*
 * router-test.cc
 *
 *  Created on: 22-10-2013
 *      Author: piotr
 */


#include <iostream>
#include "../include/ccframework/ccFramework.h"

using namespace ccFramework;

void Test1() {
	ccRoute *tmp = new ccRoute("test","/test_route/{:test_param1}/{:test_param2}", NULL);
	try {
		std::cout<<tmp->getUrl({std::make_pair("test_param1","test"),std::make_pair("test_param2","test")
		,std::make_pair("shit","test&dupa")
		,std::make_pair("chuj","test ze spacja")
		,std::make_pair("dupa","test żółć")})<<std::endl;
	} catch (ccException &e) {
		std::cout<<"Error: "<<e.getCode()<<", message: "<<e.getMessage()<<std::endl;
	}
	delete tmp;
}

int main() {
	Test1();
	return 0;
}
