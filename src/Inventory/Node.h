#ifndef NODE_H
#define NODE_H


#include <iostream>
#include <string>
#include "Item.h"

class Node {
private:
Item data;
Node* next;
public:
    //Default constructor
    Node();
    // Regular constructor given an item
    Node(const Item& item);

    //Getters and setters
    Item& getData() ;
    void setData(const Item& newItem);
    Node* getNext() const;
    void setNext(Node* newNext);

};

#endif 