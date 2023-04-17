//
// Created by piotr on 17.04.2023.
//

#include "ProductFactory.h"
#include "../helpers/imagehelper.h"
#include "gamingconsole.h"
#include "tv.h"
#include "keyboard.h"
#include "gamepad.h"

Product *ProductFactory::CreateProduct(Products selectedProduct, Sizes selectedSize) {
    auto product = getProductText(static_cast<int>(selectedProduct));
    auto imagePath = ImageHelper::getProductImagePath(selectedProduct, selectedSize);

    switch (selectedProduct) {
        case Products::GamingConsole : {
            return new GamingConsole(product, imagePath, selectedSize);
        }
        case Products::GamePad : {
            return new Gamepad(product, imagePath, selectedSize);
        }
        case Products::TV : {
            return new TV(product, imagePath, selectedSize);
        }
        case Products::Keyboard : {
            return new Keyboard(product, imagePath, selectedSize);
        }
    }

    return nullptr;
}

ProductFactory::ProductFactory() = default;
