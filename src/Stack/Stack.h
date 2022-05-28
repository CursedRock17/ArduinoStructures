#ifndef STACK_H
#define STACK_H

#include <memory>

template<class Type>
class Stack {
public:
  //This is a LIFO type data structure
  Stack(){
    reAlloc(2);
  }

  ~Stack(){
    for(int i = 0; i < memSize; ++i){
      st[i].~Type();
    }

    memSize = 0;
    delete[] st;
  }

//Size Functions of Stack ----------------------------------------

bool isEmpty(){
  if(memSize == 0) return true;
  return false;
}

size_t size(){
  return memSize;
}

//This deconstructs all of the "fake" copies made to hold space, which reduces size until we hit a real element
void makeSizePerfect(){
  for(size_t b = memSize; b < memCapacity; b++){
    st[b].~Type();
  }
  memCapacity = memSize;
}

//Change and Check Functions ----------------------------------------

const Type& top() const {
   return st[memSize - 1];
}

Type& top() {
  return st[memSize - 1];
}

void push(const Type& value){
  if(memSize >= memCapacity){
    reAlloc(memCapacity + memCapacity / 2);
  }

  st[memSize] = std::move(value);
  memSize++;
}

template<class... Args>
Type& emplace(Type&& args){
  if(memSize >= memCapacity){
    reAlloc(memCapacity + memCapacity / 2);
  }

  new(&st[memSize]) Type(std::forward<Args>(args) ...);
  memSize++;
  return st[memSize++];
}

void pop(){
  if(memSize > 0){
    memSize--;
    st[memSize].~Type();
  }
}


private:

  void reAlloc(size_t newCapacity){
    Type* newBlock = new Type[newCapacity];

    if(newCapacity < memSize){
      memSize = newCapacity;
    }

/*
Move the value with the std function instead of assigning when we can move instead
of copy -> this function will allows to dynamically size the vector on the stack
*/
    for(size_t i = 0; i < memSize; i++){
      newBlock[i] = std::move(st[i]);
    }

    //Clear function but doesn't reset size
    for(size_t i = 0; i < memSize; i++){
      st[i].~Type();
    }

    delete[] st;
    st = newBlock;
    memCapacity = newCapacity;
  }

Type* st = nullptr;
size_t memSize = 0;
size_t memCapacity = 0;
};

#endif
