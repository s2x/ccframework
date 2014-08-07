/*
 * ccQueryParser.h
 *
 *  Created on: 02-08-2013
 *      Author: piotr
 */

#ifndef CCQUERYPARSER_H_
#define CCQUERYPARSER_H_
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include "ccArray.h"
using std::vector;

namespace ccFramework {

class ccQueryParser {
	std::string query;
	ccArray *QueryElemets;
	ccArray *map_pairs(std::string character_string, ccArray *Elements, std::string sep = "&");
	vector<std::string> split(const std::string& s, const std::string& delim, const bool keep_empty = true);

public:
	ccQueryParser(std::string query, std::string sep = "&");
	virtual ~ccQueryParser();
	std::string getParameter(std::string name);

	ccArray *getAllParameters(){
		return QueryElemets;
	}
};

} /* namespace ccFramework */
#endif /* CCQUERYPARSER_H_ */
