/*
 * ccApp.h
 *
 *  Created on: 30-07-2013
 *      Author: piotr
 */

#ifndef CCAPP_H_
#define CCAPP_H_
#include "ccFramework.h"
#include "fcgiapp.h"

namespace ccFramework {

class ccApp {
	char **envp;
	static ccApp *instance;
	ccController *default_countroller;
	ccRequest *request;
	ccRouter *router;
	ccAcl *acl;
	static ccConfigLoader *config;
	bool loadConfig(std::string config_file);
public:
	ccApp(std::string config_file);
	~ccApp();

	static std::string getConfigValue(std::string name);
	static std::string getConfigValue(std::string name, std::string value);
	std::string getInitParam(std::string name);

	virtual void init() {};
	ccRouter *getRouter() {
		return this->router;
	}

	ccResponse *processRequest(FCGX_Request fcgi_request);

	static ccApp *getInstance(){
		return instance;
	}

	ccRequest *getRequest();
};

} /* namespace ccFramework */
#endif /* CCAPP_H_ */
