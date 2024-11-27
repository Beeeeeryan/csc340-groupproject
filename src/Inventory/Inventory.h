#ifndef INVENTORY_H
#define INVENTORY_H
#include "Item.h"
#include <vector>

class Inventory
{
private:
    std:: vector <Item> items;

public:
    Inventory();
    ~Inventory();

    void AddItem(const Item& Item);
    void UseItem(const std:: string& ItemName);
    void ShowItems()const; //print out a list of all items

};


