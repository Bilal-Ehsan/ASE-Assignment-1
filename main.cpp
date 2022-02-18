#include <sstream>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <unordered_map>
#include <map>
#include <algorithm>

using northSide = std::string;
using southSide = std::string;

void loadData(std::string, std::unordered_map<northSide, southSide>&);
void tokeniseInput(std::string&, char, std::unordered_map<northSide, southSide>&);
std::unordered_map<northSide, southSide> inverseMap(std::unordered_map<northSide, southSide>&);;

int main(int argc, char* argv[]) {
  std::unordered_map<northSide, southSide> bricks;
  std::list<std::string> outputSequence;

  loadData(argv[1], bricks);

  const auto startingBrick = bricks.begin();

  outputSequence.emplace_back(startingBrick->first);
  outputSequence.emplace_back(startingBrick->second);

  for (const auto& brick : bricks) {
    auto back = bricks.find(outputSequence.back());

    if (back == bricks.end()) {
      break;
    } else {
      outputSequence.emplace_back(back->second);
    }
  }

  std::unordered_map<southSide, northSide> inversed = inverseMap(bricks);

  for (const auto& brick : inversed) {
    auto front = inversed.find(outputSequence.front());

    if (front == bricks.end()) {
      break;
    } else {
      outputSequence.emplace_front(front->second);
    } 
  }

  for (const auto& symbol : outputSequence)
    std::cout << symbol << std::endl;

  return 0;
}

void loadData(std::string path, std::unordered_map<northSide, southSide>& bricks) {
  std::ifstream ifs;
  ifs.open(path);

  if (!ifs) {
    std::cerr << "Could not open file!" << std::endl;
    return;
  }

  std::string line = "";

  while (std::getline(ifs, line)) {
    if (line == "") continue;

    const char delim = ',';
    tokeniseInput(line, delim, bricks);
  }

  ifs.close();
}

void tokeniseInput(std::string& str, char delim, std::unordered_map<northSide, southSide>& bricks) {
  std::stringstream ss(str);
  std::vector<std::string> brick = {};

  while (std::getline(ss, str, delim))
    brick.emplace_back(str);

  std::string northSide = brick[0];
  std::string southSide = brick[1];
  bricks.emplace(northSide, southSide);
}

std::unordered_map<northSide, southSide> inverseMap(std::unordered_map<northSide, southSide>& map) {
  std::unordered_map<northSide, southSide> inv;

  std::for_each(map.begin(), map.end(), [&inv](const std::pair<southSide, northSide>& p) {
    inv.emplace(p.second, p.first);
  });

  return inv;
}
