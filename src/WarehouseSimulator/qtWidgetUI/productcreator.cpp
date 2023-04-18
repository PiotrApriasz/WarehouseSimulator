//
// Created by piotr on 21.03.2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_ProductCreator.h" resolved

#include <QHBoxLayout>
#include "productcreator.h"
#include "ui_ProductCreator.h"
#include "../businessLogic/enums/products.h"
#include "../businessLogic/helpers/imagehelper.h"
#include "../businessLogic/Products/productfactory.h"

#include <QString>
#include <algorithm>
#include <vector>
#include <QList>

ProductCreator::ProductCreator(QWidget *parent) :
        QDialog(parent), ui(new Ui::ProductCreator) {
    ui->setupUi(this);

    ui->productCB->addItems(convertEnums(ProductsStrings));
    ui->sizeCB->addItems(convertEnums(SizesStrings));

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

    auto product = ProductFactory::CreateProduct(selectedProduct, selectedSize);
    auto *productWidget = new ProductWidget(this, product);
    emit ProductCreator::productAdded(productWidget);

    this->close();
}

QList<QString> ProductCreator::convertEnums(std::vector<std::string> enumNames) {
    return [&enumNames]() {
        QList<QString> result;
        std::transform(enumNames.cbegin(), enumNames.cend(), std::back_inserter(result),
                       [](const std::string& str) { return QString::fromStdString(str); });
        return result;
    }();
}

