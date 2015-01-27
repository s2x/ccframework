/*
 * ccStaticRoute.h
 *
 *  Created on: 26-01-2015
 *      Author: piotr
 */

#ifndef CCSTATICROUTE_H_
#define CCSTATICROUTE_H_

#include "ccRoute.h"

namespace ccFramework {

class ccStaticRoute: public ccRoute {
public:
	ccStaticRoute(std::string name, std::string pattern,
			ccRouterFunctor* functor) : ccRoute(name, pattern, functor) {};

	bool match(ccRequest *request);

};

} /* namespace ccFramework */

#endif /* CCSTATICROUTE_H_ */
