/*
 * ccSession.cpp
 *
 *  Created on: 12-09-2013
 *      Author: piotr
 */

#include "ccframework/ccFramework.h"
#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>

namespace ccFramework {

ccSession::ccSession(ccRequest *request) {
	std::string sess_key = ccApp::getInstance()->getConfigValue(
			"session.session_id", "CCF_SESSSION_ID");
	std::string sess_dir = ccApp::getInstance()->getConfigValue(
			"session.session_dir", "");

	this->id = request->getCookie(sess_key,"");

	if (this->id.length()!=32) {
		struct timeval now;
		gettimeofday(&now, NULL);
		char buf[64];
		sprintf(buf,"%ld%ld", now.tv_sec, now.tv_usec);
		this->id = ccCommon::md5hash(buf);
	}

	this->session_file = sess_dir + "/" + this->id + ".sess";
	this->loadSession();
	this->save = false;
}

void ccSession::loadSession() {
	this->session = new ccConfigLoader(this->session_file);
}

void ccSession::set(std::string path, std::string val) {
	this->session->setConfigValue(path,val);
}

std::string ccSession::get(std::string path, std::string val) {
	return this->session->getConfigValue(path,val);
}

ccSession::~ccSession() {
// TODO Auto-generated destructor stub
	if (this->save) this->session->save();
	delete this->session;
}

void ccSession::setSave(bool save) {
	this->save = save;
}

} /* namespace ccFramework */


