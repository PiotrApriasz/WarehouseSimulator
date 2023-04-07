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
#include "../businessLogic/wardrobe.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

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

    void initializeWardrobes();
    void initializeWardrobe1ClickHandlers();
    void initializeWardrobe2ClickHandlers();
    void initializeWardrobe3ClickHandlers();


    bool addProductToStorageBox(Product *product, const std::string& storageBoxId);
    bool deleteProductFromStorageBox(Product *product, const std::string& storageBoxId);
    void showMessageBox(const std::string& title, std::string  text);

private slots:
    void onCreateProductBtnClick();
    void addNewProduct(QWidget *widget);
    void moveProductToWardrobe(QWidget *widget);
    void onSendBtnClick();
};


#endif //WAREHOUSESIMULATOR_MAINWINDOW_H
