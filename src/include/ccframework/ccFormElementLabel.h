/*
 * ccFormElementLabel.h
 *
 *  Created on: 28-05-2014
 *      Author: piotr
 */

#ifndef CCFORMELEMENTLABEL_H_
#define CCFORMELEMENTLABEL_H_

#include "ccBaseFormElement.h"

namespace ccFramework {

class ccFormElementLabel: public ccBaseFormElement {
public:
	ccFormElementLabel(std::string name): ccBaseFormElement(name){
		tag_name = "label";
		has_tag_value = true;
		tag_value = "";
		this->setAttribute("for",name);
	}
};

} /* namespace ccFramework */

#endif /* CCFORMELEMENTLABEL_H_ */
