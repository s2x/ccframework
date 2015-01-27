/*
 * baseHelper.cpp
 *
 *  Created on: 4 lut 2014
 *      Author: piotr
 */

#include "ccBaseHelper.h"
#include "ccRequest.h"
#include "ccApp.h"
namespace ccFramework {

ccRequest* ccBaseHelper::getRequest() {
	return ccApp::getInstance()->getRequest();
}

}


