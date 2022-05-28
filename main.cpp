#include <iostream>
#include <time.h>
#include "./src/Debug/Debug.h"
#include "./src/Vector/Vector.h"
#include "./src/Queue/Queue.h"
#include "./src/Stack/Stack.h"
#include "./src/LinkedList/LinkedList.h"

//This is purely an example file of using the data structures, there will be more indepth in documentation

void goober();

void goober(){}

int main(){
  Debug s;
  Queue<int> q;

  q.push(2);
  q.push(3);
  std::cout << q.size() << std::endl;
  q.pop();
  std::cout << q.front() << std::endl;
    std::cout << q.size() << std::endl;
      std::cout << q.front() << std::endl;
        std::cout << q.back() << std::endl;
        Stack<int> st;

        st.push(5);
        st.push(7);
        std::cout << st.top() << std::endl;
        st.pop();
        std::cout << st.top() << std::endl;
        st.pop();

  float result = s.beginDebug(&goober);
  float res = result;


  ForwardList<int> list;
  list.pushFront(7);
  list.pushFront(3);
  list.pushFront(9);
  list.pushFront(5);

  list.sort();
    std::cout << "Front: " << list.front() << std::endl;
    list.popFront();
    std::cout << "Popped" << std::endl;

    std::cout << "Front: " << list.front() << std::endl;
    list.popFront();
    std::cout << "Popped" << std::endl;

    std::cout << "Front: " << list.front() << std::endl;
    list.popFront();
    std::cout << "Popped" << std::endl;

}
