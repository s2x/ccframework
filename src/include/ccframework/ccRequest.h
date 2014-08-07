/*
 * ccRequest.h
 *
 *  Created on: 30-07-2013
 *      Author: piotr
 */

#ifndef CCREQUEST_H_
#define CCREQUEST_H_
#include "ccFramework.h"
#include "fcgiapp.h"
#include <iostream>
namespace ccFramework {

class ccRequest {
	ccSession *session;
	FCGX_Request request;
	void parsePostParameters();
	void parseGetParameters();
	void parseCookieParameters();
	ccArray *query_params;
	ccArray *post_params;
	ccArray *cookies;
public:

	static const int POST = 1;
	static const int GET = 2;

	ccRequest(FCGX_Request request);
	virtual ~ccRequest();
	std::string getEnvParamter(std::string name,
			std::string default_value = "");
	bool hasRequestParameter(std::string name);
	bool hasPostParameter(std::string name);

	int getRequestParameterAsInt(std::string name, int default_value = 0);
	double getRequestParameterAsDouble(std::string name, double default_value =
			0.0);

	std::string getRequestParameter(std::string name,
			std::string default_value = "");
	std::string getPostParameter(std::string name, std::string default_value =
			"");

	std::string getCookie(std::string name, std::string default_value = "");
	bool hasCookie(std::string name);
	void setRequestParameter(std::string name, std::string value);
	ccSession *getSession();
	void setSession(ccSession *session);
	int getMethod();
};

} /* namespace ccFramework */
#endif /* CCREQUEST_H_ */
