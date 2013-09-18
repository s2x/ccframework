/*
 * ccRouteMatcher.h
 *
 *  Created on: 30-07-2013
 *      Author: piotr
 */

#ifndef CCROUTEMATCHER_H_
#define CCROUTEMATCHER_H_
#include <iostream>
#include "ccFramework.h"

namespace ccFramework {

class ccRouteMatcher {
	std::map<std::string,ccRoute *> routes;
public:
	ccRouteMatcher();
	virtual ~ccRouteMatcher();
	void addRoute(ccRoute *route);

	std::string getRoute(ccRequest *request);
};

} /* namespace ccFramework */
#endif /* CCROUTEMATCHER_H_ */
