#include <sstream>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <unordered_map>

void loadData(std::string, std::unordered_map<std::string, std::string>&);
void tokensieInput(std::string&, char, std::unordered_map<std::string, std::string>&);

int main(int argc, char* argv[]) {
  std::unordered_map<std::string, std::string> bricks;
  std::list<std::string> outputSequence;

  loadData(argv[1], bricks);

  const auto startingBrick = bricks.begin();

  outputSequence.emplace_back(startingBrick->first);
  outputSequence.emplace_back(startingBrick->second);

  for (const auto& brick : bricks) {
    if (bricks.find(outputSequence.back()) == bricks.end()) {
      auto front = bricks.find(outputSequence.front());

      for (const auto& brick : bricks) {
        if (brick.second == front->first)
          outputSequence.emplace_front(brick.first);
      }
    } else {
      auto back = bricks.find(outputSequence.back());
      outputSequence.emplace_back(back->second);
    }
  }

  for (const auto& symbol : outputSequence)
    std::cout << symbol << std::endl;

  return 0;
}

void loadData(std::string path, std::unordered_map<std::string, std::string>& bricks) {
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
    tokensieInput(line, delim, bricks);
  }

  ifs.close();
}

void tokensieInput(std::string& str, char delim, std::unordered_map<std::string, std::string>& bricks) {
  std::stringstream ss(str);
  std::vector<std::string> brick = {};

  while (std::getline(ss, str, delim))
    brick.emplace_back(str);

  std::string northSide = brick[0];
  std::string southSide = brick[1];
  bricks.emplace(northSide, southSide);
}
