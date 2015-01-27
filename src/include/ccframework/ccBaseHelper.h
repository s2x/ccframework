/*
 * baseHelper.h
 *
 *  Created on: 4 lut 2014
 *      Author: piotr
 */

#ifndef BASEHELPER_H_
#define BASEHELPER_H_

#include "ctemplate/template.h"
#include "ccRequest.h"

namespace ccFramework {

class ccBaseHelper : public ctemplate::TemplateHelper {
public:
	ccRequest* getRequest();
};

}
#endif /* BASEHELPER_H_ */
