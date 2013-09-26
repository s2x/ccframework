/*
 * ccRoute.cpp
 *
 *  Created on: 13-08-2013
 *      Author: piotr
 */

#include "ccframework/ccFramework.h"
#include <stdio.h>
#include <stdlib.h>
namespace ccFramework {

ccRoute::ccRoute(std::string name, std::string pattern) {
	// TODO Auto-generated constructor stub
	const char *error = NULL;
	int erroffset;

	this->name = name;
	this->pattern = "^" + this->prepare(pattern) + "$";
	this->re = pcre_compile(this->pattern.c_str(), 0, &error, &erroffset, NULL);

	if (error) delete error;
}

bool ccRoute::match(std::string subject) {
	int ovector[30];
	int rc;
	int substring_length = 0;
	int substring_start = 0;

	this->request_params.clear();

	rc = pcre_exec(this->re, NULL, subject.c_str(), subject.length(), 0, 0,
			ovector, 30);
	if (rc < 0)
		return false;

	for (int i = 1; i < rc; i++) {
		substring_start = ovector[2 * i];
		substring_length = ovector[2 * i + 1] - ovector[2 * i];

		this->request_params.insert(
				std::pair<std::string, std::string>(this->route_params[(i-1)],
						subject.substr(substring_start, substring_length)));
	}
	return true;
}

std::string ccRoute::prepare(std::string pattern) {
	this->route_parts.clear();
	this->route_params.clear();

	const char *error = NULL;
	const char *subject = pattern.c_str();
	int erroffset;
	int ovector[30];
	std::string ret = "";
	bool has_params = false;
	int rc;
	int offset = 0;
	int substring_length = 0;
	int substring_start = 0;

	pcre *pre = pcre_compile("{:(.*?)}", 0, &error, &erroffset, NULL);
	do {
		rc = pcre_exec(pre, NULL, subject, pattern.length(), offset, 0, ovector,
				30);
		if (rc > 0) {
			has_params = true;
			substring_start = offset;
			substring_length = ovector[0] - offset;
			ret.append(pattern.substr(substring_start, substring_length));
			this->route_parts.push_back(
					pattern.substr(substring_start, substring_length));
			substring_start = ovector[2];
			substring_length = ovector[3] - ovector[2];
			ret.append("([^/]++)");
			this->route_parts.push_back(
					pattern.substr(substring_start, substring_length));
			this->route_params.push_back(
					pattern.substr(substring_start, substring_length));
		}
		offset = ovector[1];
	} while (rc >= 0);

	pcre_free(pre);
	if (!has_params) {
		this->route_parts.push_back(pattern);
		return pattern;
	}

	if (error) delete error;

	/* number of elements in the output vector */
	return ret;
}

std::string ccRoute::getRouteParameter(std::string name) {
	return this->getRouteParameter(name, "");
}

std::string ccRoute::getRouteParameter(std::string name,
		std::string default_value) {
	if (this->hasRouteParameter(name)) {
		return this->request_params[name];
	}
	return "";
}

bool ccRoute::hasRouteParameter(std::string name) {
	return this->request_params.count( name );
}

ccRoute::~ccRoute() {
	pcre_free(this->re);
// TODO Auto-generated destructor stub
}

} /* namespace ccFramework */
