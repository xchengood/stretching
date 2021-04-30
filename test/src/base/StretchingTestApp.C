//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "StretchingTestApp.h"
#include "StretchingApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
StretchingTestApp::validParams()
{
  InputParameters params = StretchingApp::validParams();
  return params;
}

StretchingTestApp::StretchingTestApp(InputParameters parameters) : MooseApp(parameters)
{
  StretchingTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

StretchingTestApp::~StretchingTestApp() {}

void
StretchingTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  StretchingApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"StretchingTestApp"});
    Registry::registerActionsTo(af, {"StretchingTestApp"});
  }
}

void
StretchingTestApp::registerApps()
{
  registerApp(StretchingApp);
  registerApp(StretchingTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
StretchingTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  StretchingTestApp::registerAll(f, af, s);
}
extern "C" void
StretchingTestApp__registerApps()
{
  StretchingTestApp::registerApps();
}
