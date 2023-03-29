//
// Created by piotr on 23.03.2023.
//

#ifndef WAREHOUSESIMULATOR_PRODUCTWIDGET_H
#define WAREHOUSESIMULATOR_PRODUCTWIDGET_H


#include <QWidget>
#include "../../businessLogic/product.h"

class ProductWidget : public QWidget {
public:
    ProductWidget(QWidget *parent, Product *product);

private:
    bool m_isHighlighted;
    Product *m_product;

    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void createWidget();

};


#endif //WAREHOUSESIMULATOR_PRODUCTWIDGET_H