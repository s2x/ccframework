/*
 * ccForm.h
 *
 *  Created on: 28-05-2014
 *      Author: piotr
 */

#ifndef CCFORM_H_
#define CCFORM_H_

#include "ccFramework.h"
namespace ccFramework {
class ccBaseForm {
protected:
	std::string name;
	std::map<std::string,ccBaseFormElement *> elements;
public:
	ccBaseForm(std::string name);
	ccBaseForm *addElement(ccBaseFormElement *element);
	virtual ~ccBaseForm();

	void ExpandTemplate(ctemplate::TemplateDictionary *dict);
};

}
#endif /* CCFORM_H_ */
