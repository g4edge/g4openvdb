#include "EventAction.hh"
#include "G4Event.hh"
#include "G4EventManager.hh"
#include "G4TrajectoryContainer.hh"
#include "G4Trajectory.hh"
#include "G4ios.hh"

EventAction::EventAction(RunAction *runAction)
  : G4UserEventAction(), fRunAction(runAction)
{
  std::cout << "EventAction::EventAction" << std::endl;
}

EventAction::~EventAction()
{
}

void EventAction::BeginOfEventAction(const G4Event* event)
{
  std::cout << "EventAction::BeginOfEventAction" << std::endl;

  G4int eventID = event->GetEventID();

}

void EventAction::EndOfEventAction(const G4Event* event)
{
  std::cout << "EventAction::EndOfEventAction" << std::endl;

  G4int eventID = event->GetEventID();
}