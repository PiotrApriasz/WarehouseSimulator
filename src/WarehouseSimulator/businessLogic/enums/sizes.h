//
// Created by piotr on 20.03.2023.
//

#ifndef WAREHOUSESIMULATOR_SIZES_H
#define WAREHOUSESIMULATOR_SIZES_H

/** @file
 * Enum zawierający dostępne rozmiary produktów
 */
enum class Sizes {
    Small, Medium, Big
};

/**
 * Właściwość przechowująca w formacie string nazwy poszczególnych wartości enum
 */
static const std::vector<std::string> SizesStrings = { "Small", "Medium", "Big" };

/**
 * Zwraca wybraną nazwę tesktową pola enum
 * @param enumVal indeks wskazujący na to, którą nazwę enum metoda ma zwrócić
 * @return Wartość enum w formacie string
 */
static const std::string getSizeText( int enumVal )
{
    return SizesStrings[enumVal];
}


#endif //WAREHOUSESIMULATOR_SIZES_H
