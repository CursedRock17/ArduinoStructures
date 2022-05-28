#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <memory>

template<class Type>
class Node {
public:
  Type data;
  Node* next;
};

//LinkedLists are not contigous, so they don't need more allocated space

template<class Type>
class ForwardList {
public:
  ForwardList(){}
  ~ForwardList(){
    clear();
  }

//Changing the List ========================================>
//There's np need to dynamically allocate with a linked list because
//It isn't contigous in the memory, therfore just use malloc and free to not memory leak

void pushFront(const Type& newData) {
  Node<Type>* current = (Node<Type>*)malloc(sizeof(Node<Type>));
  Node<Type>** headRef = &head;

  current->data = newData;
  current->next = *headRef;
  memSize++;

  *headRef = current;
}

void popFront(){
    Node<Type>** headRef = &head;
    Node<Type>* current = *headRef;

    if(headRef != NULL){
      *headRef = current->next;
      free(current);
      memSize--;
    }

}

void clear(){

  Node<Type>** headRef = &head;
  Node<Type>* current = *headRef;

  while(current->next != NULL){
    free(current);
    current = current->next;
  }
  memSize = 0;
}

//Checking the Size =========================================>
bool isEmpty() {
  if(memSize == 0) return true;
    return false;
}

size_t size(){
  return memSize;
}

//Access an Element =========================================>
Type& front(){
  if(memSize <= 0){
    //Throw Error with Serial.print();
  }
return head->data;
}

const Type& front() const {
  if(memSize <= 0){
    //Throw Error with Serial.print();
  }
return head->data;
}

//Operations on the list --------------------------------------->
void sort() {
  Node<Type> **headRef = &head;
  Node<Type> *current = *headRef, *index = NULL;
  int temp;

  if(headRef == NULL){
    return;
  } else {
    while (current != NULL) {
      index = current->next;

      while (index != NULL){
        if (current->data > index->data) {
          temp = current->data;
          current->data = index->data;
          index->data = temp;
        }
        index = index->next;
      }
        current = current->next;
    }
  }
}


private:
  Node<Type>* head = NULL;
  size_t memSize = 0;
};

#endif
