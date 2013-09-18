/*
 * ccEventDispatcher.h
 *
 *  Created on: 17-09-2013
 *      Author: piotr
 */

#ifndef CCEVENTDISPATCHER_H_
#define CCEVENTDISPATCHER_H_

namespace ccFramework {
void *event_func_template (void *name, ...);

class ccEventDispatcher {
	static std::vector<ccEvent *> events;
	static ccEventDispatcher *instance;

public:
	ccEventDispatcher();
	virtual ~ccEventDispatcher();
	static ccEventDispatcher *getInstance();
	static void registerEvent(std::string name, void *ptr);
	static void notify(std::string name, std::map<std::string, void *> params);
};

} /* namespace ccFramework */
#endif /* CCEVENTDISPATCHER_H_ */
