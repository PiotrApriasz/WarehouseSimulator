//
// Created by piotr on 26.03.2023.
//

#include <utility>
#include <algorithm>
#include <vector>

#include "Wardrobe.h"


Wardrobe<AccessPolicies::Free>::Wardrobe(std::vector<StorageBox> shelves, std::string wardrobeId) :
        m_shelves(std::move(shelves)),
        m_wardrobeId(std::move(wardrobeId))
{}

bool Wardrobe<AccessPolicies::Free>::addProduct(Product *product, std::string storageBoxId) {
    return false;
}

bool Wardrobe<AccessPolicies::Free>::removeProduct(Product *product) {

}

Wardrobe<AccessPolicies::FIFO>::Wardrobe(std::vector<StorageBox> shelves, std::string wardrobeId) :
        m_shelves(std::move(shelves)),
        m_wardrobeId(std::move(wardrobeId))
{}

bool Wardrobe<AccessPolicies::FIFO>::addProduct(Product *product, std::string storageBoxId) {
    auto shelvesSize = m_shelves.size();
    auto productsSize = m_products.size();

    if (shelvesSize == productsSize)
        return false;

    char last_char = storageBoxId.back();
    int id = last_char - '0';

    if (!m_shelves[id - 1].setProduct(product))
         return false;

    m_products.push(product);

    return true;
}

bool Wardrobe<AccessPolicies::FIFO>::removeProduct(Product *product) {
    if (m_products.front() == product) {
        m_products.pop();
        return true;
    }
    return false;
}

Wardrobe<AccessPolicies::LIFO>::Wardrobe(std::vector<StorageBox> shelves, std::string wardrobeId) :
        m_shelves(std::move(shelves)),
        m_wardrobeId(std::move(wardrobeId))
{}

bool Wardrobe<AccessPolicies::LIFO>::addProduct(Product product, std::string storageBoxId) {
    return false;
}

bool Wardrobe<AccessPolicies::LIFO>::removerProduct(std::string storageBoxId) {

}
