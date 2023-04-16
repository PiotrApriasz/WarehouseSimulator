//
// Created by piotr on 26.03.2023.
//

#ifndef WAREHOUSESIMULATOR_WARDROBE_H
#define WAREHOUSESIMULATOR_WARDROBE_H


#include <vector>
#include <queue>
#include <stack>
#include "enums/accesspolicies.h"
#include "StorageBox.h"

template <AccessPolicies AccessPolicyType> class Wardrobe {

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
        m_shelves(shelves),
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

template <> class Wardrobe<AccessPolicies::FIFO> {
public:
    Wardrobe(std::vector<StorageBox> shelves, std::string wardrobeId);
    bool addProduct(Product *product, std::string storageBoxId);
    bool removeProduct(Product *product, std::string storageBoxId);

private:
    std::vector<StorageBox> m_shelves;
    std::string m_wardrobeId;
    std::queue<Product*> m_products;
};

template <> class Wardrobe<AccessPolicies::LIFO> {
public:
    Wardrobe(std::vector<StorageBox> shelves, std::string wardrobeId);
    bool addProduct(Product *product, std::string storageBoxId);
    bool removeProduct(Product *product, std::string storageBoxId);

private:
    std::vector<StorageBox> m_shelves;
    std::string m_wardrobeId;
    std::stack<Product> m_products;
};


#endif //WAREHOUSESIMULATOR_WARDROBE_H
