//
// Created by piotr on 23.03.2023.
//

#include "ProductWidget.h"
#include <QMouseEvent>
#include <QDrag>
#include <QMimeData>
#include <QPainter>
#include <sstream>
#include <QLabel>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QPushButton>

ProductWidget::ProductWidget(QWidget *parent, Product *product)
        : QWidget(parent),
        m_product(product) {
    createWidget();
}

void ProductWidget::createWidget() {
    switch (m_product->getSize()) {
        case Sizes::Small : {
            setFixedSize(60, 100);
            break;
        }
        case Sizes::Medium : {
            setFixedSize(100, 100);
            break;
        }
        case Sizes::Big : {
            setFixedSize(180, 100);
            break;
        }
    }

    std::ostringstream stylesheetSetting;
    stylesheetSetting << "background-image: url(" << m_product->getImagePath() << ");";
    std::string stylesheetText = stylesheetSetting.str();
    std::replace(stylesheetText.begin(), stylesheetText.end(), '\\', '/');
    setStyleSheet(QString::fromStdString(stylesheetText));
}

Product *ProductWidget::getProduct() {
    return m_product;
}