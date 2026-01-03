#include "NanoVDB.hh"

NanoVDB::NanoVDB() {
}

NanoVDB::~NanoVDB() {}

void NanoVDB::Fill(float x, float y, float z, float v) {
  auto accessor = grid->getAccessor();

  nanovdb::Coord xyz(x, y, z);
}
