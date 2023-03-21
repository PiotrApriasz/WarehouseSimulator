//
// Created by piotr on 21.03.2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_ProductCreator.h" resolved

#include "productcreator.h"
#include "ui_ProductCreator.h"


ProductCreator::ProductCreator(QWidget *parent) :
        QDialog(parent), ui(new Ui::ProductCreator) {
    ui->setupUi(this);
}

ProductCreator::~ProductCreator() {
    delete ui;
}
