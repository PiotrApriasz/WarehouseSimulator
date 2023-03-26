//
// Created by piotr on 20.03.2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include <QVBoxLayout>
#include <iostream>
#include <QGraphicsScene>
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

    QVBoxLayout *layout = new QVBoxLayout(ui->factoryGB);
    layout->addWidget(widget, 0, Qt::AlignCenter);
    widget->setObjectName("Product");
    ui->factoryGB->setLayout(layout);
}

void MainWindow::moveProductToWardrobe(QWidget *widget) {
    qDebug() << "Widget was clicked: " << widget->objectName();
    QWidget* childWidget = ui->factoryGB->findChild<QWidget*>("Product");

    QLayout* groupBoxLayout = ui->factoryGB->layout();
    groupBoxLayout->removeWidget(childWidget);
    childWidget->setParent(nullptr);
    ui->factoryGB->setLayout(groupBoxLayout);

    QVBoxLayout* frameLayout = new QVBoxLayout(widget);
    frameLayout->addWidget(childWidget, 0, Qt::AlignCenter);

    widget->setLayout(frameLayout);

    widget->removeEventFilter(m_clickHandlerw1f4);
}
