//
// Created by piotr on 01.04.2023.
//

#ifndef WAREHOUSESIMULATOR_IMAGEHELPER_H
#define WAREHOUSESIMULATOR_IMAGEHELPER_H


#include <string>
#include "../enums/sizes.h"
#include "../enums/products.h"

/**
 * Klasa statyczna wspomagająca pracę z obrazami produktów
 */
class ImageHelper {
public:
    /**
     * Metoda zwracająca ściężkę do odpowiedniego obrazu produktu
     * @param product Obiekt produktu, którego obraz należy pobrać
     * @param size Rozmiar produktu
     * @return Ścieżka dostępu do odnalezionego towaru
     */
    static std::string getProductImagePath(Products product, Sizes size);
private:
    ImageHelper() = default;
    static std::string const m_mainImagesPath;
};


#endif //WAREHOUSESIMULATOR_IMAGEHELPER_H
