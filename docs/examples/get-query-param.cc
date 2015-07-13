/*
 ============================================================================
 Name        : get-query-param.cc
 Author      : Piotr Hałas
 Version     :
 Copyright   : 
 Description : Hello World in ccFramework,
 Compile     : g++ get-query-param.cc -std=c++11 `pkg-config --cflags --libs ccframework` -lfcgi++ -lfcgi  -o get-query-param.fcgi
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
        //creates new response with Hello world message

        //check if request has name parameter
        if (request->hasRequestParameter("name")) {

            //get name parameter from request
            string name = request->getRequestParameter("name");

            //name empty, so you are anonymous
            if (name == "") name = "anonymous";

            return (new ccResponse("Hello " + name));
        }

        //Redirect to name parameter
        return this->redirect("?name=", "301");


    }

    // registerRoutes is called by ccApp 
    void registerRoutes() {
        //register route
        this->getRouter()->addRoute(
                // create new static route
                new ccStaticRoute("index", "/",

                        //macro for easy creating new functor
                                  create_routing_functor(ExampleController, indexAction)));
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
