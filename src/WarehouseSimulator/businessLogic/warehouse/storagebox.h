//
// Created by piotr on 29.03.2023.
//

#ifndef WAREHOUSESIMULATOR_STORAGEBOX_H
#define WAREHOUSESIMULATOR_STORAGEBOX_H

#include "../products/product.h"
#include "../enums/sizes.h"

/**
 * Klasa opisująca pudło przchowywania, w którym przechowywane będą produktu
 */
class StorageBox {
public:
    StorageBox(Sizes size, std::string storageBoxId);

    /**
     * Dodaje produkt do pudła
     * @param product Wskaźnik na obiekt wybranego produktu
     * @return Wartość bool określającą czy udało się dodać produkt
     */
    bool setProduct(Product *product);

    /**
     * @return Wskaźnik na produkt przechowywany w pudle przechowywania
     */
    Product *getProduct();

    /**
     * @return Wartość enum rozmiaru jaki może przechowywać dane pudło przechowywania
     */
    Sizes getSize();

    /**
     * @return Identyfikator danego pudła przechowywania
     */
    std::string getStorageBoxId();

private:
    Product *m_product = nullptr;
    Sizes m_size;
    std::string m_storageBoxId;
};


#endif //WAREHOUSESIMULATOR_STORAGEBOX_H
