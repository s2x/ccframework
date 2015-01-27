/*
 * ccPregRoute.h
 *
 *  Created on: 26-01-2015
 *      Author: piotr
 */

#ifndef CCPREGROUTE_H_
#define CCPREGROUTE_H_

#include <pcre.h>
#include "ccClassDeclarations.h"
#include "ccRoute.h"
#include <iostream>

namespace ccFramework {
class ccPregRoute: public ccRoute {
protected:
	pcre *re;

public:
	ccPregRoute(std::string name, std::string pattern,
			ccRouterFunctor* functor) : ccRoute(name, pattern, functor) {

		const char *error = NULL;
		int erroffset;
		std::string tmp_pattern = "^" + this->prepare(pattern) + "$";
		this->re = pcre_compile(tmp_pattern.c_str(), 0, &error, &erroffset, NULL);

		if (error) delete error;
	}

	~ccPregRoute();

	std::string prepare(std::string pattern);
	std::string getUrl(std::map<std::string, std::string> params);
	void setParameterType(std::string name, std::string patter);

	bool match(ccRequest *request);
};
} /* namespace ccFramework */

#endif /* CCPREGROUTE_H_ */
