#ifndef QUEUE_H
#define QUEUE_H

#include <memory>
//Follows FIFO structure only changing the front and back

template<class Type>
class Queue {
public:
  Queue(){
    reAlloc(2);
  }
  ~Queue(){
    for(size_t i = 0; i < memSize; ++i){
        q[i].~Type();
    }
    memSize = 0;
    delete[] q;
  }

//Size Members ------------------------------------------

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
      q[b].~Type();
    }
    memCapacity = memSize;
  }

//Things that affect that queue ------------------------

void pop(){
  //Remove the item and make sure to move the reference, removed the front ;
  if(memSize > 0){
    memSize--;
    q[0].~Type();
    for(size_t b = 0; b < memSize; b++){
      q[b] = std::move(q[b + 1]);
    }
  }
}

void push(const Type& value){
  //This time we will the item by moving the previous queue to this one, pushes to the end
  if(memSize >= memCapacity){
    reAlloc(memCapacity + memCapacity / 2);
  }

  q[memSize] = std::move(value);
  memSize++;
}

//This template can take any amount of args which is great for things like a Vector3
template<class... Args>
Type& emplace(Type&& args) {
  if(memSize >= memCapacity){
    reAlloc(memCapacity + memCapacity / 2);
  }


  new(&q[memSize]) Type(std::forward<Args>(args) ...);
  memSize++;
  return q[memSize++];
}

//Accessors to the data --------------------------------------

const Type& front() const {
  if(memSize <= 0){
    //Throw error
  }
  else {
    return q[0];
  }
}

Type& front() {
  if(memSize <= 0){
    //Throw error
  }
    return q[0];
}


const Type& back() const {
  if(memSize <= 0){
    //Throw error
  }
  else {
    return q[memSize - 1];
  }
}

Type& back() {
  if(memSize <= 0){
    //Throw error
  }
    return q[memSize - 1];
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
      newBlock[i] = std::move(q[i]);
    }

    //Clear function but doesn't reset size
    for(size_t i = 0; i < memSize; i++){
      q[i].~Type();
    }

    delete[] q;
    q = newBlock;
    memCapacity = newCapacity;
  }

  Type* q = nullptr;

  size_t memSize = 0;
  size_t memCapacity = 0;
};

#endif
