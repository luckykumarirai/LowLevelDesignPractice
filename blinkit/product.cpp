#include "product.hpp"

Product::Product(int productId, std::string productName){
    this->productId = productId;
    this->productName = productName;    
}

void Product::addProduct(int productId, std::string productName){
    ProductUnit product(productId, productName);
    this->products.push_back(product);
};

void Product::removeProduct(int productId){
    for (int i = 0;i<products.size();i++){
        if (products[i].productUnitId == productId){
            products.erase(products.begin() + i);
            break;
        }   
    }
}
int Product::getStock(){
    return products.size(); 
}