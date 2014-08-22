/*
 * ccConfigLoader.cpp
 *
 *  Created on: 12-09-2013
 *      Author: piotr
 */

#include "ccframework/ccFramework.h"

namespace ccFramework {

ccConfigLoader::ccConfigLoader(std::string filename) {
	// TODO Auto-generated constructor stub
	this->config_file = filename;
	this->load(filename);
}

void ccConfigLoader::setConfig(YAML::Node node) {
	this->config = YAML::Load(YAML::Dump(node));

}

bool ccConfigLoader::save() {

	std::ofstream fout(this->config_file.c_str());
	if (fout) {
		fout << YAML::Dump(this->config);
		fout.close();
	}
	return false;
}

void ccConfigLoader::setConfigValue(std::string name, std::string value) {
	this->arraySet(this->config, name, value);
}

void ccConfigLoader::arraySet(YAML::Node node, std::string path,
		std::string value) {
	if (path.length() != 0) {
		std::string tmp_name = path;
		std::size_t found = tmp_name.find(".", found);
		if (found != std::string::npos) {
			std::string node_name = tmp_name.substr(0, found);
			tmp_name = tmp_name.substr(found + 1);
			this->arraySet(node[node_name.c_str()], tmp_name, value);
		} else {
			node[tmp_name.c_str()] = value;
		}
	}
}

ccConfigLoader::~ccConfigLoader() {
	// TODO Auto-generated destructor stub
}

bool ccConfigLoader::load(std::string config_file) {
	if (ccCommon::file_exists(config_file)) {
		this->config = YAML::LoadFile(config_file);
	} else {
		this->config = YAML::Load("");
	}
	return true;
}

std::string ccConfigLoader::arraySearch(YAML::Node node, std::string path,
		std::string default_value) {
	if (!node || path.length() == 0) return default_value;

	std::string tmp_name = path;
	std::size_t found = 0;
	found = tmp_name.find(".", found);
	if (found != std::string::npos) {
		std::string node_name = tmp_name.substr(0, found);
		tmp_name = tmp_name.substr(found + 1);
		return this->arraySearch(node[node_name.c_str()], tmp_name, default_value);
	}
	if (node[tmp_name.c_str()])
		return node[tmp_name.c_str()].as<std::string>();
	return default_value;
}

std::string ccConfigLoader::getConfigValue(std::string name,
		std::string value) {
	return this->arraySearch(this->config, name, value);
}

} /* namespace ccFramework */

const YAML::Node& ccFramework::ccConfigLoader::getConfig() const {
	return config;
}
