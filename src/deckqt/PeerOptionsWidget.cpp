#include "PeerOptionsWidget.hpp"
#include "ui_PeerOptionsWidget.h"

PeerOptionsWidget::PeerOptionsWidget(QWidget *parent) :
    QWidget(parent),
    ui_(new Ui::PeerOptionsWidget)
{
    ui_->setupUi(this);
}

PeerOptionsWidget::~PeerOptionsWidget()
{
    delete ui_;
}

void PeerOptionsWidget::setNodeName(QString nodename)
{
    ui_->nodeName->setText(nodename);
}

QString PeerOptionsWidget::getNodeName() const
{
    return ui_->nodeName->text();
}
