
#include "Inventory.h"
#include "Item.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "../UI/UserInterface.h"
#include "../Character/Player.h"


using namespace std;


Inventory::Inventory(){
  head = nullptr;
}

Inventory::Inventory(const vector<Item>& items){
  //Make sure list is empty and add all items to inventory
  head = nullptr;
  for(unsigned int i = 0; i < items.size(); i++){
    addItem(items[i]);
  }

}

Inventory::~Inventory() {
  Node* current = head;
  while(current != nullptr){
    Node* temp =  current;
    current = current->getNext();
    delete temp;
  }
}
//Inserting at front of the list
void Inventory::addItem(const Item& newItem){
  Node* current = head;

  //Traverse through the list for any duplicates:
  while(current != nullptr)
  {
    if(current->getData().GetName() == newItem.GetName())
    {
      int amount = current->getData().GetAmount();
      int newAmount = newItem.GetAmount() + amount;
      current->getData().setAmount(newAmount);
      return;
    }
    current = current->getNext();
  }

  //If no duplicates add @ beginning of the list
  Node* newNode = new Node(newItem);
  newNode->setNext(head);
  head = newNode;
}

//Remove item by name
void Inventory::removeItem(const string& itemName){
  Node* current = head;
  Node* prev = nullptr;

  //Traverse the list until you find the item
  while(current!= nullptr && current->getData().GetName() != itemName){
    prev = current;
    current = current->getNext();
  }

  if(current == nullptr){
    printCentered( current->getData().GetName() + " not found.", border_width + 30);
    return;
  }
    // If the item amount is greater than 1, just decrement the count
    if(current->getData().GetAmount() > 1) {
        int newAmount = current->getData().GetAmount() - 1;  // Decrement the amount
        current->getData().setAmount(newAmount);  
  
        return;  // Exit since we only updated the amount, not removed the item
    }

  //Checks if the item is the head
  if(prev == nullptr){
    head = current->getNext();
  }else {
    prev->setNext(current->getNext());
  }

  //Free memory
  delete current;
  printCentered( current->getData().GetName() + " removed from inventory.", border_width + 30);

}


Item* Inventory::searchItem(const string& itemName)
{

      Node* current = head;
    
    // Traverse the linked list to search for the item
    while (current != nullptr) {
        if (current->getData().GetName() == itemName) {
            // If the item is found, return a reference to the item
            return &current->getData();
        }
        current = current->getNext();  // Move to the next node
    }

    //Return a nullptr if not found
    return nullptr;
}


bool Inventory::useItem(Item& targetItem, Player& player )
{
    Node* current = head;
    //Search for item
    
    while(current != nullptr)
    {
      if(current->getData().GetName() == targetItem.GetName())
      {
        //Update attribute accordingly
        if(targetItem.GetName() == "Potion")
        {
        

          int updateHealth = player.getHealth() + targetItem.GetItemAffect();
          player.setHealth(updateHealth);
          // Print the top border
          cout << string(border_width + 30, '-') << endl;
          printCentered(player.getName() + " justed used a " + targetItem.GetName(), border_width + 30);
          printCentered("You have recovered " +  to_string(targetItem.GetItemAffect()) + " points!", border_width + 30);
          //Delete the item after using
          player.removeItemFromInventory(targetItem.GetName());
          printCentered("You now have " + to_string(targetItem.GetAmount()) + " left", border_width + 30);
          return true;
        }
        if(targetItem.GetName().find("Shield") != string::npos)
        {
          player.setArmour(targetItem.GetItemAffect());
          // Print the top border
          cout << string(border_width + 30, '-') << endl;
          printCentered(player.getName() + " justed equipped " + targetItem.GetName(), border_width + 30);
          return true;
        }
        if(targetItem.GetName().find("Scroll")!= string::npos)
        {
          int updatedAttackPower  = player.getAttackPower() + targetItem.GetItemAffect();
          player.setAttackPower(updatedAttackPower);
          cout << string(border_width + 30, '-') << endl;
          printCentered(player.getName() + " justed used a " + targetItem.GetName(), border_width + 30);
          printCentered(targetItem.GetDescription(), border_width + 30);
          //Delete the item after using
          player.removeItemFromInventory(targetItem.GetName());
          return true;
        }
        if(targetItem.GetName().find("Sword") != string::npos)
        {
          player.setAttackPower(targetItem.GetItemAffect());

          cout << string(border_width + 30, '-') << endl;
          printCentered(player.getName() + " justed equipped " + targetItem.GetName(), border_width + 30);
          printCentered(targetItem.GetDescription(), border_width + 30);
          return true;
        }
        //Other Item Implentations can go here in the future
      }
        // Move to the next node
        current = current->getNext();
    }


    //Update player attributes


    //Remove the item



  return false;
}




void Inventory::displayInventory() const {
  Node* current = head;
  if(current == nullptr){
    cout << "Inventory does not exists" << endl;
    return;
  }
  // Traverse through the linked list and print each item's data
  while (current != nullptr) {
    int box_width = border_width + 30; 

    // Print the top border
    cout << string(box_width, '-') << endl;

    // Print each field centered
    printCentered("Item: " + current->getData().GetName(), box_width);
    printCentered("Amount: " + to_string(current->getData().GetAmount()), box_width);
    printCentered("Description: " + current->getData().GetDescription(), box_width);

    // Print the bottom border
     cout << string(box_width, '-') << endl;

    current = current->getNext();  // Move to the next node
  }
}
void Inventory::sortItems(){
  //Checks if the list is empty or only has one node
  if(!head || !head->getNext())
  {
    return;
  }


  Node* sorted = nullptr;

  //Traversing original list
  Node* current = head;
  while(current != nullptr){
    Node* next = current->getNext();
    if(sorted == nullptr || current->getData().GetName() < sorted->getData().GetName()){
      //Insert at the beginning
      current->setNext(sorted);
      sorted = current;
    }else {
      //Go through the sorted list to find the correct location
      Node* temp = sorted;
      while(temp->getNext() != nullptr && temp->getNext()->getData().GetName() < current->getData().GetName()){
        temp =  temp->getNext();
      }

      //Insert after temp
      current->setNext(temp->getNext());
      temp->setNext(current);
    }

    //Move to the next node in the original list
    current = next;
  }

  //Update the head to the new sorted list
  head = sorted;
}




