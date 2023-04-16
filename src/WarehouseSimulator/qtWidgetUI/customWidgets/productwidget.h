//
// Created by piotr on 23.03.2023.
//

#ifndef WAREHOUSESIMULATOR_PRODUCTWIDGET_H
#define WAREHOUSESIMULATOR_PRODUCTWIDGET_H


#include <QWidget>
#include "../../businessLogic/Products/product.h"

class ProductWidget : public QWidget {
public:
    ProductWidget(QWidget *parent, Product *product);
    Product *getProduct();

private:
    Product *m_product;
    void createWidget();

};


#endif //WAREHOUSESIMULATOR_PRODUCTWIDGET_H
