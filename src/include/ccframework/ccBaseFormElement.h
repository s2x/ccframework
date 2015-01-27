/*
 * ccBaseFormElement.h
 *
 *  Created on: 7 maj 2014
 *      Author: piotr
 */

#ifndef CCBASEFORMELEMENT_H_
#define CCBASEFORMELEMENT_H_
#include "ctemplate/template.h"
namespace ccFramework {

class ccBaseFormElement {
protected:
	std::map<std::string, std::string> attributes;

	std::string name;
	std::string template_file = "";
	std::string content = "<{{TAG_NAME}}{{#ATTRIBUTES}} {{ATTR_NAME}}=\"{{ATTR_VALUE}}\"{{/ATTRIBUTES}}>{{VALUE}}{{#END_TAG}}</{{TAG_NAME}}>{{/END_TAG}}";
	std::string tag_name;
	std::string tag_value;
	bool has_tag_value = false;
	ctemplate::TemplateDictionary *dict;
public:
	ccBaseFormElement(std::string name);
	virtual ~ccBaseFormElement();
	//getters and setters
	virtual std::string getContent();
	virtual ccBaseFormElement* setContent(const std::string& content);
	virtual std::string render();

	ccBaseFormElement *setAttribute(std::string name, std::string value = "");
	virtual std::string getTemplateFile();
	virtual void setTemplateFile(std::string templateFile);
	const std::string& getName() const;
};

} /* namespace ccFramework */

#endif /* CCBASEFORMELEMENT_H_ */
