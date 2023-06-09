//
// Created by piotr on 20.03.2023.
//

#include "product.h"
#include "../enums/sizes.h"
#include <string>

Product::Product(std::string name, std::string imagePath, Sizes size) {
    m_name = name;
    m_imagePath = imagePath;
    m_productSize = size;
}

Sizes Product::getSize() {
    return m_productSize;
}

std::string Product::getProductSendInfo() {
    return "Product has been send";
}

std::string Product::getImagePath() {
    return m_imagePath;
}

std::string Product::getName() {
    return m_name;
}
