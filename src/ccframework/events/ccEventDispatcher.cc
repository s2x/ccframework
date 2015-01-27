/*
 * ccEventDispatcher.cpp
 *
 *  Created on: 17-09-2013
 *      Author: piotr
 */

#include "ccEventDispatcher.h"
#include "ccEvent.h"
namespace ccFramework {

ccEventDispatcher *ccEventDispatcher::instance = NULL;
std::vector<ccEvent *> ccEventDispatcher::events;

ccEventDispatcher::ccEventDispatcher() {
	// TODO Auto-generated constructor stub

}

ccEventDispatcher* ccEventDispatcher::getInstance() {
	if (ccEventDispatcher::instance == NULL) {
		ccEventDispatcher::instance = new ccEventDispatcher;
	}
	return ccEventDispatcher::instance;
}

ccEventDispatcher::~ccEventDispatcher() {
	// TODO Auto-generated destructor stub
}

void ccEventDispatcher::registerEvent(std::string name, void* ptr) {
	ccEvent *e = new ccEvent(name, ptr);
	events.push_back(e);
}

void ccEventDispatcher::notify(std::string name,std::map<std::string, void *> params) {
	  for (std::vector<ccEvent *>::iterator it = events.begin() ; it != events.end(); ++it) {
		  if ((*it)->getName() == name) {
			  (*it)->call(params);
		  }
	  }
//	events[name]->call(params);
}

} /* namespace ccFramework */
