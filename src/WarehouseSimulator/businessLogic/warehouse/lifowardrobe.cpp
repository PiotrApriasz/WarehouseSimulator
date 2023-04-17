//
// Created by piotr on 17.04.2023.
//

#include "LifoWardrobe.h"

Wardrobe<AccessPolicies::LIFO>::Wardrobe(std::vector<StorageBox> shelves, std::string wardrobeId) :
        m_shelves(std::move(shelves)),
        m_wardrobeId(std::move(wardrobeId))
{}

bool Wardrobe<AccessPolicies::LIFO>::addProduct(Product *product, std::string storageBoxId) {
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

bool Wardrobe<AccessPolicies::LIFO>::removeProduct(Product *product, std::string storageBoxId) {
    auto test = m_products.top();

    if (test == product) {
        m_products.pop();

        char last_char = storageBoxId.back();
        int id = last_char - '0';

        if (!m_shelves[id - 1].setProduct(nullptr))
            return false;

        return true;
    }

    return false;
}