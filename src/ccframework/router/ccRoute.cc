/*
 * ccRoute.cpp
 *
 *  Created on: 13-08-2013
 *      Author: piotr
 */

#include "ccRoute.h"
#include "ccApp.h"
#include "ccAcl.h"
#include "ccResource.h"
#include "ccRequest.h"
#include "ccSession.h"
#include "ccRouter.h"
#include "ccException.h"
#include "ccQueryParser.h"
namespace ccFramework {

ccRoute::ccRoute(std::string name, std::string pattern,
		ccRouterFunctor* functor) {
	// TODO Auto-generated constructor stub

	this->functor = functor;
	this->name = name;
	this->pattern = pattern;
}

ccRouterFunctor* ccRoute::getFunctor() {
	return this->functor;
}

bool ccRoute::match(ccRequest *request) {
	return false;
}



std::string ccRoute::getRouteParameter(std::string name) {
	return this->getRouteParameter(name, "");
}

std::string ccRoute::getRouteParameter(std::string name,
		std::string default_value) {
	if (this->hasRouteParameter(name)) {
		return this->request_params[name];
	}
	return "";
}

bool ccRoute::hasRouteParameter(std::string name) {
	return this->request_params.count(name);
}

ccRoute::~ccRoute() {
// TODO Auto-generated destructor stub
}

ccResponse *ccRoute::Call(ccRequest* request) {
	if (ccApp::getInstance()->getAcl()->isAllowed("__route_" + this->getName(),
			request->getSession()->get("acl.user_role", ccAcl::DEFAULT_ROLE))) {
		return this->functor->Call(request);
	} else {
		throw ccException(ccException::ERROR_FORBIDDEN,
				ccException::ERROR_MSG_FORBIDDEN);
	}
	return NULL;
}

void ccRoute::setPermision(std::string role, bool allowed) {
	ccApp::getInstance()->getAcl()->addPermision("__route_" + this->getName(),
			role, allowed);

}

void ccRoute::inheritPermissions(std::string route_name) {
	ccResource *tmp = ccApp::getInstance()->getAcl()->getResource(
			"__route_" + route_name);
	ccResource *this_tmp = ccApp::getInstance()->getAcl()->getResource(
			"__route_" + this->getName());
	if (tmp && this_tmp)
		this_tmp->setParent(tmp);

}


std::string ccRoute::getUrl(std::string query_string) {
	ccQueryParser qp(query_string);
	return this->getUrl(qp.getAllParameters());
}

std::string ccRoute::getUrl(std::map<std::string, std::string> params) {
	return this->pattern;
}

std::string ccRoute::getFixedRequestUri(ccRequest* request) {
	std::string request_uri = request->getEnvParamter("REDIRECT_URL",
			request->getEnvParamter("REQUEST_URI"));
	std::string script_name = request->getEnvParamter("SCRIPT_NAME");
    
    
    if (script_name!="") {
        if (request_uri.find(script_name)==0) {
            request_uri = request_uri.substr(script_name.length());
        }
    }
    
    if (request_uri.find("/") == std::string::npos) {
        request_uri = "/"+request_uri;
    }
    
    return request_uri;
}

} /* namespace ccFramework */


