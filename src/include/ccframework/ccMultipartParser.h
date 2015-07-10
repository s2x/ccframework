/*
 * ccMultipartParser.h
 *
 *  Created on: 24-10-2013
 *      Author: piotr
 */

#ifndef CCMULTIPARTPARSER_H_
#define CCMULTIPARTPARSER_H_

#include <map>
#include <iostream>
#include "ccArray.h"

namespace ccFramework {

class ccMultipartParser {
	ccArray _parameters;
	void parsePart(std::string part);

public:
	ccMultipartParser(std::string query, std::string sep = "&");
	virtual ~ccMultipartParser();

	ccArray getAllParameters() const {
		return _parameters;
	}
};

} /* namespace ccFramework */
#endif /* CCMULTIPARTPARSER_H_ */
