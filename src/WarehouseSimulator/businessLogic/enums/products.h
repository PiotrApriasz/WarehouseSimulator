//
// Created by piotr on 21.03.2023.
//

#ifndef WAREHOUSESIMULATOR_PRODUCTS_H
#define WAREHOUSESIMULATOR_PRODUCTS_H

/** @file
 * Enum zawierający dostępne produkty jakie można przechowywać w aplikacji
 */
enum class Products {
    GamingConsole = 0, /**< GamingConsole - Konsola do grania (np. Xbox) */
    GamePad = 1, /**< GamePad - Kontroler do kosnoli czy komputera */
    TV = 2, /**< TV - Telewizor */
    Keyboard = 3 /**< Keyboard - Klawiatura */
};

/**
 * Właściwość przechowująca w formacie string nazwy poszczególnych wartości enum
 */
static const std::vector<std::string> ProductsStrings = { "GamingConsole", "GamePad", "TV", "Keyboard" };

/**
 * Zwraca wybraną nazwę tesktową pola enum
 * @param enumVal indeks wskazujący na to, którą nazwę enum metoda ma zwrócić
 * @return Wartość enum w formacie string
 */
static const std::string getProductText( int enumVal )
{
    return ProductsStrings[enumVal];
}

#endif //WAREHOUSESIMULATOR_PRODUCTS_H
