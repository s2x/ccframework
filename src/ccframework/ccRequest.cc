/*
 * ccRequest.cpp
 *
 *  Created on: 30-07-2013
 *      Author: piotr
 */

#include "ccframework/ccFramework.h"

namespace ccFramework {

ccRequest::ccRequest(FCGX_Request request) {
	// TODO Auto-generated constructor stub
	this->request = request;
	this->session = NULL;
	this->parsePostParameters();
	this->parseGetParameters();
	this->parseCookieParameters();
}

ccRequest::~ccRequest() {
	// TODO Auto-generated destructor stub
	if (this->session != NULL) delete this->session;
}

std::string ccRequest::getEnvParamter(std::string name, std::string default_value) {
	char *tmp = FCGX_GetParam(name.c_str(), this->request.envp);
	if (tmp) return tmp;
	return default_value;
}

void ccRequest::parseGetParameters() {
	char *tmp = FCGX_GetParam("QUERY_STRING", this->request.envp);
	ccQueryParser qp(tmp);
	this->query_params= qp.getAllParameters();
}


void ccRequest::parsePostParameters() {
	char buf[100];
	memset(buf,0,sizeof(buf));
	std::string tmp="";
	while (FCGX_GetStr(buf, sizeof(buf), request.in) > 0) {
	    tmp.append(buf);
		memset(buf,0,sizeof(buf));
	}
	std::string content_type = this->getEnvParamter("CONTENT_TYPE","");
	if (content_type.find("multipart/form-data;",0)==0) {
		int bound_pos = content_type.find("boundary=",0);
		if (bound_pos != std::string::npos) {
			std::string boundry = content_type.substr((bound_pos+9));
			ccMultipartParser mpp(tmp, boundry);
			this->post_params = mpp.getAllParameters();
		}
	}else {
		ccQueryParser qp(tmp);
		this->post_params = qp.getAllParameters();
	}
}


void ccRequest::parseCookieParameters() {
	char *tmp = FCGX_GetParam("HTTP_COOKIE", this->request.envp);
	if (tmp!=NULL) {
		ccQueryParser qp(tmp, ";");
		this->cookies = qp.getAllParameters();
	}
}

bool ccRequest::hasRequestParameter(std::string name) {
	return this->query_params.count(name);
}

std::string ccRequest::getRequestParameter(std::string name,
		std::string default_value) {
	if (this->hasRequestParameter(name)) {
		return ccCommon::UriDecode(this->query_params[name]);
	}
	return default_value;
}

void ccFramework::ccRequest::setRequestParameter(std::string name,
		std::string value) {
	this->query_params[name] = value;
}

std::string ccRequest::getCookie(std::string name, std::string default_value) {
	if (this->hasCookie(name)) {
		return this->cookies[name];
	}
	return default_value;
}

bool ccRequest::hasCookie(std::string name) {
	return this->cookies.count(name);
}


ccSession* ccRequest::getSession() {
	return this->session;
}

void ccRequest::setSession(ccSession* session) {
	this->session = session;
}


int ccRequest::getRequestParameterAsInt(std::string name, int default_value ) {
	if (!this->hasRequestParameter(name)) return default_value;
	return ccCommon::string2int(this->getRequestParameter(name));
}

double ccRequest::getRequestParameterAsDouble(std::string name, double default_value ) {
	if (!this->hasRequestParameter(name)) return default_value;
	return ccCommon::string2double(this->getRequestParameter(name));
}

bool ccRequest::hasPostParameter(std::string name) {

	return (this->post_params.find(name)!=this->post_params.end())?true:false;
}

std::string ccRequest::getPostParameter(std::string name,
		std::string default_value) {

	if (this->hasPostParameter(name)) return ccCommon::UriDecode(this->post_params[name]);
	return default_value;

}

int ccRequest::getMethod() {
	if (this->getEnvParamter("REQUEST_METHOD","GET")=="POST") return ccRequest::POST;
	//if (this->getEnvParamter("REQUEST_METHOD","GET")=="GET") return ccRequest::GET;
	return ccRequest::GET;
}

} /* namespace ccFramework */
