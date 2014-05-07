/*
 * ccController.h
 *
 *  Created on: 30-07-2013
 *      Author: piotr
 */

#ifndef CCCONTROLLER_H_
#define CCCONTROLLER_H_
#include <ctemplate/template.h>
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
	
	std::string genUrl(std::string route_name);
	std::string genUrl(std::string route_name, std::map<std::string, std::string> params);
};

} /* namespace ccFramework */
#endif /* CCCONTROLLER_H_ */
