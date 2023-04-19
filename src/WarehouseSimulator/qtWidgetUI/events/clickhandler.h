//
// Created by piotr on 25.03.2023.
//

#ifndef WAREHOUSESIMULATOR_CLICKHANDLER_H
#define WAREHOUSESIMULATOR_CLICKHANDLER_H

#include <QFrame>
#include <QMouseEvent>
#include <QObject>

/**
 * @file
 * Klasa pozwalająca zaimplementować własną obsługę kliku myszki dla dowolnego obiektu  Qt
 */
class ClickHandler : public QObject {
Q_OBJECT
public:
    ClickHandler(QObject *parent = nullptr) : QObject(parent) {}

    /**
     * Event wyzwalany w momencie kliknięcia na obiekt, w którym zainstaloany jest poniższy filtr
     * @param obj Wskaźnik na kliknięty obiekt
     * @param event
     * @return
     */
    bool eventFilter(QObject *obj, QEvent *event) override {
        if (event->type() == QEvent::MouseButtonPress) {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
            if (mouseEvent->button() == Qt::LeftButton && obj->isWidgetType()) {
                QWidget *widget = static_cast<QWidget*>(obj);
                emit clicked(widget);
            }
        }
        return QObject::eventFilter(obj, event);
    }

signals:
    /**
     * Sygnał jaki jest wysyłany kiedy obiekt zostanie kliknięty
     * @param widget Wskaźnik na kliknięty obiekt
     */
    void clicked(QWidget *widget);
};

#endif //WAREHOUSESIMULATOR_CLICKHANDLER_H
