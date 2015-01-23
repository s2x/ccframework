/*
 * ccComponentHelper.h
 *
 *  Created on: 23-01-2015
 *      Author: piotr
 */

#ifndef CCCOMPONENTHELPER_H_
#define CCCOMPONENTHELPER_H_

#include "ccFramework.h"

namespace ccFramework {

class ccComponentHelper: public ccBaseHelper {
protected:
	static std::map<std::string, ccResponse *(*)(std::map<std::string, std::string> params)> components;
public:
	std::string Modify(std::map<std::string,std::string> params) const;
	static void registerComponent(std::string name, ccResponse *(*pointer)(std::map<std::string, std::string> params) );
	ccComponentHelper();
};

} /* namespace ccFramework */

#endif /* CCCOMPONENTHELPER_H_ */
