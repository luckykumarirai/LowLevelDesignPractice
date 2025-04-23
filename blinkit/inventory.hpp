#ifndef Inventory_hpp
#define Inventory_hpp   

#include "product.hpp"
#include <vector>   

class Inventory {
public:

    std::vector<Product> inventory;
    void addProduct(const Product &product);
    void removeProduct(int productId);
    Product* getProductById(int productId);
};  

#endif