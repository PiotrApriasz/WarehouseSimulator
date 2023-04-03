//
// Created by piotr on 29.03.2023.
//

#ifndef WAREHOUSESIMULATOR_STORAGEBOX_H
#define WAREHOUSESIMULATOR_STORAGEBOX_H

#include "Product.h"
#include "enums/sizes.h"

class StorageBox {
public:
    StorageBox(Sizes size, std::string storageBoxId);
    bool setProduct(Product *product);
    Product *getProduct();
    Sizes getSize();
    std::string getStorageBoxId();

private:
    Product *m_product;
    Sizes m_size;
    std::string m_storageBoxId;
};


#endif //WAREHOUSESIMULATOR_STORAGEBOX_H
