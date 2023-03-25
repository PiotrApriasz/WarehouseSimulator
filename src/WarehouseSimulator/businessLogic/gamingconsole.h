//
// Created by piotr on 21.03.2023.
//

#ifndef WAREHOUSESIMULATOR_GAMINGCONSOLE_H
#define WAREHOUSESIMULATOR_GAMINGCONSOLE_H

#include "product.h"
#include "enums/productsize.h"

class GamingConsole : public Product {
public:
    explicit GamingConsole(std::string name, std::string imagePath, ProductSize productSize);
};


#endif //WAREHOUSESIMULATOR_GAMINGCONSOLE_H
