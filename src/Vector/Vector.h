#ifndef VECTOR_H
#define VECTOR_H

#include <memory>


template <class Type>
class Vector {
  public:
    Vector(){
      //This actaully creates the newobject by call new, delete is opposite of new
      reAlloc(2);
    }
    ~Vector(){
      clear();
      delete[] vec;
      //Just delete the entirity of the data instead of setting to nullptr
      //::operator delete(vec, memCapacity * sizeof(Type));
    }

//Changing the Vector ------------------------------------>
    //EmplaceBack function with ... amount of args as a template

    void pushBack(const Type& addOn){
      //WE have to copy paste the old array to the new one and add allocated space, use std::move to move value into array
      if(memSize >= memCapacity){
        reAlloc(memCapacity + memCapacity / 2);
      }

      vec[memSize] = std::move(addOn);
      memSize++;
    }

    template<class... Args>
    Type& emplaceBack(Args&&... args){
      if(memSize >= memCapacity){
        reAlloc(memCapacity + memCapacity / 2);
      }

      new(&vec[memSize]) Type(std::forward<Args>(args)...);
      memSize++;
      return vec[memSize++];
      //Have return type of Type&
    }

    void popBack(){
      //Make sure to destroy the pointer at this spot ("With Destructor")
      if(memSize > 0){
        memSize--;
        vec[memSize].~Type();
      }
    }

    void clear(){
      //Same as popback byt whole array
      for(size_t i = 0; i < memSize; i++){
        vec[i].~Type();
      }
      memSize = 0;
    }

// -> Acccess Members -----------------------
  /*All access members need a const and nonconst because the user may want to change
  data at the point, otherwise we don't want anything funky to happen
  */
    const Type& operator[](size_t index) const {
      if(index >= memSize){
          //Throw warning
      }

      return vec[index];
    }

    Type& operator[](int index) {
      if(index >= memSize){
        //Throw warning
      }

      return vec[index];
    }

    const Type& front() const {
      if(memSize <= 0){
        //Throw Error
      }
      return vec[0];
    }

    Type& front(){
      if(memSize <= 0){
        //Throw Error
      }
      return vec[0];
    }

    const Type& back() const {
      if(memSize <= 0){
        //Throw Error
      }
      return vec[memSize - 1];
    }

    Type& back(){
      if(memSize <= 0){
        //Throw Error
      }
      return vec[memSize - 1];
    }

//Size Functions ---------------------------------

  const size_t size() const {
    return memSize;
  }

  const bool isEmpty() const {
    if(memSize == 0){
      return true;
    }

    return false;
  }

  void makeSizePerfect(){
    for(size_t b = memSize; b < memCapacity; b++){
      vec[b].~Type();
    }
    memCapacity = memSize;
  }

//Private Function -------------------------------

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
        newBlock[i] = std::move(vec[i]);
      }

      //Clear function but doesn't reset size
      for(size_t i = 0; i < memSize; i++){
        vec[i].~Type();
      }

      delete[] vec;
      vec = newBlock;
      memCapacity = newCapacity;
    }

    size_t memSize = 0;
    size_t memCapacity = 0;
    Type* vec = nullptr;
};

#endif
