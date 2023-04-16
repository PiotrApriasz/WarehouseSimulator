//
// Created by piotr on 29.03.2023.
//

#include "tv.h"
#include "../enums/sizes.h"
#include <string>

TV::TV(std::string name, std::string imagePath, Sizes size) :
        Product(name, imagePath, size) {

}

std::string TV::getProductSendInfo() {
    return "TV has been sent. Hope the screen is sharp";
}

