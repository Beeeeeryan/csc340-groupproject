#include "Item.h"
#include <iostream>
using namespace std;


Item::Item(){
  ItemName = "Unknown";
  ItemName = "No description available";
  ItemAmount = 0;
  ItemAffect = 0;
}

Item::Item(const string& ItemName, const string& ItemDesc, int ItemAmount, int ItemAffect)
{
  this->ItemName = ItemName;
  this->ItemDescription = ItemDesc;
  this->ItemAmount = ItemAmount;
  this->ItemAffect = ItemAffect;
}

Item::~Item() {}

 string Item::GetName() const { 
    return this->ItemName; 
}
 string Item::GetDescription() const { 
    return this->ItemDescription; 
}
int Item::GetItemAffect() const{
    return this->ItemAffect;
}

int Item::GetAmount() const { 
    return this->ItemAmount; 
}
void Item::setAmount(int newAmount){
  this->ItemAmount = newAmount;
}

void Item::UseItem() {
    if (ItemAmount > 0) {
       cout << "Using " << ItemName << ": " << ItemDescription << "\n";
        --ItemAmount;
    } else {
       cout << "No " << ItemName << " left to use.\n";
    }
}