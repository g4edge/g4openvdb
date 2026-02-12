#pragma once

#include "G4VUserActionInitialization.hh"

class ActionInitialization : public G4VUserActionInitialization
{
public:
  ActionInitialization();
  virtual ~ActionInitialization() = default;

  virtual void BuildForMaster() const;
  virtual void Build() const;
};
