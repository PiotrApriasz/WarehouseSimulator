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
    Wardrobe(std::vector<StorageBox> *shelves, std::string wardrobeId);
    bool addProduct(Product product, std::string storageBoxId);
    bool removerProduct(std::string storageBoxId);

private:
    std::vector<StorageBox> *m_shelves;
    std::string m_wardrobeId;
    std::vector<Product> m_products;
};

template <> class Wardrobe<AccessPolicies::FIFO> {
public:
    Wardrobe(std::vector<StorageBox> shelves, std::string wardrobeId);
    bool addProduct(Product *product, std::string storageBoxId);
    bool removerProduct(std::string storageBoxId);

private:
    std::vector<StorageBox> m_shelves;
    std::string m_wardrobeId;
    std::queue<Product> m_products;
};

template <> class Wardrobe<AccessPolicies::LIFO> {
public:
    Wardrobe(std::vector<StorageBox> *shelves, std::string wardrobeId);
    bool addProduct(Product product, std::string storageBoxId);
    bool removerProduct(std::string storageBoxId);

private:
    std::vector<StorageBox> *m_shelves;
    std::string m_wardrobeId;
    std::stack<Product> m_products;
};


#endif //WAREHOUSESIMULATOR_WARDROBE_H
