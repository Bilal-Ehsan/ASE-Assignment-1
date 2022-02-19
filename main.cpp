#include "solution-1.h"
// #include "solution-2.h"

int main(int argc, char* argv[]) {
  std::unordered_map<northSide, southSide> bricks = loadData(argv[1]);
  std::list<std::string> outputSequence = createSequence(bricks);
  displaySequence(outputSequence);

  // std::map<northSide, southSide> bricks = loadData(argv[1]);
  // std::list<std::string> outputSequence = createSequence(bricks);
  // displaySequence(outputSequence);

  return 0;
}
