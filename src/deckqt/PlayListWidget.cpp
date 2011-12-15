#include "PlayListWidget.hpp"
#include "ui_PlayListWidget.h"

PlayListWidget::PlayListWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlayListWidget)
{
    ui->setupUi(this);
}

PlayListWidget::~PlayListWidget()
{
    delete ui;
}
