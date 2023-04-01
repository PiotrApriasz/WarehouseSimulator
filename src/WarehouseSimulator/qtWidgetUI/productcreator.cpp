//
// Created by piotr on 21.03.2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_ProductCreator.h" resolved

#include <iostream>
#include <QHBoxLayout>
#include "productcreator.h"
#include "ui_ProductCreator.h"
#include "../businessLogic/enums/products.h"
#include "../businessLogic/helpers/imagehelper.h"


ProductCreator::ProductCreator(QWidget *parent) :
        QDialog(parent), ui(new Ui::ProductCreator) {
    ui->setupUi(this);

    ui->productCB->addItems({"Gaming Console", "Game Pad", "TV", "Keyboard"});
    ui->sizeCB->addItems({"Small", "Medium", "Big"});

    connect(ui->cancelBtn, SIGNAL(clicked()), this,
            SLOT(onCancelBtnClick()));

    connect(ui->createBtn, SIGNAL(clicked()),
            SLOT(onCreateBtnClick()));

    m_mainWindow = parent;
}

ProductCreator::~ProductCreator() {
    delete ui;
}

void ProductCreator::onCancelBtnClick() {
    this->close();
}

void ProductCreator::onCreateBtnClick() {
    auto selectedProduct = Products(ui->productCB->currentIndex());
    auto selectedSize = Sizes(ui->sizeCB->currentIndex());

    switch (selectedProduct) {
        case Products::GamingConsole : {
            auto *myWidget = new ProductWidget(this,
                                               new Product("Gaming Console", "test", selectedSize));
            emit ProductCreator::productAdded(myWidget);
            break;
        }
    }

    this->close();
}

