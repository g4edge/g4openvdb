#include "G4Run.hh"
#include "G4RunManager.hh"
#include "G4SystemOfUnits.hh"

#include "RunAction.hh"

RunAction::RunAction()
  : G4UserRunAction()
{
  std::cout << "RunAction::RunAction" << std::endl;
}

RunAction::~RunAction()
{
}

void RunAction::BeginOfRunAction(const G4Run* run)
{
  std::cout << "RunAction::BeginOfRunAction" << std::endl;
  std::cout << "RunAction::BeginOfRunAction> run " << run->GetRunID() << " start." << G4endl;
}

void RunAction::EndOfRunAction(const G4Run* run)
{
  std::cout << "RunAction::EndOfRunAction" << std::endl;
}