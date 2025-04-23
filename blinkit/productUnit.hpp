#ifndef Product_hpp
#define Product_hpp
#include<string>

// Product = A catalog item that a user can browse. like "Amul milk, "Pepsi".
class ProductUnit {
    public: 
    int productUnitId;
    std::string ProductUnitName;
    ProductUnit(int productUnitId, std::string ProductUnitName);
};

#endif