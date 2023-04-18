//
// Created by piotr on 20.03.2023.
//

#ifndef WAREHOUSESIMULATOR_SIZES_H
#define WAREHOUSESIMULATOR_SIZES_H

#include <vector>


enum class Sizes {
    Small, Medium, Big
};

static const std::vector<std::string> SizesStrings = { "Small", "Medium", "Big" };

static const std::string getSizeText( int enumVal )
{
    return SizesStrings[enumVal];
}


#endif //WAREHOUSESIMULATOR_SIZES_H
