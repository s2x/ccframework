/*
 * ccYamlSessionProvider.cc
 *
 *  Created on: 26-01-2015
 *      Author: piotr
 */

#include "ccYamlSessionProvider.h"
#include "ccCommon.h"

namespace ccFramework {



bool ccYamlSessionProvider::hasSession(std::string id) {
	if (ccCommon::file_exists(this->getSessionFilename(id))) return true;
	return false;
}

YAML::Node ccYamlSessionProvider::load(std::string id) {
	if (this->hasSession(id)) return YAML::LoadFile(this->getSessionFilename(id));
	return YAML::Load("");
}

bool ccYamlSessionProvider::save(std::string id, YAML::Node data) {
	std::ofstream fout(this->getSessionFilename(id));
	if (fout) {
		fout << YAML::Dump(data);
		fout.close();
		return true;
	}
	return false;
}

std::string ccYamlSessionProvider::getSessionFilename(std::string id) {
	return this->session_dir+"/"+id+".sess";
}

} /* namespace ccFramework */
