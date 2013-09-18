/*
 * ccRouteMatcher.cpp
 *
 *  Created on: 30-07-2013
 *      Author: piotr
 */

#include "ccframework/ccFramework.h"

namespace ccFramework {

ccRouteMatcher::ccRouteMatcher() {
	// TODO Auto-generated constructor stub

}

ccRouteMatcher::~ccRouteMatcher() {
	// TODO Auto-generated destructor stub
		while (this->routes.size()) {
                delete this->routes.begin()->second;
                this->routes.erase(this->routes.begin());

        };

}

std::string ccRouteMatcher::getRoute(ccRequest *request) {
	std::string routename = request->getEnvParamter("REDIRECT__ROUTER_route");
	if (routename == "")
		routename = request->getEnvParamter("_ROUTER_route");

	for (std::map<std::string, ccRoute *>::iterator it = this->routes.begin();
			it != this->routes.end(); ++it) {

		std::string request_uri= request->getEnvParamter("REQUEST_URI");
		request_uri = request_uri.substr(0,request_uri.find_first_of("?"));

		if (it->second->match(request_uri)) {

			std::map<std::string, std::string> tmp = it->second->getRouteParameters();
			for (std::map<std::string, std::string>::iterator itp = tmp.begin();itp != tmp.end(); ++itp) {
				request->setRequestParameter(itp->first, itp->second);
			}
			return it->second->getName();
		}
	}
	if (routename == "")
		routename = "__404";
	return routename;
}

} /* namespace ccFramework */

void ccFramework::ccRouteMatcher::addRoute(ccRoute* route) {
	this->routes[route->getName()] = route;
}
