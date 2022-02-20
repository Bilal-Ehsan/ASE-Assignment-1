#ifndef SOLUTION_ONE_H
#define SOLUTION_ONE_H

#include <unordered_map>
#include <list>
#include <string>

using northSide = std::string;
using southSide = std::string;

namespace solution_1 {
  std::unordered_map<northSide, southSide> loadData(const std::string);
  void tokeniseInput(std::string&, char, std::unordered_map<northSide, southSide>&);
  std::list<std::string> createSequence(std::unordered_map<northSide, southSide>&);
  std::unordered_map<northSide, southSide> inverseMap(std::unordered_map<northSide, southSide>&);
  void displaySequence(std::list<std::string>&);
}

#endif
