#pragma once

#include "G4UserSteppingAction.hh"

class EventAction;
class G4Step;

class SteppingAction : public G4UserSteppingAction
{
public:
  SteppingAction(EventAction* eventAction);
  virtual void UserSteppingAction(const G4Step *step);

private:
  EventAction* fEventAction;
};