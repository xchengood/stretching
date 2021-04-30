#include "StretchingApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
StretchingApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy DirichletBC, that is, set DirichletBC default for preset = true
  params.set<bool>("use_legacy_dirichlet_bc") = false;

  return params;
}

StretchingApp::StretchingApp(InputParameters parameters) : MooseApp(parameters)
{
  StretchingApp::registerAll(_factory, _action_factory, _syntax);
}

StretchingApp::~StretchingApp() {}

void
StretchingApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"StretchingApp"});
  Registry::registerActionsTo(af, {"StretchingApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
StretchingApp::registerApps()
{
  registerApp(StretchingApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
StretchingApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  StretchingApp::registerAll(f, af, s);
}
extern "C" void
StretchingApp__registerApps()
{
  StretchingApp::registerApps();
}
