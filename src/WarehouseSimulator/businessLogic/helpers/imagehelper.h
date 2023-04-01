//
// Created by piotr on 01.04.2023.
//

#ifndef WAREHOUSESIMULATOR_IMAGEHELPER_H
#define WAREHOUSESIMULATOR_IMAGEHELPER_H


#include <string>
#include "../enums/sizes.h"
#include "../enums/products.h"

class ImageHelper {
public:
    static std::string getProductImagePath(Products product, Sizes size);
private:
    ImageHelper() = default;
    static std::string const m_mainImagesPath;
};


#endif //WAREHOUSESIMULATOR_IMAGEHELPER_H
