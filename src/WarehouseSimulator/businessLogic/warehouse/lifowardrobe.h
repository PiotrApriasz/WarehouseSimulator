#pragma once

#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>

#include "../enums/accesspolicies.h"
#include "storagebox.h"
#include "wardrobe.h"

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

