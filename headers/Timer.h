#ifndef TIMER_H
#define TIMER_H

#include <iostream>
#include <chrono>

struct Timer {
  std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
  std::chrono::duration<float> duration;

  Timer();
  ~Timer();
};

#endif
