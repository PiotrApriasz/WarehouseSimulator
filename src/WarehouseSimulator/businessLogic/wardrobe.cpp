//
// Created by piotr on 26.03.2023.
//

#include <utility>

#include "Wardrobe.h"

template <AccessPolicies AccessPolicyType>
Wardrobe<AccessPolicyType>::Wardrobe(std::vector<std::vector<StorageBox>> shelves, std::string wardrobeId) :
        m_shelves(std::move(shelves)),
        m_wardrobeId(std::move(wardrobeId))
{}

template <AccessPolicies AccessPolicyType>
bool Wardrobe<AccessPolicyType>::addProduct(Product product, std::string storageBoxId) {

}

template <AccessPolicies AccessPolicyType>
bool Wardrobe<AccessPolicyType>::removerProduct(std::string storageBoxId) {

}



Wardrobe<AccessPolicies::FIFO>::Wardrobe(std::vector<std::vector<StorageBox>> shelves, std::string wardrobeId) :
        m_shelves(std::move(shelves)),
        m_wardrobeId(std::move(wardrobeId))
{}

bool Wardrobe<AccessPolicies::FIFO>::addProduct(Product product, std::string storageBoxId) {

}

bool Wardrobe<AccessPolicies::FIFO>::removerProduct(std::string storageBoxId) {

}

Wardrobe<AccessPolicies::LIFO>::Wardrobe(std::vector<std::vector<StorageBox>> shelves, std::string wardrobeId) :
        m_shelves(std::move(shelves)),
        m_wardrobeId(std::move(wardrobeId))
{}

bool Wardrobe<AccessPolicies::LIFO>::addProduct(Product product, std::string storageBoxId) {

}

bool Wardrobe<AccessPolicies::LIFO>::removerProduct(std::string storageBoxId) {

}
