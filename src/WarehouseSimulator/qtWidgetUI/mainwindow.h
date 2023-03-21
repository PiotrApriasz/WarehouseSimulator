//
// Created by piotr on 20.03.2023.
//

#ifndef WAREHOUSESIMULATOR_MAINWINDOW_H
#define WAREHOUSESIMULATOR_MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "../businessLogic/productsize.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

private:
    Ui::MainWindow *ui;
    void madeUnVisible();

private slots:
    void onCreateProductBtnClick();
};


#endif //WAREHOUSESIMULATOR_MAINWINDOW_H
