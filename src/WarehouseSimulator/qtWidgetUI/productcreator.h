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
    ProductWidget* productAdded(ProductWidget *widget);

private slots:
    void onCancelBtnClick();
    void onCreateBtnClick();
};


#endif //WAREHOUSESIMULATOR_PRODUCTCREATOR_H
