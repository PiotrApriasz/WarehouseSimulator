//
// Created by piotr on 26.03.2023.
//

#ifndef WAREHOUSESIMULATOR_ACCESSPOLICIES_H
#define WAREHOUSESIMULATOR_ACCESSPOLICIES_H

/** @file
 * Enum zawierający polityki dostępu szaf w magazynie
 */
enum class AccessPolicies {
    FIFO = 0, /**< FIFO - First In First Out - Symuluje działanie kolejki. Pierwszy położony produkt musi być zdjęty w pierwszej kolejności. */
    LIFO = 1, /**< LIFO - Last In First Out - Symuluje działanie stosu. Ostatni położony produkt musi być zdjęty w pierwszej kolejności. */
    Free = 2 /**< Free - Dostęp dowolny - Symuluje działanie listy. Produkty można zdejmować dowolnie. */
};

#endif //WAREHOUSESIMULATOR_ACCESSPOLICIES_H
