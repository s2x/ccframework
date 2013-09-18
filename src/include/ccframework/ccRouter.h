/*
 * ccRouter.h
 *
 *  Created on: 30-07-2013
 *      Author: piotr
 */

#ifndef CCROUTER_H_
#define CCROUTER_H_
#include <iostream>
#include <map>
#include "ccFramework.h"

namespace ccFramework {

class ccRouterFunctor
{
public:

   // two possible functions to call member function. virtual cause derived
   // classes will use a pointer to an object and a pointer to a member function
   // to make the function call
   virtual ccResponse *operator()(ccRequest* request)=0;  // call using operator
   virtual ccResponse *Call(ccRequest* request)=0;        // call using function
   virtual ccController *getController()=0; 
   virtual ~ccRouterFunctor(){};
};


// derived template class
template <class TClass> class ccSpecificRouterFunctor : public ccRouterFunctor
{
private:
	  ccResponse * (TClass::*fpt)(ccRequest*);   // pointer to member function
   TClass* pt2Object;                  // pointer to object

public:

   // constructor - takes pointer to an object and pointer to a member and stores
   // them in two private variables
   ccSpecificRouterFunctor(TClass* _pt2Object, ccResponse *(TClass::*_fpt)(ccRequest*))
      { pt2Object = _pt2Object;  fpt=_fpt; };

   // override operator "()"
   virtual ccResponse *operator()(ccRequest* request)
    { return (*pt2Object.*fpt)(request);};              // execute member function

   // override function "Call"
   virtual ccResponse *Call(ccRequest* request)
     { return (*pt2Object.*fpt)(request);};             // execute member function
	 
   virtual ccController *getController() {
	return (pt2Object);
   }

   virtual ~ccSpecificRouterFunctor(){

   }
};

class ccRouter {
	std::map<std::string,ccRouterFunctor *> functors;
	ccRouteMatcher *route_matcher;
	std::string active_route;
public:
	ccRouter();
	virtual ~ccRouter();
	void addRoute(std::string name, ccRouterFunctor *functor);
	void addRoute(std::string name, std::string pattern, ccRouterFunctor *functor);
	ccRouterFunctor *getRoute(ccRequest *request);
	ccRouterFunctor *getRoute(std::string route_name);

	const std::string& getActiveRoute() const {
		return active_route;
	}
};

} /* namespace ccFramework */
#endif /* CCROUTER_H_ */
