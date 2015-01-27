/*
 * ccPregRoute.cpp
 *
 *  Created on: 26-01-2015
 *      Author: piotr
 */

#include "ccPregRoute.h"
#include "ccRequest.h"
#include "ccCommon.h"
#include "ccException.h"
namespace ccFramework {

bool ccPregRoute::match(ccRequest *request) {
	int ovector[30];
	int rc;
	int substring_length = 0;
	int substring_start = 0;

	this->request_params.clear();

	std::string request_uri = this->getFixedRequestUri(request);
	request_uri = request_uri.substr(0, request_uri.find_first_of("?"));

	rc = pcre_exec(this->re, NULL, request_uri.c_str(), request_uri.length(), 0,
			0, ovector, 30);
	if (rc < 0)
		return false;

	for (int i = 1; i < rc; i++) {
		substring_start = ovector[2 * i];
		substring_length = ovector[2 * i + 1] - ovector[2 * i];

		this->request_params.insert(
				std::pair<std::string, std::string>(this->route_params[(i - 1)],
						request_uri.substr(substring_start, substring_length)));
	}
	return true;
}


std::string ccPregRoute::prepare(std::string pttr) {
	this->route_parts.clear();
	this->route_params.clear();

	const char *error = NULL;
	const char *subject = pttr.c_str();
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
		rc = pcre_exec(pre, NULL, subject, pttr.length(), offset, 0, ovector,
				30);
		if (rc > 0) {
			has_params = true;
			substring_start = offset;
			substring_length = ovector[0] - offset;
			std::string route_part = pttr.substr(substring_start,
					substring_length);
			ret.append(route_part);
			substring_start = ovector[2];
			substring_length = ovector[3] - ovector[2];
			route_part = pttr.substr(substring_start,
					substring_length);
			if (this->params_type.count(route_part))
				ret.append(this->params_type[route_part]);
			else
				ret.append("([^/]++)");
			this->route_params.push_back(route_part);
		}
		offset = ovector[1];
	} while (rc >= 0);

	pcre_free(pre);
	if (!has_params) {
		//this->route_parts.push_back(pttr);
		return pttr;
	}

	if (error)
		delete error;
	/* number of elements in the output vector */
	return ret;
}

std::string ccPregRoute::getUrl(std::map<std::string, std::string> params) {
	std::string ret = "";
	int erroffset;
	int ovector[30];
	const char *error = NULL;
	std::string tmp_pattern = this->pattern;
	int rc;
	int offset = 0;
	int substring_length = 0;
	int substring_start = 0;
	bool has_params = false;

	std::map<std::string, std::string> set_params = params;

	pcre *pre = pcre_compile("{:(.*?)}", 0, &error, &erroffset, NULL);
	do {
		rc = pcre_exec(pre, NULL, tmp_pattern.c_str(), tmp_pattern.length(), offset, 0, ovector,
				30);
		if (rc > 0) {
			has_params = true;
			substring_start = offset;
			substring_length = ovector[0] - offset;
			std::string route_part = tmp_pattern.substr(substring_start,substring_length);
			ret.append(route_part);
			substring_start = ovector[2];
			substring_length = ovector[3] - ovector[2];
			route_part = tmp_pattern.substr(substring_start, substring_length);
			if (params.count(route_part)) {
				ret.append(ccCommon::UriEncode(params[route_part]));
				set_params.erase(route_part);
			}
			else {
				throw ccException("500","Route "+this->getName()+" require paramter: "+route_part);
			}
		}
		offset = ovector[1];
	} while (rc >= 0);
	pcre_free(pre);

	std::string query = "";
	for(std::map<std::string, std::string>::iterator it = set_params.begin(); it != set_params.end(); ++it) {
		query+=ccCommon::UriEncode(it->first)+"="+ccCommon::UriEncode(it->second);
		if (it != --set_params.end()) query += "&";
	}

	if (error) delete error;

	if (!has_params) ret = this->pattern;
	if (query!="") ret += "?"+query;

	/* number of elements in the output vector */
	return ret;
}

void ccPregRoute::setParameterType(std::string name, std::string param_patter) {
	const char *error = NULL;
	int erroffset;

	this->params_type[name] = param_patter;
	pcre_free(this->re);
	std::string tmp_pattern = "^" + this->prepare(this->pattern) + "$";
	this->re = pcre_compile(tmp_pattern.c_str(), 0, &error, &erroffset, NULL);
}

ccPregRoute::~ccPregRoute() {
	pcre_free(this->re);
// TODO Auto-generated destructor stub
}


} /* namespace ccFramework */
