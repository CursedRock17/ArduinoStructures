#include <iostream>
#include <chrono>
#include "./src/Debug/Debug.h"

int main(){
  Debug s;
  std::chrono::duration<double> result = s.beginDebug();
  std::cout << "Hello World: " << result.count() << std::endl;
}
