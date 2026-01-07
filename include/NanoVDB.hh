#pragma once

#include <nanovdb/NanoVDB.h>
#include <nanovdb/util/GridBuilder.h>
#include <nanovdb/tools/CreatePrimitives.h>


class NanoVDB {
public:
  NanoVDB();
  ~NanoVDB();
  void Fill(float x, float y, float z, float v);

private:

};