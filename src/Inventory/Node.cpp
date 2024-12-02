#include <iostream>
#include <string>
#include "Node.h"
using namespace std;


Node::Node(){
      this->next = nullptr;
}

Node::Node(const Item& item){
  this->data = item;
  this->next = nullptr;
}

Item& Node::getData() {
  return this->data;
}
void Node::setData(const Item& newItem){
  this->data = newItem;
}
Node* Node::getNext() const {
  return this->next;
}
void Node::setNext(Node* newNext){
  this->next = newNext;
}