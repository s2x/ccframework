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
	static ccApp *instance;
	ccController *default_countroller;
	ccRequest *request;
	ccRouter *router;
	ccAcl *acl;
	static ccConfigLoader *config;
	bool loadConfig(std::string config_file);

	std::streambuf * cin_streambuf;
	std::streambuf * cout_streambuf;
	std::streambuf * cerr_streambuf;

public:

	ccApp(std::string config_file);
	virtual ~ccApp();

	static std::string getConfigValue(std::string name);
	static std::string getConfigValue(std::string name, std::string value);


	//helpers
	static std::string genUrl(std::string route_name, std::string query_string);
	static std::string genUrl(std::string route_name, std::map<std::string, std::string> params);
	static std::string getActiveRouteName();

	virtual void init() {};
	void run();
	ccRouter *getRouter() {
		return this->router;
	}

	ccResponse *processRequest(FCGX_Request fcgi_request);

	static ccApp *getInstance(){
		return instance;
	}

	ccRequest *getRequest();
	ccAcl* getAcl();
	static  ccConfigLoader* getConfig();
};

} /* namespace ccFramework */
#endif /* CCAPP_H_ */
