/*
 * ccResponse.h
 *
 *  Created on: 30-07-2013
 *      Author: piotr
 */

#ifndef CCRESPONSE_H_
#define CCRESPONSE_H_
#include <map>
#include "ccCookie.h"
namespace ccFramework {

class ccResponse {
protected:
	std::map<std::string, std::string> headers;
	std::string content;
	std::map<std::string, ccCookie*> cookies;

public:
	ccResponse();
	ccResponse(std::string content);
	virtual ~ccResponse();

	std::string getContent();

	void setContent(const std::string& content) {
		this->content = content;
	}

	void addCookie(ccCookie *cookie);

	std::string getHeaders();

	void setHeader(std::string name, std::string val) {
		this->headers[name] = val;
	}

	void redirect(std::string uri) {
		this->setHeader("Location", uri);
	}
};

} /* namespace ccFramework */
#endif /* CCRESPONSE_H_ */
