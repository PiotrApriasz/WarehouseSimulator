//
// Created by piotr on 29.03.2023.
//

#ifndef WAREHOUSESIMULATOR_KEYBOARD_H
#define WAREHOUSESIMULATOR_KEYBOARD_H

#include "product.h"
#include "../enums/sizes.h"

/**
 * Klasa opisująca produkt Keyboard dziedzicząca po klasie Product
 */
class Keyboard : public Product {
public:
    explicit Keyboard(std::string name, std::string imagePath, Sizes size);

    /**
     * @return Informacja, którą można wyświetlić podczas wysyłki/zdejmowania towaru
     */
    std::string getProductSendInfo() override;
};


#endif //WAREHOUSESIMULATOR_KEYBOARD_H
