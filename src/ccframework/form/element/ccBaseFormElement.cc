/*
 * ccBaseFormElement.cpp
 *
 *  Created on: 7 maj 2014
 *      Author: piotr
 */

#include "ccframework/ccFramework.h"

namespace ccFramework {

ccBaseFormElement::ccBaseFormElement(std::string name) {
	// TODO Auto-generated constructor stub
	this->name = name;
	this->dict = NULL;
}

ccBaseFormElement::~ccBaseFormElement() {
	// TODO Auto-generated destructor stub
}

std::string ccBaseFormElement::render() {
	std::string ret;
	this->dict = new ctemplate::TemplateDictionary("Form_element_"+this->name);
	printf("tmpfile: %s\n",this->getTemplateFile().c_str());
	ctemplate::StringToTemplateCache(this->template_file,this->getContent(),ctemplate::DO_NOT_STRIP);

	this->dict->SetValue("TAG_NAME",this->tag_name);
	if (this->has_tag_value) {
		this->dict->ShowSection("END_TAG");
		this->dict->SetValue("TAG_VALUE",this->tag_value);
	}

	std::map<std::string,std::string>::iterator it;
	for (it = this->attributes.begin(); it!=this->attributes.end(); it++) {
		ctemplate::TemplateDictionary *item = this->dict->AddSectionDictionary("ATTRIBUTES");
		item->SetValue("ATTR_NAME",it->first);
		item->SetValue("ATTR_VALUE",it->second);
	}

	ctemplate::ExpandTemplate(this->template_file, ctemplate::DO_NOT_STRIP, this->dict,&ret);
	return ret;
}

void ccBaseFormElement::setAttribute(std::string name, std::string value) {
	this->attributes[name] = value;
}

std::string ccBaseFormElement::getTemplateFile() {
	return template_file;
}

void ccBaseFormElement::setTemplateFile( std::string templateFile) {
	template_file = templateFile;
}

} /* namespace ccFramework */

std::string ccFramework::ccBaseFormElement::getContent(){
	return this->content;
}

std::string ccFramework::ccBaseFormElement::getDefaultContent() {
	return "";
}

void ccFramework::ccBaseFormElement::setContent(const std::string& content) {
	this->content = content;
}


