#ifndef SOLUTION_TWO_H
#define SOLUTION_TWO_H

#include <string>
#include <map>
#include <list>

using northSide = std::string;
using southSide = std::string;

namespace solution_2 {
  std::map<northSide, southSide> loadData(const std::string path);
  void tokeniseInput(std::string& str, char delim, std::map<northSide, southSide>& bricks);
  std::list<std::string> createSequence(std::map<northSide, southSide>& bricks);
  std::map<southSide, northSide> inverseMap(std::map<northSide, southSide>& map);
  void displaySequence(std::list<std::string>& seq);
}

#endif
