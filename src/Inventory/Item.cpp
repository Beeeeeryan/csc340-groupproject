#include "Item.h"
#include <iostream>


Item::Item(const std::string& ItemName, const std::string& ItemDesc, int ItemAmount)
    : ItemName(ItemName), ItemDescription(ItemDesc), ItemAmount(ItemAmount) {}

Item::~Item() {}


std::string Item::GetName() const { 
    return ItemName; 
}

std::string Item::GetDesc() const { 
    return ItemDescription; 
}


int Item::GetAmount() const { 
    return ItemAmount; 
}

void Item::UseItem() {
    if (ItemAmount > 0) {
        std::cout << "Using " << ItemName << ": " << ItemDescription << "\n";
        --ItemAmount;
    } else {
        std::cout << "No " << ItemName << " left to use.\n";
    }
}