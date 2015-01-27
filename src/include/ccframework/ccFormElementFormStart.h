/*
 * ccFormElementText.h
 *
 *  Created on: 28-05-2014
 *      Author: piotr
 */

#ifndef CCFORMELEMENTFROMSTART_H_
#define CCFORMELEMENTFROMSTART_H_

namespace ccFramework {

class ccFormElementFormStart: public ccBaseFormElement {
public:
	ccFormElementFormStart(std::string name): ccBaseFormElement(name){
		template_file = "form/element/formstart.html";
		tag_name = "form";
	};
};

} /* namespace ccFramework */

#endif /* CCFORMELEMENTFROMSTART_H_ */
