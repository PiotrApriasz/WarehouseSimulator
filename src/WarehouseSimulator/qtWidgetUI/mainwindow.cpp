//
// Created by piotr on 20.03.2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "ui_MainWindow.h"
#include "productcreator.h"


MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow) {
    ui->setupUi(this);

    connect(ui->createProductBtn, SIGNAL(clicked()), this,
            SLOT(onCreateProductBtnClick()));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::onCreateProductBtnClick() {
    ProductCreator *productCreatorBox = new ProductCreator(this);
    productCreatorBox->show();
}


