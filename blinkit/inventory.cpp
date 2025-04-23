#include "inventory.hpp"

void Inventory::addProduct(const Product &product){
    this->inventory.push_back(product);
}
void Inventory::removeProduct(int productId){
    this->inventory.erase(this->inventory.begin() + productId);
}

Product *Inventory::getProductById(int productId){
    for (auto& p : this->inventory) {
        if (p.productId == productId) {
            return &p;
        }
    }
    return nullptr;
}