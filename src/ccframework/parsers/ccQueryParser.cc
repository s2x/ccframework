/*
 * ccQueryParser.cpp
 *
 *  Created on: 02-08-2013
 *      Author: piotr
 */

#include "ccframework/ccFramework.h"

namespace ccFramework {

ccQueryParser::ccQueryParser(std::string query, std::string sep) {
	this->query = query;
	this->map_pairs(this->query,this->QueryElemets, sep);
}

ccQueryParser::~ccQueryParser() {
	// TODO Auto-generated destructor stub
}

std::map<std::string, std::string>& ccQueryParser::map_pairs(std::string character_string,
		std::map<std::string, std::string>& Elements, std::string sep) {
	std::string test,key,value;
	std::vector<std::string>::iterator it;
	std::vector<std::string> words;

	words = split(character_string, sep);
	for (it = words.begin(); it != words.end(); ++it) {
		test = *it;
		const std::string::size_type pos_eq = test.find('=');
		if (pos_eq != std::string::npos) {
			key = ccCommon::trim(test.substr(0, pos_eq));
			value = test.substr(pos_eq + 1);
			Elements.insert(std::pair<std::string, std::string>(key, value));
		}

	}
	return Elements;
}

vector<std::string> ccQueryParser::split(const std::string& s,
		const std::string& delim, const bool keep_empty) {
	vector<std::string> result;
	if (delim.empty()) {
		result.push_back(s);
		return result;
	}
	std::string::const_iterator substart = s.begin(), subend;
	while (true) {
		subend = search(substart, s.end(), delim.begin(), delim.end());
		std::string temp(substart, subend);
		if (keep_empty || !temp.empty()) {
			result.push_back(temp);
		}
		if (subend == s.end()) {
			break;
		}
		substart = subend + delim.size();
	}
	return result;
}

std::string ccQueryParser::getParameter(std::string name) {
	return "";
}

} /* namespace ccFramework */
