//
// Created by piotr on 26.03.2023.
//

#include <utility>
#include <algorithm>
#include <vector>

#include "Wardrobe.h"

template <AccessPolicies AccessPolicyType>
Wardrobe<AccessPolicyType>::Wardrobe(std::vector<StorageBox> *shelves, std::string wardrobeId) :
        m_shelves(shelves),
        m_wardrobeId(std::move(wardrobeId))
{}

template <AccessPolicies AccessPolicyType>
bool Wardrobe<AccessPolicyType>::addProduct(Product product, std::string storageBoxId) {
    return false;
}

template <AccessPolicies AccessPolicyType>
bool Wardrobe<AccessPolicyType>::removerProduct(std::string storageBoxId) {

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

    return true;
}

bool Wardrobe<AccessPolicies::FIFO>::removerProduct(std::string storageBoxId) {

}

Wardrobe<AccessPolicies::LIFO>::Wardrobe(std::vector<StorageBox> *shelves, std::string wardrobeId) :
        m_shelves(shelves),
        m_wardrobeId(std::move(wardrobeId))
{}

bool Wardrobe<AccessPolicies::LIFO>::addProduct(Product product, std::string storageBoxId) {
    return false;
}

bool Wardrobe<AccessPolicies::LIFO>::removerProduct(std::string storageBoxId) {

}
