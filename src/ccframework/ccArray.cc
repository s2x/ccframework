/*
 * ccArray.cc
 *
 *  Created on: 20 lis 2014
 *      Author: pha
 */

#include "ccArray.h"

namespace ccFramework {

void ccArray::_setParent(ccArray *parent) {
	this->parent = parent;
}

int ccArray::_string2int(std::string value) {
	int tmp;
	std::istringstream(value) >> tmp;
	return tmp;
}

std::string ccArray::_int2string(int value, std::string format) {
	char buffer[50];
	sprintf(buffer, format.c_str(), value);
	return buffer;
}

ccArray::ccArray() {
	this->isset = false;
	this->last_key_id = 0;
	this->is_array = false;
	this->parent = NULL;
	this->has_valid_childs = false;
}

ccArray::ccArray(std::string name) {
	this->name = name;
	this->isset = false;
	this->last_key_id = 0;
	this->is_array = false;
	this->parent = NULL;
	this->has_valid_childs = false;
}

ccArray::ccArray(const ccArray &b) {
	this->parent = NULL;
	this->isset = b.isset;
	this->last_key_id = b.last_key_id;
	this->is_array = b.is_array;
	this->has_valid_childs = b.has_valid_childs;
	this->name = b.name;
	this->value = b.value;

	//clear childs
	this->childs.clear();
	//copy all childs
	if (b.getType() == TYPE_ARRAY || b.getType() == TYPE_LIST) {
		for (std::vector<ccArray *>::const_iterator it = b.childs.begin();
				it != b.childs.end(); it++) {
				ccArray *tmp = new ccArray();
				*tmp = (**it);
				tmp->_setParent(this);
				this->childs.push_back(tmp);
		}
		//force settings
		this->has_valid_childs = b.has_valid_childs;
		this->is_array = b.is_array;
	}
}

ccArray::~ccArray() {
	//delete all children's
	for (std::vector<ccArray *>::iterator it = childs.begin();
			it != childs.end(); ++it) {
		delete (*it);
	}
}

/**
 * unset one child by key
 */
void ccArray::unset(std::string key) {
	//find key and delete
	for (std::vector<ccArray *>::iterator it = childs.begin();
			it != childs.end();) {
		if ((*it)->getName() == key) {
			it = childs.erase(it);
		} else {
			it++;
		}
	}
}

/**
 * Return all children's
 */
std::vector<ccArray *> ccArray::getChildrens() {
	return this->childs;
}

/**
 * Get parent node
 * Return null if root
 */
ccArray *ccArray::getParent() {
	return this->parent;

}

/**
 * != operator overload
 */
bool ccArray::operator!=(const ccArray &b) const{
	return (*this == b) ? false : true;
}

/**
 * == operator overload
 */
bool ccArray::operator==(const ccArray &b) const{
	//test if type is equal
	if (this->getType() != b.getType())
		return false;

	switch (this->getType()) {
	case TYPE_NOT_SET:
		return true;
		break;
	case TYPE_VALUE:
		//test only the value
		return (this->value == b.value) ? true : false;
		break;
	case TYPE_ARRAY:
	case TYPE_LIST:
		// check if size is the same
		if (this->childs.size() != b.childs.size()) {
			return false;
		}

		//test child's if equal
		for (std::vector<ccArray *>::const_iterator it = childs.begin();
				it != childs.end(); it++) {
			//check if key exists
			if (!(b._hasKey((*it)->getName()))) return false;

			//check if nodes are equal, recurrence
			if (b._getKey((*it)->getName())!= (**it)) return false;
		}

		return true;
		break;
	}
	return false;
}

ccArray &ccArray::operator=(const ccArray &b) {

	//do not copy self
	if (this == &b)
    		return *this;

	//copy some settings
	this->isset = b.isset;
	this->last_key_id = b.last_key_id;
	this->is_array = b.is_array;
	this->has_valid_childs = b.has_valid_childs;
	this->name = b.name;
	this->value = b.value;

	//clear childs
	this->childs.clear();

	//copy all childs
	if (b.getType() == TYPE_ARRAY || b.getType() == TYPE_LIST) {
		for (std::vector<ccArray *>::const_iterator it = b.childs.begin();
				it != b.childs.end(); it++) {
				ccArray *tmp = new ccArray();
				*tmp = (**it);
				tmp->_setParent(this);
				this->childs.push_back(tmp);
		}
		//force settings
		this->has_valid_childs = b.has_valid_childs;
		this->is_array = b.is_array;
	}
	return *this;
}

/**
 * Value assign
 */
ccArray& ccArray::operator=(std::string value) {
	//cleanup some data
	this->isset = true;
	this->childs.clear();
	this->is_array = false;
	this->has_valid_childs = false;
	this->value = value;

	//update parent nodes
	ccArray *tmp = this->parent;
	while (tmp) {
		tmp->isset=true;
		if (tmp->childs.size() > 0) {
			tmp->has_valid_childs = true;
		}
		tmp = tmp->getParent();
	}
	return *this;
}


ccArray& ccArray::operator[](std::string key) {
	for (std::vector<ccArray *>::iterator it = this->childs.begin();
			it != this->childs.end(); ++it) {
		if ((*it)->name == key) {
			return *(*it);
		}
	}
	ccArray *tmp = NULL;

	if (key == "" || key == ccArray::_int2string(ccArray::_string2int(key))) {
		if (key == "")
			key = ccArray::_int2string(this->last_key_id);
		tmp = new ccArray(key);
		if (ccArray::_string2int(key) >= this->last_key_id)
			this->last_key_id = ccArray::_string2int(key) + 1;
	} else {
		//this is not list, this is map!
		// this->is_array = true;
		tmp = new ccArray(key);
	}

	tmp->_setParent(this);
	this->childs.push_back(tmp);
	return *tmp;
}

ccArray::operator std::string() const {
	return this->toString();
}

bool ccArray::_hasKey(std::string key) const {
	if (this->_getKey(key)!=NULL) return true;
	return false;
}

ccArray *ccArray::_getKey(std::string key) const {
	// iterate over all keys
	for (std::vector<ccArray *>::const_iterator it = this->childs.begin();
			it != this->childs.end(); ++it) {
		if ((*it)->name == key) {
			return (*it);
		}
	}
	return NULL;
}

std::ostream& operator<<(std::ostream& os, const ccArray& dt) {
	os << dt.toString();
	return os;
}

ccArray::operator void*() {
	if (isset == true)
		return this;
	//to do cleanup search path
	ccArray *tmp = this;
	while (tmp->parent && tmp->parent->has_valid_childs == false) {
		tmp = tmp->parent;
	}
	tmp->parent->unset(tmp->getName());

	return 0;
}

/**
 * Get node type
 */
int ccArray::getType() const {
	if (this->childs.size() > 0 && this->has_valid_childs) {
		if (this->is_array)
			return TYPE_ARRAY;
		return TYPE_LIST;
	}
	if (this->isset)
		return TYPE_VALUE;
	return TYPE_NOT_SET;
}

/**
 * Return name o this node
 */
std::string ccArray::getName() {
	return this->name;
}

/**
 * Return value of this node as string
 * If array or list return "ARRAY"
 * see toString function
 */
std::string ccArray::getValue() {
	return this->toString();
}

/**
 * Return as string
 */
std::string ccArray::toString() const {
	switch (this->getType()) {
	case TYPE_NOT_SET:
		return "NULL";
		break;
	case TYPE_VALUE:
		return this->value;
		break;
	case TYPE_ARRAY:
		return "Array";
		break;
	case TYPE_LIST:
		return "Array";
		break;
	}
	return "";
}

/**
 * check if node has valid childrens
 */
bool ccArray::hasChildrens() {
	return this->has_valid_childs;
}

/**
 * Append node
 */
ccArray& ccArray::append() {
	ccArray *tmp = new ccArray(ccArray::_int2string(last_key_id));
	this->childs.push_back(tmp);
	this->last_key_id++;
	return *tmp;
}

} /* namespace ccArray */
