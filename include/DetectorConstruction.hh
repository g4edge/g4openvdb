#pragma once

#include "G4VUserDetectorConstruction.hh"

class DetectorConstruction : public G4VUserDetectorConstruction
{
public:
  DetectorConstruction(G4VPhysicalVolume* setWorld = 0) { fWorld = setWorld; }

  virtual G4VPhysicalVolume* Construct() { return fWorld; }

private:
  G4VPhysicalVolume* fWorld;
};