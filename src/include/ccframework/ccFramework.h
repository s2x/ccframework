#ifndef CCFRAMEWORK_H_
#define CCFRAMEWORK_H_

//routing functor
#define create_routing_functor(class_name, function_name) new ccSpecificRouterFunctor< class_name >(this, &class_name::function_name)

#include <iostream>
#include <fstream>
#include "yaml-cpp/yaml.h"

#include "ccPreforkServer.h"
#include "ccHttpCodes.h"
#include "ccAcl.h"
#include "ccApp.h"
#include "ccBaseFormElement.h"
#include "ccBaseForm.h"
#include "ccBaseHelper.h"
#include "ccCommon.h"
#include "ccComponentHelper.h"
#include "ccConfig.h"
#include "ccConfigLoader.h"
#include "ccController.h"
#include "ccCookie.h"
#include "ccEventDispatcher.h"
#include "ccEvent.h"
#include "ccException.h"
#include "ccFormElementFormStart.h"
#include "ccFormElementLabel.h"
#include "ccFormElementText.h"
#include "ccMultipartParser.h"
#include "ccPregRoute.h"
#include "ccQueryParser.h"
#include "ccRequest.h"
#include "ccResource.h"
#include "ccResponse.h"
#include "ccRole.h"
#include "ccRoute.h"
#include "ccRouter.h"
#include "ccSession.h"
#include "ccSessionProvider.h"
#include "ccMemorySessionProvider.h"
#include "ccStaticRoute.h"
#include "ccTemplateResponse.h"
#include "ccYamlSessionProvider.h"


#endif /* CCFRAMEWORK_H_ */
