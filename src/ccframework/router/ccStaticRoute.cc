/*
 * ccStaticRoute.cpp
 *
 *  Created on: 26-01-2015
 *      Author: piotr
 */

#include "ccStaticRoute.h"
#include "ccRequest.h"

namespace ccFramework {

bool ccStaticRoute::match(ccRequest* request) {
	this->request_params.clear();
	std::string request_uri = request->getEnvParamter("REDIRECT_URL",
			request->getEnvParamter("REQUEST_URI"));
	request_uri = request_uri.substr(0, request_uri.find_first_of("?"));

	if (request_uri.compare(this->pattern)==0) {
		return true;
	}

	return false;
}

} /* namespace ccFramework */
