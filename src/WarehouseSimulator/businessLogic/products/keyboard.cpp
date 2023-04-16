//
// Created by piotr on 29.03.2023.
//

#include "keyboard.h"
#include "../enums/sizes.h"
#include <string>

Keyboard::Keyboard(std::string name, std::string imagePath, Sizes size) :
    Product(name, imagePath, size) {

}

std::string Keyboard::getProductSendInfo() {
    return "Keyboard has been sent. Hope the sound of keys is nice";
}
