#pragma once

#include <nanovdb/NanoVDB.h>
#include <nanovdb/tools/GridBuilder.h>
#include <nanovdb/tools/CreatePrimitives.h>

using ValueT = float;
using GridT = nanovdb::NanoGrid<ValueT>;
// using BuilderT = nanovdb::tools::GridBuilder<ValueT>;

class NanoVDB {
public:
  NanoVDB();
  ~NanoVDB();
  void Fill(float x, float y, float z, float v);

private:
  const GridT* grid;
};