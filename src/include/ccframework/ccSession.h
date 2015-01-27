/*
 * ccSession.h
 *
 *  Created on: 12-09-2013
 *      Author: piotr
 */

#ifndef CCSESSION_H_
#define CCSESSION_H_
#include "ccClassDeclarations.h"
#include "ccConfigLoader.h"
#include "ccSessionProvider.h"
#include "ccRequest.h"

namespace ccFramework {

class ccSession {
	YAML::Node config;
	std::string id;
	ccConfigLoader *session;
	ccSessionProvider *provider;
	bool save;
public:
	void set(std::string path, std::string val);
	std::string get(std::string path, std::string val="");

	ccSession(ccRequest *request, ccSessionProvider *provider = NULL);
	virtual ~ccSession();

	const std::string& getId() const;

	void setSave(bool save);
};

} /* namespace ccFramework */
#endif /* CCSESSION_H_ */
