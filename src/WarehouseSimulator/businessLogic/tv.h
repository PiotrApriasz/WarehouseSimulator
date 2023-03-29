//
// Created by piotr on 29.03.2023.
//

#ifndef WAREHOUSESIMULATOR_TV_H
#define WAREHOUSESIMULATOR_TV_H

#include "product.h"
#include "enums/sizes.h"


class TV : public Product {
public:
    explicit TV(std::string name, std::string imagePath, Sizes size);

    std::string getProductSendInfo() override;
};


#endif //WAREHOUSESIMULATOR_TV_H
