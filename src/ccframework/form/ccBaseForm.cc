/*
 * ccForm.cc
 *
 *  Created on: 28-05-2014
 *      Author: piotr
 */

#include "ccBaseForm.h"
#include "ccBaseFormElement.h"
#include "ccFormElementFormStart.h"
namespace ccFramework {

ccBaseForm::ccBaseForm(std::string name) {
	// TODO Auto-generated constructor stub
	this->name = name;
}

ccBaseForm::~ccBaseForm() {
	// TODO Auto-generated destructor stub
}

ccBaseForm* ccFramework::ccBaseForm::addElement(ccBaseFormElement* element) {
	this->elements[element->getName()] = element;
	return this;
}

void ccBaseForm::ExpandTemplate(ctemplate::TemplateDictionary* dict) {
	ccFormElementFormStart form_start("form");
	form_start.setAttribute("method","post")->setAttribute("action","");
	dict->SetValue("form_"+name+"_start", form_start.render());
	dict->SetValue("form_"+name+"_end", "</form>");
}

}
