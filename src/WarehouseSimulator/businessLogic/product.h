//
// Created by piotr on 20.03.2023.
//

#ifndef WAREHOUSESIMULATOR_PRODUCT_H
#define WAREHOUSESIMULATOR_PRODUCT_H


#include <string>
#include "enums/productsize.h"

class Product {
public:
    explicit Product(std::string name, std::string imagePath, ProductSize productSize);

protected:
    std::string m_name;
    std::string m_imagePath;
    ProductSize m_productSize;
};


#endif //WAREHOUSESIMULATOR_PRODUCT_H
