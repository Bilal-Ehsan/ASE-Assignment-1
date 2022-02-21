#include "../headers/main.h"
#include "../headers/solution-1.h"
#include "../headers/solution-2.h"

int main(int argc, char* argv[]) {
  firstImplementation(argv[1]);
  // secondImplementation(argv[1]);
  
  return 0;
}

void firstImplementation(std::string path) {
  std::unordered_map<northSide, southSide> bricks = solution_1::loadData(path);
  std::list<std::string> outputSequence = solution_1::createSequence(bricks);
  solution_1::displaySequence(outputSequence);
}

void secondImplementation(std::string path) {
  std::map<northSide, southSide> bricks = solution_2::loadData(path);
  std::list<std::string> outputSequence = solution_2::createSequence(bricks);
  solution_2::displaySequence(outputSequence);
}
