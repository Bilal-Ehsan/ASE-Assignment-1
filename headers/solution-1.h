#ifndef SOLUTION_ONE_H
#define SOLUTION_ONE_H

#include <unordered_map>
#include <list>
#include <string>

using northSide = std::string;
using southSide = std::string;

namespace solution_1 {
  std::unordered_map<northSide, southSide> loadData(const std::string path);
  void tokeniseInput(std::string& str, char delim, std::unordered_map<northSide, southSide>& bricks);
  std::list<std::string> createSequence(std::unordered_map<northSide, southSide>& bricks);
  std::unordered_map<southSide, northSide> inverseMap(std::unordered_map<northSide, southSide>& map);
  void displaySequence(std::list<std::string>& seq);
}

#endif
