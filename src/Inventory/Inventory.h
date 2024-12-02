#ifndef INVENTORY_H
#define INVENTORY_H
#include "Item.h"
#include "Node.h"
#include <string>
#include <vector>

//Linked List class Inventory
class Inventory{
  private:
    Node* head;
  public:
    //Default Constructor and deconstructor
    Inventory();
    Inventory(const std::vector<Item>& items);
    ~Inventory();
    /*Linked List methods
      ->add an Item/remove an Item by name/display inventory/sort items
    */
    void addItem(const Item& newItem);
    void removeItem(const std::string& itemName);
    void sortItems();
    void displayInventory()const;
};

#endif 
