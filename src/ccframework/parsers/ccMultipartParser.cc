/*
 * ccMultipartParser.cc
 *
 *  Created on: 24-10-2013
 *      Author: piotr
 */

#include "ccframework/ccFramework.h"

namespace ccFramework {

ccMultipartParser::ccMultipartParser(std::string query, std::string sep) {
	this->QueryElemets = new ccArray();
	// TODO Auto-generated constructor stub
	std::string real_sep = "--"+sep;
	long pos = 0;
	long endpos = 0;
	long endofdata = query.find((real_sep+"--"),0);
	pos = query.find(real_sep,endpos);
	endpos =query.find(real_sep,pos+1);

	while (pos != std::string::npos && pos !=endofdata) {
		std::string part = query.substr((pos+real_sep.length()), (endpos-pos-real_sep.length()));
		this->parsePart(part);
		pos = query.find(real_sep,endpos);
		endpos =query.find(real_sep,pos+1);
	}

}

void ccMultipartParser::parsePart(std::string part) {
	  char delims = '\n';
	  std::stringstream ss(ccCommon::trim(part));
	  std::string to;
	  std::string value = "";
	  std::string name = "";
	  if (part != "")
	  {
		bool data_section = false;
	    while(std::getline(ss,to,'\n')){
	    	if (data_section) {
	    		//add to value
	    		value+=to;
	    	}
	    	else {
	    		if (to.find("Content-Disposition: form-data;")!=std::string::npos) {
	    			//field description
	    			int name_pos = to.find(" name=\"");
	    			int name_end_pos = to.find("\"",name_pos+7);
	    			if (name_pos!=std::string::npos && name_end_pos!=std::string::npos) {
	    				name = to.substr(name_pos+7, name_end_pos-name_pos-7);
	    			}
	    		}
	    	}
	    	if (data_section == false && ccCommon::trim(to).length()==0) data_section = true;
	    }
	    if (ccCommon::trim(name)!= "") {
            this->QueryElemets->getChild(ccCommon::trim(name))->setValue(value);
        }
	  }
}

ccMultipartParser::~ccMultipartParser() {
	// TODO Auto-generated destructor stub
}

} /* namespace ccFramework */
