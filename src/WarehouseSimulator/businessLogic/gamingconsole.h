//
// Created by piotr on 21.03.2023.
//

#ifndef WAREHOUSESIMULATOR_GAMINGCONSOLE_H
#define WAREHOUSESIMULATOR_GAMINGCONSOLE_H

#include "product.h"
#include "enums/sizes.h"

class GamingConsole : public Product {
public:
    explicit GamingConsole(std::string name, std::string imagePath, Sizes size);

    std::string getProductSendInfo() override;
};


#endif //WAREHOUSESIMULATOR_GAMINGCONSOLE_H
