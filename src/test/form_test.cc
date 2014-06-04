#include "../include/ccframework/ccFramework.h"

using namespace ccFramework;


int main() {
	std::string form_content;
	std::string form_template = "{{form_test_start}}{{form_test_end}}";

	ctemplate::TemplateDictionary dict("test_form");
	ccBaseForm form("test");
	ccFormElementText text("test");
	ccFormElementLabel label("test");

	form.addElement(&text);
	form.ExpandTemplate(&dict);
	ctemplate::StringToTemplateCache("test_form",form_template,ctemplate::DO_NOT_STRIP);
	ctemplate::ExpandTemplate("test_form",ctemplate::DO_NOT_STRIP, &dict, &form_content);
	std::cout<<form_content<<std::endl;

	//printf("default route is: %s", );
	return 0;
	//controller.genUrl("default",{}).c_str()
}
