#ifndef DEBUG_H
#define DEBUG_H

#include <chrono>

typedef std::chrono::duration<double> doubleTime;
typedef std::chrono::time_point<std::chrono::steady_clock, std::chrono::duration<long long, std::ratio<1, 1000000000>>> longDuration;

//Remeber memory based sizing on functions and stuff

class Debug {
  public:
    Debug();
    ~Debug();

    doubleTime beginDebug();
    double getTime();
    void booleanTest(bool subjectResult);
  private:
    int time;
    auto startTimer() -> longDuration;
    auto endTimer() -> longDuration;
};

#endif
