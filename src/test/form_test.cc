#include "../include/ccframework/ccFramework.h"

using namespace ccFramework;

void node_get_leafs(ccArray *root, std::vector<ccArray *> *leafs) {

  if (root->hasChildrens()) {
    std::vector<ccArray *> tmp = root->getChildrens();
		for (std::vector<ccArray *>::iterator it = tmp.begin(); it != tmp.end();
				++it) {
			node_get_leafs((*it), leafs);
		}

  } else {
    leafs->push_back(root);
  }
}

std::string build_http_query(ccArray *root) {
  std::vector<ccArray *> leafs;

  node_get_leafs(root, &leafs);
  std::string query = "";

  for (std::vector<ccArray *>::iterator it = leafs.begin() ; it != leafs.end(); ++it) {
    std::string name = "";
    std::string last_name = (*it)->getName();
    ccArray *parent = (*it)->getParent();
    while (parent->getParent()) {
      name = "["+parent->getName()+"]"+name;
      last_name = parent->getName();
      parent= parent->getParent();
    }
    last_name += name;
    query += last_name+"="+(*it)->getValue();

    if ((it+1) != leafs.end()) query +="&";
  }
  return query;
}

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

	ccQueryParser qb("dapa=dupa&dapa=32&chuj=323");
	ccArray *cc = qb.getAllParameters();
//	ccArray *cc = new ccArray();
//	cc->append() = "dupa";
//	cc->append() = "dupa";
	std::cout<<build_http_query(cc)<<std::endl;

	std::vector<ccArray *> leafs;
	node_get_leafs(cc,&leafs);
	for (std::vector<ccArray *>::iterator it = leafs.begin() ; it != leafs.end(); ++it) {
	      std::cout<<"["<<(*it)->getName()<<"] = "<<(*it)->getValue()<<std::endl;
	}

	//printf("default route is: %s", );
	return 0;
	//controller.genUrl("default",{}).c_str()
}
