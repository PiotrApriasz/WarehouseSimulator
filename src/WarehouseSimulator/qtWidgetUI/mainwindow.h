//
// Created by piotr on 20.03.2023.
//

#ifndef WAREHOUSESIMULATOR_MAINWINDOW_H
#define WAREHOUSESIMULATOR_MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "../businessLogic/enums/sizes.h"
#include "productcreator.h"
#include "events/clickhandler.h"
#include "../businessLogic/warehouse/wardrobe.h"
#include "../businessLogic/warehouse/fifowardrobe.h"
#include "../businessLogic/warehouse/lifowardrobe.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * Klasa reprezentująca główne okno aplikacji gdzie dostępna jest większość jej funkcjonalności. Dziedziczy po QMainWindow.
 */
class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

private:
    ProductCreator* m_productDB;
    Ui::MainWindow *ui;

    Wardrobe<AccessPolicies::FIFO> *m_fifoWardrobe;
    Wardrobe<AccessPolicies::LIFO> *m_lifoWardrobe;
    Wardrobe<AccessPolicies::Free> *m_freeWardrobe;

    /**
     * Inijalizuje obieky szaf, które będzie można uzywać podczas obsługi programu
     */
    void initializeWardrobes();
    /**
     * Inicjalizuje obsługę kliknieć dla szafy 1
     */
    void initializeWardrobe1ClickHandlers();
    /**
     * Inicjalizuje obsługę kliknieć dla szafy 2
     */
    void initializeWardrobe2ClickHandlers();
    /**
     * Inicjalizuje obsługę kliknieć dla szafy 3
     */
    void initializeWardrobe3ClickHandlers();

    /**
     * Główna metoda dodająca produkt do wybranego pudła przechowywania
     * @param product Wskaźnik na obiekt dodawanego produktu
     * @param storageBoxId Identyfikator wybranego pudła przechowywania, do którego użytkownik chce dodać produkt
     * @return Wartość bool określającą czy udało się dodać produkt
     */
    bool addProductToStorageBox(Product *product, const std::string& storageBoxId);

    /**
     * Główna metoda usuwania wybranego produktu z pudła przechowywania
     * @param product Wskaźnik na obiekt usuwanego produktu
     * @param storageBoxId Identyfikator wybranego pudła przechowywania, z którego użytkownik chce zdjąć produkt
     * @return  Wartość bool określającą czy udało się zdjąć produkt
     */
    bool deleteProductFromStorageBox(Product *product, const std::string& storageBoxId);

    /**
     * Pokazuje okno dialogowe z podanym tytułem i treścią
     * @param title Tytuł dla okna dialogowego
     * @param text Treść okna dialogowego
     */
    static void showMessageBox(const std::string& title, const std::string&  text);

private slots:
    /**
     * Slot wywoływany po kliknięciu przycisku tworzenia produktu. Pokazuje okno kreatora produktów
     */
    void onCreateProductBtnClick();

    /**
     * Slot wywoływany w momencie utworzenia nowego produktu w kreatorze produktów. Dodaje widget produktu do okna nowych produktów
     * @param widget Utworzony widget produktu
     */
    void addNewProduct(QWidget *widget);

    /**
     * Slot wywoływany w momencie chęci dodania produktu do szafy lub jego zdjęcia. Implementuje logikę przenoszenia widgetów w wybrane miejsca UI
     * @param widget
     */
    void moveProduct(QWidget *widget);

    /**
     * Slot wywoływany w momencie kliknięcia przycisku wysłania/usunięcia produktu. Obsługuje logikę niszczenia obiektu i widgetu produktu
     */
    void onSendBtnClick();
};


#endif //WAREHOUSESIMULATOR_MAINWINDOW_H
