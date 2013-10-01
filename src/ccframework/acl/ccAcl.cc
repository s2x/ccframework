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

void ccAcl::addResource(std::string name, std::string parent) {
	if (!this->hasResource("name")) {
		ccResource *tmp = new ccResource(name);
		this->resources.push_back(tmp);
		if (this->hasResource(parent)) {
			tmp->setParent(this->getResource(parent));
		}
	}
}

ccResource* ccAcl::getResource(std::string name) {
	for (int i=0; i<this->resources.size(); i++) {
		if (this->resources[i]->getName() == name) this->resources[i];
	}
	return NULL;
}

bool ccAcl::isAllowAll(){
	return allow_all;
}

void ccAcl::setAllowAll(bool allowAll) {
	this->allow_all = allowAll;
}

bool ccAcl::hasResource(std::string name) {
	for (int i=0; i<this->resources.size(); i++) {
		if (this->resources[i]->getName() == name) return true;
	}
	return false;
}

bool ccAcl::isAllowed(std::string role, std::string resource) {
	if (this->isAllowAll()) {
		//looking only for deny entry

		return true;
	}

	return false;
}

} /* namespace ccFramework */


