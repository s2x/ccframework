/*
 * ccForm.h
 *
 *  Created on: 28-05-2014
 *      Author: piotr
 */

#ifndef CCFORM_H_
#define CCFORM_H_

#include "ccFramework.h"

class ccBaseForm {
protected:
	std::string name;
public:
	ccBaseForm(std::string name);
	virtual ~ccBaseForm();
};

#endif /* CCFORM_H_ */
