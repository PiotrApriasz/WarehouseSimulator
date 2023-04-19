#pragma once

#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>

#include "../enums/accesspolicies.h"
#include "storagebox.h"
#include "wardrobe.h"

/**
 * Klasa specjalizacji szablonów dla polityki dostępu FIFO. Do przechowywania produktów wykorzystuje kolejke
 */
template <> class Wardrobe<AccessPolicies::FIFO> {
public:
    Wardrobe(std::vector<StorageBox> shelves, std::string wardrobeId);
    /**
     * Dodaje przekazany produkt do wybranego z ui pudła przechowywania
     * @param product Wskaźnik przekazywanego obiektu produktu
     * @param storageBoxId Identyfikator wybranego z ui pudła przechowywania
     * @return Wartość bool określającą czy udało się dodać produkt
     */
    bool addProduct(Product *product, std::string storageBoxId);
    /**
     * Zdejmuje produkt z wybranej półki przechowywania o ile zezwala na to polityka dostepu szafy
     * @param product Wskaźnik na obiekt produktu do zdjęcia z szafy
     * @param storageBoxId Identyfikator wybranego z ui pudła przechowywania
     * @return Wartość bool określającą czy dany produkt można zdjąć z pudła
     */
    bool removeProduct(Product *product, std::string storageBoxId);

private:
    std::vector<StorageBox> m_shelves;
    std::string m_wardrobeId;
    std::queue<Product*> m_products;
};
