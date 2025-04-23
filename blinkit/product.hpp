#ifndef ProductUnit_hpp
#define ProductUnit_hpp
#include<string>
#include<vector>
#include "productUnit.hpp"

// ProductUnit = A specific unit of that product that is actually stocked in a warehouse (think of it like an individual box with a barcode).
// A cartoon of all Amul milk in a warehouse would be a product unit.

class Product{
    public:
        int productId;
        std::string productName;
        std::vector<ProductUnit> products;
        Product(int productId, std::string productName);
        void addProduct(int productId, std::string ProductName);
        void removeProduct(int productId);
        int getStock();
};
#endif