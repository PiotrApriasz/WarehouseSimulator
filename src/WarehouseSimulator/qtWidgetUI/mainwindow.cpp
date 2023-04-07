//
// Created by piotr on 20.03.2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include <QVBoxLayout>
#include <iostream>
#include <QGraphicsScene>
#include <QMessageBox>
#include "mainwindow.h"
#include "ui_MainWindow.h"
#include "productcreator.h"
#include "events/clickhandler.h"


MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow) {
    ui->setupUi(this);

    ui->sendBtn->setVisible(false);

    auto central = centralWidget();
    central->setLayout(new QVBoxLayout(central));

    m_productDB = new ProductCreator(this);

    connect(ui->createProductBtn, SIGNAL(clicked()), this,
            SLOT(onCreateProductBtnClick()));

    connect(ui->sendBtn, &QPushButton::clicked, this,
            &MainWindow::onSendBtnClick);

    connect(m_productDB, &ProductCreator::productAdded, this,
            &MainWindow::addNewProduct);

    initializeWardrobe1ClickHandlers();

    initializeWardrobes();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::onCreateProductBtnClick() {
    m_productDB->show();
}

void MainWindow::addNewProduct(QWidget *widget) {

    if (ui->factoryGB->layout() != nullptr) {
        delete ui->factoryGB->layout();
    }

    auto *layout = new QVBoxLayout(ui->factoryGB);
    layout->addWidget(widget, 0, Qt::AlignCenter);
    widget->setObjectName("Product");
    ui->factoryGB->setLayout(layout);
}

void MainWindow::moveProductToWardrobe(QWidget *widget) {
    qDebug() << "Widget was clicked: " << widget->objectName();

    auto wardrobeChildWidget = widget->findChild<QWidget*>("Product");

    if (wardrobeChildWidget == nullptr) {
        if (widget->layout() != nullptr) {
            delete widget->layout();
        }

        auto childWidget = ui->factoryGB->findChild<QWidget*>("Product");
        auto productWidget = dynamic_cast<ProductWidget*>(childWidget);

        if (childWidget != nullptr) {

            if (!addProductToStorageBox(productWidget->getProduct(), widget->objectName().toStdString()))
                return;

            QLayout* groupBoxLayout = ui->factoryGB->layout();
            groupBoxLayout->removeWidget(childWidget);
            childWidget->setParent(nullptr);
            ui->factoryGB->setLayout(groupBoxLayout);

            auto* frameLayout = new QVBoxLayout(widget);
            frameLayout->addWidget(childWidget, 0, Qt::AlignCenter);

            widget->setLayout(frameLayout);

            childWidget->installEventFilter(this);
        }
    }
    else {
        if (ui->shipmentGB->layout() == nullptr) {

            auto productWidget = dynamic_cast<ProductWidget*>(wardrobeChildWidget);

            if (!deleteProductFromStorageBox(productWidget->getProduct(), widget->objectName().toStdString()))
                return;

            QLayout *storageBoxLayout = widget->layout();
            storageBoxLayout->removeWidget(wardrobeChildWidget);
            wardrobeChildWidget->setParent(nullptr);
            widget->setLayout(storageBoxLayout);

            auto *layout = new QVBoxLayout(ui->shipmentGB);
            layout->addWidget(wardrobeChildWidget, 0, Qt::AlignCenter);
            ui->shipmentGB->setLayout(layout);

            ui->sendBtn->setVisible(true);
        }
    }
}

void MainWindow::onSendBtnClick() {
    auto product = dynamic_cast<ProductWidget*>(ui->shipmentGB->findChild<QWidget*>("Product"));

    showMessageBox("Product Shipment", product->getProduct()->getProductSendInfo());

    delete product;
    delete ui->shipmentGB->layout();

    ui->sendBtn->setVisible(false);
}

bool MainWindow::addProductToStorageBox(Product *product, const std::string& storageBoxId) {
    auto wardrobeId = storageBoxId.substr(0, 4);

    if (wardrobeId == "war1") {
        if (!m_fifoWardrobe->addProduct(product, storageBoxId)) {
            showMessageBox("Product Creation", "Product can't be added");
            return false;
        }
    }
    /*else if (wardrobeId == "war2") {
        if (!m_lifoWardrobe->addProduct(product, storageBoxId)) {
            showMessageBox("Product Creation", "Product can't be added");
            return false;
        }
    }
    else if (wardrobeId == "war3") {
        if (!m_freeWardrobe->addProduct(product, storageBoxId)) {
            showMessageBox("Product Creation", "Product can't be added");
            return false;
        }
    }*/

    return true;
}

bool MainWindow::deleteProductFromStorageBox(Product *product, const std::string& storageBoxId) {
    auto wardrobeId = storageBoxId.substr(0, 4);

    if (wardrobeId == "war1") {
        if (!m_fifoWardrobe->removeProduct(product)) {
            showMessageBox("Product Removal", "This product can't be removed right now. Try another one");
            return false;
        }
    }
    /*else if (wardrobeId == "war2") {
        if (!m_lifoWardrobe->addProduct(product, storageBoxId)) {
            showMessageBox("Product Creation", "Product can't be added");
            return false;
        }
    }
    else if (wardrobeId == "war3") {
        if (!m_freeWardrobe->addProduct(product, storageBoxId)) {
            showMessageBox("Product Creation", "Product can't be added");
            return false;
        }
    }*/

    return true;
}

void MainWindow::showMessageBox(const std::string& title, std::string text) {
    QMessageBox msgBox;
    msgBox.setWindowTitle(QString::fromStdString(title));
    msgBox.setText(QString::fromStdString(text));
    msgBox.exec();
}

void MainWindow::initializeWardrobes() {
    std::vector<StorageBox> wardrobe1StorageBoxes =  {
            StorageBox(Sizes::Medium, "war1fr1"),
            StorageBox(Sizes::Medium, "war1fr2"),
            StorageBox(Sizes::Big, "war1fr3"),
            StorageBox(Sizes::Small, "war1fr4"),
            StorageBox(Sizes::Small, "war1fr5"),
            StorageBox(Sizes::Small, "war1fr6"),
            StorageBox(Sizes::Big, "war1fr7"),
    };

    m_fifoWardrobe = new Wardrobe<AccessPolicies::FIFO>(wardrobe1StorageBoxes, "war1");
}

void MainWindow::initializeWardrobe1ClickHandlers() {
    auto clickHandler_w1fr1 = new ClickHandler(ui->war1fr1);
    ui->war1fr1->installEventFilter(clickHandler_w1fr1);

    connect(clickHandler_w1fr1, &ClickHandler::clicked, this,
            &MainWindow::moveProductToWardrobe);

    auto clickHandler_w1fr2 = new ClickHandler(ui->war1fr2);
    ui->war1fr2->installEventFilter(clickHandler_w1fr2);

    connect(clickHandler_w1fr2, &ClickHandler::clicked, this,
            &MainWindow::moveProductToWardrobe);

    auto clickHandler_w1fr3 = new ClickHandler(ui->war1fr3);
    ui->war1fr3->installEventFilter(clickHandler_w1fr3);

    connect(clickHandler_w1fr3, &ClickHandler::clicked, this,
            &MainWindow::moveProductToWardrobe);

    auto clickHandler_w1fr4 = new ClickHandler(ui->war1fr4);
    ui->war1fr4->installEventFilter(clickHandler_w1fr4);

    connect(clickHandler_w1fr4, &ClickHandler::clicked, this,
            &MainWindow::moveProductToWardrobe);

    auto clickHandler_w1fr5 = new ClickHandler(ui->war1fr5);
    ui->war1fr5->installEventFilter(clickHandler_w1fr5);

    connect(clickHandler_w1fr5, &ClickHandler::clicked, this,
            &MainWindow::moveProductToWardrobe);

    auto clickHandler_w1fr6 = new ClickHandler(ui->war1fr6);
    ui->war1fr6->installEventFilter(clickHandler_w1fr6);

    connect(clickHandler_w1fr6, &ClickHandler::clicked, this,
            &MainWindow::moveProductToWardrobe);

    auto clickHandler_w1fr7 = new ClickHandler(ui->war1fr7);
    ui->war1fr7->installEventFilter(clickHandler_w1fr7);

    connect(clickHandler_w1fr7, &ClickHandler::clicked, this,
            &MainWindow::moveProductToWardrobe);
}
