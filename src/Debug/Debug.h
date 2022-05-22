#ifndef DEBUG_H
#define DEBUG_H

#include <time.h>
#include <cstring>
//Remeber memory based sizing on functions and stuff

class Debug {
  public:
    Debug();
    ~Debug();

    float beginDebug( void function() );
    double getTime();

    int overflowAdd(int numberA, int numberB);
    float overflowAdd(float numberA, float numberB);
    double overflowAdd(double numberA, double numberB);
    short overflowAdd(short numberA, short numberB);
    long overflowAdd(long numberA, long numberB);

    size_t sizeOf(char string[]);
  private:
    int time;
    auto startTimer() -> clock_t;
    auto endTimer() -> clock_t;
};


#endif
