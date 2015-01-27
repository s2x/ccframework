/*
 * ccException.h
 *
 *  Created on: 30-09-2013
 *      Author: piotr
 */

#ifndef CCEXCEPTION_H_
#define CCEXCEPTION_H_

#include <iostream>

namespace ccFramework {

class ccException {
	std::string code;
	std::string msg;
public:
	static const std::string ERROR_UNAUTHORIZED;
	static const std::string ERROR_FORBIDDEN;
	static const std::string ERROR_NOT_FOUND;
	static const std::string ERROR_INTERNAL_SERVER_ERROR;


	static const std::string ERROR_MSG_INTERNAL_SERVER_ERROR;
	static const std::string ERROR_MSG_FORBIDDEN;

	ccException(std::string code, std::string msg);
	virtual ~ccException();
	std::string getCode();
	std::string getMessage();
};

} /* namespace ccFramework */
#endif /* CCEXCEPTION_H_ */
