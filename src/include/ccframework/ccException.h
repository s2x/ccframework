/*
 * ccException.h
 *
 *  Created on: 30-09-2013
 *      Author: piotr
 */

#ifndef CCEXCEPTION_H_
#define CCEXCEPTION_H_

#include "ccFramework.h"

namespace ccFramework {

class ccException {
	std::string code;
	std::string msg;
public:
	ccException(std::string code, std::string msg);
	virtual ~ccException();
	std::string getCode();
	std::string getMessage();
};

} /* namespace ccFramework */
#endif /* CCEXCEPTION_H_ */
