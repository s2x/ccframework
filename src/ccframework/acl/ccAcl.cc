/*
 * ccAcl.cpp
 *
 *  Created on: 25-09-2013
 *      Author: piotr
 */

#include "../../include/ccframework/ccFramework.h"

namespace ccFramework {

ccAcl::ccAcl() {
	// TODO Auto-generated constructor stub

}

ccAcl::~ccAcl() {
	// TODO Auto-generated destructor stub
}

void ccAcl::addRole(std::string name, std::string parent) {
	if (!this->hasRole("name")) {
		ccRole *tmp = new ccRole(name);
		this->roles.push_back(tmp);
		if (this->hasRole(parent)) {
			tmp->setParent(this->getRole(parent));
		}
	}
}

ccRole* ccAcl::getRole(std::string name) {
	for (int i=0; i<this->roles.size(); i++) {
		if (this->roles[i]->getName() == name) this->roles[i];
	}
	return NULL;
}

bool ccAcl::hasRole(std::string name) {
	for (int i=0; i<this->roles.size(); i++) {
		if (this->roles[i]->getName() == name) return true;
	}
	return false;
}

} /* namespace ccFramework */
