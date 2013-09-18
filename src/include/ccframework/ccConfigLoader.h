/*
 * ccConfigLoader.h
 *
 *  Created on: 12-09-2013
 *      Author: piotr
 */

#ifndef CCCONFIGLOADER_H_
#define CCCONFIGLOADER_H_

namespace ccFramework {

class ccConfigLoader {
	YAML::Node config;
	std::string config_file;
	std::string arraySearch(YAML::Node, std::string path);
	void arraySet(YAML::Node, std::string path, std::string value);
public:
	bool load(std::string config_file);
	void setConfig(YAML::Node);
	std::string getConfigValue(std::string name, std::string value= "");
	void setConfigValue(std::string name, std::string value);
	ccConfigLoader(std::string filename);
	bool save();
	virtual ~ccConfigLoader();
};

} /* namespace ccFramework */
#endif /* CCCONFIGLOADER_H_ */
