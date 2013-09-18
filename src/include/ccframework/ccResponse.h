/*
 * ccResponse.h
 *
 *  Created on: 30-07-2013
 *      Author: piotr
 */

#ifndef CCRESPONSE_H_
#define CCRESPONSE_H_

#include <iostream>
#include <sstream>

namespace ccFramework {

class ccResponse {
	std::map<std::string, std::string> headers;
	std::string content;
	std::map<std::string, ccCookie*> cookies;

public:
	ccResponse();
	ccResponse(std::string content);
	virtual ~ccResponse();

	const std::string& getContent() const {
		return content;
	}

	void setContent(const std::string& content) {
		this->content = content;
	}

	void addCookie(ccCookie *cookie) {
		std::map<std::string, ccCookie*>::iterator it;
		it  = this->cookies.find(cookie->getName());
		if ( it != this->cookies.end()) {
			this->cookies.erase(it);
			delete it->second;
		}

		this->cookies[cookie->getName()]= cookie;
	}

	std::string getHeaders() {
		std::string ret;
		std::ostringstream ss;
		ss<< this->content.length();
		this->setHeader("Content-length",ss.str());

		for (std::map<std::string, std::string>::const_iterator it =
				this->headers.begin(); it != this->headers.end(); ++it) {
			ret = ret + it->first + ":" + it->second + "\r\n";
		}

		for (std::map<std::string, ccCookie*>::const_iterator it =
				this->cookies.begin(); it != this->cookies.end(); ++it) {
			ret = ret + "Set-Cookie: " + it->second->serialize() + "\r\n";
		}

		return ret;
	}

	void setHeader(std::string name, std::string val) {
		this->headers[name] = val;
	}

	void redirect(std::string uri) {
		this->setHeader("Location", uri);
	}
};

} /* namespace ccFramework */
#endif /* CCRESPONSE_H_ */
