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
	ctemplate::mutable_default_template_cache()->SetTemplateRootDirectory(
			this->config->getConfigValue("template_dir", ""));
	this->router = new ccRouter();
	this->default_countroller = new ccController(this);
	instance = this;

	//boostrap some config

	this->cin_streambuf = std::cin.rdbuf();
	this->cout_streambuf = std::cout.rdbuf();
	this->cerr_streambuf = std::cerr.rdbuf();

	this->acl = new ccAcl();
	this->acl->addRole("_GUEST");
	this->acl->setAllowAll(true);
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

	// TODO Auto-generated destructor stub

	delete this->router;
	delete this->default_countroller;
	delete this->config;
}

ccResponse *ccApp::processRequest(FCGX_Request fcgi_request) {
	ctemplate::mutable_default_template_cache()->ReloadAllIfChanged(
			ctemplate::TemplateCache::IMMEDIATE_RELOAD);

	ccResponse *ret = NULL;
	this->request = new ccRequest(fcgi_request);

	// autostart session
	if (this->getConfigValue("session.autostart", "0") == "1") {
		this->request->setSession(new ccSession(request));
	}

	try {
		ccRoute *route = this->router->getRoute(this->request);
		this->router->setActiveRoute(route);
		ret = route->Call(this->request);
	} catch (ccException &e) {
		ret = this->default_countroller->__errorAction(this->request, e);
	}

	if (this->request->getSession()) {
		ccCookie *cs = new ccCookie(
				this->getConfigValue("session.session_id", "CCF_SESSSION_ID"),
				request->getSession()->getId());
		ret->addCookie(cs);
	}
	delete this->request;
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

ccRequest* ccApp::getRequest() {
	return request;
}

void ccApp::run() {

	FCGX_Request request;

	FCGX_Init();
	FCGX_InitRequest(&request, 0, 0);
	while (FCGX_Accept_r(&request) == 0) {

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

		ccResponse *resp = this->processRequest(request);
		FCGX_FPrintF(request.out, "%s"
				"\r\n"
				"%s", resp->getHeaders().c_str(), resp->getContent().c_str());
		delete resp;
	}
	FCGX_Finish_r(&request);
}

ccAcl* ccApp::getAcl(){
	return this->acl;
}

} /* namespace ccFramework */


