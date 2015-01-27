/*
 * ccSession.cpp
 *
 *  Created on: 12-09-2013
 *      Author: piotr
 */

#include "ccSession.h"
#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include "ccApp.h"
#include "ccRequest.h"
#include "ccSessionProvider.h"
#include "ccCookie.h"
#include "ccCommon.h"
#include "ccConfigLoader.h"

namespace ccFramework {

ccSession::ccSession(ccRequest *request, ccSessionProvider *provider) {
	std::string sess_key = ccApp::getInstance()->getConfigValue(
			"session.session_id", "CCF_SESSSION_ID");

	if (provider == NULL ) provider = new ccSessionProvider(""); //empty session provider
	this->provider = provider;
//	this->session = new ccConfigLoader("");

	this->id = request->getCookie(sess_key,"");

	if (this->id.length()!=32 || !this->provider->hasSession(this->id)) {
		//session not found so create new

		// do until find new session key
		do {
			struct timeval now;
			gettimeofday(&now, NULL);
			char buf[64];
			sprintf(buf,"%ld%ld", now.tv_sec, now.tv_usec);
			this->id = ccCommon::md5hash(buf);
		} while (this->provider->hasSession(this->id));
	}
	this->config = this->provider->load(this->id);
	this->save = false;
}

void ccSession::set(std::string path, std::string val) {
	this->config[path] = val;
}

std::string ccSession::get(std::string path, std::string val) {
	if ( this->config[path]) return this->config[path].as<std::string>();
	return val;
}

ccSession::~ccSession() {
	this->provider->save(this->id, this->config);
}

void ccSession::setSave(bool save) {
	this->save = save;
}

const std::string& ccSession::getId() const {
	return this->id;
}

} /* namespace ccFramework */


