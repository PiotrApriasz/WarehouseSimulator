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
    ClickHandler *m_clickHandlerw1f4;

private slots:
    void onCreateProductBtnClick();
    void addNewProduct(QWidget *widget);
    void moveProductToWardrobe(QWidget *widget);
};


#endif //WAREHOUSESIMULATOR_MAINWINDOW_H
