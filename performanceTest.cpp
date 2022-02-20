#include <iostream>
#include <chrono>

#include "main.h"

struct Timer {
  std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
  std::chrono::duration<float> duration;

  Timer() {
    start = std::chrono::high_resolution_clock::now();
  }

  ~Timer() {
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;

    float ms = duration.count() * 1000.0f;
    std::cout << "\nTimer took " << ms << "ms " << std::endl;
  }
};

void func() {
  Timer timer;

  // ...
}

int main() {
  func();
  return 0;
}
