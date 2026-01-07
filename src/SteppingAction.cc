#include "SteppingAction.hh"
#include "EventAction.hh"

#include "G4Step.hh"

SteppingAction::SteppingAction(EventAction* eventAction)
  : G4UserSteppingAction(), fEventAction(eventAction)
{
}

void SteppingAction::UserSteppingAction(const G4Step* step)
{
  std::cout << "SteppingAction::UserSteppingAction" << std::endl;
  auto edep = step->GetTotalEnergyDeposit();
}