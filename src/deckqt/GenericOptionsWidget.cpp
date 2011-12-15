#include "GenericOptionsWidget.hpp"
#include "ui_GenericOptionsWidget.h"

GenericOptionsWidget::GenericOptionsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GenericOptionsWidget)
{
    ui->setupUi(this);
}

GenericOptionsWidget::~GenericOptionsWidget()
{
    delete ui;
}
