#ifndef CCROUTE_H_
#define CCROUTE_H_
#include "ccFramework.h"
#include <iostream>
#include <vector>
#include <pcre.h>

namespace ccFramework {

class ccRoute {
	std::string name;
	std::string pattern;
	pcre *re;
	std::vector<std::string> route_params;
	std::vector<std::string> route_parts;
	std::map<std::string, std::string> request_params;
	ccRouterFunctor* functor;
public:
	ccRoute(std::string name, ccRouterFunctor* functor);
	ccRoute(std::string name, std::string pattern,  ccRouterFunctor* functor);
	bool match(ccRequest *request);
	std::string prepare(std::string pattern);
	bool hasRouteParameter(std::string name);
	std::string getRouteParameter(std::string name);
	std::string getRouteParameter(std::string name, std::string default_value);
	ccResponse *Call(ccRequest* request);
	void setPermision(std::string role, bool allowed);
	void inheritPermissions(std::string route_name);

	virtual ~ccRoute();

	const std::string& getName() const {
		return name;
	}

	void setName(const std::string& name) {
		this->name = name;
	}

	std::map<std::string, std::string> getRouteParameters() {
		return request_params;
	}

	ccRouterFunctor* getFunctor();
};

} /* namespace ccFramework */
#endif /* CCROUTE_H_ */
