/*
 * ccFormElementText.h
 *
 *  Created on: 28-05-2014
 *      Author: piotr
 */

#ifndef CCFORMELEMENTTEXT_H_
#define CCFORMELEMENTTEXT_H_

namespace ccFramework {

class ccFormElementText: public ccBaseFormElement {
public:
	ccFormElementText(std::string name): ccBaseFormElement(name){
		template_file = "form/element/text.html";
		tag_name = "input";
		this->setAttribute("id",name);
		this->setAttribute("name",name);
		this->setAttribute("type","text");
		this->setAttribute("value","");
	};
};

} /* namespace ccFramework */

#endif /* CCFORMELEMENTTEXT_H_ */
