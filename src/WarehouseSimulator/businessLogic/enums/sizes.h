//
// Created by piotr on 20.03.2023.
//

#ifndef WAREHOUSESIMULATOR_SIZES_H
#define WAREHOUSESIMULATOR_SIZES_H


enum class Sizes {
    Small, Medium, Big
};

static const std::string SizesStrings[] = { "Small", "Medium", "Big" };

static const std::string getSizeText( int enumVal )
{
    return SizesStrings[enumVal];
}


#endif //WAREHOUSESIMULATOR_SIZES_H
