#include "DatabaseOptionsWidget.hpp"
#include "ui_DatabaseOptionsWidget.h"

DatabaseOptionsWidget::DatabaseOptionsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DatabaseOptionsWidget)
{
    ui->setupUi(this);
}

DatabaseOptionsWidget::~DatabaseOptionsWidget()
{
    delete ui;
}
