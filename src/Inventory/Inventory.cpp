#include "Inventory.h"
#include "Item.h"
#include <iostream>
#include <string>
#include <vector>

Inventory::Inventory() {}
Inventory::~Inventory() {}

void Inventory::AddItem(const Item& item) {
    items.push_back(item);
    std::cout << "Added " << item.GetName() << " to the bag.\n";
}

void Inventory::UseItem(const std::string& itemName) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->GetName() == itemName) {
            it->UseItem();
            if (it->GetAmount() <= 0) {
                items.erase(it);  //delete the item after used
            }
            return;
        }
    }
    std::cout << "Item " << itemName << " not found in your bag.\n";
}

void Inventory::ShowItems() const {
    if (items.empty()) {
        std::cout << "Your item bag is empty\n";
        return;
    }
    std::cout << "Items:\n";
    for (const auto& item : items) {
        std::cout << "- " << item.GetName() << " (" << item.GetAmount() << "): " << item.GetDescription() << "\n";
    }
}