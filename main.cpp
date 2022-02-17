#include <sstream>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <unordered_map>

void tokensieInput(std::string& str, char delim, std::unordered_map<std::string, std::string>& bricks) {
  std::stringstream ss(str);
  std::vector<std::string> brick = {};

  while (std::getline(ss, str, delim)) {
    brick.emplace_back(str);
  }

  std::string northSide = brick[0];
  std::string southSide = brick[1];
  bricks.emplace(northSide, southSide);
}

int main(int argc, char* argv[]) {
  std::ifstream ifs;
  ifs.open(argv[1]);

  if (!ifs) {
    std::cerr << "Could not open file!" << std::endl;
    return -1;
  }

  std::string line = "";
  std::unordered_map<std::string, std::string> bricks;

  while (std::getline(ifs, line)) {
    if (line == "") continue;

    const char delim = ',';
    tokensieInput(line, delim, bricks);
  }

  ifs.close();
  return 0;
}
