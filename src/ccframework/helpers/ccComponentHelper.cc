/*
 * ccComponentHelper.cpp
 *
 *  Created on: 23-01-2015
 *      Author: piotr
 */

#include "ccComponentHelper.h"

namespace ccFramework {

std::map<std::string, ccResponse* (*)(std::map<std::string, std::string> params)> ccComponentHelper::components;

std::string ccComponentHelper::Modify(
		std::map<std::string, std::string> params) const {
	//check if component has name
	if (params.count("name")>0) {
		std::string name = params["name"];

		// if component exits then execute
		if (ccComponentHelper::components.count(name)) {
			return ccComponentHelper::components[name](params)->getContent();
		}
	}

	//return empty component
	return "";
}

void ccComponentHelper::registerComponent(std::string name, ccResponse* (*pointer)(std::map<std::string,std::string> params))
{
	ccComponentHelper::components[name] = pointer;
}

ccComponentHelper::ccComponentHelper() {
	// TODO Auto-generated constructor stub

}

} /* namespace ccFramework */
