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

    m_clickHandlerw1f4 = new ClickHandler(ui->wardrobe1Frame4);
    ui->wardrobe1Frame4->installEventFilter(m_clickHandlerw1f4);

    connect(m_clickHandlerw1f4, &ClickHandler::clicked, this,
            &MainWindow::moveProductToWardrobe);
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

    if (widget->layout() != nullptr) {
        delete widget->layout();
    }

    QWidget* wardrobeChildWidget = widget->findChild<QWidget*>("Product");
    QWidget* childWidget = ui->factoryGB->findChild<QWidget*>("Product");

    if (wardrobeChildWidget == nullptr && childWidget != nullptr) {
        QLayout* groupBoxLayout = ui->factoryGB->layout();
        groupBoxLayout->removeWidget(childWidget);
        childWidget->setParent(nullptr);
        ui->factoryGB->setLayout(groupBoxLayout);

        auto* frameLayout = new QVBoxLayout(widget);
        frameLayout->addWidget(childWidget, 0, Qt::AlignCenter);

        widget->setLayout(frameLayout);
    }
}

void MainWindow::onSendBtnClick() {
    auto product = static_cast<ProductWidget*>(ui->shipmentGB->findChild<QWidget*>("Product"));

    QMessageBox msgBox;
    msgBox.setWindowTitle("ProductShipment");
    msgBox.setText(QString::fromStdString(product->getProduct()->getProductSendInfo()));
    msgBox.exec();

    delete product;
    delete ui->shipmentGB->layout();

    ui->sendBtn->setVisible(false);
}
