/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * cc-template.cc
 * Copyright (C) 2013 Piotr Ha??as <piotr@piotr-server>
 *
 * ccframework is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * ccframework is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "ccframework/ccFramework.h"

namespace ccFramework {
std::set<std::string> ccTemplateResponse::default_stylesheets;
std::set<std::string> ccTemplateResponse::default_head_javascripts;
std::set<std::string> ccTemplateResponse::default_footer_javascripts;

const std::string& ccTemplateResponse::getLayout() const {
	return layout;
}

ccTemplateResponse::ccTemplateResponse(std::string dict_name, std::string template_name) {
	this->layout = "layout.tpl";
	this->template_name = template_name;
	this->layout_dict = new ctemplate::TemplateDictionary(dict_name);
	this->dict = this->layout_dict->AddIncludeDictionary("RAW_CONTENT");
}

ccTemplateResponse::~ccTemplateResponse() {
	delete this->layout_dict;
}


void ccTemplateResponse::setLayout(const std::string& layout) {
	this->layout = layout;
}

void ccTemplateResponse::setParameter(std::string param, std::string val) {
	this->dict->SetValue(param,val);
}

ccResponse* ccTemplateResponse::render() {
	std::string r_content;

	//Set javascripts and css
	this->layout_dict->SetValue("HEAD_STYLES",this->renderCssList(ccTemplateResponse::default_stylesheets));
	this->layout_dict->SetValue("HEAD_JAVASCRIPTS",this->renderJsList(ccTemplateResponse::default_head_javascripts));
	this->layout_dict->SetValue("FOOTER_JAVASCRIPTS",this->renderJsList(ccTemplateResponse::default_footer_javascripts));

	//Set template file
	this->dict->SetFilename(template_name);
	
	std::map<std::string, void *> tmp;
	tmp["template"] = (void *)this;
	ccFramework::ccEventDispatcher::notify("ccTemplate.beforeRenderLayout",tmp);

	ctemplate::ExpandTemplate(this->layout, ctemplate::DO_NOT_STRIP, this->layout_dict, &r_content);
	return new ccResponse(r_content);
}
std::string ccTemplateResponse::renderCssList(std::set<std::string> stylesheets) {
	std::string ret="";
	for(std::set<std::string>::iterator i = stylesheets.begin(); i != stylesheets.end(); ++i) {
		ret = ret + "<link href=\""+(*i)+"\" rel=\"stylesheet\">\n";
	}
	return ret;
}

ctemplate::TemplateDictionary* ccTemplateResponse::getDict() {
	return this->dict;

}

ctemplate::TemplateDictionary* ccTemplateResponse::getLayoutDict() {
	return this->layout_dict;
}

std::string ccTemplateResponse::renderJsList(std::set<std::string> javascripts) {
	std::string ret="";
	for(std::set<std::string>::iterator i = javascripts.begin(); i != javascripts.end(); ++i) {
		ret = ret + "<script src=\""+(*i)+"\"></script>\n";
	}
	return ret;
}

void ccTemplateResponse::addDefaultCss(std::string uri) {
	ccTemplateResponse::default_stylesheets.insert(uri);
}
void ccTemplateResponse::addDefaultHeadJs(std::string uri) {
	ccTemplateResponse::default_head_javascripts.insert(uri);
}

void ccTemplateResponse::addDefaultFooterJs(std::string uri) {
	ccTemplateResponse::default_footer_javascripts.insert(uri);
}

}
