/*
 * ccAcl.h
 *
 *  Created on: 25-09-2013
 *      Author: piotr
 */

#ifndef CCACL_H_
#define CCACL_H_

#include "../../include/ccframework/ccFramework.h"

namespace ccFramework {

class ccAcl {
	std::vector<ccRole *> roles;
public:
	ccAcl();
	virtual ~ccAcl();
	void addRole(std::string name, std::string parent="");
	ccRole *getRole(std::string name);
	bool hasRole(std::string name);
};

} /* namespace ccFramework */
#endif /* CCACL_H_ */
