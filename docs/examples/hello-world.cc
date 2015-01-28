/*
 ============================================================================
 Name        : hello-world.cc
 Author      : Piotr Hałas
 Version     :
 Copyright   : 
 Description : Hello World in ccFramework,
 Compile     : g++ hello-world.cc -std=c++11 `pkg-config --cflags --libs ccframework` -lfcgi++ -lfcgi  -o hello-world.fcgi
 ============================================================================
 */

#include "ccFramework.h"

using namespace std;
using namespace ccFramework;


// controlller class 
class ExampleController: public ccController {
public:
    //custom constructor is needed
    ExampleController(ccApp *app): ccController(app) {};
    
    //very simple controller, just print hello world
    ccResponse *indexAction(ccRequest *request) {
        //creates new response with Hello world message
        return (new ccResponse("Hello world!!!"));
    }
    
    // registerRoutes is called by ccApp 
    void registerRoutes() {
        //register route
        this->getRouter()->addRoute(
                // create new static route
                new ccStaticRoute("index", "/", 
                
                    //macro for easy creating new functor
                    create_routing_functor(ExampleController,indexAction)));
    }
};

int main(void) {
    //initailise main app, set the config file
    ccApp app("../config.yml");

    //register example controller 
    app.registerController("example",new ExampleController(&app));
    
    //main loop. Wait for connection
    app.run();

    return 0;
}
