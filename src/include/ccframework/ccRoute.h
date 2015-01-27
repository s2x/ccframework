#ifndef CCROUTE_H_
#define CCROUTE_H_

#include <iostream>
#include <vector>
#include <map>
#include "ccClassDeclarations.h"

namespace ccFramework {


class ccRoute {
protected:
	std::string name;
	std::string pattern;

	std::vector<std::string> route_params;
	std::vector<std::string> route_parts;
	std::map<std::string, std::string> request_params;
	std::map<std::string, std::string> params_type;
	ccRouterFunctor* functor;
public:
	ccRoute(std::string name, std::string pattern,  ccRouterFunctor* functor);

	virtual bool match(ccRequest *request);


	//if is active route then get paramters
	bool hasRouteParameter(std::string name);
	std::string getRouteParameter(std::string name);
	std::string getRouteParameter(std::string name, std::string default_value);

	// run controle/action
	ccResponse *Call(ccRequest* request);

	// permisions
	void setPermision(std::string role, bool allowed);
	void inheritPermissions(std::string route_name);

	// genertaing urls
	virtual std::string getUrl(std::map<std::string, std::string> params);
	std::string getUrl(std::string query_string);

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
