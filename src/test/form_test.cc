#include "../include/ccframework/ccFramework.h"

using namespace ccFramework;


int main() {
	ccFormElementText text("test");
	ccFormElementLabel label("test");

	printf("Render simple input type: %s\n",text.render().c_str());
	printf("Render simple input type: %s\n",label.render().c_str());
	//printf("default route is: %s", );
	return 0;
	//controller.genUrl("default",{}).c_str()
}
