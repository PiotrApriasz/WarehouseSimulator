//
// Created by piotr on 21.03.2023.
//

#ifndef WAREHOUSESIMULATOR_PRODUCTCREATOR_H
#define WAREHOUSESIMULATOR_PRODUCTCREATOR_H

#include <QDialog>
#include "customWidgets/productwidget.h"


QT_BEGIN_NAMESPACE
namespace Ui { class ProductCreator; }
QT_END_NAMESPACE

/**
 * Klasa reprezentująca okno kreatora produktów. Dziedziczy po klasie QDialog.
 */
class ProductCreator : public QDialog {
Q_OBJECT

public:
    explicit ProductCreator(QWidget *parent = nullptr);

    ~ProductCreator() override;

private:
    Ui::ProductCreator *ui;
    QWidget* m_mainWindow;
    QList<QString> convertEnums(std::vector<std::string> enumNames);

signals:
    /**
     * Sygnał sygnalizujący utworznie nowego widgetu produktu
     * @param widget Wskażnik na obiekt utworzonego widgetu produktu
     * @return Zwraca wskaźnik utworzonego widgetu produktu
     */
    ProductWidget* productAdded(ProductWidget *widget);

private slots:
    void onCancelBtnClick();
    void onCreateBtnClick();
};


#endif //WAREHOUSESIMULATOR_PRODUCTCREATOR_H
