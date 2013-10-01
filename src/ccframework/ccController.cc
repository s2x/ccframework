/*
 * ccController.cpp
 *
 *  Created on: 30-07-2013
 *      Author: piotr
 */

#include "ccframework/ccFramework.h"

namespace ccFramework {

ccController::ccController(ccApp *app) {
	// TODO Auto-generated constructor stub
	this->app = app;
}

ccController::~ccController() {
	// TODO Auto-generated destructor stub
}


ccResponse *ccController::forward(std::string route_name, ccRequest *request) {
	ccRoute *route = this->app->getRouter()->getRoute(route_name);
	this->app->getRouter()->setActiveRoute(route);
	ccResponse *ret = route->Call(request);
	return ret;
}

ccResponse* ccController::__errorAction(ccRequest* request, ccException e) {
	ccTemplateResponse tpl("__error","_error.tpl");
	tpl.setParameter("ERROR_NUMBER", e.getCode());
	tpl.setParameter("ERROR_MSG", e.getMessage());
	ccResponse *ret = tpl.render();
	ret->setHeader("Status",e.getCode());
    return ret;
}

ccRouter* ccController::getRouter() {
	return this->app->getRouter();
}


} /* namespace ccFramework */

