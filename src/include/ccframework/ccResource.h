/*
 * ccResource.h
 *
 *  Created on: 25-09-2013
 *      Author: piotr
 */

#ifndef CCRESOURCE_H_
#define CCRESOURCE_H_
#include <iostream>

namespace ccFramework {

class ccResource {
	std::string name;
	ccResource *parent;
public:
	ccResource(std::string name, ccResource *parent = NULL);
	virtual ~ccResource();
	ccResource* getParent();
	void setParent(ccResource* parent);
	std::string getName();
};

} /* namespace ccFramework */
#endif /* CCRESOURCE_H_ */
