/*
 ============================================================================
 Name        : hello-world.cc
 Author      : Piotr Hałas
 Version     :
 Copyright   : 
 Description : Hello World in ccFramework,
 Compile     : g++ server-example.cc `pkg-config --cflags --libs ccframework` -o server-example.fcgi
 ============================================================================
 */

#include "ccFramework.h"

#include<iostream>
#include<ctime>

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
        string text = "Seconds since the Epoch: "+ccCommon::int2string(std::time(0));
        return (new ccResponse(text));
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

    PreforkServer server(&app);
    server.setMaxSpare(1);
    int sockfd = FCGX_OpenSocket("/tmp/myfcgiserver.sock", 1024);
    server.run(sockfd, false);
    return 0;
}
