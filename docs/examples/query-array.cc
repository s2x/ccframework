/*
 ============================================================================
 Name        : query-array.cc
 Author      : Piotr Hałas
 Version     :
 Copyright   : 
 Description : Hello World in ccFramework,
 Compile     : g++ query-array.cc -std=c++11 `pkg-config --cflags --libs ccframework` -o query-array.fcgi
 ============================================================================
 */

#include "ccFramework.h"

using namespace std;
using namespace ccFramework;


void ccArray_get_leafs(ccArray *root, std::vector<ccArray *> *leafs) {

    if (root->hasChildrens()) {
        std::vector<ccArray *> tmp = root->getChildrens();
        for (std::vector<ccArray *>::iterator it = tmp.begin(); it != tmp.end();
             ++it) {

            ccArray_get_leafs((*it), leafs);
        }

    } else {

        leafs->push_back(root);
    }
}

std::string build_list(ccArray *root) {
    std::vector<ccArray *> leafs;

    ccArray_get_leafs(root, &leafs);
    std::string query = "";

    for (std::vector<ccArray *>::iterator it = leafs.begin(); it != leafs.end();
         ++it) {
        std::string name = "";
        std::string last_name = (*it)->getName();
        ccArray *parent = (*it);
        while (parent->getParent()->getParent()) {
            name = "[" + parent->getName() + "]" + name;
            last_name = parent->getName();
            parent = parent->getParent();
        }
        query += parent->getName() + name + "=" + (*it)->getValue();

        if ((it + 1) != leafs.end())
            query += "\n";
    }
    return query;
}

// controlller class 
class ExampleController : public ccController {
public:
    //custom constructor is needed
    ExampleController(ccApp *app) : ccController(app) { };

    //very simple controller, just print hello world
    ccResponse *indexAction(ccRequest *request) {
        //creates new response with Hello world message

        ccArray params = request->getRequestParamters();

        std::string resp = "Request params: <pre>";

        resp+= build_list(&params);

        resp += "</pre>";
        return (new ccResponse(resp));

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
