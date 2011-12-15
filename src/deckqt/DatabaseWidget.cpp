#include "DatabaseWidget.hpp"
#include "ui_DatabaseWidget.h"

DatabaseWidget::DatabaseWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DatabaseWidget)
{
    ui->setupUi(this);
}

DatabaseWidget::~DatabaseWidget()
{
    delete ui;
}
