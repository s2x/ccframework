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
std::deque<std::string> ccTemplateResponse::default_stylesheets;
std::deque<std::string> ccTemplateResponse::default_head_javascripts;
std::deque<std::string> ccTemplateResponse::default_footer_javascripts;

const std::string& ccTemplateResponse::getLayout() const {
	return layout;
}

ccTemplateResponse::ccTemplateResponse(std::string dict_name, std::string template_name) {
	std::string rname = ccApp::getInstance()->getRouter()->getActiveRouteName();

	this->layout = ccApp::getInstance()->getConfigValue("routes."+rname+".layout",ccApp::getInstance()->getConfigValue("templates.default_template","layout.tpl"));
	this->template_name = template_name;
	this->layout_dict = new ctemplate::TemplateDictionary(dict_name);
	this->dict = this->layout_dict->AddIncludeDictionary("RAW_CONTENT");

	//set positioning stuff
	this->description = ccApp::getInstance()->getConfigValue("routes."+rname+".description",ccApp::getInstance()->getConfigValue("templates.default_description",""));
	this->title = ccApp::getInstance()->getConfigValue("routes."+rname+".title",ccApp::getInstance()->getConfigValue("templates.default_title",""));
	this->keywords = ccApp::getInstance()->getConfigValue("routes."+rname+".keywords",ccApp::getInstance()->getConfigValue("templates.default_keywords",""));
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

	//prepare some defult metas
	this->addMetatag({std::make_pair("name","description"), std::make_pair("content",this->description)});
	this->addMetatag({std::make_pair("name","keywords"), std::make_pair("content",this->keywords)});

	//Set javascripts and css
	this->layout_dict->SetValue("HEAD_STYLES",this->renderCssList(ccTemplateResponse::default_stylesheets) + this->renderCssList(this->stylesheets));
	this->layout_dict->SetValue("HEAD_JAVASCRIPTS",this->renderJsList(ccTemplateResponse::default_head_javascripts) + this->renderJsList(this->javascripts_head));
	this->layout_dict->SetValue("FOOTER_JAVASCRIPTS",this->renderJsList(ccTemplateResponse::default_footer_javascripts) + this->renderJsList(this->javascripts_foot));
	this->layout_dict->SetValue("HEAD_METAS",this->renderMetaList(this->metas));
	this->layout_dict->SetValue("HEAD_TITLE", ccCommon::htmlTag("title",this->title));

	//Set template file
	this->dict->SetFilename(template_name);

	// dispatcher before render
	ccFramework::ccEventDispatcher::notify("ccTemplate.beforeRenderLayout",{std::make_pair("template", (void *)this)});

	// render a template
	ctemplate::ExpandTemplate(this->layout, ctemplate::DO_NOT_STRIP, this->layout_dict, &r_content);
	return new ccResponse(r_content);
}
std::string ccTemplateResponse::renderCssList(std::deque<std::string> stylesheets) {
	std::string ret="";
	for(std::deque<std::string>::iterator i = stylesheets.begin(); i != stylesheets.end(); ++i) {
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

std::string ccTemplateResponse::renderJsList(std::deque<std::string> javascripts) {
	std::string ret="";
	for(std::deque<std::string>::iterator i = javascripts.begin(); i != javascripts.end(); ++i) {
		ret = ret + "<script src=\""+(*i)+"\"></script>\n";
	}
	return ret;
}

void ccTemplateResponse::addDefaultCss(std::string uri) {
	ccTemplateResponse::default_stylesheets.push_back(uri);
}
void ccTemplateResponse::addDefaultHeadJs(std::string uri) {
	ccTemplateResponse::default_head_javascripts.push_back(uri);
}

void ccTemplateResponse::addDefaultFooterJs(std::string uri) {
	ccTemplateResponse::default_footer_javascripts.push_back(uri);
}

std::string ccTemplateResponse::getDescription(){
	return description;
}

std::string ccTemplateResponse::getKeywords(){
	return keywords;
}

void ccTemplateResponse::setTitle(std::string value) {
	this->title = value;
}

void ccTemplateResponse::setDescription(std::string value) {
	this->description = value;
}

void ccTemplateResponse::setKeywords(std::string value) {
	this->keywords = value;
}

void ccTemplateResponse::addMetatag(std::map<std::string, std::string> params) {
	this->metas.push_back(ccCommon::htmlTag("meta","",params));
}

std::string ccTemplateResponse::getTitle(){
	return title;
}

std::string ccTemplateResponse::renderMetaList(
		std::deque<std::string> javascripts) {
	std::string ret="";
	for(std::deque<std::string>::iterator i = metas.begin(); i != metas.end(); ++i) {
		ret += (*i)+"\n";
	}
	return ret;
}

void ccTemplateResponse::addJs(std::string uri, bool footer) {
    if (footer) this->javascripts_foot.push_back(uri);
    else this->javascripts_head.push_back(uri);
}

void ccTemplateResponse::addCss(std::string uri) {
	this->stylesheets.push_back(uri);
}

}

