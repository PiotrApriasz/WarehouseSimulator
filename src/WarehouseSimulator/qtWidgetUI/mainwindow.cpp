//
// Created by piotr on 20.03.2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "ui_MainWindow.h"


MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow) {
    ui->setupUi(this);

    connect(ui->createProductBtn, SIGNAL(clicked()), this,
            SLOT(onCreateProductBtnClick()));
    connect(ui->smallProductBtn, SIGNAL(clicked()), this,
            SLOT(onProductBtnClick(ProductSize::Small)));
    connect(ui->mediumProductBtn, SIGNAL(clicked()), this,
            SLOT(onProductBtnClick(ProductSize::Medium)));
    connect(ui->bigProductBtn, SIGNAL(clicked()), this,
            SLOT(onProductBtnClick(ProductSize::Big)));

    madeUnVisible();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::madeUnVisible() {
    ui->smallProductBtn->setHidden(true);
    ui->mediumProductBtn->setHidden(true);
    ui->bigProductBtn->setHidden(true);
}

void MainWindow::onCreateProductBtnClick() {
    ui->smallProductBtn->setHidden(false);
    ui->mediumProductBtn->setHidden(false);
    ui->bigProductBtn->setHidden(false);
}

void MainWindow::onProductBtnClick(ProductSize productSize) {
    madeUnVisible();

    switch (productSize) {

    }
}
