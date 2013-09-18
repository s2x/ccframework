/*
 * ccSession.h
 *
 *  Created on: 12-09-2013
 *      Author: piotr
 */

#ifndef CCSESSION_H_
#define CCSESSION_H_
#include "ccFramework.h"

namespace ccFramework {

class ccSession {
	std::string id;
	std::string session_file;
	ccConfigLoader *session;
	void loadSession();
public:
	void set(std::string path, std::string val);
	std::string get(std::string path, std::string val="");
	ccSession(ccRequest *request);
	virtual ~ccSession();
	std::string getSessionFile() {
		return this->session_file;
	}

	const std::string& getId() const {
		return id;
	}
};

} /* namespace ccFramework */
#endif /* CCSESSION_H_ */
