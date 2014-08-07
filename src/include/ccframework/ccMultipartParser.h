/*
 * ccMultipartParser.h
 *
 *  Created on: 24-10-2013
 *      Author: piotr
 */

#ifndef CCMULTIPARTPARSER_H_
#define CCMULTIPARTPARSER_H_

#include "ccFramework.h"

namespace ccFramework {

class ccMultipartParser {
	ccArray *QueryElemets;
	void parsePart(std::string part);

public:
	ccMultipartParser(std::string query, std::string sep = "&");
	virtual ~ccMultipartParser();

	ccArray *getAllParameters() {
		return QueryElemets;
	}
};

} /* namespace ccFramework */
#endif /* CCMULTIPARTPARSER_H_ */
