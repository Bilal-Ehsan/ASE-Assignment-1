#ifndef SOLUTION_2
#define SOLUTION_2

#include <string>
#include <map>
#include <list>

using northSide = std::string;
using southSide = std::string;

std::map<northSide, southSide> loadData(const std::string);
void tokeniseInput(std::string&, char, std::map<northSide, southSide>&);
std::list<std::string> createSequence(std::map<northSide, southSide>&);
std::map<northSide, southSide> inverseMap(std::map<northSide, southSide>&);
void displaySequence(std::list<std::string>&);

#endif
