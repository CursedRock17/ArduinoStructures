# ArduinoStructures

As the name suggests, this repo is mainly data structures meant for easy use with Arduino Projects, as an Arduino library. I often
see that data structures are used less in Arduino projects due to their large memory usage, especially when using STL c++ versions.
While this repo doesn't completely remove the amount of space used, it certainly chunks a large amount away. First, it's a more
barebones library meant to be missing some features that it's STL counterparts have, if it's important and I severly undervalued
a functions ability, then it should be PR and added to the main file. Additionally, for contigous memory based structures, the library
utilizes move semantics, new, and delete to push pointers around, this is a bonus because it can dynamically allocate data, in which 
the STL classes require an allocator and possibly don't use move semantics.

Basic ReAllocation function which utilizes move semantics: 
```
void reAlloc(size_t newCapacity){
    Type* newBlock = new Type[newCapacity];

    if(newCapacity < memSize){
      memSize = newCapacity;
    }

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
```

This function is often times used throughout the repo on data structures which contigously store it's memory like the stack. This
first sizes a new Type based on what Type the user passes, then we see if the new capacity is more than the size, because the size
of the stack has to scale to the max. Then we simply move the values into the new stack or whatever data structure the function
is being called for, from there deconstruct and remove the old structure hence leaving us with just one and now making that the
current data structure. These movement types limit use from having to call the copy constructor and rather delete and allocate a
new structure instead.

Most of these structures are created with template-based code which extends complete flexibily over to the user. Currently the only
reason these structures are stacked into one big file is because they haven't been added to the Arduino library, there are many 
similar functions and data type across the files, such as :
```

bool isEmpty(){
  if(memSize == 0) return true;
  return false;
}
////////////////////////
size_t size(){
  return memSize;
}
/////////////////////////
void reAlloc(size_t newCapacity){
    Type* newBlock = new Type[newCapacity];

    if(newCapacity < memSize){
      memSize = newCapacity;
    }
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
////////////////////////
size_t memSize = 0;
size_t memCapacity = 0;

```
If these files could be one section as it stands right now, they could all be involved in a large data structure class and just inherit
these traits, but they need to be standalone files to minimize the amount of storage used.

