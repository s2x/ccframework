/*
 * ccEvent.h
 *
 *  Created on: 17-09-2013
 *      Author: piotr
 */

#ifndef CCEVENT_H_
#define CCEVENT_H_

#include <map>
#include <iostream>
namespace ccFramework {

class ccEvent {
	std::string name;
	void *(*func_poiner)(std::map<std::string, void *>);
public:
	ccEvent(std::string name, void *ptr);
	virtual ~ccEvent();
	void call(std::map<std::string, void *>);
	std::string getName();
};

} /* namespace ccFramework */
#endif /* CCEVENT_H_ */
