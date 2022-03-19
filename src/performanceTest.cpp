#include "../headers/performanceTest.h"
#include "../headers/Timer.h"
#include "../headers/solution-1.h"
#include "../headers/solution-2.h"

int main(int argc, char* argv[]) {
  firstImplementation(argv[1]);
  // secondImplementation(argv[1]);
  
  return 0;
}

void firstImplementation(std::string path) {
  Timer timer;

  std::unordered_map<northSide, southSide> bricks = solution_1::loadData(path);
  std::list<std::string> outputSequence = solution_1::createSequence(bricks);
}

void secondImplementation(std::string path) {
  Timer timer;

  std::map<northSide, southSide> bricks = solution_2::loadData(path);
  std::list<std::string> outputSequence = solution_2::createSequence(bricks);
}
