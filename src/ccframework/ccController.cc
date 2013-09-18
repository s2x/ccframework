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
	ccRouterFunctor *route = this->app->getRouter()->getRoute(route_name);
	ccResponse *ret = route->Call(request);
	return ret;
}

ccResponse* ccController::__404Action(ccRequest* request) {

	//return this->forward("test", request);
	ccTemplateResponse tpl("test_test","_404.tpl");
	tpl.setParameter("CONTENT","TestController::__404Action["+request->getRequestParameter("megatest")+"]");
    return tpl.render();
}

ccRouter* ccController::getRouter() {
	return this->app->getRouter();
}


} /* namespace ccFramework */

