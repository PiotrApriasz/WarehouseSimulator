//
// Created by piotr on 20.03.2023.
//

#ifndef WAREHOUSESIMULATOR_PRODUCT_H
#define WAREHOUSESIMULATOR_PRODUCT_H


#include <string>
#include "../enums/sizes.h"

/**
 * Bazowa klasa opisująca produkty
 */
class Product {
public:
    explicit Product(std::string name, std::string imagePath, Sizes size);

    /**
     * @return Nazwa produktu
     */
    std::string getName();
    /**
     * @return Ściężka do obrazu wizualizującego produkt
     */
    std::string getImagePath();
    /**
     * @return Rozmiar produktu
     */
    Sizes getSize();

    /**
     * Metoda wirtualna, którą mogą nadpisywać klasy dziedziczące
     * @return Informacja, którą można wyświetlić podczas wysyłki/zdejmowania towaru
     */
    virtual std::string getProductSendInfo();

protected:
    std::string m_name;
    std::string m_imagePath;
    Sizes m_productSize;
};


#endif //WAREHOUSESIMULATOR_PRODUCT_H
