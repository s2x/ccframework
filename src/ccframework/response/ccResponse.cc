/*
 * ccResponse.cpp
 *
 *  Created on: 30-07-2013
 *      Author: piotr
 */

#include "ccResponse.h"
#include "ccCookie.h"
#include <sstream>
namespace ccFramework {

ccResponse::ccResponse() {
	// TODO Auto-generated constructor stub
	this->setHeader("Content-type","text/html");
}

ccResponse::ccResponse(std::string content) {
	this->setHeader("Content-type","text/html");
	this->setContent(content);
}


ccResponse::~ccResponse() {
	// TODO Auto-generated destructor stub

	while (this->cookies.size()) {
		delete this->cookies.begin()->second;
		this->cookies.erase(this->cookies.begin());
	}

}

void ccResponse::addCookie(ccCookie *cookie) {
	std::map<std::string, ccCookie*>::iterator it;
	it  = this->cookies.find(cookie->getName());
	if ( it != this->cookies.end()) {
		this->cookies.erase(it);
		delete it->second;
	}

	this->cookies[cookie->getName()]= cookie;
}

std::string ccResponse:: getHeaders() {
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

} /* namespace ccFramework */

