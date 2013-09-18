/*
 * ccApp.cpp
 *
 *  Created on: 30-07-2013
 *      Author: piotr
 */

#include "ccframework/ccFramework.h"

namespace ccFramework {

ccApp *ccApp::instance = NULL;
ccConfigLoader *ccApp::config = NULL;

ccApp::ccApp(char **env) {
	this->envp = env;
	this->loadConfig(this->getInitParam("CCF_CONFIG_FILE"));
	ctemplate::mutable_default_template_cache()->SetTemplateRootDirectory(this->config->getConfigValue("template_dir",""));
	this->router = new ccRouter();
	this->default_countroller = new ccController(this);
	this->getRouter()->addRoute("__404",
			new ccSpecificRouterFunctor<ccController>(this->default_countroller,
					&ccController::__404Action));
	instance = this;
}
ccApp::~ccApp() {
	// TODO Auto-generated destructor stub

	delete this->router;
	delete this->default_countroller;
	delete this->config;
}

ccResponse *ccApp::processRequest(FCGX_Request fcgi_request) {
	ctemplate::mutable_default_template_cache()->ReloadAllIfChanged(
			ctemplate::TemplateCache::IMMEDIATE_RELOAD);
	ccRequest *request = new ccRequest(fcgi_request);

	// autostart session
	if (this->getConfigValue("session.autostart", "0") == "1") {
		request->setSession(new ccSession(request));
	}

	ccRouterFunctor* route = this->router->getRoute(request);
	ccResponse *ret = route->Call(request);

	if (request->getSession()) {
		ccCookie *cs = new ccCookie(
				this->getConfigValue("session.session_id", "CCF_SESSSION_ID"),request->getSession()->getId());
		ret->addCookie(cs);
	}
	delete request;
	return ret;
}

bool ccApp::loadConfig(std::string config_file) {
	config = new ccConfigLoader(config_file);
	return true;
}

std::string ccApp::getConfigValue(std::string name) {
	return config->getConfigValue(name);
}

std::string ccApp::getConfigValue(std::string name, std::string value) {
	return config->getConfigValue(name, value);
}

std::string ccApp::getInitParam(std::string name) {
	  char** env;
	  for (env = this->envp; *env != 0; env++)
	  {
		  std::string tmp = *env;
		  unsigned int pos = tmp.find("=");
		  if (pos != std::string::npos && tmp.substr(0,pos) == name) {
			  return tmp.substr(pos+1);
		  }
	  }
	  return "";
}


} /* namespace ccFramework */

