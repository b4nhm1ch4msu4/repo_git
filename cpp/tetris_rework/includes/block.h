#pragma once
#include "position.h"
#include <map>
#include <vector>

class Block {
public:
  Block();
  void Draw();

protected:
  int id;
  int rotateState;
  std::map<int, std::vector<Position>> cells;
};
