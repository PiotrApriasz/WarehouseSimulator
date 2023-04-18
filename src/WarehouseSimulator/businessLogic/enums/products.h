//
// Created by piotr on 21.03.2023.
//

#ifndef WAREHOUSESIMULATOR_PRODUCTS_H
#define WAREHOUSESIMULATOR_PRODUCTS_H

enum class Products {
    GamingConsole = 0, GamePad = 1, TV = 2, Keyboard = 3
};

static const std::vector<std::string> ProductsStrings = { "GamingConsole", "GamePad", "TV", "Keyboard" };

static const std::string getProductText( int enumVal )
{
    return ProductsStrings[enumVal];
}

#endif //WAREHOUSESIMULATOR_PRODUCTS_H
