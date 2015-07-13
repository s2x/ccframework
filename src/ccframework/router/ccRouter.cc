/*
 * ccRoute.cpp
 *
 *  Created on: 30-07-2013
 *      Author: piotr
 */

#include "ccRouter.h"
#include "ccApp.h"
#include "ccRoute.h"
#include "ccQueryParser.h"
#include "ccRequest.h"
#include "ccAcl.h"
#include "ccException.h"
#include <iostream>
namespace ccFramework {

ccRouter::ccRouter() {
	// TODO Auto-generated constructor stub
	this->active_route = nullptr;
}

ccRouter::~ccRouter() {
	// TODO Auto-generated destructor stub
		while (this->routes.size()) {
                delete (*this->routes.begin());
                this->routes.erase(this->routes.begin());

        };

}

ccRoute *ccRouter::getRoute(ccRequest *request) {
	for (std::vector<ccRoute *>::iterator it = this->routes.begin();
			it != this->routes.end(); ++it) {
		if ((*it)->match(request)) {
			std::map<std::string, std::string> tmp = (*it)->getRouteParameters();
			for (std::map<std::string, std::string>::iterator itp = tmp.begin();itp != tmp.end(); ++itp) {
				request->setRequestParameter(itp->first, itp->second);
			}
			return (*it);
		}
	}
	throw ccException("404", "Page not found!");
	return NULL;
}

ccRoute* ccRouter::getRoute(std::string route_name) {
	for (std::vector<ccRoute *>::iterator it = this->routes.begin();
			it != this->routes.end(); ++it) {

		if ((*it)->getName() == route_name) {
			return (*it);
		}
	}
	return NULL;
}

void ccRouter::addRoute(ccRoute* route) {
	ccApp::getInstance()->getAcl()->addResource("__route_"+route->getName());
	this->routes.push_back(route);
}

ccRoute* ccRouter::getActiveRoute() {
	return this->active_route;
}

void ccRouter::setActiveRoute(ccRoute* activeRoute) {
	active_route = activeRoute;
}

std::string ccRouter::getActiveRouteName(){
	if (this->active_route)
		return this->active_route->getName();
	return "";
}

} /* namespace ccFramework */


