#include "./Debug.h"
#include <chrono>

typedef std::chrono::duration<double> doubleTime;
typedef std::chrono::time_point<std::chrono::steady_clock, std::chrono::duration<long long, std::ratio<1, 1000000000>>> longDuration;
// -> Constructor and Destructor
Debug::Debug(){
  getTime();
  beginDebug();
}

Debug::~Debug(){

}

// -> Time Based Statements

auto Debug::startTimer() -> longDuration {
    auto start = std::chrono::steady_clock::now();
    longDuration startTime = start;
    return startTime;
}

auto Debug::endTimer() -> longDuration {
    auto end = std::chrono::steady_clock::now();
    longDuration endTime = end;
    return endTime;
}

double Debug::getTime(){
  //doubleTime totalTime;
  double totalTime;
  return totalTime;
}

// -> Main Function Call
doubleTime Debug::beginDebug(){
  //Make sure to include space between start and end
  longDuration start = startTimer();
  for(int i = 0; i < 5000000; ++i){

  }
  longDuration end = endTimer();
  doubleTime timeDifference = end - start;
  return timeDifference;
}


// -> Testing Certain Lines

void Debug::booleanTest(bool subjectResult){
  if(!subjectResult){

  }
}
