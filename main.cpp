#include <iostream>
#include <time.h>
#include "./src/Debug/Debug.h"

void goober();

void goober(){}

int main(){
  Debug s;

  float result = s.beginDebug(&goober);
  float res = result;

  std::cout << res << std::endl;
}


/*
Main goal of this project is memory visuals, we want the users to see how much memory
function calls actually use up and we want them to be safe from overflow where we
can implement it, we want to Serial.print time and space of fucntion calls and stuff like that
in addition to the library we can make an ImGUi project wher the user can see the callstack
and see how much tiem and space things actually takes
*/
