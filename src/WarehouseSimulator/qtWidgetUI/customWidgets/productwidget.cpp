//
// Created by piotr on 23.03.2023.
//

#include "ProductWidget.h"
#include <QMouseEvent>
#include <QDrag>
#include <QMimeData>
#include <QPainter>

ProductWidget::ProductWidget(QWidget *parent)
        : QWidget(parent)
{
    setFixedSize(100, 100);
    setStyleSheet("background-color: red;");
    m_isHighlighted = false;
}

void ProductWidget::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    if (m_isHighlighted) {
        painter.fillRect(rect(), QColor(255, 255, 0, 128)); // Fill with yellow color
    }
    // Draw the contents of the widget
}

void ProductWidget::mousePressEvent(QMouseEvent* event) {
    m_isHighlighted = !m_isHighlighted;
    update(); // Redraw the widget to show the highlight
    QWidget::mousePressEvent(event);
}
