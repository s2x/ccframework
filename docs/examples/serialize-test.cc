/*
 ============================================================================
 Name        : serialize-test.cc
 Author      : Piotr Hałas
 Version     :
 Copyright   : 
 Description : Hello World in ccFramework,
 Compile     : g++ serialize-test.cc -std=c++11 `pkg-config --cflags --libs ccframework` -o serialize-test.fcgi
 ============================================================================
 */

#include "ccFramework.h"

using namespace std;
using namespace ccFramework;

// controlller class
class ExampleController : public ccController {
public:
    //custom constructor is needed
    ExampleController(ccApp *app) : ccController(app) { };

    //very simple controller, just print hello world
    ccResponse *indexAction(ccRequest *request) {
        return (new ccResponse("To test serializers go to /xml?test=xml or /json?test=json"));

    }

    //very simple controller, just print json data
    ccResponse *jsonAction(ccRequest *request) {
        return (new ccJsonResponse(request->getRequestParamters()));

    }

    //very simple controller, just print xml data
    ccResponse *xmlAction(ccRequest *request) {
        return (new ccResponse("To test serializers go to /xml?test=xml or /json?test=json"));

    }

    // registerRoutes is called by ccApp 
    void registerRoutes() {
        //register route
        this->getRouter()->addRoute(
                // create new static route
                new ccStaticRoute("index", "/",

                        //macro for easy creating new functor
                                  create_routing_functor(ExampleController, indexAction)));

        this->getRouter()->addRoute(
                // create new static route
                new ccStaticRoute("json", "/json",

                        //macro for easy creating new functor
                                  create_routing_functor(ExampleController, jsonAction)));

        this->getRouter()->addRoute(
                // create new static route
                new ccStaticRoute("xml", "/xml",

                        //macro for easy creating new functor
                                  create_routing_functor(ExampleController, xmlAction)));
    }
};

int main(void) {
    //initailise main app, set the config file
    ccApp app("../config.yml");

    //register example controller 
    app.registerController("example", new ExampleController(&app));

    //main loop. Wait for connection
    app.run();

    return 0;
}
