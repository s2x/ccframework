/*
 * ccApp.cpp
 *
 *  Created on: 30-07-2013
 *      Author: piotr
 */

#include "ccframework/ccFramework.h"
#include "fcgio.h"
#include "fcgi_config.h"  // HAVE_IOSTREAM_WITHASSIGN_STREAMBUF
namespace ccFramework {

ccApp *ccApp::instance = NULL;
ccConfigLoader *ccApp::config = NULL;

ccApp::ccApp(std::string config_file) {

	this->request = NULL;
	this->loadConfig(config_file);

	//add default template dir
	ctemplate::mutable_default_template_cache()->SetTemplateRootDirectory(
			this->config->getConfigValue("template_dir", ""));

	//initialise router and controler stuff
	this->router = new ccRouter();
	this->default_countroller = new ccController(this);

	//set instance
	instance = this;

	// set read buffers
	this->cin_streambuf = std::cin.rdbuf();
	this->cout_streambuf = std::cout.rdbuf();
	this->cerr_streambuf = std::cerr.rdbuf();

	//set acl
	this->acl = new ccAcl();
	this->acl->setAllowAll(true);
    
   	ctemplate::addTemplateHelper("COMPONENT",new ccComponentHelper());

}
ccApp::~ccApp() {
#if HAVE_IOSTREAM_WITHASSIGN_STREAMBUF
	cin = this->cin_streambuf;
	cout = this->cout_streambuf;
	cerr = this->cerr_streambuf;
#else
	std::cin.rdbuf(this->cin_streambuf);
	std::cout.rdbuf(this->cout_streambuf);
	std::cerr.rdbuf(this->cerr_streambuf);
#endif

	delete this->router;
	delete this->default_countroller;
	delete this->config;

	for (std::map<std::string, ccController*>::iterator it=this->registred_controllers.begin(); it!=this->registred_controllers.end(); ++it) {
		delete (it->second);
	}
}

ccResponse *ccApp::processRequest(FCGX_Request fcgi_request) {

	ccResponse *ret = NULL;

	//reload cache if template changes
	if (this->getConfigValue("templates.cache", "0") == "0") {
	ctemplate::mutable_default_template_cache()->ReloadAllIfChanged(
			ctemplate::TemplateCache::IMMEDIATE_RELOAD);
	} else {
		ctemplate::mutable_default_template_cache()->ReloadAllIfChanged(
				ctemplate::TemplateCache::LAZY_RELOAD);

	}
	//proces fastcgi headers
	this->request = new ccRequest(fcgi_request);

	// autostart session
	this->getRequest()->setSession(new ccSession(request));
	if (this->getConfigValue("session.autostart", "0") == "1") {
		//autosave
		this->getRequest()->getSession()->setSave(true);
	}

	//get role from session
	this->getRequest()->getSession()->set("acl.user_role",
			this->getRequest()->getSession()->get("acl.user_role",
					ccAcl::DEFAULT_ROLE));

	try {
		//get route and call action
		ccRoute *route = this->router->getRoute(this->request);
		this->router->setActiveRoute(route);
		ret = route->Call(this->request);
	} catch (ccException &e) {
		ret = this->default_countroller->__errorAction(this->request, e);
	} catch (...) {
		ccException e("500","Internal Error");
		ret = this->default_countroller->__errorAction(this->request, e);
	}

	// save session if exists and set session id to cookie
	if (this->getRequest()->getSession()) {
		ccCookie *cs = new ccCookie(
				this->getConfigValue("session.session_id", "CCF_SESSSION_ID"),
				request->getSession()->getId());
		ret->addCookie(cs);
	}

	//free memory
	delete this->request;

	//return response
	return ret;
}

/**
 * Load main configu from file
 */
bool ccApp::loadConfig(std::string config_file) {
	config = new ccConfigLoader(config_file);
	return true;
}

/**
 * Get config value
 */
std::string ccApp::getConfigValue(std::string name) {
	return config->getConfigValue(name);
}

/**
 * get config value, when value does not exists return default
 */
std::string ccApp::getConfigValue(std::string name, std::string value) {
	return config->getConfigValue(name, value);
}

/**
 * Get current request
 */
ccRequest* ccApp::getRequest() {
	return request;
}

/**
 * main applicaton loop
 */
void ccApp::run() {

	FCGX_Request request;

	// init some fastcgi data
	FCGX_Init();
	FCGX_InitRequest(&request, 0, 0);

	//wait for valid request
	while (FCGX_Accept_r(&request) == 0) {

		// set streams
		fcgi_streambuf cin_fcgi_streambuf(request.in);
		fcgi_streambuf cout_fcgi_streambuf(request.out);
		fcgi_streambuf cerr_fcgi_streambuf(request.err);

#if HAVE_IOSTREAM_WITHASSIGN_STREAMBUF
		cin = &cin_fcgi_streambuf;
		cout = &cout_fcgi_streambuf;
		cerr = &cerr_fcgi_streambuf;
#else
		std::cin.rdbuf(&cin_fcgi_streambuf);
		std::cout.rdbuf(&cout_fcgi_streambuf);
		std::cerr.rdbuf(&cerr_fcgi_streambuf);
#endif
		//process request;
		ccResponse *resp = this->processRequest(request);

		//return headers and content
		FCGX_FPrintF(request.out, "%s"
				"\r\n"
				"%s", resp->getHeaders().c_str(), resp->getContent().c_str());
		//FCGX_FPrintF(request.out,"<pre>");
		//for ( ; *request.envp != NULL; request.envp++) {
		//	FCGX_FPrintF(request.out,"%s\n", *request.envp);
		//}
		//FCGX_FPrintF(request.out,"</pre>");

		//free memory
		delete resp;
	}

	//fastcig cleanup
	FCGX_Finish_r(&request);
}

/**
 * get acl
 */
ccAcl* ccApp::getAcl() {
	return this->acl;
}

/**
 * Helper for generating urls
 */
std::string ccApp::genUrl(std::string route_name, std::string query_string) {
	ccRoute *route = ccApp::instance->getRouter()->getRoute(route_name);
	if (route)	return route->getUrl(query_string);
	return "";
}

/**
 * Helper for generating urls
 */
std::string ccApp::genUrl(std::string route_name,
		std::map<std::string, std::string> params) {
	ccRoute *route = ccApp::instance->getRouter()->getRoute(route_name);
	if (route)	return route->getUrl(params);
	return "";
}

/**
 * get active route name
 */
std::string ccApp::getActiveRouteName() {
	return ccApp::instance->getRouter()->getActiveRouteName();
}

ccConfigLoader* ccApp::getConfig() {
	return config;
}

void ccApp::registerController(std::string name, ccController* controller) {
	if (this->registred_controllers.count(name)==0) {
		this->registred_controllers[name] = controller;
		controller->initController();
		controller->registerRoutes();
	}

}



} /* namespace ccFramework */


