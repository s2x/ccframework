/*
 * ccRouter.cpp
 *
 *  Created on: 30-07-2013
 *      Author: piotr
 */

#include "ccframework/ccFramework.h"

namespace ccFramework {

ccRouter::ccRouter() {
	this->route_matcher = new ccRouteMatcher();
	this->functors.clear();
	// TODO Auto-generated constructor stub
}

ccRouter::~ccRouter() {
	delete this->route_matcher;
	if (this->functors.size()==0) return;
	while (this->functors.size()) {
		delete this->functors.begin()->second;
		this->functors.erase(this->functors.begin());

	};
	// TODO Auto-generated destructor stub
}

void ccRouter::addRoute(std::string name, ccRouterFunctor* functor) {
	this->functors[name] = functor;
}

void ccRouter::addRoute(const std::string name, std::string pattern,
	ccRouterFunctor* functor) {
	this->functors[name] = functor;
	this->route_matcher->addRoute(new ccRoute(name, pattern));
	//new ccRoute(name, pattern, functor);

}

ccRouterFunctor* ccRouter::getRoute(std::string route_name) {
	if (this->functors.find( route_name ) != this->functors.end()) {
		return this->functors[route_name];
		this->active_route = route_name;
	}
	return this->functors["__404"];
}

ccRouterFunctor* ccRouter::getRoute(ccRequest *request) {
	this->active_route = this->route_matcher->getRoute(request);
	if (this->functors.find( this->active_route  ) != this->functors.end()) return this->functors[this->active_route ];
	return this->functors["__404"];
}

} /* namespace ccFramework */
