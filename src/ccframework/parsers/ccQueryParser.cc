/*
 * ccQueryParser.cpp
 *
 *  Created on: 02-08-2013
 *      Author: piotr
 */

#include "ccQueryParser.h"
#include "ccCommon.h"

namespace ccFramework {

ccQueryParser::ccQueryParser(std::string query, std::string sep) {
	this->query = query;
	this->map_pairs(this->query, sep);
}

ccQueryParser::~ccQueryParser() {
	// TODO Auto-generated destructor stub
}

void ccQueryParser::map_pairs(std::string character_string, std::string sep) {
	std::string test,key,value;
	std::vector<std::string>::iterator it;
	std::vector<std::string> words;

	words = split(character_string, sep);
	for (it = words.begin(); it != words.end(); ++it) {
		test = *it;
		const std::string::size_type pos_eq = test.find('=');
		if (pos_eq != std::string::npos) {
			key = ccCommon::UriDecode(ccCommon::trim(test.substr(0, pos_eq)));
			value = ccCommon::UriDecode(test.substr(pos_eq + 1));

			ccCommon::set_array_element_by_path(&_parameters,key,value);
//			Elements.insert(std::pair<std::string, std::string>(key, value));
		}

	}
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

} /* namespace ccFramework */
