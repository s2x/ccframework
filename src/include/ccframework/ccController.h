/*
 * ccController.h
 *
 *  Created on: 30-07-2013
 *      Author: piotr
 */

#ifndef CCCONTROLLER_H_
#define CCCONTROLLER_H_

#include "ccApp.h"
#include "ccResponse.h"
#include "ccRequest.h"
#include <iostream>
#include "ccException.h"
#include "ccRoute.h"
namespace ccFramework {

class ccController {
protected:
	ccApp *app;
public:
	ccResponse *forward(std::string route_name, ccRequest *request);
	ccController(ccApp *app);
	virtual ~ccController();
    ccResponse *__errorAction(ccRequest *request, ccException e);
    ccRouter *getRouter();
    ccResponse *redirect(std::string url, std::string code = "302");
	virtual void registerRoutes();
	virtual void initController();
	
	std::string genUrl(std::string route_name);
	std::string genUrl(std::string route_name, std::map<std::string, std::string> params);
};

} /* namespace ccFramework */
#endif /* CCCONTROLLER_H_ */
