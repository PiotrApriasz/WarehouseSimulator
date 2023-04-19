//
// Created by piotr on 23.03.2023.
//

#ifndef WAREHOUSESIMULATOR_PRODUCTWIDGET_H
#define WAREHOUSESIMULATOR_PRODUCTWIDGET_H


#include <QWidget>
#include "../../businessLogic/Products/product.h"

/**
 * Klasa widgetu produktu dziedzicząca po klasie QWidget. Określa widget produktu wyświetlanego w UI
 */
class ProductWidget : public QWidget {
public:
    ProductWidget(QWidget *parent, Product *product);
    /**
     * @return Wskaźnik na produkt jakiego wyświetlanie obsługuje
     */
    Product *getProduct();

private:
    Product *m_product;
    void createWidget();

};


#endif //WAREHOUSESIMULATOR_PRODUCTWIDGET_H
