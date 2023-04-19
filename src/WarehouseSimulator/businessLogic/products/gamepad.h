//
// Created by piotr on 29.03.2023.
//

#ifndef WAREHOUSESIMULATOR_GAMEPAD_H
#define WAREHOUSESIMULATOR_GAMEPAD_H

#include "product.h"
#include "../enums/sizes.h"

/**
 * Klasa opisująca produkt Gamepad dziedzicząca po klasie Product
 */
class Gamepad : public Product {

public:
    explicit Gamepad(std::string name, std::string imagePath, Sizes size);

    /**
     * @return Informacja, którą można wyświetlić podczas wysyłki/zdejmowania towaru
     */
    std::string getProductSendInfo() override;
};


#endif //WAREHOUSESIMULATOR_GAMEPAD_H
