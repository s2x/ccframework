#ifndef CCFRAMEWORK_H_
#define CCFRAMEWORK_H_
namespace ccFramework {
class ccApp;
class ccController;
class ccQueryParser;
class ccRequest;
class ccResponse;
class ccRoute;
class ccRouter;
class ccRouterFunctor;
class ccTemplateResponse;
class ccCookie;
class ccCommon;
class ccSession;
class ccConfig;
class ccConfigLoader;
class ccEvent;
class ccEventDispatcher;
class ccRole;
class ccResource;
class ccAcl;
class ccException;
class ccMultipartParser;

// form and forms elements
class ccBaseForm;
class ccBaseFormElement;
class ccFormElementText;
class ccFormElementLabel;
class ccBaseFormRenderer;
class ccFormElementFormStart;

// helpers
class ccBaseHelper;
class ccComponentHelper;
}
#include <iostream>
#include <fstream>
#include "yaml-cpp/yaml.h"
#include "ccCookie.h"
#include "ccApp.h"
#include "ccEvent.h"
#include "ccEventDispatcher.h"
#include "ccController.h"
#include "ccQueryParser.h"
#include "ccRequest.h"
#include "ccResponse.h"
#include "ccRoute.h"
#include "ccRouter.h"
#include "ccTemplateResponse.h"
#include "ccCommon.h"
#include "ccSession.h"
#include "ccConfig.h"
#include "ccConfigLoader.h"
#include "ccRole.h"
#include "ccResource.h"
#include "ccAcl.h"
#include "ccException.h"
#include "ccMultipartParser.h"
#include "ccBaseHelper.h"
#include "ccComponentHelper.h"
#include "ccBaseForm.h"
#include "ccBaseFormElement.h"
#include "ccFormElementText.h"
#include "ccFormElementLabel.h"
#include "ccFormElementFormStart.h"
#endif /* CCFRAMEWORK_H_ */
