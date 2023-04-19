//
// Created by piotr on 17.04.2023.
//

#ifndef WAREHOUSESIMULATOR_PRODUCTFACTORY_H
#define WAREHOUSESIMULATOR_PRODUCTFACTORY_H


#include "Product.h"
#include "../enums/products.h"
#include "../enums/sizes.h"

/**
 * Klasa udostępniająca możliwość łatwego tworzenia nowcyh obiektów produktów
 */
class ProductFactory {
public:
    /**
     * Tworzy obiekt produktu na podstawie przekazanych parametrów
     * @param selectedProduct Wartość enum wybranego produktu
     * @param selectedSize Wartość enum wybranego rozmiaru produktu
     * @return Wskaźnik na wytworzony obiekt produktu
     */
    static Product* CreateProduct(Products selectedProduct, Sizes selectedSize);
private:
    ProductFactory();
};


#endif //WAREHOUSESIMULATOR_PRODUCTFACTORY_H
