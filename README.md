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

# **Vector**
Documentation on the Vector Library:

Declaration: `Vector<Type> vec;`
Simply declare the vector with a type and a name to set it up.

## Changing the Vector
`void pushBack(const Type& addOn)`, declaration `vec.pushBack(5);` This will add another element to the back of the vector

`Type& emplaceBack(Args&&... args)`, declaration `vec.emplaceBack<Vector3>(0, 1, 2);` This will create a constructor of a certain type

`void popBack()`, declaration `vec.popBack();` remove the last element in the vector if there is one

`void clear()`, declaration `vec.clear();` remove the entirity of the Vector

## Access Members
`const Type& operator[](size_t index) const`, declaration `vec[0];` get the element at the specified index (Both const and nonconst)

`const Type& front() const`, declaration `vec.front();` get the first element in the vector if possible(Both const and nonconst)

`const Type& back() const`, declaration `vec.back();` get the last element in the vector if possible (Both const and nonconst)

## Size Functions
`const size_t size() const`, declaration `vec.size();` get an immutable number representing the number of elements in the vector

`const bool isEmpty() const`, declaration `vec.isEmpty();` get true or false statement on whether or not the vector is empty

`void makeSizePerfect()`, declaration `vec.makeSizePerfect();` cut down on any excess allocated space for preparedness

# **Stack**
Documentation on the Stack library

Declaration: `Stack<Type> st`
Simply declare the stack with a type and a name to set it up.

## Size Functions

` size_t size()`, declaration `st.size();` get an immutable number representing the number of elements in the stack

`bool isEmpty()`, declaration `st.isEmpty();` get true or false statement on whether or not the stack is empty
    
`void makeSizePerfect()`, declaration `st.makeSizePerfect();` cut down on any excess allocated space for preparedness

## Access Members and changes to the stack

`const Type& top() const`, declaration `st.top();` return the top element of the stack(Both const and nonconst)

`void push(const Type& value)`, declaration `st.push(5);` add another element of the specified type to the top of the stack v(Both const and nonconst)

`template<class... Args>
Type& emplace(Type&& args)`, declaration `st.emplace<Vector3>(1,2,3);`

 `void pop()`, declaration `st.pop()` remove the top element from the stack
 
 # ** Queue **
 Documentation on the Queue library
 
 Declaration: `Queue<Type> q;`
 simply declare the stack woiht a type and a name to set it up
 
 ## Size Functions

` size_t size()`, declaration `q.size();` get a number representing the number of elements in the queue

`bool isEmpty()`, declaration `q.isEmpty();` get true or false statement on whether or not the queue is empty
    
`void makeSizePerfect()`, declaration `q.makeSizePerfect();` cut down on any excess allocated space for preparedness
 
 ## Changing the Queue
 
`void push(const Type& addOn)`, declaration `q.pushBack(5);` This will add another element to the back of the queue

`Type& emplaceBack(Args&&... args)`, declaration `q.emplaceBack<Vector3>(0, 1, 2);` This will create a constructor of a certain type

`void pop()`, declaration `q.popBack();` remove the front element in the queue if there is one

## Access Members 

`const Type& front() const`, declaration `q.front();` get the first element in the vector if possible(Both const and nonconst)

`const Type& back() const`, declaration `q.back();` get the last element in the vector if possible (Both const and nonconst)

# **ForwardList**

Documentation of a ForwardList also know as a singly-linked List

Declaration `ForwardList<Type> list`

## Size Functions

`size_t size()`, declaration `list.size();` get a number representing the number of elements in the list

`bool isEmpty()`, declaration `list.isEmpty();` get true or false statement on whether or not the list is empty

## Altering the List

`void pushFront(const Type& newData)`, declaration `list.pushFront(5);` add a piece of data to the front of the list

`void popFront()`, declaration `list.popFront();` Remove the first element and it's data from the list

`void clear()`, declaration `list.clear();` remove all of the elements in the list

## Access Member

`const Type& front() const`, declaration `list.front();` get the first element in the list if possible(Both const and nonconst)

## Functions on the List

`void sort()`, declaration `list.sort();` sort through the entiriety of the array.

