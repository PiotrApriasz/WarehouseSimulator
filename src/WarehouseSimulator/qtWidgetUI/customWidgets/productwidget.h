//
// Created by piotr on 23.03.2023.
//

#ifndef WAREHOUSESIMULATOR_PRODUCTWIDGET_H
#define WAREHOUSESIMULATOR_PRODUCTWIDGET_H


#include <QWidget>

class ProductWidget : public QWidget {
public:
    ProductWidget(QWidget *parent = nullptr);

private:
    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    bool m_isHighlighted;
};


#endif //WAREHOUSESIMULATOR_PRODUCTWIDGET_H
