/*
 * ccArray.h
 *
 *  Created on: 30-07-2014
 *      Author: piotr
 */

#ifndef CCARRAY_H_
#define CCARRAY_H_

#include <iostream>
#include <sstream>
#include <vector>
#include <stdio.h>
namespace ccFramework {
class ccArray {
private:
	bool isset;
        bool isarray;
	std::string value;
	std::string name;
	std::vector<ccArray *> childs;
	int last_key_id;
	ccArray *parent;


	static std::string int2string(int value, std::string format="%d") {
		char buffer [50];
		sprintf (buffer, format.c_str() ,value);
		return buffer;
	}

	static int string2int(std::string value) {
		int tmp;
		std::istringstream ( value ) >> tmp;
		return tmp;
	}
public:
 	ccArray() {this->isset = false; this->parent = NULL; this->last_key_id =0; this->isarray=false;}
        ccArray(std::string name) {this->name = name;this->isset = false; this->parent = NULL; this->last_key_id =0; this->isarray = false;}
	~ccArray() {
		for (std::vector<ccArray *>::iterator it = childs.begin() ; it != childs.end(); ++it) {
      			delete (*it);
		}
	}

	void unset(std::string key) {
		for (std::vector<ccArray *>::iterator it = childs.begin() ; it != childs.end(); ++it) {
			if ((*it)->getName() == key) {
        	 		childs.erase(it);
 			}
		}
	}

	void setValue(std::string value) {
		this->childs.clear();
		this->last_key_id = 0;
		this->value = value;
		this->isset = true;
		this->isarray = false;
	}

	bool isNULL() {
		return this->isset;
	}

	bool isArray() {
		return this->isarray;
	}

	int count(std::string name) {
		int count = 0;
		for (std::vector<ccArray *>::iterator it = this->childs.begin() ; it != this->childs.end(); ++it) {
				      if ((*it)->name == name) {
				        count++;
				      }
		}
		return count;
	}

	std::string getValue() {
		if (this->childs.size() && this->isarray) return "ARRAY";
		if (!this->isset) return "NULL";
		return this->value;
	}

	std::string getName() {
		return this->name;
	}


	ccArray *getParent() {
		return this->parent;
	}


	std::vector<ccArray *> getChildrens() {
	    return this->childs;
	}
    
    bool hasChild(std::string) {
        for (std::vector<ccArray *>::iterator it = this->childs.begin() ; it != this->childs.end(); ++it) {
				      if ((*it)->name == name) {
		        return true;
		      }
		}
        return false;
    }

	bool hasChildrens() {
		return this->isarray;
	}

	ccArray *addChild(std::string name="") {
		if (name == ccArray::int2string(ccArray::string2int(name))) {
          		this->last_key_id = ccArray::string2int(name)+1;
		}
		if (name == "") {
			name = ccArray::int2string(this->last_key_id);
		}

        //unset child node if value and set array
        if (this->hasChild(name) && !this->getChild(name)->hasChildrens()) {
            std::string curr_val = this->getChild(name)->getValue();
            this->unset(name);
            ccArray *current = new ccArray(name);
            current->setValue(curr_val);
            this->childs.push_back(current);
        }
        
		ccArray *tmp = new ccArray(name);
		tmp->parent = this;
		this->childs.push_back(tmp);
		this->isset = true;
		this->isarray = true;
		return tmp;
	}

	ccArray *getChild(std::string name) {
		for (std::vector<ccArray *>::iterator it = this->childs.begin() ; it != this->childs.end(); ++it) {
		      if ((*it)->name == name) {
		        return (*it);
		      }
		}
		return this->addChild(name);
	}
};

void array_get_leafs(ccArray *root, std::vector<ccArray *> *leafs);

}


#endif /* CCARRAY_H_ */
