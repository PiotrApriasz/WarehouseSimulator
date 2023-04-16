//
// Created by piotr on 29.03.2023.
//

#include <string>
#include "gamepad.h"
#include "../enums/sizes.h"

Gamepad::Gamepad(std::string name, std::string imagePath, Sizes size) :
        Product(name, imagePath, size) {

}

std::string Gamepad::getProductSendInfo() {
    return "Gamepad has been sent. Hope it will fit hands well";
}
