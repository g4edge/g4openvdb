#include "NanoVDB.hh"
#include "nanovdb/io/IO.h"

NanoVDB::NanoVDB() {
}

NanoVDB::~NanoVDB() {}

void NanoVDB::Fill(float x, float y, float z, float v) {


  nanovdb::tools::build::Grid<float> grid(0,"boolocks");

  std::vector<nanovdb::GridHandle<>> handles;
  handles.push_back(nanovdb::tools::createNanoGrid(grid));

  for(auto i =0;i<10;i++) {
    auto ijk = nanovdb::Coord(10*i, y, z);
    auto acc = grid.getAccessor();
    acc.setValue(ijk, v);
  }

  nanovdb::io::writeGrids("./ra.nvdb", handles);

}

