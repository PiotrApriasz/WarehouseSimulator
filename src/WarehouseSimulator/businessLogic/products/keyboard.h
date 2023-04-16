//
// Created by piotr on 29.03.2023.
//

#ifndef WAREHOUSESIMULATOR_KEYBOARD_H
#define WAREHOUSESIMULATOR_KEYBOARD_H

#include "product.h"
#include "../enums/sizes.h"


class Keyboard : public Product {
public:
    explicit Keyboard(std::string name, std::string imagePath, Sizes size);

    std::string getProductSendInfo() override;
};


#endif //WAREHOUSESIMULATOR_KEYBOARD_H
