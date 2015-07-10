/*
 * ccArray.h
 *
 *  Created on: 20 lis 2014
 *      Author: pha
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
	/**
	 * Value of node
	 */
	std::string value;

	/**
	 * Node name
	 */
	std::string name;

	/**
	 * Vector of node childs
	 */
	std::vector<ccArray *> childs;

	/**
	 * is node set (not null)
	 */
	bool isset;

	/**
	 * is node array (not value, not list)
	 */
	bool is_array;

	/**
	 * has node childs
	 */
	bool has_valid_childs;

	/**
	 * last inserted key, for list node
	 */
	int last_key_id;

	/**
	 * pointer to parent node
	 */
	ccArray *parent;


	void _setParent(ccArray *parent);
	//internal function for checking if key exists
	bool _hasKey(std::string key) const;
	ccArray *_getKey(std::string key) const;

	/**
	 * Internal functions for key autoincrement
	 */
	static int _string2int(std::string value);
	static std::string _int2string(int value, std::string format = "%d");
public:
	/**
	 * Node types
	 */
	static const int TYPE_NOT_SET = 0;
	static const int TYPE_VALUE = 1;
	static const int TYPE_ARRAY = 2;
	static const int TYPE_LIST = 3;

	std::string getName();
	std::string getValue();

	//Constructors
	ccArray();
	ccArray(std::string name);
	//Copy constructor
	ccArray(const ccArray &b);

	/**
	 * Custom Destructor
	 */
	~ccArray();

	/**
	 * unset one child by key
	 */
	void unset(std::string key);

	/**
	 * Return all children's
	 */
	std::vector<ccArray *> getChildrens();

	/**
	 * Get parent node
	 * Return null if root
	 */
	ccArray *getParent();

	/**
	 * Get node type
	 */
	int getType() const;

	/**
	 * operators overload
	 */
	bool operator!=(const ccArray &b) const;
	bool operator==(const ccArray &b) const;
	ccArray &operator=(const ccArray &b);
	ccArray &operator=(std::string value);
	ccArray &operator[](std::string key);
	operator std::string() const;
	operator void*();
	friend std::ostream& operator<<(std::ostream& os, const ccArray& dt);


	/**
	 * Return as string
	 */
	std::string toString() const;

	/**
	 * check if node has valid childrens
	 */
	bool hasChildrens();

	/**
	 * Append node
	 */
	ccArray& append();

};


} /* namespace ccArray */

#endif /* CCARRAY_H_ */
