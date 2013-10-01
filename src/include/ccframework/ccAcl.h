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
	std::vector<ccResource *> resources;
	bool allow_all = false;
public:
	ccAcl();
	virtual ~ccAcl();
	void addRole(std::string name, std::string parent="");

	ccRole *getRole(std::string name);
	bool hasRole(std::string name);


	void addResource(std::string name, std::string parent="");
	ccResource *getResource(std::string name);
	bool hasResource(std::string name);
	bool isAllowAll();
	void setAllowAll(bool allowAll = false);

	bool isAllowed(std::string role, std::string resource);
};

} /* namespace ccFramework */
#endif /* CCACL_H_ */
