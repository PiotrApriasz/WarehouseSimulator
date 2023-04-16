//
// Created by piotr on 20.03.2023.
//

#ifndef WAREHOUSESIMULATOR_PRODUCT_H
#define WAREHOUSESIMULATOR_PRODUCT_H


#include <string>
#include "../enums/sizes.h"

class Product {
public:
    explicit Product(std::string name, std::string imagePath, Sizes size);

    std::string getName();
    std::string getImagePath();
    Sizes getSize();

    virtual std::string getProductSendInfo();

protected:
    std::string m_name;
    std::string m_imagePath;
    Sizes m_productSize;
};


#endif //WAREHOUSESIMULATOR_PRODUCT_H
