#include "./Debug.h"
#include <iostream>
#include <time.h>
#include <cstring>

//#include <Arduino.h>

// -> Constructor and Destructor
Debug::Debug(){}

Debug::~Debug(){

}

// -> Time Based Statements

auto Debug::startTimer() -> clock_t {
    clock_t start;
    start = clock();
    return start;
}

auto Debug::endTimer() -> clock_t {
    clock_t end;
    end = clock();
    return end;
}

double Debug::getTime(){
  //doubleTime totalTime;
  double totalTime;
  return totalTime;
}

// -> Main Function Call
float Debug::beginDebug( void function() ) {
  //Make sure to include space between start and end
  clock_t start = startTimer();
  function();
  clock_t end = endTimer();
  clock_t timeDifference = end - start;

  float timeTaken = (float(timeDifference))/CLOCKS_PER_SEC;
  //Serial.print("It took ", timeTake, " Seconds");
  return timeTaken;
}


// -> Testing Certain Lines

/*
Creating Override Functions for float, double, int, long, short formatting
We can't see beforehand, but if it can't fit in the maxsize then we throw the error in
the form of -1 and 1;
*/

int Debug::overflowAdd(int numberA, int numberB){
  //When checking for overflow the intmax is 2147483647

  int* res = new int[(sizeof(int))];
  int* result = res;
  *result = numberA + numberB;

  if(numberA > 0 && numberB > 0 && *result < 0) {
    //Serial.print("overflow error");
    return -1;
  }
  if(numberA < 0 && numberB < 0 && *result > 0) {
    //Serial.print("overflow error");
    return -1;
  }

  int returnAdd = numberA + numberB;
  return returnAdd;
}

float Debug::overflowAdd(float numberA, float numberB){
  float* res = new float[(sizeof(float))];
  float* result = res;
  *result = numberA + numberB;

  if(numberA > 0 && numberB > 0 && *result < 0) {
    //Serial.print("overflow error");
    return -1;
  }
  if(numberA < 0 && numberB < 0 && *result > 0) {
    //Serial.print("overflow error");
    return -1;
  }

  float returnAdd = numberA + numberB;
  return returnAdd;
}

double Debug::overflowAdd(double numberA, double numberB){
  double* res = new double[(sizeof(double))];
  double* result = res;
  *result = numberA + numberB;

  if(numberA > 0 && numberB > 0 && *result < 0) {
    //Serial.print("overflow error");
    return -1;
  }
  if(numberA < 0 && numberB < 0 && *result > 0) {
    //Serial.print("overflow error");
    return -1;
  }

  double returnAdd = numberA + numberB;
  return returnAdd;
}

short Debug::overflowAdd(short numberA, short numberB){
  short* res = new short[(sizeof(short))];
  short* result = res;
  *result = numberA + numberB;

  if(numberA > 0 && numberB > 0 && *result < 0) {
    //Serial.print("overflow error");
    return -1;
  }
  if(numberA < 0 && numberB < 0 && *result > 0) {
    //Serial.print("overflow error");
    return -1;
  }

  short returnAdd = numberA + numberB;
  return returnAdd;
}

long Debug::overflowAdd(long numberA, long numberB){
  long* res = new long[(sizeof(long))];
  long* result = res;
  *result = numberA + numberB;

  if(numberA > 0 && numberB > 0 && *result < 0) {
    //Serial.print("overflow error");
    return -1;
  }
  if(numberA < 0 && numberB < 0 && *result > 0) {
    //Serial.print("overflow error");
    return -1;
  }

  long returnAdd = numberA + numberB;
  return returnAdd;
}

// -> Checking size of value (types ex: string), size is in bytes
size_t Debug::sizeOf(char string[]){
  //Serial.print(strlen(string), " bytes");
  return strlen(string);
}
