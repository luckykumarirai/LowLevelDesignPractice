#include<iostream>
using namespace std;

class FoodItem{
    public:
        virtual double getPrice() = 0;
        virtual string getDescription() = 0;
        virtual ~FoodItem() {}
};


class Pizza : public FoodItem{
    public:
        double getPrice(){
            return 100;
        }
        string getDescription(){
            return "Pizza";
        }
};

class Burger : public FoodItem{
    public:
        double getPrice(){
            return 50;
        }
        string getDescription(){
            return "Burger";
        }
};

class Decorator : public FoodItem{
    protected:
        FoodItem* foodItem;
    public:
        Decorator(FoodItem *item) : foodItem(item) {}
};

class Topping : public Decorator{
    private:
        double extraToppingPrice;

    public:
        Topping(FoodItem* foodItem, double price): Decorator(foodItem), extraToppingPrice(price) {}

        double getPrice(){
            return foodItem->getPrice() + extraToppingPrice;
        }
        string getDescription(){
            return foodItem->getDescription() + " with Topping";
        }
};

class Sauce : public Decorator{
    private:
        double saucePrice;
    public:
        Sauce(FoodItem* foodItem, double price): Decorator(foodItem), saucePrice(price) {}

        double getPrice(){
            return foodItem->getPrice() + saucePrice;
        }
        string getDescription(){
            return foodItem->getDescription() + " with Sauce";
        }
};
 int main(){
      
     FoodItem * pizza = new Pizza();
     pizza = new Topping(pizza, 10);
     pizza = new Sauce(pizza, 5);


    FoodItem * burger = new Burger();
    burger = new Sauce(burger, 5);

    cout << pizza->getDescription() << " Price: " << pizza->getPrice() << endl;
    cout << burger->getDescription() << " Price: " << burger->getPrice() << endl;

    delete pizza;
    delete burger;
    
     return 0;
 }