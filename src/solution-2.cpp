#include "../headers/solution-2.h"

#include <sstream>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

std::map<northSide, southSide> solution_2::loadData(const std::string path) {
  std::map<northSide, southSide> bricks;
  std::ifstream ifs;
  ifs.open(path);

  if (!ifs) {
    std::cerr << "Could not open file! Use ./<executable> \"<path-to-file>\"" << std::endl;
    std::exit(1);
  }

  std::string line;

  while (std::getline(ifs, line)) {
    if (line == "") continue;

    const char delim = ',';
    tokeniseInput(line, delim, bricks);
  }

  ifs.close();
  return bricks;
}

void solution_2::tokeniseInput(std::string& str, char delim, std::map<northSide, southSide>& bricks) {
  std::stringstream ss(str);
  std::vector<std::string> brick;

  while (std::getline(ss, str, delim))
    brick.emplace_back(str);

  std::string northSide = brick[0];
  std::string southSide = brick[1];
  bricks.emplace(northSide, southSide);
}

std::list<std::string> solution_2::createSequence(std::map<northSide, southSide>& bricks) {
  std::list<std::string> outputSequence;
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

  std::map<southSide, northSide> inversed = inverseMap(bricks);

  for (const auto& brick : inversed) {
    auto front = inversed.find(outputSequence.front());

    if (front == inversed.end()) {
      break;
    } else {
      outputSequence.emplace_front(front->second);
    } 
  }

  return outputSequence;
}

std::map<southSide, northSide> solution_2::inverseMap(std::map<northSide, southSide>& map) {
  std::map<southSide, northSide> inv;

  std::for_each(map.begin(), map.end(), [&inv](const std::pair<northSide, southSide>& p) {
    inv.emplace(p.second, p.first);
  });

  return inv;
}

void solution_2::displaySequence(std::list<std::string>& seq) {
  for (const auto& symbol : seq)
    std::cout << symbol << std::endl;
}
