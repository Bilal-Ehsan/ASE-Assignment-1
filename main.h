#ifndef MAIN_H
#define MAIN_H

#include <unordered_map>
#include <map>
#include <string>
#include <list>

using northSide = std::string;
using southSide = std::string;

std::unordered_map<northSide, southSide> loadData(const std::string);
// std::map<northSide, southSide> loadData(const std::string);
void tokeniseInput(std::string&, char, std::unordered_map<northSide, southSide>&);
// void tokeniseInput(std::string&, char, std::map<northSide, southSide>&);
std::list<std::string> createSequence(std::unordered_map<northSide, southSide>&);
// std::list<std::string> createSequence(std::map<northSide, southSide>&);
std::unordered_map<northSide, southSide> inverseMap(std::unordered_map<northSide, southSide>&);
// std::map<northSide, southSide> inverseMap(std::map<northSide, southSide>&);
void displaySequence(std::list<std::string>&);

#endif
