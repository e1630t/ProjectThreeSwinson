#include <iostream>
#include <string>

using namespace std;

class GroceryItem {
    public:
    GroceryItem(string name);
    GroceryItem(string name, int quantity);

    string getName() const;
    int getQuantity() const;

    void addItem();
    void removeItem();

    bool operator < (const GroceryItem& other) const;

    private:
    string name;
    int quantity;

};