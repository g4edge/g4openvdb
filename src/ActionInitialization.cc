#include "ActionInitialization.hh"
#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"
#include "EventAction.hh"
#include "SteppingAction.hh"

ActionInitialization::ActionInitialization() : G4VUserActionInitialization() {}

void ActionInitialization::BuildForMaster() const {}

void ActionInitialization::Build() const
{
  SetUserAction(new PrimaryGeneratorAction);

  // run action
  auto runAction = new RunAction();
  SetUserAction(runAction);

  // event action
  auto eventAction = new EventAction(runAction);
  SetUserAction(eventAction);

  // stepping action
  SetUserAction(new SteppingAction(eventAction));
}

