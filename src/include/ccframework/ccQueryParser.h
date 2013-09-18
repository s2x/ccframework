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
using std::vector;

namespace ccFramework {

class ccQueryParser {
	std::string query;
	std::map<std::string, std::string> QueryElemets;
	std::map<std::string, std::string>& map_pairs(std::string character_string, std::map<std::string, std::string>& Elements, std::string sep = "&");
	vector<std::string> split(const std::string& s, const std::string& delim, const bool keep_empty = true);

public:
	ccQueryParser(std::string query, std::string sep = "&");
	virtual ~ccQueryParser();
	std::string getParameter(std::string name);

	const std::map<std::string, std::string>& getAllParameters() const {
		return QueryElemets;
	}
};

} /* namespace ccFramework */
#endif /* CCQUERYPARSER_H_ */
