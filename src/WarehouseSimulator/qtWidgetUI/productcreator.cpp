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
#include "../businessLogic/gamingconsole.h"
#include "../businessLogic/gamepad.h"
#include "../businessLogic/tv.h"
#include "../businessLogic/keyboard.h"


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

    auto product = getProductText(static_cast<int>(selectedProduct));
    auto imagePath = ImageHelper::getProductImagePath(selectedProduct, selectedSize);

    switch (selectedProduct) {
        case Products::GamingConsole : {
            auto *widget = new ProductWidget(this,
                                               new GamingConsole(product,
                                                                        imagePath,
                                                                        selectedSize));
            emit ProductCreator::productAdded(widget);
            break;
        }
        case Products::GamePad : {
            auto *widget = new ProductWidget(this,
                                             new Gamepad(product,
                                                               imagePath,
                                                               selectedSize));
            emit ProductCreator::productAdded(widget);
            break;
        }
        case Products::TV : {
            auto *widget = new ProductWidget(this,
                                             new TV(product,
                                                               imagePath,
                                                               selectedSize));
            emit ProductCreator::productAdded(widget);
            break;
        }
        case Products::Keyboard : {
            auto *widget = new ProductWidget(this,
                                             new Keyboard(product,
                                                               imagePath,
                                                               selectedSize));
            emit ProductCreator::productAdded(widget);
            break;
        }
    }

    this->close();
}

