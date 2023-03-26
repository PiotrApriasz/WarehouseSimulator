//
// Created by piotr on 21.03.2023.
//

#include "GamingConsole.h"
#include "enums/sizes.h"

GamingConsole::GamingConsole(std::string name, std::string imagePath, Sizes size) :
        Product(name, imagePath, size) {

}

std::string GamingConsole::getProductSendInfo() {
    return "Gaming Console has been sand. Hope it will be good fo gaming";
}
