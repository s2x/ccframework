/*
 * ccRole.h
 *
 *  Created on: 25-09-2013
 *      Author: piotr
 */

#ifndef CCROLE_H_
#define CCROLE_H_
#include <iostream>

namespace ccFramework {

class ccRole {
	std::string name;
	ccRole *parent;
public:
	ccRole(std::string name, ccRole *parent = NULL);
	virtual ~ccRole();
	ccRole* getParent();
	void setParent(ccRole* parent);
	std::string getName();
};

} /* namespace ccFramework */
#endif /* CCROLE_H_ */
