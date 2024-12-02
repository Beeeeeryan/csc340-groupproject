#ifndef ITEM_H
#define ITEM_H
#include <string>


class Item
{
private:
    std::string ItemName;
    std::string ItemDescription;
    int ItemAmount;
    
public:

    //Default constructor
    Item();
    Item(const std::string& ItemName, const std::string& ItemDesc, int ItemAmount);
    ~Item();

    std:: string GetName() const; //get item Name
    
    std::string GetDescription() const; //get item description
    
    int GetAmount() const;
    void setAmount(int newAmount);
    void UseItem();
};


#endif