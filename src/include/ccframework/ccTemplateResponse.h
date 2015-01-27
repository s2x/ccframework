/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * cc-template.h
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

#ifndef _CC_TEMPLATE_H_
#define _CC_TEMPLATE_H_
#include <iostream>
#include <set>
#include <deque>
#include <ctemplate/template.h>
#include "ccClassDeclarations.h"


namespace ccFramework {
class ccTemplateResponse
{

public:
	ccTemplateResponse(std::string dict_name, std::string template_name);
	~ccTemplateResponse();
	const std::string& getLayout() const;
	void setLayout(const std::string& layout);
	void setParameter(std::string param, std::string val);
	void addCss(std::string uri);
    void addJs(std::string uri, bool footer = false);
	void setTitle(std::string value);
	void setDescription(std::string value);
	void setKeywords(std::string value);
	void addMetatag(std::map<std::string, std::string> params);

	ctemplate::TemplateDictionary *getDict();
	ctemplate::TemplateDictionary *getLayoutDict();
	ccResponse *render();
	void static addDefaultCss(std::string uri);
	void static addDefaultHeadJs(std::string uri);
	void static addDefaultFooterJs(std::string uri);
	std::string getDescription();
	std::string getKeywords();
	std::string getTitle();

protected:
	std::string renderCssList(std::deque<std::string> stylesheets);
	std::string renderJsList(std::deque<std::string> javascripts);
	std::string renderMetaList(std::deque<std::string> javascripts);
	std::deque<std::string> stylesheets;
    std::deque<std::string> javascripts_head;
    std::deque<std::string> javascripts_foot;
	std::deque<std::string> metas;
	static std::deque<std::string> default_stylesheets;
	static std::deque<std::string> default_head_javascripts;
	static std::deque<std::string> default_footer_javascripts;
	std::string layout;
	std::string title;
	std::string keywords;
	std::string description;
	std::string template_name;
	ctemplate::TemplateDictionary *dict;
	ctemplate::TemplateDictionary *layout_dict;
private:

};
}
#endif // _CC_TEMPLATE_H_

