//
// Created by piotr on 20.03.2023.
//

#include "Product.h"
#include "enums/productsize.h"
#include <string>

Product::Product(std::string name, std::string imagePath, ProductSize productSize) {
    m_name = name;
    m_imagePath = imagePath;
    m_productSize = productSize;
}
