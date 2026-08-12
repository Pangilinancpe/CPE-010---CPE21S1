#include <iostream>
#include <list>
#include <string>

class Item {
protected:
    std::string name;
    double price;
    int quantity;
public:
    Item(std::string n, double p, int q) : name(n), price(p), quantity(q) {}
    virtual ~Item() {}
    double calculateSum() const {
        return price * quantity;
    }
    std::string getName() const {
        return name;
    }
    virtual std::string getCategory() const = 0;

    void displayDetails() const {
        std::cout << getCategory() << ": " << name
                   << " | PHP " << price << " x " << quantity
                   << " = PHP " << calculateSum() << std::endl;
    }
};

class Fruit : public Item {
public:
    Fruit(std::string n, double p, int q) : Item(n, p, q) {
        std::cout << "Constructor called for " << name << std::endl;
    }

    ~Fruit() override {
        std::cout << "Fruit Destructor called for " << name << std::endl;
    }

    std::string getCategory() const override { return "Fruit"; }
};

class Vegetable : public Item {
public:
    Vegetable(std::string n, double p, int q) : Item(n, p, q) {
        std::cout << "Constructor called for " << name << std::endl;
    }

    ~Vegetable() override {
        std::cout << "Vegetable Destructor called for " << name << std::endl;
    }

    std::string getCategory() const override { return "Vegetable"; }
};

double TotalSum(Item* list[], int count) {
    double total = 0;
    for (int i = 0; i < count; i++) {
        total += list[i]->calculateSum();
    }
    return total;
}
int main() {
    Item* GroceryList[4];
    GroceryList[0] = new Fruit("Apple", 10, 7);
    GroceryList[1] = new Fruit("Banana", 10, 8);
    GroceryList[2] = new Vegetable("Broccoli", 60, 12);
    GroceryList[3] = new Vegetable("Lettuce", 50, 10);
    int count = 4;
    std::cout << "\n-- Grocery List --\n";
    for (int i = 0; i < count; i++) {
        GroceryList[i]->displayDetails();
    }
    std::cout << "\nTotal: PHP " << TotalSum(GroceryList, count) << std::endl;
    std::cout << "\n-- Removing Lettuce --\n";
    for (int i = 0; i < count; i++) {
        if (GroceryList[i]->getName() == "Lettuce") {
            delete GroceryList[i];
            GroceryList[i] = GroceryList[count - 1];
            count--;
            break;
        }
    }
    std::cout << "\n-- Updated Grocery List --\n";
    for (int i = 0; i < count; i++) {
        GroceryList[i]->displayDetails();
    }
    std::cout << "\nUpdated Total: PHP " << TotalSum(GroceryList, count) << std::endl;

    for (int i = 0; i < count; i++) {
        delete GroceryList[i];
    }

    return 0;
}
