//
// Created by piotr on 17.04.2023.
//

#ifndef WAREHOUSESIMULATOR_PRODUCTFACTORY_H
#define WAREHOUSESIMULATOR_PRODUCTFACTORY_H


#include "Product.h"
#include "../enums/products.h"
#include "../enums/sizes.h"

class ProductFactory {
public:
    static Product* CreateProduct(Products selectedProduct, Sizes selectedSize);
private:
    ProductFactory();
};


#endif //WAREHOUSESIMULATOR_PRODUCTFACTORY_H
