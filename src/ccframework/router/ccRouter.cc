/*
 * ccRoute.cpp
 *
 *  Created on: 30-07-2013
 *      Author: piotr
 */

#include "ccframework/ccFramework.h"

namespace ccFramework {

ccRouter::ccRouter() {
	// TODO Auto-generated constructor stub

}

ccRouter::~ccRouter() {
	// TODO Auto-generated destructor stub
		while (this->routes.size()) {
                delete (*this->routes.begin());
                this->routes.erase(this->routes.begin());

        };

}

ccRoute *ccRouter::getRoute(ccRequest *request) {
	std::cerr<<"Checking for: "<<request->getEnvParamter("REQUEST_URI")<<std::endl;

	for (std::vector<ccRoute *>::iterator it = this->routes.begin();
			it != this->routes.end(); ++it) {
		std::cerr<<"Checking route: "<<(*it)->getName()<<std::endl;
		if ((*it)->match(request)) {
			std::cerr<<"Route matched: "<<(*it)->getName()<<std::endl;
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

} /* namespace ccFramework */


