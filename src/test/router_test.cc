#include "../include/ccframework/ccFramework.h"

using namespace ccFramework;

ccApp app("");

ccController controller(&app);

int test_createRoute() {
	app.getRouter()->addRoute(
				new ccRoute("default", "/default",
						new ccSpecificRouterFunctor<ccController>(NULL,	NULL)));
	app.getRouter()->addRoute(
				new ccRoute("default2", "/default2",
						new ccSpecificRouterFunctor<ccController>(NULL,	NULL)));

	if (app.getRouter()->getRoute("default")!= NULL) return 1;
	return 0;
}

int test_genUrl() {
	std::string url = app.getRouter()->getRoute("default")->getUrl("").c_str();

	if (url == "/default") return 1;
	return 0;
}

int main() {
	if (test_createRoute()) {
		printf("Test create route: OK\n");
		if (test_genUrl()) printf("Test get url: OK\n");
	}
	printf("default route is: %s\n", controller.genUrl("default",{}).c_str());
	printf("default route is: %s\n", controller.genUrl("default2",{}).c_str());
	printf("default route is: %s\n", controller.genUrl("default",{}).c_str());
	printf("default route is: %s\n", controller.genUrl("default",{}).c_str());
	printf("default route is: %s\n", controller.genUrl("default",{}).c_str());
	printf("default route is: %s\n", controller.genUrl("default",{}).c_str());
	//printf("default route is: %s", );
	return 0;
	//controller.genUrl("default",{}).c_str()
}
