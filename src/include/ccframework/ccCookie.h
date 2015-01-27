/*
 * ccCookie.h
 *
 *  Created on: 12-09-2013
 *      Author: piotr
 */

#ifndef CCCOOKIE_H_
#define CCCOOKIE_H_

#include <iostream>

namespace ccFramework {

class ccCookie {
	std::string name;
	std::string value;
	bool secure;
	std::string path;
	std::string domain;
	time_t expires;
public:
	ccCookie(std::string name, std::string value);
	virtual ~ccCookie();

	const std::string& getName() const {
		return name;
	}

	void setName(const std::string& name) {
		this->name = name;
	}

	const std::string& getValue() const {
		return value;
	}

	void setValue(const std::string& value) {
		this->value = value;
	}

	const std::string& getDomain() const {
		return domain;
	}

	void setDomain(const std::string& domain) {
		this->domain = domain;
	}

	const std::string& getPath() const {
		return path;
	}

	void setPath(const std::string& path) {
		this->path = path;
	}

	bool isSecure() const {
		return secure;
	}

	void setSecure(bool secure) {
		this->secure = secure;
	}
	time_t getExpires() const {
		return expires;
	}

	void setExpires(time_t expires) {
		this->expires = expires;
	}
	std::string serialize() {
		std::string ret;

		ret = this->name + "=" + this->value;
		struct tm * timeinfo;

		if (this->expires != 0) {
			char buffer [120];
			timeinfo = localtime(&this->expires);
			strftime (buffer,80,"%a, %e %h %Y %H:%M:%S %z",timeinfo);
			ret += "; expires="+(std::string)buffer;
		//	delete timeinfo;
		}

		if (this->path != "") ret += "; path="+this->path;
		if (this->domain != "") ret += "; domain="+this->domain;

		if (this->isSecure()) ret += "; secure";

		return ret;
	}

};

} /* namespace ccFramework */
#endif /* CCCOOKIE_H_ */
