#include "FTFP_BERT.hh"
#include "G4RunManagerFactory.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"
#include "G4UImanager.hh"
#include "G4GDMLParser.hh"

#include "DetectorConstruction.hh"
#include "ActionInitialization.hh"
#include "NanoVDB.hh"

int main(int argc, char** argv)
{

  std::cout << "g4openvdb> Geant4 Openvdb" << std::endl;

  //auto* runManager = G4RunManagerFactory::CreateRunManager();

  // multithreaded run manager
  auto* runManager = new G4RunManager();

  // Get number of cores
  auto numberOfCores = G4Threading::G4GetNumberOfCores();
  auto numberofGeant4Cores = numberOfCores-2;
  std::cout << "g4openvdb> Number of cores        : " << numberOfCores << std::endl;
  std::cout << "g4openvdb> Number of cores (used) : " << numberofGeant4Cores << std::endl;

  // Set number of threads
  runManager->SetNumberOfThreads(numberofGeant4Cores);

  // Create NanoVDB object
  auto nanoVDB = NanoVDB();

  // GDML parser
  G4GDMLParser parser;
  parser.Read(argv[1]);

  // Detector construction
  runManager->SetUserInitialization(new DetectorConstruction(parser.GetWorldVolume()));

  // Physics list
  runManager->SetUserInitialization(new FTFP_BERT);

  // Actions
  runManager->SetUserInitialization(new ActionInitialization());

  // Initialize run manage
  runManager->Initialize();

  // Initialize visualization
  G4VisManager* visManager = new G4VisExecutive;
  visManager->Initialize();

  // Get the pointer to the User Interface manager
  G4UImanager* UImanager = G4UImanager::GetUIpointer();

  if (argc == 3)  // batch mode
  {
    G4String command = "/control/execute ";
    G4String fileName = argv[1];
    UImanager->ApplyCommand(command + fileName);
  }
  else  // interactive mode
  {
    G4UIExecutive* ui = new G4UIExecutive(argc, argv);
    UImanager->ApplyCommand("/control/execute vis.mac");
    ui->SessionStart();
    delete ui;
  }

  delete visManager;
  delete runManager;

}