#pragma once

#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>

#include "../enums/accesspolicies.h"
#include "storagebox.h"

template <AccessPolicies AccessPolicyType>
class Wardrobe {
public:
    explicit Wardrobe(std::vector<StorageBox> shelves, std::string wardrobeId);
    bool addProduct(Product *product, std::string storageBoxId);
    bool removeProduct(Product *product, std::string storageBoxId);

private:
    std::vector<StorageBox> m_shelves;
    std::string m_wardrobeId;
    std::vector<Product*> m_products;
};

template <AccessPolicies AccessPolicyType>
Wardrobe<AccessPolicyType>::Wardrobe(std::vector<StorageBox> shelves, std::string wardrobeId) :
        m_shelves(std::move(shelves)),
        m_wardrobeId(std::move(wardrobeId))
{}

template <AccessPolicies AccessPolicyType>
bool Wardrobe<AccessPolicyType>::addProduct(Product *product, std::string storageBoxId) {
    auto shelvesSize = m_shelves.size();
    auto productsSize = m_products.size();

    if (shelvesSize == productsSize)
        return false;

    char last_char = storageBoxId.back();
    int id = last_char - '0';

    if (!m_shelves[id - 1].setProduct(product))
        return false;

    m_products.push_back(product);

    return true;
}

template <AccessPolicies AccessPolicyType>
bool Wardrobe<AccessPolicyType>::removeProduct(Product *product, std::string storageBoxId) {
    m_products.erase(std::remove(m_products.begin(), m_products.end(), product), m_products.end());

    char last_char = storageBoxId.back();
    int id = last_char - '0';

    if (!m_shelves[id - 1].setProduct(nullptr))
        return false;

    return true;
}