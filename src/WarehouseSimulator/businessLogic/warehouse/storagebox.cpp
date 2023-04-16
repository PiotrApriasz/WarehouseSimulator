//
// Created by piotr on 29.03.2023.
//

#include "storagebox.h"

StorageBox::StorageBox(Sizes size, std::string storageBoxId) :
    m_size(std::move(size)),
    m_storageBoxId(std::move(storageBoxId))
{
}

bool StorageBox::setProduct(Product *product) {
    if (product != nullptr) {
        if (m_product != nullptr)
            return false;

        if (product->getSize() != m_size)
            return false;
    }

    m_product = product;
    return true;
}

Product *StorageBox::getProduct() {
    if (m_product != nullptr)
        return m_product;

    return nullptr;
}

Sizes StorageBox::getSize() {
    return m_size;
}

std::string StorageBox::getStorageBoxId() {
    return m_storageBoxId;
}




