#include "PeerOptionsWidget.hpp"
#include "ui_PeerOptionsWidget.h"

PeerOptionsWidget::PeerOptionsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PeerOptionsWidget)
{
    ui->setupUi(this);
}

PeerOptionsWidget::~PeerOptionsWidget()
{
    delete ui;
}
