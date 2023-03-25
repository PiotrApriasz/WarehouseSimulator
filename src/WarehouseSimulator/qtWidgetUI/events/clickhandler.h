//
// Created by piotr on 25.03.2023.
//

#ifndef WAREHOUSESIMULATOR_CLICKHANDLER_H
#define WAREHOUSESIMULATOR_CLICKHANDLER_H

#include <QFrame>
#include <QMouseEvent>
#include <QObject>

class ClickHandler : public QObject {
Q_OBJECT
public:
    ClickHandler(QObject *parent = nullptr) : QObject(parent) {}

    bool eventFilter(QObject *obj, QEvent *event) override {
        if (event->type() == QEvent::MouseButtonPress) {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
            if (mouseEvent->button() == Qt::LeftButton && obj->isWidgetType()) {
                QWidget *widget = static_cast<QWidget*>(obj);
                // Left button was clicked on the widget, emit a signal or do some other action
                emit clicked(widget);
            }
        }
        return QObject::eventFilter(obj, event);
    }

signals:
    void clicked(QWidget *widget);
};

#endif //WAREHOUSESIMULATOR_CLICKHANDLER_H
