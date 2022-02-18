#include "dll.h"

// ADD FUNCTIONS
void DLL::addFront(int d){
 Node* newNode = new Node(d,nullptr, head);
 if (head == nullptr)
 {
   head=newNode;
   tail=newNode;
   newNode->next = nullptr;
   newNode->prev = nullptr;
 }
 else
 {
   head->prev = newNode;
   head = newNode;
 }
 length++;
};

void DLL::addBack(int d){
  Node* newNode = new Node(d,tail,nullptr);
  if (head == nullptr)
  {
    head=newNode;
    tail=newNode;
    newNode->prev = nullptr;
    newNode->next = nullptr;
  }
  else
  {
    tail->next = newNode;
    tail = newNode;
  }
  length++;
};

// DELETE FUNCTIONS
void DLL::deleteFront(){
  if (head==nullptr) return;
  if (head->next==nullptr){ // only 1 item
    delete head;
    head=nullptr;
    tail=nullptr;
    length = 0;
    return;
  }

  Node* tmpptr = head->next;
  delete head;
  head = tmpptr;
  head->prev = nullptr;
  length--;
};

void DLL::deleteBack(){
  if (head==nullptr)return;
  if (head->next == nullptr){ // only 1 item
    delete head;
    head = nullptr;
    tail = nullptr;
    length = 0;
    return;
  }

  Node* tmpptr = tail->prev;
  delete tail;
  tail = tmpptr;
  tail->next = nullptr;
  length--;
};

void DLL::deleteAt(int i){
  if (head == nullptr) return;
  if (i >= length) return;
  if (i == 0) return deleteFront(); 
  if (i == length-1) return deleteBack();
  
  Node* curr = head;
  for (int j=0; j<i; j++){
    curr = curr->next;
  }

  Node* tmpprev = curr->prev;
  Node* tmpnext = curr->next;

  delete curr;
  tmpprev->next = tmpnext;
  tmpnext->prev = tmpprev;

  length --;
};

// PRINT FUNCTIONS
void DLL::print(){
  if (head == nullptr) return;
  
  std::cout <<'\n';
  std::cout << "Print from head: " << '\n';
  
  Node*curr = head;
  while (curr!=nullptr){
    
    std::cout << curr->data << '\n';
    curr=curr->next;
  }
  
  std::cout <<'\n';
  std::cout << "Print from tail: " << '\n';

  curr=tail;
  while (curr!=nullptr){
    std::cout << curr->data << '\n';
    curr=curr->prev;
  }
  std::cout <<'\n';
};

void DLL::printLength(){
  int len = 0;
  Node* curr = head;
  while (curr!=nullptr){
    len ++;
    curr=curr->next;
  }
  std::cout << '\n' << "Actual length of list: " << len << '\n' ;
  std::cout << "Length Value in list: " << length << '\n';
};