/*
 * ccAcl.cpp
 *
 *  Created on: 25-09-2013
 *      Author: piotr
 */

#include "../../include/ccframework/ccFramework.h"

namespace ccFramework {

const std::string ccAcl::DEFAULT_ROLE = "__GUEST";

ccAcl::ccAcl() {
	this->allow_all = true;
	this->allow_first = true;
	// TODO Auto-generated constructor stub
	this->addRole(ccAcl::DEFAULT_ROLE, "");
}

ccAcl::~ccAcl() {
	// TODO Auto-generated destructor stub
}

void ccAcl::addRole(std::string name, std::string parent) {
	if (!this->hasRole(name)) {
		ccRole *tmp = new ccRole(name);
		this->roles.push_back(tmp);
		if (this->hasRole(parent)) {
			std::cerr << "Set parent: " << parent << " for role: " << name
					<< std::endl;
			tmp->setParent(this->getRole(parent));
		}
	}
}

ccRole* ccAcl::getRole(std::string name) {
	for (int i = 0; i < this->roles.size(); i++) {
		if (this->roles[i]->getName() == name)
			return this->roles[i];
	}
	return NULL;
}

bool ccAcl::hasRole(std::string name) {
	for (int i = 0; i < this->roles.size(); i++) {
		if (this->roles[i]->getName() == name)
			return true;
	}
	return false;
}

void ccAcl::addResource(std::string name, std::string parent) {
	if (!this->hasResource(name)) {
		ccResource *tmp = new ccResource(name);
		this->resources.push_back(tmp);
		if (this->hasResource(parent)) {
			tmp->setParent(this->getResource(parent));
		}
	}
}

ccResource* ccAcl::getResource(std::string name) {
	for (int i = 0; i < this->resources.size(); i++) {
		if (this->resources[i]->getName() == name)
			return this->resources[i];
	}
	return NULL;
}

bool ccAcl::isAllowAll() {
	return allow_all;
}

void ccAcl::setAllowAll(bool allowAll) {
	this->allow_all = allowAll;
}

bool ccAcl::hasResource(std::string name) {
	for (int i = 0; i < this->resources.size(); i++) {
		if (this->resources[i]->getName() == name)
			return true;
	}
	return false;
}

bool ccAcl::isAllowed(std::string resource, std::string role) {
	ccRole *tmp_role = this->getRole(role);
	ccResource *tmp_res = this->getResource(resource);

	//role or resource not found so permision denied
	if (tmp_role == NULL || tmp_res == NULL) {
		return false;
	}

	while (tmp_res != NULL) {
		tmp_role = this->getRole(role);
		while (tmp_role != NULL) {
			if (this->permisions.find(tmp_res) != this->permisions.end()) {
				if (this->permisions[tmp_res].find(tmp_role)
						!= this->permisions[tmp_res].end()) {
					return this->permisions[tmp_res][tmp_role];
				}
			}
			tmp_role = tmp_role->getParent();
		}
		tmp_res = tmp_res->getParent();
	}

	//not found in permision so is allowed
	if (this->isAllowAll()) {
		return true;
	}

	// not allowed
	return false;
}

bool ccAcl::isAllowFirst() {
	return allow_first;
}

void ccAcl::setAllowFirst(bool allowFirst) {
	allow_first = allowFirst;
}

ccAcl* ccAcl::addPermision(std::string resource, std::string role,
		bool allowed) {

	ccRole *tmp_role = this->getRole(role);
	ccResource *tmp_res = this->getResource(resource);

	if (tmp_res && tmp_role) {
		std::cerr << "add permision for resource: " << resource << ", role: "
				<< tmp_role->getName() << std::endl;
		this->permisions[tmp_res][tmp_role] = allowed;
	}
	return this;
}

} /* namespace ccFramework */

