//
// Created by piotr on 20.03.2023.
//

#include <QPushButton>

#ifndef WAREHOUSESIMULATOR_PRODUCTBUTTON_H
#define WAREHOUSESIMULATOR_PRODUCTBUTTON_H


class ProductButton : public QPushButton {
    Q_OBJECT

public:
    explicit ProductButton(QPushButton *button = nullptr);
};


#endif //WAREHOUSESIMULATOR_PRODUCTBUTTON_H
